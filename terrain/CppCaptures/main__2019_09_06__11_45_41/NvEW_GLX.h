//---------------------------------------------------------------------------
// File: NvEW_GLX.h
//
// Distributed as part of NVIDIA Tegra Graphics Debugger serialization output.
//
// Copyright (c) NVIDIA Corporation.  All rights reserved.
//--------------------------------------------------------------------------

#pragma once

#include "nvglx.h"

/* GLX_AMD_gpu_association */
#ifdef GLX_AMD_gpu_association
extern PFNGLXGETGPUIDSAMDPROC __glXGetGPUIDsAMD;
#define glXGetGPUIDsAMD __glXGetGPUIDsAMD
extern PFNGLXGETGPUINFOAMDPROC __glXGetGPUInfoAMD;
#define glXGetGPUInfoAMD __glXGetGPUInfoAMD
extern PFNGLXGETCONTEXTGPUIDAMDPROC __glXGetContextGPUIDAMD;
#define glXGetContextGPUIDAMD __glXGetContextGPUIDAMD
extern PFNGLXCREATEASSOCIATEDCONTEXTAMDPROC __glXCreateAssociatedContextAMD;
#define glXCreateAssociatedContextAMD __glXCreateAssociatedContextAMD
extern PFNGLXCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC __glXCreateAssociatedContextAttribsAMD;
#define glXCreateAssociatedContextAttribsAMD __glXCreateAssociatedContextAttribsAMD
extern PFNGLXDELETEASSOCIATEDCONTEXTAMDPROC __glXDeleteAssociatedContextAMD;
#define glXDeleteAssociatedContextAMD __glXDeleteAssociatedContextAMD
extern PFNGLXMAKEASSOCIATEDCONTEXTCURRENTAMDPROC __glXMakeAssociatedContextCurrentAMD;
#define glXMakeAssociatedContextCurrentAMD __glXMakeAssociatedContextCurrentAMD
extern PFNGLXGETCURRENTASSOCIATEDCONTEXTAMDPROC __glXGetCurrentAssociatedContextAMD;
#define glXGetCurrentAssociatedContextAMD __glXGetCurrentAssociatedContextAMD
extern PFNGLXBLITCONTEXTFRAMEBUFFERAMDPROC __glXBlitContextFramebufferAMD;
#define glXBlitContextFramebufferAMD __glXBlitContextFramebufferAMD
#endif

/* GLX_ARB_create_context */
#ifdef GLX_ARB_create_context
extern PFNGLXCREATECONTEXTATTRIBSARBPROC __glXCreateContextAttribsARB;
#define glXCreateContextAttribsARB __glXCreateContextAttribsARB
#endif

/* GLX_ARB_get_proc_address */
#ifdef GLX_ARB_get_proc_address
extern PFNGLXGETPROCADDRESSARBPROC __glXGetProcAddressARB;
#define glXGetProcAddressARB __glXGetProcAddressARB
#endif

/* GLX_EXT_import_context */
#ifdef GLX_EXT_import_context
extern PFNGLXGETCURRENTDISPLAYEXTPROC __glXGetCurrentDisplayEXT;
#define glXGetCurrentDisplayEXT __glXGetCurrentDisplayEXT
extern PFNGLXQUERYCONTEXTINFOEXTPROC __glXQueryContextInfoEXT;
#define glXQueryContextInfoEXT __glXQueryContextInfoEXT
extern PFNGLXGETCONTEXTIDEXTPROC __glXGetContextIDEXT;
#define glXGetContextIDEXT __glXGetContextIDEXT
extern PFNGLXIMPORTCONTEXTEXTPROC __glXImportContextEXT;
#define glXImportContextEXT __glXImportContextEXT
extern PFNGLXFREECONTEXTEXTPROC __glXFreeContextEXT;
#define glXFreeContextEXT __glXFreeContextEXT
#endif

/* GLX_EXT_swap_control */
#ifdef GLX_EXT_swap_control
extern PFNGLXSWAPINTERVALEXTPROC __glXSwapIntervalEXT;
#define glXSwapIntervalEXT __glXSwapIntervalEXT
#endif

/* GLX_EXT_texture_from_pixmap */
#ifdef GLX_EXT_texture_from_pixmap
extern PFNGLXBINDTEXIMAGEEXTPROC __glXBindTexImageEXT;
#define glXBindTexImageEXT __glXBindTexImageEXT
extern PFNGLXRELEASETEXIMAGEEXTPROC __glXReleaseTexImageEXT;
#define glXReleaseTexImageEXT __glXReleaseTexImageEXT
#endif

/* GLX_MESA_agp_offset */
#ifdef GLX_MESA_agp_offset
extern PFNGLXGETAGPOFFSETMESAPROC __glXGetAGPOffsetMESA;
#define glXGetAGPOffsetMESA __glXGetAGPOffsetMESA
#endif

/* GLX_MESA_copy_sub_buffer */
#ifdef GLX_MESA_copy_sub_buffer
extern PFNGLXCOPYSUBBUFFERMESAPROC __glXCopySubBufferMESA;
#define glXCopySubBufferMESA __glXCopySubBufferMESA
#endif

/* GLX_MESA_pixmap_colormap */
#ifdef GLX_MESA_pixmap_colormap
extern PFNGLXCREATEGLXPIXMAPMESAPROC __glXCreateGLXPixmapMESA;
#define glXCreateGLXPixmapMESA __glXCreateGLXPixmapMESA
#endif

/* GLX_MESA_query_renderer */
#ifdef GLX_MESA_query_renderer
extern PFNGLXQUERYCURRENTRENDERERINTEGERMESAPROC __glXQueryCurrentRendererIntegerMESA;
#define glXQueryCurrentRendererIntegerMESA __glXQueryCurrentRendererIntegerMESA
extern PFNGLXQUERYCURRENTRENDERERSTRINGMESAPROC __glXQueryCurrentRendererStringMESA;
#define glXQueryCurrentRendererStringMESA __glXQueryCurrentRendererStringMESA
extern PFNGLXQUERYRENDERERINTEGERMESAPROC __glXQueryRendererIntegerMESA;
#define glXQueryRendererIntegerMESA __glXQueryRendererIntegerMESA
extern PFNGLXQUERYRENDERERSTRINGMESAPROC __glXQueryRendererStringMESA;
#define glXQueryRendererStringMESA __glXQueryRendererStringMESA
#endif

/* GLX_MESA_release_buffers */
#ifdef GLX_MESA_release_buffers
extern PFNGLXRELEASEBUFFERSMESAPROC __glXReleaseBuffersMESA;
#define glXReleaseBuffersMESA __glXReleaseBuffersMESA
#endif

/* GLX_MESA_set_3dfx_mode */
#ifdef GLX_MESA_set_3dfx_mode
extern PFNGLXSET3DFXMODEMESAPROC __glXSet3DfxModeMESA;
#define glXSet3DfxModeMESA __glXSet3DfxModeMESA
#endif

/* GLX_NV_copy_buffer */
#ifdef GLX_NV_copy_buffer
extern PFNGLXCOPYBUFFERSUBDATANVPROC __glXCopyBufferSubDataNV;
#define glXCopyBufferSubDataNV __glXCopyBufferSubDataNV
extern PFNGLXNAMEDCOPYBUFFERSUBDATANVPROC __glXNamedCopyBufferSubDataNV;
#define glXNamedCopyBufferSubDataNV __glXNamedCopyBufferSubDataNV
#endif

/* GLX_NV_copy_image */
#ifdef GLX_NV_copy_image
extern PFNGLXCOPYIMAGESUBDATANVPROC __glXCopyImageSubDataNV;
#define glXCopyImageSubDataNV __glXCopyImageSubDataNV
#endif

/* GLX_NV_delay_before_swap */
#ifdef GLX_NV_delay_before_swap
extern PFNGLXDELAYBEFORESWAPNVPROC __glXDelayBeforeSwapNV;
#define glXDelayBeforeSwapNV __glXDelayBeforeSwapNV
#endif

/* GLX_NV_present_video */
#ifdef GLX_NV_present_video
extern PFNGLXENUMERATEVIDEODEVICESNVPROC __glXEnumerateVideoDevicesNV;
#define glXEnumerateVideoDevicesNV __glXEnumerateVideoDevicesNV
extern PFNGLXBINDVIDEODEVICENVPROC __glXBindVideoDeviceNV;
#define glXBindVideoDeviceNV __glXBindVideoDeviceNV
#endif

/* GLX_NV_swap_group */
#ifdef GLX_NV_swap_group
extern PFNGLXJOINSWAPGROUPNVPROC __glXJoinSwapGroupNV;
#define glXJoinSwapGroupNV __glXJoinSwapGroupNV
extern PFNGLXBINDSWAPBARRIERNVPROC __glXBindSwapBarrierNV;
#define glXBindSwapBarrierNV __glXBindSwapBarrierNV
extern PFNGLXQUERYSWAPGROUPNVPROC __glXQuerySwapGroupNV;
#define glXQuerySwapGroupNV __glXQuerySwapGroupNV
extern PFNGLXQUERYMAXSWAPGROUPSNVPROC __glXQueryMaxSwapGroupsNV;
#define glXQueryMaxSwapGroupsNV __glXQueryMaxSwapGroupsNV
extern PFNGLXQUERYFRAMECOUNTNVPROC __glXQueryFrameCountNV;
#define glXQueryFrameCountNV __glXQueryFrameCountNV
extern PFNGLXRESETFRAMECOUNTNVPROC __glXResetFrameCountNV;
#define glXResetFrameCountNV __glXResetFrameCountNV
#endif

/* GLX_NV_video_capture */
#ifdef GLX_NV_video_capture
extern PFNGLXBINDVIDEOCAPTUREDEVICENVPROC __glXBindVideoCaptureDeviceNV;
#define glXBindVideoCaptureDeviceNV __glXBindVideoCaptureDeviceNV
extern PFNGLXENUMERATEVIDEOCAPTUREDEVICESNVPROC __glXEnumerateVideoCaptureDevicesNV;
#define glXEnumerateVideoCaptureDevicesNV __glXEnumerateVideoCaptureDevicesNV
extern PFNGLXLOCKVIDEOCAPTUREDEVICENVPROC __glXLockVideoCaptureDeviceNV;
#define glXLockVideoCaptureDeviceNV __glXLockVideoCaptureDeviceNV
extern PFNGLXQUERYVIDEOCAPTUREDEVICENVPROC __glXQueryVideoCaptureDeviceNV;
#define glXQueryVideoCaptureDeviceNV __glXQueryVideoCaptureDeviceNV
extern PFNGLXRELEASEVIDEOCAPTUREDEVICENVPROC __glXReleaseVideoCaptureDeviceNV;
#define glXReleaseVideoCaptureDeviceNV __glXReleaseVideoCaptureDeviceNV
#endif

/* GLX_NV_video_out */
#ifdef GLX_NV_video_out
extern PFNGLXGETVIDEODEVICENVPROC __glXGetVideoDeviceNV;
#define glXGetVideoDeviceNV __glXGetVideoDeviceNV
extern PFNGLXRELEASEVIDEODEVICENVPROC __glXReleaseVideoDeviceNV;
#define glXReleaseVideoDeviceNV __glXReleaseVideoDeviceNV
extern PFNGLXBINDVIDEOIMAGENVPROC __glXBindVideoImageNV;
#define glXBindVideoImageNV __glXBindVideoImageNV
extern PFNGLXRELEASEVIDEOIMAGENVPROC __glXReleaseVideoImageNV;
#define glXReleaseVideoImageNV __glXReleaseVideoImageNV
extern PFNGLXSENDPBUFFERTOVIDEONVPROC __glXSendPbufferToVideoNV;
#define glXSendPbufferToVideoNV __glXSendPbufferToVideoNV
extern PFNGLXGETVIDEOINFONVPROC __glXGetVideoInfoNV;
#define glXGetVideoInfoNV __glXGetVideoInfoNV
#endif

/* GLX_OML_sync_control */
#ifdef GLX_OML_sync_control
extern PFNGLXGETSYNCVALUESOMLPROC __glXGetSyncValuesOML;
#define glXGetSyncValuesOML __glXGetSyncValuesOML
extern PFNGLXGETMSCRATEOMLPROC __glXGetMscRateOML;
#define glXGetMscRateOML __glXGetMscRateOML
extern PFNGLXSWAPBUFFERSMSCOMLPROC __glXSwapBuffersMscOML;
#define glXSwapBuffersMscOML __glXSwapBuffersMscOML
extern PFNGLXWAITFORMSCOMLPROC __glXWaitForMscOML;
#define glXWaitForMscOML __glXWaitForMscOML
extern PFNGLXWAITFORSBCOMLPROC __glXWaitForSbcOML;
#define glXWaitForSbcOML __glXWaitForSbcOML
#endif

/* GLX_SGI_cushion */
#ifdef GLX_SGI_cushion
extern PFNGLXCUSHIONSGIPROC __glXCushionSGI;
#define glXCushionSGI __glXCushionSGI
#endif

/* GLX_SGI_make_current_read */
#ifdef GLX_SGI_make_current_read
extern PFNGLXMAKECURRENTREADSGIPROC __glXMakeCurrentReadSGI;
#define glXMakeCurrentReadSGI __glXMakeCurrentReadSGI
extern PFNGLXGETCURRENTREADDRAWABLESGIPROC __glXGetCurrentReadDrawableSGI;
#define glXGetCurrentReadDrawableSGI __glXGetCurrentReadDrawableSGI
#endif

/* GLX_SGI_swap_control */
#ifdef GLX_SGI_swap_control
extern PFNGLXSWAPINTERVALSGIPROC __glXSwapIntervalSGI;
#define glXSwapIntervalSGI __glXSwapIntervalSGI
#endif

/* GLX_SGI_video_sync */
#ifdef GLX_SGI_video_sync
extern PFNGLXGETVIDEOSYNCSGIPROC __glXGetVideoSyncSGI;
#define glXGetVideoSyncSGI __glXGetVideoSyncSGI
extern PFNGLXWAITVIDEOSYNCSGIPROC __glXWaitVideoSyncSGI;
#define glXWaitVideoSyncSGI __glXWaitVideoSyncSGI
#endif

/* GLX_SGIX_dmbuffer */
#ifdef GLX_SGIX_dmbuffer
extern PFNGLXASSOCIATEDMPBUFFERSGIXPROC __glXAssociateDMPbufferSGIX;
#define glXAssociateDMPbufferSGIX __glXAssociateDMPbufferSGIX
#endif

/* GLX_SGIX_fbconfig */
#ifdef GLX_SGIX_fbconfig
extern PFNGLXGETFBCONFIGATTRIBSGIXPROC __glXGetFBConfigAttribSGIX;
#define glXGetFBConfigAttribSGIX __glXGetFBConfigAttribSGIX
extern PFNGLXCHOOSEFBCONFIGSGIXPROC __glXChooseFBConfigSGIX;
#define glXChooseFBConfigSGIX __glXChooseFBConfigSGIX
extern PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC __glXCreateGLXPixmapWithConfigSGIX;
#define glXCreateGLXPixmapWithConfigSGIX __glXCreateGLXPixmapWithConfigSGIX
extern PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC __glXCreateContextWithConfigSGIX;
#define glXCreateContextWithConfigSGIX __glXCreateContextWithConfigSGIX
extern PFNGLXGETVISUALFROMFBCONFIGSGIXPROC __glXGetVisualFromFBConfigSGIX;
#define glXGetVisualFromFBConfigSGIX __glXGetVisualFromFBConfigSGIX
extern PFNGLXGETFBCONFIGFROMVISUALSGIXPROC __glXGetFBConfigFromVisualSGIX;
#define glXGetFBConfigFromVisualSGIX __glXGetFBConfigFromVisualSGIX
#endif

/* GLX_SGIX_hyperpipe */
#ifdef GLX_SGIX_hyperpipe
extern PFNGLXQUERYHYPERPIPENETWORKSGIXPROC __glXQueryHyperpipeNetworkSGIX;
#define glXQueryHyperpipeNetworkSGIX __glXQueryHyperpipeNetworkSGIX
extern PFNGLXHYPERPIPECONFIGSGIXPROC __glXHyperpipeConfigSGIX;
#define glXHyperpipeConfigSGIX __glXHyperpipeConfigSGIX
extern PFNGLXQUERYHYPERPIPECONFIGSGIXPROC __glXQueryHyperpipeConfigSGIX;
#define glXQueryHyperpipeConfigSGIX __glXQueryHyperpipeConfigSGIX
extern PFNGLXDESTROYHYPERPIPECONFIGSGIXPROC __glXDestroyHyperpipeConfigSGIX;
#define glXDestroyHyperpipeConfigSGIX __glXDestroyHyperpipeConfigSGIX
extern PFNGLXBINDHYPERPIPESGIXPROC __glXBindHyperpipeSGIX;
#define glXBindHyperpipeSGIX __glXBindHyperpipeSGIX
extern PFNGLXQUERYHYPERPIPEBESTATTRIBSGIXPROC __glXQueryHyperpipeBestAttribSGIX;
#define glXQueryHyperpipeBestAttribSGIX __glXQueryHyperpipeBestAttribSGIX
extern PFNGLXHYPERPIPEATTRIBSGIXPROC __glXHyperpipeAttribSGIX;
#define glXHyperpipeAttribSGIX __glXHyperpipeAttribSGIX
extern PFNGLXQUERYHYPERPIPEATTRIBSGIXPROC __glXQueryHyperpipeAttribSGIX;
#define glXQueryHyperpipeAttribSGIX __glXQueryHyperpipeAttribSGIX
#endif

/* GLX_SGIX_pbuffer */
#ifdef GLX_SGIX_pbuffer
extern PFNGLXCREATEGLXPBUFFERSGIXPROC __glXCreateGLXPbufferSGIX;
#define glXCreateGLXPbufferSGIX __glXCreateGLXPbufferSGIX
extern PFNGLXDESTROYGLXPBUFFERSGIXPROC __glXDestroyGLXPbufferSGIX;
#define glXDestroyGLXPbufferSGIX __glXDestroyGLXPbufferSGIX
extern PFNGLXQUERYGLXPBUFFERSGIXPROC __glXQueryGLXPbufferSGIX;
#define glXQueryGLXPbufferSGIX __glXQueryGLXPbufferSGIX
extern PFNGLXSELECTEVENTSGIXPROC __glXSelectEventSGIX;
#define glXSelectEventSGIX __glXSelectEventSGIX
extern PFNGLXGETSELECTEDEVENTSGIXPROC __glXGetSelectedEventSGIX;
#define glXGetSelectedEventSGIX __glXGetSelectedEventSGIX
#endif

/* GLX_SGIX_swap_barrier */
#ifdef GLX_SGIX_swap_barrier
extern PFNGLXBINDSWAPBARRIERSGIXPROC __glXBindSwapBarrierSGIX;
#define glXBindSwapBarrierSGIX __glXBindSwapBarrierSGIX
extern PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC __glXQueryMaxSwapBarriersSGIX;
#define glXQueryMaxSwapBarriersSGIX __glXQueryMaxSwapBarriersSGIX
#endif

/* GLX_SGIX_swap_group */
#ifdef GLX_SGIX_swap_group
extern PFNGLXJOINSWAPGROUPSGIXPROC __glXJoinSwapGroupSGIX;
#define glXJoinSwapGroupSGIX __glXJoinSwapGroupSGIX
#endif

/* GLX_SGIX_video_resize */
#ifdef GLX_SGIX_video_resize
extern PFNGLXBINDCHANNELTOWINDOWSGIXPROC __glXBindChannelToWindowSGIX;
#define glXBindChannelToWindowSGIX __glXBindChannelToWindowSGIX
extern PFNGLXCHANNELRECTSGIXPROC __glXChannelRectSGIX;
#define glXChannelRectSGIX __glXChannelRectSGIX
extern PFNGLXQUERYCHANNELRECTSGIXPROC __glXQueryChannelRectSGIX;
#define glXQueryChannelRectSGIX __glXQueryChannelRectSGIX
extern PFNGLXQUERYCHANNELDELTASSGIXPROC __glXQueryChannelDeltasSGIX;
#define glXQueryChannelDeltasSGIX __glXQueryChannelDeltasSGIX
extern PFNGLXCHANNELRECTSYNCSGIXPROC __glXChannelRectSyncSGIX;
#define glXChannelRectSyncSGIX __glXChannelRectSyncSGIX
#endif

/* GLX_SGIX_video_source */
#ifdef GLX_SGIX_video_source
extern PFNGLXCREATEGLXVIDEOSOURCESGIXPROC __glXCreateGLXVideoSourceSGIX;
#define glXCreateGLXVideoSourceSGIX __glXCreateGLXVideoSourceSGIX
extern PFNGLXDESTROYGLXVIDEOSOURCESGIXPROC __glXDestroyGLXVideoSourceSGIX;
#define glXDestroyGLXVideoSourceSGIX __glXDestroyGLXVideoSourceSGIX
#endif

/* GLX_SUN_get_transparent_index */
#ifdef GLX_SUN_get_transparent_index
extern PFNGLXGETTRANSPARENTINDEXSUNPROC __glXGetTransparentIndexSUN;
#define glXGetTransparentIndexSUN __glXGetTransparentIndexSUN
#endif


//-----------------------------------------------------------------------------
// InitFunctions_GLX
//-----------------------------------------------------------------------------
void InitFunctions_GLX();

//-----------------------------------------------------------------------------
// DeInitFunctions_GLX
//-----------------------------------------------------------------------------
void DeInitFunctions_GLX();
