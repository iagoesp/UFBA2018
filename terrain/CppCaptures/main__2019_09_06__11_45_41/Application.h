#pragma once

#include <cstdint>
#include <string>

//-----------------------------------------------------------------------------
// Application
//-----------------------------------------------------------------------------
class Application
{
protected:
    Application();
    Application(const Application&);
    Application& operator=(const Application&);

public:
    static Application& PlatformInstance();

    int Execute();
    int Execute(int argc, char** argv);
    static bool HasForceBorderlessWindow();
    static bool HasMultiThreadedReplay();
    static void EnableMultiThreadedReplay(bool enable);

protected:
    bool ParseCommandLine(int argc, char** argv);
    int ExecuteInternal(int argc, char** argv);

    virtual void PlatformInit();
    virtual void PlatformDone();
    virtual void OutputMessage(const std::string& message) const;
    virtual bool ProcessMessages() = 0;

    uint64_t m_repeatCount = 0;
    uint64_t m_frameIndex = 0;
    bool m_perfStats = false;
    bool m_forceBorderlessWindow = false;
    bool m_multiThreadedReplay = true;
    bool m_dumpFrameTimes = false;
};
