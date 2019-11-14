//---------------------------------------------------------------------------
// File: NvEW_GLX.cpp
//
// Distributed as part of NVIDIA Tegra Graphics Debugger serialization output.
//
// Copyright (c) NVIDIA Corporation.  All rights reserved.
//--------------------------------------------------------------------------

#include "NvEW_GLX.h"
#include <dlfcn.h>

#include "Helpers.h"

extern void* GetProcAddress(void* libHandle, const char* funcName);

static void* s_libHandle = nullptr;

//-----------------------------------------------------------------------------
// InitFunctions_GLX
//-----------------------------------------------------------------------------
void InitFunctions_GLX()
{
    s_libHandle = dlopen(pNameLibGLX, RTLD_NOW);
    NV_THROW_IF(!s_libHandle, "Failed to open GLX library");

    /* GLX_AMD_gpu_association */
#ifdef GLX_AMD_gpu_association
    __glXGetGPUIDsAMD = reinterpret_cast<PFNGLXGETGPUIDSAMDPROC>(GetProcAddress(s_libHandle, "glXGetGPUIDsAMD"));
    __glXGetGPUInfoAMD = reinterpret_cast<PFNGLXGETGPUINFOAMDPROC>(GetProcAddress(s_libHandle, "glXGetGPUInfoAMD"));
    __glXGetContextGPUIDAMD = reinterpret_cast<PFNGLXGETCONTEXTGPUIDAMDPROC>(GetProcAddress(s_libHandle, "glXGetContextGPUIDAMD"));
    __glXCreateAssociatedContextAMD = reinterpret_cast<PFNGLXCREATEASSOCIATEDCONTEXTAMDPROC>(GetProcAddress(s_libHandle, "glXCreateAssociatedContextAMD"));
    __glXCreateAssociatedContextAttribsAMD = reinterpret_cast<PFNGLXCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC>(GetProcAddress(s_libHandle, "glXCreateAssociatedContextAttribsAMD"));
    __glXDeleteAssociatedContextAMD = reinterpret_cast<PFNGLXDELETEASSOCIATEDCONTEXTAMDPROC>(GetProcAddress(s_libHandle, "glXDeleteAssociatedContextAMD"));
    __glXMakeAssociatedContextCurrentAMD = reinterpret_cast<PFNGLXMAKEASSOCIATEDCONTEXTCURRENTAMDPROC>(GetProcAddress(s_libHandle, "glXMakeAssociatedContextCurrentAMD"));
    __glXGetCurrentAssociatedContextAMD = reinterpret_cast<PFNGLXGETCURRENTASSOCIATEDCONTEXTAMDPROC>(GetProcAddress(s_libHandle, "glXGetCurrentAssociatedContextAMD"));
    __glXBlitContextFramebufferAMD = reinterpret_cast<PFNGLXBLITCONTEXTFRAMEBUFFERAMDPROC>(GetProcAddress(s_libHandle, "glXBlitContextFramebufferAMD"));
#endif

    /* GLX_ARB_create_context */
#ifdef GLX_ARB_create_context
    __glXCreateContextAttribsARB = reinterpret_cast<PFNGLXCREATECONTEXTATTRIBSARBPROC>(GetProcAddress(s_libHandle, "glXCreateContextAttribsARB"));
#endif

    /* GLX_ARB_get_proc_address */
#ifdef GLX_ARB_get_proc_address
    __glXGetProcAddressARB = reinterpret_cast<PFNGLXGETPROCADDRESSARBPROC>(GetProcAddress(s_libHandle, "glXGetProcAddressARB"));
#endif

    /* GLX_EXT_import_context */
#ifdef GLX_EXT_import_context
    __glXGetCurrentDisplayEXT = reinterpret_cast<PFNGLXGETCURRENTDISPLAYEXTPROC>(GetProcAddress(s_libHandle, "glXGetCurrentDisplayEXT"));
    __glXQueryContextInfoEXT = reinterpret_cast<PFNGLXQUERYCONTEXTINFOEXTPROC>(GetProcAddress(s_libHandle, "glXQueryContextInfoEXT"));
    __glXGetContextIDEXT = reinterpret_cast<PFNGLXGETCONTEXTIDEXTPROC>(GetProcAddress(s_libHandle, "glXGetContextIDEXT"));
    __glXImportContextEXT = reinterpret_cast<PFNGLXIMPORTCONTEXTEXTPROC>(GetProcAddress(s_libHandle, "glXImportContextEXT"));
    __glXFreeContextEXT = reinterpret_cast<PFNGLXFREECONTEXTEXTPROC>(GetProcAddress(s_libHandle, "glXFreeContextEXT"));
#endif

    /* GLX_EXT_swap_control */
#ifdef GLX_EXT_swap_control
    __glXSwapIntervalEXT = reinterpret_cast<PFNGLXSWAPINTERVALEXTPROC>(GetProcAddress(s_libHandle, "glXSwapIntervalEXT"));
#endif

    /* GLX_EXT_texture_from_pixmap */
#ifdef GLX_EXT_texture_from_pixmap
    __glXBindTexImageEXT = reinterpret_cast<PFNGLXBINDTEXIMAGEEXTPROC>(GetProcAddress(s_libHandle, "glXBindTexImageEXT"));
    __glXReleaseTexImageEXT = reinterpret_cast<PFNGLXRELEASETEXIMAGEEXTPROC>(GetProcAddress(s_libHandle, "glXReleaseTexImageEXT"));
#endif

    /* GLX_MESA_agp_offset */
#ifdef GLX_MESA_agp_offset
    __glXGetAGPOffsetMESA = reinterpret_cast<PFNGLXGETAGPOFFSETMESAPROC>(GetProcAddress(s_libHandle, "glXGetAGPOffsetMESA"));
#endif

    /* GLX_MESA_copy_sub_buffer */
#ifdef GLX_MESA_copy_sub_buffer
    __glXCopySubBufferMESA = reinterpret_cast<PFNGLXCOPYSUBBUFFERMESAPROC>(GetProcAddress(s_libHandle, "glXCopySubBufferMESA"));
#endif

    /* GLX_MESA_pixmap_colormap */
#ifdef GLX_MESA_pixmap_colormap
    __glXCreateGLXPixmapMESA = reinterpret_cast<PFNGLXCREATEGLXPIXMAPMESAPROC>(GetProcAddress(s_libHandle, "glXCreateGLXPixmapMESA"));
#endif

    /* GLX_MESA_query_renderer */
#ifdef GLX_MESA_query_renderer
    __glXQueryCurrentRendererIntegerMESA = reinterpret_cast<PFNGLXQUERYCURRENTRENDERERINTEGERMESAPROC>(GetProcAddress(s_libHandle, "glXQueryCurrentRendererIntegerMESA"));
    __glXQueryCurrentRendererStringMESA = reinterpret_cast<PFNGLXQUERYCURRENTRENDERERSTRINGMESAPROC>(GetProcAddress(s_libHandle, "glXQueryCurrentRendererStringMESA"));
    __glXQueryRendererIntegerMESA = reinterpret_cast<PFNGLXQUERYRENDERERINTEGERMESAPROC>(GetProcAddress(s_libHandle, "glXQueryRendererIntegerMESA"));
    __glXQueryRendererStringMESA = reinterpret_cast<PFNGLXQUERYRENDERERSTRINGMESAPROC>(GetProcAddress(s_libHandle, "glXQueryRendererStringMESA"));
#endif

    /* GLX_MESA_release_buffers */
#ifdef GLX_MESA_release_buffers
    __glXReleaseBuffersMESA = reinterpret_cast<PFNGLXRELEASEBUFFERSMESAPROC>(GetProcAddress(s_libHandle, "glXReleaseBuffersMESA"));
#endif

    /* GLX_MESA_set_3dfx_mode */
#ifdef GLX_MESA_set_3dfx_mode
    __glXSet3DfxModeMESA = reinterpret_cast<PFNGLXSET3DFXMODEMESAPROC>(GetProcAddress(s_libHandle, "glXSet3DfxModeMESA"));
#endif

    /* GLX_NV_copy_buffer */
#ifdef GLX_NV_copy_buffer
    __glXCopyBufferSubDataNV = reinterpret_cast<PFNGLXCOPYBUFFERSUBDATANVPROC>(GetProcAddress(s_libHandle, "glXCopyBufferSubDataNV"));
    __glXNamedCopyBufferSubDataNV = reinterpret_cast<PFNGLXNAMEDCOPYBUFFERSUBDATANVPROC>(GetProcAddress(s_libHandle, "glXNamedCopyBufferSubDataNV"));
#endif

    /* GLX_NV_copy_image */
#ifdef GLX_NV_copy_image
    __glXCopyImageSubDataNV = reinterpret_cast<PFNGLXCOPYIMAGESUBDATANVPROC>(GetProcAddress(s_libHandle, "glXCopyImageSubDataNV"));
#endif

    /* GLX_NV_delay_before_swap */
#ifdef GLX_NV_delay_before_swap
    __glXDelayBeforeSwapNV = reinterpret_cast<PFNGLXDELAYBEFORESWAPNVPROC>(GetProcAddress(s_libHandle, "glXDelayBeforeSwapNV"));
#endif

    /* GLX_NV_present_video */
#ifdef GLX_NV_present_video
    __glXEnumerateVideoDevicesNV = reinterpret_cast<PFNGLXENUMERATEVIDEODEVICESNVPROC>(GetProcAddress(s_libHandle, "glXEnumerateVideoDevicesNV"));
    __glXBindVideoDeviceNV = reinterpret_cast<PFNGLXBINDVIDEODEVICENVPROC>(GetProcAddress(s_libHandle, "glXBindVideoDeviceNV"));
#endif

    /* GLX_NV_swap_group */
#ifdef GLX_NV_swap_group
    __glXJoinSwapGroupNV = reinterpret_cast<PFNGLXJOINSWAPGROUPNVPROC>(GetProcAddress(s_libHandle, "glXJoinSwapGroupNV"));
    __glXBindSwapBarrierNV = reinterpret_cast<PFNGLXBINDSWAPBARRIERNVPROC>(GetProcAddress(s_libHandle, "glXBindSwapBarrierNV"));
    __glXQuerySwapGroupNV = reinterpret_cast<PFNGLXQUERYSWAPGROUPNVPROC>(GetProcAddress(s_libHandle, "glXQuerySwapGroupNV"));
    __glXQueryMaxSwapGroupsNV = reinterpret_cast<PFNGLXQUERYMAXSWAPGROUPSNVPROC>(GetProcAddress(s_libHandle, "glXQueryMaxSwapGroupsNV"));
    __glXQueryFrameCountNV = reinterpret_cast<PFNGLXQUERYFRAMECOUNTNVPROC>(GetProcAddress(s_libHandle, "glXQueryFrameCountNV"));
    __glXResetFrameCountNV = reinterpret_cast<PFNGLXRESETFRAMECOUNTNVPROC>(GetProcAddress(s_libHandle, "glXResetFrameCountNV"));
#endif

    /* GLX_NV_video_capture */
#ifdef GLX_NV_video_capture
    __glXBindVideoCaptureDeviceNV = reinterpret_cast<PFNGLXBINDVIDEOCAPTUREDEVICENVPROC>(GetProcAddress(s_libHandle, "glXBindVideoCaptureDeviceNV"));
    __glXEnumerateVideoCaptureDevicesNV = reinterpret_cast<PFNGLXENUMERATEVIDEOCAPTUREDEVICESNVPROC>(GetProcAddress(s_libHandle, "glXEnumerateVideoCaptureDevicesNV"));
    __glXLockVideoCaptureDeviceNV = reinterpret_cast<PFNGLXLOCKVIDEOCAPTUREDEVICENVPROC>(GetProcAddress(s_libHandle, "glXLockVideoCaptureDeviceNV"));
    __glXQueryVideoCaptureDeviceNV = reinterpret_cast<PFNGLXQUERYVIDEOCAPTUREDEVICENVPROC>(GetProcAddress(s_libHandle, "glXQueryVideoCaptureDeviceNV"));
    __glXReleaseVideoCaptureDeviceNV = reinterpret_cast<PFNGLXRELEASEVIDEOCAPTUREDEVICENVPROC>(GetProcAddress(s_libHandle, "glXReleaseVideoCaptureDeviceNV"));
#endif

    /* GLX_NV_video_out */
#ifdef GLX_NV_video_out
    __glXGetVideoDeviceNV = reinterpret_cast<PFNGLXGETVIDEODEVICENVPROC>(GetProcAddress(s_libHandle, "glXGetVideoDeviceNV"));
    __glXReleaseVideoDeviceNV = reinterpret_cast<PFNGLXRELEASEVIDEODEVICENVPROC>(GetProcAddress(s_libHandle, "glXReleaseVideoDeviceNV"));
    __glXBindVideoImageNV = reinterpret_cast<PFNGLXBINDVIDEOIMAGENVPROC>(GetProcAddress(s_libHandle, "glXBindVideoImageNV"));
    __glXReleaseVideoImageNV = reinterpret_cast<PFNGLXRELEASEVIDEOIMAGENVPROC>(GetProcAddress(s_libHandle, "glXReleaseVideoImageNV"));
    __glXSendPbufferToVideoNV = reinterpret_cast<PFNGLXSENDPBUFFERTOVIDEONVPROC>(GetProcAddress(s_libHandle, "glXSendPbufferToVideoNV"));
    __glXGetVideoInfoNV = reinterpret_cast<PFNGLXGETVIDEOINFONVPROC>(GetProcAddress(s_libHandle, "glXGetVideoInfoNV"));
#endif

    /* GLX_OML_sync_control */
#ifdef GLX_OML_sync_control
    __glXGetSyncValuesOML = reinterpret_cast<PFNGLXGETSYNCVALUESOMLPROC>(GetProcAddress(s_libHandle, "glXGetSyncValuesOML"));
    __glXGetMscRateOML = reinterpret_cast<PFNGLXGETMSCRATEOMLPROC>(GetProcAddress(s_libHandle, "glXGetMscRateOML"));
    __glXSwapBuffersMscOML = reinterpret_cast<PFNGLXSWAPBUFFERSMSCOMLPROC>(GetProcAddress(s_libHandle, "glXSwapBuffersMscOML"));
    __glXWaitForMscOML = reinterpret_cast<PFNGLXWAITFORMSCOMLPROC>(GetProcAddress(s_libHandle, "glXWaitForMscOML"));
    __glXWaitForSbcOML = reinterpret_cast<PFNGLXWAITFORSBCOMLPROC>(GetProcAddress(s_libHandle, "glXWaitForSbcOML"));
#endif

    /* GLX_SGI_cushion */
#ifdef GLX_SGI_cushion
    __glXCushionSGI = reinterpret_cast<PFNGLXCUSHIONSGIPROC>(GetProcAddress(s_libHandle, "glXCushionSGI"));
#endif

    /* GLX_SGI_make_current_read */
#ifdef GLX_SGI_make_current_read
    __glXMakeCurrentReadSGI = reinterpret_cast<PFNGLXMAKECURRENTREADSGIPROC>(GetProcAddress(s_libHandle, "glXMakeCurrentReadSGI"));
    __glXGetCurrentReadDrawableSGI = reinterpret_cast<PFNGLXGETCURRENTREADDRAWABLESGIPROC>(GetProcAddress(s_libHandle, "glXGetCurrentReadDrawableSGI"));
#endif

    /* GLX_SGI_swap_control */
#ifdef GLX_SGI_swap_control
    __glXSwapIntervalSGI = reinterpret_cast<PFNGLXSWAPINTERVALSGIPROC>(GetProcAddress(s_libHandle, "glXSwapIntervalSGI"));
#endif

    /* GLX_SGI_video_sync */
#ifdef GLX_SGI_video_sync
    __glXGetVideoSyncSGI = reinterpret_cast<PFNGLXGETVIDEOSYNCSGIPROC>(GetProcAddress(s_libHandle, "glXGetVideoSyncSGI"));
    __glXWaitVideoSyncSGI = reinterpret_cast<PFNGLXWAITVIDEOSYNCSGIPROC>(GetProcAddress(s_libHandle, "glXWaitVideoSyncSGI"));
#endif

    /* GLX_SGIX_dmbuffer */
#ifdef GLX_SGIX_dmbuffer
    __glXAssociateDMPbufferSGIX = reinterpret_cast<PFNGLXASSOCIATEDMPBUFFERSGIXPROC>(GetProcAddress(s_libHandle, "glXAssociateDMPbufferSGIX"));
#endif

    /* GLX_SGIX_fbconfig */
#ifdef GLX_SGIX_fbconfig
    __glXGetFBConfigAttribSGIX = reinterpret_cast<PFNGLXGETFBCONFIGATTRIBSGIXPROC>(GetProcAddress(s_libHandle, "glXGetFBConfigAttribSGIX"));
    __glXChooseFBConfigSGIX = reinterpret_cast<PFNGLXCHOOSEFBCONFIGSGIXPROC>(GetProcAddress(s_libHandle, "glXChooseFBConfigSGIX"));
    __glXCreateGLXPixmapWithConfigSGIX = reinterpret_cast<PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC>(GetProcAddress(s_libHandle, "glXCreateGLXPixmapWithConfigSGIX"));
    __glXCreateContextWithConfigSGIX = reinterpret_cast<PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC>(GetProcAddress(s_libHandle, "glXCreateContextWithConfigSGIX"));
    __glXGetVisualFromFBConfigSGIX = reinterpret_cast<PFNGLXGETVISUALFROMFBCONFIGSGIXPROC>(GetProcAddress(s_libHandle, "glXGetVisualFromFBConfigSGIX"));
    __glXGetFBConfigFromVisualSGIX = reinterpret_cast<PFNGLXGETFBCONFIGFROMVISUALSGIXPROC>(GetProcAddress(s_libHandle, "glXGetFBConfigFromVisualSGIX"));
#endif

    /* GLX_SGIX_hyperpipe */
#ifdef GLX_SGIX_hyperpipe
    __glXQueryHyperpipeNetworkSGIX = reinterpret_cast<PFNGLXQUERYHYPERPIPENETWORKSGIXPROC>(GetProcAddress(s_libHandle, "glXQueryHyperpipeNetworkSGIX"));
    __glXHyperpipeConfigSGIX = reinterpret_cast<PFNGLXHYPERPIPECONFIGSGIXPROC>(GetProcAddress(s_libHandle, "glXHyperpipeConfigSGIX"));
    __glXQueryHyperpipeConfigSGIX = reinterpret_cast<PFNGLXQUERYHYPERPIPECONFIGSGIXPROC>(GetProcAddress(s_libHandle, "glXQueryHyperpipeConfigSGIX"));
    __glXDestroyHyperpipeConfigSGIX = reinterpret_cast<PFNGLXDESTROYHYPERPIPECONFIGSGIXPROC>(GetProcAddress(s_libHandle, "glXDestroyHyperpipeConfigSGIX"));
    __glXBindHyperpipeSGIX = reinterpret_cast<PFNGLXBINDHYPERPIPESGIXPROC>(GetProcAddress(s_libHandle, "glXBindHyperpipeSGIX"));
    __glXQueryHyperpipeBestAttribSGIX = reinterpret_cast<PFNGLXQUERYHYPERPIPEBESTATTRIBSGIXPROC>(GetProcAddress(s_libHandle, "glXQueryHyperpipeBestAttribSGIX"));
    __glXHyperpipeAttribSGIX = reinterpret_cast<PFNGLXHYPERPIPEATTRIBSGIXPROC>(GetProcAddress(s_libHandle, "glXHyperpipeAttribSGIX"));
    __glXQueryHyperpipeAttribSGIX = reinterpret_cast<PFNGLXQUERYHYPERPIPEATTRIBSGIXPROC>(GetProcAddress(s_libHandle, "glXQueryHyperpipeAttribSGIX"));
#endif

    /* GLX_SGIX_pbuffer */
#ifdef GLX_SGIX_pbuffer
    __glXCreateGLXPbufferSGIX = reinterpret_cast<PFNGLXCREATEGLXPBUFFERSGIXPROC>(GetProcAddress(s_libHandle, "glXCreateGLXPbufferSGIX"));
    __glXDestroyGLXPbufferSGIX = reinterpret_cast<PFNGLXDESTROYGLXPBUFFERSGIXPROC>(GetProcAddress(s_libHandle, "glXDestroyGLXPbufferSGIX"));
    __glXQueryGLXPbufferSGIX = reinterpret_cast<PFNGLXQUERYGLXPBUFFERSGIXPROC>(GetProcAddress(s_libHandle, "glXQueryGLXPbufferSGIX"));
    __glXSelectEventSGIX = reinterpret_cast<PFNGLXSELECTEVENTSGIXPROC>(GetProcAddress(s_libHandle, "glXSelectEventSGIX"));
    __glXGetSelectedEventSGIX = reinterpret_cast<PFNGLXGETSELECTEDEVENTSGIXPROC>(GetProcAddress(s_libHandle, "glXGetSelectedEventSGIX"));
#endif

    /* GLX_SGIX_swap_barrier */
#ifdef GLX_SGIX_swap_barrier
    __glXBindSwapBarrierSGIX = reinterpret_cast<PFNGLXBINDSWAPBARRIERSGIXPROC>(GetProcAddress(s_libHandle, "glXBindSwapBarrierSGIX"));
    __glXQueryMaxSwapBarriersSGIX = reinterpret_cast<PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC>(GetProcAddress(s_libHandle, "glXQueryMaxSwapBarriersSGIX"));
#endif

    /* GLX_SGIX_swap_group */
#ifdef GLX_SGIX_swap_group
    __glXJoinSwapGroupSGIX = reinterpret_cast<PFNGLXJOINSWAPGROUPSGIXPROC>(GetProcAddress(s_libHandle, "glXJoinSwapGroupSGIX"));
#endif

    /* GLX_SGIX_video_resize */
#ifdef GLX_SGIX_video_resize
    __glXBindChannelToWindowSGIX = reinterpret_cast<PFNGLXBINDCHANNELTOWINDOWSGIXPROC>(GetProcAddress(s_libHandle, "glXBindChannelToWindowSGIX"));
    __glXChannelRectSGIX = reinterpret_cast<PFNGLXCHANNELRECTSGIXPROC>(GetProcAddress(s_libHandle, "glXChannelRectSGIX"));
    __glXQueryChannelRectSGIX = reinterpret_cast<PFNGLXQUERYCHANNELRECTSGIXPROC>(GetProcAddress(s_libHandle, "glXQueryChannelRectSGIX"));
    __glXQueryChannelDeltasSGIX = reinterpret_cast<PFNGLXQUERYCHANNELDELTASSGIXPROC>(GetProcAddress(s_libHandle, "glXQueryChannelDeltasSGIX"));
    __glXChannelRectSyncSGIX = reinterpret_cast<PFNGLXCHANNELRECTSYNCSGIXPROC>(GetProcAddress(s_libHandle, "glXChannelRectSyncSGIX"));
#endif

    /* GLX_SGIX_video_source */
#ifdef GLX_SGIX_video_source
    __glXCreateGLXVideoSourceSGIX = reinterpret_cast<PFNGLXCREATEGLXVIDEOSOURCESGIXPROC>(GetProcAddress(s_libHandle, "glXCreateGLXVideoSourceSGIX"));
    __glXDestroyGLXVideoSourceSGIX = reinterpret_cast<PFNGLXDESTROYGLXVIDEOSOURCESGIXPROC>(GetProcAddress(s_libHandle, "glXDestroyGLXVideoSourceSGIX"));
#endif

    /* GLX_SUN_get_transparent_index */
#ifdef GLX_SUN_get_transparent_index
    __glXGetTransparentIndexSUN = reinterpret_cast<PFNGLXGETTRANSPARENTINDEXSUNPROC>(GetProcAddress(s_libHandle, "glXGetTransparentIndexSUN"));
#endif

}

//-----------------------------------------------------------------------------
// DeInitFunctions_GLX
//-----------------------------------------------------------------------------
void DeInitFunctions_GLX()
{
    dlclose(s_libHandle);
    s_libHandle = nullptr;
}

/* GLX_AMD_gpu_association */
#ifdef GLX_AMD_gpu_association
PFNGLXGETGPUIDSAMDPROC __glXGetGPUIDsAMD = NULL;
PFNGLXGETGPUINFOAMDPROC __glXGetGPUInfoAMD = NULL;
PFNGLXGETCONTEXTGPUIDAMDPROC __glXGetContextGPUIDAMD = NULL;
PFNGLXCREATEASSOCIATEDCONTEXTAMDPROC __glXCreateAssociatedContextAMD = NULL;
PFNGLXCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC __glXCreateAssociatedContextAttribsAMD = NULL;
PFNGLXDELETEASSOCIATEDCONTEXTAMDPROC __glXDeleteAssociatedContextAMD = NULL;
PFNGLXMAKEASSOCIATEDCONTEXTCURRENTAMDPROC __glXMakeAssociatedContextCurrentAMD = NULL;
PFNGLXGETCURRENTASSOCIATEDCONTEXTAMDPROC __glXGetCurrentAssociatedContextAMD = NULL;
PFNGLXBLITCONTEXTFRAMEBUFFERAMDPROC __glXBlitContextFramebufferAMD = NULL;
#endif

/* GLX_ARB_create_context */
#ifdef GLX_ARB_create_context
PFNGLXCREATECONTEXTATTRIBSARBPROC __glXCreateContextAttribsARB = NULL;
#endif

/* GLX_ARB_get_proc_address */
#ifdef GLX_ARB_get_proc_address
PFNGLXGETPROCADDRESSARBPROC __glXGetProcAddressARB = NULL;
#endif

/* GLX_EXT_import_context */
#ifdef GLX_EXT_import_context
PFNGLXGETCURRENTDISPLAYEXTPROC __glXGetCurrentDisplayEXT = NULL;
PFNGLXQUERYCONTEXTINFOEXTPROC __glXQueryContextInfoEXT = NULL;
PFNGLXGETCONTEXTIDEXTPROC __glXGetContextIDEXT = NULL;
PFNGLXIMPORTCONTEXTEXTPROC __glXImportContextEXT = NULL;
PFNGLXFREECONTEXTEXTPROC __glXFreeContextEXT = NULL;
#endif

/* GLX_EXT_swap_control */
#ifdef GLX_EXT_swap_control
PFNGLXSWAPINTERVALEXTPROC __glXSwapIntervalEXT = NULL;
#endif

/* GLX_EXT_texture_from_pixmap */
#ifdef GLX_EXT_texture_from_pixmap
PFNGLXBINDTEXIMAGEEXTPROC __glXBindTexImageEXT = NULL;
PFNGLXRELEASETEXIMAGEEXTPROC __glXReleaseTexImageEXT = NULL;
#endif

/* GLX_MESA_agp_offset */
#ifdef GLX_MESA_agp_offset
PFNGLXGETAGPOFFSETMESAPROC __glXGetAGPOffsetMESA = NULL;
#endif

/* GLX_MESA_copy_sub_buffer */
#ifdef GLX_MESA_copy_sub_buffer
PFNGLXCOPYSUBBUFFERMESAPROC __glXCopySubBufferMESA = NULL;
#endif

/* GLX_MESA_pixmap_colormap */
#ifdef GLX_MESA_pixmap_colormap
PFNGLXCREATEGLXPIXMAPMESAPROC __glXCreateGLXPixmapMESA = NULL;
#endif

/* GLX_MESA_query_renderer */
#ifdef GLX_MESA_query_renderer
PFNGLXQUERYCURRENTRENDERERINTEGERMESAPROC __glXQueryCurrentRendererIntegerMESA = NULL;
PFNGLXQUERYCURRENTRENDERERSTRINGMESAPROC __glXQueryCurrentRendererStringMESA = NULL;
PFNGLXQUERYRENDERERINTEGERMESAPROC __glXQueryRendererIntegerMESA = NULL;
PFNGLXQUERYRENDERERSTRINGMESAPROC __glXQueryRendererStringMESA = NULL;
#endif

/* GLX_MESA_release_buffers */
#ifdef GLX_MESA_release_buffers
PFNGLXRELEASEBUFFERSMESAPROC __glXReleaseBuffersMESA = NULL;
#endif

/* GLX_MESA_set_3dfx_mode */
#ifdef GLX_MESA_set_3dfx_mode
PFNGLXSET3DFXMODEMESAPROC __glXSet3DfxModeMESA = NULL;
#endif

/* GLX_NV_copy_buffer */
#ifdef GLX_NV_copy_buffer
PFNGLXCOPYBUFFERSUBDATANVPROC __glXCopyBufferSubDataNV = NULL;
PFNGLXNAMEDCOPYBUFFERSUBDATANVPROC __glXNamedCopyBufferSubDataNV = NULL;
#endif

/* GLX_NV_copy_image */
#ifdef GLX_NV_copy_image
PFNGLXCOPYIMAGESUBDATANVPROC __glXCopyImageSubDataNV = NULL;
#endif

/* GLX_NV_delay_before_swap */
#ifdef GLX_NV_delay_before_swap
PFNGLXDELAYBEFORESWAPNVPROC __glXDelayBeforeSwapNV = NULL;
#endif

/* GLX_NV_present_video */
#ifdef GLX_NV_present_video
PFNGLXENUMERATEVIDEODEVICESNVPROC __glXEnumerateVideoDevicesNV = NULL;
PFNGLXBINDVIDEODEVICENVPROC __glXBindVideoDeviceNV = NULL;
#endif

/* GLX_NV_swap_group */
#ifdef GLX_NV_swap_group
PFNGLXJOINSWAPGROUPNVPROC __glXJoinSwapGroupNV = NULL;
PFNGLXBINDSWAPBARRIERNVPROC __glXBindSwapBarrierNV = NULL;
PFNGLXQUERYSWAPGROUPNVPROC __glXQuerySwapGroupNV = NULL;
PFNGLXQUERYMAXSWAPGROUPSNVPROC __glXQueryMaxSwapGroupsNV = NULL;
PFNGLXQUERYFRAMECOUNTNVPROC __glXQueryFrameCountNV = NULL;
PFNGLXRESETFRAMECOUNTNVPROC __glXResetFrameCountNV = NULL;
#endif

/* GLX_NV_video_capture */
#ifdef GLX_NV_video_capture
PFNGLXBINDVIDEOCAPTUREDEVICENVPROC __glXBindVideoCaptureDeviceNV = NULL;
PFNGLXENUMERATEVIDEOCAPTUREDEVICESNVPROC __glXEnumerateVideoCaptureDevicesNV = NULL;
PFNGLXLOCKVIDEOCAPTUREDEVICENVPROC __glXLockVideoCaptureDeviceNV = NULL;
PFNGLXQUERYVIDEOCAPTUREDEVICENVPROC __glXQueryVideoCaptureDeviceNV = NULL;
PFNGLXRELEASEVIDEOCAPTUREDEVICENVPROC __glXReleaseVideoCaptureDeviceNV = NULL;
#endif

/* GLX_NV_video_out */
#ifdef GLX_NV_video_out
PFNGLXGETVIDEODEVICENVPROC __glXGetVideoDeviceNV = NULL;
PFNGLXRELEASEVIDEODEVICENVPROC __glXReleaseVideoDeviceNV = NULL;
PFNGLXBINDVIDEOIMAGENVPROC __glXBindVideoImageNV = NULL;
PFNGLXRELEASEVIDEOIMAGENVPROC __glXReleaseVideoImageNV = NULL;
PFNGLXSENDPBUFFERTOVIDEONVPROC __glXSendPbufferToVideoNV = NULL;
PFNGLXGETVIDEOINFONVPROC __glXGetVideoInfoNV = NULL;
#endif

/* GLX_OML_sync_control */
#ifdef GLX_OML_sync_control
PFNGLXGETSYNCVALUESOMLPROC __glXGetSyncValuesOML = NULL;
PFNGLXGETMSCRATEOMLPROC __glXGetMscRateOML = NULL;
PFNGLXSWAPBUFFERSMSCOMLPROC __glXSwapBuffersMscOML = NULL;
PFNGLXWAITFORMSCOMLPROC __glXWaitForMscOML = NULL;
PFNGLXWAITFORSBCOMLPROC __glXWaitForSbcOML = NULL;
#endif

/* GLX_SGI_cushion */
#ifdef GLX_SGI_cushion
PFNGLXCUSHIONSGIPROC __glXCushionSGI = NULL;
#endif

/* GLX_SGI_make_current_read */
#ifdef GLX_SGI_make_current_read
PFNGLXMAKECURRENTREADSGIPROC __glXMakeCurrentReadSGI = NULL;
PFNGLXGETCURRENTREADDRAWABLESGIPROC __glXGetCurrentReadDrawableSGI = NULL;
#endif

/* GLX_SGI_swap_control */
#ifdef GLX_SGI_swap_control
PFNGLXSWAPINTERVALSGIPROC __glXSwapIntervalSGI = NULL;
#endif

/* GLX_SGI_video_sync */
#ifdef GLX_SGI_video_sync
PFNGLXGETVIDEOSYNCSGIPROC __glXGetVideoSyncSGI = NULL;
PFNGLXWAITVIDEOSYNCSGIPROC __glXWaitVideoSyncSGI = NULL;
#endif

/* GLX_SGIX_dmbuffer */
#ifdef GLX_SGIX_dmbuffer
PFNGLXASSOCIATEDMPBUFFERSGIXPROC __glXAssociateDMPbufferSGIX = NULL;
#endif

/* GLX_SGIX_fbconfig */
#ifdef GLX_SGIX_fbconfig
PFNGLXGETFBCONFIGATTRIBSGIXPROC __glXGetFBConfigAttribSGIX = NULL;
PFNGLXCHOOSEFBCONFIGSGIXPROC __glXChooseFBConfigSGIX = NULL;
PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC __glXCreateGLXPixmapWithConfigSGIX = NULL;
PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC __glXCreateContextWithConfigSGIX = NULL;
PFNGLXGETVISUALFROMFBCONFIGSGIXPROC __glXGetVisualFromFBConfigSGIX = NULL;
PFNGLXGETFBCONFIGFROMVISUALSGIXPROC __glXGetFBConfigFromVisualSGIX = NULL;
#endif

/* GLX_SGIX_hyperpipe */
#ifdef GLX_SGIX_hyperpipe
PFNGLXQUERYHYPERPIPENETWORKSGIXPROC __glXQueryHyperpipeNetworkSGIX = NULL;
PFNGLXHYPERPIPECONFIGSGIXPROC __glXHyperpipeConfigSGIX = NULL;
PFNGLXQUERYHYPERPIPECONFIGSGIXPROC __glXQueryHyperpipeConfigSGIX = NULL;
PFNGLXDESTROYHYPERPIPECONFIGSGIXPROC __glXDestroyHyperpipeConfigSGIX = NULL;
PFNGLXBINDHYPERPIPESGIXPROC __glXBindHyperpipeSGIX = NULL;
PFNGLXQUERYHYPERPIPEBESTATTRIBSGIXPROC __glXQueryHyperpipeBestAttribSGIX = NULL;
PFNGLXHYPERPIPEATTRIBSGIXPROC __glXHyperpipeAttribSGIX = NULL;
PFNGLXQUERYHYPERPIPEATTRIBSGIXPROC __glXQueryHyperpipeAttribSGIX = NULL;
#endif

/* GLX_SGIX_pbuffer */
#ifdef GLX_SGIX_pbuffer
PFNGLXCREATEGLXPBUFFERSGIXPROC __glXCreateGLXPbufferSGIX = NULL;
PFNGLXDESTROYGLXPBUFFERSGIXPROC __glXDestroyGLXPbufferSGIX = NULL;
PFNGLXQUERYGLXPBUFFERSGIXPROC __glXQueryGLXPbufferSGIX = NULL;
PFNGLXSELECTEVENTSGIXPROC __glXSelectEventSGIX = NULL;
PFNGLXGETSELECTEDEVENTSGIXPROC __glXGetSelectedEventSGIX = NULL;
#endif

/* GLX_SGIX_swap_barrier */
#ifdef GLX_SGIX_swap_barrier
PFNGLXBINDSWAPBARRIERSGIXPROC __glXBindSwapBarrierSGIX = NULL;
PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC __glXQueryMaxSwapBarriersSGIX = NULL;
#endif

/* GLX_SGIX_swap_group */
#ifdef GLX_SGIX_swap_group
PFNGLXJOINSWAPGROUPSGIXPROC __glXJoinSwapGroupSGIX = NULL;
#endif

/* GLX_SGIX_video_resize */
#ifdef GLX_SGIX_video_resize
PFNGLXBINDCHANNELTOWINDOWSGIXPROC __glXBindChannelToWindowSGIX = NULL;
PFNGLXCHANNELRECTSGIXPROC __glXChannelRectSGIX = NULL;
PFNGLXQUERYCHANNELRECTSGIXPROC __glXQueryChannelRectSGIX = NULL;
PFNGLXQUERYCHANNELDELTASSGIXPROC __glXQueryChannelDeltasSGIX = NULL;
PFNGLXCHANNELRECTSYNCSGIXPROC __glXChannelRectSyncSGIX = NULL;
#endif

/* GLX_SGIX_video_source */
#ifdef GLX_SGIX_video_source
PFNGLXCREATEGLXVIDEOSOURCESGIXPROC __glXCreateGLXVideoSourceSGIX = NULL;
PFNGLXDESTROYGLXVIDEOSOURCESGIXPROC __glXDestroyGLXVideoSourceSGIX = NULL;
#endif

/* GLX_SUN_get_transparent_index */
#ifdef GLX_SUN_get_transparent_index
PFNGLXGETTRANSPARENTINDEXSUNPROC __glXGetTransparentIndexSUN = NULL;
#endif

