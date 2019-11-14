//-----------------------------------------------------------------------------
// Generated with NVIDIA Nsight Graphics 2019.3.0.0
// 
// File: Helpers.cpp
// 
//-----------------------------------------------------------------------------

#include "NvEW_GL.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "NvEW_GLX.h"

#if !defined(_MSC_VER) || _MSC_VER >= 1700
#include <mutex>
#endif
#include <set>
#include <sstream>

#include "Helpers.h"
#include "Resources.h"
#include "ReadOnlyDatabase.h"

#if !defined(WIN32)

#include <dlfcn.h>

#endif

#if !defined(_WIN64) && !defined(__x86_64__) && !defined(__ppc64__) && !defined(__LP64__)
#if !defined(NV_AUTOMATED_BUILD)
#error Application originally targeted 64-bit; compiling now as 32-bit
#else
#if defined(_MSC_VER)
#pragma message("Warning: Application originally targeted 64-bit; compiling now as 32-bit")
#else
#warning Application originally targeted 64-bit; compiling now as 32-bit
#endif
#endif
#endif

#if defined(WIN32)

// Tell the driver to use the high performance GPU
extern "C"
{
    __declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
};

#endif

using namespace Serialization;

static ReadOnlyDatabase* s_pDatabase = nullptr;

union HexFloat
{
    float f;
    uint32_t h;
};

union HexDouble
{
    double d;
    uint64_t h;
};

float HexToFloat(uint32_t h)
{
    HexFloat v;
    v.h = h;
    return v.f;
}

double HexToDouble(uint64_t h)
{
    HexDouble v;
    v.h = h;
    return v.d;
}

float NAN_F()
{
    return HexToFloat(0xffc00000);
}

float INF_F()
{
    return HexToFloat(0x7f800000);
}

double NAN_D()
{
    return HexToDouble(0xfff8000000000000);
}

double INF_D()
{
    return HexToDouble(0x7ff0000000000000);
}

//-----------------------------------------------------------------------------
// ReportErrorWithMessage
//-----------------------------------------------------------------------------
void ReportErrorWithMessage(const char* message, const char* file, int line)
{
    std::stringstream stream;
    stream << message << " at " << file << "(" << line << ")";
    NV_MESSAGE(stream.str().c_str());
}

//-----------------------------------------------------------------------------
// ThrowErrorWithMessage
//-----------------------------------------------------------------------------
void ThrowErrorWithMessage(const char* message, const char* file, int line)
{
    std::stringstream stream;
    stream << message << " at " << file << "(" << line << ")";
    throw std::runtime_error(stream.str());
}

//-----------------------------------------------------------------------------
// WriteMessage
//-----------------------------------------------------------------------------
void WriteMessage(const char* message)
{
#ifdef NV_WIN32_SUBSYSTEM
    if (!automated)
    {
        ::OutputDebugStringA(message);
        ::OutputDebugStringA("\n");
        return;
    }
#endif

    fprintf(stderr, "%s", message);
    fprintf(stderr, "\n");
}

//-----------------------------------------------------------------------------
// InitializeDatabase
//-----------------------------------------------------------------------------
void InitializeDatabase()
{
    // Set max page size: 64MB
    const static uint64_t MAX_PAGE_SIZE = 1 << 26;

    // Set max resident page count
    const static size_t MAX_RESIDENT_PAGES = 16;
    s_pDatabase = new ReadOnlyDatabase("data.bin", MAX_PAGE_SIZE, MAX_RESIDENT_PAGES);
}

//-----------------------------------------------------------------------------
// GetDatabase
//-----------------------------------------------------------------------------
Serialization::ReadOnlyDatabase& GetDatabase()
{
    return *s_pDatabase;
}

//-----------------------------------------------------------------------------
// FreeCachedMemory
//-----------------------------------------------------------------------------
void FreeCachedMemory()
{
    BEGIN_DATA_SCOPE_FUNCTION();

    GetDatabase().FreeCachedMemory();
}

//-----------------------------------------------------------------------------
// DebugCallback
//-----------------------------------------------------------------------------
void APIENTRY DebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const GLvoid* userParam)
{
    std::vector<char> buf(length + 32);

    // Toggle this code block to configure whether messages show up only once
#if 0
    static std::set<std::string> viewMessagesOnce;
    std::string strMessage(message);
    if (viewMessagesOnce.find(strMessage) == viewMessagesOnce.end())
    {
        viewMessagesOnce.insert(strMessage);
    }
    else
    {
        return;
    }
#endif

    switch (type)
    {
    case GL_DEBUG_TYPE_ERROR:
        sprintf(&buf[0], "Error: %s\n", message);
        break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        sprintf(&buf[0], "Deprecated behavior: %s\n", message);
        break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        sprintf(&buf[0], "Undefined behavior: %s\n", message);
        break;
    case GL_DEBUG_TYPE_PORTABILITY:
        sprintf(&buf[0], "Portability: %s\n", message);
        break;
    case GL_DEBUG_TYPE_PERFORMANCE:
        sprintf(&buf[0], "Performance: %s\n", message);
        break;
    case GL_DEBUG_TYPE_OTHER:
    default:
        sprintf(&buf[0], "Other: %s\n", message);
        break;
    }

    NV_MESSAGE(&buf[0]);
}

//-----------------------------------------------------------------------------
// InitializeListOfLists
//-----------------------------------------------------------------------------
template <typename T> T** InitializeListOfLists(int resourceId, std::vector<uint8_t>& retvalData, Serialization::BlobProxy<uint8_t*>& dataProxy)
{
    BEGIN_DATA_SCOPE_FUNCTION();

    using namespace Serialization;
    
    DATABASE_HANDLE handle(resourceId);
    uint64_t totalBlobSize = GetDatabase().GetSize(handle);
    if (0 == totalBlobSize)
    {
        BEGIN_DATA_SCOPE();

        return NULL;
    }

    dataProxy = GetDatabase().Read<uint8_t*>(handle);

    // Extract the number of lists
    int* pNumLists = (int*)dataProxy.Get();
    int numLists = *pNumLists;

    // Point to the actual start of the pointer list
    uint64_t* pListStart = (uint64_t*)(pNumLists + 1);

    // Allocate space to store the actual pointers based on the offsets in the blob
    retvalData.resize(numLists * sizeof(T*));

    // Convert the offsets stored in the blob into pointers
    T** ppRetvalData = (T**)&retvalData[0];
    for (int i = 0; i < numLists; ++i)
    {
        BEGIN_DATA_SCOPE();

        ppRetvalData[i] = (T*)(pListStart[i] + dataProxy.Get());
    }

    return ppRetvalData;
}

// Template instantiations
template const GLvoid** InitializeListOfLists(int resourceId, std::vector<uint8_t>& retvalData, Serialization::BlobProxy<uint8_t*>& dataProxy);
template const GLchar** InitializeListOfLists(int resourceId, std::vector<uint8_t>& retvalData, Serialization::BlobProxy<uint8_t*>& dataProxy);

//-----------------------------------------------------------------------------
// GetProcAddress
//-----------------------------------------------------------------------------
void* GetProcAddress(void* libHandle, const char* funcName)
{
    // First try to get the function using dlsym
    void* funcHandle = dlsym(libHandle, funcName);

    if (funcHandle)
    {{
        return funcHandle;
    }}

    // If that fails then use glXGetProcAddress, if that fails then
    // conclude that the function is not available
    return reinterpret_cast<void*>(glXGetProcAddress(reinterpret_cast<const GLubyte*>(funcName)));
}

//-----------------------------------------------------------------------------
// Common Resources
//-----------------------------------------------------------------------------
#if defined(WIN32)

HRESULT result;
HINSTANCE currentInstance = NULL;
#endif

bool hasFrameReset = true;
bool forceDebug = false;
bool automated = false;
bool useDebugBytecode = false;
double array_of_0s[256] = { 0 };
char errorBuf[512];
const char* pNameLibGL = "libGL.so.1";
const char* pNameLibGLX = "libGL.so.1";

//-----------------------------------------------------------------------------
// Threading Resources
//-----------------------------------------------------------------------------
#if defined(WIN32)

bool releaseReplayerThreads = false;
bool exitReplayerThreads = false;
HANDLE threadSequenceEvents[NUM_REPLAYER_THREADS] = { NULL };
HANDLE threadDoneEvents[NUM_REPLAYER_THREADS] = { NULL };
#else

bool releaseReplayerThreads = false;
bool exitReplayerThreads = false;
EventsArray threadSequenceEvents;
EventsArray threadDoneEvents;
#endif
