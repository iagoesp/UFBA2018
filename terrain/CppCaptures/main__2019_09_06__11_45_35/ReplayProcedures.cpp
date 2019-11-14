//-----------------------------------------------------------------------------
// Generated with NVIDIA Nsight Graphics 2019.3.0.0
// 
// File: ReplayProcedures.cpp
// 
//-----------------------------------------------------------------------------

#include "Helpers.h"
#include "Resources.h"
#include "Threading.h"

//-----------------------------------------------------------------------------
// Replay Procedures
//-----------------------------------------------------------------------------
extern void SetInitialFrameState00();
extern void ResetInitialFrameState00(bool firstTime);
extern void RestoreEventRanges();
extern void TerminateEventRanges();
extern void SetupWinResources();
extern void ResetWinResources(bool firstTime);
extern void CreateResources00();
extern void OnBeforeWinResourcesInit00();
extern void CreateWinResources00();
extern void OnAfterWinResourcesInit00();
extern void ReleaseResources00();
extern void ReleaseWinResources00();
extern void OnAfterWinResourcesReleased00();

extern void RunFrame0Part00();

//-----------------------------------------------------------------------------
// CreateAndSetupResources
//-----------------------------------------------------------------------------
void CreateAndSetupResources()
{
    BEGIN_DATA_SCOPE_FUNCTION();

    InitializeDatabase();
    OnBeforeWinResourcesInit00();
    CreateWinResources00();
    OnAfterWinResourcesInit00();
    SetupWinResources();
    GetDatabase().SetForceEvict(true);
    CreateResources00();
    SetInitialFrameState00();
    GetDatabase().SetForceEvict(false);
}

//-----------------------------------------------------------------------------
// ReleaseResources
//-----------------------------------------------------------------------------
void ReleaseResources()
{
    BEGIN_DATA_SCOPE_FUNCTION();

    ReleaseResources00();
    ReleaseWinResources00();
    OnAfterWinResourcesReleased00();
}

//-----------------------------------------------------------------------------
// RunFrame
//-----------------------------------------------------------------------------
void RunFrame()
{
    BEGIN_DATA_SCOPE_FUNCTION();

    RestoreEventRanges();
    RunFrame0Part00();
    TerminateEventRanges();
    if (hasFrameReset)
    {
        BEGIN_DATA_SCOPE();

        ResetWinResources(false);
        ResetInitialFrameState00(false);
    }
}
