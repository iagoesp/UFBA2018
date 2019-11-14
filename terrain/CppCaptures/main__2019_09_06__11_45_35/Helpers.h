//-----------------------------------------------------------------------------
// Generated with NVIDIA Nsight Graphics 2019.3.0.0
// 
// File: Helpers.h
// 
//-----------------------------------------------------------------------------

#pragma once

#include "NvEW_GL.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "NvEW_GLX.h"

#include <cassert>
#include <cstdint>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <set>
#include <stdio.h>

#include "ReadOnlyDatabase.h"
#include "ThreadPool.h"

#if !defined(WIN32)

#include <memory>
#include <array>

#endif
#if !defined(WIN32)

class AutoResetEvent;
#endif

//-----------------------------------------------------------------------------
// Common Resources
//-----------------------------------------------------------------------------
#if defined(WIN32)

extern HRESULT result;
extern HINSTANCE currentInstance;
#endif

extern bool hasFrameReset;
extern bool forceDebug;
extern bool automated;
extern bool useDebugBytecode;
extern double array_of_0s[256];
extern char errorBuf[512];
extern const char* pNameLibGL;
extern const char* pNameLibGLX;

//-----------------------------------------------------------------------------
// Threading Resources
//-----------------------------------------------------------------------------
#if defined(WIN32)

const unsigned int NUM_REPLAYER_THREADS = 1ull;
extern bool releaseReplayerThreads;
extern bool exitReplayerThreads;
extern HANDLE threadSequenceEvents[];
extern HANDLE threadDoneEvents[];
#else

const unsigned int NUM_REPLAYER_THREADS = 1ull;
extern bool releaseReplayerThreads;
extern bool exitReplayerThreads;
using EventsArray = std::array<std::shared_ptr<AutoResetEvent>, NUM_REPLAYER_THREADS>;
extern EventsArray threadSequenceEvents;
extern EventsArray threadDoneEvents;
#endif

static const char NV_FRAME_RESET_MARKER_NAME[] = "[NSIGHT] Frame Reset";
static const wchar_t NV_FRAME_RESET_MARKER_NAME_W[] = L"[NSIGHT] Frame Reset";

#if defined(_MSC_VER) && _MSC_VER < 1900
#define snprintf _snprintf
#endif

#define NV_SAFE_RELEASE(_pObject) if (_pObject) { _pObject->Release(); _pObject = NULL; }
#define NV_SAFE_DESTROY(_pObject) if (_pObject) { _pObject->Destroy(); _pObject = NULL; }

extern float HexToFloat(uint32_t h);
extern double HexToDouble(uint64_t h);
extern float NAN_F();
extern float INF_F();
extern double NAN_D();
extern double INF_D();

extern void ReportErrorWithMessage(const char* message, const char* file, int line);
extern void ThrowErrorWithMessage(const char* message, const char* file, int line);
extern void WriteMessage(const char* message);

inline void NvMessage(const char* message)
{
    WriteMessage(message);
}

template <typename... Targs>
void NvMessage(const char* format, Targs... fArgs)
{
    const int BUFFER_SIZE = 512;
    char message[BUFFER_SIZE] = { 0 };
    snprintf(message, BUFFER_SIZE - 1, format, fArgs...);
    WriteMessage(message);
}

#define NV_MESSAGE(...) NvMessage(__VA_ARGS__)

#define NV_MESSAGE_ONCE(...)        \
do {                                \
    static bool s_once = false;     \
    if (!s_once) {                  \
        NV_MESSAGE(__VA_ARGS__);    \
        s_once = true;              \
    }                               \
} while(false)

#define NV_THROW_IF(_Condition, _Message) if (_Condition) { ThrowErrorWithMessage(_Message, __FILE__, __LINE__); }
#define NV_ASSERT(_Condition) assert(_Condition)

#define NV_ANONYMOUS_VARIABLE_DIRECT(_NAME, _LINE) _NAME##_LINE
#define NV_ANONYMOUS_VARIABLE(_NAME, _LINE) NV_ANONYMOUS_VARIABLE_DIRECT(_NAME, _LINE)


// Toggle this code block to configure whether errors are checked on every GL statement
#if 0
#define NV_EXEC_GL(_statement)                                                                      \
{                                                                                                   \
    _statement;                                                                                     \
                                                                                                    \
    const GLenum error = glGetError();                                                              \
    static bool ignoreThisError = false;                                                            \
    if (error && !ignoreThisError)                                                                  \
    {                                                                                               \
        NV_ASSERT(false && #_statement);                                                            \
        snprintf(errorBuf, sizeof(errorBuf), "Error 0x%x with statement %s", error, #_statement);   \
        ReportErrorWithMessage(errorBuf, __FILE__, __LINE__);                                       \
    }                                                                                               \
}
#else
#define NV_EXEC_GL(_statement) _statement
#endif


#define NV_CHECK_INIT(_Object)                                                              \
{                                                                                           \
    const GLenum error = glGetError();                                                      \
    if (error)                                                                              \
    {                                                                                       \
        snprintf(errorBuf, sizeof(errorBuf), "Error 0x%x setting up %s", error, #_Object);  \
        ThrowErrorWithMessage(errorBuf, __FILE__, __LINE__);                                \
    }                                                                                       \
}

// Conditionally alias the debug usage to the KHR variants for Android/QNX/Linux.
#if defined(__ANDROID__) || defined(__QNX__) || defined(__linux__)
#ifndef GL_DEBUG_TYPE_ERROR
#define GL_DEBUG_TYPE_ERROR                  GL_DEBUG_TYPE_ERROR_KHR
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR    GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_KHR
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR     GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_KHR
#define GL_DEBUG_TYPE_PORTABILITY            GL_DEBUG_TYPE_PORTABILITY_KHR
#define GL_DEBUG_TYPE_PERFORMANCE            GL_DEBUG_TYPE_PERFORMANCE_KHR
#define GL_DEBUG_TYPE_OTHER                  GL_DEBUG_TYPE_OTHER_KHR
#define GL_DEBUG_TYPE_MARKER                 GL_DEBUG_TYPE_MARKER_KHR
#define GL_DEBUG_TYPE_PUSH_GROUP             GL_DEBUG_TYPE_PUSH_GROUP_KHR
#define GL_DEBUG_TYPE_POP_GROUP              GL_DEBUG_TYPE_POP_GROUP_KHR
#define GL_DEBUG_SOURCE_API                  GL_DEBUG_SOURCE_API_KHR
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM        GL_DEBUG_SOURCE_WINDOW_SYSTEM_KHR
#define GL_DEBUG_SOURCE_SHADER_COMPILER      GL_DEBUG_SOURCE_SHADER_COMPILER_KHR
#define GL_DEBUG_SOURCE_THIRD_PARTY          GL_DEBUG_SOURCE_THIRD_PARTY_KHR
#define GL_DEBUG_SOURCE_APPLICATION          GL_DEBUG_SOURCE_APPLICATION_KHR
#define GL_DEBUG_SOURCE_OTHER                GL_DEBUG_SOURCE_OTHER_KHR
#define GL_DEBUG_SEVERITY_HIGH               GL_DEBUG_SEVERITY_HIGH_KHR
#define GL_DEBUG_SEVERITY_MEDIUM             GL_DEBUG_SEVERITY_MEDIUM_KHR
#define GL_DEBUG_SEVERITY_LOW                GL_DEBUG_SEVERITY_LOW_KHR
#define GL_DEBUG_SEVERITY_NOTIFICATION       GL_DEBUG_SEVERITY_NOTIFICATION_KHR
#define glPushDebugGroup                     glPushDebugGroupKHR
#define glPopDebugGroup                      glPopDebugGroupKHR
#endif
#endif


#ifndef APIENTRY
# ifdef GLAPIENTRY
#  define APIENTRY GLAPIENTRY
# elif defined(GL_APIENTRY)
#  define APIENTRY GL_APIENTRY
# else
#  define APIENTRY
# endif
#endif

extern void APIENTRY DebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const GLvoid* userParam);

template <typename T>
T** InitializeListOfLists(int resourceId, std::vector<uint8_t>& retvalData, Serialization::BlobProxy<uint8_t*>& dataProxy);
#define NV_GET_LIST_OF_LISTS(_PtrType, _Handle, _RetValData, _DataProxy) InitializeListOfLists<_PtrType>(_Handle, _RetValData, _DataProxy)

template <typename T>
class ConfigSelector
{
public:
    inline T GetConfig() const
    {
        return (m_configs.size() > 0 ? *m_configs.begin() : 0);
    }

    inline int GetConfigs(T* configs, int num) const
    {
        int total = std::min(num, int(m_configs.size()));
        int i = 0;
        for (typename std::set<T>::const_iterator it = m_configs.begin(); it != m_configs.end(); ++it)
        {
            configs[i++] = *it;
        }
        return total;
    }

    void IntersectConfigs(const T* configs, int num)
    {
        if (!configs)
        {
            return;
        }

        std::set<T> setConfigs(configs, configs + num);

        // Compute intersections between two sets
        if (m_init)
        {
            m_init = false;
            m_configs.swap(setConfigs);
        }
        else
        {
            std::set<T> intersection;
            std::set_intersection(m_configs.begin(), m_configs.end(), setConfigs.begin(), setConfigs.end(), std::inserter(intersection, intersection.end()));
            m_configs.swap(intersection);
        }
    }

private:
    std::set<T> m_configs;
    bool m_init = true;
};
        


inline GLXFBConfig GLXChooseConfig(Display* dpy, const int* attrib_list, const GLXFBConfig* configs, int num_config)
{
    NV_THROW_IF(!attrib_list || !configs, "No valid attribute list or configs specified.");

    std::map<int, int> mapAttribs;
    for (int i = 0; attrib_list[i] != None; i += 2)
    {
        mapAttribs[attrib_list[i]] = attrib_list[i+1];
    }

    for (int i = 0; i < num_config; ++i)
    {
        bool isMatched = true;
        GLXFBConfig config = configs[i];
        for (std::map<int, int>::const_iterator it = mapAttribs.begin(); it != mapAttribs.end(); ++it)
        {
            int value = 0;
            if (0 != glXGetFBConfigAttrib(dpy, config, it->first, &value) || value != it->second)
            {
                isMatched = false;
                break;
            }
        }

        if (isMatched)
        {
            return config;
        }
    }
    return 0;
}


inline void MakeCurrentContextNull()
{
    auto display = glXGetCurrentDisplay();
    if (display) {
        glXMakeCurrent(display, None, NULL); 
    }
}
void InitializeDatabase();
Serialization::ReadOnlyDatabase& GetDatabase();
#if defined(__arm__)
template<typename T, typename DataScopeTrackerType>
T GetResources(DataScopeTrackerType& dataScopeTracker, Serialization::DATABASE_HANDLE handle)
{
    std::shared_ptr<Serialization::BlobProxyBase> spBlobProxy = GetDatabase().ReadShared<T>(handle);
    dataScopeTracker.AddBlobProxyToCurrentDataScope(spBlobProxy);
    return (std::static_pointer_cast<Serialization::BlobProxy<T> >(spBlobProxy))->Get();
}
#define NV_GET_RESOURCE(T, handle) GetResources<T>(dataScopeTracker, handle)
#define NV_GET_BYTECODE(T, releaseHandle, debugHandle) GetResources<T>(dataScopeTracker, useDebugBytecode ? debugHandle : releaseHandle)
#define NV_GET_RESOURCE_CHECKED(T, handle, size) GetResources<T>(dataScopeTracker, handle)
#else
#define NV_GET_RESOURCE(T, handle) GetDatabase().Read<T>(handle).Get()
#define NV_GET_BYTECODE(T, releaseHandle, debugHandle) GetDatabase().Read<T>(useDebugBytecode ? debugHandle : releaseHandle).Get()
template<typename T>
T GetResourceChecked(Serialization::DATABASE_HANDLE handle, size_t size)
{
    NV_THROW_IF(size != 0 && GetDatabase().GetSize(handle) != size, "Database size mismatch")
    return GetDatabase().Read<T>(handle).Get();
}
#define NV_GET_RESOURCE_CHECKED(T, handle, size) GetResourceChecked<T>(handle, size)
#endif //defined(__arm__)
extern void FreeCachedMemory();
