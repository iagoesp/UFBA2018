#include "Application.h"
#include "Arguments.h"
#include "Helpers.h"
#include "ReplayProcedures.h"
#include "Resources.h"
#include "Threading.h"

#include <algorithm>
#include <cfloat>
#include <chrono>
#include <iostream>
#include <sstream>
#include <stdexcept>

#ifdef NV_HAS_FUNCTION_OVERRIDES
#include "function_overrides.h"
#else
#define My_init() init()
#define My_frame(frame_number, frame_functions) frame_functions
#define My_done() done()
#endif

#if _MSC_VER
// See https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-1/fatal-error-c1060 for additional information
#pragma message("[NVIDIA Nsight] C++ Captures can occasionally fail compilation due to compiler memory issues. If you are seeing a C1060 compiler message, the /Zm and /m compiler options have been shown to help.")
#endif

#ifndef NOMINMAX
#define NOMINMAX
#endif

#define FPS_AVG_WINDOW 32
#define FPS_WARMUP_WINDOW (2 * FPS_AVG_WINDOW)

static Application* s_instance = nullptr;

//------------------------------------------------------------------------------
// Application
//------------------------------------------------------------------------------
Application::Application()
{
    NV_ASSERT(s_instance == nullptr);
    s_instance = this;
}

//------------------------------------------------------------------------------
// ExecuteInternal
//------------------------------------------------------------------------------
int Application::ExecuteInternal(int argc, char** argv)
{
    int ret = EXIT_SUCCESS;

    // Necessary for override system
    auto init = [this]() { this->PlatformInit(); };
    auto done = [this]() { this->PlatformDone(); };

    std::vector<uint64_t> frameTimes;

    if (m_dumpFrameTimes) {
        const auto frameTimeReservation = (m_repeatCount > 0) ? m_repeatCount : uint64_t(60*60*3);
        frameTimes.reserve(static_cast<size_t>(frameTimeReservation));
    }

    try {

        My_init();

        auto lastFpsReport = std::chrono::high_resolution_clock::now();
        float minDurationMs = FLT_MAX;
        float maxDurationMs = 0;
        float runningAverage[FPS_AVG_WINDOW] = { 0 };
        float totalDurationMs = 0;
        float minDurationMsTotal = FLT_MAX;
        float maxDurationMsTotal = 0;

        auto OutputPerfStats = [](const char* prefix, float durationAVGMs, float fps, float minDurationMs, float maxDurationMs, uint64_t frames) {
            NV_MESSAGE("%sAVG: %6.3f ms (%6.3f FPS) | MIN: %6.3f ms | MAX: %6.3f ms | Frames: %6u", prefix, durationAVGMs, fps, minDurationMs, maxDurationMs, frames);
        };

        while (m_repeatCount == 0 || m_frameIndex < m_repeatCount) {

            if (!ProcessMessages()) {
                break;
            }

            const auto start = std::chrono::high_resolution_clock::now();

            My_frame(
                m_frameIndex,
                RunFrame(););

            const auto end = std::chrono::high_resolution_clock::now();
            const auto diff = (end - start);
            const auto deltaInMs = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

            if (m_dumpFrameTimes) {
                frameTimes.push_back(deltaInMs);
            }

            if (m_perfStats) {
                if (m_frameIndex > FPS_WARMUP_WINDOW) {
                    const auto timeSinceLastReport = std::chrono::duration_cast<std::chrono::milliseconds>(end - lastFpsReport);
                    float durationMs = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.f;
                    minDurationMs = std::min<float>(minDurationMs, durationMs);
                    maxDurationMs = std::max<float>(maxDurationMs, durationMs);

                    const auto indexAfterWarmup = (m_frameIndex - FPS_WARMUP_WINDOW);

                    runningAverage[indexAfterWarmup % FPS_AVG_WINDOW] = durationMs;
                    totalDurationMs += durationMs;
                    if (timeSinceLastReport >= std::chrono::seconds(1)) {
                        float sum = 0;
                        const uint32_t nFramesToAverage = std::min<uint32_t>(static_cast<uint32_t>(indexAfterWarmup + 1), FPS_AVG_WINDOW);
                        for (uint32_t i = 0; i < nFramesToAverage; i++) {
                            sum += runningAverage[i];
                        }
                        OutputPerfStats("", sum / float(nFramesToAverage), (1000.f / durationMs), minDurationMs, maxDurationMs, nFramesToAverage);
                        lastFpsReport = end;
                        minDurationMsTotal = std::min<float>(minDurationMsTotal, minDurationMs);
                        maxDurationMsTotal = std::max<float>(maxDurationMsTotal, maxDurationMs);

                        minDurationMs = FLT_MAX;
                        maxDurationMs = 0;
                    }
                } else if (m_frameIndex == FPS_WARMUP_WINDOW) {
                    lastFpsReport = end;
                }
            }

            m_frameIndex++;
        }

        if (m_perfStats && m_frameIndex > FPS_WARMUP_WINDOW) {
            const float durationAVGMs = totalDurationMs / float(m_frameIndex - FPS_WARMUP_WINDOW);
            OutputPerfStats("Total ", durationAVGMs, (1000.f / durationAVGMs), minDurationMsTotal, maxDurationMsTotal, m_frameIndex);
        }
    } catch (std::exception& e) {
        OutputMessage(std::string("Nvda.Replay Error: ") + e.what());
        ret = EXIT_FAILURE;
    }

    My_done();

    if (m_dumpFrameTimes) {
        auto convertToMs = [](uint64_t n) -> float {
            return n / 1000.f;
        };

        FILE* f = fopen("frametimes.csv", "w");
        if (f) {
            for (const auto frameTime : frameTimes) {
                fprintf(f, "%.3f, ", convertToMs(frameTime));
            }
            fclose(f);
        } else {
            OutputMessage("Failed to dump frame times");
        }
    }

    return ret;
}

//------------------------------------------------------------------------------
// Execute
//------------------------------------------------------------------------------
int Application::Execute()
{
    int argc = 0;
    char* argv[] = { const_cast<char*>("") };
    return ExecuteInternal(argc, argv);
}

//------------------------------------------------------------------------------
// Execute
//------------------------------------------------------------------------------
int Application::Execute(int argc, char** argv)
{
    // Parse the command line arguments
    if (!ParseCommandLine(argc, argv)) {
        return EXIT_FAILURE;
    }

    return ExecuteInternal(argc, argv);
}

//------------------------------------------------------------------------------
// HasForceBorderlessWindow (static)
//------------------------------------------------------------------------------
bool Application::HasForceBorderlessWindow()
{
    return s_instance->m_forceBorderlessWindow;
}

//------------------------------------------------------------------------------
// HasMultiThreadedReplay
//------------------------------------------------------------------------------
bool Application::HasMultiThreadedReplay()
{
    return s_instance->m_multiThreadedReplay;
}

//------------------------------------------------------------------------------
// EnableMultiThreadedReplay
//------------------------------------------------------------------------------
void Application::EnableMultiThreadedReplay(bool enable)
{
    s_instance->m_multiThreadedReplay = enable;
}

//------------------------------------------------------------------------------
// Init
//------------------------------------------------------------------------------
void Application::PlatformInit()
{
    CreateAndSetupResources();
}

//------------------------------------------------------------------------------
// Done
//------------------------------------------------------------------------------
void Application::PlatformDone()
{
    ReleaseResources();
}

//------------------------------------------------------------------------------
// OutputMessage
//------------------------------------------------------------------------------
void Application::OutputMessage(const std::string& message) const
{
    NV_MESSAGE(message.c_str());
}

//------------------------------------------------------------------------------
// ParseCommandLine
//------------------------------------------------------------------------------
bool Application::ParseCommandLine(int argc, char** argv)
{
    // Create parses
    args::ArgumentParser parser("Nvda.Replayer -- NVIDIA Nsight C++ Capture Replayer");

    // This matches the previous parser
    parser.ShortPrefix("/");
    parser.LongPrefix("-");
    parser.helpParams.showTerminator = false;

    // API agnostic options
    args::HelpFlag help(parser, "help", "Display this help menu", { "help" });
    args::ValueFlag<uint32_t> optRepeat(parser, "N", "Number of frames to run", { "repeat" });
    args::Flag optNoReset(parser, "noreset", "Do not perform a state reset in between frames", { "noreset", "no-reset" });
    args::Flag optForceDebug(parser, "forcedebug", "Force enable API validation", { "forcedebug", "force-debug" });
    args::Flag optAutomated(parser, "automated", "Do not use facilities that require user interaction", { "automated" });
    args::Flag optPerfStats(parser, "fps", "Include FPS in output messages", { "fps" });
    args::Flag optForceBorderlessWindow(parser, "wb", "Force borderless window", { "wb" });
    args::ValueFlag<std::string> optLogDir(parser, "FILE", "Write stdout/stderr messages to an output file", { "log" });
    args::Flag optDumpFrameTimes(parser, "dumpframetimes", "Dumps individual frame times into a csv", { "dumpframetimes" });
    args::Flag optDebugShaderBytecode(parser, "debugshaderbytecode", "Use debug shader bytecode (default is to use release bytecode)", { "debugshaderbytecode" });

    // Register add external API-specific options
    std::vector<FnParseResults> vecFnParseResults;
    for (auto& fnAddArguments : GetExternalArguments()) {
        vecFnParseResults.push_back(fnAddArguments(parser));
    }

    // Positional options
    args::PositionalList<std::string> overrideArguments(parser, "override_arguments", "Extra arguments to be made available to function_overrides", args::Options::Hidden);

    // Perform parse
    try {
        parser.ParseCLI(argc, argv);
    } catch (args::Completion e) {
        std::cout << e.what();
        return false;
    } catch (args::Help) {
        OutputMessage(parser.Help());
        return false;
    } catch (args::Error e) {
        std::stringstream ss;
        ss << e.what() << std::endl;
        ss << parser.Help();
        OutputMessage(ss.str());
        return false;
    }

    if (optRepeat) {
        m_repeatCount = optRepeat.Get();
    }

    if (optNoReset) {
        hasFrameReset = false;
    }

    if (optForceDebug) {
        forceDebug = true;
    }

    if (optAutomated) {
        automated = true;
    }

    if (optLogDir) {
        automated = true;
        freopen(optLogDir.Get().c_str(), "w", stderr);
    }

    if (optDumpFrameTimes) {
        m_dumpFrameTimes = true;
    }

    if (optForceBorderlessWindow) {
        m_forceBorderlessWindow = true;
    }

    if (optPerfStats) {
        m_perfStats = true;
    }

    if (optDebugShaderBytecode) {
        useDebugBytecode = true;
    }

    // Parse additional options
    for (auto& fnParseResults : vecFnParseResults) {
        fnParseResults();
    }

    return true;
}
