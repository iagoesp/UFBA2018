#include "Win32Application.h"

#include <windows.h>

#include "Helpers.h"

//------------------------------------------------------------------------------
// Win32Application
//------------------------------------------------------------------------------
Win32Application::Win32Application()
{
}

//------------------------------------------------------------------------------
// OutputMessage
//------------------------------------------------------------------------------
void Win32Application::OutputMessage(const std::string& message) const
{
#ifdef NV_WIN32_SUBSYSTEM
    if (!automated) {
        std::wstring wstr_message(message.begin(), message.end());
        MessageBox(NULL, wstr_message.c_str(), L"Nvda.Replayer", MB_ICONEXCLAMATION);
        return;
    }
#endif

    NV_MESSAGE(message.c_str());
}

//------------------------------------------------------------------------------
// ProcessMessages
//------------------------------------------------------------------------------
bool Win32Application::ProcessMessages()
{
    MSG msg;
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            return false;
        } else {
            // Translate and dispatch the message
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return true;
}

//------------------------------------------------------------------------------
// PlatformInstance
//------------------------------------------------------------------------------
Application& Application::PlatformInstance()
{
    static Win32Application app;
    return app;
}
