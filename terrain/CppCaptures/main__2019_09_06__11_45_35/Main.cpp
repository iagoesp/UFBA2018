//-----------------------------------------------------------------------------
// Generated with NVIDIA Nsight Graphics 2019.3.0.0
// 
// File: Main.cpp
// 
//-----------------------------------------------------------------------------

// Defines the entry point that initializes and runs the serialized frame capture

#include "Application.h"

#ifdef NV_WIN32_SUBSYSTEM

#include <windows.h>

extern HINSTANCE currentInstance;

//-----------------------------------------------------------------------------
// WinMain
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    currentInstance = hInstance;

    Application::PlatformInstance().Execute(__argc, __argv);
}

#else

//-----------------------------------------------------------------------------
// main
//-----------------------------------------------------------------------------
int main(int argc, char** argv)
{
    Application::PlatformInstance().Execute(argc, argv);
}

#endif


