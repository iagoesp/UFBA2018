//-------------------------------------------------------------------------------
// File: ThreadPool.h
//
// Copyright (c) NVIDIA Corporation.  All rights reserved.
//-------------------------------------------------------------------------------

#include "ThreadPool.h"
#include "Application.h"
#include "ThreadPoolImpl.h"

//--------------------------------------------------------------------------------------
// NvHasMultithreadedReplay
//--------------------------------------------------------------------------------------
bool NvHasMultithreadedReplay()
{
    return Application::HasMultiThreadedReplay();
}
