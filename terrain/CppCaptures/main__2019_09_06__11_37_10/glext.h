//---------------------------------------------------------------------------
// File: glext.h
//
// Copyright (c) NVIDIA Corporation.  All rights reserved.
//---------------------------------------------------------------------------

#ifndef __glext_h_
#define __glext_h_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GLAPIENTRY
# ifdef _WIN32
#  if (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED)  /* Mimic <windef.h> */
#   define GLAPIENTRY __stdcall
#  else
#   define GLAPIENTRY
#  endif
# else
#  define GLAPIENTRY
# endif
#endif

#ifndef GLAPI
# define GLAPI extern
#endif

#ifndef GLAPIENTRYP
# define GLAPIENTRYP GLAPIENTRY *
#endif

/*************************************************************/

#ifndef GL_TYPEDEFS_1_5
#define GL_TYPEDEFS_1_5
#if defined(_WIN64)
    typedef __int64 GLintptr;
    typedef __int64 GLsizeiptr;
#elif defined(__x86_64__) || defined (__LP64__) || defined(__aarch64__)
    typedef long int GLintptr;
    typedef long int GLsizeiptr;
#else
    typedef int GLintptr;
    typedef int GLsizeiptr;
#endif
#endif

#ifndef GL_TYPEDEFS_2_0
# define GL_TYPEDEFS_2_0
    typedef char GLchar;
#endif

#ifndef GL_TYPEDEFS_3_2
# define GL_TYPEDEFS_3_2
    typedef int64_t GLint64;
    typedef uint64_t GLuint64;
    typedef GLintptr GLsync;
#endif

#ifndef GL_TYPEDEFS_4_1
# define GL_TYPEDEFS_4_1
    typedef int GLfixed;
#endif

#ifndef GL_TYPEDEFS_4_3
# define GL_TYPEDEFS_4_3
    typedef void (GLAPIENTRY *GLDEBUGPROC)(
        GLenum source,
        GLenum type,
        GLuint id,
        GLenum severity,
        GLsizei length,
        const GLchar* message,
        void* userParam);
#endif

typedef unsigned short GLhalf;
typedef unsigned int GLhandleARB;
typedef char GLcharARB;
#if defined(_WIN64)
    typedef __int64 GLintptrARB;
    typedef __int64 GLsizeiptrARB;
#elif defined(__x86_64__) || defined (__LP64__) || defined(__aarch64__)
    typedef long int GLintptrARB;
    typedef long int GLsizeiptrARB;
#else
    typedef int GLintptrARB;
    typedef int GLsizeiptrARB;
#endif

typedef int64_t GLint64EXT;
typedef uint64_t GLuint64EXT;

typedef GLintptr GLvdpauSurfaceNV;

typedef GLintptr GLxorgSyncFenceEXT;

typedef void *GLeglImageOES;

typedef void (GLAPIENTRY *GLDEBUGPROCARB)(GLenum source,
                                          GLenum type,
                                          GLuint id,
                                          GLenum severity,
                                          GLsizei length,
                                          const GLchar* message,
                                          GLvoid* userParam);
typedef void (GLAPIENTRY *GLVULKANPROCNV)(void);


/*************************************************************/

#ifndef GL_AMD_multi_draw_indirect
#define GL_AMD_multi_draw_indirect 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glMultiDrawArraysIndirectAMD(GLenum mode, const GLvoid* indirect, GLsizei primcount, GLsizei stride);
GLAPI void GLAPIENTRY glMultiDrawElementsIndirectAMD(GLenum mode, GLenum type, const GLvoid* indirect, GLsizei primcount, GLsizei stride);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC)(GLenum mode, const GLvoid* indirect, GLsizei primcount, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC)(GLenum mode, GLenum type, const GLvoid* indirect, GLsizei primcount, GLsizei stride);
#endif


#ifndef GL_ANGLE_framebuffer_blit
#define GL_ANGLE_framebuffer_blit 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlitFramebufferANGLE(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLITFRAMEBUFFERANGLEPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#endif


#ifndef GL_ANGLE_framebuffer_multisample
#define GL_ANGLE_framebuffer_multisample 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glRenderbufferStorageMultisampleANGLE(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEANGLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#endif


#ifndef GL_ARB_bindless_texture
#define GL_ARB_bindless_texture 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLuint64 GLAPIENTRY glGetTextureHandleARB(GLuint texture);
GLAPI GLuint64 GLAPIENTRY glGetTextureSamplerHandleARB(GLuint texture, GLuint sampler);
GLAPI void GLAPIENTRY glMakeTextureHandleResidentARB(GLuint64 handle);
GLAPI void GLAPIENTRY glMakeTextureHandleNonResidentARB(GLuint64 handle);
GLAPI GLuint64 GLAPIENTRY glGetImageHandleARB(GLuint texture, GLint level, GLboolean layered, GLint layer, GLint format);
GLAPI void GLAPIENTRY glMakeImageHandleResidentARB(GLuint64 handle, GLenum access);
GLAPI void GLAPIENTRY glMakeImageHandleNonResidentARB(GLuint64 handle);
GLAPI GLboolean GLAPIENTRY glIsTextureHandleResidentARB(GLuint64 handle);
GLAPI GLboolean GLAPIENTRY glIsImageHandleResidentARB(GLuint64 handle);
GLAPI void GLAPIENTRY glUniformHandleui64ARB(GLint location, GLuint64 value);
GLAPI void GLAPIENTRY glUniformHandleui64vARB(GLint location, GLsizei count, const GLuint64* value);
GLAPI void GLAPIENTRY glProgramUniformHandleui64ARB(GLuint program, GLint location, GLuint64 value);
GLAPI void GLAPIENTRY glProgramUniformHandleui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* value);
GLAPI void GLAPIENTRY glVertexAttribL1ui64ARB(GLuint index, GLuint64 x);
GLAPI void GLAPIENTRY glVertexAttribL1ui64vARB(GLuint index, const GLuint64* v);
GLAPI void GLAPIENTRY glGetVertexAttribLui64vARB(GLuint index, GLenum pname, GLuint64* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLuint64 (GLAPIENTRYP PFNGLGETTEXTUREHANDLEARBPROC)(GLuint texture);
typedef GLuint64 (GLAPIENTRYP PFNGLGETTEXTURESAMPLERHANDLEARBPROC)(GLuint texture, GLuint sampler);
typedef void (GLAPIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTARBPROC)(GLuint64 handle);
typedef void (GLAPIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC)(GLuint64 handle);
typedef GLuint64 (GLAPIENTRYP PFNGLGETIMAGEHANDLEARBPROC)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLint format);
typedef void (GLAPIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTARBPROC)(GLuint64 handle, GLenum access);
typedef void (GLAPIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC)(GLuint64 handle);
typedef GLboolean (GLAPIENTRYP PFNGLISTEXTUREHANDLERESIDENTARBPROC)(GLuint64 handle);
typedef GLboolean (GLAPIENTRYP PFNGLISIMAGEHANDLERESIDENTARBPROC)(GLuint64 handle);
typedef void (GLAPIENTRYP PFNGLUNIFORMHANDLEUI64ARBPROC)(GLint location, GLuint64 value);
typedef void (GLAPIENTRYP PFNGLUNIFORMHANDLEUI64VARBPROC)(GLint location, GLsizei count, const GLuint64* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC)(GLuint program, GLint location, GLuint64 value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64* value);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL1UI64ARBPROC)(GLuint index, GLuint64 x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL1UI64VARBPROC)(GLuint index, const GLuint64* v);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBLUI64VARBPROC)(GLuint index, GLenum pname, GLuint64* params);
#endif


#ifndef GL_ARB_color_buffer_float
#define GL_ARB_color_buffer_float 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glClampColorARB(GLenum target, GLenum clamp);
GLAPI void GLAPIENTRY glClampColor(GLenum target, GLenum clamp);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCLAMPCOLORARBPROC)(GLenum target, GLenum clamp);
typedef void (GLAPIENTRYP PFNGLCLAMPCOLORPROC)(GLenum target, GLenum clamp);
#endif


#ifndef GL_ARB_compute_variable_group_size
#define GL_ARB_compute_variable_group_size 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDispatchComputeGroupSizeARB(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
#endif


#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDebugMessageControlARB(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
GLAPI void GLAPIENTRY glDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
GLAPI void GLAPIENTRY glDebugMessageCallbackARB(GLDEBUGPROCARB callback, const void* userParam);
GLAPI GLuint GLAPIENTRY glGetDebugMessageLogARB(GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDEBUGMESSAGECONTROLARBPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
typedef void (GLAPIENTRYP PFNGLDEBUGMESSAGEINSERTARBPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
typedef void (GLAPIENTRYP PFNGLDEBUGMESSAGECALLBACKARBPROC)(GLDEBUGPROCARB callback, const void* userParam);
typedef GLuint (GLAPIENTRYP PFNGLGETDEBUGMESSAGELOGARBPROC)(GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
#endif


#ifndef GL_ARB_draw_buffers
#define GL_ARB_draw_buffers 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawBuffersARB(GLsizei n, const GLenum* bufs);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWBUFFERSARBPROC)(GLsizei n, const GLenum* bufs);
#endif


#ifndef GL_ARB_draw_buffers_blend
#define GL_ARB_draw_buffers_blend 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlendEquationiARB(GLuint buf, GLenum mode);
GLAPI void GLAPIENTRY glBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI void GLAPIENTRY glBlendFunciARB(GLuint buf, GLenum src, GLenum dst);
GLAPI void GLAPIENTRY glBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONIARBPROC)(GLuint buf, GLenum mode);
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONSEPARATEIARBPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (GLAPIENTRYP PFNGLBLENDFUNCIARBPROC)(GLuint buf, GLenum src, GLenum dst);
typedef void (GLAPIENTRYP PFNGLBLENDFUNCSEPARATEIARBPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#endif


#ifndef GL_ARB_draw_instanced
#define GL_ARB_draw_instanced 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
GLAPI void GLAPIENTRY glDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei primcount);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWARRAYSINSTANCEDARBPROC)(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSINSTANCEDARBPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei primcount);
#endif


#ifndef GL_ARB_geometry_shader4
#define GL_ARB_geometry_shader4 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glProgramParameteriARB(GLuint program, GLenum pname, GLint value);
GLAPI void GLAPIENTRY glFramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level);
GLAPI void GLAPIENTRY glFramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void GLAPIENTRY glFramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPROGRAMPARAMETERIARBPROC)(GLuint program, GLenum pname, GLint value);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTUREARBPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERARBPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTUREFACEARBPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
#endif


#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid* data);
GLAPI void GLAPIENTRY glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
GLAPI void GLAPIENTRY glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid* image);
GLAPI void GLAPIENTRY glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* image);
GLAPI void GLAPIENTRY glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params);
GLAPI void GLAPIENTRY glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glConvolutionParameteri(GLenum target, GLenum pname, GLint params);
GLAPI void GLAPIENTRY glConvolutionParameteriv(GLenum target, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
GLAPI void GLAPIENTRY glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid* image);
GLAPI void GLAPIENTRY glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid* row, GLvoid* column, GLvoid* span);
GLAPI void GLAPIENTRY glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* row, const GLvoid* column);
GLAPI void GLAPIENTRY glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values);
GLAPI void GLAPIENTRY glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetHistogramParameteriv(GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values);
GLAPI void GLAPIENTRY glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
GLAPI void GLAPIENTRY glMinmax(GLenum target, GLenum internalformat, GLboolean sink);
GLAPI void GLAPIENTRY glResetHistogram(GLenum target);
GLAPI void GLAPIENTRY glResetMinmax(GLenum target);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOLORSUBTABLEPROC)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCOPYCOLORSUBTABLEPROC)(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
typedef void (GLAPIENTRYP PFNGLCONVOLUTIONFILTER1DPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid* image);
typedef void (GLAPIENTRYP PFNGLCONVOLUTIONFILTER2DPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* image);
typedef void (GLAPIENTRYP PFNGLCONVOLUTIONPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat params);
typedef void (GLAPIENTRYP PFNGLCONVOLUTIONPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLCONVOLUTIONPARAMETERIPROC)(GLenum target, GLenum pname, GLint params);
typedef void (GLAPIENTRYP PFNGLCONVOLUTIONPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLCOPYCONVOLUTIONFILTER1DPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (GLAPIENTRYP PFNGLCOPYCONVOLUTIONFILTER2DPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLGETCONVOLUTIONFILTERPROC)(GLenum target, GLenum format, GLenum type, GLvoid* image);
typedef void (GLAPIENTRYP PFNGLGETCONVOLUTIONPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETCONVOLUTIONPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETSEPARABLEFILTERPROC)(GLenum target, GLenum format, GLenum type, GLvoid* row, GLvoid* column, GLvoid* span);
typedef void (GLAPIENTRYP PFNGLSEPARABLEFILTER2DPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* row, const GLvoid* column);
typedef void (GLAPIENTRYP PFNGLGETHISTOGRAMPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values);
typedef void (GLAPIENTRYP PFNGLGETHISTOGRAMPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETHISTOGRAMPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETMINMAXPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values);
typedef void (GLAPIENTRYP PFNGLGETMINMAXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETMINMAXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLHISTOGRAMPROC)(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
typedef void (GLAPIENTRYP PFNGLMINMAXPROC)(GLenum target, GLenum internalformat, GLboolean sink);
typedef void (GLAPIENTRYP PFNGLRESETHISTOGRAMPROC)(GLenum target);
typedef void (GLAPIENTRYP PFNGLRESETMINMAXPROC)(GLenum target);
#endif


#ifndef GL_ARB_indirect_parameters
#define GL_ARB_indirect_parameters 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glMultiDrawArraysIndirectCountARB(GLenum mode, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLAPI void GLAPIENTRY glMultiDrawElementsIndirectCountARB(GLenum mode, GLenum type, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC)(GLenum mode, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC)(GLenum mode, GLenum type, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#endif


#ifndef GL_ARB_instanced_arrays
#define GL_ARB_instanced_arrays 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glVertexAttribDivisorARB(GLuint index, GLuint divisor);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBDIVISORARBPROC)(GLuint index, GLuint divisor);
#endif


#ifndef GL_ARB_multisample
#define GL_ARB_multisample 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glSampleCoverageARB(GLclampf value, GLboolean invert);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLSAMPLECOVERAGEARBPROC)(GLclampf value, GLboolean invert);
#endif


#ifndef GL_ARB_multitexture
#define GL_ARB_multitexture 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glActiveTextureARB(GLenum texture);
GLAPI void GLAPIENTRY glClientActiveTextureARB(GLenum texture);
GLAPI void GLAPIENTRY glMultiTexCoord1dARB(GLenum target, GLdouble s);
GLAPI void GLAPIENTRY glMultiTexCoord1dvARB(GLenum target, const GLdouble* v);
GLAPI void GLAPIENTRY glMultiTexCoord1fARB(GLenum target, GLfloat s);
GLAPI void GLAPIENTRY glMultiTexCoord1fvARB(GLenum target, const GLfloat* v);
GLAPI void GLAPIENTRY glMultiTexCoord1iARB(GLenum target, GLint s);
GLAPI void GLAPIENTRY glMultiTexCoord1ivARB(GLenum target, const GLint* v);
GLAPI void GLAPIENTRY glMultiTexCoord1sARB(GLenum target, GLshort s);
GLAPI void GLAPIENTRY glMultiTexCoord1svARB(GLenum target, const GLshort* v);
GLAPI void GLAPIENTRY glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t);
GLAPI void GLAPIENTRY glMultiTexCoord2dvARB(GLenum target, const GLdouble* v);
GLAPI void GLAPIENTRY glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t);
GLAPI void GLAPIENTRY glMultiTexCoord2fvARB(GLenum target, const GLfloat* v);
GLAPI void GLAPIENTRY glMultiTexCoord2iARB(GLenum target, GLint s, GLint t);
GLAPI void GLAPIENTRY glMultiTexCoord2ivARB(GLenum target, const GLint* v);
GLAPI void GLAPIENTRY glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t);
GLAPI void GLAPIENTRY glMultiTexCoord2svARB(GLenum target, const GLshort* v);
GLAPI void GLAPIENTRY glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r);
GLAPI void GLAPIENTRY glMultiTexCoord3dvARB(GLenum target, const GLdouble* v);
GLAPI void GLAPIENTRY glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r);
GLAPI void GLAPIENTRY glMultiTexCoord3fvARB(GLenum target, const GLfloat* v);
GLAPI void GLAPIENTRY glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r);
GLAPI void GLAPIENTRY glMultiTexCoord3ivARB(GLenum target, const GLint* v);
GLAPI void GLAPIENTRY glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r);
GLAPI void GLAPIENTRY glMultiTexCoord3svARB(GLenum target, const GLshort* v);
GLAPI void GLAPIENTRY glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
GLAPI void GLAPIENTRY glMultiTexCoord4dvARB(GLenum target, const GLdouble* v);
GLAPI void GLAPIENTRY glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GLAPI void GLAPIENTRY glMultiTexCoord4fvARB(GLenum target, const GLfloat* v);
GLAPI void GLAPIENTRY glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q);
GLAPI void GLAPIENTRY glMultiTexCoord4ivARB(GLenum target, const GLint* v);
GLAPI void GLAPIENTRY glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
GLAPI void GLAPIENTRY glMultiTexCoord4svARB(GLenum target, const GLshort* v);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLACTIVETEXTUREARBPROC)(GLenum texture);
typedef void (GLAPIENTRYP PFNGLCLIENTACTIVETEXTUREARBPROC)(GLenum texture);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1DARBPROC)(GLenum target, GLdouble s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1DVARBPROC)(GLenum target, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1FARBPROC)(GLenum target, GLfloat s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1FVARBPROC)(GLenum target, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1IARBPROC)(GLenum target, GLint s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1IVARBPROC)(GLenum target, const GLint* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1SARBPROC)(GLenum target, GLshort s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1SVARBPROC)(GLenum target, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2DARBPROC)(GLenum target, GLdouble s, GLdouble t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2DVARBPROC)(GLenum target, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2FARBPROC)(GLenum target, GLfloat s, GLfloat t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2FVARBPROC)(GLenum target, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2IARBPROC)(GLenum target, GLint s, GLint t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2IVARBPROC)(GLenum target, const GLint* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2SARBPROC)(GLenum target, GLshort s, GLshort t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2SVARBPROC)(GLenum target, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3DARBPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3DVARBPROC)(GLenum target, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3FARBPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3FVARBPROC)(GLenum target, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3IARBPROC)(GLenum target, GLint s, GLint t, GLint r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3IVARBPROC)(GLenum target, const GLint* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3SARBPROC)(GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3SVARBPROC)(GLenum target, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4DARBPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4DVARBPROC)(GLenum target, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4FARBPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4FVARBPROC)(GLenum target, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4IARBPROC)(GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4IVARBPROC)(GLenum target, const GLint* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4SARBPROC)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4SVARBPROC)(GLenum target, const GLshort* v);
#endif


#ifndef GL_ARB_occlusion_query
#define GL_ARB_occlusion_query 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGenQueriesARB(GLsizei n, GLuint* ids);
GLAPI void GLAPIENTRY glDeleteQueriesARB(GLsizei n, const GLuint* ids);
GLAPI GLboolean GLAPIENTRY glIsQueryARB(GLuint id);
GLAPI void GLAPIENTRY glBeginQueryARB(GLenum target, GLuint id);
GLAPI void GLAPIENTRY glEndQueryARB(GLenum target);
GLAPI void GLAPIENTRY glGetQueryObjectivARB(GLuint id, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetQueryObjectuivARB(GLuint id, GLenum pname, GLuint* params);
GLAPI void GLAPIENTRY glGetQueryivARB(GLenum target, GLenum pname, GLint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGENQUERIESARBPROC)(GLsizei n, GLuint* ids);
typedef void (GLAPIENTRYP PFNGLDELETEQUERIESARBPROC)(GLsizei n, const GLuint* ids);
typedef GLboolean (GLAPIENTRYP PFNGLISQUERYARBPROC)(GLuint id);
typedef void (GLAPIENTRYP PFNGLBEGINQUERYARBPROC)(GLenum target, GLuint id);
typedef void (GLAPIENTRYP PFNGLENDQUERYARBPROC)(GLenum target);
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTIVARBPROC)(GLuint id, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTUIVARBPROC)(GLuint id, GLenum pname, GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETQUERYIVARBPROC)(GLenum target, GLenum pname, GLint* params);
#endif


#ifndef GL_ARB_parallel_shader_compile
#define GL_ARB_parallel_shader_compile 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glMaxShaderCompilerThreadsARB(GLuint count);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLMAXSHADERCOMPILERTHREADSARBPROC)(GLuint count);
#endif


#ifndef GL_ARB_point_parameters
#define GL_ARB_point_parameters 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPointParameterfARB(GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glPointParameterfvARB(GLenum pname, const GLfloat* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERFARBPROC)(GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERFVARBPROC)(GLenum pname, const GLfloat* params);
#endif


#ifndef GL_ARB_robustness
#define GL_ARB_robustness 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLenum GLAPIENTRY glGetGraphicsResetStatusARB();
GLAPI void GLAPIENTRY glGetnMapdvARB(GLenum target, GLenum query, GLsizei bufSize, GLdouble* v);
GLAPI void GLAPIENTRY glGetnMapfvARB(GLenum target, GLenum query, GLsizei bufSize, GLfloat* v);
GLAPI void GLAPIENTRY glGetnMapivARB(GLenum target, GLenum query, GLsizei bufSize, GLint* v);
GLAPI void GLAPIENTRY glGetnPixelMapfvARB(GLenum map, GLsizei bufSize, GLfloat* values);
GLAPI void GLAPIENTRY glGetnPixelMapuivARB(GLenum map, GLsizei bufSize, GLuint* values);
GLAPI void GLAPIENTRY glGetnPixelMapusvARB(GLenum map, GLsizei bufSize, GLushort* values);
GLAPI void GLAPIENTRY glGetnPolygonStippleARB(GLsizei bufSize, GLubyte* mask);
GLAPI void GLAPIENTRY glGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
GLAPI void GLAPIENTRY glReadnPixelsARB(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
GLAPI void GLAPIENTRY glGetnColorTableARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid* table);
GLAPI void GLAPIENTRY glGetnConvolutionFilterARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid* image);
GLAPI void GLAPIENTRY glGetnSeparableFilterARB(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, GLvoid* row, GLsizei columnBufSize, GLvoid* column, GLvoid* span);
GLAPI void GLAPIENTRY glGetnHistogramARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid* values);
GLAPI void GLAPIENTRY glGetnMinmaxARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid* values);
GLAPI void GLAPIENTRY glGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, GLvoid* img);
GLAPI void GLAPIENTRY glGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
GLAPI void GLAPIENTRY glGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint* params);
GLAPI void GLAPIENTRY glGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
GLAPI void GLAPIENTRY glGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLenum (GLAPIENTRYP PFNGLGETGRAPHICSRESETSTATUSARBPROC)();
typedef void (GLAPIENTRYP PFNGLGETNMAPDVARBPROC)(GLenum target, GLenum query, GLsizei bufSize, GLdouble* v);
typedef void (GLAPIENTRYP PFNGLGETNMAPFVARBPROC)(GLenum target, GLenum query, GLsizei bufSize, GLfloat* v);
typedef void (GLAPIENTRYP PFNGLGETNMAPIVARBPROC)(GLenum target, GLenum query, GLsizei bufSize, GLint* v);
typedef void (GLAPIENTRYP PFNGLGETNPIXELMAPFVARBPROC)(GLenum map, GLsizei bufSize, GLfloat* values);
typedef void (GLAPIENTRYP PFNGLGETNPIXELMAPUIVARBPROC)(GLenum map, GLsizei bufSize, GLuint* values);
typedef void (GLAPIENTRYP PFNGLGETNPIXELMAPUSVARBPROC)(GLenum map, GLsizei bufSize, GLushort* values);
typedef void (GLAPIENTRYP PFNGLGETNPOLYGONSTIPPLEARBPROC)(GLsizei bufSize, GLubyte* mask);
typedef void (GLAPIENTRYP PFNGLGETNTEXIMAGEARBPROC)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLREADNPIXELSARBPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLGETNCOLORTABLEARBPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid* table);
typedef void (GLAPIENTRYP PFNGLGETNCONVOLUTIONFILTERARBPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid* image);
typedef void (GLAPIENTRYP PFNGLGETNSEPARABLEFILTERARBPROC)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, GLvoid* row, GLsizei columnBufSize, GLvoid* column, GLvoid* span);
typedef void (GLAPIENTRYP PFNGLGETNHISTOGRAMARBPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid* values);
typedef void (GLAPIENTRYP PFNGLGETNMINMAXARBPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid* values);
typedef void (GLAPIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC)(GLenum target, GLint lod, GLsizei bufSize, GLvoid* img);
typedef void (GLAPIENTRYP PFNGLGETNUNIFORMFVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETNUNIFORMIVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETNUNIFORMUIVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETNUNIFORMDVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
#endif


#ifndef GL_ARB_sample_shading
#define GL_ARB_sample_shading 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glMinSampleShadingARB(GLclampf value);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLMINSAMPLESHADINGARBPROC)(GLclampf value);
#endif


#ifndef GL_ARB_shader_objects
#define GL_ARB_shader_objects 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDeleteObjectARB(GLhandleARB obj);
GLAPI GLhandleARB GLAPIENTRY glGetHandleARB(GLenum pname);
GLAPI void GLAPIENTRY glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj);
GLAPI GLhandleARB GLAPIENTRY glCreateShaderObjectARB(GLenum shaderType);
GLAPI void GLAPIENTRY glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, const GLcharARB** string, const GLint* length);
GLAPI void GLAPIENTRY glCompileShaderARB(GLhandleARB shaderObj);
GLAPI GLhandleARB GLAPIENTRY glCreateProgramObjectARB();
GLAPI void GLAPIENTRY glAttachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj);
GLAPI void GLAPIENTRY glLinkProgramARB(GLhandleARB programObj);
GLAPI void GLAPIENTRY glUseProgramObjectARB(GLhandleARB programObj);
GLAPI void GLAPIENTRY glValidateProgramARB(GLhandleARB programObj);
GLAPI void GLAPIENTRY glUniform1fARB(GLint location, GLfloat v0);
GLAPI void GLAPIENTRY glUniform2fARB(GLint location, GLfloat v0, GLfloat v1);
GLAPI void GLAPIENTRY glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void GLAPIENTRY glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void GLAPIENTRY glUniform1iARB(GLint location, GLint v0);
GLAPI void GLAPIENTRY glUniform2iARB(GLint location, GLint v0, GLint v1);
GLAPI void GLAPIENTRY glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void GLAPIENTRY glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void GLAPIENTRY glUniform1fvARB(GLint location, GLsizei count, const GLfloat* value);
GLAPI void GLAPIENTRY glUniform2fvARB(GLint location, GLsizei count, const GLfloat* value);
GLAPI void GLAPIENTRY glUniform3fvARB(GLint location, GLsizei count, const GLfloat* value);
GLAPI void GLAPIENTRY glUniform4fvARB(GLint location, GLsizei count, const GLfloat* value);
GLAPI void GLAPIENTRY glUniform1ivARB(GLint location, GLsizei count, const GLint* value);
GLAPI void GLAPIENTRY glUniform2ivARB(GLint location, GLsizei count, const GLint* value);
GLAPI void GLAPIENTRY glUniform3ivARB(GLint location, GLsizei count, const GLint* value);
GLAPI void GLAPIENTRY glUniform4ivARB(GLint location, GLsizei count, const GLint* value);
GLAPI void GLAPIENTRY glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei* length, GLcharARB* infoLog);
GLAPI void GLAPIENTRY glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei* count, GLhandleARB* obj);
GLAPI GLint GLAPIENTRY glGetUniformLocationARB(GLhandleARB programObj, const GLcharARB* name);
GLAPI void GLAPIENTRY glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei* length, GLsizei* size, GLenum* type, GLcharARB* name);
GLAPI void GLAPIENTRY glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat* params);
GLAPI void GLAPIENTRY glGetUniformivARB(GLhandleARB programObj, GLint location, GLint* params);
GLAPI void GLAPIENTRY glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei* length, GLcharARB* source);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDELETEOBJECTARBPROC)(GLhandleARB obj);
typedef GLhandleARB (GLAPIENTRYP PFNGLGETHANDLEARBPROC)(GLenum pname);
typedef void (GLAPIENTRYP PFNGLDETACHOBJECTARBPROC)(GLhandleARB containerObj, GLhandleARB attachedObj);
typedef GLhandleARB (GLAPIENTRYP PFNGLCREATESHADEROBJECTARBPROC)(GLenum shaderType);
typedef void (GLAPIENTRYP PFNGLSHADERSOURCEARBPROC)(GLhandleARB shaderObj, GLsizei count, const GLcharARB** string, const GLint* length);
typedef void (GLAPIENTRYP PFNGLCOMPILESHADERARBPROC)(GLhandleARB shaderObj);
typedef GLhandleARB (GLAPIENTRYP PFNGLCREATEPROGRAMOBJECTARBPROC)();
typedef void (GLAPIENTRYP PFNGLATTACHOBJECTARBPROC)(GLhandleARB containerObj, GLhandleARB attachedObj);
typedef void (GLAPIENTRYP PFNGLLINKPROGRAMARBPROC)(GLhandleARB programObj);
typedef void (GLAPIENTRYP PFNGLUSEPROGRAMOBJECTARBPROC)(GLhandleARB programObj);
typedef void (GLAPIENTRYP PFNGLVALIDATEPROGRAMARBPROC)(GLhandleARB programObj);
typedef void (GLAPIENTRYP PFNGLUNIFORM1FARBPROC)(GLint location, GLfloat v0);
typedef void (GLAPIENTRYP PFNGLUNIFORM2FARBPROC)(GLint location, GLfloat v0, GLfloat v1);
typedef void (GLAPIENTRYP PFNGLUNIFORM3FARBPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (GLAPIENTRYP PFNGLUNIFORM4FARBPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (GLAPIENTRYP PFNGLUNIFORM1IARBPROC)(GLint location, GLint v0);
typedef void (GLAPIENTRYP PFNGLUNIFORM2IARBPROC)(GLint location, GLint v0, GLint v1);
typedef void (GLAPIENTRYP PFNGLUNIFORM3IARBPROC)(GLint location, GLint v0, GLint v1, GLint v2);
typedef void (GLAPIENTRYP PFNGLUNIFORM4IARBPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (GLAPIENTRYP PFNGLUNIFORM1FVARBPROC)(GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM2FVARBPROC)(GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM3FVARBPROC)(GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM4FVARBPROC)(GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM1IVARBPROC)(GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM2IVARBPROC)(GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM3IVARBPROC)(GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM4IVARBPROC)(GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX2FVARBPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX3FVARBPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX4FVARBPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLGETOBJECTPARAMETERFVARBPROC)(GLhandleARB obj, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETOBJECTPARAMETERIVARBPROC)(GLhandleARB obj, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETINFOLOGARBPROC)(GLhandleARB obj, GLsizei maxLength, GLsizei* length, GLcharARB* infoLog);
typedef void (GLAPIENTRYP PFNGLGETATTACHEDOBJECTSARBPROC)(GLhandleARB containerObj, GLsizei maxCount, GLsizei* count, GLhandleARB* obj);
typedef GLint (GLAPIENTRYP PFNGLGETUNIFORMLOCATIONARBPROC)(GLhandleARB programObj, const GLcharARB* name);
typedef void (GLAPIENTRYP PFNGLGETACTIVEUNIFORMARBPROC)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei* length, GLsizei* size, GLenum* type, GLcharARB* name);
typedef void (GLAPIENTRYP PFNGLGETUNIFORMFVARBPROC)(GLhandleARB programObj, GLint location, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETUNIFORMIVARBPROC)(GLhandleARB programObj, GLint location, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETSHADERSOURCEARBPROC)(GLhandleARB obj, GLsizei maxLength, GLsizei* length, GLcharARB* source);
#endif


#ifndef GL_ARB_shader_subroutine
#define GL_ARB_shader_subroutine 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glProgramSubroutineParametersuivNV(GLenum target, GLsizei count, const GLuint* params);
GLAPI void GLAPIENTRY glGetProgramSubroutineParameteruivNV(GLenum target, GLuint index, GLuint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC)(GLenum target, GLsizei count, const GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC)(GLenum target, GLuint index, GLuint* params);
#endif


#ifndef GL_ARB_shading_language_include
#define GL_ARB_shading_language_include 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glNamedStringARB(GLenum type, GLint namelen, const GLchar* name, GLint stringlen, const GLchar* string);
GLAPI void GLAPIENTRY glDeleteNamedStringARB(GLint namelen, const GLchar* name);
GLAPI void GLAPIENTRY glCompileShaderIncludeARB(GLuint shader, GLsizei count, const GLchar** path, const GLint* length);
GLAPI GLboolean GLAPIENTRY glIsNamedStringARB(GLint namelen, const GLchar* name);
GLAPI void GLAPIENTRY glGetNamedStringARB(GLint namelen, const GLchar* name, GLsizei bufSize, GLint* stringlen, GLchar* string);
GLAPI void GLAPIENTRY glGetNamedStringivARB(GLint namelen, const GLchar* name, GLenum pname, GLint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLNAMEDSTRINGARBPROC)(GLenum type, GLint namelen, const GLchar* name, GLint stringlen, const GLchar* string);
typedef void (GLAPIENTRYP PFNGLDELETENAMEDSTRINGARBPROC)(GLint namelen, const GLchar* name);
typedef void (GLAPIENTRYP PFNGLCOMPILESHADERINCLUDEARBPROC)(GLuint shader, GLsizei count, const GLchar** path, const GLint* length);
typedef GLboolean (GLAPIENTRYP PFNGLISNAMEDSTRINGARBPROC)(GLint namelen, const GLchar* name);
typedef void (GLAPIENTRYP PFNGLGETNAMEDSTRINGARBPROC)(GLint namelen, const GLchar* name, GLsizei bufSize, GLint* stringlen, GLchar* string);
typedef void (GLAPIENTRYP PFNGLGETNAMEDSTRINGIVARBPROC)(GLint namelen, const GLchar* name, GLenum pname, GLint* params);
#endif


#ifndef GL_ARB_sparse_buffer
#define GL_ARB_sparse_buffer 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBufferPageCommitmentARB(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBUFFERPAGECOMMITMENTARBPROC)(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
#endif


#ifndef GL_ARB_sparse_texture
#define GL_ARB_sparse_texture 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTexPageCommitmentARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXPAGECOMMITMENTARBPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#endif


#ifndef GL_ARB_texture_buffer_object
#define GL_ARB_texture_buffer_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTexBufferARB(GLenum target, GLenum internalformat, GLuint buffer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXBUFFERARBPROC)(GLenum target, GLenum internalformat, GLuint buffer);
#endif


#ifndef GL_ARB_texture_compression
#define GL_ARB_texture_compression 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* data);
GLAPI void GLAPIENTRY glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data);
GLAPI void GLAPIENTRY glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* data);
GLAPI void GLAPIENTRY glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data);
GLAPI void GLAPIENTRY glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data);
GLAPI void GLAPIENTRY glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* data);
GLAPI void GLAPIENTRY glGetCompressedTexImageARB(GLenum target, GLint lod, GLvoid* img);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)(GLenum target, GLint lod, GLvoid* img);
#endif


#ifndef GL_ARB_transform_feedback3
#define GL_ARB_transform_feedback3 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTransformFeedbackStreamAttribsNV(GLsizei count, const GLint* attribs, GLsizei nbuffers, const GLint* bufstreams, GLenum bufferMode);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTRANSFORMFEEDBACKSTREAMATTRIBSNVPROC)(GLsizei count, const GLint* attribs, GLsizei nbuffers, const GLint* bufstreams, GLenum bufferMode);
#endif


#ifndef GL_ARB_transpose_matrix
#define GL_ARB_transpose_matrix 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glLoadTransposeMatrixfARB(const GLfloat* m);
GLAPI void GLAPIENTRY glLoadTransposeMatrixdARB(const GLdouble* m);
GLAPI void GLAPIENTRY glMultTransposeMatrixfARB(const GLfloat* m);
GLAPI void GLAPIENTRY glMultTransposeMatrixdARB(const GLdouble* m);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLLOADTRANSPOSEMATRIXFARBPROC)(const GLfloat* m);
typedef void (GLAPIENTRYP PFNGLLOADTRANSPOSEMATRIXDARBPROC)(const GLdouble* m);
typedef void (GLAPIENTRYP PFNGLMULTTRANSPOSEMATRIXFARBPROC)(const GLfloat* m);
typedef void (GLAPIENTRYP PFNGLMULTTRANSPOSEMATRIXDARBPROC)(const GLdouble* m);
#endif


#ifndef GL_ARB_vertex_buffer_object
#define GL_ARB_vertex_buffer_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBindBufferARB(GLenum target, GLuint buffer);
GLAPI void GLAPIENTRY glBufferDataARB(GLenum target, GLsizeiptrARB size, const GLvoid* data, GLenum usage);
GLAPI void GLAPIENTRY glBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid* data);
GLAPI void GLAPIENTRY glDeleteBuffersARB(GLsizei n, const GLuint* buffers);
GLAPI void GLAPIENTRY glGenBuffersARB(GLsizei n, GLuint* buffers);
GLAPI void GLAPIENTRY glGetBufferParameterivARB(GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetBufferPointervARB(GLenum target, GLenum pname, GLvoid** params);
GLAPI void GLAPIENTRY glGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid* data);
GLAPI GLboolean GLAPIENTRY glIsBufferARB(GLuint buffer);
GLAPI GLvoid* GLAPIENTRY glMapBufferARB(GLenum target, GLenum access);
GLAPI GLboolean GLAPIENTRY glUnmapBufferARB(GLenum target);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBINDBUFFERARBPROC)(GLenum target, GLuint buffer);
typedef void (GLAPIENTRYP PFNGLBUFFERDATAARBPROC)(GLenum target, GLsizeiptrARB size, const GLvoid* data, GLenum usage);
typedef void (GLAPIENTRYP PFNGLBUFFERSUBDATAARBPROC)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLDELETEBUFFERSARBPROC)(GLsizei n, const GLuint* buffers);
typedef void (GLAPIENTRYP PFNGLGENBUFFERSARBPROC)(GLsizei n, GLuint* buffers);
typedef void (GLAPIENTRYP PFNGLGETBUFFERPARAMETERIVARBPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETBUFFERPOINTERVARBPROC)(GLenum target, GLenum pname, GLvoid** params);
typedef void (GLAPIENTRYP PFNGLGETBUFFERSUBDATAARBPROC)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid* data);
typedef GLboolean (GLAPIENTRYP PFNGLISBUFFERARBPROC)(GLuint buffer);
typedef GLvoid* (GLAPIENTRYP PFNGLMAPBUFFERARBPROC)(GLenum target, GLenum access);
typedef GLboolean (GLAPIENTRYP PFNGLUNMAPBUFFERARBPROC)(GLenum target);
#endif


#ifndef GL_ARB_vertex_program
#define GL_ARB_vertex_program 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glVertexAttrib1dARB(GLuint index, GLdouble x);
GLAPI void GLAPIENTRY glVertexAttrib1dvARB(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttrib1fARB(GLuint index, GLfloat x);
GLAPI void GLAPIENTRY glVertexAttrib1fvARB(GLuint index, const GLfloat* v);
GLAPI void GLAPIENTRY glVertexAttrib1sARB(GLuint index, GLshort x);
GLAPI void GLAPIENTRY glVertexAttrib1svARB(GLuint index, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glVertexAttrib2dvARB(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y);
GLAPI void GLAPIENTRY glVertexAttrib2fvARB(GLuint index, const GLfloat* v);
GLAPI void GLAPIENTRY glVertexAttrib2sARB(GLuint index, GLshort x, GLshort y);
GLAPI void GLAPIENTRY glVertexAttrib2svARB(GLuint index, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glVertexAttrib3dvARB(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glVertexAttrib3fvARB(GLuint index, const GLfloat* v);
GLAPI void GLAPIENTRY glVertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z);
GLAPI void GLAPIENTRY glVertexAttrib3svARB(GLuint index, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttrib4NbvARB(GLuint index, const GLbyte* v);
GLAPI void GLAPIENTRY glVertexAttrib4NivARB(GLuint index, const GLint* v);
GLAPI void GLAPIENTRY glVertexAttrib4NsvARB(GLuint index, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GLAPI void GLAPIENTRY glVertexAttrib4NubvARB(GLuint index, const GLubyte* v);
GLAPI void GLAPIENTRY glVertexAttrib4NuivARB(GLuint index, const GLuint* v);
GLAPI void GLAPIENTRY glVertexAttrib4NusvARB(GLuint index, const GLushort* v);
GLAPI void GLAPIENTRY glVertexAttrib4bvARB(GLuint index, const GLbyte* v);
GLAPI void GLAPIENTRY glVertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glVertexAttrib4dvARB(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glVertexAttrib4fvARB(GLuint index, const GLfloat* v);
GLAPI void GLAPIENTRY glVertexAttrib4ivARB(GLuint index, const GLint* v);
GLAPI void GLAPIENTRY glVertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI void GLAPIENTRY glVertexAttrib4svARB(GLuint index, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttrib4ubvARB(GLuint index, const GLubyte* v);
GLAPI void GLAPIENTRY glVertexAttrib4uivARB(GLuint index, const GLuint* v);
GLAPI void GLAPIENTRY glVertexAttrib4usvARB(GLuint index, const GLushort* v);
GLAPI void GLAPIENTRY glVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
GLAPI void GLAPIENTRY glEnableVertexAttribArrayARB(GLuint index);
GLAPI void GLAPIENTRY glDisableVertexAttribArrayARB(GLuint index);
GLAPI void GLAPIENTRY glProgramStringARB(GLenum target, GLenum format, GLsizei len, const GLvoid* string);
GLAPI void GLAPIENTRY glBindProgramARB(GLenum target, GLuint program);
GLAPI void GLAPIENTRY glDeleteProgramsARB(GLsizei n, const GLuint* programs);
GLAPI void GLAPIENTRY glGenProgramsARB(GLsizei n, GLuint* programs);
GLAPI void GLAPIENTRY glProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glProgramEnvParameter4dvARB(GLenum target, GLuint index, const GLdouble* params);
GLAPI void GLAPIENTRY glProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glProgramEnvParameter4fvARB(GLenum target, GLuint index, const GLfloat* params);
GLAPI void GLAPIENTRY glProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glProgramLocalParameter4dvARB(GLenum target, GLuint index, const GLdouble* params);
GLAPI void GLAPIENTRY glProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glProgramLocalParameter4fvARB(GLenum target, GLuint index, const GLfloat* params);
GLAPI void GLAPIENTRY glGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble* params);
GLAPI void GLAPIENTRY glGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat* params);
GLAPI void GLAPIENTRY glGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble* params);
GLAPI void GLAPIENTRY glGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat* params);
GLAPI void GLAPIENTRY glGetProgramivARB(GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetProgramStringARB(GLenum target, GLenum pname, GLvoid* string);
GLAPI void GLAPIENTRY glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble* params);
GLAPI void GLAPIENTRY glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetVertexAttribivARB(GLuint index, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetVertexAttribPointervARB(GLuint index, GLenum pname, GLvoid** pointer);
GLAPI GLboolean GLAPIENTRY glIsProgramARB(GLuint program);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1DARBPROC)(GLuint index, GLdouble x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1DVARBPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1FARBPROC)(GLuint index, GLfloat x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1FVARBPROC)(GLuint index, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1SARBPROC)(GLuint index, GLshort x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1SVARBPROC)(GLuint index, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2DARBPROC)(GLuint index, GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2DVARBPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2FARBPROC)(GLuint index, GLfloat x, GLfloat y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2FVARBPROC)(GLuint index, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2SARBPROC)(GLuint index, GLshort x, GLshort y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2SVARBPROC)(GLuint index, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3DARBPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3DVARBPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3FARBPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3FVARBPROC)(GLuint index, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3SARBPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3SVARBPROC)(GLuint index, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NBVARBPROC)(GLuint index, const GLbyte* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NIVARBPROC)(GLuint index, const GLint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NSVARBPROC)(GLuint index, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NUBARBPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NUBVARBPROC)(GLuint index, const GLubyte* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NUIVARBPROC)(GLuint index, const GLuint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NUSVARBPROC)(GLuint index, const GLushort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4BVARBPROC)(GLuint index, const GLbyte* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4DARBPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4DVARBPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4FARBPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4FVARBPROC)(GLuint index, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4IVARBPROC)(GLuint index, const GLint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4SARBPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4SVARBPROC)(GLuint index, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4UBVARBPROC)(GLuint index, const GLubyte* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4UIVARBPROC)(GLuint index, const GLuint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4USVARBPROC)(GLuint index, const GLushort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBPOINTERARBPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLENABLEVERTEXATTRIBARRAYARBPROC)(GLuint index);
typedef void (GLAPIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)(GLuint index);
typedef void (GLAPIENTRYP PFNGLPROGRAMSTRINGARBPROC)(GLenum target, GLenum format, GLsizei len, const GLvoid* string);
typedef void (GLAPIENTRYP PFNGLBINDPROGRAMARBPROC)(GLenum target, GLuint program);
typedef void (GLAPIENTRYP PFNGLDELETEPROGRAMSARBPROC)(GLsizei n, const GLuint* programs);
typedef void (GLAPIENTRYP PFNGLGENPROGRAMSARBPROC)(GLsizei n, GLuint* programs);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETER4DARBPROC)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETER4DVARBPROC)(GLenum target, GLuint index, const GLdouble* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETER4FARBPROC)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETER4FVARBPROC)(GLenum target, GLuint index, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETER4DARBPROC)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)(GLenum target, GLuint index, const GLdouble* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETER4FARBPROC)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)(GLenum target, GLuint index, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMENVPARAMETERDVARBPROC)(GLenum target, GLuint index, GLdouble* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMENVPARAMETERFVARBPROC)(GLenum target, GLuint index, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)(GLenum target, GLuint index, GLdouble* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)(GLenum target, GLuint index, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMIVARBPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMSTRINGARBPROC)(GLenum target, GLenum pname, GLvoid* string);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBDVARBPROC)(GLuint index, GLenum pname, GLdouble* params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBFVARBPROC)(GLuint index, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBIVARBPROC)(GLuint index, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBPOINTERVARBPROC)(GLuint index, GLenum pname, GLvoid** pointer);
typedef GLboolean (GLAPIENTRYP PFNGLISPROGRAMARBPROC)(GLuint program);
#endif


#ifndef GL_ARB_vertex_shader
#define GL_ARB_vertex_shader 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBindAttribLocationARB(GLhandleARB programObj, GLuint index, const GLcharARB* name);
GLAPI void GLAPIENTRY glGetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei* length, GLsizei* size, GLenum* type, GLcharARB* name);
GLAPI GLint GLAPIENTRY glGetAttribLocationARB(GLhandleARB programObj, const GLcharARB* name);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBINDATTRIBLOCATIONARBPROC)(GLhandleARB programObj, GLuint index, const GLcharARB* name);
typedef void (GLAPIENTRYP PFNGLGETACTIVEATTRIBARBPROC)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei* length, GLsizei* size, GLenum* type, GLcharARB* name);
typedef GLint (GLAPIENTRYP PFNGLGETATTRIBLOCATIONARBPROC)(GLhandleARB programObj, const GLcharARB* name);
#endif


#ifndef GL_ARB_window_pos
#define GL_ARB_window_pos 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glWindowPos2dARB(GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glWindowPos2fARB(GLfloat x, GLfloat y);
GLAPI void GLAPIENTRY glWindowPos2iARB(GLint x, GLint y);
GLAPI void GLAPIENTRY glWindowPos2sARB(GLshort x, GLshort y);
GLAPI void GLAPIENTRY glWindowPos2dvARB(const GLdouble* p);
GLAPI void GLAPIENTRY glWindowPos2fvARB(const GLfloat* p);
GLAPI void GLAPIENTRY glWindowPos2ivARB(const GLint* p);
GLAPI void GLAPIENTRY glWindowPos2svARB(const GLshort* p);
GLAPI void GLAPIENTRY glWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glWindowPos3iARB(GLint x, GLint y, GLint z);
GLAPI void GLAPIENTRY glWindowPos3sARB(GLshort x, GLshort y, GLshort z);
GLAPI void GLAPIENTRY glWindowPos3dvARB(const GLdouble* p);
GLAPI void GLAPIENTRY glWindowPos3fvARB(const GLfloat* p);
GLAPI void GLAPIENTRY glWindowPos3ivARB(const GLint* p);
GLAPI void GLAPIENTRY glWindowPos3svARB(const GLshort* p);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2DARBPROC)(GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2FARBPROC)(GLfloat x, GLfloat y);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2IARBPROC)(GLint x, GLint y);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2SARBPROC)(GLshort x, GLshort y);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2DVARBPROC)(const GLdouble* p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2FVARBPROC)(const GLfloat* p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2IVARBPROC)(const GLint* p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2SVARBPROC)(const GLshort* p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3DARBPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3FARBPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3IARBPROC)(GLint x, GLint y, GLint z);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3SARBPROC)(GLshort x, GLshort y, GLshort z);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3DVARBPROC)(const GLdouble* p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3FVARBPROC)(const GLfloat* p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3IVARBPROC)(const GLint* p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3SVARBPROC)(const GLshort* p);
#endif


#ifndef GL_ATI_draw_buffers
#define GL_ATI_draw_buffers 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawBuffersATI(GLsizei n, const GLenum* bufs);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWBUFFERSATIPROC)(GLsizei n, const GLenum* bufs);
#endif


#ifndef GL_Autodesk_valid_back_buffer_hint
#define GL_Autodesk_valid_back_buffer_hint 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glWindowBackBufferHintAutodesk();
GLAPI GLboolean GLAPIENTRY glValidBackBufferHintAutodesk(GLint x, GLint y, GLsizei width, GLsizei height);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLWINDOWBACKBUFFERHINTAUTODESKPROC)();
typedef GLboolean (GLAPIENTRYP PFNGLVALIDBACKBUFFERHINTAUTODESKPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
#endif


#ifndef GL_EXT_base_instance
#define GL_EXT_base_instance 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawArraysInstancedBaseInstanceEXT(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
GLAPI void GLAPIENTRY glDrawElementsInstancedBaseInstanceEXT(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLuint baseinstance);
GLAPI void GLAPIENTRY glDrawElementsInstancedBaseVertexBaseInstanceEXT(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEEXTPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEEXTPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLuint baseinstance);
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEEXTPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
#endif


#ifndef GL_EXT_bindable_uniform
#define GL_EXT_bindable_uniform 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glUniformBufferEXT(GLuint program, GLint location, GLuint buffer);
GLAPI GLint GLAPIENTRY glGetUniformBufferSizeEXT(GLuint program, GLint location);
GLAPI GLintptr GLAPIENTRY glGetUniformOffsetEXT(GLuint program, GLint location);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLUNIFORMBUFFEREXTPROC)(GLuint program, GLint location, GLuint buffer);
typedef GLint (GLAPIENTRYP PFNGLGETUNIFORMBUFFERSIZEEXTPROC)(GLuint program, GLint location);
typedef GLintptr (GLAPIENTRYP PFNGLGETUNIFORMOFFSETEXTPROC)(GLuint program, GLint location);
#endif


#ifndef GL_EXT_blend_color
#define GL_EXT_blend_color 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlendColorEXT(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLENDCOLOREXTPROC)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
#endif


#ifndef GL_EXT_blend_equation_separate
#define GL_EXT_blend_equation_separate 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONSEPARATEEXTPROC)(GLenum modeRGB, GLenum modeAlpha);
#endif


#ifndef GL_EXT_blend_func_separate
#define GL_EXT_blend_func_separate 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLENDFUNCSEPARATEEXTPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
#endif


#ifndef GL_EXT_blend_minmax
#define GL_EXT_blend_minmax 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlendEquationEXT(GLenum mode);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONEXTPROC)(GLenum mode);
#endif


#ifndef GL_EXT_buffer_storage
#define GL_EXT_buffer_storage 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBufferStorageEXT(GLenum target, GLsizeiptr size, const GLvoid* data, GLbitfield flags);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBUFFERSTORAGEEXTPROC)(GLenum target, GLsizeiptr size, const GLvoid* data, GLbitfield flags);
#endif


#ifndef GL_EXT_compiled_vertex_array
#define GL_EXT_compiled_vertex_array 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glLockArraysEXT(GLint first, GLsizei count);
GLAPI void GLAPIENTRY glUnlockArraysEXT();
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLLOCKARRAYSEXTPROC)(GLint first, GLsizei count);
typedef void (GLAPIENTRYP PFNGLUNLOCKARRAYSEXTPROC)();
#endif


#ifndef GL_EXT_copy_image
#define GL_EXT_copy_image 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glCopyImageSubDataEXT(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOPYIMAGESUBDATAEXTPROC)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
#endif


#ifndef GL_EXT_debug_label
#define GL_EXT_debug_label 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glLabelObjectEXT(GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
GLAPI void GLAPIENTRY glGetObjectLabelEXT(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLLABELOBJECTEXTPROC)(GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
typedef void (GLAPIENTRYP PFNGLGETOBJECTLABELEXTPROC)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
#endif


#ifndef GL_EXT_debug_marker
#define GL_EXT_debug_marker 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glInsertEventMarkerEXT(GLsizei length, const GLchar* marker);
GLAPI void GLAPIENTRY glPushGroupMarkerEXT(GLsizei length, const GLchar* marker);
GLAPI void GLAPIENTRY glPopGroupMarkerEXT();
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLINSERTEVENTMARKEREXTPROC)(GLsizei length, const GLchar* marker);
typedef void (GLAPIENTRYP PFNGLPUSHGROUPMARKEREXTPROC)(GLsizei length, const GLchar* marker);
typedef void (GLAPIENTRYP PFNGLPOPGROUPMARKEREXTPROC)();
#endif


#ifndef GL_EXT_depth_bounds_test
#define GL_EXT_depth_bounds_test 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDepthBoundsEXT(GLclampd zmin, GLclampd zmax);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDEPTHBOUNDSEXTPROC)(GLclampd zmin, GLclampd zmax);
#endif


#ifndef GL_EXT_direct_state_access
#define GL_EXT_direct_state_access 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glClientAttribDefaultEXT(GLbitfield mask);
GLAPI void GLAPIENTRY glPushClientAttribDefaultEXT(GLbitfield mask);
GLAPI void GLAPIENTRY glMatrixLoadfEXT(GLenum mode, const GLfloat* m);
GLAPI void GLAPIENTRY glMatrixLoaddEXT(GLenum mode, const GLdouble* m);
GLAPI void GLAPIENTRY glMatrixMultfEXT(GLenum mode, const GLfloat* m);
GLAPI void GLAPIENTRY glMatrixMultdEXT(GLenum mode, const GLdouble* m);
GLAPI void GLAPIENTRY glMatrixLoadIdentityEXT(GLenum mode);
GLAPI void GLAPIENTRY glMatrixRotatefEXT(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glMatrixRotatedEXT(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glMatrixScalefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glMatrixScaledEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glMatrixTranslatefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glMatrixTranslatedEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glMatrixFrustumEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLAPI void GLAPIENTRY glMatrixOrthoEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLAPI void GLAPIENTRY glMatrixPopEXT(GLenum mode);
GLAPI void GLAPIENTRY glMatrixPushEXT(GLenum mode);
GLAPI void GLAPIENTRY glMatrixLoadTransposefEXT(GLenum mode, const GLfloat* m);
GLAPI void GLAPIENTRY glMatrixLoadTransposedEXT(GLenum mode, const GLdouble* m);
GLAPI void GLAPIENTRY glMatrixMultTransposefEXT(GLenum mode, const GLfloat* m);
GLAPI void GLAPIENTRY glMatrixMultTransposedEXT(GLenum mode, const GLdouble* m);
GLAPI void GLAPIENTRY glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param);
GLAPI void GLAPIENTRY glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glCopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI void GLAPIENTRY glCopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI void GLAPIENTRY glCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void GLAPIENTRY glCopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels);
GLAPI void GLAPIENTRY glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glCopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param);
GLAPI void GLAPIENTRY glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glCopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI void GLAPIENTRY glCopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI void GLAPIENTRY glCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void GLAPIENTRY glCopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels);
GLAPI void GLAPIENTRY glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glCopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture);
GLAPI void GLAPIENTRY glEnableClientStateIndexedEXT(GLenum array, GLuint index);
GLAPI void GLAPIENTRY glEnableClientStateiEXT(GLenum array, GLuint index);
GLAPI void GLAPIENTRY glDisableClientStateIndexedEXT(GLenum array, GLuint index);
GLAPI void GLAPIENTRY glDisableClientStateiEXT(GLenum array, GLuint index);
GLAPI void GLAPIENTRY glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
GLAPI void GLAPIENTRY glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param);
GLAPI void GLAPIENTRY glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
GLAPI void GLAPIENTRY glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLdouble* params);
GLAPI void GLAPIENTRY glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param);
GLAPI void GLAPIENTRY glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble* params);
GLAPI void GLAPIENTRY glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat* data);
GLAPI void GLAPIENTRY glGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble* data);
GLAPI void GLAPIENTRY glGetPointerIndexedvEXT(GLenum target, GLuint index, GLvoid** data);
GLAPI void GLAPIENTRY glGetFloati_vEXT(GLenum target, GLuint index, GLfloat* data);
GLAPI void GLAPIENTRY glGetDoublei_vEXT(GLenum target, GLuint index, GLdouble* data);
GLAPI void GLAPIENTRY glGetPointeri_vEXT(GLenum target, GLuint index, GLvoid** data);
GLAPI void GLAPIENTRY glCompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* bits);
GLAPI void GLAPIENTRY glCompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* bits);
GLAPI void GLAPIENTRY glCompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* bits);
GLAPI void GLAPIENTRY glCompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* bits);
GLAPI void GLAPIENTRY glCompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* bits);
GLAPI void GLAPIENTRY glCompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* bits);
GLAPI void GLAPIENTRY glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint lod, GLvoid* img);
GLAPI void GLAPIENTRY glCompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* bits);
GLAPI void GLAPIENTRY glCompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* bits);
GLAPI void GLAPIENTRY glCompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* bits);
GLAPI void GLAPIENTRY glCompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* bits);
GLAPI void GLAPIENTRY glCompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* bits);
GLAPI void GLAPIENTRY glCompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* bits);
GLAPI void GLAPIENTRY glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint lod, GLvoid* img);
GLAPI void GLAPIENTRY glNamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, const GLvoid* string);
GLAPI void GLAPIENTRY glNamedProgramLocalParameter4dEXT(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glNamedProgramLocalParameter4dvEXT(GLuint program, GLenum target, GLuint index, const GLdouble* params);
GLAPI void GLAPIENTRY glNamedProgramLocalParameter4fEXT(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glNamedProgramLocalParameter4fvEXT(GLuint program, GLenum target, GLuint index, const GLfloat* params);
GLAPI void GLAPIENTRY glGetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble* params);
GLAPI void GLAPIENTRY glGetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat* params);
GLAPI void GLAPIENTRY glGetNamedProgramivEXT(GLuint program, GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetNamedProgramStringEXT(GLuint program, GLenum target, GLenum pname, GLvoid* string);
GLAPI void GLAPIENTRY glNamedProgramLocalParameters4fvEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat* params);
GLAPI void GLAPIENTRY glNamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void GLAPIENTRY glNamedProgramLocalParameterI4ivEXT(GLuint program, GLenum target, GLuint index, const GLint* params);
GLAPI void GLAPIENTRY glNamedProgramLocalParametersI4ivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint* params);
GLAPI void GLAPIENTRY glNamedProgramLocalParameterI4uiEXT(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void GLAPIENTRY glNamedProgramLocalParameterI4uivEXT(GLuint program, GLenum target, GLuint index, const GLuint* params);
GLAPI void GLAPIENTRY glNamedProgramLocalParametersI4uivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint* params);
GLAPI void GLAPIENTRY glGetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint* params);
GLAPI void GLAPIENTRY glGetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint* params);
GLAPI void GLAPIENTRY glTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, const GLuint* params);
GLAPI void GLAPIENTRY glGetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint* params);
GLAPI void GLAPIENTRY glMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, const GLuint* params);
GLAPI void GLAPIENTRY glGetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint* params);
GLAPI void GLAPIENTRY glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0);
GLAPI void GLAPIENTRY glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1);
GLAPI void GLAPIENTRY glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void GLAPIENTRY glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void GLAPIENTRY glProgramUniform1iEXT(GLuint program, GLint location, GLint v0);
GLAPI void GLAPIENTRY glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1);
GLAPI void GLAPIENTRY glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void GLAPIENTRY glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void GLAPIENTRY glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value);
GLAPI void GLAPIENTRY glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value);
GLAPI void GLAPIENTRY glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value);
GLAPI void GLAPIENTRY glProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix2x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix3x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix2x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix4x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix3x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix4x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0);
GLAPI void GLAPIENTRY glProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1);
GLAPI void GLAPIENTRY glProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void GLAPIENTRY glProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void GLAPIENTRY glProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value);
GLAPI void GLAPIENTRY glProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value);
GLAPI void GLAPIENTRY glProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value);
GLAPI void GLAPIENTRY glProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value);
GLAPI void GLAPIENTRY glNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, const GLvoid* data, GLenum usage);
GLAPI void GLAPIENTRY glNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid* data);
GLAPI GLvoid* GLAPIENTRY glMapNamedBufferEXT(GLuint buffer, GLenum access);
GLAPI GLboolean GLAPIENTRY glUnmapNamedBufferEXT(GLuint buffer);
GLAPI void GLAPIENTRY glGetNamedBufferParameterivEXT(GLuint buffer, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetNamedBufferPointervEXT(GLuint buffer, GLenum pname, GLvoid** params);
GLAPI void GLAPIENTRY glGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid* data);
GLAPI void GLAPIENTRY glTextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
GLAPI void GLAPIENTRY glMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
GLAPI void GLAPIENTRY glNamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glGetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum pname, GLint* params);
GLAPI GLenum GLAPIENTRY glCheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target);
GLAPI void GLAPIENTRY glNamedFramebufferTexture1DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void GLAPIENTRY glNamedFramebufferTexture2DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void GLAPIENTRY glNamedFramebufferTexture3DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLAPI void GLAPIENTRY glNamedFramebufferRenderbufferEXT(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void GLAPIENTRY glGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGenerateTextureMipmapEXT(GLuint texture, GLenum target);
GLAPI void GLAPIENTRY glGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target);
GLAPI void GLAPIENTRY glFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode);
GLAPI void GLAPIENTRY glFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, const GLenum* bufs);
GLAPI void GLAPIENTRY glFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode);
GLAPI void GLAPIENTRY glGetFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glNamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
GLAPI void GLAPIENTRY glNamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void GLAPIENTRY glNamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
GLAPI void GLAPIENTRY glTextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer);
GLAPI void GLAPIENTRY glMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer);
GLAPI void GLAPIENTRY glVertexArrayVertexOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void GLAPIENTRY glVertexArrayColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void GLAPIENTRY glVertexArrayEdgeFlagOffsetEXT(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
GLAPI void GLAPIENTRY glVertexArrayIndexOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void GLAPIENTRY glVertexArrayNormalOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void GLAPIENTRY glVertexArrayTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void GLAPIENTRY glVertexArrayMultiTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void GLAPIENTRY glVertexArrayFogCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void GLAPIENTRY glVertexArraySecondaryColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void GLAPIENTRY glVertexArrayVertexAttribOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
GLAPI void GLAPIENTRY glVertexArrayVertexAttribIOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void GLAPIENTRY glEnableVertexArrayEXT(GLuint vaobj, GLenum array);
GLAPI void GLAPIENTRY glDisableVertexArrayEXT(GLuint vaobj, GLenum array);
GLAPI void GLAPIENTRY glEnableVertexArrayAttribEXT(GLuint vaobj, GLenum array);
GLAPI void GLAPIENTRY glDisableVertexArrayAttribEXT(GLuint vaobj, GLenum array);
GLAPI void GLAPIENTRY glGetVertexArrayIntegervEXT(GLuint vaobj, GLenum pname, GLint* param);
GLAPI void GLAPIENTRY glGetVertexArrayPointervEXT(GLuint vaobj, GLenum pname, GLvoid** param);
GLAPI void GLAPIENTRY glGetVertexArrayIntegeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLint* param);
GLAPI void GLAPIENTRY glGetVertexArrayPointeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLvoid** param);
GLAPI GLvoid* GLAPIENTRY glMapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI void GLAPIENTRY glFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI void GLAPIENTRY glNamedCopyBufferSubDataEXT(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI void GLAPIENTRY glGetNamedBufferParameteri64vEXT(GLuint buffer, GLenum pname, GLint64* params);
GLAPI void GLAPIENTRY glProgramUniform1dEXT(GLuint program, GLint location, GLdouble x);
GLAPI void GLAPIENTRY glProgramUniform2dEXT(GLuint program, GLint location, GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glProgramUniform3dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glProgramUniform4dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glProgramUniform1dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniform2dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniform3dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniform4dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix2x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix2x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix3x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix3x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix4x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix4x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glTextureBufferRangeEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLsizeiptr offset, GLsizeiptr range);
GLAPI void GLAPIENTRY glTextureStorage2DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
GLAPI void GLAPIENTRY glTextureStorage3DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
GLAPI void GLAPIENTRY glClearNamedBufferDataEXT(GLuint buffer, GLenum internalFormat, GLenum format, GLenum type, const GLvoid* data);
GLAPI void GLAPIENTRY glClearNamedBufferSubDataEXT(GLuint buffer, GLenum internalFormat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid* data);
GLAPI void GLAPIENTRY glNamedFramebufferParameteriEXT(GLuint framebuffer, GLenum pname, GLint param);
GLAPI void GLAPIENTRY glGetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glNamedBufferStorageEXT(GLuint buffer, GLsizeiptr size, const GLvoid* data, GLbitfield flags);
GLAPI void GLAPIENTRY glVertexArrayVertexAttribDivisorEXT(GLuint vaobj, GLuint index, GLuint divisor);
GLAPI void GLAPIENTRY glTexturePageCommitmentEXT(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
GLAPI void GLAPIENTRY glNamedBufferPageCommitmentEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCLIENTATTRIBDEFAULTEXTPROC)(GLbitfield mask);
typedef void (GLAPIENTRYP PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC)(GLbitfield mask);
typedef void (GLAPIENTRYP PFNGLMATRIXLOADFEXTPROC)(GLenum mode, const GLfloat* m);
typedef void (GLAPIENTRYP PFNGLMATRIXLOADDEXTPROC)(GLenum mode, const GLdouble* m);
typedef void (GLAPIENTRYP PFNGLMATRIXMULTFEXTPROC)(GLenum mode, const GLfloat* m);
typedef void (GLAPIENTRYP PFNGLMATRIXMULTDEXTPROC)(GLenum mode, const GLdouble* m);
typedef void (GLAPIENTRYP PFNGLMATRIXLOADIDENTITYEXTPROC)(GLenum mode);
typedef void (GLAPIENTRYP PFNGLMATRIXROTATEFEXTPROC)(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLMATRIXROTATEDEXTPROC)(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLMATRIXSCALEFEXTPROC)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLMATRIXSCALEDEXTPROC)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLMATRIXTRANSLATEFEXTPROC)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLMATRIXTRANSLATEDEXTPROC)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLMATRIXFRUSTUMEXTPROC)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (GLAPIENTRYP PFNGLMATRIXORTHOEXTPROC)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (GLAPIENTRYP PFNGLMATRIXPOPEXTPROC)(GLenum mode);
typedef void (GLAPIENTRYP PFNGLMATRIXPUSHEXTPROC)(GLenum mode);
typedef void (GLAPIENTRYP PFNGLMATRIXLOADTRANSPOSEFEXTPROC)(GLenum mode, const GLfloat* m);
typedef void (GLAPIENTRYP PFNGLMATRIXLOADTRANSPOSEDEXTPROC)(GLenum mode, const GLdouble* m);
typedef void (GLAPIENTRYP PFNGLMATRIXMULTTRANSPOSEFEXTPROC)(GLenum mode, const GLfloat* m);
typedef void (GLAPIENTRYP PFNGLMATRIXMULTTRANSPOSEDEXTPROC)(GLenum mode, const GLdouble* m);
typedef void (GLAPIENTRYP PFNGLTEXTUREPARAMETERFEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLTEXTUREPARAMETERFVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLTEXTUREPARAMETERIEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLTEXTUREPARAMETERIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLTEXTUREIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLTEXTUREIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLTEXTURESUBIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLTEXTURESUBIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLCOPYTEXTUREIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (GLAPIENTRYP PFNGLCOPYTEXTUREIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (GLAPIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (GLAPIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLGETTEXTUREIMAGEEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLGETTEXTUREPARAMETERFVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETTEXTUREPARAMETERIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLTEXTUREIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLTEXTURESUBIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLMULTITEXPARAMETERFEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLMULTITEXPARAMETERFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLMULTITEXPARAMETERIEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLMULTITEXPARAMETERIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLMULTITEXIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLMULTITEXIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLMULTITEXSUBIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLMULTITEXSUBIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLCOPYMULTITEXIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (GLAPIENTRYP PFNGLCOPYMULTITEXIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (GLAPIENTRYP PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (GLAPIENTRYP PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLGETMULTITEXIMAGEEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLGETMULTITEXPARAMETERFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETMULTITEXPARAMETERIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLMULTITEXIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLMULTITEXSUBIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLBINDMULTITEXTUREEXTPROC)(GLenum texunit, GLenum target, GLuint texture);
typedef void (GLAPIENTRYP PFNGLENABLECLIENTSTATEINDEXEDEXTPROC)(GLenum array, GLuint index);
typedef void (GLAPIENTRYP PFNGLENABLECLIENTSTATEIEXTPROC)(GLenum array, GLuint index);
typedef void (GLAPIENTRYP PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC)(GLenum array, GLuint index);
typedef void (GLAPIENTRYP PFNGLDISABLECLIENTSTATEIEXTPROC)(GLenum array, GLuint index);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDPOINTEREXTPROC)(GLenum texunit, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLMULTITEXENVFEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLMULTITEXENVFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLMULTITEXENVIEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLMULTITEXENVIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLMULTITEXGENDEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
typedef void (GLAPIENTRYP PFNGLMULTITEXGENDVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, const GLdouble* params);
typedef void (GLAPIENTRYP PFNGLMULTITEXGENFEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLMULTITEXGENFVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLMULTITEXGENIEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLMULTITEXGENIVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLGETMULTITEXENVFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETMULTITEXENVIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETMULTITEXGENDVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLdouble* params);
typedef void (GLAPIENTRYP PFNGLGETMULTITEXGENFVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETMULTITEXGENIVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETFLOATINDEXEDVEXTPROC)(GLenum target, GLuint index, GLfloat* data);
typedef void (GLAPIENTRYP PFNGLGETDOUBLEINDEXEDVEXTPROC)(GLenum target, GLuint index, GLdouble* data);
typedef void (GLAPIENTRYP PFNGLGETPOINTERINDEXEDVEXTPROC)(GLenum target, GLuint index, GLvoid** data);
typedef void (GLAPIENTRYP PFNGLGETFLOATI_VEXTPROC)(GLenum target, GLuint index, GLfloat* data);
typedef void (GLAPIENTRYP PFNGLGETDOUBLEI_VEXTPROC)(GLenum target, GLuint index, GLdouble* data);
typedef void (GLAPIENTRYP PFNGLGETPOINTERI_VEXTPROC)(GLenum target, GLuint index, GLvoid** data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* bits);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* bits);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* bits);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* bits);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* bits);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* bits);
typedef void (GLAPIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC)(GLuint texture, GLenum target, GLint lod, GLvoid* img);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* bits);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* bits);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* bits);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* bits);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* bits);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* bits);
typedef void (GLAPIENTRYP PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC)(GLenum texunit, GLenum target, GLint lod, GLvoid* img);
typedef void (GLAPIENTRYP PFNGLNAMEDPROGRAMSTRINGEXTPROC)(GLuint program, GLenum target, GLenum format, GLsizei len, const GLvoid* string);
typedef void (GLAPIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC)(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC)(GLuint program, GLenum target, GLuint index, const GLdouble* params);
typedef void (GLAPIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC)(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC)(GLuint program, GLenum target, GLuint index, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC)(GLuint program, GLenum target, GLuint index, GLdouble* params);
typedef void (GLAPIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC)(GLuint program, GLenum target, GLuint index, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETNAMEDPROGRAMIVEXTPROC)(GLuint program, GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETNAMEDPROGRAMSTRINGEXTPROC)(GLuint program, GLenum target, GLenum pname, GLvoid* string);
typedef void (GLAPIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC)(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (GLAPIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC)(GLuint program, GLenum target, GLuint index, const GLint* params);
typedef void (GLAPIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint* params);
typedef void (GLAPIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC)(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (GLAPIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC)(GLuint program, GLenum target, GLuint index, const GLuint* params);
typedef void (GLAPIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC)(GLuint program, GLenum target, GLuint index, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC)(GLuint program, GLenum target, GLuint index, GLuint* params);
typedef void (GLAPIENTRYP PFNGLTEXTUREPARAMETERIIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLTEXTUREPARAMETERIUIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETTEXTUREPARAMETERIIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETTEXTUREPARAMETERIUIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLuint* params);
typedef void (GLAPIENTRYP PFNGLMULTITEXPARAMETERIIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLMULTITEXPARAMETERIUIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETMULTITEXPARAMETERIIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETMULTITEXPARAMETERIUIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLuint* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1FEXTPROC)(GLuint program, GLint location, GLfloat v0);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1IEXTPROC)(GLuint program, GLint location, GLint v0);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1UIEXTPROC)(GLuint program, GLint location, GLuint v0);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLNAMEDBUFFERDATAEXTPROC)(GLuint buffer, GLsizeiptr size, const GLvoid* data, GLenum usage);
typedef void (GLAPIENTRYP PFNGLNAMEDBUFFERSUBDATAEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid* data);
typedef GLvoid* (GLAPIENTRYP PFNGLMAPNAMEDBUFFEREXTPROC)(GLuint buffer, GLenum access);
typedef GLboolean (GLAPIENTRYP PFNGLUNMAPNAMEDBUFFEREXTPROC)(GLuint buffer);
typedef void (GLAPIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC)(GLuint buffer, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETNAMEDBUFFERPOINTERVEXTPROC)(GLuint buffer, GLenum pname, GLvoid** params);
typedef void (GLAPIENTRYP PFNGLGETNAMEDBUFFERSUBDATAEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid* data);
typedef void (GLAPIENTRYP PFNGLTEXTUREBUFFEREXTPROC)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
typedef void (GLAPIENTRYP PFNGLMULTITEXBUFFEREXTPROC)(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
typedef void (GLAPIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC)(GLuint renderbuffer, GLenum pname, GLint* params);
typedef GLenum (GLAPIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC)(GLuint framebuffer, GLenum target);
typedef void (GLAPIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (GLAPIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (GLAPIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (GLAPIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (GLAPIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGENERATETEXTUREMIPMAPEXTPROC)(GLuint texture, GLenum target);
typedef void (GLAPIENTRYP PFNGLGENERATEMULTITEXMIPMAPEXTPROC)(GLenum texunit, GLenum target);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC)(GLuint framebuffer, GLenum mode);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC)(GLuint framebuffer, GLsizei n, const GLenum* bufs);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERREADBUFFEREXTPROC)(GLuint framebuffer, GLenum mode);
typedef void (GLAPIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC)(GLuint framebuffer, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC)(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
typedef void (GLAPIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (GLAPIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
typedef void (GLAPIENTRYP PFNGLTEXTURERENDERBUFFEREXTPROC)(GLuint texture, GLenum target, GLuint renderbuffer);
typedef void (GLAPIENTRYP PFNGLMULTITEXRENDERBUFFEREXTPROC)(GLenum texunit, GLenum target, GLuint renderbuffer);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYCOLOROFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYINDEXOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYNORMALOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLENABLEVERTEXARRAYEXTPROC)(GLuint vaobj, GLenum array);
typedef void (GLAPIENTRYP PFNGLDISABLEVERTEXARRAYEXTPROC)(GLuint vaobj, GLenum array);
typedef void (GLAPIENTRYP PFNGLENABLEVERTEXARRAYATTRIBEXTPROC)(GLuint vaobj, GLenum array);
typedef void (GLAPIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC)(GLuint vaobj, GLenum array);
typedef void (GLAPIENTRYP PFNGLGETVERTEXARRAYINTEGERVEXTPROC)(GLuint vaobj, GLenum pname, GLint* param);
typedef void (GLAPIENTRYP PFNGLGETVERTEXARRAYPOINTERVEXTPROC)(GLuint vaobj, GLenum pname, GLvoid** param);
typedef void (GLAPIENTRYP PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint* param);
typedef void (GLAPIENTRYP PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC)(GLuint vaobj, GLuint index, GLenum pname, GLvoid** param);
typedef GLvoid* (GLAPIENTRYP PFNGLMAPNAMEDBUFFERRANGEEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (GLAPIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (GLAPIENTRYP PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (GLAPIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VEXTPROC)(GLuint buffer, GLenum pname, GLint64* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1DEXTPROC)(GLuint program, GLint location, GLdouble x);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2DEXTPROC)(GLuint program, GLint location, GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3DEXTPROC)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4DEXTPROC)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1DVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2DVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3DVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4DVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLTEXTUREBUFFERRANGEEXTPROC)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLsizeiptr offset, GLsizeiptr range);
typedef void (GLAPIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC)(GLuint texture, GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
typedef void (GLAPIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC)(GLuint texture, GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
typedef void (GLAPIENTRYP PFNGLCLEARNAMEDBUFFERDATAEXTPROC)(GLuint buffer, GLenum internalFormat, GLenum format, GLenum type, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC)(GLuint buffer, GLenum internalFormat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC)(GLuint framebuffer, GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC)(GLuint framebuffer, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLNAMEDBUFFERSTORAGEEXTPROC)(GLuint buffer, GLsizeiptr size, const GLvoid* data, GLbitfield flags);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC)(GLuint vaobj, GLuint index, GLuint divisor);
typedef void (GLAPIENTRYP PFNGLTEXTUREPAGECOMMITMENTEXTPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
typedef void (GLAPIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
#endif


#ifndef GL_EXT_discard_framebuffer
#define GL_EXT_discard_framebuffer 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDiscardFramebufferEXT(GLenum target, GLsizei numAttachments, const GLenum* attachments);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDISCARDFRAMEBUFFEREXTPROC)(GLenum target, GLsizei numAttachments, const GLenum* attachments);
#endif


#ifndef GL_EXT_disjoint_timer_query
#define GL_EXT_disjoint_timer_query 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glQueryCounterEXT(GLuint id, GLenum target);
GLAPI void GLAPIENTRY glGetQueryObjectivEXT(GLuint id, GLenum pname, GLint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLQUERYCOUNTEREXTPROC)(GLuint id, GLenum target);
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTIVEXTPROC)(GLuint id, GLenum pname, GLint* params);
#endif


#ifndef GL_EXT_draw_buffers_indexed
#define GL_EXT_draw_buffers_indexed 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glEnableiEXT(GLenum target, GLuint index);
GLAPI void GLAPIENTRY glDisableiEXT(GLenum target, GLuint index);
GLAPI void GLAPIENTRY glBlendEquationiEXT(GLuint buf, GLenum mode);
GLAPI void GLAPIENTRY glBlendEquationSeparateiEXT(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI void GLAPIENTRY glBlendFunciEXT(GLuint buf, GLenum src, GLenum dst);
GLAPI void GLAPIENTRY glBlendFuncSeparateiEXT(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GLAPI void GLAPIENTRY glColorMaskiEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLAPI GLboolean GLAPIENTRY glIsEnablediEXT(GLenum target, GLuint index);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLENABLEIEXTPROC)(GLenum target, GLuint index);
typedef void (GLAPIENTRYP PFNGLDISABLEIEXTPROC)(GLenum target, GLuint index);
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONIEXTPROC)(GLuint buf, GLenum mode);
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONSEPARATEIEXTPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (GLAPIENTRYP PFNGLBLENDFUNCIEXTPROC)(GLuint buf, GLenum src, GLenum dst);
typedef void (GLAPIENTRYP PFNGLBLENDFUNCSEPARATEIEXTPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef void (GLAPIENTRYP PFNGLCOLORMASKIEXTPROC)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef GLboolean (GLAPIENTRYP PFNGLISENABLEDIEXTPROC)(GLenum target, GLuint index);
#endif


#ifndef GL_EXT_draw_buffers2
#define GL_EXT_draw_buffers2 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glColorMaskIndexedEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLAPI void GLAPIENTRY glGetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean* data);
GLAPI void GLAPIENTRY glGetIntegerIndexedvEXT(GLenum target, GLuint index, GLint* data);
GLAPI void GLAPIENTRY glEnableIndexedEXT(GLenum target, GLuint index);
GLAPI void GLAPIENTRY glDisableIndexedEXT(GLenum target, GLuint index);
GLAPI GLboolean GLAPIENTRY glIsEnabledIndexedEXT(GLenum target, GLuint index);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOLORMASKINDEXEDEXTPROC)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void (GLAPIENTRYP PFNGLGETBOOLEANINDEXEDVEXTPROC)(GLenum target, GLuint index, GLboolean* data);
typedef void (GLAPIENTRYP PFNGLGETINTEGERINDEXEDVEXTPROC)(GLenum target, GLuint index, GLint* data);
typedef void (GLAPIENTRYP PFNGLENABLEINDEXEDEXTPROC)(GLenum target, GLuint index);
typedef void (GLAPIENTRYP PFNGLDISABLEINDEXEDEXTPROC)(GLenum target, GLuint index);
typedef GLboolean (GLAPIENTRYP PFNGLISENABLEDINDEXEDEXTPROC)(GLenum target, GLuint index);
#endif


#ifndef GL_EXT_draw_elements_base_vertex
#define GL_EXT_draw_elements_base_vertex 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawElementsBaseVertexEXT(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
GLAPI void GLAPIENTRY glDrawRangeElementsBaseVertexEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
GLAPI void GLAPIENTRY glDrawElementsInstancedBaseVertexEXT(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLint basevertex);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSBASEVERTEXEXTPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
typedef void (GLAPIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXEXTPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXEXTPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLint basevertex);
#endif


#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawArraysInstancedEXT(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
GLAPI void GLAPIENTRY glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei primcount);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWARRAYSINSTANCEDEXTPROC)(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSINSTANCEDEXTPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei primcount);
#endif


#ifndef GL_EXT_draw_range_elements
#define GL_EXT_draw_range_elements 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWRANGEELEMENTSEXTPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices);
#endif


#ifndef GL_EXT_fog_coord
#define GL_EXT_fog_coord 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glFogCoorddEXT(GLdouble fog);
GLAPI void GLAPIENTRY glFogCoorddvEXT(const GLdouble* fog);
GLAPI void GLAPIENTRY glFogCoordfEXT(GLfloat fog);
GLAPI void GLAPIENTRY glFogCoordfvEXT(const GLfloat* fog);
GLAPI void GLAPIENTRY glFogCoordPointerEXT(GLenum type, GLsizei stride, const GLvoid* pointer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLFOGCOORDDEXTPROC)(GLdouble fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDDVEXTPROC)(const GLdouble* fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDFEXTPROC)(GLfloat fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDFVEXTPROC)(const GLfloat* fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDPOINTEREXTPROC)(GLenum type, GLsizei stride, const GLvoid* pointer);
#endif


#ifndef GL_EXT_framebuffer_blit
#define GL_EXT_framebuffer_blit 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLITFRAMEBUFFEREXTPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#endif


#ifndef GL_EXT_framebuffer_multisample
#define GL_EXT_framebuffer_multisample 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#endif


#ifndef GL_EXT_framebuffer_object
#define GL_EXT_framebuffer_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLboolean GLAPIENTRY glIsRenderbufferEXT(GLuint renderbuffer);
GLAPI void GLAPIENTRY glBindRenderbufferEXT(GLenum target, GLuint renderbuffer);
GLAPI void GLAPIENTRY glDeleteRenderbuffersEXT(GLsizei n, const GLuint* renderbuffers);
GLAPI void GLAPIENTRY glGenRenderbuffersEXT(GLsizei n, GLuint* renderbuffers);
GLAPI void GLAPIENTRY glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint* params);
GLAPI GLboolean GLAPIENTRY glIsFramebufferEXT(GLuint framebuffer);
GLAPI void GLAPIENTRY glBindFramebufferEXT(GLenum target, GLuint framebuffer);
GLAPI void GLAPIENTRY glDeleteFramebuffersEXT(GLsizei n, const GLuint* framebuffers);
GLAPI void GLAPIENTRY glGenFramebuffersEXT(GLsizei n, GLuint* framebuffers);
GLAPI GLenum GLAPIENTRY glCheckFramebufferStatusEXT(GLenum target);
GLAPI void GLAPIENTRY glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void GLAPIENTRY glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void GLAPIENTRY glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLAPI void GLAPIENTRY glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void GLAPIENTRY glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGenerateMipmapEXT(GLenum target);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLboolean (GLAPIENTRYP PFNGLISRENDERBUFFEREXTPROC)(GLuint renderbuffer);
typedef void (GLAPIENTRYP PFNGLBINDRENDERBUFFEREXTPROC)(GLenum target, GLuint renderbuffer);
typedef void (GLAPIENTRYP PFNGLDELETERENDERBUFFERSEXTPROC)(GLsizei n, const GLuint* renderbuffers);
typedef void (GLAPIENTRYP PFNGLGENRENDERBUFFERSEXTPROC)(GLsizei n, GLuint* renderbuffers);
typedef void (GLAPIENTRYP PFNGLRENDERBUFFERSTORAGEEXTPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint* params);
typedef GLboolean (GLAPIENTRYP PFNGLISFRAMEBUFFEREXTPROC)(GLuint framebuffer);
typedef void (GLAPIENTRYP PFNGLBINDFRAMEBUFFEREXTPROC)(GLenum target, GLuint framebuffer);
typedef void (GLAPIENTRYP PFNGLDELETEFRAMEBUFFERSEXTPROC)(GLsizei n, const GLuint* framebuffers);
typedef void (GLAPIENTRYP PFNGLGENFRAMEBUFFERSEXTPROC)(GLsizei n, GLuint* framebuffers);
typedef GLenum (GLAPIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)(GLenum target);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTURE1DEXTPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTURE3DEXTPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (GLAPIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(GLenum target, GLenum attachment, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGENERATEMIPMAPEXTPROC)(GLenum target);
#endif


#ifndef GL_EXT_geometry_shader4
#define GL_EXT_geometry_shader4 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glProgramParameteriEXT(GLuint program, GLenum pname, GLint value);
GLAPI void GLAPIENTRY glFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level);
GLAPI void GLAPIENTRY glFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void GLAPIENTRY glFramebufferTextureFaceEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPROGRAMPARAMETERIEXTPROC)(GLuint program, GLenum pname, GLint value);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTUREEXTPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
#endif


#ifndef GL_EXT_gpu_program_parameters
#define GL_EXT_gpu_program_parameters 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glProgramEnvParameters4fvEXT(GLenum target, GLuint index, GLsizei count, const GLfloat* params);
GLAPI void GLAPIENTRY glProgramLocalParameters4fvEXT(GLenum target, GLuint index, GLsizei count, const GLfloat* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETERS4FVEXTPROC)(GLenum target, GLuint index, GLsizei count, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC)(GLenum target, GLuint index, GLsizei count, const GLfloat* params);
#endif


#ifndef GL_EXT_gpu_shader4
#define GL_EXT_gpu_shader4 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGetUniformuivEXT(GLuint program, GLint location, GLuint* params);
GLAPI void GLAPIENTRY glBindFragDataLocationEXT(GLuint program, GLuint color, const GLchar* name);
GLAPI GLint GLAPIENTRY glGetFragDataLocationEXT(GLuint program, const GLchar* name);
GLAPI void GLAPIENTRY glUniform1uiEXT(GLint location, GLuint v0);
GLAPI void GLAPIENTRY glUniform2uiEXT(GLint location, GLuint v0, GLuint v1);
GLAPI void GLAPIENTRY glUniform3uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void GLAPIENTRY glUniform4uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void GLAPIENTRY glUniform1uivEXT(GLint location, GLsizei count, const GLuint* value);
GLAPI void GLAPIENTRY glUniform2uivEXT(GLint location, GLsizei count, const GLuint* value);
GLAPI void GLAPIENTRY glUniform3uivEXT(GLint location, GLsizei count, const GLuint* value);
GLAPI void GLAPIENTRY glUniform4uivEXT(GLint location, GLsizei count, const GLuint* value);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGETUNIFORMUIVEXTPROC)(GLuint program, GLint location, GLuint* params);
typedef void (GLAPIENTRYP PFNGLBINDFRAGDATALOCATIONEXTPROC)(GLuint program, GLuint color, const GLchar* name);
typedef GLint (GLAPIENTRYP PFNGLGETFRAGDATALOCATIONEXTPROC)(GLuint program, const GLchar* name);
typedef void (GLAPIENTRYP PFNGLUNIFORM1UIEXTPROC)(GLint location, GLuint v0);
typedef void (GLAPIENTRYP PFNGLUNIFORM2UIEXTPROC)(GLint location, GLuint v0, GLuint v1);
typedef void (GLAPIENTRYP PFNGLUNIFORM3UIEXTPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (GLAPIENTRYP PFNGLUNIFORM4UIEXTPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (GLAPIENTRYP PFNGLUNIFORM1UIVEXTPROC)(GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM2UIVEXTPROC)(GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM3UIVEXTPROC)(GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM4UIVEXTPROC)(GLint location, GLsizei count, const GLuint* value);
#endif


#ifndef GL_EXT_import_sync_object
#define GL_EXT_import_sync_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLsync GLAPIENTRY glImportSyncEXT(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLsync (GLAPIENTRYP PFNGLIMPORTSYNCEXTPROC)(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags);
#endif


#ifndef GL_EXT_map_buffer_range
#define GL_EXT_map_buffer_range 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLvoid* GLAPIENTRY glMapBufferRangeEXT(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI void GLAPIENTRY glFlushMappedBufferRangeEXT(GLenum target, GLintptr offset, GLsizeiptr length);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLvoid* (GLAPIENTRYP PFNGLMAPBUFFERRANGEEXTPROC)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (GLAPIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEEXTPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
#endif


#ifndef GL_EXT_memory_object
#define GL_EXT_memory_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGetUnsignedBytevEXT(GLenum pname, GLubyte* data);
GLAPI void GLAPIENTRY glGetUnsignedBytei_vEXT(GLenum target, GLuint index, GLubyte* data);
GLAPI void GLAPIENTRY glCreateMemoryObjectsEXT(GLsizei n, GLuint* memoryObjects);
GLAPI void GLAPIENTRY glDeleteMemoryObjectsEXT(GLsizei n, const GLuint* memoryObjects);
GLAPI GLboolean GLAPIENTRY glIsMemoryObjectEXT(GLuint memoryObject);
GLAPI void GLAPIENTRY glMemoryObjectParameterivEXT(GLuint memoryObject, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glGetMemoryObjectParameterivEXT(GLuint memoryObject, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glTexStorageMem1DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLuint memory, GLuint64 offset);
GLAPI void GLAPIENTRY glTexStorageMem2DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset);
GLAPI void GLAPIENTRY glTexStorageMem2DMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, GLuint memory, GLuint64 offset);
GLAPI void GLAPIENTRY glTexStorageMem3DEXT(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset);
GLAPI void GLAPIENTRY glTexStorageMem3DMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, GLuint memory, GLuint64 offset);
GLAPI void GLAPIENTRY glBufferStorageMemEXT(GLenum target, GLsizeiptr size, GLuint memory, GLuint64 offset);
GLAPI void GLAPIENTRY glTextureStorageMem1DEXT(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLuint memory, GLuint64 offset);
GLAPI void GLAPIENTRY glTextureStorageMem2DEXT(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset);
GLAPI void GLAPIENTRY glTextureStorageMem2DMultisampleEXT(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset);
GLAPI void GLAPIENTRY glTextureStorageMem3DEXT(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset);
GLAPI void GLAPIENTRY glTextureStorageMem3DMultisampleEXT(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset);
GLAPI void GLAPIENTRY glNamedBufferStorageMemEXT(GLuint buffer, GLsizeiptr size, GLuint memory, GLuint64 offset);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGETUNSIGNEDBYTEVEXTPROC)(GLenum pname, GLubyte* data);
typedef void (GLAPIENTRYP PFNGLGETUNSIGNEDBYTEI_VEXTPROC)(GLenum target, GLuint index, GLubyte* data);
typedef void (GLAPIENTRYP PFNGLCREATEMEMORYOBJECTSEXTPROC)(GLsizei n, GLuint* memoryObjects);
typedef void (GLAPIENTRYP PFNGLDELETEMEMORYOBJECTSEXTPROC)(GLsizei n, const GLuint* memoryObjects);
typedef GLboolean (GLAPIENTRYP PFNGLISMEMORYOBJECTEXTPROC)(GLuint memoryObject);
typedef void (GLAPIENTRYP PFNGLMEMORYOBJECTPARAMETERIVEXTPROC)(GLuint memoryObject, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLGETMEMORYOBJECTPARAMETERIVEXTPROC)(GLuint memoryObject, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLTEXSTORAGEMEM1DEXTPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLuint memory, GLuint64 offset);
typedef void (GLAPIENTRYP PFNGLTEXSTORAGEMEM2DEXTPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset);
typedef void (GLAPIENTRYP PFNGLTEXSTORAGEMEM2DMULTISAMPLEEXTPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, GLuint memory, GLuint64 offset);
typedef void (GLAPIENTRYP PFNGLTEXSTORAGEMEM3DEXTPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset);
typedef void (GLAPIENTRYP PFNGLTEXSTORAGEMEM3DMULTISAMPLEEXTPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, GLuint memory, GLuint64 offset);
typedef void (GLAPIENTRYP PFNGLBUFFERSTORAGEMEMEXTPROC)(GLenum target, GLsizeiptr size, GLuint memory, GLuint64 offset);
typedef void (GLAPIENTRYP PFNGLTEXTURESTORAGEMEM1DEXTPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLuint memory, GLuint64 offset);
typedef void (GLAPIENTRYP PFNGLTEXTURESTORAGEMEM2DEXTPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset);
typedef void (GLAPIENTRYP PFNGLTEXTURESTORAGEMEM2DMULTISAMPLEEXTPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset);
typedef void (GLAPIENTRYP PFNGLTEXTURESTORAGEMEM3DEXTPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset);
typedef void (GLAPIENTRYP PFNGLTEXTURESTORAGEMEM3DMULTISAMPLEEXTPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset);
typedef void (GLAPIENTRYP PFNGLNAMEDBUFFERSTORAGEMEMEXTPROC)(GLuint buffer, GLsizeiptr size, GLuint memory, GLuint64 offset);
#endif


#ifndef GL_EXT_memory_object_fd
#define GL_EXT_memory_object_fd 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glImportMemoryFdEXT(GLuint memory, GLuint64 size, GLenum handleType, GLint fd);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLIMPORTMEMORYFDEXTPROC)(GLuint memory, GLuint64 size, GLenum handleType, GLint fd);
#endif


#ifndef GL_EXT_memory_object_win32
#define GL_EXT_memory_object_win32 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glImportMemoryWin32HandleEXT(GLuint memory, GLuint64 size, GLenum handleType, const void* handle);
GLAPI void GLAPIENTRY glImportMemoryWin32NameEXT(GLuint memory, GLuint64 size, GLenum handleType, const void* name);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLIMPORTMEMORYWIN32HANDLEEXTPROC)(GLuint memory, GLuint64 size, GLenum handleType, const void* handle);
typedef void (GLAPIENTRYP PFNGLIMPORTMEMORYWIN32NAMEEXTPROC)(GLuint memory, GLuint64 size, GLenum handleType, const void* name);
#endif


#ifndef GL_EXT_multi_draw_arrays
#define GL_EXT_multi_draw_arrays 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glMultiDrawArraysEXT(GLenum mode, const GLint* first, const GLsizei* count, GLsizei primcount);
GLAPI void GLAPIENTRY glMultiDrawElementsEXT(GLenum mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei primcount);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLMULTIDRAWARRAYSEXTPROC)(GLenum mode, const GLint* first, const GLsizei* count, GLsizei primcount);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWELEMENTSEXTPROC)(GLenum mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei primcount);
#endif


#ifndef GL_EXT_multi_draw_indirect
#define GL_EXT_multi_draw_indirect 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glMultiDrawArraysIndirectEXT(GLenum mode, const GLvoid* indirect, GLsizei primcount, GLsizei stride);
GLAPI void GLAPIENTRY glMultiDrawElementsIndirectEXT(GLenum mode, GLenum type, const GLvoid* indirect, GLsizei primcount, GLsizei stride);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTEXTPROC)(GLenum mode, const GLvoid* indirect, GLsizei primcount, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTEXTPROC)(GLenum mode, GLenum type, const GLvoid* indirect, GLsizei primcount, GLsizei stride);
#endif


#ifndef GL_EXT_occlusion_query_boolean
#define GL_EXT_occlusion_query_boolean 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGenQueriesEXT(GLsizei n, GLuint* ids);
GLAPI void GLAPIENTRY glDeleteQueriesEXT(GLsizei n, const GLuint* ids);
GLAPI GLboolean GLAPIENTRY glIsQueryEXT(GLuint id);
GLAPI void GLAPIENTRY glBeginQueryEXT(GLenum target, GLuint id);
GLAPI void GLAPIENTRY glEndQueryEXT(GLenum target);
GLAPI void GLAPIENTRY glGetQueryivEXT(GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetQueryObjectuivEXT(GLuint id, GLenum pname, GLuint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGENQUERIESEXTPROC)(GLsizei n, GLuint* ids);
typedef void (GLAPIENTRYP PFNGLDELETEQUERIESEXTPROC)(GLsizei n, const GLuint* ids);
typedef GLboolean (GLAPIENTRYP PFNGLISQUERYEXTPROC)(GLuint id);
typedef void (GLAPIENTRYP PFNGLBEGINQUERYEXTPROC)(GLenum target, GLuint id);
typedef void (GLAPIENTRYP PFNGLENDQUERYEXTPROC)(GLenum target);
typedef void (GLAPIENTRYP PFNGLGETQUERYIVEXTPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTUIVEXTPROC)(GLuint id, GLenum pname, GLuint* params);
#endif


#ifndef GL_EXT_point_parameters
#define GL_EXT_point_parameters 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPointParameterfEXT(GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glPointParameterfvEXT(GLenum pname, const GLfloat* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERFEXTPROC)(GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERFVEXTPROC)(GLenum pname, const GLfloat* params);
#endif


#ifndef GL_EXT_polygon_offset_clamp
#define GL_EXT_polygon_offset_clamp 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPolygonOffsetClampEXT(GLfloat factor, GLfloat units, GLfloat clamp);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPOLYGONOFFSETCLAMPEXTPROC)(GLfloat factor, GLfloat units, GLfloat clamp);
#endif


#ifndef GL_EXT_primitive_bounding_box
#define GL_EXT_primitive_bounding_box 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPrimitiveBoundingBoxEXT(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPRIMITIVEBOUNDINGBOXEXTPROC)(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
#endif


#ifndef GL_EXT_provoking_vertex
#define GL_EXT_provoking_vertex 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glProvokingVertexEXT(GLenum mode);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPROVOKINGVERTEXEXTPROC)(GLenum mode);
#endif


#ifndef GL_EXT_raster_multisample
#define GL_EXT_raster_multisample 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glRasterSamplesEXT(GLuint samples, GLboolean fixedsamplelocations);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLRASTERSAMPLESEXTPROC)(GLuint samples, GLboolean fixedsamplelocations);
#endif


#ifndef GL_EXT_robustness
#define GL_EXT_robustness 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLenum GLAPIENTRY glGetGraphicsResetStatusEXT();
GLAPI void GLAPIENTRY glReadnPixelsEXT(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
GLAPI void GLAPIENTRY glGetnUniformfvEXT(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
GLAPI void GLAPIENTRY glGetnUniformivEXT(GLuint program, GLint location, GLsizei bufSize, GLint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLenum (GLAPIENTRYP PFNGLGETGRAPHICSRESETSTATUSEXTPROC)();
typedef void (GLAPIENTRYP PFNGLREADNPIXELSEXTPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLGETNUNIFORMFVEXTPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETNUNIFORMIVEXTPROC)(GLuint program, GLint location, GLsizei bufSize, GLint* params);
#endif


#ifndef GL_EXT_secondary_color
#define GL_EXT_secondary_color 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glSecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue);
GLAPI void GLAPIENTRY glSecondaryColor3bvEXT(const GLbyte* v);
GLAPI void GLAPIENTRY glSecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue);
GLAPI void GLAPIENTRY glSecondaryColor3dvEXT(const GLdouble* v);
GLAPI void GLAPIENTRY glSecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue);
GLAPI void GLAPIENTRY glSecondaryColor3fvEXT(const GLfloat* v);
GLAPI void GLAPIENTRY glSecondaryColor3iEXT(GLint red, GLint green, GLint blue);
GLAPI void GLAPIENTRY glSecondaryColor3ivEXT(const GLint* v);
GLAPI void GLAPIENTRY glSecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue);
GLAPI void GLAPIENTRY glSecondaryColor3svEXT(const GLshort* v);
GLAPI void GLAPIENTRY glSecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue);
GLAPI void GLAPIENTRY glSecondaryColor3ubvEXT(const GLubyte* v);
GLAPI void GLAPIENTRY glSecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue);
GLAPI void GLAPIENTRY glSecondaryColor3uivEXT(const GLuint* v);
GLAPI void GLAPIENTRY glSecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue);
GLAPI void GLAPIENTRY glSecondaryColor3usvEXT(const GLushort* v);
GLAPI void GLAPIENTRY glSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3BEXTPROC)(GLbyte red, GLbyte green, GLbyte blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3BVEXTPROC)(const GLbyte* v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3DEXTPROC)(GLdouble red, GLdouble green, GLdouble blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3DVEXTPROC)(const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3FEXTPROC)(GLfloat red, GLfloat green, GLfloat blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3FVEXTPROC)(const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3IEXTPROC)(GLint red, GLint green, GLint blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3IVEXTPROC)(const GLint* v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3SEXTPROC)(GLshort red, GLshort green, GLshort blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3SVEXTPROC)(const GLshort* v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3UBEXTPROC)(GLubyte red, GLubyte green, GLubyte blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3UBVEXTPROC)(const GLubyte* v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3UIEXTPROC)(GLuint red, GLuint green, GLuint blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3UIVEXTPROC)(const GLuint* v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3USEXTPROC)(GLushort red, GLushort green, GLushort blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3USVEXTPROC)(const GLushort* v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLORPOINTEREXTPROC)(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
#endif


#ifndef GL_EXT_semaphore
#define GL_EXT_semaphore 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGenSemaphoresEXT(GLsizei n, GLuint* semaphores);
GLAPI void GLAPIENTRY glDeleteSemaphoresEXT(GLsizei n, const GLuint* semaphores);
GLAPI GLboolean GLAPIENTRY glIsSemaphoreEXT(GLuint semaphore);
GLAPI void GLAPIENTRY glSemaphoreParameterui64vEXT(GLuint semaphore, GLenum pname, const GLuint64* params);
GLAPI void GLAPIENTRY glGetSemaphoreParameterui64vEXT(GLuint semaphore, GLenum pname, GLuint64* params);
GLAPI void GLAPIENTRY glWaitSemaphoreEXT(GLuint semaphore, GLuint numBufferBarriers, const GLuint* buffers, GLuint numTextureBarriers, const GLuint* textures, const GLenum* srcLayouts);
GLAPI void GLAPIENTRY glSignalSemaphoreEXT(GLuint semaphore, GLuint numBufferBarriers, const GLuint* buffers, GLuint numTextureBarriers, const GLuint* textures, const GLenum* dstLayouts);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGENSEMAPHORESEXTPROC)(GLsizei n, GLuint* semaphores);
typedef void (GLAPIENTRYP PFNGLDELETESEMAPHORESEXTPROC)(GLsizei n, const GLuint* semaphores);
typedef GLboolean (GLAPIENTRYP PFNGLISSEMAPHOREEXTPROC)(GLuint semaphore);
typedef void (GLAPIENTRYP PFNGLSEMAPHOREPARAMETERUI64VEXTPROC)(GLuint semaphore, GLenum pname, const GLuint64* params);
typedef void (GLAPIENTRYP PFNGLGETSEMAPHOREPARAMETERUI64VEXTPROC)(GLuint semaphore, GLenum pname, GLuint64* params);
typedef void (GLAPIENTRYP PFNGLWAITSEMAPHOREEXTPROC)(GLuint semaphore, GLuint numBufferBarriers, const GLuint* buffers, GLuint numTextureBarriers, const GLuint* textures, const GLenum* srcLayouts);
typedef void (GLAPIENTRYP PFNGLSIGNALSEMAPHOREEXTPROC)(GLuint semaphore, GLuint numBufferBarriers, const GLuint* buffers, GLuint numTextureBarriers, const GLuint* textures, const GLenum* dstLayouts);
#endif


#ifndef GL_EXT_semaphore_fd
#define GL_EXT_semaphore_fd 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glImportSemaphoreFdEXT(GLuint semaphore, GLenum handleType, GLint fd);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLIMPORTSEMAPHOREFDEXTPROC)(GLuint semaphore, GLenum handleType, GLint fd);
#endif


#ifndef GL_EXT_semaphore_win32
#define GL_EXT_semaphore_win32 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glImportSemaphoreWin32HandleEXT(GLuint semaphore, GLenum handleType, const void* handle);
GLAPI void GLAPIENTRY glImportSemaphoreWin32NameEXT(GLuint semaphore, GLenum handleType, const void* name);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLIMPORTSEMAPHOREWIN32HANDLEEXTPROC)(GLuint semaphore, GLenum handleType, const void* handle);
typedef void (GLAPIENTRYP PFNGLIMPORTSEMAPHOREWIN32NAMEEXTPROC)(GLuint semaphore, GLenum handleType, const void* name);
#endif


#ifndef GL_EXT_separate_shader_objects
#define GL_EXT_separate_shader_objects 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glActiveProgramEXT(GLuint program);
GLAPI void GLAPIENTRY glUseShaderProgramEXT(GLenum type, GLuint program);
GLAPI GLuint GLAPIENTRY glCreateShaderProgramEXT(GLenum type, const GLchar* string);
GLAPI void GLAPIENTRY glActiveShaderProgramEXT(GLuint pipeline, GLuint program);
GLAPI void GLAPIENTRY glBindProgramPipelineEXT(GLuint pipeline);
GLAPI GLuint GLAPIENTRY glCreateShaderProgramvEXT(GLenum type, GLsizei count, const GLchar** strings);
GLAPI void GLAPIENTRY glDeleteProgramPipelinesEXT(GLsizei n, const GLuint* pipelines);
GLAPI void GLAPIENTRY glGenProgramPipelinesEXT(GLsizei n, GLuint* pipelines);
GLAPI void GLAPIENTRY glGetProgramPipelineInfoLogEXT(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
GLAPI void GLAPIENTRY glGetProgramPipelineivEXT(GLuint pipeline, GLenum pname, GLint* params);
GLAPI GLboolean GLAPIENTRY glIsProgramPipelineEXT(GLuint pipeline);
GLAPI void GLAPIENTRY glUseProgramStagesEXT(GLuint pipeline, GLbitfield stages, GLuint program);
GLAPI void GLAPIENTRY glValidateProgramPipelineEXT(GLuint pipeline);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLACTIVEPROGRAMEXTPROC)(GLuint program);
typedef void (GLAPIENTRYP PFNGLUSESHADERPROGRAMEXTPROC)(GLenum type, GLuint program);
typedef GLuint (GLAPIENTRYP PFNGLCREATESHADERPROGRAMEXTPROC)(GLenum type, const GLchar* string);
typedef void (GLAPIENTRYP PFNGLACTIVESHADERPROGRAMEXTPROC)(GLuint pipeline, GLuint program);
typedef void (GLAPIENTRYP PFNGLBINDPROGRAMPIPELINEEXTPROC)(GLuint pipeline);
typedef GLuint (GLAPIENTRYP PFNGLCREATESHADERPROGRAMVEXTPROC)(GLenum type, GLsizei count, const GLchar** strings);
typedef void (GLAPIENTRYP PFNGLDELETEPROGRAMPIPELINESEXTPROC)(GLsizei n, const GLuint* pipelines);
typedef void (GLAPIENTRYP PFNGLGENPROGRAMPIPELINESEXTPROC)(GLsizei n, GLuint* pipelines);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGEXTPROC)(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMPIPELINEIVEXTPROC)(GLuint pipeline, GLenum pname, GLint* params);
typedef GLboolean (GLAPIENTRYP PFNGLISPROGRAMPIPELINEEXTPROC)(GLuint pipeline);
typedef void (GLAPIENTRYP PFNGLUSEPROGRAMSTAGESEXTPROC)(GLuint pipeline, GLbitfield stages, GLuint program);
typedef void (GLAPIENTRYP PFNGLVALIDATEPROGRAMPIPELINEEXTPROC)(GLuint pipeline);
#endif


#ifndef GL_EXT_shader_image_load_store
#define GL_EXT_shader_image_load_store 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBindImageTextureEXT(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format);
GLAPI void GLAPIENTRY glMemoryBarrierEXT(GLbitfield barriers);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBINDIMAGETEXTUREEXTPROC)(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format);
typedef void (GLAPIENTRYP PFNGLMEMORYBARRIEREXTPROC)(GLbitfield barriers);
#endif


#ifndef GL_EXT_sparse_texture
#define GL_EXT_sparse_texture 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTexPageCommitmentEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXPAGECOMMITMENTEXTPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#endif


#ifndef GL_EXT_stencil_two_side
#define GL_EXT_stencil_two_side 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glActiveStencilFaceEXT(GLenum face);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLACTIVESTENCILFACEEXTPROC)(GLenum face);
#endif


#ifndef GL_EXT_tessellation_shader
#define GL_EXT_tessellation_shader 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPatchParameteriEXT(GLenum pname, GLint value);
GLAPI void GLAPIENTRY glPatchParameterfvEXT(GLenum pname, const GLfloat* values);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPATCHPARAMETERIEXTPROC)(GLenum pname, GLint value);
typedef void (GLAPIENTRYP PFNGLPATCHPARAMETERFVEXTPROC)(GLenum pname, const GLfloat* values);
#endif


#ifndef GL_EXT_texture_border_clamp
#define GL_EXT_texture_border_clamp 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glSamplerParameterIivEXT(GLuint sampler, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glSamplerParameterIuivEXT(GLuint sampler, GLenum pname, const GLuint* params);
GLAPI void GLAPIENTRY glGetSamplerParameterIivEXT(GLuint sampler, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetSamplerParameterIuivEXT(GLuint sampler, GLenum pname, GLuint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLSAMPLERPARAMETERIIVEXTPROC)(GLuint sampler, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLSAMPLERPARAMETERIUIVEXTPROC)(GLuint sampler, GLenum pname, const GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETSAMPLERPARAMETERIIVEXTPROC)(GLuint sampler, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETSAMPLERPARAMETERIUIVEXTPROC)(GLuint sampler, GLenum pname, GLuint* params);
#endif


#ifndef GL_EXT_texture_buffer
#define GL_EXT_texture_buffer 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTexBufferRangeEXT(GLenum target, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXBUFFERRANGEEXTPROC)(GLenum target, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#endif


#ifndef GL_EXT_texture_buffer_object
#define GL_EXT_texture_buffer_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXBUFFEREXTPROC)(GLenum target, GLenum internalformat, GLuint buffer);
#endif


#ifndef GL_EXT_texture_integer
#define GL_EXT_texture_integer 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTexParameterIivEXT(GLenum target, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glTexParameterIuivEXT(GLenum target, GLenum pname, const GLuint* params);
GLAPI void GLAPIENTRY glGetTexParameterIivEXT(GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint* params);
GLAPI void GLAPIENTRY glClearColorIiEXT(GLint red, GLint green, GLint blue, GLint alpha);
GLAPI void GLAPIENTRY glClearColorIuiEXT(GLuint red, GLuint green, GLuint blue, GLuint alpha);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXPARAMETERIIVEXTPROC)(GLenum target, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLTEXPARAMETERIUIVEXTPROC)(GLenum target, GLenum pname, const GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETTEXPARAMETERIIVEXTPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETTEXPARAMETERIUIVEXTPROC)(GLenum target, GLenum pname, GLuint* params);
typedef void (GLAPIENTRYP PFNGLCLEARCOLORIIEXTPROC)(GLint red, GLint green, GLint blue, GLint alpha);
typedef void (GLAPIENTRYP PFNGLCLEARCOLORIUIEXTPROC)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
#endif


#ifndef GL_EXT_texture_object
#define GL_EXT_texture_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLboolean GLAPIENTRY glAreTexturesResidentEXT(GLsizei n, const GLuint* textures, GLboolean* residences);
GLAPI void GLAPIENTRY glBindTextureEXT(GLenum target, GLuint texture);
GLAPI void GLAPIENTRY glDeleteTexturesEXT(GLsizei n, const GLuint* textures);
GLAPI void GLAPIENTRY glGenTexturesEXT(GLsizei n, GLuint* textures);
GLAPI GLboolean GLAPIENTRY glIsTextureEXT(GLuint texture);
GLAPI void GLAPIENTRY glPrioritizeTexturesEXT(GLsizei n, const GLuint* textures, const GLclampf* priorities);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLboolean (GLAPIENTRYP PFNGLARETEXTURESRESIDENTEXTPROC)(GLsizei n, const GLuint* textures, GLboolean* residences);
typedef void (GLAPIENTRYP PFNGLBINDTEXTUREEXTPROC)(GLenum target, GLuint texture);
typedef void (GLAPIENTRYP PFNGLDELETETEXTURESEXTPROC)(GLsizei n, const GLuint* textures);
typedef void (GLAPIENTRYP PFNGLGENTEXTURESEXTPROC)(GLsizei n, GLuint* textures);
typedef GLboolean (GLAPIENTRYP PFNGLISTEXTUREEXTPROC)(GLuint texture);
typedef void (GLAPIENTRYP PFNGLPRIORITIZETEXTURESEXTPROC)(GLsizei n, const GLuint* textures, const GLclampf* priorities);
#endif


#ifndef GL_EXT_texture_storage
#define GL_EXT_texture_storage 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTexStorage1DEXT(GLenum target, GLsizei levels, GLint internalformat, GLsizei width);
GLAPI void GLAPIENTRY glTexStorage2DEXT(GLenum target, GLsizei levels, GLint internalformat, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glTexStorage3DEXT(GLenum target, GLsizei levels, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void GLAPIENTRY glTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLint internalformat, GLsizei width);
GLAPI void GLAPIENTRY glTextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLint internalformat, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glTextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXSTORAGE1DEXTPROC)(GLenum target, GLsizei levels, GLint internalformat, GLsizei width);
typedef void (GLAPIENTRYP PFNGLTEXSTORAGE2DEXTPROC)(GLenum target, GLsizei levels, GLint internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLTEXSTORAGE3DEXTPROC)(GLenum target, GLsizei levels, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (GLAPIENTRYP PFNGLTEXTURESTORAGE1DEXTPROC)(GLuint texture, GLenum target, GLsizei levels, GLint internalformat, GLsizei width);
typedef void (GLAPIENTRYP PFNGLTEXTURESTORAGE2DEXTPROC)(GLuint texture, GLenum target, GLsizei levels, GLint internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLTEXTURESTORAGE3DEXTPROC)(GLuint texture, GLenum target, GLsizei levels, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth);
#endif


#ifndef GL_EXT_texture_view
#define GL_EXT_texture_view 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTextureViewEXT(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXTUREVIEWEXTPROC)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
#endif


#ifndef GL_EXT_texture3D
#define GL_EXT_texture3D 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glCopyTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXIMAGE3DEXTPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLTEXSUBIMAGE3DEXTPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLCOPYTEXSUBIMAGE3DEXTPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#endif


#ifndef GL_EXT_timer_query
#define GL_EXT_timer_query 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64EXT* params);
GLAPI void GLAPIENTRY glGetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64EXT* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTI64VEXTPROC)(GLuint id, GLenum pname, GLint64EXT* params);
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTUI64VEXTPROC)(GLuint id, GLenum pname, GLuint64EXT* params);
#endif


#ifndef GL_EXT_transform_feedback2
#define GL_EXT_transform_feedback2 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGenTransformFeedbacksEXT(GLsizei n, GLuint* ids);
GLAPI void GLAPIENTRY glDeleteTransformFeedbacksEXT(GLsizei n, const GLuint* ids);
GLAPI void GLAPIENTRY glBindTransformFeedbackEXT(GLenum target, GLuint id);
GLAPI GLboolean GLAPIENTRY glIsTransformFeedbackEXT(GLuint id);
GLAPI void GLAPIENTRY glPauseTransformFeedbackEXT();
GLAPI void GLAPIENTRY glResumeTransformFeedbackEXT();
GLAPI void GLAPIENTRY glDrawTransformFeedbackEXT(GLenum mode, GLuint name);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGENTRANSFORMFEEDBACKSEXTPROC)(GLsizei n, GLuint* ids);
typedef void (GLAPIENTRYP PFNGLDELETETRANSFORMFEEDBACKSEXTPROC)(GLsizei n, const GLuint* ids);
typedef void (GLAPIENTRYP PFNGLBINDTRANSFORMFEEDBACKEXTPROC)(GLenum target, GLuint id);
typedef GLboolean (GLAPIENTRYP PFNGLISTRANSFORMFEEDBACKEXTPROC)(GLuint id);
typedef void (GLAPIENTRYP PFNGLPAUSETRANSFORMFEEDBACKEXTPROC)();
typedef void (GLAPIENTRYP PFNGLRESUMETRANSFORMFEEDBACKEXTPROC)();
typedef void (GLAPIENTRYP PFNGLDRAWTRANSFORMFEEDBACKEXTPROC)(GLenum mode, GLuint name);
#endif


#ifndef GL_EXT_vertex_array
#define GL_EXT_vertex_array 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glArrayElementEXT(GLint i);
GLAPI void GLAPIENTRY glColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
GLAPI void GLAPIENTRY glEdgeFlagPointerEXT(GLsizei stride, GLsizei count, const GLboolean* pointer);
GLAPI void GLAPIENTRY glGetPointervEXT(GLenum pname, GLvoid** params);
GLAPI void GLAPIENTRY glIndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
GLAPI void GLAPIENTRY glNormalPointerEXT(GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
GLAPI void GLAPIENTRY glTexCoordPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
GLAPI void GLAPIENTRY glVertexPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
GLAPI void GLAPIENTRY glDrawArraysEXT(GLenum mode, GLint first, GLsizei count);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLARRAYELEMENTEXTPROC)(GLint i);
typedef void (GLAPIENTRYP PFNGLCOLORPOINTEREXTPROC)(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLEDGEFLAGPOINTEREXTPROC)(GLsizei stride, GLsizei count, const GLboolean* pointer);
typedef void (GLAPIENTRYP PFNGLGETPOINTERVEXTPROC)(GLenum pname, GLvoid** params);
typedef void (GLAPIENTRYP PFNGLINDEXPOINTEREXTPROC)(GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLNORMALPOINTEREXTPROC)(GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLTEXCOORDPOINTEREXTPROC)(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLVERTEXPOINTEREXTPROC)(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLDRAWARRAYSEXTPROC)(GLenum mode, GLint first, GLsizei count);
#endif


#ifndef GL_EXT_vertex_attrib_64bit
#define GL_EXT_vertex_attrib_64bit 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glVertexAttribL1dEXT(GLuint index, GLdouble x);
GLAPI void GLAPIENTRY glVertexAttribL2dEXT(GLuint index, GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glVertexAttribL3dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glVertexAttribL4dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glVertexAttribL1dvEXT(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttribL2dvEXT(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttribL3dvEXT(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttribL4dvEXT(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttribLPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
GLAPI void GLAPIENTRY glVertexArrayVertexAttribLOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLAPI void GLAPIENTRY glGetVertexAttribLdvEXT(GLuint index, GLenum pname, GLdouble* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL1DEXTPROC)(GLuint index, GLdouble x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL2DEXTPROC)(GLuint index, GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL3DEXTPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL4DEXTPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL1DVEXTPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL2DVEXTPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL3DVEXTPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL4DVEXTPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBLPOINTEREXTPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBLDVEXTPROC)(GLuint index, GLenum pname, GLdouble* params);
#endif


#ifndef GL_EXT_ycbcr_422
#define GL_EXT_ycbcr_422 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glLoadTransformEXT(GLenum transform);
GLAPI void GLAPIENTRY glMultTransformEXT(GLenum transform);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLLOADTRANSFORMEXTPROC)(GLenum transform);
typedef void (GLAPIENTRYP PFNGLMULTTRANSFORMEXTPROC)(GLenum transform);
#endif


#ifndef GL_GL_MASK_OVR_multiview
#define GL_GL_MASK_OVR_multiview 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glNamedFramebufferTextureMultiviewOVR(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
#endif


#ifndef GL_KHR_blend_equation_advanced
#define GL_KHR_blend_equation_advanced 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlendBarrierKHR();
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLENDBARRIERKHRPROC)();
#endif


#ifndef GL_KHR_debug
#define GL_KHR_debug 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPushDebugGroupKHR(GLenum source, GLuint id, GLsizei length, const GLchar* message);
GLAPI void GLAPIENTRY glPopDebugGroupKHR();
GLAPI void GLAPIENTRY glObjectLabelKHR(GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
GLAPI void GLAPIENTRY glObjectPtrLabelKHR(GLvoid* ptr, GLsizei length, const GLchar* label);
GLAPI void GLAPIENTRY glGetObjectLabelKHR(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
GLAPI void GLAPIENTRY glGetObjectPtrLabelKHR(GLvoid* ptr, GLsizei bufSize, GLsizei* length, GLchar* label);
GLAPI void GLAPIENTRY glDebugMessageControlKHR(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
GLAPI void GLAPIENTRY glDebugMessageInsertKHR(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
GLAPI void GLAPIENTRY glDebugMessageCallbackKHR(GLDEBUGPROC callback, const void* userParam);
GLAPI GLuint GLAPIENTRY glGetDebugMessageLogKHR(GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
GLAPI void GLAPIENTRY glGetPointervKHR(GLenum pname, GLvoid** params);
GLAPI void GLAPIENTRY glPushDebugGroupOES(GLenum source, GLuint id, GLsizei length, const GLchar* message);
GLAPI void GLAPIENTRY glPopDebugGroupOES();
GLAPI void GLAPIENTRY glObjectLabelOES(GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
GLAPI void GLAPIENTRY glObjectPtrLabelOES(GLvoid* ptr, GLsizei length, const GLchar* label);
GLAPI void GLAPIENTRY glGetObjectLabelOES(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
GLAPI void GLAPIENTRY glGetObjectPtrLabelOES(GLvoid* ptr, GLsizei bufSize, GLsizei* length, GLchar* label);
GLAPI void GLAPIENTRY glDebugMessageControlOES(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
GLAPI void GLAPIENTRY glDebugMessageInsertOES(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
GLAPI void GLAPIENTRY glDebugMessageCallbackOES(GLDEBUGPROC callback, const void* userParam);
GLAPI GLuint GLAPIENTRY glGetDebugMessageLogOES(GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
GLAPI void GLAPIENTRY glGetPointervOES(GLenum pname, GLvoid** params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPUSHDEBUGGROUPKHRPROC)(GLenum source, GLuint id, GLsizei length, const GLchar* message);
typedef void (GLAPIENTRYP PFNGLPOPDEBUGGROUPKHRPROC)();
typedef void (GLAPIENTRYP PFNGLOBJECTLABELKHRPROC)(GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
typedef void (GLAPIENTRYP PFNGLOBJECTPTRLABELKHRPROC)(GLvoid* ptr, GLsizei length, const GLchar* label);
typedef void (GLAPIENTRYP PFNGLGETOBJECTLABELKHRPROC)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
typedef void (GLAPIENTRYP PFNGLGETOBJECTPTRLABELKHRPROC)(GLvoid* ptr, GLsizei bufSize, GLsizei* length, GLchar* label);
typedef void (GLAPIENTRYP PFNGLDEBUGMESSAGECONTROLKHRPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
typedef void (GLAPIENTRYP PFNGLDEBUGMESSAGEINSERTKHRPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
typedef void (GLAPIENTRYP PFNGLDEBUGMESSAGECALLBACKKHRPROC)(GLDEBUGPROC callback, const void* userParam);
typedef GLuint (GLAPIENTRYP PFNGLGETDEBUGMESSAGELOGKHRPROC)(GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
typedef void (GLAPIENTRYP PFNGLGETPOINTERVKHRPROC)(GLenum pname, GLvoid** params);
typedef void (GLAPIENTRYP PFNGLPUSHDEBUGGROUPOESPROC)(GLenum source, GLuint id, GLsizei length, const GLchar* message);
typedef void (GLAPIENTRYP PFNGLPOPDEBUGGROUPOESPROC)();
typedef void (GLAPIENTRYP PFNGLOBJECTLABELOESPROC)(GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
typedef void (GLAPIENTRYP PFNGLOBJECTPTRLABELOESPROC)(GLvoid* ptr, GLsizei length, const GLchar* label);
typedef void (GLAPIENTRYP PFNGLGETOBJECTLABELOESPROC)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
typedef void (GLAPIENTRYP PFNGLGETOBJECTPTRLABELOESPROC)(GLvoid* ptr, GLsizei bufSize, GLsizei* length, GLchar* label);
typedef void (GLAPIENTRYP PFNGLDEBUGMESSAGECONTROLOESPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
typedef void (GLAPIENTRYP PFNGLDEBUGMESSAGEINSERTOESPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
typedef void (GLAPIENTRYP PFNGLDEBUGMESSAGECALLBACKOESPROC)(GLDEBUGPROC callback, const void* userParam);
typedef GLuint (GLAPIENTRYP PFNGLGETDEBUGMESSAGELOGOESPROC)(GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
typedef void (GLAPIENTRYP PFNGLGETPOINTERVOESPROC)(GLenum pname, GLvoid** params);
#endif


#ifndef GL_KHR_robustness
#define GL_KHR_robustness 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLenum GLAPIENTRY glGetGraphicsResetStatusKHR();
GLAPI void GLAPIENTRY glReadnPixelsKHR(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
GLAPI void GLAPIENTRY glGetnUniformfvKHR(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
GLAPI void GLAPIENTRY glGetnUniformivKHR(GLuint program, GLint location, GLsizei bufSize, GLint* params);
GLAPI void GLAPIENTRY glGetnUniformuivKHR(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLenum (GLAPIENTRYP PFNGLGETGRAPHICSRESETSTATUSKHRPROC)();
typedef void (GLAPIENTRYP PFNGLREADNPIXELSKHRPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLGETNUNIFORMFVKHRPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETNUNIFORMIVKHRPROC)(GLuint program, GLint location, GLsizei bufSize, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETNUNIFORMUIVKHRPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
#endif


#ifndef GL_NV_bindless_multi_draw_indirect
#define GL_NV_bindless_multi_draw_indirect 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glMultiDrawArraysIndirectBindlessNV(GLenum mode, const GLvoid* indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
GLAPI void GLAPIENTRY glMultiDrawElementsIndirectBindlessNV(GLenum mode, GLenum type, const GLvoid* indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC)(GLenum mode, const GLvoid* indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC)(GLenum mode, GLenum type, const GLvoid* indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
#endif


#ifndef GL_NV_bindless_multi_draw_indirect_count
#define GL_NV_bindless_multi_draw_indirect_count 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glMultiDrawArraysIndirectBindlessCountNV(GLenum mode, const GLvoid* indirect, GLintptr drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
GLAPI void GLAPIENTRY glMultiDrawElementsIndirectBindlessCountNV(GLenum mode, GLenum type, const GLvoid* indirect, GLintptr drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC)(GLenum mode, const GLvoid* indirect, GLintptr drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC)(GLenum mode, GLenum type, const GLvoid* indirect, GLintptr drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
#endif


#ifndef GL_NV_bindless_texture
#define GL_NV_bindless_texture 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLuint64 GLAPIENTRY glGetTextureHandleNV(GLuint texture);
GLAPI GLuint64 GLAPIENTRY glGetTextureSamplerHandleNV(GLuint texture, GLuint sampler);
GLAPI void GLAPIENTRY glMakeTextureHandleResidentNV(GLuint64 handle);
GLAPI void GLAPIENTRY glMakeTextureHandleNonResidentNV(GLuint64 handle);
GLAPI GLuint64 GLAPIENTRY glGetImageHandleNV(GLuint texture, GLint level, GLboolean layered, GLint layer, GLint format);
GLAPI void GLAPIENTRY glMakeImageHandleResidentNV(GLuint64 handle, GLenum access);
GLAPI void GLAPIENTRY glMakeImageHandleNonResidentNV(GLuint64 handle);
GLAPI GLboolean GLAPIENTRY glIsTextureHandleResidentNV(GLuint64 handle);
GLAPI GLboolean GLAPIENTRY glIsImageHandleResidentNV(GLuint64 handle);
GLAPI void GLAPIENTRY glUniformHandleui64NV(GLint location, GLuint64EXT v0);
GLAPI void GLAPIENTRY glUniformHandleui64vNV(GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void GLAPIENTRY glProgramUniformHandleui64NV(GLuint program, GLint location, GLuint64EXT v0);
GLAPI void GLAPIENTRY glProgramUniformHandleui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLuint64 (GLAPIENTRYP PFNGLGETTEXTUREHANDLENVPROC)(GLuint texture);
typedef GLuint64 (GLAPIENTRYP PFNGLGETTEXTURESAMPLERHANDLENVPROC)(GLuint texture, GLuint sampler);
typedef void (GLAPIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTNVPROC)(GLuint64 handle);
typedef void (GLAPIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC)(GLuint64 handle);
typedef GLuint64 (GLAPIENTRYP PFNGLGETIMAGEHANDLENVPROC)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLint format);
typedef void (GLAPIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTNVPROC)(GLuint64 handle, GLenum access);
typedef void (GLAPIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC)(GLuint64 handle);
typedef GLboolean (GLAPIENTRYP PFNGLISTEXTUREHANDLERESIDENTNVPROC)(GLuint64 handle);
typedef GLboolean (GLAPIENTRYP PFNGLISIMAGEHANDLERESIDENTNVPROC)(GLuint64 handle);
typedef void (GLAPIENTRYP PFNGLUNIFORMHANDLEUI64NVPROC)(GLint location, GLuint64EXT v0);
typedef void (GLAPIENTRYP PFNGLUNIFORMHANDLEUI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC)(GLuint program, GLint location, GLuint64EXT v0);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
#endif


#ifndef GL_NV_blend_equation_advanced
#define GL_NV_blend_equation_advanced 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlendParameteriNV(GLenum pname, GLint value);
GLAPI void GLAPIENTRY glBlendBarrierNV();
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLENDPARAMETERINVPROC)(GLenum pname, GLint value);
typedef void (GLAPIENTRYP PFNGLBLENDBARRIERNVPROC)();
#endif


#ifndef GL_NV_command_list
#define GL_NV_command_list 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLuint GLAPIENTRY glGetCommandHeaderNV(GLenum tokenID, GLuint size);
GLAPI GLushort GLAPIENTRY glGetStageIndexNV(GLenum shaderType);
GLAPI void GLAPIENTRY glCreateStatesNV(GLsizei n, GLuint* states);
GLAPI void GLAPIENTRY glDeleteStatesNV(GLsizei n, const GLuint* states);
GLAPI GLboolean GLAPIENTRY glIsStateNV(GLuint state);
GLAPI void GLAPIENTRY glCreateCommandListsNV(GLsizei n, GLuint* lists);
GLAPI void GLAPIENTRY glDeleteCommandListsNV(GLsizei n, const GLuint* lists);
GLAPI GLboolean GLAPIENTRY glIsCommandListNV(GLuint list);
GLAPI void GLAPIENTRY glStatePropertiesDynamicNV(GLuint state, GLsizei count, const GLint* params);
GLAPI void GLAPIENTRY glStateCaptureNV(GLuint id, GLenum mode);
GLAPI void GLAPIENTRY glDrawCommandsNV(GLenum mode, GLuint buffer, const GLintptr* indirects, const GLsizei* sizes, GLuint count);
GLAPI void GLAPIENTRY glDrawCommandsAddressNV(GLenum mode, const GLuint64* indirects, const GLsizei* sizes, GLuint count);
GLAPI void GLAPIENTRY glDrawCommandsStatesNV(GLuint buffer, const GLintptr* indirects, const GLsizei* sizes, const GLuint* states, const GLuint* fbos, GLuint count);
GLAPI void GLAPIENTRY glDrawCommandsStatesAddressNV(const GLuint64* indirects, const GLsizei* sizes, const GLuint* states, const GLuint* fbos, GLuint count);
GLAPI void GLAPIENTRY glListDrawCommandsStatesClientNV(GLuint list, GLuint segment, const GLvoid** indirects, const GLsizei* sizes, const GLuint* states, const GLuint* fbos, GLuint count);
GLAPI void GLAPIENTRY glCommandListSegmentsNV(GLuint list, GLuint segments);
GLAPI void GLAPIENTRY glCompileCommandListNV(GLuint list);
GLAPI void GLAPIENTRY glCallCommandListNV(GLuint list);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLuint (GLAPIENTRYP PFNGLGETCOMMANDHEADERNVPROC)(GLenum tokenID, GLuint size);
typedef GLushort (GLAPIENTRYP PFNGLGETSTAGEINDEXNVPROC)(GLenum shaderType);
typedef void (GLAPIENTRYP PFNGLCREATESTATESNVPROC)(GLsizei n, GLuint* states);
typedef void (GLAPIENTRYP PFNGLDELETESTATESNVPROC)(GLsizei n, const GLuint* states);
typedef GLboolean (GLAPIENTRYP PFNGLISSTATENVPROC)(GLuint state);
typedef void (GLAPIENTRYP PFNGLCREATECOMMANDLISTSNVPROC)(GLsizei n, GLuint* lists);
typedef void (GLAPIENTRYP PFNGLDELETECOMMANDLISTSNVPROC)(GLsizei n, const GLuint* lists);
typedef GLboolean (GLAPIENTRYP PFNGLISCOMMANDLISTNVPROC)(GLuint list);
typedef void (GLAPIENTRYP PFNGLSTATEPROPERTIESDYNAMICNVPROC)(GLuint state, GLsizei count, const GLint* params);
typedef void (GLAPIENTRYP PFNGLSTATECAPTURENVPROC)(GLuint id, GLenum mode);
typedef void (GLAPIENTRYP PFNGLDRAWCOMMANDSNVPROC)(GLenum mode, GLuint buffer, const GLintptr* indirects, const GLsizei* sizes, GLuint count);
typedef void (GLAPIENTRYP PFNGLDRAWCOMMANDSADDRESSNVPROC)(GLenum mode, const GLuint64* indirects, const GLsizei* sizes, GLuint count);
typedef void (GLAPIENTRYP PFNGLDRAWCOMMANDSSTATESNVPROC)(GLuint buffer, const GLintptr* indirects, const GLsizei* sizes, const GLuint* states, const GLuint* fbos, GLuint count);
typedef void (GLAPIENTRYP PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC)(const GLuint64* indirects, const GLsizei* sizes, const GLuint* states, const GLuint* fbos, GLuint count);
typedef void (GLAPIENTRYP PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC)(GLuint list, GLuint segment, const GLvoid** indirects, const GLsizei* sizes, const GLuint* states, const GLuint* fbos, GLuint count);
typedef void (GLAPIENTRYP PFNGLCOMMANDLISTSEGMENTSNVPROC)(GLuint list, GLuint segments);
typedef void (GLAPIENTRYP PFNGLCOMPILECOMMANDLISTNVPROC)(GLuint list);
typedef void (GLAPIENTRYP PFNGLCALLCOMMANDLISTNVPROC)(GLuint list);
#endif


#ifndef GL_NV_compute_stream
#define GL_NV_compute_stream 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLuint GLAPIENTRY glCreateStreamNV(GLenum target);
GLAPI void GLAPIENTRY glDeleteStreamNV(GLuint stream);
GLAPI void GLAPIENTRY glComputeStreamNV(GLuint stream);
GLAPI GLsync GLAPIENTRY glFenceSyncStreamNV(GLuint stream, GLenum condition, GLbitfield flags);
GLAPI void GLAPIENTRY glWaitSyncStreamNV(GLuint stream, GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI void GLAPIENTRY glMemoryBarrierStreamNV(GLuint stream, GLbitfield barriers);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLuint (GLAPIENTRYP PFNGLCREATESTREAMNVPROC)(GLenum target);
typedef void (GLAPIENTRYP PFNGLDELETESTREAMNVPROC)(GLuint stream);
typedef void (GLAPIENTRYP PFNGLCOMPUTESTREAMNVPROC)(GLuint stream);
typedef GLsync (GLAPIENTRYP PFNGLFENCESYNCSTREAMNVPROC)(GLuint stream, GLenum condition, GLbitfield flags);
typedef void (GLAPIENTRYP PFNGLWAITSYNCSTREAMNVPROC)(GLuint stream, GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (GLAPIENTRYP PFNGLMEMORYBARRIERSTREAMNVPROC)(GLuint stream, GLbitfield barriers);
#endif


#ifndef GL_NV_conditional_render
#define GL_NV_conditional_render 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBeginConditionalRenderNV(GLuint id, GLenum mode);
GLAPI void GLAPIENTRY glEndConditionalRenderNV();
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBEGINCONDITIONALRENDERNVPROC)(GLuint id, GLenum mode);
typedef void (GLAPIENTRYP PFNGLENDCONDITIONALRENDERNVPROC)();
#endif


#ifndef GL_NV_conservative_raster
#define GL_NV_conservative_raster 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glSubpixelPrecisionBiasNV(GLuint xbits, GLuint ybits);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLSUBPIXELPRECISIONBIASNVPROC)(GLuint xbits, GLuint ybits);
#endif


#ifndef GL_NV_copy_buffer
#define GL_NV_copy_buffer 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glCopyBufferSubDataNV(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOPYBUFFERSUBDATANVPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#endif


#ifndef GL_NV_copy_image
#define GL_NV_copy_image 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glCopyImageSubDataNV(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOPYIMAGESUBDATANVPROC)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
#endif


#ifndef GL_NV_depth_buffer_float
#define GL_NV_depth_buffer_float 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDepthRangedNV(GLdouble zNear, GLdouble zFar);
GLAPI void GLAPIENTRY glClearDepthdNV(GLdouble depth);
GLAPI void GLAPIENTRY glDepthBoundsdNV(GLdouble zmin, GLdouble zmax);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDEPTHRANGEDNVPROC)(GLdouble zNear, GLdouble zFar);
typedef void (GLAPIENTRYP PFNGLCLEARDEPTHDNVPROC)(GLdouble depth);
typedef void (GLAPIENTRYP PFNGLDEPTHBOUNDSDNVPROC)(GLdouble zmin, GLdouble zmax);
#endif


#ifndef GL_NV_draw_buffers
#define GL_NV_draw_buffers 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawBuffersNV(GLsizei n, const GLenum* bufs);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWBUFFERSNVPROC)(GLsizei n, const GLenum* bufs);
#endif


#ifndef GL_NV_draw_instanced
#define GL_NV_draw_instanced 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawArraysInstancedNV(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
GLAPI void GLAPIENTRY glDrawElementsInstancedNV(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei primcount);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWARRAYSINSTANCEDNVPROC)(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSINSTANCEDNVPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei primcount);
#endif


#ifndef GL_NV_draw_mesh
#define GL_NV_draw_mesh 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawMeshNV(GLenum mode, GLsizei count, GLenum type, GLsizei stride, const GLvoid* indicesTexCoord, const GLvoid* indicesNormal, const GLvoid* indicesVertex);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWMESHNVPROC)(GLenum mode, GLsizei count, GLenum type, GLsizei stride, const GLvoid* indicesTexCoord, const GLvoid* indicesNormal, const GLvoid* indicesVertex);
#endif


#ifndef GL_NV_draw_texture
#define GL_NV_draw_texture 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawTextureNV(GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWTEXTURENVPROC)(GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
#endif


#ifndef GL_NV_draw_vulkan_image
#define GL_NV_draw_vulkan_image 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLVULKANPROCNV GLAPIENTRY glGetVkProcAddrNV(const GLchar* name);
GLAPI void GLAPIENTRY glWaitVkSemaphoreNV(GLuint64 vkSemaphore);
GLAPI void GLAPIENTRY glSignalVkSemaphoreNV(GLuint64 vkSemaphore);
GLAPI void GLAPIENTRY glSignalVkFenceNV(GLuint64 vkFence);
GLAPI void GLAPIENTRY glDrawVkImageNV(GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLVULKANPROCNV (GLAPIENTRYP PFNGLGETVKPROCADDRNVPROC)(const GLchar* name);
typedef void (GLAPIENTRYP PFNGLWAITVKSEMAPHORENVPROC)(GLuint64 vkSemaphore);
typedef void (GLAPIENTRYP PFNGLSIGNALVKSEMAPHORENVPROC)(GLuint64 vkSemaphore);
typedef void (GLAPIENTRYP PFNGLSIGNALVKFENCENVPROC)(GLuint64 vkFence);
typedef void (GLAPIENTRYP PFNGLDRAWVKIMAGENVPROC)(GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
#endif


#ifndef GL_NV_ES1_1_compatibility
#define GL_NV_ES1_1_compatibility 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glAlphaFuncx(GLenum func, GLclampx ref);
GLAPI void GLAPIENTRY glClearColorx(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha);
GLAPI void GLAPIENTRY glClearDepthx(GLclampx depth);
GLAPI void GLAPIENTRY glClipPlanef(GLenum plane, const GLfloat* equation);
GLAPI void GLAPIENTRY glClipPlanex(GLenum plane, const GLfixed* equation);
GLAPI void GLAPIENTRY glColor3x(GLfixed red, GLfixed green, GLfixed blue);
GLAPI void GLAPIENTRY glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
GLAPI void GLAPIENTRY glDepthRangex(GLclampx zNear, GLclampx zFar);
GLAPI void GLAPIENTRY glFogx(GLenum pname, GLfixed param);
GLAPI void GLAPIENTRY glFogxv(GLenum pname, const GLfixed* params);
GLAPI void GLAPIENTRY glFrustumf(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
GLAPI void GLAPIENTRY glFrustumx(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar);
GLAPI void GLAPIENTRY glGetClipPlanef(GLenum plane, GLfloat* eqn);
GLAPI void GLAPIENTRY glGetClipPlanex(GLenum plane, GLfixed* eqn);
GLAPI void GLAPIENTRY glGetFixedv(GLenum pname, GLfixed* params);
GLAPI void GLAPIENTRY glGetLightxv(GLenum light, GLenum pname, GLfixed* params);
GLAPI void GLAPIENTRY glGetMaterialxv(GLenum face, GLenum pname, GLfixed* params);
GLAPI void GLAPIENTRY glGetTexEnvxv(GLenum env, GLenum pname, GLfixed* params);
GLAPI void GLAPIENTRY glGetTexParameterxv(GLenum target, GLenum pname, GLfixed* params);
GLAPI void GLAPIENTRY glLightModelx(GLenum pname, GLfixed param);
GLAPI void GLAPIENTRY glLightModelxv(GLenum pname, const GLfixed* params);
GLAPI void GLAPIENTRY glLightx(GLenum light, GLenum pname, GLfixed param);
GLAPI void GLAPIENTRY glLightxv(GLenum light, GLenum pname, const GLfixed* params);
GLAPI void GLAPIENTRY glLineWidthx(GLfixed width);
GLAPI void GLAPIENTRY glLoadMatrixx(const GLfixed* m);
GLAPI void GLAPIENTRY glMaterialx(GLenum face, GLenum pname, GLfixed param);
GLAPI void GLAPIENTRY glMaterialxv(GLenum face, GLenum pname, const GLfixed* params);
GLAPI void GLAPIENTRY glMultiTexCoord1x(GLenum target, GLfixed s);
GLAPI void GLAPIENTRY glMultiTexCoord1xv(GLenum target, const GLfixed* v);
GLAPI void GLAPIENTRY glMultiTexCoord2x(GLenum target, GLfixed s, GLfixed t);
GLAPI void GLAPIENTRY glMultiTexCoord2xv(GLenum target, const GLfixed* v);
GLAPI void GLAPIENTRY glMultiTexCoord3x(GLenum target, GLfixed s, GLfixed t, GLfixed r);
GLAPI void GLAPIENTRY glMultiTexCoord3xv(GLenum target, const GLfixed* v);
GLAPI void GLAPIENTRY glMultiTexCoord4x(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
GLAPI void GLAPIENTRY glMultiTexCoord4xv(GLenum target, const GLfixed* v);
GLAPI void GLAPIENTRY glMultMatrixx(const GLfixed* m);
GLAPI void GLAPIENTRY glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz);
GLAPI void GLAPIENTRY glOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
GLAPI void GLAPIENTRY glOrthox(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar);
GLAPI void GLAPIENTRY glPointParameterx(GLenum pname, GLfixed param);
GLAPI void GLAPIENTRY glPointParameterxv(GLenum pname, const GLfixed* params);
GLAPI void GLAPIENTRY glPointSizex(GLfixed size);
GLAPI void GLAPIENTRY glPolygonOffsetx(GLfixed factor, GLfixed units);
GLAPI void GLAPIENTRY glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
GLAPI void GLAPIENTRY glSampleCoveragex(GLclampx value, GLboolean invert);
GLAPI void GLAPIENTRY glScalex(GLfixed x, GLfixed y, GLfixed z);
GLAPI void GLAPIENTRY glTexEnvx(GLenum target, GLenum pname, GLfixed param);
GLAPI void GLAPIENTRY glTexEnvxv(GLenum target, GLenum pname, const GLfixed* params);
GLAPI void GLAPIENTRY glTexParameterx(GLenum target, GLenum pname, GLfixed param);
GLAPI void GLAPIENTRY glTexParameterxv(GLenum target, GLenum pname, const GLfixed* params);
GLAPI void GLAPIENTRY glTranslatex(GLfixed x, GLfixed y, GLfixed z);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLALPHAFUNCXPROC)(GLenum func, GLclampx ref);
typedef void (GLAPIENTRYP PFNGLCLEARCOLORXPROC)(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha);
typedef void (GLAPIENTRYP PFNGLCLEARDEPTHXPROC)(GLclampx depth);
typedef void (GLAPIENTRYP PFNGLCLIPPLANEFPROC)(GLenum plane, const GLfloat* equation);
typedef void (GLAPIENTRYP PFNGLCLIPPLANEXPROC)(GLenum plane, const GLfixed* equation);
typedef void (GLAPIENTRYP PFNGLCOLOR3XPROC)(GLfixed red, GLfixed green, GLfixed blue);
typedef void (GLAPIENTRYP PFNGLCOLOR4XPROC)(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
typedef void (GLAPIENTRYP PFNGLDEPTHRANGEXPROC)(GLclampx zNear, GLclampx zFar);
typedef void (GLAPIENTRYP PFNGLFOGXPROC)(GLenum pname, GLfixed param);
typedef void (GLAPIENTRYP PFNGLFOGXVPROC)(GLenum pname, const GLfixed* params);
typedef void (GLAPIENTRYP PFNGLFRUSTUMFPROC)(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
typedef void (GLAPIENTRYP PFNGLFRUSTUMXPROC)(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar);
typedef void (GLAPIENTRYP PFNGLGETCLIPPLANEFPROC)(GLenum plane, GLfloat* eqn);
typedef void (GLAPIENTRYP PFNGLGETCLIPPLANEXPROC)(GLenum plane, GLfixed* eqn);
typedef void (GLAPIENTRYP PFNGLGETFIXEDVPROC)(GLenum pname, GLfixed* params);
typedef void (GLAPIENTRYP PFNGLGETLIGHTXVPROC)(GLenum light, GLenum pname, GLfixed* params);
typedef void (GLAPIENTRYP PFNGLGETMATERIALXVPROC)(GLenum face, GLenum pname, GLfixed* params);
typedef void (GLAPIENTRYP PFNGLGETTEXENVXVPROC)(GLenum env, GLenum pname, GLfixed* params);
typedef void (GLAPIENTRYP PFNGLGETTEXPARAMETERXVPROC)(GLenum target, GLenum pname, GLfixed* params);
typedef void (GLAPIENTRYP PFNGLLIGHTMODELXPROC)(GLenum pname, GLfixed param);
typedef void (GLAPIENTRYP PFNGLLIGHTMODELXVPROC)(GLenum pname, const GLfixed* params);
typedef void (GLAPIENTRYP PFNGLLIGHTXPROC)(GLenum light, GLenum pname, GLfixed param);
typedef void (GLAPIENTRYP PFNGLLIGHTXVPROC)(GLenum light, GLenum pname, const GLfixed* params);
typedef void (GLAPIENTRYP PFNGLLINEWIDTHXPROC)(GLfixed width);
typedef void (GLAPIENTRYP PFNGLLOADMATRIXXPROC)(const GLfixed* m);
typedef void (GLAPIENTRYP PFNGLMATERIALXPROC)(GLenum face, GLenum pname, GLfixed param);
typedef void (GLAPIENTRYP PFNGLMATERIALXVPROC)(GLenum face, GLenum pname, const GLfixed* params);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1XPROC)(GLenum target, GLfixed s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1XVPROC)(GLenum target, const GLfixed* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2XPROC)(GLenum target, GLfixed s, GLfixed t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2XVPROC)(GLenum target, const GLfixed* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3XPROC)(GLenum target, GLfixed s, GLfixed t, GLfixed r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3XVPROC)(GLenum target, const GLfixed* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4XPROC)(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4XVPROC)(GLenum target, const GLfixed* v);
typedef void (GLAPIENTRYP PFNGLMULTMATRIXXPROC)(const GLfixed* m);
typedef void (GLAPIENTRYP PFNGLNORMAL3XPROC)(GLfixed nx, GLfixed ny, GLfixed nz);
typedef void (GLAPIENTRYP PFNGLORTHOFPROC)(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
typedef void (GLAPIENTRYP PFNGLORTHOXPROC)(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar);
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERXPROC)(GLenum pname, GLfixed param);
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERXVPROC)(GLenum pname, const GLfixed* params);
typedef void (GLAPIENTRYP PFNGLPOINTSIZEXPROC)(GLfixed size);
typedef void (GLAPIENTRYP PFNGLPOLYGONOFFSETXPROC)(GLfixed factor, GLfixed units);
typedef void (GLAPIENTRYP PFNGLROTATEXPROC)(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
typedef void (GLAPIENTRYP PFNGLSAMPLECOVERAGEXPROC)(GLclampx value, GLboolean invert);
typedef void (GLAPIENTRYP PFNGLSCALEXPROC)(GLfixed x, GLfixed y, GLfixed z);
typedef void (GLAPIENTRYP PFNGLTEXENVXPROC)(GLenum target, GLenum pname, GLfixed param);
typedef void (GLAPIENTRYP PFNGLTEXENVXVPROC)(GLenum target, GLenum pname, const GLfixed* params);
typedef void (GLAPIENTRYP PFNGLTEXPARAMETERXPROC)(GLenum target, GLenum pname, GLfixed param);
typedef void (GLAPIENTRYP PFNGLTEXPARAMETERXVPROC)(GLenum target, GLenum pname, const GLfixed* params);
typedef void (GLAPIENTRYP PFNGLTRANSLATEXPROC)(GLfixed x, GLfixed y, GLfixed z);
#endif


#ifndef GL_NV_explicit_multisample
#define GL_NV_explicit_multisample 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGetMultisamplefvNV(GLenum pname, GLuint index, GLfloat* val);
GLAPI void GLAPIENTRY glSampleMaskIndexedNV(GLuint index, GLuint mask);
GLAPI void GLAPIENTRY glTexRenderbufferNV(GLenum target, GLuint renderbuffer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGETMULTISAMPLEFVNVPROC)(GLenum pname, GLuint index, GLfloat* val);
typedef void (GLAPIENTRYP PFNGLSAMPLEMASKINDEXEDNVPROC)(GLuint index, GLuint mask);
typedef void (GLAPIENTRYP PFNGLTEXRENDERBUFFERNVPROC)(GLenum target, GLuint renderbuffer);
#endif


#ifndef GL_NV_fence
#define GL_NV_fence 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDeleteFencesNV(GLsizei n, const GLuint* fences);
GLAPI void GLAPIENTRY glGenFencesNV(GLsizei n, GLuint* fences);
GLAPI GLboolean GLAPIENTRY glIsFenceNV(GLuint fence);
GLAPI GLboolean GLAPIENTRY glTestFenceNV(GLuint fence);
GLAPI void GLAPIENTRY glGetFenceivNV(GLuint fence, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glFinishFenceNV(GLuint fence);
GLAPI void GLAPIENTRY glSetFenceNV(GLuint fence, GLenum condition);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDELETEFENCESNVPROC)(GLsizei n, const GLuint* fences);
typedef void (GLAPIENTRYP PFNGLGENFENCESNVPROC)(GLsizei n, GLuint* fences);
typedef GLboolean (GLAPIENTRYP PFNGLISFENCENVPROC)(GLuint fence);
typedef GLboolean (GLAPIENTRYP PFNGLTESTFENCENVPROC)(GLuint fence);
typedef void (GLAPIENTRYP PFNGLGETFENCEIVNVPROC)(GLuint fence, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLFINISHFENCENVPROC)(GLuint fence);
typedef void (GLAPIENTRYP PFNGLSETFENCENVPROC)(GLuint fence, GLenum condition);
#endif


#ifndef GL_NV_fragment_program
#define GL_NV_fragment_program 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGetProgramNamedParameterdvNV(GLuint id, GLsizei len, const GLubyte* name, GLdouble* params);
GLAPI void GLAPIENTRY glGetProgramNamedParameterfvNV(GLuint id, GLsizei len, const GLubyte* name, GLfloat* params);
GLAPI void GLAPIENTRY glProgramNamedParameter4dNV(GLuint id, GLsizei len, const GLubyte* name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glProgramNamedParameter4dvNV(GLuint id, GLsizei len, const GLubyte* name, const GLdouble* v);
GLAPI void GLAPIENTRY glProgramNamedParameter4fNV(GLuint id, GLsizei len, const GLubyte* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glProgramNamedParameter4fvNV(GLuint id, GLsizei len, const GLubyte* name, const GLfloat* v);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC)(GLuint id, GLsizei len, const GLubyte* name, GLdouble* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC)(GLuint id, GLsizei len, const GLubyte* name, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMNAMEDPARAMETER4DNVPROC)(GLuint id, GLsizei len, const GLubyte* name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC)(GLuint id, GLsizei len, const GLubyte* name, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLPROGRAMNAMEDPARAMETER4FNVPROC)(GLuint id, GLsizei len, const GLubyte* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC)(GLuint id, GLsizei len, const GLubyte* name, const GLfloat* v);
#endif


#ifndef GL_NV_framebuffer_blit
#define GL_NV_framebuffer_blit 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlitFramebufferNV(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLITFRAMEBUFFERNVPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#endif


#ifndef GL_NV_framebuffer_multisample
#define GL_NV_framebuffer_multisample 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glRenderbufferStorageMultisampleNV(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLENVPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#endif


#ifndef GL_NV_framebuffer_multisample_coverage
#define GL_NV_framebuffer_multisample_coverage 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glRenderbufferStorageMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
#endif


#ifndef GL_NV_geometry_program4
#define GL_NV_geometry_program4 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glProgramVertexLimitNV(GLenum target, GLint limit);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPROGRAMVERTEXLIMITNVPROC)(GLenum target, GLint limit);
#endif


#ifndef GL_NV_get_tex_image
#define GL_NV_get_tex_image 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGetTexImageNV(GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels);
GLAPI void GLAPIENTRY glGetCompressedTexImageNV(GLenum target, GLint lod, GLvoid* img);
GLAPI void GLAPIENTRY glGetTexLevelParameterfvNV(GLenum target, GLint level, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetTexLevelParameterivNV(GLenum target, GLint level, GLenum pname, GLint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGETTEXIMAGENVPROC)(GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLGETCOMPRESSEDTEXIMAGENVPROC)(GLenum target, GLint lod, GLvoid* img);
typedef void (GLAPIENTRYP PFNGLGETTEXLEVELPARAMETERFVNVPROC)(GLenum target, GLint level, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETTEXLEVELPARAMETERIVNVPROC)(GLenum target, GLint level, GLenum pname, GLint* params);
#endif


#ifndef GL_NV_gpu_multicast
#define GL_NV_gpu_multicast 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glMulticastBufferSubDataNV(GLbitfield gpuMask, GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid* data);
GLAPI void GLAPIENTRY glMulticastCopyBufferSubDataNV(GLuint sourceGpu, GLbitfield destinationGpuMask, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI void GLAPIENTRY glMulticastCopyImageSubDataNV(GLuint sourceGpu, GLbitfield destinationGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void GLAPIENTRY glMulticastBarrierNV();
GLAPI void GLAPIENTRY glMulticastGetQueryObjectivNV(GLuint gpu, GLuint id, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glMulticastGetQueryObjectuivNV(GLuint gpu, GLuint id, GLenum pname, GLuint* params);
GLAPI void GLAPIENTRY glMulticastGetQueryObjecti64vNV(GLuint gpu, GLuint id, GLenum pname, GLint64* params);
GLAPI void GLAPIENTRY glMulticastGetQueryObjectui64vNV(GLuint gpu, GLuint id, GLenum pname, GLuint64* params);
GLAPI void GLAPIENTRY glMulticastFramebufferSampleLocationsfvNV(GLuint gpu, GLuint framebuffer, GLuint start, GLsizei count, const GLclampf* v);
GLAPI void GLAPIENTRY glRenderGpuMaskNV(GLbitfield mask);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLMULTICASTBUFFERSUBDATANVPROC)(GLbitfield gpuMask, GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLMULTICASTCOPYBUFFERSUBDATANVPROC)(GLuint sourceGpu, GLbitfield destinationGpuMask, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (GLAPIENTRYP PFNGLMULTICASTCOPYIMAGESUBDATANVPROC)(GLuint sourceGpu, GLbitfield destinationGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
typedef void (GLAPIENTRYP PFNGLMULTICASTBARRIERNVPROC)();
typedef void (GLAPIENTRYP PFNGLMULTICASTGETQUERYOBJECTIVNVPROC)(GLuint gpu, GLuint id, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLMULTICASTGETQUERYOBJECTUIVNVPROC)(GLuint gpu, GLuint id, GLenum pname, GLuint* params);
typedef void (GLAPIENTRYP PFNGLMULTICASTGETQUERYOBJECTI64VNVPROC)(GLuint gpu, GLuint id, GLenum pname, GLint64* params);
typedef void (GLAPIENTRYP PFNGLMULTICASTGETQUERYOBJECTUI64VNVPROC)(GLuint gpu, GLuint id, GLenum pname, GLuint64* params);
typedef void (GLAPIENTRYP PFNGLMULTICASTFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)(GLuint gpu, GLuint framebuffer, GLuint start, GLsizei count, const GLclampf* v);
typedef void (GLAPIENTRYP PFNGLRENDERGPUMASKNVPROC)(GLbitfield mask);
#endif


#ifndef GL_NV_gpu_program4
#define GL_NV_gpu_program4 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glProgramLocalParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void GLAPIENTRY glProgramLocalParameterI4ivNV(GLenum target, GLuint index, const GLint* params);
GLAPI void GLAPIENTRY glProgramLocalParametersI4ivNV(GLenum target, GLuint index, GLsizei count, const GLint* params);
GLAPI void GLAPIENTRY glProgramLocalParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void GLAPIENTRY glProgramLocalParameterI4uivNV(GLenum target, GLuint index, const GLuint* params);
GLAPI void GLAPIENTRY glProgramLocalParametersI4uivNV(GLenum target, GLuint index, GLsizei count, const GLuint* params);
GLAPI void GLAPIENTRY glProgramEnvParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void GLAPIENTRY glProgramEnvParameterI4ivNV(GLenum target, GLuint index, const GLint* params);
GLAPI void GLAPIENTRY glProgramEnvParametersI4ivNV(GLenum target, GLuint index, GLsizei count, const GLint* params);
GLAPI void GLAPIENTRY glProgramEnvParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void GLAPIENTRY glProgramEnvParameterI4uivNV(GLenum target, GLuint index, const GLuint* params);
GLAPI void GLAPIENTRY glProgramEnvParametersI4uivNV(GLenum target, GLuint index, GLsizei count, const GLuint* params);
GLAPI void GLAPIENTRY glGetProgramLocalParameterIivNV(GLenum target, GLuint index, GLint* params);
GLAPI void GLAPIENTRY glGetProgramLocalParameterIuivNV(GLenum target, GLuint index, GLuint* params);
GLAPI void GLAPIENTRY glGetProgramEnvParameterIivNV(GLenum target, GLuint index, GLint* params);
GLAPI void GLAPIENTRY glGetProgramEnvParameterIuivNV(GLenum target, GLuint index, GLuint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETERI4INVPROC)(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC)(GLenum target, GLuint index, const GLint* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLint* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETERI4UINVPROC)(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC)(GLenum target, GLuint index, const GLuint* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLuint* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETERI4INVPROC)(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETERI4IVNVPROC)(GLenum target, GLuint index, const GLint* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETERSI4IVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLint* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETERI4UINVPROC)(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETERI4UIVNVPROC)(GLenum target, GLuint index, const GLuint* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC)(GLenum target, GLuint index, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC)(GLenum target, GLuint index, GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMENVPARAMETERIIVNVPROC)(GLenum target, GLuint index, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC)(GLenum target, GLuint index, GLuint* params);
#endif


#ifndef GL_NV_gpu_shader5
#define GL_NV_gpu_shader5 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glUniform1i64NV(GLint location, GLint64EXT x);
GLAPI void GLAPIENTRY glUniform2i64NV(GLint location, GLint64EXT x, GLint64EXT y);
GLAPI void GLAPIENTRY glUniform3i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
GLAPI void GLAPIENTRY glUniform4i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
GLAPI void GLAPIENTRY glUniform1i64vNV(GLint location, GLsizei count, const GLint64EXT* value);
GLAPI void GLAPIENTRY glUniform2i64vNV(GLint location, GLsizei count, const GLint64EXT* value);
GLAPI void GLAPIENTRY glUniform3i64vNV(GLint location, GLsizei count, const GLint64EXT* value);
GLAPI void GLAPIENTRY glUniform4i64vNV(GLint location, GLsizei count, const GLint64EXT* value);
GLAPI void GLAPIENTRY glUniform1ui64NV(GLint location, GLuint64EXT x);
GLAPI void GLAPIENTRY glUniform2ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y);
GLAPI void GLAPIENTRY glUniform3ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
GLAPI void GLAPIENTRY glUniform4ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
GLAPI void GLAPIENTRY glUniform1ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void GLAPIENTRY glUniform2ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void GLAPIENTRY glUniform3ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void GLAPIENTRY glUniform4ui64vNV(GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void GLAPIENTRY glProgramUniform1i64NV(GLuint program, GLint location, GLint64EXT x);
GLAPI void GLAPIENTRY glProgramUniform2i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
GLAPI void GLAPIENTRY glProgramUniform3i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
GLAPI void GLAPIENTRY glProgramUniform4i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
GLAPI void GLAPIENTRY glProgramUniform1i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
GLAPI void GLAPIENTRY glProgramUniform2i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
GLAPI void GLAPIENTRY glProgramUniform3i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
GLAPI void GLAPIENTRY glProgramUniform4i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
GLAPI void GLAPIENTRY glProgramUniform1ui64NV(GLuint program, GLint location, GLuint64EXT x);
GLAPI void GLAPIENTRY glProgramUniform2ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
GLAPI void GLAPIENTRY glProgramUniform3ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
GLAPI void GLAPIENTRY glProgramUniform4ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
GLAPI void GLAPIENTRY glProgramUniform1ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void GLAPIENTRY glProgramUniform2ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void GLAPIENTRY glProgramUniform3ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void GLAPIENTRY glProgramUniform4ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void GLAPIENTRY glGetUniformi64vNV(GLuint program, GLint location, GLint64EXT* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLUNIFORM1I64NVPROC)(GLint location, GLint64EXT x);
typedef void (GLAPIENTRYP PFNGLUNIFORM2I64NVPROC)(GLint location, GLint64EXT x, GLint64EXT y);
typedef void (GLAPIENTRYP PFNGLUNIFORM3I64NVPROC)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void (GLAPIENTRYP PFNGLUNIFORM4I64NVPROC)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void (GLAPIENTRYP PFNGLUNIFORM1I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM2I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM3I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM4I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM1UI64NVPROC)(GLint location, GLuint64EXT x);
typedef void (GLAPIENTRYP PFNGLUNIFORM2UI64NVPROC)(GLint location, GLuint64EXT x, GLuint64EXT y);
typedef void (GLAPIENTRYP PFNGLUNIFORM3UI64NVPROC)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void (GLAPIENTRYP PFNGLUNIFORM4UI64NVPROC)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void (GLAPIENTRYP PFNGLUNIFORM1UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM2UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM3UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM4UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1I64NVPROC)(GLuint program, GLint location, GLint64EXT x);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2I64NVPROC)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3I64NVPROC)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4I64NVPROC)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1I64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2I64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3I64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4I64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1UI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2UI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3UI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4UI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (GLAPIENTRYP PFNGLGETUNIFORMI64VNVPROC)(GLuint program, GLint location, GLint64EXT* params);
#endif


#ifndef GL_NV_half_float
#define GL_NV_half_float 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glVertex2hNV(GLhalf x, GLhalf y);
GLAPI void GLAPIENTRY glVertex2hvNV(const GLhalf* v);
GLAPI void GLAPIENTRY glVertex3hNV(GLhalf x, GLhalf y, GLhalf z);
GLAPI void GLAPIENTRY glVertex3hvNV(const GLhalf* v);
GLAPI void GLAPIENTRY glVertex4hNV(GLhalf x, GLhalf y, GLhalf z, GLhalf w);
GLAPI void GLAPIENTRY glVertex4hvNV(const GLhalf* v);
GLAPI void GLAPIENTRY glNormal3hNV(GLhalf nx, GLhalf ny, GLhalf nz);
GLAPI void GLAPIENTRY glNormal3hvNV(const GLhalf* v);
GLAPI void GLAPIENTRY glColor3hNV(GLhalf red, GLhalf green, GLhalf blue);
GLAPI void GLAPIENTRY glColor3hvNV(const GLhalf* v);
GLAPI void GLAPIENTRY glColor4hNV(GLhalf red, GLhalf green, GLhalf blue, GLhalf alpha);
GLAPI void GLAPIENTRY glColor4hvNV(const GLhalf* v);
GLAPI void GLAPIENTRY glTexCoord1hNV(GLhalf s);
GLAPI void GLAPIENTRY glTexCoord1hvNV(const GLhalf* v);
GLAPI void GLAPIENTRY glTexCoord2hNV(GLhalf s, GLhalf t);
GLAPI void GLAPIENTRY glTexCoord2hvNV(const GLhalf* v);
GLAPI void GLAPIENTRY glTexCoord3hNV(GLhalf s, GLhalf t, GLhalf r);
GLAPI void GLAPIENTRY glTexCoord3hvNV(const GLhalf* v);
GLAPI void GLAPIENTRY glTexCoord4hNV(GLhalf s, GLhalf t, GLhalf r, GLhalf q);
GLAPI void GLAPIENTRY glTexCoord4hvNV(const GLhalf* v);
GLAPI void GLAPIENTRY glMultiTexCoord1hNV(GLenum target, GLhalf s);
GLAPI void GLAPIENTRY glMultiTexCoord1hvNV(GLenum target, const GLhalf* v);
GLAPI void GLAPIENTRY glMultiTexCoord2hNV(GLenum target, GLhalf s, GLhalf t);
GLAPI void GLAPIENTRY glMultiTexCoord2hvNV(GLenum target, const GLhalf* v);
GLAPI void GLAPIENTRY glMultiTexCoord3hNV(GLenum target, GLhalf s, GLhalf t, GLhalf r);
GLAPI void GLAPIENTRY glMultiTexCoord3hvNV(GLenum target, const GLhalf* v);
GLAPI void GLAPIENTRY glMultiTexCoord4hNV(GLenum target, GLhalf s, GLhalf t, GLhalf r, GLhalf q);
GLAPI void GLAPIENTRY glMultiTexCoord4hvNV(GLenum target, const GLhalf* v);
GLAPI void GLAPIENTRY glFogCoordhNV(GLhalf fog);
GLAPI void GLAPIENTRY glFogCoordhvNV(const GLhalf* fog);
GLAPI void GLAPIENTRY glSecondaryColor3hNV(GLhalf red, GLhalf green, GLhalf blue);
GLAPI void GLAPIENTRY glSecondaryColor3hvNV(const GLhalf* v);
GLAPI void GLAPIENTRY glVertexAttrib1hNV(GLuint index, GLhalf x);
GLAPI void GLAPIENTRY glVertexAttrib1hvNV(GLuint index, const GLhalf* v);
GLAPI void GLAPIENTRY glVertexAttrib2hNV(GLuint index, GLhalf x, GLhalf y);
GLAPI void GLAPIENTRY glVertexAttrib2hvNV(GLuint index, const GLhalf* v);
GLAPI void GLAPIENTRY glVertexAttrib3hNV(GLuint index, GLhalf x, GLhalf y, GLhalf z);
GLAPI void GLAPIENTRY glVertexAttrib3hvNV(GLuint index, const GLhalf* v);
GLAPI void GLAPIENTRY glVertexAttrib4hNV(GLuint index, GLhalf x, GLhalf y, GLhalf z, GLhalf w);
GLAPI void GLAPIENTRY glVertexAttrib4hvNV(GLuint index, const GLhalf* v);
GLAPI void GLAPIENTRY glVertexAttribs1hvNV(GLuint index, GLsizei count, const GLhalf* v);
GLAPI void GLAPIENTRY glVertexAttribs2hvNV(GLuint index, GLsizei count, const GLhalf* v);
GLAPI void GLAPIENTRY glVertexAttribs3hvNV(GLuint index, GLsizei count, const GLhalf* v);
GLAPI void GLAPIENTRY glVertexAttribs4hvNV(GLuint index, GLsizei count, const GLhalf* v);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLVERTEX2HNVPROC)(GLhalf x, GLhalf y);
typedef void (GLAPIENTRYP PFNGLVERTEX2HVNVPROC)(const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLVERTEX3HNVPROC)(GLhalf x, GLhalf y, GLhalf z);
typedef void (GLAPIENTRYP PFNGLVERTEX3HVNVPROC)(const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLVERTEX4HNVPROC)(GLhalf x, GLhalf y, GLhalf z, GLhalf w);
typedef void (GLAPIENTRYP PFNGLVERTEX4HVNVPROC)(const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLNORMAL3HNVPROC)(GLhalf nx, GLhalf ny, GLhalf nz);
typedef void (GLAPIENTRYP PFNGLNORMAL3HVNVPROC)(const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLCOLOR3HNVPROC)(GLhalf red, GLhalf green, GLhalf blue);
typedef void (GLAPIENTRYP PFNGLCOLOR3HVNVPROC)(const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLCOLOR4HNVPROC)(GLhalf red, GLhalf green, GLhalf blue, GLhalf alpha);
typedef void (GLAPIENTRYP PFNGLCOLOR4HVNVPROC)(const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD1HNVPROC)(GLhalf s);
typedef void (GLAPIENTRYP PFNGLTEXCOORD1HVNVPROC)(const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD2HNVPROC)(GLhalf s, GLhalf t);
typedef void (GLAPIENTRYP PFNGLTEXCOORD2HVNVPROC)(const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD3HNVPROC)(GLhalf s, GLhalf t, GLhalf r);
typedef void (GLAPIENTRYP PFNGLTEXCOORD3HVNVPROC)(const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD4HNVPROC)(GLhalf s, GLhalf t, GLhalf r, GLhalf q);
typedef void (GLAPIENTRYP PFNGLTEXCOORD4HVNVPROC)(const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1HNVPROC)(GLenum target, GLhalf s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1HVNVPROC)(GLenum target, const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2HNVPROC)(GLenum target, GLhalf s, GLhalf t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2HVNVPROC)(GLenum target, const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3HNVPROC)(GLenum target, GLhalf s, GLhalf t, GLhalf r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3HVNVPROC)(GLenum target, const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4HNVPROC)(GLenum target, GLhalf s, GLhalf t, GLhalf r, GLhalf q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4HVNVPROC)(GLenum target, const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLFOGCOORDHNVPROC)(GLhalf fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDHVNVPROC)(const GLhalf* fog);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3HNVPROC)(GLhalf red, GLhalf green, GLhalf blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3HVNVPROC)(const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1HNVPROC)(GLuint index, GLhalf x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1HVNVPROC)(GLuint index, const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2HNVPROC)(GLuint index, GLhalf x, GLhalf y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2HVNVPROC)(GLuint index, const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3HNVPROC)(GLuint index, GLhalf x, GLhalf y, GLhalf z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3HVNVPROC)(GLuint index, const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4HNVPROC)(GLuint index, GLhalf x, GLhalf y, GLhalf z, GLhalf w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4HVNVPROC)(GLuint index, const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS1HVNVPROC)(GLuint index, GLsizei count, const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS2HVNVPROC)(GLuint index, GLsizei count, const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS3HVNVPROC)(GLuint index, GLsizei count, const GLhalf* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS4HVNVPROC)(GLuint index, GLsizei count, const GLhalf* v);
#endif


#ifndef GL_NV_instanced_arrays
#define GL_NV_instanced_arrays 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glVertexAttribDivisorNV(GLuint index, GLuint divisor);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBDIVISORNVPROC)(GLuint index, GLuint divisor);
#endif


#ifndef GL_NV_internalformat_sample_query
#define GL_NV_internalformat_sample_query 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGetInternalformatSampleivNV(GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei bufSize, GLint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGETINTERNALFORMATSAMPLEIVNVPROC)(GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei bufSize, GLint* params);
#endif


#ifndef GL_NV_non_square_matrices
#define GL_NV_non_square_matrices 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glUniformMatrix2x3fvNV(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix3x2fvNV(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix2x4fvNV(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix4x2fvNV(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix3x4fvNV(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix4x3fvNV(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX2X3FVNVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX3X2FVNVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX2X4FVNVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX4X2FVNVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX3X4FVNVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX4X3FVNVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#endif


#ifndef GL_NV_occlusion_query
#define GL_NV_occlusion_query 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGenOcclusionQueriesNV(GLsizei n, GLuint* ids);
GLAPI void GLAPIENTRY glDeleteOcclusionQueriesNV(GLsizei n, const GLuint* ids);
GLAPI GLboolean GLAPIENTRY glIsOcclusionQueryNV(GLuint id);
GLAPI void GLAPIENTRY glBeginOcclusionQueryNV(GLuint id);
GLAPI void GLAPIENTRY glEndOcclusionQueryNV();
GLAPI void GLAPIENTRY glGetOcclusionQueryivNV(GLuint id, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetOcclusionQueryuivNV(GLuint id, GLenum pname, GLuint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGENOCCLUSIONQUERIESNVPROC)(GLsizei n, GLuint* ids);
typedef void (GLAPIENTRYP PFNGLDELETEOCCLUSIONQUERIESNVPROC)(GLsizei n, const GLuint* ids);
typedef GLboolean (GLAPIENTRYP PFNGLISOCCLUSIONQUERYNVPROC)(GLuint id);
typedef void (GLAPIENTRYP PFNGLBEGINOCCLUSIONQUERYNVPROC)(GLuint id);
typedef void (GLAPIENTRYP PFNGLENDOCCLUSIONQUERYNVPROC)();
typedef void (GLAPIENTRYP PFNGLGETOCCLUSIONQUERYIVNVPROC)(GLuint id, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETOCCLUSIONQUERYUIVNVPROC)(GLuint id, GLenum pname, GLuint* params);
#endif


#ifndef GL_NV_parameter_buffer_object
#define GL_NV_parameter_buffer_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glProgramBufferParametersfvNV(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLfloat* params);
GLAPI void GLAPIENTRY glProgramBufferParametersIivNV(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLint* params);
GLAPI void GLAPIENTRY glProgramBufferParametersIuivNV(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLuint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC)(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC)(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLint* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC)(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLuint* params);
#endif


#ifndef GL_NV_path_rendering
#define GL_NV_path_rendering 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLuint GLAPIENTRY glGenPathsNV(GLsizei range);
GLAPI void GLAPIENTRY glDeletePathsNV(GLuint path, GLsizei range);
GLAPI GLboolean GLAPIENTRY glIsPathNV(GLuint path);
GLAPI void GLAPIENTRY glPathCommandsNV(GLuint path, GLsizei numCommands, const GLubyte* commands, GLsizei numCoords, GLenum coordType, const GLvoid* coords);
GLAPI void GLAPIENTRY glPathCoordsNV(GLuint path, GLsizei numCoords, GLenum coordType, const GLvoid* coords);
GLAPI void GLAPIENTRY glPathSubCommandsNV(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte* commands, GLsizei numCoords, GLenum coordType, const GLvoid* coords);
GLAPI void GLAPIENTRY glPathSubCoordsNV(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const GLvoid* coords);
GLAPI void GLAPIENTRY glPathStringNV(GLuint path, GLenum format, GLsizei length, const GLvoid* pathString);
GLAPI void GLAPIENTRY glPathGlyphsNV(GLuint firstPathName, GLenum fontTarget, const GLvoid* fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const GLvoid* charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
GLAPI void GLAPIENTRY glPathGlyphRangeNV(GLuint firstPathName, GLenum fontTarget, const GLvoid* fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
GLAPI GLenum GLAPIENTRY glPathGlyphIndexArrayNV(GLuint firstPathName, GLenum fontTarget, const GLvoid* fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
GLAPI GLenum GLAPIENTRY glPathMemoryGlyphIndexArrayNV(GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const GLvoid* fontData, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
GLAPI GLenum GLAPIENTRY glPathGlyphIndexRangeNV(GLenum fontTarget, const GLvoid* fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint* baseAndCount);
GLAPI void GLAPIENTRY glWeightPathsNV(GLuint resultPath, GLsizei numPaths, const GLuint* paths, const GLfloat* weights);
GLAPI void GLAPIENTRY glCopyPathNV(GLuint resultPath, GLuint srcPath);
GLAPI void GLAPIENTRY glInterpolatePathsNV(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
GLAPI void GLAPIENTRY glTransformPathNV(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat* transformValues);
GLAPI void GLAPIENTRY glPathParameterivNV(GLuint path, GLenum pname, const GLint* value);
GLAPI void GLAPIENTRY glPathParameteriNV(GLuint path, GLenum pname, GLint value);
GLAPI void GLAPIENTRY glPathParameterfvNV(GLuint path, GLenum pname, const GLfloat* value);
GLAPI void GLAPIENTRY glPathParameterfNV(GLuint path, GLenum pname, GLfloat value);
GLAPI void GLAPIENTRY glPathDashArrayNV(GLuint path, GLsizei dashCount, const GLfloat* dashArray);
GLAPI void GLAPIENTRY glPathStencilFuncNV(GLenum func, GLint ref, GLuint mask);
GLAPI void GLAPIENTRY glPathStencilDepthOffsetNV(GLfloat factor, GLfloat units);
GLAPI void GLAPIENTRY glStencilFillPathNV(GLuint path, GLenum fillMode, GLuint mask);
GLAPI void GLAPIENTRY glStencilStrokePathNV(GLuint path, GLint reference, GLuint mask);
GLAPI void GLAPIENTRY glStencilFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat* transformValues);
GLAPI void GLAPIENTRY glStencilStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat* transformValues);
GLAPI void GLAPIENTRY glPathCoverDepthFuncNV(GLenum func);
GLAPI void GLAPIENTRY glPathColorGenNV(GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat* coeffs);
GLAPI void GLAPIENTRY glPathTexGenNV(GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat* coeffs);
GLAPI void GLAPIENTRY glPathFogGenNV(GLenum genMode);
GLAPI void GLAPIENTRY glCoverFillPathNV(GLuint path, GLenum coverMode);
GLAPI void GLAPIENTRY glCoverStrokePathNV(GLuint path, GLenum coverMode);
GLAPI void GLAPIENTRY glCoverFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat* transformValues);
GLAPI void GLAPIENTRY glCoverStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat* transformValues);
GLAPI void GLAPIENTRY glStencilThenCoverFillPathNV(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
GLAPI void GLAPIENTRY glStencilThenCoverStrokePathNV(GLuint path, GLint reference, GLuint mask, GLenum coverMode);
GLAPI void GLAPIENTRY glStencilThenCoverFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat* transformValues);
GLAPI void GLAPIENTRY glStencilThenCoverStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat* transformValues);
GLAPI void GLAPIENTRY glProgramPathFragmentInputGenNV(GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat* coeffs);
GLAPI void GLAPIENTRY glGetPathParameterivNV(GLuint path, GLenum pname, GLint* value);
GLAPI void GLAPIENTRY glGetPathParameterfvNV(GLuint path, GLenum pname, GLfloat* value);
GLAPI void GLAPIENTRY glGetPathCommandsNV(GLuint path, GLubyte* commands);
GLAPI void GLAPIENTRY glGetPathCoordsNV(GLuint path, GLfloat* coords);
GLAPI void GLAPIENTRY glGetPathDashArrayNV(GLuint path, GLfloat* dashArray);
GLAPI void GLAPIENTRY glGetPathMetricsNV(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLsizei stride, GLfloat* metrics);
GLAPI void GLAPIENTRY glGetPathMetricRangeNV(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat* metrics);
GLAPI void GLAPIENTRY glGetPathSpacingNV(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat* returnedSpacing);
GLAPI void GLAPIENTRY glGetPathColorGenivNV(GLenum color, GLenum pname, GLint* value);
GLAPI void GLAPIENTRY glGetPathColorGenfvNV(GLenum color, GLenum pname, GLfloat* value);
GLAPI void GLAPIENTRY glGetPathTexGenivNV(GLenum texCoordSet, GLenum pname, GLint* value);
GLAPI void GLAPIENTRY glGetPathTexGenfvNV(GLenum texCoordSet, GLenum pname, GLfloat* value);
GLAPI GLboolean GLAPIENTRY glIsPointInFillPathNV(GLuint path, GLuint mask, GLfloat x, GLfloat y);
GLAPI GLboolean GLAPIENTRY glIsPointInStrokePathNV(GLuint path, GLfloat x, GLfloat y);
GLAPI GLfloat GLAPIENTRY glGetPathLengthNV(GLuint path, GLsizei startSegment, GLsizei numSegments);
GLAPI GLboolean GLAPIENTRY glPointAlongPathNV(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat* x, GLfloat* y, GLfloat* tangentX, GLfloat* tangentY);
GLAPI void GLAPIENTRY glMatrixLoad3x2fNV(GLenum mode, const GLfloat* m);
GLAPI void GLAPIENTRY glMatrixLoad3x3fNV(GLenum mode, const GLfloat* m);
GLAPI void GLAPIENTRY glMatrixLoadTranspose3x3fNV(GLenum mode, const GLfloat* m);
GLAPI void GLAPIENTRY glMatrixMult3x2fNV(GLenum mode, const GLfloat* m);
GLAPI void GLAPIENTRY glMatrixMult3x3fNV(GLenum mode, const GLfloat* m);
GLAPI void GLAPIENTRY glMatrixMultTranspose3x3fNV(GLenum mode, const GLfloat* m);
GLAPI void GLAPIENTRY glGetProgramResourcefvNV(GLuint program, GLenum iface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei bufSize, GLsizei* length, GLfloat* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLuint (GLAPIENTRYP PFNGLGENPATHSNVPROC)(GLsizei range);
typedef void (GLAPIENTRYP PFNGLDELETEPATHSNVPROC)(GLuint path, GLsizei range);
typedef GLboolean (GLAPIENTRYP PFNGLISPATHNVPROC)(GLuint path);
typedef void (GLAPIENTRYP PFNGLPATHCOMMANDSNVPROC)(GLuint path, GLsizei numCommands, const GLubyte* commands, GLsizei numCoords, GLenum coordType, const GLvoid* coords);
typedef void (GLAPIENTRYP PFNGLPATHCOORDSNVPROC)(GLuint path, GLsizei numCoords, GLenum coordType, const GLvoid* coords);
typedef void (GLAPIENTRYP PFNGLPATHSUBCOMMANDSNVPROC)(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte* commands, GLsizei numCoords, GLenum coordType, const GLvoid* coords);
typedef void (GLAPIENTRYP PFNGLPATHSUBCOORDSNVPROC)(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const GLvoid* coords);
typedef void (GLAPIENTRYP PFNGLPATHSTRINGNVPROC)(GLuint path, GLenum format, GLsizei length, const GLvoid* pathString);
typedef void (GLAPIENTRYP PFNGLPATHGLYPHSNVPROC)(GLuint firstPathName, GLenum fontTarget, const GLvoid* fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const GLvoid* charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef void (GLAPIENTRYP PFNGLPATHGLYPHRANGENVPROC)(GLuint firstPathName, GLenum fontTarget, const GLvoid* fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef GLenum (GLAPIENTRYP PFNGLPATHGLYPHINDEXARRAYNVPROC)(GLuint firstPathName, GLenum fontTarget, const GLvoid* fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef GLenum (GLAPIENTRYP PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC)(GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const GLvoid* fontData, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef GLenum (GLAPIENTRYP PFNGLPATHGLYPHINDEXRANGENVPROC)(GLenum fontTarget, const GLvoid* fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint* baseAndCount);
typedef void (GLAPIENTRYP PFNGLWEIGHTPATHSNVPROC)(GLuint resultPath, GLsizei numPaths, const GLuint* paths, const GLfloat* weights);
typedef void (GLAPIENTRYP PFNGLCOPYPATHNVPROC)(GLuint resultPath, GLuint srcPath);
typedef void (GLAPIENTRYP PFNGLINTERPOLATEPATHSNVPROC)(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
typedef void (GLAPIENTRYP PFNGLTRANSFORMPATHNVPROC)(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat* transformValues);
typedef void (GLAPIENTRYP PFNGLPATHPARAMETERIVNVPROC)(GLuint path, GLenum pname, const GLint* value);
typedef void (GLAPIENTRYP PFNGLPATHPARAMETERINVPROC)(GLuint path, GLenum pname, GLint value);
typedef void (GLAPIENTRYP PFNGLPATHPARAMETERFVNVPROC)(GLuint path, GLenum pname, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPATHPARAMETERFNVPROC)(GLuint path, GLenum pname, GLfloat value);
typedef void (GLAPIENTRYP PFNGLPATHDASHARRAYNVPROC)(GLuint path, GLsizei dashCount, const GLfloat* dashArray);
typedef void (GLAPIENTRYP PFNGLPATHSTENCILFUNCNVPROC)(GLenum func, GLint ref, GLuint mask);
typedef void (GLAPIENTRYP PFNGLPATHSTENCILDEPTHOFFSETNVPROC)(GLfloat factor, GLfloat units);
typedef void (GLAPIENTRYP PFNGLSTENCILFILLPATHNVPROC)(GLuint path, GLenum fillMode, GLuint mask);
typedef void (GLAPIENTRYP PFNGLSTENCILSTROKEPATHNVPROC)(GLuint path, GLint reference, GLuint mask);
typedef void (GLAPIENTRYP PFNGLSTENCILFILLPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat* transformValues);
typedef void (GLAPIENTRYP PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat* transformValues);
typedef void (GLAPIENTRYP PFNGLPATHCOVERDEPTHFUNCNVPROC)(GLenum func);
typedef void (GLAPIENTRYP PFNGLPATHCOLORGENNVPROC)(GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat* coeffs);
typedef void (GLAPIENTRYP PFNGLPATHTEXGENNVPROC)(GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat* coeffs);
typedef void (GLAPIENTRYP PFNGLPATHFOGGENNVPROC)(GLenum genMode);
typedef void (GLAPIENTRYP PFNGLCOVERFILLPATHNVPROC)(GLuint path, GLenum coverMode);
typedef void (GLAPIENTRYP PFNGLCOVERSTROKEPATHNVPROC)(GLuint path, GLenum coverMode);
typedef void (GLAPIENTRYP PFNGLCOVERFILLPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat* transformValues);
typedef void (GLAPIENTRYP PFNGLCOVERSTROKEPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat* transformValues);
typedef void (GLAPIENTRYP PFNGLSTENCILTHENCOVERFILLPATHNVPROC)(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
typedef void (GLAPIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC)(GLuint path, GLint reference, GLuint mask, GLenum coverMode);
typedef void (GLAPIENTRYP PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat* transformValues);
typedef void (GLAPIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat* transformValues);
typedef void (GLAPIENTRYP PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC)(GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat* coeffs);
typedef void (GLAPIENTRYP PFNGLGETPATHPARAMETERIVNVPROC)(GLuint path, GLenum pname, GLint* value);
typedef void (GLAPIENTRYP PFNGLGETPATHPARAMETERFVNVPROC)(GLuint path, GLenum pname, GLfloat* value);
typedef void (GLAPIENTRYP PFNGLGETPATHCOMMANDSNVPROC)(GLuint path, GLubyte* commands);
typedef void (GLAPIENTRYP PFNGLGETPATHCOORDSNVPROC)(GLuint path, GLfloat* coords);
typedef void (GLAPIENTRYP PFNGLGETPATHDASHARRAYNVPROC)(GLuint path, GLfloat* dashArray);
typedef void (GLAPIENTRYP PFNGLGETPATHMETRICSNVPROC)(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLsizei stride, GLfloat* metrics);
typedef void (GLAPIENTRYP PFNGLGETPATHMETRICRANGENVPROC)(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat* metrics);
typedef void (GLAPIENTRYP PFNGLGETPATHSPACINGNVPROC)(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat* returnedSpacing);
typedef void (GLAPIENTRYP PFNGLGETPATHCOLORGENIVNVPROC)(GLenum color, GLenum pname, GLint* value);
typedef void (GLAPIENTRYP PFNGLGETPATHCOLORGENFVNVPROC)(GLenum color, GLenum pname, GLfloat* value);
typedef void (GLAPIENTRYP PFNGLGETPATHTEXGENIVNVPROC)(GLenum texCoordSet, GLenum pname, GLint* value);
typedef void (GLAPIENTRYP PFNGLGETPATHTEXGENFVNVPROC)(GLenum texCoordSet, GLenum pname, GLfloat* value);
typedef GLboolean (GLAPIENTRYP PFNGLISPOINTINFILLPATHNVPROC)(GLuint path, GLuint mask, GLfloat x, GLfloat y);
typedef GLboolean (GLAPIENTRYP PFNGLISPOINTINSTROKEPATHNVPROC)(GLuint path, GLfloat x, GLfloat y);
typedef GLfloat (GLAPIENTRYP PFNGLGETPATHLENGTHNVPROC)(GLuint path, GLsizei startSegment, GLsizei numSegments);
typedef GLboolean (GLAPIENTRYP PFNGLPOINTALONGPATHNVPROC)(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat* x, GLfloat* y, GLfloat* tangentX, GLfloat* tangentY);
typedef void (GLAPIENTRYP PFNGLMATRIXLOAD3X2FNVPROC)(GLenum mode, const GLfloat* m);
typedef void (GLAPIENTRYP PFNGLMATRIXLOAD3X3FNVPROC)(GLenum mode, const GLfloat* m);
typedef void (GLAPIENTRYP PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC)(GLenum mode, const GLfloat* m);
typedef void (GLAPIENTRYP PFNGLMATRIXMULT3X2FNVPROC)(GLenum mode, const GLfloat* m);
typedef void (GLAPIENTRYP PFNGLMATRIXMULT3X3FNVPROC)(GLenum mode, const GLfloat* m);
typedef void (GLAPIENTRYP PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC)(GLenum mode, const GLfloat* m);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMRESOURCEFVNVPROC)(GLuint program, GLenum iface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei bufSize, GLsizei* length, GLfloat* params);
#endif


#ifndef GL_NV_pixel_data_range
#define GL_NV_pixel_data_range 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glFlushPixelDataRangeNV(GLenum target);
GLAPI void GLAPIENTRY glPixelDataRangeNV(GLenum target, GLsizei size, const GLvoid* pointer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLFLUSHPIXELDATARANGENVPROC)(GLenum target);
typedef void (GLAPIENTRYP PFNGLPIXELDATARANGENVPROC)(GLenum target, GLsizei size, const GLvoid* pointer);
#endif


#ifndef GL_NV_point_sprite
#define GL_NV_point_sprite 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPointParameteriNV(GLenum pname, GLint param);
GLAPI void GLAPIENTRY glPointParameterivNV(GLenum pname, const GLint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERINVPROC)(GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERIVNVPROC)(GLenum pname, const GLint* params);
#endif


#ifndef GL_NV_present_video
#define GL_NV_present_video 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPresentFrameKeyedNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1);
GLAPI void GLAPIENTRY glPresentFrameDualFillNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3);
GLAPI void GLAPIENTRY glGetVideoivNV(GLuint video_slot, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetVideouivNV(GLuint video_slot, GLenum pname, GLuint* params);
GLAPI void GLAPIENTRY glGetVideoi64vNV(GLuint video_slot, GLenum pname, GLint64EXT* params);
GLAPI void GLAPIENTRY glGetVideoui64vNV(GLuint video_slot, GLenum pname, GLuint64EXT* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPRESENTFRAMEKEYEDNVPROC)(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1);
typedef void (GLAPIENTRYP PFNGLPRESENTFRAMEDUALFILLNVPROC)(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3);
typedef void (GLAPIENTRYP PFNGLGETVIDEOIVNVPROC)(GLuint video_slot, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETVIDEOUIVNVPROC)(GLuint video_slot, GLenum pname, GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETVIDEOI64VNVPROC)(GLuint video_slot, GLenum pname, GLint64EXT* params);
typedef void (GLAPIENTRYP PFNGLGETVIDEOUI64VNVPROC)(GLuint video_slot, GLenum pname, GLuint64EXT* params);
#endif


#ifndef GL_NV_primitive_restart
#define GL_NV_primitive_restart 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPrimitiveRestartNV();
GLAPI void GLAPIENTRY glPrimitiveRestartIndexNV(GLuint index);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPRIMITIVERESTARTNVPROC)();
typedef void (GLAPIENTRYP PFNGLPRIMITIVERESTARTINDEXNVPROC)(GLuint index);
#endif


#ifndef GL_NV_read_buffer
#define GL_NV_read_buffer 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glReadBufferNV(GLenum mode);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLREADBUFFERNVPROC)(GLenum mode);
#endif


#ifndef GL_NV_register_combiners
#define GL_NV_register_combiners 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glCombinerParameterfvNV(GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glCombinerParameterfNV(GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glCombinerParameterivNV(GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glCombinerParameteriNV(GLenum pname, GLint param);
GLAPI void GLAPIENTRY glCombinerInputNV(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
GLAPI void GLAPIENTRY glCombinerOutputNV(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
GLAPI void GLAPIENTRY glFinalCombinerInputNV(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
GLAPI void GLAPIENTRY glGetCombinerInputParameterfvNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetCombinerInputParameterivNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetCombinerOutputParameterfvNV(GLenum stage, GLenum portion, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetCombinerOutputParameterivNV(GLenum stage, GLenum portion, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetFinalCombinerInputParameterfvNV(GLenum variable, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetFinalCombinerInputParameterivNV(GLenum variable, GLenum pname, GLint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOMBINERPARAMETERFVNVPROC)(GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLCOMBINERPARAMETERFNVPROC)(GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLCOMBINERPARAMETERIVNVPROC)(GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLCOMBINERPARAMETERINVPROC)(GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLCOMBINERINPUTNVPROC)(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
typedef void (GLAPIENTRYP PFNGLCOMBINEROUTPUTNVPROC)(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
typedef void (GLAPIENTRYP PFNGLFINALCOMBINERINPUTNVPROC)(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
typedef void (GLAPIENTRYP PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)(GLenum stage, GLenum portion, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)(GLenum stage, GLenum portion, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC)(GLenum variable, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC)(GLenum variable, GLenum pname, GLint* params);
#endif


#ifndef GL_NV_register_combiners2
#define GL_NV_register_combiners2 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glCombinerStageParameterfvNV(GLenum stage, GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glGetCombinerStageParameterfvNV(GLenum stage, GLenum pname, GLfloat* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOMBINERSTAGEPARAMETERFVNVPROC)(GLenum stage, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC)(GLenum stage, GLenum pname, GLfloat* params);
#endif


#ifndef GL_NV_shader_buffer_load
#define GL_NV_shader_buffer_load 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGetBufferParameterui64vNV(GLenum target, GLenum pname, GLuint64EXT* params);
GLAPI void GLAPIENTRY glGetIntegerui64vNV(GLenum target, GLuint64EXT* data);
GLAPI void GLAPIENTRY glGetNamedBufferParameterui64vNV(GLuint buffer, GLenum pname, GLuint64EXT* params);
GLAPI GLboolean GLAPIENTRY glIsBufferResidentNV(GLenum target);
GLAPI GLboolean GLAPIENTRY glIsNamedBufferResidentNV(GLuint buffer);
GLAPI void GLAPIENTRY glMakeBufferNonResidentNV(GLenum target);
GLAPI void GLAPIENTRY glMakeBufferResidentNV(GLenum target, GLenum access);
GLAPI void GLAPIENTRY glMakeNamedBufferNonResidentNV(GLuint buffer);
GLAPI void GLAPIENTRY glMakeNamedBufferResidentNV(GLuint buffer, GLenum access);
GLAPI void GLAPIENTRY glUniformui64NV(GLint location, GLuint64EXT v0);
GLAPI void GLAPIENTRY glUniformui64vNV(GLint location, GLsizei count, const GLuint64EXT* value);
GLAPI void GLAPIENTRY glGetUniformui64vNV(GLuint program, GLint location, GLuint64EXT* params);
GLAPI void GLAPIENTRY glProgramUniformui64NV(GLuint program, GLint location, GLuint64EXT v0);
GLAPI void GLAPIENTRY glProgramUniformui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGETBUFFERPARAMETERUI64VNVPROC)(GLenum target, GLenum pname, GLuint64EXT* params);
typedef void (GLAPIENTRYP PFNGLGETINTEGERUI64VNVPROC)(GLenum target, GLuint64EXT* data);
typedef void (GLAPIENTRYP PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC)(GLuint buffer, GLenum pname, GLuint64EXT* params);
typedef GLboolean (GLAPIENTRYP PFNGLISBUFFERRESIDENTNVPROC)(GLenum target);
typedef GLboolean (GLAPIENTRYP PFNGLISNAMEDBUFFERRESIDENTNVPROC)(GLuint buffer);
typedef void (GLAPIENTRYP PFNGLMAKEBUFFERNONRESIDENTNVPROC)(GLenum target);
typedef void (GLAPIENTRYP PFNGLMAKEBUFFERRESIDENTNVPROC)(GLenum target, GLenum access);
typedef void (GLAPIENTRYP PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC)(GLuint buffer);
typedef void (GLAPIENTRYP PFNGLMAKENAMEDBUFFERRESIDENTNVPROC)(GLuint buffer, GLenum access);
typedef void (GLAPIENTRYP PFNGLUNIFORMUI64NVPROC)(GLint location, GLuint64EXT v0);
typedef void (GLAPIENTRYP PFNGLUNIFORMUI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (GLAPIENTRYP PFNGLGETUNIFORMUI64VNVPROC)(GLuint program, GLint location, GLuint64EXT* params);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMUI64NVPROC)(GLuint program, GLint location, GLuint64EXT v0);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMUI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
#endif


#ifndef GL_NV_tessellation_program5
#define GL_NV_tessellation_program5 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPatchParameteriNV(GLenum pname, GLint value);
GLAPI void GLAPIENTRY glPatchParameterfvNV(GLenum pname, const GLfloat* values);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPATCHPARAMETERINVPROC)(GLenum pname, GLint value);
typedef void (GLAPIENTRYP PFNGLPATCHPARAMETERFVNVPROC)(GLenum pname, const GLfloat* values);
#endif


#ifndef GL_NV_texture_array
#define GL_NV_texture_array 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glCompressedTexImage3DNV(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* data);
GLAPI void GLAPIENTRY glCompressedTexSubImage3DNV(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data);
GLAPI void GLAPIENTRY glCopyTexSubImage3DNV(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glFramebufferTextureLayerNV(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void GLAPIENTRY glTexImage3DNV(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glTexSubImage3DNV(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DNVPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DNVPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCOPYTEXSUBIMAGE3DNVPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERNVPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (GLAPIENTRYP PFNGLTEXIMAGE3DNVPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLTEXSUBIMAGE3DNVPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
#endif


#ifndef GL_NV_texture_barrier
#define GL_NV_texture_barrier 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTextureBarrierNV();
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXTUREBARRIERNVPROC)();
#endif


#ifndef GL_NV_texture_dirty_tile_map
#define GL_NV_texture_dirty_tile_map 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGetTextureDirtyTileMapNV(GLuint texture, GLint level, GLuint writeBuffer, GLintptr writeOffset);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGETTEXTUREDIRTYTILEMAPNVPROC)(GLuint texture, GLint level, GLuint writeBuffer, GLintptr writeOffset);
#endif


#ifndef GL_NV_texture_multisample
#define GL_NV_texture_multisample 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTexImage2DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
GLAPI void GLAPIENTRY glTexImage3DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
GLAPI void GLAPIENTRY glTextureImage2DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
GLAPI void GLAPIENTRY glTextureImage3DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
GLAPI void GLAPIENTRY glTextureImage2DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
GLAPI void GLAPIENTRY glTextureImage3DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
typedef void (GLAPIENTRYP PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
typedef void (GLAPIENTRYP PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC)(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
typedef void (GLAPIENTRYP PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC)(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
typedef void (GLAPIENTRYP PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC)(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
typedef void (GLAPIENTRYP PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC)(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
#endif


#ifndef GL_NV_timer_query
#define GL_NV_timer_query 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGetQueryObjectui64vNV(GLuint id, GLenum pname, GLuint64* params);
GLAPI void GLAPIENTRY glQueryCounterNV(GLuint id, GLenum target);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTUI64VNVPROC)(GLuint id, GLenum pname, GLuint64* params);
typedef void (GLAPIENTRYP PFNGLQUERYCOUNTERNVPROC)(GLuint id, GLenum target);
#endif


#ifndef GL_NV_transform_feedback
#define GL_NV_transform_feedback 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBeginTransformFeedbackNV(GLenum primitiveMode);
GLAPI void GLAPIENTRY glEndTransformFeedbackNV();
GLAPI void GLAPIENTRY glTransformFeedbackAttribsNV(GLuint count, const GLint* attribs, GLenum bufferMode);
GLAPI void GLAPIENTRY glBindBufferRangeNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void GLAPIENTRY glBindBufferOffsetNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
GLAPI void GLAPIENTRY glBindBufferBaseNV(GLenum target, GLuint index, GLuint buffer);
GLAPI void GLAPIENTRY glTransformFeedbackVaryingsNV(GLuint program, GLsizei count, const GLint* locations, GLenum bufferMode);
GLAPI void GLAPIENTRY glActiveVaryingNV(GLuint program, const GLchar* name);
GLAPI GLint GLAPIENTRY glGetVaryingLocationNV(GLuint program, const GLchar* name);
GLAPI void GLAPIENTRY glGetActiveVaryingNV(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
GLAPI void GLAPIENTRY glGetTransformFeedbackVaryingNV(GLuint program, GLuint index, GLint* location);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBEGINTRANSFORMFEEDBACKNVPROC)(GLenum primitiveMode);
typedef void (GLAPIENTRYP PFNGLENDTRANSFORMFEEDBACKNVPROC)();
typedef void (GLAPIENTRYP PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC)(GLuint count, const GLint* attribs, GLenum bufferMode);
typedef void (GLAPIENTRYP PFNGLBINDBUFFERRANGENVPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (GLAPIENTRYP PFNGLBINDBUFFEROFFSETNVPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLBINDBUFFERBASENVPROC)(GLenum target, GLuint index, GLuint buffer);
typedef void (GLAPIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC)(GLuint program, GLsizei count, const GLint* locations, GLenum bufferMode);
typedef void (GLAPIENTRYP PFNGLACTIVEVARYINGNVPROC)(GLuint program, const GLchar* name);
typedef GLint (GLAPIENTRYP PFNGLGETVARYINGLOCATIONNVPROC)(GLuint program, const GLchar* name);
typedef void (GLAPIENTRYP PFNGLGETACTIVEVARYINGNVPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
typedef void (GLAPIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC)(GLuint program, GLuint index, GLint* location);
#endif


#ifndef GL_NV_transform_feedback2
#define GL_NV_transform_feedback2 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGenTransformFeedbacksNV(GLsizei n, GLuint* ids);
GLAPI void GLAPIENTRY glDeleteTransformFeedbacksNV(GLsizei n, const GLuint* ids);
GLAPI void GLAPIENTRY glBindTransformFeedbackNV(GLenum target, GLuint id);
GLAPI GLboolean GLAPIENTRY glIsTransformFeedbackNV(GLuint id);
GLAPI void GLAPIENTRY glPauseTransformFeedbackNV();
GLAPI void GLAPIENTRY glResumeTransformFeedbackNV();
GLAPI void GLAPIENTRY glDrawTransformFeedbackNV(GLenum mode, GLuint name);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGENTRANSFORMFEEDBACKSNVPROC)(GLsizei n, GLuint* ids);
typedef void (GLAPIENTRYP PFNGLDELETETRANSFORMFEEDBACKSNVPROC)(GLsizei n, const GLuint* ids);
typedef void (GLAPIENTRYP PFNGLBINDTRANSFORMFEEDBACKNVPROC)(GLenum target, GLuint id);
typedef GLboolean (GLAPIENTRYP PFNGLISTRANSFORMFEEDBACKNVPROC)(GLuint id);
typedef void (GLAPIENTRYP PFNGLPAUSETRANSFORMFEEDBACKNVPROC)();
typedef void (GLAPIENTRYP PFNGLRESUMETRANSFORMFEEDBACKNVPROC)();
typedef void (GLAPIENTRYP PFNGLDRAWTRANSFORMFEEDBACKNVPROC)(GLenum mode, GLuint name);
#endif


#ifndef GL_NV_vdpau_interop
#define GL_NV_vdpau_interop 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glVDPAUInitNV(const GLvoid* vdpDevice, const GLvoid* getProcAddress);
GLAPI void GLAPIENTRY glVDPAUFiniNV();
GLAPI GLvdpauSurfaceNV GLAPIENTRY glVDPAURegisterVideoSurfaceNV(const GLvoid* vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint* textureNames);
GLAPI GLvdpauSurfaceNV GLAPIENTRY glVDPAURegisterOutputSurfaceNV(const GLvoid* vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint* textureNames);
GLAPI GLboolean GLAPIENTRY glVDPAUIsSurfaceNV(GLvdpauSurfaceNV surface);
GLAPI void GLAPIENTRY glVDPAUUnregisterSurfaceNV(GLvdpauSurfaceNV surface);
GLAPI void GLAPIENTRY glVDPAUGetSurfaceivNV(GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values);
GLAPI void GLAPIENTRY glVDPAUSurfaceAccessNV(GLvdpauSurfaceNV surface, GLenum access);
GLAPI void GLAPIENTRY glVDPAUMapSurfacesNV(GLsizei numSurfaces, const GLvdpauSurfaceNV* surfaces);
GLAPI void GLAPIENTRY glVDPAUUnmapSurfacesNV(GLsizei numSurface, const GLvdpauSurfaceNV* surfaces);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLVDPAUINITNVPROC)(const GLvoid* vdpDevice, const GLvoid* getProcAddress);
typedef void (GLAPIENTRYP PFNGLVDPAUFININVPROC)();
typedef GLvdpauSurfaceNV (GLAPIENTRYP PFNGLVDPAUREGISTERVIDEOSURFACENVPROC)(const GLvoid* vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint* textureNames);
typedef GLvdpauSurfaceNV (GLAPIENTRYP PFNGLVDPAUREGISTEROUTPUTSURFACENVPROC)(const GLvoid* vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint* textureNames);
typedef GLboolean (GLAPIENTRYP PFNGLVDPAUISSURFACENVPROC)(GLvdpauSurfaceNV surface);
typedef void (GLAPIENTRYP PFNGLVDPAUUNREGISTERSURFACENVPROC)(GLvdpauSurfaceNV surface);
typedef void (GLAPIENTRYP PFNGLVDPAUGETSURFACEIVNVPROC)(GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values);
typedef void (GLAPIENTRYP PFNGLVDPAUSURFACEACCESSNVPROC)(GLvdpauSurfaceNV surface, GLenum access);
typedef void (GLAPIENTRYP PFNGLVDPAUMAPSURFACESNVPROC)(GLsizei numSurfaces, const GLvdpauSurfaceNV* surfaces);
typedef void (GLAPIENTRYP PFNGLVDPAUUNMAPSURFACESNVPROC)(GLsizei numSurface, const GLvdpauSurfaceNV* surfaces);
#endif


#ifndef GL_NV_vertex_array_range
#define GL_NV_vertex_array_range 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glFlushVertexArrayRangeNV();
GLAPI void GLAPIENTRY glVertexArrayRangeNV(GLsizei size, const GLvoid* pointer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLFLUSHVERTEXARRAYRANGENVPROC)();
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYRANGENVPROC)(GLsizei size, const GLvoid* pointer);
#endif


#ifndef GL_NV_vertex_attrib_integer_64bit
#define GL_NV_vertex_attrib_integer_64bit 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glVertexAttribL1i64NV(GLuint index, GLint64EXT x);
GLAPI void GLAPIENTRY glVertexAttribL2i64NV(GLuint index, GLint64EXT x, GLint64EXT y);
GLAPI void GLAPIENTRY glVertexAttribL3i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
GLAPI void GLAPIENTRY glVertexAttribL4i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
GLAPI void GLAPIENTRY glVertexAttribL1ui64NV(GLuint index, GLuint64EXT x);
GLAPI void GLAPIENTRY glVertexAttribL2ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y);
GLAPI void GLAPIENTRY glVertexAttribL3ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
GLAPI void GLAPIENTRY glVertexAttribL4ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
GLAPI void GLAPIENTRY glVertexAttribL1i64vNV(GLuint index, const GLint64EXT* v);
GLAPI void GLAPIENTRY glVertexAttribL2i64vNV(GLuint index, const GLint64EXT* v);
GLAPI void GLAPIENTRY glVertexAttribL3i64vNV(GLuint index, const GLint64EXT* v);
GLAPI void GLAPIENTRY glVertexAttribL4i64vNV(GLuint index, const GLint64EXT* v);
GLAPI void GLAPIENTRY glVertexAttribL1ui64vNV(GLuint index, const GLuint64EXT* v);
GLAPI void GLAPIENTRY glVertexAttribL2ui64vNV(GLuint index, const GLuint64EXT* v);
GLAPI void GLAPIENTRY glVertexAttribL3ui64vNV(GLuint index, const GLuint64EXT* v);
GLAPI void GLAPIENTRY glVertexAttribL4ui64vNV(GLuint index, const GLuint64EXT* v);
GLAPI void GLAPIENTRY glVertexAttribLFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride);
GLAPI void GLAPIENTRY glGetVertexAttribLi64vNV(GLuint index, GLenum pname, GLint64EXT* params);
GLAPI void GLAPIENTRY glGetVertexAttribLui64vNV(GLuint index, GLenum pname, GLuint64EXT* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL1I64NVPROC)(GLuint index, GLint64EXT x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL2I64NVPROC)(GLuint index, GLint64EXT x, GLint64EXT y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL3I64NVPROC)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL4I64NVPROC)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL1UI64NVPROC)(GLuint index, GLuint64EXT x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL2UI64NVPROC)(GLuint index, GLuint64EXT x, GLuint64EXT y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL3UI64NVPROC)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL4UI64NVPROC)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL1I64VNVPROC)(GLuint index, const GLint64EXT* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL2I64VNVPROC)(GLuint index, const GLint64EXT* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL3I64VNVPROC)(GLuint index, const GLint64EXT* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL4I64VNVPROC)(GLuint index, const GLint64EXT* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL1UI64VNVPROC)(GLuint index, const GLuint64EXT* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL2UI64VNVPROC)(GLuint index, const GLuint64EXT* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL3UI64VNVPROC)(GLuint index, const GLuint64EXT* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL4UI64VNVPROC)(GLuint index, const GLuint64EXT* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBLFORMATNVPROC)(GLuint index, GLint size, GLenum type, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBLI64VNVPROC)(GLuint index, GLenum pname, GLint64EXT* params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBLUI64VNVPROC)(GLuint index, GLenum pname, GLuint64EXT* params);
#endif


#ifndef GL_NV_vertex_buffer_unified_memory
#define GL_NV_vertex_buffer_unified_memory 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBufferAddressRangeNV(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
GLAPI void GLAPIENTRY glVertexFormatNV(GLint size, GLenum type, GLsizei stride);
GLAPI void GLAPIENTRY glNormalFormatNV(GLenum type, GLsizei stride);
GLAPI void GLAPIENTRY glColorFormatNV(GLint size, GLenum type, GLsizei stride);
GLAPI void GLAPIENTRY glIndexFormatNV(GLenum type, GLsizei stride);
GLAPI void GLAPIENTRY glTexCoordFormatNV(GLint size, GLenum type, GLsizei stride);
GLAPI void GLAPIENTRY glEdgeFlagFormatNV(GLsizei stride);
GLAPI void GLAPIENTRY glSecondaryColorFormatNV(GLint size, GLenum type, GLsizei stride);
GLAPI void GLAPIENTRY glFogCoordFormatNV(GLenum type, GLsizei stride);
GLAPI void GLAPIENTRY glVertexAttribFormatNV(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
GLAPI void GLAPIENTRY glVertexAttribIFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride);
GLAPI void GLAPIENTRY glGetIntegerui64i_vNV(GLenum target, GLuint index, GLuint64EXT* data);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBUFFERADDRESSRANGENVPROC)(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
typedef void (GLAPIENTRYP PFNGLVERTEXFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLNORMALFORMATNVPROC)(GLenum type, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLCOLORFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLINDEXFORMATNVPROC)(GLenum type, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLTEXCOORDFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLEDGEFLAGFORMATNVPROC)(GLsizei stride);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLORFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLFOGCOORDFORMATNVPROC)(GLenum type, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBFORMATNVPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBIFORMATNVPROC)(GLuint index, GLint size, GLenum type, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLGETINTEGERUI64I_VNVPROC)(GLenum target, GLuint index, GLuint64EXT* data);
#endif


#ifndef GL_NV_vertex_program
#define GL_NV_vertex_program 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLboolean GLAPIENTRY glAreProgramsResidentNV(GLsizei n, const GLuint* programs, GLboolean* residences);
GLAPI void GLAPIENTRY glBindProgramNV(GLenum target, GLuint id);
GLAPI void GLAPIENTRY glDeleteProgramsNV(GLsizei n, const GLuint* programs);
GLAPI void GLAPIENTRY glExecuteProgramNV(GLenum target, GLuint id, const GLfloat* params);
GLAPI void GLAPIENTRY glGenProgramsNV(GLsizei n, GLuint* programs);
GLAPI void GLAPIENTRY glGetProgramParameterdvNV(GLenum target, GLuint index, GLenum pname, GLdouble* params);
GLAPI void GLAPIENTRY glGetProgramParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetProgramivNV(GLuint id, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetProgramStringNV(GLuint id, GLenum pname, GLubyte* program);
GLAPI void GLAPIENTRY glGetTrackMatrixivNV(GLenum target, GLuint address, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetVertexAttribdvNV(GLuint index, GLenum pname, GLdouble* params);
GLAPI void GLAPIENTRY glGetVertexAttribfvNV(GLuint index, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetVertexAttribivNV(GLuint index, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetVertexAttribPointervNV(GLuint index, GLenum pname, GLvoid** pointer);
GLAPI GLboolean GLAPIENTRY glIsProgramNV(GLuint id);
GLAPI void GLAPIENTRY glLoadProgramNV(GLenum target, GLuint id, GLsizei len, const GLubyte* program);
GLAPI void GLAPIENTRY glProgramParameter4dNV(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glProgramParameter4dvNV(GLenum target, GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glProgramParameter4fNV(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glProgramParameter4fvNV(GLenum target, GLuint index, const GLfloat* v);
GLAPI void GLAPIENTRY glProgramParameters4dvNV(GLenum target, GLuint index, GLsizei count, const GLdouble* v);
GLAPI void GLAPIENTRY glProgramParameters4fvNV(GLenum target, GLuint index, GLsizei count, const GLfloat* v);
GLAPI void GLAPIENTRY glRequestResidentProgramsNV(GLsizei n, const GLuint* programs);
GLAPI void GLAPIENTRY glTrackMatrixNV(GLenum target, GLuint address, GLenum matrix, GLenum transform);
GLAPI void GLAPIENTRY glVertexAttribPointerNV(GLuint index, GLint fsize, GLenum type, GLsizei stride, const GLvoid* pointer);
GLAPI void GLAPIENTRY glVertexAttrib1dNV(GLuint index, GLdouble x);
GLAPI void GLAPIENTRY glVertexAttrib1dvNV(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttrib1fNV(GLuint index, GLfloat x);
GLAPI void GLAPIENTRY glVertexAttrib1fvNV(GLuint index, const GLfloat* v);
GLAPI void GLAPIENTRY glVertexAttrib1sNV(GLuint index, GLshort x);
GLAPI void GLAPIENTRY glVertexAttrib1svNV(GLuint index, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttrib2dNV(GLuint index, GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glVertexAttrib2dvNV(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttrib2fNV(GLuint index, GLfloat x, GLfloat y);
GLAPI void GLAPIENTRY glVertexAttrib2fvNV(GLuint index, const GLfloat* v);
GLAPI void GLAPIENTRY glVertexAttrib2sNV(GLuint index, GLshort x, GLshort y);
GLAPI void GLAPIENTRY glVertexAttrib2svNV(GLuint index, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttrib3dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glVertexAttrib3dvNV(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttrib3fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glVertexAttrib3fvNV(GLuint index, const GLfloat* v);
GLAPI void GLAPIENTRY glVertexAttrib3sNV(GLuint index, GLshort x, GLshort y, GLshort z);
GLAPI void GLAPIENTRY glVertexAttrib3svNV(GLuint index, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttrib4dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glVertexAttrib4dvNV(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttrib4fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glVertexAttrib4fvNV(GLuint index, const GLfloat* v);
GLAPI void GLAPIENTRY glVertexAttrib4sNV(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI void GLAPIENTRY glVertexAttrib4svNV(GLuint index, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttrib4ubNV(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GLAPI void GLAPIENTRY glVertexAttrib4ubvNV(GLuint index, const GLubyte* v);
GLAPI void GLAPIENTRY glVertexAttribs1dvNV(GLuint index, GLsizei count, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttribs1fvNV(GLuint index, GLsizei count, const GLfloat* v);
GLAPI void GLAPIENTRY glVertexAttribs1svNV(GLuint index, GLsizei count, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttribs2dvNV(GLuint index, GLsizei count, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttribs2fvNV(GLuint index, GLsizei count, const GLfloat* v);
GLAPI void GLAPIENTRY glVertexAttribs2svNV(GLuint index, GLsizei count, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttribs3dvNV(GLuint index, GLsizei count, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttribs3fvNV(GLuint index, GLsizei count, const GLfloat* v);
GLAPI void GLAPIENTRY glVertexAttribs3svNV(GLuint index, GLsizei count, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttribs4dvNV(GLuint index, GLsizei count, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttribs4fvNV(GLuint index, GLsizei count, const GLfloat* v);
GLAPI void GLAPIENTRY glVertexAttribs4svNV(GLuint index, GLsizei count, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttribs4ubvNV(GLuint index, GLsizei count, const GLubyte* v);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLboolean (GLAPIENTRYP PFNGLAREPROGRAMSRESIDENTNVPROC)(GLsizei n, const GLuint* programs, GLboolean* residences);
typedef void (GLAPIENTRYP PFNGLBINDPROGRAMNVPROC)(GLenum target, GLuint id);
typedef void (GLAPIENTRYP PFNGLDELETEPROGRAMSNVPROC)(GLsizei n, const GLuint* programs);
typedef void (GLAPIENTRYP PFNGLEXECUTEPROGRAMNVPROC)(GLenum target, GLuint id, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGENPROGRAMSNVPROC)(GLsizei n, GLuint* programs);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMPARAMETERDVNVPROC)(GLenum target, GLuint index, GLenum pname, GLdouble* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMPARAMETERFVNVPROC)(GLenum target, GLuint index, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMIVNVPROC)(GLuint id, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMSTRINGNVPROC)(GLuint id, GLenum pname, GLubyte* program);
typedef void (GLAPIENTRYP PFNGLGETTRACKMATRIXIVNVPROC)(GLenum target, GLuint address, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBDVNVPROC)(GLuint index, GLenum pname, GLdouble* params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBFVNVPROC)(GLuint index, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBIVNVPROC)(GLuint index, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBPOINTERVNVPROC)(GLuint index, GLenum pname, GLvoid** pointer);
typedef GLboolean (GLAPIENTRYP PFNGLISPROGRAMNVPROC)(GLuint id);
typedef void (GLAPIENTRYP PFNGLLOADPROGRAMNVPROC)(GLenum target, GLuint id, GLsizei len, const GLubyte* program);
typedef void (GLAPIENTRYP PFNGLPROGRAMPARAMETER4DNVPROC)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLPROGRAMPARAMETER4DVNVPROC)(GLenum target, GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLPROGRAMPARAMETER4FNVPROC)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLPROGRAMPARAMETER4FVNVPROC)(GLenum target, GLuint index, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLPROGRAMPARAMETERS4DVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLPROGRAMPARAMETERS4FVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLREQUESTRESIDENTPROGRAMSNVPROC)(GLsizei n, const GLuint* programs);
typedef void (GLAPIENTRYP PFNGLTRACKMATRIXNVPROC)(GLenum target, GLuint address, GLenum matrix, GLenum transform);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBPOINTERNVPROC)(GLuint index, GLint fsize, GLenum type, GLsizei stride, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1DNVPROC)(GLuint index, GLdouble x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1DVNVPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1FNVPROC)(GLuint index, GLfloat x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1FVNVPROC)(GLuint index, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1SNVPROC)(GLuint index, GLshort x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1SVNVPROC)(GLuint index, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2DNVPROC)(GLuint index, GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2DVNVPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2FNVPROC)(GLuint index, GLfloat x, GLfloat y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2FVNVPROC)(GLuint index, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2SNVPROC)(GLuint index, GLshort x, GLshort y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2SVNVPROC)(GLuint index, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3DNVPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3DVNVPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3FNVPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3FVNVPROC)(GLuint index, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3SNVPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3SVNVPROC)(GLuint index, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4DNVPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4DVNVPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4FNVPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4FVNVPROC)(GLuint index, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4SNVPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4SVNVPROC)(GLuint index, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4UBNVPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4UBVNVPROC)(GLuint index, const GLubyte* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS1DVNVPROC)(GLuint index, GLsizei count, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS1FVNVPROC)(GLuint index, GLsizei count, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS1SVNVPROC)(GLuint index, GLsizei count, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS2DVNVPROC)(GLuint index, GLsizei count, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS2FVNVPROC)(GLuint index, GLsizei count, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS2SVNVPROC)(GLuint index, GLsizei count, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS3DVNVPROC)(GLuint index, GLsizei count, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS3FVNVPROC)(GLuint index, GLsizei count, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS3SVNVPROC)(GLuint index, GLsizei count, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS4DVNVPROC)(GLuint index, GLsizei count, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS4FVNVPROC)(GLuint index, GLsizei count, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS4SVNVPROC)(GLuint index, GLsizei count, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS4UBVNVPROC)(GLuint index, GLsizei count, const GLubyte* v);
#endif


#ifndef GL_NV_vertex_program4
#define GL_NV_vertex_program4 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glVertexAttribI1iEXT(GLuint index, GLint x);
GLAPI void GLAPIENTRY glVertexAttribI2iEXT(GLuint index, GLint x, GLint y);
GLAPI void GLAPIENTRY glVertexAttribI3iEXT(GLuint index, GLint x, GLint y, GLint z);
GLAPI void GLAPIENTRY glVertexAttribI4iEXT(GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void GLAPIENTRY glVertexAttribI1uiEXT(GLuint index, GLuint x);
GLAPI void GLAPIENTRY glVertexAttribI2uiEXT(GLuint index, GLuint x, GLuint y);
GLAPI void GLAPIENTRY glVertexAttribI3uiEXT(GLuint index, GLuint x, GLuint y, GLuint z);
GLAPI void GLAPIENTRY glVertexAttribI4uiEXT(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void GLAPIENTRY glVertexAttribI1ivEXT(GLuint index, const GLint* v);
GLAPI void GLAPIENTRY glVertexAttribI2ivEXT(GLuint index, const GLint* v);
GLAPI void GLAPIENTRY glVertexAttribI3ivEXT(GLuint index, const GLint* v);
GLAPI void GLAPIENTRY glVertexAttribI4ivEXT(GLuint index, const GLint* v);
GLAPI void GLAPIENTRY glVertexAttribI1uivEXT(GLuint index, const GLuint* v);
GLAPI void GLAPIENTRY glVertexAttribI2uivEXT(GLuint index, const GLuint* v);
GLAPI void GLAPIENTRY glVertexAttribI3uivEXT(GLuint index, const GLuint* v);
GLAPI void GLAPIENTRY glVertexAttribI4uivEXT(GLuint index, const GLuint* v);
GLAPI void GLAPIENTRY glVertexAttribI4bvEXT(GLuint index, const GLbyte* v);
GLAPI void GLAPIENTRY glVertexAttribI4svEXT(GLuint index, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttribI4ubvEXT(GLuint index, const GLubyte* v);
GLAPI void GLAPIENTRY glVertexAttribI4usvEXT(GLuint index, const GLushort* v);
GLAPI void GLAPIENTRY glVertexAttribIPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
GLAPI void GLAPIENTRY glGetVertexAttribIivEXT(GLuint index, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetVertexAttribIuivEXT(GLuint index, GLenum pname, GLuint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI1IEXTPROC)(GLuint index, GLint x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI2IEXTPROC)(GLuint index, GLint x, GLint y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI3IEXTPROC)(GLuint index, GLint x, GLint y, GLint z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4IEXTPROC)(GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI1UIEXTPROC)(GLuint index, GLuint x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI2UIEXTPROC)(GLuint index, GLuint x, GLuint y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI3UIEXTPROC)(GLuint index, GLuint x, GLuint y, GLuint z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4UIEXTPROC)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI1IVEXTPROC)(GLuint index, const GLint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI2IVEXTPROC)(GLuint index, const GLint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI3IVEXTPROC)(GLuint index, const GLint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4IVEXTPROC)(GLuint index, const GLint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI1UIVEXTPROC)(GLuint index, const GLuint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI2UIVEXTPROC)(GLuint index, const GLuint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI3UIVEXTPROC)(GLuint index, const GLuint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4UIVEXTPROC)(GLuint index, const GLuint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4BVEXTPROC)(GLuint index, const GLbyte* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4SVEXTPROC)(GLuint index, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4UBVEXTPROC)(GLuint index, const GLubyte* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4USVEXTPROC)(GLuint index, const GLushort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBIPOINTEREXTPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBIIVEXTPROC)(GLuint index, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBIUIVEXTPROC)(GLuint index, GLenum pname, GLuint* params);
#endif


#ifndef GL_NV_video_capture
#define GL_NV_video_capture 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBeginVideoCaptureNV(GLuint video_capture_slot);
GLAPI void GLAPIENTRY glBindVideoCaptureStreamBufferNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptr offset);
GLAPI void GLAPIENTRY glBindVideoCaptureStreamTextureNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture);
GLAPI void GLAPIENTRY glEndVideoCaptureNV(GLuint video_capture_slot);
GLAPI void GLAPIENTRY glGetVideoCaptureivNV(GLuint video_capture_slot, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetVideoCaptureStreamivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetVideoCaptureStreamfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetVideoCaptureStreamdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble* params);
GLAPI GLenum GLAPIENTRY glVideoCaptureNV(GLuint video_capture_slot, GLuint* sequence_num, GLuint64EXT* capture_time);
GLAPI void GLAPIENTRY glVideoCaptureStreamParameterivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glVideoCaptureStreamParameterfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glVideoCaptureStreamParameterdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBEGINVIDEOCAPTURENVPROC)(GLuint video_capture_slot);
typedef void (GLAPIENTRYP PFNGLBINDVIDEOCAPTURESTREAMBUFFERNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLBINDVIDEOCAPTURESTREAMTEXTURENVPROC)(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture);
typedef void (GLAPIENTRYP PFNGLENDVIDEOCAPTURENVPROC)(GLuint video_capture_slot);
typedef void (GLAPIENTRYP PFNGLGETVIDEOCAPTUREIVNVPROC)(GLuint video_capture_slot, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETVIDEOCAPTURESTREAMIVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETVIDEOCAPTURESTREAMFVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETVIDEOCAPTURESTREAMDVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble* params);
typedef GLenum (GLAPIENTRYP PFNGLVIDEOCAPTURENVPROC)(GLuint video_capture_slot, GLuint* sequence_num, GLuint64EXT* capture_time);
typedef void (GLAPIENTRYP PFNGLVIDEOCAPTURESTREAMPARAMETERIVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLVIDEOCAPTURESTREAMPARAMETERFVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLVIDEOCAPTURESTREAMPARAMETERDVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble* params);
#endif


#ifndef GL_NV_viewport_array
#define GL_NV_viewport_array 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glViewportArrayvNV(GLuint first, GLsizei count, const GLfloat* v);
GLAPI void GLAPIENTRY glViewportIndexedfNV(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
GLAPI void GLAPIENTRY glViewportIndexedfvNV(GLuint index, const GLfloat* v);
GLAPI void GLAPIENTRY glScissorArrayvNV(GLuint first, GLsizei count, const GLint* v);
GLAPI void GLAPIENTRY glScissorIndexedNV(GLuint index, GLint left, GLint bottom, GLint width, GLint height);
GLAPI void GLAPIENTRY glScissorIndexedvNV(GLuint index, const GLint* v);
GLAPI void GLAPIENTRY glDepthRangeArrayfvNV(GLuint first, GLsizei count, const GLfloat* v);
GLAPI void GLAPIENTRY glDepthRangeIndexedfNV(GLuint index, GLfloat n, GLfloat f);
GLAPI void GLAPIENTRY glGetFloati_vNV(GLenum target, GLuint index, GLfloat* v);
GLAPI void GLAPIENTRY glEnableiNV(GLenum target, GLuint index);
GLAPI void GLAPIENTRY glDisableiNV(GLenum target, GLuint index);
GLAPI GLboolean GLAPIENTRY glIsEnablediNV(GLenum target, GLuint index);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLVIEWPORTARRAYVNVPROC)(GLuint first, GLsizei count, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVIEWPORTINDEXEDFNVPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
typedef void (GLAPIENTRYP PFNGLVIEWPORTINDEXEDFVNVPROC)(GLuint index, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLSCISSORARRAYVNVPROC)(GLuint first, GLsizei count, const GLint* v);
typedef void (GLAPIENTRYP PFNGLSCISSORINDEXEDNVPROC)(GLuint index, GLint left, GLint bottom, GLint width, GLint height);
typedef void (GLAPIENTRYP PFNGLSCISSORINDEXEDVNVPROC)(GLuint index, const GLint* v);
typedef void (GLAPIENTRYP PFNGLDEPTHRANGEARRAYFVNVPROC)(GLuint first, GLsizei count, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLDEPTHRANGEINDEXEDFNVPROC)(GLuint index, GLfloat n, GLfloat f);
typedef void (GLAPIENTRYP PFNGLGETFLOATI_VNVPROC)(GLenum target, GLuint index, GLfloat* v);
typedef void (GLAPIENTRYP PFNGLENABLEINVPROC)(GLenum target, GLuint index);
typedef void (GLAPIENTRYP PFNGLDISABLEINVPROC)(GLenum target, GLuint index);
typedef GLboolean (GLAPIENTRYP PFNGLISENABLEDINVPROC)(GLenum target, GLuint index);
#endif


#ifndef GL_NVX_cross_process_interop
#define GL_NVX_cross_process_interop 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glCreateTextureExternalStorageNVX(GLenum handleType, const void* handle, GLuint* texture);
GLAPI void GLAPIENTRY glCreateBufferExternalStorageNVX(GLenum handleType, const void* handle, GLuint* buffer);
GLAPI void GLAPIENTRY glGetExternalHandleNVX(GLenum objectType, GLuint object, GLenum handleType, const void** handle);
GLAPI void GLAPIENTRY glGetTextureParameterivNVX(GLuint texture, GLenum pname, GLint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCREATETEXTUREEXTERNALSTORAGENVXPROC)(GLenum handleType, const void* handle, GLuint* texture);
typedef void (GLAPIENTRYP PFNGLCREATEBUFFEREXTERNALSTORAGENVXPROC)(GLenum handleType, const void* handle, GLuint* buffer);
typedef void (GLAPIENTRYP PFNGLGETEXTERNALHANDLENVXPROC)(GLenum objectType, GLuint object, GLenum handleType, const void** handle);
typedef void (GLAPIENTRYP PFNGLGETTEXTUREPARAMETERIVNVXPROC)(GLuint texture, GLenum pname, GLint* params);
#endif


#ifndef GL_OES_draw_buffers_indexed
#define GL_OES_draw_buffers_indexed 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glEnableiOES(GLenum target, GLuint index);
GLAPI void GLAPIENTRY glDisableiOES(GLenum target, GLuint index);
GLAPI void GLAPIENTRY glBlendEquationiOES(GLuint buf, GLenum mode);
GLAPI void GLAPIENTRY glBlendEquationSeparateiOES(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI void GLAPIENTRY glBlendFunciOES(GLuint buf, GLenum src, GLenum dst);
GLAPI void GLAPIENTRY glBlendFuncSeparateiOES(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GLAPI void GLAPIENTRY glColorMaskiOES(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLAPI GLboolean GLAPIENTRY glIsEnablediOES(GLenum target, GLuint index);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLENABLEIOESPROC)(GLenum target, GLuint index);
typedef void (GLAPIENTRYP PFNGLDISABLEIOESPROC)(GLenum target, GLuint index);
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONIOESPROC)(GLuint buf, GLenum mode);
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONSEPARATEIOESPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (GLAPIENTRYP PFNGLBLENDFUNCIOESPROC)(GLuint buf, GLenum src, GLenum dst);
typedef void (GLAPIENTRYP PFNGLBLENDFUNCSEPARATEIOESPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef void (GLAPIENTRYP PFNGLCOLORMASKIOESPROC)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef GLboolean (GLAPIENTRYP PFNGLISENABLEDIOESPROC)(GLenum target, GLuint index);
#endif


#ifndef GL_OES_draw_texture
#define GL_OES_draw_texture 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawTexsOES(GLshort X, GLshort Y, GLshort Z, GLshort W, GLshort H);
GLAPI void GLAPIENTRY glDrawTexiOES(GLint X, GLint Y, GLint Z, GLint W, GLint H);
GLAPI void GLAPIENTRY glDrawTexfOES(GLfloat X, GLfloat Y, GLfloat Z, GLfloat W, GLfloat H);
GLAPI void GLAPIENTRY glDrawTexxOES(GLfixed X, GLfixed Y, GLfixed Z, GLfixed W, GLfixed H);
GLAPI void GLAPIENTRY glDrawTexsvOES(const GLshort* coords);
GLAPI void GLAPIENTRY glDrawTexivOES(const GLint* coords);
GLAPI void GLAPIENTRY glDrawTexfvOES(const GLfloat* coords);
GLAPI void GLAPIENTRY glDrawTexxvOES(const GLfixed* coords);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWTEXSOESPROC)(GLshort X, GLshort Y, GLshort Z, GLshort W, GLshort H);
typedef void (GLAPIENTRYP PFNGLDRAWTEXIOESPROC)(GLint X, GLint Y, GLint Z, GLint W, GLint H);
typedef void (GLAPIENTRYP PFNGLDRAWTEXFOESPROC)(GLfloat X, GLfloat Y, GLfloat Z, GLfloat W, GLfloat H);
typedef void (GLAPIENTRYP PFNGLDRAWTEXXOESPROC)(GLfixed X, GLfixed Y, GLfixed Z, GLfixed W, GLfixed H);
typedef void (GLAPIENTRYP PFNGLDRAWTEXSVOESPROC)(const GLshort* coords);
typedef void (GLAPIENTRYP PFNGLDRAWTEXIVOESPROC)(const GLint* coords);
typedef void (GLAPIENTRYP PFNGLDRAWTEXFVOESPROC)(const GLfloat* coords);
typedef void (GLAPIENTRYP PFNGLDRAWTEXXVOESPROC)(const GLfixed* coords);
#endif


#ifndef GL_OES_EGL_image
#define GL_OES_EGL_image 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glEGLImageTargetTexture2DOES(GLenum target, GLeglImageOES image);
GLAPI void GLAPIENTRY glEGLImageTargetRenderbufferStorageOES(GLenum target, GLeglImageOES image);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLEGLIMAGETARGETTEXTURE2DOESPROC)(GLenum target, GLeglImageOES image);
typedef void (GLAPIENTRYP PFNGLEGLIMAGETARGETRENDERBUFFERSTORAGEOESPROC)(GLenum target, GLeglImageOES image);
#endif


#ifndef GL_OES_framebuffer_object
#define GL_OES_framebuffer_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBindFramebufferOES(GLenum target, GLuint framebuffer);
GLAPI void GLAPIENTRY glBindRenderbufferOES(GLenum target, GLuint renderbuffer);
GLAPI GLenum GLAPIENTRY glCheckFramebufferStatusOES(GLenum target);
GLAPI void GLAPIENTRY glDeleteFramebuffersOES(GLsizei n, const GLuint* framebuffers);
GLAPI void GLAPIENTRY glDeleteRenderbuffersOES(GLsizei n, const GLuint* renderbuffers);
GLAPI void GLAPIENTRY glFramebufferRenderbufferOES(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void GLAPIENTRY glFramebufferTexture2DOES(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void GLAPIENTRY glGenerateMipmapOES(GLenum target);
GLAPI void GLAPIENTRY glGenFramebuffersOES(GLsizei n, GLuint* framebuffers);
GLAPI void GLAPIENTRY glGenRenderbuffersOES(GLsizei n, GLuint* renderbuffers);
GLAPI void GLAPIENTRY glGetFramebufferAttachmentParameterivOES(GLenum target, GLenum attachment, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetRenderbufferParameterivOES(GLenum target, GLenum pname, GLint* params);
GLAPI GLboolean GLAPIENTRY glIsFramebufferOES(GLuint framebuffer);
GLAPI GLboolean GLAPIENTRY glIsRenderbufferOES(GLuint renderbuffer);
GLAPI void GLAPIENTRY glRenderbufferStorageOES(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBINDFRAMEBUFFEROESPROC)(GLenum target, GLuint framebuffer);
typedef void (GLAPIENTRYP PFNGLBINDRENDERBUFFEROESPROC)(GLenum target, GLuint renderbuffer);
typedef GLenum (GLAPIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSOESPROC)(GLenum target);
typedef void (GLAPIENTRYP PFNGLDELETEFRAMEBUFFERSOESPROC)(GLsizei n, const GLuint* framebuffers);
typedef void (GLAPIENTRYP PFNGLDELETERENDERBUFFERSOESPROC)(GLsizei n, const GLuint* renderbuffers);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERRENDERBUFFEROESPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTURE2DOESPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (GLAPIENTRYP PFNGLGENERATEMIPMAPOESPROC)(GLenum target);
typedef void (GLAPIENTRYP PFNGLGENFRAMEBUFFERSOESPROC)(GLsizei n, GLuint* framebuffers);
typedef void (GLAPIENTRYP PFNGLGENRENDERBUFFERSOESPROC)(GLsizei n, GLuint* renderbuffers);
typedef void (GLAPIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVOESPROC)(GLenum target, GLenum attachment, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVOESPROC)(GLenum target, GLenum pname, GLint* params);
typedef GLboolean (GLAPIENTRYP PFNGLISFRAMEBUFFEROESPROC)(GLuint framebuffer);
typedef GLboolean (GLAPIENTRYP PFNGLISRENDERBUFFEROESPROC)(GLuint renderbuffer);
typedef void (GLAPIENTRYP PFNGLRENDERBUFFERSTORAGEOESPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
#endif


#ifndef GL_OES_geometry_shader
#define GL_OES_geometry_shader 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glFramebufferTextureOES(GLenum target, GLenum attachment, GLuint texture, GLint level);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTUREOESPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
#endif


#ifndef GL_OES_get_program_binary
#define GL_OES_get_program_binary 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGetProgramBinaryOES(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, GLvoid* binary);
GLAPI void GLAPIENTRY glProgramBinaryOES(GLuint program, GLenum binaryFormat, const GLvoid* binary, GLsizei length);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGETPROGRAMBINARYOESPROC)(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, GLvoid* binary);
typedef void (GLAPIENTRYP PFNGLPROGRAMBINARYOESPROC)(GLuint program, GLenum binaryFormat, const GLvoid* binary, GLsizei length);
#endif


#ifndef GL_OES_mapbuffer
#define GL_OES_mapbuffer 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGetBufferPointervOES(GLenum target, GLenum pname, GLvoid** params);
GLAPI GLvoid* GLAPIENTRY glMapBufferOES(GLenum target, GLenum access);
GLAPI GLboolean GLAPIENTRY glUnmapBufferOES(GLenum target);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGETBUFFERPOINTERVOESPROC)(GLenum target, GLenum pname, GLvoid** params);
typedef GLvoid* (GLAPIENTRYP PFNGLMAPBUFFEROESPROC)(GLenum target, GLenum access);
typedef GLboolean (GLAPIENTRYP PFNGLUNMAPBUFFEROESPROC)(GLenum target);
#endif


#ifndef GL_OES_point_size_array
#define GL_OES_point_size_array 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPointSizePointerOES(GLenum type, GLsizei stride, const GLvoid* pointer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPOINTSIZEPOINTEROESPROC)(GLenum type, GLsizei stride, const GLvoid* pointer);
#endif


#ifndef GL_OES_sample_shading
#define GL_OES_sample_shading 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glMinSampleShadingOES(GLclampf value);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLMINSAMPLESHADINGOESPROC)(GLclampf value);
#endif


#ifndef GL_OES_single_precision
#define GL_OES_single_precision 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDepthRangefOES(GLclampf zNear, GLclampf zFar);
GLAPI void GLAPIENTRY glFrustumfOES(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
GLAPI void GLAPIENTRY glOrthofOES(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
GLAPI void GLAPIENTRY glClipPlanefOES(GLenum plane, const GLfloat* equation);
GLAPI void GLAPIENTRY glGetClipPlanefOES(GLfloat* eqn);
GLAPI void GLAPIENTRY glClearDepthfOES(GLclampf depth);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDEPTHRANGEFOESPROC)(GLclampf zNear, GLclampf zFar);
typedef void (GLAPIENTRYP PFNGLFRUSTUMFOESPROC)(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
typedef void (GLAPIENTRYP PFNGLORTHOFOESPROC)(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
typedef void (GLAPIENTRYP PFNGLCLIPPLANEFOESPROC)(GLenum plane, const GLfloat* equation);
typedef void (GLAPIENTRYP PFNGLGETCLIPPLANEFOESPROC)(GLfloat* eqn);
typedef void (GLAPIENTRYP PFNGLCLEARDEPTHFOESPROC)(GLclampf depth);
#endif


#ifndef GL_OES_tessellation_shader
#define GL_OES_tessellation_shader 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPatchParameteriOES(GLenum pname, GLint value);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPATCHPARAMETERIOESPROC)(GLenum pname, GLint value);
#endif


#ifndef GL_OES_texture_border_clamp
#define GL_OES_texture_border_clamp 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glSamplerParameterIivOES(GLuint sampler, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glSamplerParameterIuivOES(GLuint sampler, GLenum pname, const GLuint* params);
GLAPI void GLAPIENTRY glGetSamplerParameterIivOES(GLuint sampler, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetSamplerParameterIuivOES(GLuint sampler, GLenum pname, GLuint* params);
GLAPI void GLAPIENTRY glTexParameterIivOES(GLenum target, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glTexParameterIuivOES(GLenum target, GLenum pname, const GLuint* params);
GLAPI void GLAPIENTRY glGetTexParameterIivOES(GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetTexParameterIuivOES(GLenum target, GLenum pname, GLuint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLSAMPLERPARAMETERIIVOESPROC)(GLuint sampler, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLSAMPLERPARAMETERIUIVOESPROC)(GLuint sampler, GLenum pname, const GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETSAMPLERPARAMETERIIVOESPROC)(GLuint sampler, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETSAMPLERPARAMETERIUIVOESPROC)(GLuint sampler, GLenum pname, GLuint* params);
typedef void (GLAPIENTRYP PFNGLTEXPARAMETERIIVOESPROC)(GLenum target, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLTEXPARAMETERIUIVOESPROC)(GLenum target, GLenum pname, const GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETTEXPARAMETERIIVOESPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETTEXPARAMETERIUIVOESPROC)(GLenum target, GLenum pname, GLuint* params);
#endif


#ifndef GL_OES_texture_buffer
#define GL_OES_texture_buffer 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTexBufferOES(GLenum target, GLenum internalformat, GLuint buffer);
GLAPI void GLAPIENTRY glTexBufferRangeOES(GLenum target, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXBUFFEROESPROC)(GLenum target, GLenum internalformat, GLuint buffer);
typedef void (GLAPIENTRYP PFNGLTEXBUFFERRANGEOESPROC)(GLenum target, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#endif


#ifndef GL_OES_texture_cube_map
#define GL_OES_texture_cube_map 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTexGenfOES(GLenum coord, GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glTexGenfvOES(GLenum coord, GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glTexGeniOES(GLenum coord, GLenum pname, GLint param);
GLAPI void GLAPIENTRY glTexGenivOES(GLenum coord, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glTexGenxOES(GLenum coord, GLenum pname, GLfixed param);
GLAPI void GLAPIENTRY glTexGenxvOES(GLenum coord, GLenum pname, const GLfixed* params);
GLAPI void GLAPIENTRY glGetTexGenfvOES(GLenum coord, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetTexGenivOES(GLenum coord, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetTexGenxvOES(GLenum coord, GLenum pname, GLfixed* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXGENFOESPROC)(GLenum coord, GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLTEXGENFVOESPROC)(GLenum coord, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLTEXGENIOESPROC)(GLenum coord, GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLTEXGENIVOESPROC)(GLenum coord, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLTEXGENXOESPROC)(GLenum coord, GLenum pname, GLfixed param);
typedef void (GLAPIENTRYP PFNGLTEXGENXVOESPROC)(GLenum coord, GLenum pname, const GLfixed* params);
typedef void (GLAPIENTRYP PFNGLGETTEXGENFVOESPROC)(GLenum coord, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETTEXGENIVOESPROC)(GLenum coord, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETTEXGENXVOESPROC)(GLenum coord, GLenum pname, GLfixed* params);
#endif


#ifndef GL_OES_texture_storage_multisample_2d_array
#define GL_OES_texture_storage_multisample_2d_array 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTexStorage3DMultisampleOES(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEOESPROC)(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#endif


#ifndef GL_OES_vertex_array_object
#define GL_OES_vertex_array_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBindVertexArrayOES(GLuint array);
GLAPI void GLAPIENTRY glDeleteVertexArraysOES(GLsizei n, const GLuint* arrays);
GLAPI void GLAPIENTRY glGenVertexArraysOES(GLsizei n, GLuint* arrays);
GLAPI GLboolean GLAPIENTRY glIsVertexArrayOES(GLuint array);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBINDVERTEXARRAYOESPROC)(GLuint array);
typedef void (GLAPIENTRYP PFNGLDELETEVERTEXARRAYSOESPROC)(GLsizei n, const GLuint* arrays);
typedef void (GLAPIENTRYP PFNGLGENVERTEXARRAYSOESPROC)(GLsizei n, GLuint* arrays);
typedef GLboolean (GLAPIENTRYP PFNGLISVERTEXARRAYOESPROC)(GLuint array);
#endif


#ifndef GL_OVR_multiview
#define GL_OVR_multiview 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glFramebufferTextureMultiviewOVR(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
#endif


#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
GLAPI void GLAPIENTRY glBlendEquation(GLenum mode);
GLAPI void GLAPIENTRY glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices);
GLAPI void GLAPIENTRY glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid* table);
GLAPI void GLAPIENTRY glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glColorTableParameteriv(GLenum target, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
GLAPI void GLAPIENTRY glGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid* table);
GLAPI void GLAPIENTRY glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetColorTableParameteriv(GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLENDCOLORPROC)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONPROC)(GLenum mode);
typedef void (GLAPIENTRYP PFNGLDRAWRANGEELEMENTSPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices);
typedef void (GLAPIENTRYP PFNGLCOLORTABLEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid* table);
typedef void (GLAPIENTRYP PFNGLCOLORTABLEPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLCOLORTABLEPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLCOPYCOLORTABLEPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (GLAPIENTRYP PFNGLGETCOLORTABLEPROC)(GLenum target, GLenum format, GLenum type, GLvoid* table);
typedef void (GLAPIENTRYP PFNGLGETCOLORTABLEPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETCOLORTABLEPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#endif


#ifdef GL_VERSION_1_2
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glColorSubTableEXT(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid* table);
GLAPI void GLAPIENTRY glColorTableEXT(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid* table);
GLAPI void GLAPIENTRY glGetColorTableEXT(GLenum target, GLenum format, GLenum type, GLvoid* table);
GLAPI void GLAPIENTRY glGetColorTableParameterfvEXT(GLenum target, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetColorTableParameterivEXT(GLenum target, GLenum pname, GLint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOLORSUBTABLEEXTPROC)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid* table);
typedef void (GLAPIENTRYP PFNGLCOLORTABLEEXTPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid* table);
typedef void (GLAPIENTRYP PFNGLGETCOLORTABLEEXTPROC)(GLenum target, GLenum format, GLenum type, GLvoid* table);
typedef void (GLAPIENTRYP PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)(GLenum target, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint* params);
#endif


#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glActiveTexture(GLenum texture);
GLAPI void GLAPIENTRY glClientActiveTexture(GLenum texture);
GLAPI void GLAPIENTRY glMultiTexCoord1d(GLenum target, GLdouble s);
GLAPI void GLAPIENTRY glMultiTexCoord1dv(GLenum target, const GLdouble* v);
GLAPI void GLAPIENTRY glMultiTexCoord1f(GLenum target, GLfloat s);
GLAPI void GLAPIENTRY glMultiTexCoord1fv(GLenum target, const GLfloat* v);
GLAPI void GLAPIENTRY glMultiTexCoord1i(GLenum target, GLint s);
GLAPI void GLAPIENTRY glMultiTexCoord1iv(GLenum target, const GLint* v);
GLAPI void GLAPIENTRY glMultiTexCoord1s(GLenum target, GLshort s);
GLAPI void GLAPIENTRY glMultiTexCoord1sv(GLenum target, const GLshort* v);
GLAPI void GLAPIENTRY glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t);
GLAPI void GLAPIENTRY glMultiTexCoord2dv(GLenum target, const GLdouble* v);
GLAPI void GLAPIENTRY glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t);
GLAPI void GLAPIENTRY glMultiTexCoord2fv(GLenum target, const GLfloat* v);
GLAPI void GLAPIENTRY glMultiTexCoord2i(GLenum target, GLint s, GLint t);
GLAPI void GLAPIENTRY glMultiTexCoord2iv(GLenum target, const GLint* v);
GLAPI void GLAPIENTRY glMultiTexCoord2s(GLenum target, GLshort s, GLshort t);
GLAPI void GLAPIENTRY glMultiTexCoord2sv(GLenum target, const GLshort* v);
GLAPI void GLAPIENTRY glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r);
GLAPI void GLAPIENTRY glMultiTexCoord3dv(GLenum target, const GLdouble* v);
GLAPI void GLAPIENTRY glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r);
GLAPI void GLAPIENTRY glMultiTexCoord3fv(GLenum target, const GLfloat* v);
GLAPI void GLAPIENTRY glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r);
GLAPI void GLAPIENTRY glMultiTexCoord3iv(GLenum target, const GLint* v);
GLAPI void GLAPIENTRY glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r);
GLAPI void GLAPIENTRY glMultiTexCoord3sv(GLenum target, const GLshort* v);
GLAPI void GLAPIENTRY glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
GLAPI void GLAPIENTRY glMultiTexCoord4dv(GLenum target, const GLdouble* v);
GLAPI void GLAPIENTRY glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GLAPI void GLAPIENTRY glMultiTexCoord4fv(GLenum target, const GLfloat* v);
GLAPI void GLAPIENTRY glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q);
GLAPI void GLAPIENTRY glMultiTexCoord4iv(GLenum target, const GLint* v);
GLAPI void GLAPIENTRY glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
GLAPI void GLAPIENTRY glMultiTexCoord4sv(GLenum target, const GLshort* v);
GLAPI void GLAPIENTRY glLoadTransposeMatrixf(const GLfloat* m);
GLAPI void GLAPIENTRY glLoadTransposeMatrixd(const GLdouble* m);
GLAPI void GLAPIENTRY glMultTransposeMatrixf(const GLfloat* m);
GLAPI void GLAPIENTRY glMultTransposeMatrixd(const GLdouble* m);
GLAPI void GLAPIENTRY glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* data);
GLAPI void GLAPIENTRY glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data);
GLAPI void GLAPIENTRY glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* data);
GLAPI void GLAPIENTRY glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data);
GLAPI void GLAPIENTRY glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data);
GLAPI void GLAPIENTRY glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* data);
GLAPI void GLAPIENTRY glGetCompressedTexImage(GLenum target, GLint lod, GLvoid* img);
GLAPI void GLAPIENTRY glSampleCoverage(GLclampf value, GLboolean invert);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLACTIVETEXTUREPROC)(GLenum texture);
typedef void (GLAPIENTRYP PFNGLCLIENTACTIVETEXTUREPROC)(GLenum texture);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1DPROC)(GLenum target, GLdouble s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1DVPROC)(GLenum target, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1FPROC)(GLenum target, GLfloat s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1FVPROC)(GLenum target, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1IPROC)(GLenum target, GLint s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1IVPROC)(GLenum target, const GLint* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1SPROC)(GLenum target, GLshort s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1SVPROC)(GLenum target, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2DPROC)(GLenum target, GLdouble s, GLdouble t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2DVPROC)(GLenum target, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2FPROC)(GLenum target, GLfloat s, GLfloat t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2FVPROC)(GLenum target, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2IPROC)(GLenum target, GLint s, GLint t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2IVPROC)(GLenum target, const GLint* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2SPROC)(GLenum target, GLshort s, GLshort t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2SVPROC)(GLenum target, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3DPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3DVPROC)(GLenum target, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3FPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3FVPROC)(GLenum target, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3IPROC)(GLenum target, GLint s, GLint t, GLint r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3IVPROC)(GLenum target, const GLint* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3SPROC)(GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3SVPROC)(GLenum target, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4DPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4DVPROC)(GLenum target, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4FPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4FVPROC)(GLenum target, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4IPROC)(GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4IVPROC)(GLenum target, const GLint* v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4SPROC)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4SVPROC)(GLenum target, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLLOADTRANSPOSEMATRIXFPROC)(const GLfloat* m);
typedef void (GLAPIENTRYP PFNGLLOADTRANSPOSEMATRIXDPROC)(const GLdouble* m);
typedef void (GLAPIENTRYP PFNGLMULTTRANSPOSEMATRIXFPROC)(const GLfloat* m);
typedef void (GLAPIENTRYP PFNGLMULTTRANSPOSEMATRIXDPROC)(const GLdouble* m);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint lod, GLvoid* img);
typedef void (GLAPIENTRYP PFNGLSAMPLECOVERAGEPROC)(GLclampf value, GLboolean invert);
#endif


#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPointParameterf(GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glPointParameterfv(GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glPointParameteri(GLenum pname, GLint param);
GLAPI void GLAPIENTRY glPointParameteriv(GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glWindowPos2d(GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glWindowPos2f(GLfloat x, GLfloat y);
GLAPI void GLAPIENTRY glWindowPos2i(GLint x, GLint y);
GLAPI void GLAPIENTRY glWindowPos2s(GLshort x, GLshort y);
GLAPI void GLAPIENTRY glWindowPos2dv(const GLdouble* p);
GLAPI void GLAPIENTRY glWindowPos2fv(const GLfloat* p);
GLAPI void GLAPIENTRY glWindowPos2iv(const GLint* p);
GLAPI void GLAPIENTRY glWindowPos2sv(const GLshort* p);
GLAPI void GLAPIENTRY glWindowPos3d(GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glWindowPos3f(GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glWindowPos3i(GLint x, GLint y, GLint z);
GLAPI void GLAPIENTRY glWindowPos3s(GLshort x, GLshort y, GLshort z);
GLAPI void GLAPIENTRY glWindowPos3dv(const GLdouble* p);
GLAPI void GLAPIENTRY glWindowPos3fv(const GLfloat* p);
GLAPI void GLAPIENTRY glWindowPos3iv(const GLint* p);
GLAPI void GLAPIENTRY glWindowPos3sv(const GLshort* p);
GLAPI void GLAPIENTRY glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLAPI void GLAPIENTRY glFogCoordd(GLdouble fog);
GLAPI void GLAPIENTRY glFogCoorddv(const GLdouble* fog);
GLAPI void GLAPIENTRY glFogCoordf(GLfloat fog);
GLAPI void GLAPIENTRY glFogCoordfv(const GLfloat* fog);
GLAPI void GLAPIENTRY glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid* pointer);
GLAPI void GLAPIENTRY glMultiDrawArrays(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount);
GLAPI void GLAPIENTRY glMultiDrawElements(GLenum mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei drawcount);
GLAPI void GLAPIENTRY glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue);
GLAPI void GLAPIENTRY glSecondaryColor3bv(const GLbyte* v);
GLAPI void GLAPIENTRY glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue);
GLAPI void GLAPIENTRY glSecondaryColor3dv(const GLdouble* v);
GLAPI void GLAPIENTRY glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue);
GLAPI void GLAPIENTRY glSecondaryColor3fv(const GLfloat* v);
GLAPI void GLAPIENTRY glSecondaryColor3i(GLint red, GLint green, GLint blue);
GLAPI void GLAPIENTRY glSecondaryColor3iv(const GLint* v);
GLAPI void GLAPIENTRY glSecondaryColor3s(GLshort red, GLshort green, GLshort blue);
GLAPI void GLAPIENTRY glSecondaryColor3sv(const GLshort* v);
GLAPI void GLAPIENTRY glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue);
GLAPI void GLAPIENTRY glSecondaryColor3ubv(const GLubyte* v);
GLAPI void GLAPIENTRY glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue);
GLAPI void GLAPIENTRY glSecondaryColor3uiv(const GLuint* v);
GLAPI void GLAPIENTRY glSecondaryColor3us(GLushort red, GLushort green, GLushort blue);
GLAPI void GLAPIENTRY glSecondaryColor3usv(const GLushort* v);
GLAPI void GLAPIENTRY glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERFPROC)(GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERFVPROC)(GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERIPROC)(GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERIVPROC)(GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2DPROC)(GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2FPROC)(GLfloat x, GLfloat y);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2IPROC)(GLint x, GLint y);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2SPROC)(GLshort x, GLshort y);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2DVPROC)(const GLdouble* p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2FVPROC)(const GLfloat* p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2IVPROC)(const GLint* p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2SVPROC)(const GLshort* p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3IPROC)(GLint x, GLint y, GLint z);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3SPROC)(GLshort x, GLshort y, GLshort z);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3DVPROC)(const GLdouble* p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3FVPROC)(const GLfloat* p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3IVPROC)(const GLint* p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3SVPROC)(const GLshort* p);
typedef void (GLAPIENTRYP PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (GLAPIENTRYP PFNGLFOGCOORDDPROC)(GLdouble fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDDVPROC)(const GLdouble* fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDFPROC)(GLfloat fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDFVPROC)(const GLfloat* fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDPOINTERPROC)(GLenum type, GLsizei stride, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWARRAYSPROC)(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWELEMENTSPROC)(GLenum mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei drawcount);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3BVPROC)(const GLbyte* v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3DVPROC)(const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3FVPROC)(const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3IPROC)(GLint red, GLint green, GLint blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3IVPROC)(const GLint* v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3SVPROC)(const GLshort* v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3UBVPROC)(const GLubyte* v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3UIVPROC)(const GLuint* v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3USVPROC)(const GLushort* v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
#endif


#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBindBuffer(GLenum target, GLuint buffer);
GLAPI void GLAPIENTRY glBufferData(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
GLAPI void GLAPIENTRY glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data);
GLAPI void GLAPIENTRY glDeleteBuffers(GLsizei n, const GLuint* buffers);
GLAPI void GLAPIENTRY glGenBuffers(GLsizei n, GLuint* buffers);
GLAPI void GLAPIENTRY glGetBufferParameteriv(GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetBufferPointerv(GLenum target, GLenum pname, GLvoid** params);
GLAPI void GLAPIENTRY glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid* data);
GLAPI GLboolean GLAPIENTRY glIsBuffer(GLuint buffer);
GLAPI GLvoid* GLAPIENTRY glMapBuffer(GLenum target, GLenum access);
GLAPI GLboolean GLAPIENTRY glUnmapBuffer(GLenum target);
GLAPI void GLAPIENTRY glGenQueries(GLsizei n, GLuint* ids);
GLAPI void GLAPIENTRY glDeleteQueries(GLsizei n, const GLuint* ids);
GLAPI GLboolean GLAPIENTRY glIsQuery(GLuint id);
GLAPI void GLAPIENTRY glBeginQuery(GLenum target, GLuint id);
GLAPI void GLAPIENTRY glEndQuery(GLenum target);
GLAPI void GLAPIENTRY glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params);
GLAPI void GLAPIENTRY glGetQueryiv(GLenum target, GLenum pname, GLint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
typedef void (GLAPIENTRYP PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
typedef void (GLAPIENTRYP PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint* buffers);
typedef void (GLAPIENTRYP PFNGLGENBUFFERSPROC)(GLsizei n, GLuint* buffers);
typedef void (GLAPIENTRYP PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETBUFFERPOINTERVPROC)(GLenum target, GLenum pname, GLvoid** params);
typedef void (GLAPIENTRYP PFNGLGETBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid* data);
typedef GLboolean (GLAPIENTRYP PFNGLISBUFFERPROC)(GLuint buffer);
typedef GLvoid* (GLAPIENTRYP PFNGLMAPBUFFERPROC)(GLenum target, GLenum access);
typedef GLboolean (GLAPIENTRYP PFNGLUNMAPBUFFERPROC)(GLenum target);
typedef void (GLAPIENTRYP PFNGLGENQUERIESPROC)(GLsizei n, GLuint* ids);
typedef void (GLAPIENTRYP PFNGLDELETEQUERIESPROC)(GLsizei n, const GLuint* ids);
typedef GLboolean (GLAPIENTRYP PFNGLISQUERYPROC)(GLuint id);
typedef void (GLAPIENTRYP PFNGLBEGINQUERYPROC)(GLenum target, GLuint id);
typedef void (GLAPIENTRYP PFNGLENDQUERYPROC)(GLenum target);
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTIVPROC)(GLuint id, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTUIVPROC)(GLuint id, GLenum pname, GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETQUERYIVPROC)(GLenum target, GLenum pname, GLint* params);
#endif


#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawBuffers(GLsizei n, const GLenum* bufs);
GLAPI void GLAPIENTRY glVertexAttrib1d(GLuint index, GLdouble x);
GLAPI void GLAPIENTRY glVertexAttrib1dv(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttrib1f(GLuint index, GLfloat x);
GLAPI void GLAPIENTRY glVertexAttrib1fv(GLuint index, const GLfloat* v);
GLAPI void GLAPIENTRY glVertexAttrib1s(GLuint index, GLshort x);
GLAPI void GLAPIENTRY glVertexAttrib1sv(GLuint index, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glVertexAttrib2dv(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y);
GLAPI void GLAPIENTRY glVertexAttrib2fv(GLuint index, const GLfloat* v);
GLAPI void GLAPIENTRY glVertexAttrib2s(GLuint index, GLshort x, GLshort y);
GLAPI void GLAPIENTRY glVertexAttrib2sv(GLuint index, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glVertexAttrib3dv(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glVertexAttrib3fv(GLuint index, const GLfloat* v);
GLAPI void GLAPIENTRY glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z);
GLAPI void GLAPIENTRY glVertexAttrib3sv(GLuint index, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttrib4Nbv(GLuint index, const GLbyte* v);
GLAPI void GLAPIENTRY glVertexAttrib4Niv(GLuint index, const GLint* v);
GLAPI void GLAPIENTRY glVertexAttrib4Nsv(GLuint index, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GLAPI void GLAPIENTRY glVertexAttrib4Nubv(GLuint index, const GLubyte* v);
GLAPI void GLAPIENTRY glVertexAttrib4Nuiv(GLuint index, const GLuint* v);
GLAPI void GLAPIENTRY glVertexAttrib4Nusv(GLuint index, const GLushort* v);
GLAPI void GLAPIENTRY glVertexAttrib4bv(GLuint index, const GLbyte* v);
GLAPI void GLAPIENTRY glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glVertexAttrib4dv(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glVertexAttrib4fv(GLuint index, const GLfloat* v);
GLAPI void GLAPIENTRY glVertexAttrib4iv(GLuint index, const GLint* v);
GLAPI void GLAPIENTRY glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI void GLAPIENTRY glVertexAttrib4sv(GLuint index, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttrib4ubv(GLuint index, const GLubyte* v);
GLAPI void GLAPIENTRY glVertexAttrib4uiv(GLuint index, const GLuint* v);
GLAPI void GLAPIENTRY glVertexAttrib4usv(GLuint index, const GLushort* v);
GLAPI void GLAPIENTRY glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
GLAPI void GLAPIENTRY glEnableVertexAttribArray(GLuint index);
GLAPI void GLAPIENTRY glDisableVertexAttribArray(GLuint index);
GLAPI void GLAPIENTRY glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble* params);
GLAPI void GLAPIENTRY glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetVertexAttribiv(GLuint index, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid** pointer);
GLAPI void GLAPIENTRY glDeleteShader(GLuint shader);
GLAPI void GLAPIENTRY glDetachShader(GLuint program, GLuint shader);
GLAPI GLuint GLAPIENTRY glCreateShader(GLenum type);
GLAPI void GLAPIENTRY glShaderSource(GLuint shader, GLsizei count, const GLchar** string, const GLint* length);
GLAPI void GLAPIENTRY glCompileShader(GLuint shader);
GLAPI GLuint GLAPIENTRY glCreateProgram();
GLAPI void GLAPIENTRY glAttachShader(GLuint program, GLuint shader);
GLAPI void GLAPIENTRY glLinkProgram(GLuint program);
GLAPI void GLAPIENTRY glUseProgram(GLuint program);
GLAPI void GLAPIENTRY glDeleteProgram(GLuint program);
GLAPI void GLAPIENTRY glValidateProgram(GLuint program);
GLAPI void GLAPIENTRY glUniform1f(GLint location, GLfloat v0);
GLAPI void GLAPIENTRY glUniform2f(GLint location, GLfloat v0, GLfloat v1);
GLAPI void GLAPIENTRY glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void GLAPIENTRY glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void GLAPIENTRY glUniform1i(GLint location, GLint v0);
GLAPI void GLAPIENTRY glUniform2i(GLint location, GLint v0, GLint v1);
GLAPI void GLAPIENTRY glUniform3i(GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void GLAPIENTRY glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void GLAPIENTRY glUniform1fv(GLint location, GLsizei count, const GLfloat* value);
GLAPI void GLAPIENTRY glUniform2fv(GLint location, GLsizei count, const GLfloat* value);
GLAPI void GLAPIENTRY glUniform3fv(GLint location, GLsizei count, const GLfloat* value);
GLAPI void GLAPIENTRY glUniform4fv(GLint location, GLsizei count, const GLfloat* value);
GLAPI void GLAPIENTRY glUniform1iv(GLint location, GLsizei count, const GLint* value);
GLAPI void GLAPIENTRY glUniform2iv(GLint location, GLsizei count, const GLint* value);
GLAPI void GLAPIENTRY glUniform3iv(GLint location, GLsizei count, const GLint* value);
GLAPI void GLAPIENTRY glUniform4iv(GLint location, GLsizei count, const GLint* value);
GLAPI void GLAPIENTRY glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI GLboolean GLAPIENTRY glIsShader(GLuint shader);
GLAPI GLboolean GLAPIENTRY glIsProgram(GLuint program);
GLAPI void GLAPIENTRY glGetShaderiv(GLuint shader, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetProgramiv(GLuint program, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders);
GLAPI void GLAPIENTRY glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
GLAPI void GLAPIENTRY glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
GLAPI GLint GLAPIENTRY glGetUniformLocation(GLuint program, const GLchar* name);
GLAPI void GLAPIENTRY glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
GLAPI void GLAPIENTRY glGetUniformfv(GLuint program, GLint location, GLfloat* params);
GLAPI void GLAPIENTRY glGetUniformiv(GLuint program, GLint location, GLint* params);
GLAPI void GLAPIENTRY glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source);
GLAPI void GLAPIENTRY glBindAttribLocation(GLuint program, GLuint index, const GLchar* name);
GLAPI void GLAPIENTRY glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
GLAPI GLint GLAPIENTRY glGetAttribLocation(GLuint program, const GLchar* name);
GLAPI void GLAPIENTRY glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
GLAPI void GLAPIENTRY glStencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass);
GLAPI void GLAPIENTRY glStencilMaskSeparate(GLenum face, GLuint mask);
GLAPI void GLAPIENTRY glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWBUFFERSPROC)(GLsizei n, const GLenum* bufs);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1DPROC)(GLuint index, GLdouble x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1DVPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1FPROC)(GLuint index, GLfloat x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1FVPROC)(GLuint index, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1SPROC)(GLuint index, GLshort x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1SVPROC)(GLuint index, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2DPROC)(GLuint index, GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2DVPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2FPROC)(GLuint index, GLfloat x, GLfloat y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2FVPROC)(GLuint index, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2SPROC)(GLuint index, GLshort x, GLshort y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2SVPROC)(GLuint index, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3DVPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3FVPROC)(GLuint index, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3SPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3SVPROC)(GLuint index, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NBVPROC)(GLuint index, const GLbyte* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NIVPROC)(GLuint index, const GLint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NSVPROC)(GLuint index, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NUBPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NUBVPROC)(GLuint index, const GLubyte* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NUIVPROC)(GLuint index, const GLuint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NUSVPROC)(GLuint index, const GLushort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4BVPROC)(GLuint index, const GLbyte* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4DVPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4FVPROC)(GLuint index, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4IVPROC)(GLuint index, const GLint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4SPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4SVPROC)(GLuint index, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4UBVPROC)(GLuint index, const GLubyte* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4UIVPROC)(GLuint index, const GLuint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4USVPROC)(GLuint index, const GLushort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void (GLAPIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBDVPROC)(GLuint index, GLenum pname, GLdouble* params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBFVPROC)(GLuint index, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBIVPROC)(GLuint index, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint index, GLenum pname, GLvoid** pointer);
typedef void (GLAPIENTRYP PFNGLDELETESHADERPROC)(GLuint shader);
typedef void (GLAPIENTRYP PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
typedef GLuint (GLAPIENTRYP PFNGLCREATESHADERPROC)(GLenum type);
typedef void (GLAPIENTRYP PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar** string, const GLint* length);
typedef void (GLAPIENTRYP PFNGLCOMPILESHADERPROC)(GLuint shader);
typedef GLuint (GLAPIENTRYP PFNGLCREATEPROGRAMPROC)();
typedef void (GLAPIENTRYP PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
typedef void (GLAPIENTRYP PFNGLLINKPROGRAMPROC)(GLuint program);
typedef void (GLAPIENTRYP PFNGLUSEPROGRAMPROC)(GLuint program);
typedef void (GLAPIENTRYP PFNGLDELETEPROGRAMPROC)(GLuint program);
typedef void (GLAPIENTRYP PFNGLVALIDATEPROGRAMPROC)(GLuint program);
typedef void (GLAPIENTRYP PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);
typedef void (GLAPIENTRYP PFNGLUNIFORM2FPROC)(GLint location, GLfloat v0, GLfloat v1);
typedef void (GLAPIENTRYP PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (GLAPIENTRYP PFNGLUNIFORM4FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (GLAPIENTRYP PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
typedef void (GLAPIENTRYP PFNGLUNIFORM2IPROC)(GLint location, GLint v0, GLint v1);
typedef void (GLAPIENTRYP PFNGLUNIFORM3IPROC)(GLint location, GLint v0, GLint v1, GLint v2);
typedef void (GLAPIENTRYP PFNGLUNIFORM4IPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (GLAPIENTRYP PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef GLboolean (GLAPIENTRYP PFNGLISSHADERPROC)(GLuint shader);
typedef GLboolean (GLAPIENTRYP PFNGLISPROGRAMPROC)(GLuint program);
typedef void (GLAPIENTRYP PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETATTACHEDSHADERSPROC)(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders);
typedef void (GLAPIENTRYP PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef GLint (GLAPIENTRYP PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar* name);
typedef void (GLAPIENTRYP PFNGLGETACTIVEUNIFORMPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
typedef void (GLAPIENTRYP PFNGLGETUNIFORMFVPROC)(GLuint program, GLint location, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETUNIFORMIVPROC)(GLuint program, GLint location, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETSHADERSOURCEPROC)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source);
typedef void (GLAPIENTRYP PFNGLBINDATTRIBLOCATIONPROC)(GLuint program, GLuint index, const GLchar* name);
typedef void (GLAPIENTRYP PFNGLGETACTIVEATTRIBPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
typedef GLint (GLAPIENTRYP PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar* name);
typedef void (GLAPIENTRYP PFNGLSTENCILFUNCSEPARATEPROC)(GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (GLAPIENTRYP PFNGLSTENCILOPSEPARATEPROC)(GLenum face, GLenum fail, GLenum zfail, GLenum zpass);
typedef void (GLAPIENTRYP PFNGLSTENCILMASKSEPARATEPROC)(GLenum face, GLuint mask);
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum modeRGB, GLenum modeAlpha);
#endif


#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#endif


#ifndef GL_VERSION_3_0
#define GL_VERSION_3_0 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glVertexAttribI1i(GLuint index, GLint x);
GLAPI void GLAPIENTRY glVertexAttribI2i(GLuint index, GLint x, GLint y);
GLAPI void GLAPIENTRY glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z);
GLAPI void GLAPIENTRY glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void GLAPIENTRY glVertexAttribI1ui(GLuint index, GLuint x);
GLAPI void GLAPIENTRY glVertexAttribI2ui(GLuint index, GLuint x, GLuint y);
GLAPI void GLAPIENTRY glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z);
GLAPI void GLAPIENTRY glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void GLAPIENTRY glVertexAttribI1iv(GLuint index, const GLint* v);
GLAPI void GLAPIENTRY glVertexAttribI2iv(GLuint index, const GLint* v);
GLAPI void GLAPIENTRY glVertexAttribI3iv(GLuint index, const GLint* v);
GLAPI void GLAPIENTRY glVertexAttribI4iv(GLuint index, const GLint* v);
GLAPI void GLAPIENTRY glVertexAttribI1uiv(GLuint index, const GLuint* v);
GLAPI void GLAPIENTRY glVertexAttribI2uiv(GLuint index, const GLuint* v);
GLAPI void GLAPIENTRY glVertexAttribI3uiv(GLuint index, const GLuint* v);
GLAPI void GLAPIENTRY glVertexAttribI4uiv(GLuint index, const GLuint* v);
GLAPI void GLAPIENTRY glVertexAttribI4bv(GLuint index, const GLbyte* v);
GLAPI void GLAPIENTRY glVertexAttribI4sv(GLuint index, const GLshort* v);
GLAPI void GLAPIENTRY glVertexAttribI4ubv(GLuint index, const GLubyte* v);
GLAPI void GLAPIENTRY glVertexAttribI4usv(GLuint index, const GLushort* v);
GLAPI void GLAPIENTRY glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
GLAPI void GLAPIENTRY glGetVertexAttribIiv(GLuint index, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params);
GLAPI void GLAPIENTRY glGetUniformuiv(GLuint program, GLint location, GLuint* params);
GLAPI void GLAPIENTRY glBindFragDataLocation(GLuint program, GLuint color, const GLchar* name);
GLAPI GLint GLAPIENTRY glGetFragDataLocation(GLuint program, const GLchar* name);
GLAPI void GLAPIENTRY glTexParameterIiv(GLenum target, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glTexParameterIuiv(GLenum target, GLenum pname, const GLuint* params);
GLAPI void GLAPIENTRY glGetTexParameterIiv(GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint* params);
GLAPI void GLAPIENTRY glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void GLAPIENTRY glBindBufferBase(GLenum target, GLuint index, GLuint buffer);
GLAPI void GLAPIENTRY glGetBooleani_v(GLenum target, GLuint index, GLboolean* data);
GLAPI void GLAPIENTRY glGetIntegeri_v(GLenum target, GLuint index, GLint* data);
GLAPI GLboolean GLAPIENTRY glIsEnabledi(GLenum target, GLuint index);
GLAPI void GLAPIENTRY glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLAPI void GLAPIENTRY glEnablei(GLenum cap, GLuint index);
GLAPI void GLAPIENTRY glDisablei(GLenum cap, GLuint index);
GLAPI const GLubyte* GLAPIENTRY glGetStringi(GLenum name, GLuint index);
GLAPI void GLAPIENTRY glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI GLboolean GLAPIENTRY glIsRenderbuffer(GLuint renderbuffer);
GLAPI void GLAPIENTRY glBindRenderbuffer(GLenum target, GLuint renderbuffer);
GLAPI void GLAPIENTRY glDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers);
GLAPI void GLAPIENTRY glGenRenderbuffers(GLsizei n, GLuint* renderbuffers);
GLAPI void GLAPIENTRY glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params);
GLAPI GLboolean GLAPIENTRY glIsFramebuffer(GLuint framebuffer);
GLAPI void GLAPIENTRY glBindFramebuffer(GLenum target, GLuint framebuffer);
GLAPI void GLAPIENTRY glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers);
GLAPI void GLAPIENTRY glGenFramebuffers(GLsizei n, GLuint* framebuffers);
GLAPI GLenum GLAPIENTRY glCheckFramebufferStatus(GLenum target);
GLAPI void GLAPIENTRY glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void GLAPIENTRY glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void GLAPIENTRY glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLAPI void GLAPIENTRY glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void GLAPIENTRY glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void GLAPIENTRY glGenerateMipmap(GLenum target);
GLAPI void GLAPIENTRY glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glBindVertexArray(GLuint array);
GLAPI void GLAPIENTRY glDeleteVertexArrays(GLsizei n, const GLuint* arrays);
GLAPI void GLAPIENTRY glGenVertexArrays(GLsizei n, GLuint* arrays);
GLAPI GLboolean GLAPIENTRY glIsVertexArray(GLuint array);
GLAPI GLvoid* GLAPIENTRY glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI GLvoid GLAPIENTRY glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length);
GLAPI void GLAPIENTRY glBeginConditionalRender(GLuint id, GLenum mode);
GLAPI void GLAPIENTRY glEndConditionalRender();
GLAPI void GLAPIENTRY glBeginTransformFeedback(GLenum primitiveMode);
GLAPI void GLAPIENTRY glEndTransformFeedback();
GLAPI void GLAPIENTRY glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar** varyings, GLenum bufferMode);
GLAPI void GLAPIENTRY glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
GLAPI void GLAPIENTRY glUniform1ui(GLint location, GLuint v0);
GLAPI void GLAPIENTRY glUniform2ui(GLint location, GLuint v0, GLuint v1);
GLAPI void GLAPIENTRY glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void GLAPIENTRY glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void GLAPIENTRY glUniform1uiv(GLint location, GLsizei count, const GLuint* value);
GLAPI void GLAPIENTRY glUniform2uiv(GLint location, GLsizei count, const GLuint* value);
GLAPI void GLAPIENTRY glUniform3uiv(GLint location, GLsizei count, const GLuint* value);
GLAPI void GLAPIENTRY glUniform4uiv(GLint location, GLsizei count, const GLuint* value);
GLAPI void GLAPIENTRY glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLAPI void GLAPIENTRY glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value);
GLAPI void GLAPIENTRY glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint* value);
GLAPI void GLAPIENTRY glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint* value);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI1IPROC)(GLuint index, GLint x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI2IPROC)(GLuint index, GLint x, GLint y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI3IPROC)(GLuint index, GLint x, GLint y, GLint z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4IPROC)(GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI1UIPROC)(GLuint index, GLuint x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI2UIPROC)(GLuint index, GLuint x, GLuint y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI3UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI1IVPROC)(GLuint index, const GLint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI2IVPROC)(GLuint index, const GLint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI3IVPROC)(GLuint index, const GLint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4IVPROC)(GLuint index, const GLint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI1UIVPROC)(GLuint index, const GLuint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI2UIVPROC)(GLuint index, const GLuint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI3UIVPROC)(GLuint index, const GLuint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4UIVPROC)(GLuint index, const GLuint* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4BVPROC)(GLuint index, const GLbyte* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4SVPROC)(GLuint index, const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4UBVPROC)(GLuint index, const GLubyte* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4USVPROC)(GLuint index, const GLushort* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBIIVPROC)(GLuint index, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint index, GLenum pname, GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETUNIFORMUIVPROC)(GLuint program, GLint location, GLuint* params);
typedef void (GLAPIENTRYP PFNGLBINDFRAGDATALOCATIONPROC)(GLuint program, GLuint color, const GLchar* name);
typedef GLint (GLAPIENTRYP PFNGLGETFRAGDATALOCATIONPROC)(GLuint program, const GLchar* name);
typedef void (GLAPIENTRYP PFNGLTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, const GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, GLuint* params);
typedef void (GLAPIENTRYP PFNGLBINDBUFFERRANGEPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (GLAPIENTRYP PFNGLBINDBUFFERBASEPROC)(GLenum target, GLuint index, GLuint buffer);
typedef void (GLAPIENTRYP PFNGLGETBOOLEANI_VPROC)(GLenum target, GLuint index, GLboolean* data);
typedef void (GLAPIENTRYP PFNGLGETINTEGERI_VPROC)(GLenum target, GLuint index, GLint* data);
typedef GLboolean (GLAPIENTRYP PFNGLISENABLEDIPROC)(GLenum target, GLuint index);
typedef void (GLAPIENTRYP PFNGLCOLORMASKIPROC)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void (GLAPIENTRYP PFNGLENABLEIPROC)(GLenum cap, GLuint index);
typedef void (GLAPIENTRYP PFNGLDISABLEIPROC)(GLenum cap, GLuint index);
typedef const GLubyte* (GLAPIENTRYP PFNGLGETSTRINGIPROC)(GLenum name, GLuint index);
typedef void (GLAPIENTRYP PFNGLBLITFRAMEBUFFERPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef GLboolean (GLAPIENTRYP PFNGLISRENDERBUFFERPROC)(GLuint renderbuffer);
typedef void (GLAPIENTRYP PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
typedef void (GLAPIENTRYP PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint* renderbuffers);
typedef void (GLAPIENTRYP PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint* renderbuffers);
typedef void (GLAPIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
typedef GLboolean (GLAPIENTRYP PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
typedef void (GLAPIENTRYP PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
typedef void (GLAPIENTRYP PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint* framebuffers);
typedef void (GLAPIENTRYP PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint* framebuffers);
typedef GLenum (GLAPIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (GLAPIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target, GLenum attachment, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (GLAPIENTRYP PFNGLGENERATEMIPMAPPROC)(GLenum target);
typedef void (GLAPIENTRYP PFNGLRENDERBUFFERSTORAGEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLBINDVERTEXARRAYPROC)(GLuint array);
typedef void (GLAPIENTRYP PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint* arrays);
typedef void (GLAPIENTRYP PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint* arrays);
typedef GLboolean (GLAPIENTRYP PFNGLISVERTEXARRAYPROC)(GLuint array);
typedef GLvoid* (GLAPIENTRYP PFNGLMAPBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef GLvoid (GLAPIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
typedef void (GLAPIENTRYP PFNGLBEGINCONDITIONALRENDERPROC)(GLuint id, GLenum mode);
typedef void (GLAPIENTRYP PFNGLENDCONDITIONALRENDERPROC)();
typedef void (GLAPIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum primitiveMode);
typedef void (GLAPIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC)();
typedef void (GLAPIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint program, GLsizei count, const GLchar** varyings, GLenum bufferMode);
typedef void (GLAPIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
typedef void (GLAPIENTRYP PFNGLUNIFORM1UIPROC)(GLint location, GLuint v0);
typedef void (GLAPIENTRYP PFNGLUNIFORM2UIPROC)(GLint location, GLuint v0, GLuint v1);
typedef void (GLAPIENTRYP PFNGLUNIFORM3UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (GLAPIENTRYP PFNGLUNIFORM4UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (GLAPIENTRYP PFNGLUNIFORM1UIVPROC)(GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM2UIVPROC)(GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM3UIVPROC)(GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM4UIVPROC)(GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLCLEARBUFFERFIPROC)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef void (GLAPIENTRYP PFNGLCLEARBUFFERFVPROC)(GLenum buffer, GLint drawbuffer, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLCLEARBUFFERIVPROC)(GLenum buffer, GLint drawbuffer, const GLint* value);
typedef void (GLAPIENTRYP PFNGLCLEARBUFFERUIVPROC)(GLenum buffer, GLint drawbuffer, const GLuint* value);
#endif


#ifndef GL_VERSION_3_1
#define GL_VERSION_3_1 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI void GLAPIENTRY glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar** uniformNames, GLuint* uniformIndices);
GLAPI void GLAPIENTRY glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
GLAPI GLuint GLAPIENTRY glGetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName);
GLAPI void GLAPIENTRY glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
GLAPI void GLAPIENTRY glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
GLAPI void GLAPIENTRY glPrimitiveRestartIndex(GLuint index);
GLAPI void GLAPIENTRY glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
GLAPI void GLAPIENTRY glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount);
GLAPI void GLAPIENTRY glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (GLAPIENTRYP PFNGLGETUNIFORMINDICESPROC)(GLuint program, GLsizei uniformCount, const GLchar** uniformNames, GLuint* uniformIndices);
typedef void (GLAPIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
typedef GLuint (GLAPIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar* uniformBlockName);
typedef void (GLAPIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
typedef void (GLAPIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
typedef void (GLAPIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint index);
typedef void (GLAPIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount);
typedef void (GLAPIENTRYP PFNGLTEXBUFFERPROC)(GLenum target, GLenum internalformat, GLuint buffer);
#endif


#ifndef GL_VERSION_3_2
#define GL_VERSION_3_2 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params);
GLAPI void GLAPIENTRY glGetInteger64i_v(GLenum target, GLuint index, GLint64* data);
GLAPI GLboolean GLAPIENTRY glIsSync(GLsync sync);
GLAPI void GLAPIENTRY glDeleteSync(GLsync sync);
GLAPI GLsync GLAPIENTRY glFenceSync(GLenum condition, GLbitfield flags);
GLAPI GLenum GLAPIENTRY glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI void GLAPIENTRY glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI void GLAPIENTRY glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values);
GLAPI void GLAPIENTRY glGetInteger64v(GLenum pname, GLint64* params);
GLAPI void GLAPIENTRY glProvokingVertex(GLenum mode);
GLAPI void GLAPIENTRY glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void GLAPIENTRY glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void GLAPIENTRY glGetMultisamplefv(GLenum pname, GLuint index, GLfloat* val);
GLAPI void GLAPIENTRY glSampleMaski(GLuint index, GLbitfield mask);
GLAPI void GLAPIENTRY glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
GLAPI void GLAPIENTRY glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
GLAPI void GLAPIENTRY glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLint basevertex);
GLAPI void GLAPIENTRY glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei drawcount, const GLint* basevertex);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum target, GLenum pname, GLint64* params);
typedef void (GLAPIENTRYP PFNGLGETINTEGER64I_VPROC)(GLenum target, GLuint index, GLint64* data);
typedef GLboolean (GLAPIENTRYP PFNGLISSYNCPROC)(GLsync sync);
typedef void (GLAPIENTRYP PFNGLDELETESYNCPROC)(GLsync sync);
typedef GLsync (GLAPIENTRYP PFNGLFENCESYNCPROC)(GLenum condition, GLbitfield flags);
typedef GLenum (GLAPIENTRYP PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (GLAPIENTRYP PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (GLAPIENTRYP PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values);
typedef void (GLAPIENTRYP PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64* params);
typedef void (GLAPIENTRYP PFNGLPROVOKINGVERTEXPROC)(GLenum mode);
typedef void (GLAPIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (GLAPIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (GLAPIENTRYP PFNGLGETMULTISAMPLEFVPROC)(GLenum pname, GLuint index, GLfloat* val);
typedef void (GLAPIENTRYP PFNGLSAMPLEMASKIPROC)(GLuint index, GLbitfield mask);
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
typedef void (GLAPIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLint basevertex);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei drawcount, const GLint* basevertex);
#endif


#ifndef GL_VERSION_3_3
#define GL_VERSION_3_3 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGenSamplers(GLsizei count, GLuint* samplers);
GLAPI void GLAPIENTRY glDeleteSamplers(GLsizei count, const GLuint* samplers);
GLAPI GLboolean GLAPIENTRY glIsSampler(GLuint sampler);
GLAPI void GLAPIENTRY glBindSampler(GLuint unit, GLuint sampler);
GLAPI void GLAPIENTRY glSamplerParameteri(GLuint sampler, GLenum pname, GLint param);
GLAPI void GLAPIENTRY glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint* params);
GLAPI void GLAPIENTRY glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* params);
GLAPI void GLAPIENTRY glBindFragDataLocationIndexed(GLuint program, GLuint color, GLuint index, const GLchar* name);
GLAPI GLint GLAPIENTRY glGetFragDataIndex(GLuint program, const GLchar* name);
GLAPI void GLAPIENTRY glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64* params);
GLAPI void GLAPIENTRY glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64* params);
GLAPI void GLAPIENTRY glQueryCounter(GLuint id, GLenum target);
GLAPI void GLAPIENTRY glVertexAttribDivisor(GLuint index, GLuint divisor);
GLAPI void GLAPIENTRY glVertexP2ui(GLenum type, GLuint coords);
GLAPI void GLAPIENTRY glVertexP2uiv(GLenum type, const GLuint* coords);
GLAPI void GLAPIENTRY glVertexP3ui(GLenum type, GLuint coords);
GLAPI void GLAPIENTRY glVertexP3uiv(GLenum type, const GLuint* coords);
GLAPI void GLAPIENTRY glVertexP4ui(GLenum type, GLuint coords);
GLAPI void GLAPIENTRY glVertexP4uiv(GLenum type, const GLuint* coords);
GLAPI void GLAPIENTRY glTexCoordP1ui(GLenum type, GLuint coords);
GLAPI void GLAPIENTRY glTexCoordP1uiv(GLenum type, const GLuint* coords);
GLAPI void GLAPIENTRY glTexCoordP2ui(GLenum type, GLuint coords);
GLAPI void GLAPIENTRY glTexCoordP2uiv(GLenum type, const GLuint* coords);
GLAPI void GLAPIENTRY glTexCoordP3ui(GLenum type, GLuint coords);
GLAPI void GLAPIENTRY glTexCoordP3uiv(GLenum type, const GLuint* coords);
GLAPI void GLAPIENTRY glTexCoordP4ui(GLenum type, GLuint coords);
GLAPI void GLAPIENTRY glTexCoordP4uiv(GLenum type, const GLuint* coords);
GLAPI void GLAPIENTRY glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords);
GLAPI void GLAPIENTRY glMultiTexCoordP1uiv(GLenum target, GLenum type, const GLuint* coords);
GLAPI void GLAPIENTRY glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords);
GLAPI void GLAPIENTRY glMultiTexCoordP2uiv(GLenum target, GLenum type, const GLuint* coords);
GLAPI void GLAPIENTRY glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords);
GLAPI void GLAPIENTRY glMultiTexCoordP3uiv(GLenum target, GLenum type, const GLuint* coords);
GLAPI void GLAPIENTRY glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords);
GLAPI void GLAPIENTRY glMultiTexCoordP4uiv(GLenum target, GLenum type, const GLuint* coords);
GLAPI void GLAPIENTRY glNormalP3ui(GLenum type, GLuint coords);
GLAPI void GLAPIENTRY glNormalP3uiv(GLenum type, const GLuint* coords);
GLAPI void GLAPIENTRY glColorP3ui(GLenum type, GLuint color);
GLAPI void GLAPIENTRY glColorP3uiv(GLenum type, const GLuint* color);
GLAPI void GLAPIENTRY glColorP4ui(GLenum type, GLuint color);
GLAPI void GLAPIENTRY glColorP4uiv(GLenum type, const GLuint* color);
GLAPI void GLAPIENTRY glSecondaryColorP3ui(GLenum type, GLuint color);
GLAPI void GLAPIENTRY glSecondaryColorP3uiv(GLenum type, const GLuint* color);
GLAPI void GLAPIENTRY glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void GLAPIENTRY glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
GLAPI void GLAPIENTRY glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void GLAPIENTRY glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
GLAPI void GLAPIENTRY glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void GLAPIENTRY glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
GLAPI void GLAPIENTRY glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void GLAPIENTRY glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGENSAMPLERSPROC)(GLsizei count, GLuint* samplers);
typedef void (GLAPIENTRYP PFNGLDELETESAMPLERSPROC)(GLsizei count, const GLuint* samplers);
typedef GLboolean (GLAPIENTRYP PFNGLISSAMPLERPROC)(GLuint sampler);
typedef void (GLAPIENTRYP PFNGLBINDSAMPLERPROC)(GLuint unit, GLuint sampler);
typedef void (GLAPIENTRYP PFNGLSAMPLERPARAMETERIPROC)(GLuint sampler, GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLSAMPLERPARAMETERFPROC)(GLuint sampler, GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, const GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, GLuint* params);
typedef void (GLAPIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(GLuint program, GLuint color, GLuint index, const GLchar* name);
typedef GLint (GLAPIENTRYP PFNGLGETFRAGDATAINDEXPROC)(GLuint program, const GLchar* name);
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTI64VPROC)(GLuint id, GLenum pname, GLint64* params);
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTUI64VPROC)(GLuint id, GLenum pname, GLuint64* params);
typedef void (GLAPIENTRYP PFNGLQUERYCOUNTERPROC)(GLuint id, GLenum target);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor);
typedef void (GLAPIENTRYP PFNGLVERTEXP2UIPROC)(GLenum type, GLuint coords);
typedef void (GLAPIENTRYP PFNGLVERTEXP2UIVPROC)(GLenum type, const GLuint* coords);
typedef void (GLAPIENTRYP PFNGLVERTEXP3UIPROC)(GLenum type, GLuint coords);
typedef void (GLAPIENTRYP PFNGLVERTEXP3UIVPROC)(GLenum type, const GLuint* coords);
typedef void (GLAPIENTRYP PFNGLVERTEXP4UIPROC)(GLenum type, GLuint coords);
typedef void (GLAPIENTRYP PFNGLVERTEXP4UIVPROC)(GLenum type, const GLuint* coords);
typedef void (GLAPIENTRYP PFNGLTEXCOORDP1UIPROC)(GLenum type, GLuint coords);
typedef void (GLAPIENTRYP PFNGLTEXCOORDP1UIVPROC)(GLenum type, const GLuint* coords);
typedef void (GLAPIENTRYP PFNGLTEXCOORDP2UIPROC)(GLenum type, GLuint coords);
typedef void (GLAPIENTRYP PFNGLTEXCOORDP2UIVPROC)(GLenum type, const GLuint* coords);
typedef void (GLAPIENTRYP PFNGLTEXCOORDP3UIPROC)(GLenum type, GLuint coords);
typedef void (GLAPIENTRYP PFNGLTEXCOORDP3UIVPROC)(GLenum type, const GLuint* coords);
typedef void (GLAPIENTRYP PFNGLTEXCOORDP4UIPROC)(GLenum type, GLuint coords);
typedef void (GLAPIENTRYP PFNGLTEXCOORDP4UIVPROC)(GLenum type, const GLuint* coords);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDP1UIPROC)(GLenum texture, GLenum type, GLuint coords);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDP1UIVPROC)(GLenum target, GLenum type, const GLuint* coords);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDP2UIPROC)(GLenum texture, GLenum type, GLuint coords);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDP2UIVPROC)(GLenum target, GLenum type, const GLuint* coords);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDP3UIPROC)(GLenum texture, GLenum type, GLuint coords);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDP3UIVPROC)(GLenum target, GLenum type, const GLuint* coords);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDP4UIPROC)(GLenum texture, GLenum type, GLuint coords);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDP4UIVPROC)(GLenum target, GLenum type, const GLuint* coords);
typedef void (GLAPIENTRYP PFNGLNORMALP3UIPROC)(GLenum type, GLuint coords);
typedef void (GLAPIENTRYP PFNGLNORMALP3UIVPROC)(GLenum type, const GLuint* coords);
typedef void (GLAPIENTRYP PFNGLCOLORP3UIPROC)(GLenum type, GLuint color);
typedef void (GLAPIENTRYP PFNGLCOLORP3UIVPROC)(GLenum type, const GLuint* color);
typedef void (GLAPIENTRYP PFNGLCOLORP4UIPROC)(GLenum type, GLuint color);
typedef void (GLAPIENTRYP PFNGLCOLORP4UIVPROC)(GLenum type, const GLuint* color);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLORP3UIPROC)(GLenum type, GLuint color);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLORP3UIVPROC)(GLenum type, const GLuint* color);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBP1UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBP1UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBP2UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBP2UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBP3UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBP3UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBP4UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBP4UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
#endif


#ifndef GL_VERSION_4_0
#define GL_VERSION_4_0 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlendEquationi(GLuint buf, GLenum mode);
GLAPI void GLAPIENTRY glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI void GLAPIENTRY glBlendFunci(GLuint buf, GLenum src, GLenum dst);
GLAPI void GLAPIENTRY glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GLAPI void GLAPIENTRY glDrawArraysIndirect(GLenum mode, const GLvoid* indirect);
GLAPI void GLAPIENTRY glDrawElementsIndirect(GLenum mode, GLenum type, const GLvoid* indirect);
GLAPI void GLAPIENTRY glUniform1d(GLint location, GLdouble x);
GLAPI void GLAPIENTRY glUniform2d(GLint location, GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glUniform1dv(GLint location, GLsizei count, const GLdouble* value);
GLAPI void GLAPIENTRY glUniform2dv(GLint location, GLsizei count, const GLdouble* value);
GLAPI void GLAPIENTRY glUniform3dv(GLint location, GLsizei count, const GLdouble* value);
GLAPI void GLAPIENTRY glUniform4dv(GLint location, GLsizei count, const GLdouble* value);
GLAPI void GLAPIENTRY glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glGetUniformdv(GLuint program, GLint location, GLdouble* params);
GLAPI void GLAPIENTRY glMinSampleShading(GLclampf value);
GLAPI void GLAPIENTRY glPatchParameteri(GLenum pname, GLint value);
GLAPI void GLAPIENTRY glPatchParameterfv(GLenum pname, const GLfloat* values);
GLAPI void GLAPIENTRY glGenTransformFeedbacks(GLsizei n, GLuint* ids);
GLAPI void GLAPIENTRY glDeleteTransformFeedbacks(GLsizei n, const GLuint* ids);
GLAPI void GLAPIENTRY glBindTransformFeedback(GLenum target, GLuint id);
GLAPI GLboolean GLAPIENTRY glIsTransformFeedback(GLuint id);
GLAPI void GLAPIENTRY glPauseTransformFeedback();
GLAPI void GLAPIENTRY glResumeTransformFeedback();
GLAPI void GLAPIENTRY glDrawTransformFeedback(GLenum mode, GLuint name);
GLAPI void GLAPIENTRY glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream);
GLAPI void GLAPIENTRY glBeginQueryIndexed(GLenum target, GLuint index, GLuint id);
GLAPI void GLAPIENTRY glEndQueryIndexed(GLenum target, GLuint index);
GLAPI void GLAPIENTRY glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint* params);
GLAPI GLint GLAPIENTRY glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar* name);
GLAPI GLuint GLAPIENTRY glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar* name);
GLAPI void GLAPIENTRY glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
GLAPI void GLAPIENTRY glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
GLAPI void GLAPIENTRY glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name);
GLAPI void GLAPIENTRY glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint* indices);
GLAPI void GLAPIENTRY glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params);
GLAPI void GLAPIENTRY glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint* values);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONIPROC)(GLuint buf, GLenum mode);
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (GLAPIENTRYP PFNGLBLENDFUNCIPROC)(GLuint buf, GLenum src, GLenum dst);
typedef void (GLAPIENTRYP PFNGLBLENDFUNCSEPARATEIPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef void (GLAPIENTRYP PFNGLDRAWARRAYSINDIRECTPROC)(GLenum mode, const GLvoid* indirect);
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const GLvoid* indirect);
typedef void (GLAPIENTRYP PFNGLUNIFORM1DPROC)(GLint location, GLdouble x);
typedef void (GLAPIENTRYP PFNGLUNIFORM2DPROC)(GLint location, GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLUNIFORM3DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLUNIFORM4DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLUNIFORM1DVPROC)(GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM2DVPROC)(GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM3DVPROC)(GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLUNIFORM4DVPROC)(GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLGETUNIFORMDVPROC)(GLuint program, GLint location, GLdouble* params);
typedef void (GLAPIENTRYP PFNGLMINSAMPLESHADINGPROC)(GLclampf value);
typedef void (GLAPIENTRYP PFNGLPATCHPARAMETERIPROC)(GLenum pname, GLint value);
typedef void (GLAPIENTRYP PFNGLPATCHPARAMETERFVPROC)(GLenum pname, const GLfloat* values);
typedef void (GLAPIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint* ids);
typedef void (GLAPIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei n, const GLuint* ids);
typedef void (GLAPIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum target, GLuint id);
typedef GLboolean (GLAPIENTRYP PFNGLISTRANSFORMFEEDBACKPROC)(GLuint id);
typedef void (GLAPIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC)();
typedef void (GLAPIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC)();
typedef void (GLAPIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC)(GLenum mode, GLuint name);
typedef void (GLAPIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)(GLenum mode, GLuint id, GLuint stream);
typedef void (GLAPIENTRYP PFNGLBEGINQUERYINDEXEDPROC)(GLenum target, GLuint index, GLuint id);
typedef void (GLAPIENTRYP PFNGLENDQUERYINDEXEDPROC)(GLenum target, GLuint index);
typedef void (GLAPIENTRYP PFNGLGETQUERYINDEXEDIVPROC)(GLenum target, GLuint index, GLenum pname, GLint* params);
typedef GLint (GLAPIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)(GLuint program, GLenum shadertype, const GLchar* name);
typedef GLuint (GLAPIENTRYP PFNGLGETSUBROUTINEINDEXPROC)(GLuint program, GLenum shadertype, const GLchar* name);
typedef void (GLAPIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
typedef void (GLAPIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
typedef void (GLAPIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name);
typedef void (GLAPIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC)(GLenum shadertype, GLsizei count, const GLuint* indices);
typedef void (GLAPIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC)(GLenum shadertype, GLint location, GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMSTAGEIVPROC)(GLuint program, GLenum shadertype, GLenum pname, GLint* values);
#endif


#ifndef GL_VERSION_4_1
#define GL_VERSION_4_1 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glVertexAttribL1d(GLuint index, GLdouble x);
GLAPI void GLAPIENTRY glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glVertexAttribL1dv(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttribL2dv(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttribL3dv(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttribL4dv(GLuint index, const GLdouble* v);
GLAPI void GLAPIENTRY glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
GLAPI void GLAPIENTRY glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble* params);
GLAPI void GLAPIENTRY glReleaseShaderCompiler();
GLAPI void GLAPIENTRY glShaderBinary(GLsizei count, const GLuint* shaders, GLenum binaryformat, const GLvoid* binary, GLsizei length);
GLAPI void GLAPIENTRY glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
GLAPI void GLAPIENTRY glDepthRangef(GLclampf zNear, GLclampf zFar);
GLAPI void GLAPIENTRY glClearDepthf(GLclampf depth);
GLAPI void GLAPIENTRY glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, GLvoid* binary);
GLAPI void GLAPIENTRY glProgramBinary(GLuint program, GLenum binaryFormat, const GLvoid* binary, GLsizei length);
GLAPI void GLAPIENTRY glProgramParameteri(GLuint program, GLenum pname, GLint value);
GLAPI void GLAPIENTRY glActiveShaderProgram(GLuint pipeline, GLuint program);
GLAPI void GLAPIENTRY glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program);
GLAPI GLuint GLAPIENTRY glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar** strings);
GLAPI void GLAPIENTRY glBindProgramPipeline(GLuint pipeline);
GLAPI void GLAPIENTRY glDeleteProgramPipelines(GLsizei n, const GLuint* pipelines);
GLAPI void GLAPIENTRY glGenProgramPipelines(GLsizei n, GLuint* pipelines);
GLAPI GLboolean GLAPIENTRY glIsProgramPipeline(GLuint pipeline);
GLAPI void GLAPIENTRY glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glValidateProgramPipeline(GLuint pipeline);
GLAPI void GLAPIENTRY glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
GLAPI void GLAPIENTRY glProgramUniform1f(GLuint program, GLint location, GLfloat v0);
GLAPI void GLAPIENTRY glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1);
GLAPI void GLAPIENTRY glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void GLAPIENTRY glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void GLAPIENTRY glProgramUniform1i(GLuint program, GLint location, GLint v0);
GLAPI void GLAPIENTRY glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1);
GLAPI void GLAPIENTRY glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void GLAPIENTRY glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void GLAPIENTRY glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint* value);
GLAPI void GLAPIENTRY glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint* value);
GLAPI void GLAPIENTRY glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint* value);
GLAPI void GLAPIENTRY glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glProgramUniform1ui(GLuint program, GLint location, GLuint v0);
GLAPI void GLAPIENTRY glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1);
GLAPI void GLAPIENTRY glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void GLAPIENTRY glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void GLAPIENTRY glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint* value);
GLAPI void GLAPIENTRY glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint* value);
GLAPI void GLAPIENTRY glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint* value);
GLAPI void GLAPIENTRY glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint* value);
GLAPI void GLAPIENTRY glProgramUniform1d(GLuint program, GLint location, GLdouble x);
GLAPI void GLAPIENTRY glProgramUniform2d(GLuint program, GLint location, GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glProgramUniform3d(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glProgramUniform4d(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
GLAPI void GLAPIENTRY glViewportArrayv(GLuint first, GLsizei count, const GLfloat* v);
GLAPI void GLAPIENTRY glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
GLAPI void GLAPIENTRY glViewportIndexedfv(GLuint index, const GLfloat* v);
GLAPI void GLAPIENTRY glScissorArrayv(GLuint first, GLsizei count, const GLint* v);
GLAPI void GLAPIENTRY glScissorIndexed(GLuint index, GLint left, GLint bottom, GLint width, GLint height);
GLAPI void GLAPIENTRY glScissorIndexedv(GLuint index, const GLint* v);
GLAPI void GLAPIENTRY glDepthRangeArrayv(GLuint first, GLsizei count, const GLclampd* v);
GLAPI void GLAPIENTRY glDepthRangeIndexed(GLuint index, GLclampd n, GLclampd f);
GLAPI void GLAPIENTRY glGetFloati_v(GLenum target, GLuint index, GLfloat* v);
GLAPI void GLAPIENTRY glGetDoublei_v(GLenum target, GLuint index, GLdouble* v);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL1DPROC)(GLuint index, GLdouble x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL2DPROC)(GLuint index, GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL1DVPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL2DVPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL3DVPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBL4DVPROC)(GLuint index, const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBLDVPROC)(GLuint index, GLenum pname, GLdouble* params);
typedef void (GLAPIENTRYP PFNGLRELEASESHADERCOMPILERPROC)();
typedef void (GLAPIENTRYP PFNGLSHADERBINARYPROC)(GLsizei count, const GLuint* shaders, GLenum binaryformat, const GLvoid* binary, GLsizei length);
typedef void (GLAPIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
typedef void (GLAPIENTRYP PFNGLDEPTHRANGEFPROC)(GLclampf zNear, GLclampf zFar);
typedef void (GLAPIENTRYP PFNGLCLEARDEPTHFPROC)(GLclampf depth);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMBINARYPROC)(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, GLvoid* binary);
typedef void (GLAPIENTRYP PFNGLPROGRAMBINARYPROC)(GLuint program, GLenum binaryFormat, const GLvoid* binary, GLsizei length);
typedef void (GLAPIENTRYP PFNGLPROGRAMPARAMETERIPROC)(GLuint program, GLenum pname, GLint value);
typedef void (GLAPIENTRYP PFNGLACTIVESHADERPROGRAMPROC)(GLuint pipeline, GLuint program);
typedef void (GLAPIENTRYP PFNGLUSEPROGRAMSTAGESPROC)(GLuint pipeline, GLbitfield stages, GLuint program);
typedef GLuint (GLAPIENTRYP PFNGLCREATESHADERPROGRAMVPROC)(GLenum type, GLsizei count, const GLchar** strings);
typedef void (GLAPIENTRYP PFNGLBINDPROGRAMPIPELINEPROC)(GLuint pipeline);
typedef void (GLAPIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC)(GLsizei n, const GLuint* pipelines);
typedef void (GLAPIENTRYP PFNGLGENPROGRAMPIPELINESPROC)(GLsizei n, GLuint* pipelines);
typedef GLboolean (GLAPIENTRYP PFNGLISPROGRAMPIPELINEPROC)(GLuint pipeline);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC)(GLuint pipeline, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC)(GLuint pipeline);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1FPROC)(GLuint program, GLint location, GLfloat v0);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1IPROC)(GLuint program, GLint location, GLint v0);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2IPROC)(GLuint program, GLint location, GLint v0, GLint v1);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1IVPROC)(GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2IVPROC)(GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3IVPROC)(GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4IVPROC)(GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1UIPROC)(GLuint program, GLint location, GLuint v0);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1DPROC)(GLuint program, GLint location, GLdouble x);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2DPROC)(GLuint program, GLint location, GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3DPROC)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4DPROC)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM1DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM2DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM3DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORM4DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRYP PFNGLVIEWPORTARRAYVPROC)(GLuint first, GLsizei count, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVIEWPORTINDEXEDFPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
typedef void (GLAPIENTRYP PFNGLVIEWPORTINDEXEDFVPROC)(GLuint index, const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLSCISSORARRAYVPROC)(GLuint first, GLsizei count, const GLint* v);
typedef void (GLAPIENTRYP PFNGLSCISSORINDEXEDPROC)(GLuint index, GLint left, GLint bottom, GLint width, GLint height);
typedef void (GLAPIENTRYP PFNGLSCISSORINDEXEDVPROC)(GLuint index, const GLint* v);
typedef void (GLAPIENTRYP PFNGLDEPTHRANGEARRAYVPROC)(GLuint first, GLsizei count, const GLclampd* v);
typedef void (GLAPIENTRYP PFNGLDEPTHRANGEINDEXEDPROC)(GLuint index, GLclampd n, GLclampd f);
typedef void (GLAPIENTRYP PFNGLGETFLOATI_VPROC)(GLenum target, GLuint index, GLfloat* v);
typedef void (GLAPIENTRYP PFNGLGETDOUBLEI_VPROC)(GLenum target, GLuint index, GLdouble* v);
#endif


#ifndef GL_VERSION_4_2
#define GL_VERSION_4_2 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawTransformFeedbackInstanced(GLenum mode, GLuint name, GLsizei instancecount);
GLAPI void GLAPIENTRY glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
GLAPI void GLAPIENTRY glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
GLAPI void GLAPIENTRY glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLuint baseinstance);
GLAPI void GLAPIENTRY glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
GLAPI void GLAPIENTRY glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void GLAPIENTRY glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void GLAPIENTRY glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
GLAPI void GLAPIENTRY glMemoryBarrier(GLbitfield barriers);
GLAPI void GLAPIENTRY glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint* params);
GLAPI void GLAPIENTRY glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)(GLenum mode, GLuint name, GLsizei instancecount);
typedef void (GLAPIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
typedef void (GLAPIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLuint baseinstance);
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
typedef void (GLAPIENTRYP PFNGLTEXSTORAGE1DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (GLAPIENTRYP PFNGLTEXSTORAGE2DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLTEXSTORAGE3DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (GLAPIENTRYP PFNGLBINDIMAGETEXTUREPROC)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
typedef void (GLAPIENTRYP PFNGLMEMORYBARRIERPROC)(GLbitfield barriers);
typedef void (GLAPIENTRYP PFNGLGETINTERNALFORMATIVPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params);
#endif


#ifndef GL_VERSION_4_3
#define GL_VERSION_4_3 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glClearBufferData(GLenum target, GLenum internalFormat, GLenum format, GLenum type, const GLvoid* data);
GLAPI void GLAPIENTRY glClearBufferSubData(GLenum target, GLenum internalFormat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid* data);
GLAPI void GLAPIENTRY glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
GLAPI void GLAPIENTRY glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
GLAPI void GLAPIENTRY glMultiDrawArraysIndirect(GLenum mode, const GLvoid* indirect, GLsizei drawcount, GLsizei stride);
GLAPI void GLAPIENTRY glMultiDrawElementsIndirect(GLenum mode, GLenum type, const GLvoid* indirect, GLsizei drawcount, GLsizei stride);
GLAPI void GLAPIENTRY glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
GLAPI void GLAPIENTRY glDispatchComputeIndirect(GLintptr indirect);
GLAPI void GLAPIENTRY glFramebufferParameteri(GLenum target, GLenum pname, GLint param);
GLAPI void GLAPIENTRY glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
GLAPI void GLAPIENTRY glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void GLAPIENTRY glInvalidateTexImage(GLuint texture, GLint level);
GLAPI void GLAPIENTRY glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI void GLAPIENTRY glInvalidateBufferData(GLuint buffer);
GLAPI void GLAPIENTRY glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments);
GLAPI void GLAPIENTRY glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar* message);
GLAPI void GLAPIENTRY glPopDebugGroup();
GLAPI void GLAPIENTRY glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
GLAPI void GLAPIENTRY glObjectPtrLabel(GLvoid* ptr, GLsizei length, const GLchar* label);
GLAPI void GLAPIENTRY glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
GLAPI void GLAPIENTRY glGetObjectPtrLabel(GLvoid* ptr, GLsizei bufSize, GLsizei* length, GLchar* label);
GLAPI void GLAPIENTRY glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
GLAPI void GLAPIENTRY glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
GLAPI void GLAPIENTRY glDebugMessageCallback(GLDEBUGPROC callback, GLvoid* userParam);
GLAPI GLuint GLAPIENTRY glGetDebugMessageLog(GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
GLAPI void GLAPIENTRY glGetProgramInterfaceiv(GLuint program, GLenum iface, GLenum pname, GLint* params);
GLAPI GLuint GLAPIENTRY glGetProgramResourceIndex(GLuint program, GLenum iface, const GLchar* name);
GLAPI void GLAPIENTRY glGetProgramResourceName(GLuint program, GLenum iface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
GLAPI void GLAPIENTRY glGetProgramResourceiv(GLuint program, GLenum iface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei bufSize, GLsizei* length, GLint* params);
GLAPI GLint GLAPIENTRY glGetProgramResourceLocation(GLuint program, GLenum iface, const GLchar* name);
GLAPI GLint GLAPIENTRY glGetProgramResourceLocationIndex(GLuint program, GLenum iface, const GLchar* name);
GLAPI void GLAPIENTRY glTexBufferRange(GLenum target, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void GLAPIENTRY glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void GLAPIENTRY glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void GLAPIENTRY glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64* params);
GLAPI void GLAPIENTRY glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void GLAPIENTRY glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void GLAPIENTRY glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void GLAPIENTRY glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void GLAPIENTRY glVertexAttribBinding(GLuint attribindex, GLuint bindingindex);
GLAPI void GLAPIENTRY glVertexBindingDivisor(GLuint bindingindex, GLuint divisor);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCLEARBUFFERDATAPROC)(GLenum target, GLenum internalFormat, GLenum format, GLenum type, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCLEARBUFFERSUBDATAPROC)(GLenum target, GLenum internalFormat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCOPYIMAGESUBDATAPROC)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
typedef void (GLAPIENTRYP PFNGLTEXTUREVIEWPROC)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC)(GLenum mode, const GLvoid* indirect, GLsizei drawcount, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const GLvoid* indirect, GLsizei drawcount, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLDISPATCHCOMPUTEPROC)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
typedef void (GLAPIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC)(GLintptr indirect);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
typedef void (GLAPIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
typedef void (GLAPIENTRYP PFNGLINVALIDATETEXIMAGEPROC)(GLuint texture, GLint level);
typedef void (GLAPIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (GLAPIENTRYP PFNGLINVALIDATEBUFFERDATAPROC)(GLuint buffer);
typedef void (GLAPIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum* attachments);
typedef void (GLAPIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLPUSHDEBUGGROUPPROC)(GLenum source, GLuint id, GLsizei length, const GLchar* message);
typedef void (GLAPIENTRYP PFNGLPOPDEBUGGROUPPROC)();
typedef void (GLAPIENTRYP PFNGLOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
typedef void (GLAPIENTRYP PFNGLOBJECTPTRLABELPROC)(GLvoid* ptr, GLsizei length, const GLchar* label);
typedef void (GLAPIENTRYP PFNGLGETOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
typedef void (GLAPIENTRYP PFNGLGETOBJECTPTRLABELPROC)(GLvoid* ptr, GLsizei bufSize, GLsizei* length, GLchar* label);
typedef void (GLAPIENTRYP PFNGLDEBUGMESSAGECONTROLPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
typedef void (GLAPIENTRYP PFNGLDEBUGMESSAGEINSERTPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
typedef void (GLAPIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC)(GLDEBUGPROC callback, GLvoid* userParam);
typedef GLuint (GLAPIENTRYP PFNGLGETDEBUGMESSAGELOGPROC)(GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint program, GLenum iface, GLenum pname, GLint* params);
typedef GLuint (GLAPIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint program, GLenum iface, const GLchar* name);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint program, GLenum iface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint program, GLenum iface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei bufSize, GLsizei* length, GLint* params);
typedef GLint (GLAPIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint program, GLenum iface, const GLchar* name);
typedef GLint (GLAPIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)(GLuint program, GLenum iface, const GLchar* name);
typedef void (GLAPIENTRYP PFNGLTEXBUFFERRANGEPROC)(GLenum target, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (GLAPIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (GLAPIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (GLAPIENTRYP PFNGLGETINTERNALFORMATI64VPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64* params);
typedef void (GLAPIENTRYP PFNGLBINDVERTEXBUFFERPROC)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBIFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBLFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBBINDINGPROC)(GLuint attribindex, GLuint bindingindex);
typedef void (GLAPIENTRYP PFNGLVERTEXBINDINGDIVISORPROC)(GLuint bindingindex, GLuint divisor);
#endif


#ifdef GL_VERSION_4_3
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glVertexArrayBindVertexBufferEXT(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void GLAPIENTRY glVertexArrayVertexAttribFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void GLAPIENTRY glVertexArrayVertexAttribIFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void GLAPIENTRY glVertexArrayVertexAttribLFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void GLAPIENTRY glVertexArrayVertexAttribBindingEXT(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
GLAPI void GLAPIENTRY glVertexArrayVertexBindingDivisorEXT(GLuint vaobj, GLuint bindingindex, GLuint divisor);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
#endif


#ifndef GL_VERSION_4_4
#define GL_VERSION_4_4 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBufferStorage(GLenum target, GLsizeiptr size, const GLvoid* data, GLbitfield flags);
GLAPI void GLAPIENTRY glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const GLvoid* data);
GLAPI void GLAPIENTRY glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* data);
GLAPI void GLAPIENTRY glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
GLAPI void GLAPIENTRY glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes);
GLAPI void GLAPIENTRY glBindTextures(GLuint first, GLsizei count, const GLuint* textures);
GLAPI void GLAPIENTRY glBindSamplers(GLuint first, GLsizei count, const GLuint* samplers);
GLAPI void GLAPIENTRY glBindImageTextures(GLuint first, GLsizei count, const GLuint* textures);
GLAPI void GLAPIENTRY glBindVertexBuffers(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBUFFERSTORAGEPROC)(GLenum target, GLsizeiptr size, const GLvoid* data, GLbitfield flags);
typedef void (GLAPIENTRYP PFNGLCLEARTEXIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCLEARTEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLBINDBUFFERSBASEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
typedef void (GLAPIENTRYP PFNGLBINDBUFFERSRANGEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes);
typedef void (GLAPIENTRYP PFNGLBINDTEXTURESPROC)(GLuint first, GLsizei count, const GLuint* textures);
typedef void (GLAPIENTRYP PFNGLBINDSAMPLERSPROC)(GLuint first, GLsizei count, const GLuint* samplers);
typedef void (GLAPIENTRYP PFNGLBINDIMAGETEXTURESPROC)(GLuint first, GLsizei count, const GLuint* textures);
typedef void (GLAPIENTRYP PFNGLBINDVERTEXBUFFERSPROC)(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);
#endif


#ifndef GL_VERSION_4_5
#define GL_VERSION_4_5 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glClipControl(GLenum origin, GLenum depth);
GLAPI void GLAPIENTRY glCreateTransformFeedbacks(GLsizei n, GLuint* ids);
GLAPI void GLAPIENTRY glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer);
GLAPI void GLAPIENTRY glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void GLAPIENTRY glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint* param);
GLAPI void GLAPIENTRY glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint* param);
GLAPI void GLAPIENTRY glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64* param);
GLAPI void GLAPIENTRY glCreateBuffers(GLsizei n, GLuint* buffers);
GLAPI void GLAPIENTRY glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const GLvoid* data, GLbitfield flags);
GLAPI void GLAPIENTRY glNamedBufferData(GLuint buffer, GLsizeiptr size, const GLvoid* data, GLenum usage);
GLAPI void GLAPIENTRY glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid* data);
GLAPI void GLAPIENTRY glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI void GLAPIENTRY glClearNamedBufferData(GLuint buffer, GLenum internalFormat, GLenum format, GLenum type, const GLvoid* data);
GLAPI void GLAPIENTRY glClearNamedBufferSubData(GLuint buffer, GLenum internalFormat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid* data);
GLAPI GLvoid* GLAPIENTRY glMapNamedBuffer(GLuint buffer, GLenum access);
GLAPI GLvoid* GLAPIENTRY glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI GLboolean GLAPIENTRY glUnmapNamedBuffer(GLuint buffer);
GLAPI void GLAPIENTRY glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI void GLAPIENTRY glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64* params);
GLAPI void GLAPIENTRY glGetNamedBufferPointerv(GLuint buffer, GLenum pname, GLvoid** params);
GLAPI void GLAPIENTRY glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid* data);
GLAPI void GLAPIENTRY glCreateFramebuffers(GLsizei n, GLuint* framebuffers);
GLAPI void GLAPIENTRY glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void GLAPIENTRY glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param);
GLAPI void GLAPIENTRY glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
GLAPI void GLAPIENTRY glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void GLAPIENTRY glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum mode);
GLAPI void GLAPIENTRY glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum* bufs);
GLAPI void GLAPIENTRY glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum mode);
GLAPI void GLAPIENTRY glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments);
GLAPI void GLAPIENTRY glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value);
GLAPI void GLAPIENTRY glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value);
GLAPI void GLAPIENTRY glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value);
GLAPI void GLAPIENTRY glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLAPI void GLAPIENTRY glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI GLenum GLAPIENTRY glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target);
GLAPI void GLAPIENTRY glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glCreateRenderbuffers(GLsizei n, GLuint* renderbuffers);
GLAPI void GLAPIENTRY glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glCreateTextures(GLenum target, GLsizei n, GLuint* textures);
GLAPI void GLAPIENTRY glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer);
GLAPI void GLAPIENTRY glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLsizeiptr offset, GLsizeiptr range);
GLAPI void GLAPIENTRY glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void GLAPIENTRY glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void GLAPIENTRY glTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
GLAPI void GLAPIENTRY glTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
GLAPI void GLAPIENTRY glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* bits);
GLAPI void GLAPIENTRY glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* bits);
GLAPI void GLAPIENTRY glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* bits);
GLAPI void GLAPIENTRY glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void GLAPIENTRY glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glTextureParameterf(GLuint texture, GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glTextureParameteri(GLuint texture, GLenum pname, GLint param);
GLAPI void GLAPIENTRY glTextureParameterIiv(GLuint texture, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint* params);
GLAPI void GLAPIENTRY glTextureParameteriv(GLuint texture, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glGenerateTextureMipmap(GLuint texture);
GLAPI void GLAPIENTRY glBindTextureUnit(GLuint unit, GLuint texture);
GLAPI void GLAPIENTRY glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
GLAPI void GLAPIENTRY glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, GLvoid* img);
GLAPI void GLAPIENTRY glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint* params);
GLAPI void GLAPIENTRY glGetTextureParameteriv(GLuint texture, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glCreateVertexArrays(GLsizei n, GLuint* arrays);
GLAPI void GLAPIENTRY glDisableVertexArrayAttrib(GLuint vaobj, GLuint index);
GLAPI void GLAPIENTRY glEnableVertexArrayAttrib(GLuint vaobj, GLuint index);
GLAPI void GLAPIENTRY glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer);
GLAPI void GLAPIENTRY glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void GLAPIENTRY glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);
GLAPI void GLAPIENTRY glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void GLAPIENTRY glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void GLAPIENTRY glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void GLAPIENTRY glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
GLAPI void GLAPIENTRY glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor);
GLAPI void GLAPIENTRY glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint* param);
GLAPI void GLAPIENTRY glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint* param);
GLAPI void GLAPIENTRY glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64* param);
GLAPI void GLAPIENTRY glCreateSamplers(GLsizei n, GLuint* samplers);
GLAPI void GLAPIENTRY glCreateProgramPipelines(GLsizei n, GLuint* pipelines);
GLAPI void GLAPIENTRY glCreateQueries(GLenum target, GLsizei n, GLuint* ids);
GLAPI void GLAPIENTRY glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void GLAPIENTRY glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void GLAPIENTRY glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void GLAPIENTRY glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void GLAPIENTRY glMemoryBarrierByRegion(GLbitfield barriers);
GLAPI void GLAPIENTRY glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, GLvoid* img);
GLAPI void GLAPIENTRY glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, GLvoid* img);
GLAPI GLenum GLAPIENTRY glGetGraphicsResetStatus();
GLAPI void GLAPIENTRY glGetnMapdv(GLenum target, GLenum query, GLsizei bufSize, GLdouble* v);
GLAPI void GLAPIENTRY glGetnMapfv(GLenum target, GLenum query, GLsizei bufSize, GLfloat* v);
GLAPI void GLAPIENTRY glGetnMapiv(GLenum target, GLenum query, GLsizei bufSize, GLint* v);
GLAPI void GLAPIENTRY glGetnPixelMapfv(GLenum map, GLsizei bufSize, GLfloat* values);
GLAPI void GLAPIENTRY glGetnPixelMapuiv(GLenum map, GLsizei bufSize, GLuint* values);
GLAPI void GLAPIENTRY glGetnPixelMapusv(GLenum map, GLsizei bufSize, GLushort* values);
GLAPI void GLAPIENTRY glGetnPolygonStipple(GLsizei bufSize, GLubyte* mask);
GLAPI void GLAPIENTRY glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
GLAPI void GLAPIENTRY glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
GLAPI void GLAPIENTRY glGetnColorTable(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid* table);
GLAPI void GLAPIENTRY glGetnConvolutionFilter(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid* image);
GLAPI void GLAPIENTRY glGetnSeparableFilter(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, GLvoid* row, GLsizei columnBufSize, GLvoid* column, GLvoid* span);
GLAPI void GLAPIENTRY glGetnHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid* values);
GLAPI void GLAPIENTRY glGetnMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid* values);
GLAPI void GLAPIENTRY glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, GLvoid* img);
GLAPI void GLAPIENTRY glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
GLAPI void GLAPIENTRY glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint* params);
GLAPI void GLAPIENTRY glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
GLAPI void GLAPIENTRY glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
GLAPI void GLAPIENTRY glTextureBarrier();
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCLIPCONTROLPROC)(GLenum origin, GLenum depth);
typedef void (GLAPIENTRYP PFNGLCREATETRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint* ids);
typedef void (GLAPIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)(GLuint xfb, GLuint index, GLuint buffer);
typedef void (GLAPIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (GLAPIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC)(GLuint xfb, GLenum pname, GLint* param);
typedef void (GLAPIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint* param);
typedef void (GLAPIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint64* param);
typedef void (GLAPIENTRYP PFNGLCREATEBUFFERSPROC)(GLsizei n, GLuint* buffers);
typedef void (GLAPIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC)(GLuint buffer, GLsizeiptr size, const GLvoid* data, GLbitfield flags);
typedef void (GLAPIENTRYP PFNGLNAMEDBUFFERDATAPROC)(GLuint buffer, GLsizeiptr size, const GLvoid* data, GLenum usage);
typedef void (GLAPIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (GLAPIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC)(GLuint buffer, GLenum internalFormat, GLenum format, GLenum type, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLenum internalFormat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid* data);
typedef GLvoid* (GLAPIENTRYP PFNGLMAPNAMEDBUFFERPROC)(GLuint buffer, GLenum access);
typedef GLvoid* (GLAPIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef GLboolean (GLAPIENTRYP PFNGLUNMAPNAMEDBUFFERPROC)(GLuint buffer);
typedef void (GLAPIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (GLAPIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC)(GLuint buffer, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)(GLuint buffer, GLenum pname, GLint64* params);
typedef void (GLAPIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC)(GLuint buffer, GLenum pname, GLvoid** params);
typedef void (GLAPIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCREATEFRAMEBUFFERSPROC)(GLsizei n, GLuint* framebuffers);
typedef void (GLAPIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (GLAPIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)(GLuint framebuffer, GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
typedef void (GLAPIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (GLAPIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)(GLuint framebuffer, GLenum mode);
typedef void (GLAPIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)(GLuint framebuffer, GLsizei n, const GLenum* bufs);
typedef void (GLAPIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)(GLuint framebuffer, GLenum mode);
typedef void (GLAPIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments);
typedef void (GLAPIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value);
typedef void (GLAPIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value);
typedef void (GLAPIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef void (GLAPIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef GLenum (GLAPIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)(GLuint framebuffer, GLenum target);
typedef void (GLAPIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)(GLuint framebuffer, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLCREATERENDERBUFFERSPROC)(GLsizei n, GLuint* renderbuffers);
typedef void (GLAPIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)(GLuint renderbuffer, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLCREATETEXTURESPROC)(GLenum target, GLsizei n, GLuint* textures);
typedef void (GLAPIENTRYP PFNGLTEXTUREBUFFERPROC)(GLuint texture, GLenum internalformat, GLuint buffer);
typedef void (GLAPIENTRYP PFNGLTEXTUREBUFFERRANGEPROC)(GLuint texture, GLenum internalformat, GLuint buffer, GLsizeiptr offset, GLsizeiptr range);
typedef void (GLAPIENTRYP PFNGLTEXTURESTORAGE1DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (GLAPIENTRYP PFNGLTEXTURESTORAGE2DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLTEXTURESTORAGE3DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (GLAPIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
typedef void (GLAPIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
typedef void (GLAPIENTRYP PFNGLTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* bits);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* bits);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* bits);
typedef void (GLAPIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (GLAPIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLTEXTUREPARAMETERFPROC)(GLuint texture, GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLTEXTUREPARAMETERIPROC)(GLuint texture, GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, const GLuint* params);
typedef void (GLAPIENTRYP PFNGLTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC)(GLuint texture);
typedef void (GLAPIENTRYP PFNGLBINDTEXTUREUNITPROC)(GLuint unit, GLuint texture);
typedef void (GLAPIENTRYP PFNGLGETTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLsizei bufSize, GLvoid* img);
typedef void (GLAPIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC)(GLuint texture, GLint level, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC)(GLuint texture, GLint level, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLCREATEVERTEXARRAYSPROC)(GLsizei n, GLuint* arrays);
typedef void (GLAPIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
typedef void (GLAPIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC)(GLuint vaobj, GLuint buffer);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC)(GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
typedef void (GLAPIENTRYP PFNGLGETVERTEXARRAYIVPROC)(GLuint vaobj, GLenum pname, GLint* param);
typedef void (GLAPIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint* param);
typedef void (GLAPIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint64* param);
typedef void (GLAPIENTRYP PFNGLCREATESAMPLERSPROC)(GLsizei n, GLuint* samplers);
typedef void (GLAPIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC)(GLsizei n, GLuint* pipelines);
typedef void (GLAPIENTRYP PFNGLCREATEQUERIESPROC)(GLenum target, GLsizei n, GLuint* ids);
typedef void (GLAPIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC)(GLbitfield barriers);
typedef void (GLAPIENTRYP PFNGLGETTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, GLvoid* img);
typedef void (GLAPIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, GLvoid* img);
typedef GLenum (GLAPIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC)();
typedef void (GLAPIENTRYP PFNGLGETNMAPDVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLdouble* v);
typedef void (GLAPIENTRYP PFNGLGETNMAPFVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLfloat* v);
typedef void (GLAPIENTRYP PFNGLGETNMAPIVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLint* v);
typedef void (GLAPIENTRYP PFNGLGETNPIXELMAPFVPROC)(GLenum map, GLsizei bufSize, GLfloat* values);
typedef void (GLAPIENTRYP PFNGLGETNPIXELMAPUIVPROC)(GLenum map, GLsizei bufSize, GLuint* values);
typedef void (GLAPIENTRYP PFNGLGETNPIXELMAPUSVPROC)(GLenum map, GLsizei bufSize, GLushort* values);
typedef void (GLAPIENTRYP PFNGLGETNPOLYGONSTIPPLEPROC)(GLsizei bufSize, GLubyte* mask);
typedef void (GLAPIENTRYP PFNGLGETNTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLREADNPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLGETNCOLORTABLEPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid* table);
typedef void (GLAPIENTRYP PFNGLGETNCONVOLUTIONFILTERPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid* image);
typedef void (GLAPIENTRYP PFNGLGETNSEPARABLEFILTERPROC)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, GLvoid* row, GLsizei columnBufSize, GLvoid* column, GLvoid* span);
typedef void (GLAPIENTRYP PFNGLGETNHISTOGRAMPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid* values);
typedef void (GLAPIENTRYP PFNGLGETNMINMAXPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid* values);
typedef void (GLAPIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint lod, GLsizei bufSize, GLvoid* img);
typedef void (GLAPIENTRYP PFNGLGETNUNIFORMFVPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETNUNIFORMIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETNUNIFORMUIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
typedef void (GLAPIENTRYP PFNGLGETNUNIFORMDVPROC)(GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
typedef void (GLAPIENTRYP PFNGLTEXTUREBARRIERPROC)();
#endif


#ifndef GL_VERSION_4_6
#define GL_VERSION_4_6 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glMultiDrawArraysIndirectCount(GLenum mode, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLAPI void GLAPIENTRY glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)(GLenum mode, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)(GLenum mode, GLenum type, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#endif


#ifndef GL_WIN_swap_hint
#define GL_WIN_swap_hint 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glAddSwapHintRectWIN(GLint x, GLint y, GLsizei width, GLsizei height);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLADDSWAPHINTRECTWINPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
#endif


/*************************************************************/

/* Version */
#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2                                      1
#endif
#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3                                      1
#endif
#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4                                      1
#endif
#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5                                      1
#endif
#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0                                      1
#endif
#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1                                      1
#endif
#ifndef GL_VERSION_3_0
#define GL_VERSION_3_0                                      1
#endif
#ifndef GL_VERSION_3_1
#define GL_VERSION_3_1                                      1
#endif
#ifndef GL_VERSION_3_2
#define GL_VERSION_3_2                                      1
#endif
#ifndef GL_VERSION_3_3
#define GL_VERSION_3_3                                      1
#endif
#ifndef GL_VERSION_4_0
#define GL_VERSION_4_0                                      1
#endif
#ifndef GL_VERSION_4_1
#define GL_VERSION_4_1                                      1
#endif
#ifndef GL_VERSION_4_2
#define GL_VERSION_4_2                                      1
#endif
#ifndef GL_VERSION_4_3
#define GL_VERSION_4_3                                      1
#endif
#ifndef GL_VERSION_4_4
#define GL_VERSION_4_4                                      1
#endif
#ifndef GL_VERSION_4_5
#define GL_VERSION_4_5                                      1
#endif
#ifndef GL_VERSION_4_6
#define GL_VERSION_4_6                                      1
#endif

/* Extensions */
#ifndef GL_AMD_multi_draw_indirect
#define GL_AMD_multi_draw_indirect                          1
#endif
#ifndef GL_AMD_seamless_cubemap_per_texture
#define GL_AMD_seamless_cubemap_per_texture                 1
#endif
#ifndef GL_AMD_vertex_shader_viewport_index
#define GL_AMD_vertex_shader_viewport_index                 1
#endif
#ifndef GL_AMD_vertex_shader_layer
#define GL_AMD_vertex_shader_layer                          1
#endif
#ifndef GL_ANDROID_extension_pack_es31a
#define GL_ANDROID_extension_pack_es31a                     1
#endif
#ifndef GL_APPLE_transform_hint
#define GL_APPLE_transform_hint                             1
#endif
#ifndef GL_ARB_arrays_of_arrays
#define GL_ARB_arrays_of_arrays                             1
#endif
#ifndef GL_ARB_base_instance
#define GL_ARB_base_instance                                1
#endif
#ifndef GL_ARB_bindless_texture
#define GL_ARB_bindless_texture                             1
#endif
#ifndef GL_ARB_blend_func_extended
#define GL_ARB_blend_func_extended                          1
#endif
#ifndef GL_ARB_buffer_storage
#define GL_ARB_buffer_storage                               1
#endif
#ifndef GL_ARB_clear_buffer_object
#define GL_ARB_clear_buffer_object                          1
#endif
#ifndef GL_ARB_clear_texture
#define GL_ARB_clear_texture                                1
#endif
#ifndef GL_ARB_clip_control
#define GL_ARB_clip_control                                 1
#endif
#ifndef GL_ARB_color_buffer_float
#define GL_ARB_color_buffer_float                           1
#endif
#ifndef GL_ARB_copy_image
#define GL_ARB_copy_image                                   1
#endif
#ifndef GL_ARB_compressed_texture_pixel_storage
#define GL_ARB_compressed_texture_pixel_storage             1
#endif
#ifndef GL_ARB_compute_shader
#define GL_ARB_compute_shader                               1
#endif
#ifndef GL_ARB_compute_variable_group_size
#define GL_ARB_compute_variable_group_size                  1
#endif
#ifndef GL_ARB_conditional_render_inverted
#define GL_ARB_conditional_render_inverted                  1
#endif
#ifndef GL_ARB_conservative_depth
#define GL_ARB_conservative_depth                           1
#endif
#ifndef GL_ARB_copy_buffer
#define GL_ARB_copy_buffer                                  1
#endif
#ifndef GL_ARB_cull_distance
#define GL_ARB_cull_distance                                1
#endif
#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output                                 1
#endif
#ifndef GL_ARB_depth_buffer_float
#define GL_ARB_depth_buffer_float                           1
#endif
#ifndef GL_ARB_depth_clamp
#define GL_ARB_depth_clamp                                  1
#endif
#ifndef GL_ARB_depth_texture
#define GL_ARB_depth_texture                                1
#endif
#ifndef GL_ARB_derivative_control
#define GL_ARB_derivative_control                           1
#endif
#ifndef GL_ARB_direct_state_access
#define GL_ARB_direct_state_access                          1
#endif
#ifndef GL_ARB_draw_buffers
#define GL_ARB_draw_buffers                                 1
#endif
#ifndef GL_ARB_draw_buffers_blend
#define GL_ARB_draw_buffers_blend                           1
#endif
#ifndef GL_ARB_draw_elements_base_vertex
#define GL_ARB_draw_elements_base_vertex                    1
#endif
#ifndef GL_ARB_draw_indirect
#define GL_ARB_draw_indirect                                1
#endif
#ifndef GL_ARB_draw_instanced
#define GL_ARB_draw_instanced                               1
#endif
#ifndef GL_ARB_enhanced_layouts
#define GL_ARB_enhanced_layouts                             1
#endif
#ifndef GL_ARB_ES2_compatibility
#define GL_ARB_ES2_compatibility                            1
#endif
#ifndef GL_ARB_ES3_compatibility
#define GL_ARB_ES3_compatibility                            1
#endif
#ifndef GL_ARB_ES3_1_compatibility
#define GL_ARB_ES3_1_compatibility                          1
#endif
#ifndef GL_ARB_explicit_attrib_location
#define GL_ARB_explicit_attrib_location                     1
#endif
#ifndef GL_ARB_explicit_uniform_location
#define GL_ARB_explicit_uniform_location                    1
#endif
#ifndef GL_ARB_fragment_layer_viewport
#define GL_ARB_fragment_layer_viewport                      1
#endif
#ifndef GL_ARB_fragment_program
#define GL_ARB_fragment_program                             1
#endif
#ifndef GL_ARB_fragment_program_shadow
#define GL_ARB_fragment_program_shadow                      1
#endif
#ifndef GL_ARB_fragment_shader
#define GL_ARB_fragment_shader                              1
#endif
#ifndef GL_ARB_fragment_coord_conventions
#define GL_ARB_fragment_coord_conventions                   1
#endif
#ifndef GL_ARB_framebuffer_no_attachments
#define GL_ARB_framebuffer_no_attachments                   1
#endif
#ifndef GL_ARB_framebuffer_object
#define GL_ARB_framebuffer_object                           1
#endif
#ifndef GL_ARB_framebuffer_sRGB
#define GL_ARB_framebuffer_sRGB                             1
#endif
#ifndef GL_ARB_get_program_binary
#define GL_ARB_get_program_binary                           1
#endif
#ifndef GL_ARB_get_texture_sub_image
#define GL_ARB_get_texture_sub_image                        1
#endif
#ifndef GL_ARB_geometry_shader4
#define GL_ARB_geometry_shader4                             1
#endif
#ifndef GL_ARB_gpu_shader5
#define GL_ARB_gpu_shader5                                  1
#endif
#ifndef GL_ARB_gpu_shader_fp64
#define GL_ARB_gpu_shader_fp64                              1
#endif
#ifndef GL_ARB_half_float_pixel
#define GL_ARB_half_float_pixel                             1
#endif
#ifndef GL_ARB_half_float_vertex
#define GL_ARB_half_float_vertex                            1
#endif
#ifndef GL_ARB_imaging
#define GL_ARB_imaging                                      1
#endif
#ifndef GL_ARB_indirect_parameters
#define GL_ARB_indirect_parameters                          1
#endif
#ifndef GL_ARB_instanced_arrays
#define GL_ARB_instanced_arrays                             1
#endif
#ifndef GL_ARB_internalformat_query
#define GL_ARB_internalformat_query                         1
#endif
#ifndef GL_ARB_internalformat_query2
#define GL_ARB_internalformat_query2                        1
#endif
#ifndef GL_ARB_invalidate_subdata
#define GL_ARB_invalidate_subdata                           1
#endif
#ifndef GL_ARB_map_buffer_alignment
#define GL_ARB_map_buffer_alignment                         1
#endif
#ifndef GL_ARB_map_buffer_range
#define GL_ARB_map_buffer_range                             1
#endif
#ifndef GL_ARB_multi_bind
#define GL_ARB_multi_bind                                   1
#endif
#ifndef GL_ARB_multi_draw_indirect
#define GL_ARB_multi_draw_indirect                          1
#endif
#ifndef GL_ARB_multisample
#define GL_ARB_multisample                                  1
#endif
#ifndef GL_ARB_multitexture
#define GL_ARB_multitexture                                 1
#endif
#ifndef GL_ARB_occlusion_query
#define GL_ARB_occlusion_query                              1
#endif
#ifndef GL_ARB_occlusion_query2
#define GL_ARB_occlusion_query2                             1
#endif
#ifndef GL_ARB_parallel_shader_compile
#define GL_ARB_parallel_shader_compile                      1
#endif
#ifndef GL_ARB_pipeline_statistics_query
#define GL_ARB_pipeline_statistics_query                    1
#endif
#ifndef GL_ARB_pixel_buffer_object
#define GL_ARB_pixel_buffer_object                          1
#endif
#ifndef GL_ARB_point_parameters
#define GL_ARB_point_parameters                             1
#endif
#ifndef GL_ARB_point_sprite
#define GL_ARB_point_sprite                                 1
#endif
#ifndef GL_ARB_program_interface_query
#define GL_ARB_program_interface_query                      1
#endif
#ifndef GL_ARB_provoking_vertex
#define GL_ARB_provoking_vertex                             1
#endif
#ifndef GL_ARB_query_buffer_object
#define GL_ARB_query_buffer_object                          1
#endif
#ifndef GL_ARB_robust_buffer_access_behavior
#define GL_ARB_robust_buffer_access_behavior                1
#endif
#ifndef GL_ARB_robustness
#define GL_ARB_robustness                                   1
#endif
#ifndef GL_ARB_robustness_application_isolation
#define GL_ARB_robustness_application_isolation             1
#endif
#ifndef GL_ARB_sample_shading
#define GL_ARB_sample_shading                               1
#endif
#ifndef GL_ARB_sampler_objects
#define GL_ARB_sampler_objects                              1
#endif
#ifndef GL_ARB_seamless_cube_map
#define GL_ARB_seamless_cube_map                            1
#endif
#ifndef GL_ARB_seamless_cubemap_per_texture
#define GL_ARB_seamless_cubemap_per_texture                 1
#endif
#ifndef GL_ARB_separate_shader_objects
#define GL_ARB_separate_shader_objects                      1
#endif
#ifndef GL_ARB_shader_atomic_counters
#define GL_ARB_shader_atomic_counters                       1
#endif
#ifndef GL_ARB_shader_bit_encoding
#define GL_ARB_shader_bit_encoding                          1
#endif
#ifndef GL_ARB_shader_draw_parameters
#define GL_ARB_shader_draw_parameters                       1
#endif
#ifndef GL_ARB_shader_group_vote
#define GL_ARB_shader_group_vote                            1
#endif
#ifndef GL_ARB_shader_image_load_store
#define GL_ARB_shader_image_load_store                      1
#endif
#ifndef GL_ARB_shader_image_size
#define GL_ARB_shader_image_size                            1
#endif
#ifndef GL_ARB_shader_objects
#define GL_ARB_shader_objects                               1
#endif
#ifndef GL_ARB_shader_precision
#define GL_ARB_shader_precision                             1
#endif
#ifndef GL_ARB_shader_storage_buffer_object
#define GL_ARB_shader_storage_buffer_object                 1
#endif
#ifndef GL_ARB_shader_subroutine
#define GL_ARB_shader_subroutine                            1
#endif
#ifndef GL_ARB_shader_texture_image_samples
#define GL_ARB_shader_texture_image_samples                 1
#endif
#ifndef GL_ARB_shader_texture_lod
#define GL_ARB_shader_texture_lod                           1
#endif
#ifndef GL_ARB_shading_language_100
#define GL_ARB_shading_language_100                         1
#endif
#ifndef GL_ARB_shading_language_420pack
#define GL_ARB_shading_language_420pack                     1
#endif
#ifndef GL_ARB_shading_language_include
#define GL_ARB_shading_language_include                     1
#endif
#ifndef GL_ARB_shading_language_packing
#define GL_ARB_shading_language_packing                     1
#endif
#ifndef GL_ARB_shadow
#define GL_ARB_shadow                                       1
#endif
#ifndef GL_ARB_shadow_ambient
#define GL_ARB_shadow_ambient                               1
#endif
#ifndef GL_ARB_sparse_buffer
#define GL_ARB_sparse_buffer                                1
#endif
#ifndef GL_ARB_sparse_texture
#define GL_ARB_sparse_texture                               1
#endif
#ifndef GL_ARB_sync
#define GL_ARB_sync                                         1
#endif
#ifndef GL_ARB_tessellation_shader
#define GL_ARB_tessellation_shader                          1
#endif
#ifndef GL_ARB_texture_barrier
#define GL_ARB_texture_barrier                              1
#endif
#ifndef GL_ARB_texture_buffer_object
#define GL_ARB_texture_buffer_object                        1
#endif
#ifndef GL_ARB_texture_buffer_object_rgb32
#define GL_ARB_texture_buffer_object_rgb32                  1
#endif
#ifndef GL_ARB_texture_buffer_range
#define GL_ARB_texture_buffer_range                         1
#endif
#ifndef GL_ARB_texture_border_clamp
#define GL_ARB_texture_border_clamp                         1
#endif
#ifndef GL_ARB_texture_compression
#define GL_ARB_texture_compression                          1
#endif
#ifndef GL_ARB_texture_compression_bptc
#define GL_ARB_texture_compression_bptc                     1
#endif
#ifndef GL_ARB_texture_compression_rgtc
#define GL_ARB_texture_compression_rgtc                     1
#endif
#ifndef GL_ARB_texture_cube_map
#define GL_ARB_texture_cube_map                             1
#endif
#ifndef GL_ARB_texture_cube_map_array
#define GL_ARB_texture_cube_map_array                       1
#endif
#ifndef GL_ARB_texture_env_add
#define GL_ARB_texture_env_add                              1
#endif
#ifndef GL_ARB_texture_env_combine
#define GL_ARB_texture_env_combine                          1
#endif
#ifndef GL_ARB_texture_env_crossbar
#define GL_ARB_texture_env_crossbar                         1
#endif
#ifndef GL_ARB_texture_env_dot3
#define GL_ARB_texture_env_dot3                             1
#endif
#ifndef GL_ARB_texture_float
#define GL_ARB_texture_float                                1
#endif
#ifndef GL_ARB_texture_gather
#define GL_ARB_texture_gather                               1
#endif
#ifndef GL_ARB_texture_mirror_clamp_to_edge
#define GL_ARB_texture_mirror_clamp_to_edge                 1
#endif
#ifndef GL_ARB_texture_mirrored_repeat
#define GL_ARB_texture_mirrored_repeat                      1
#endif
#ifndef GL_ARB_texture_multisample
#define GL_ARB_texture_multisample                          1
#endif
#ifndef GL_ARB_texture_non_power_of_two
#define GL_ARB_texture_non_power_of_two                     1
#endif
#ifndef GL_ARB_texture_query_levels
#define GL_ARB_texture_query_levels                         1
#endif
#ifndef GL_ARB_texture_query_lod
#define GL_ARB_texture_query_lod                            1
#endif
#ifndef GL_ARB_texture_rectangle
#define GL_ARB_texture_rectangle                            1
#endif
#ifndef GL_ARB_texture_rg
#define GL_ARB_texture_rg                                   1
#endif
#ifndef GL_ARB_texture_rgb10_a2ui
#define GL_ARB_texture_rgb10_a2ui                           1
#endif
#ifndef GL_ARB_texture_stencil8
#define GL_ARB_texture_stencil8                             1
#endif
#ifndef GL_ARB_texture_storage
#define GL_ARB_texture_storage                              1
#endif
#ifndef GL_ARB_texture_storage_multisample
#define GL_ARB_texture_storage_multisample                  1
#endif
#ifndef GL_ARB_texture_swizzle
#define GL_ARB_texture_swizzle                              1
#endif
#ifndef GL_ARB_texture_view
#define GL_ARB_texture_view                                 1
#endif
#ifndef GL_ARB_timer_query
#define GL_ARB_timer_query                                  1
#endif
#ifndef GL_ARB_transform_feedback2
#define GL_ARB_transform_feedback2                          1
#endif
#ifndef GL_ARB_transform_feedback3
#define GL_ARB_transform_feedback3                          1
#endif
#ifndef GL_ARB_transform_feedback_instanced
#define GL_ARB_transform_feedback_instanced                 1
#endif
#ifndef GL_ARB_transform_feedback_overflow_query
#define GL_ARB_transform_feedback_overflow_query            1
#endif
#ifndef GL_ARB_transpose_matrix
#define GL_ARB_transpose_matrix                             1
#endif
#ifndef GL_ARB_stencil_texturing
#define GL_ARB_stencil_texturing                            1
#endif
#ifndef GL_ARB_uniform_buffer_object
#define GL_ARB_uniform_buffer_object                        1
#endif
#ifndef GL_ARB_vertex_array_bgra
#define GL_ARB_vertex_array_bgra                            1
#endif
#ifndef GL_ARB_vertex_array_object
#define GL_ARB_vertex_array_object                          1
#endif
#ifndef GL_ARB_vertex_attrib_64bit
#define GL_ARB_vertex_attrib_64bit                          1
#endif
#ifndef GL_ARB_vertex_attrib_binding
#define GL_ARB_vertex_attrib_binding                        1
#endif
#ifndef GL_ARB_vertex_buffer_object
#define GL_ARB_vertex_buffer_object                         1
#endif
#ifndef GL_ARB_vertex_program
#define GL_ARB_vertex_program                               1
#endif
#ifndef GL_ARB_vertex_shader
#define GL_ARB_vertex_shader                                1
#endif
#ifndef GL_ARB_vertex_type_10f_11f_11f_rev
#define GL_ARB_vertex_type_10f_11f_11f_rev                  1
#endif
#ifndef GL_ARB_vertex_type_2_10_10_10_rev
#define GL_ARB_vertex_type_2_10_10_10_rev                   1
#endif
#ifndef GL_ARB_viewport_array
#define GL_ARB_viewport_array                               1
#endif
#ifndef GL_ARB_window_pos
#define GL_ARB_window_pos                                   1
#endif
#ifndef GL_ATI_draw_buffers
#define GL_ATI_draw_buffers                                 1
#endif
#ifndef GL_ATI_pixel_format_float
#define GL_ATI_pixel_format_float                           1
#endif
#ifndef GL_ATI_texture_float
#define GL_ATI_texture_float                                1
#endif
#ifndef GL_ATI_texture_mirror_once
#define GL_ATI_texture_mirror_once                          1
#endif
#ifndef GL_Autodesk_valid_back_buffer_hint
#define GL_Autodesk_valid_back_buffer_hint                  1
#endif
#ifndef GL_EXT_Cg_shader
#define GL_EXT_Cg_shader                                    1
#endif
#ifndef GL_EXT_abgr
#define GL_EXT_abgr                                         1
#endif
#ifndef GL_EXT_bgra
#define GL_EXT_bgra                                         1
#endif
#ifndef GL_EXT_base_instance
#define GL_EXT_base_instance                                1
#endif
#ifndef GL_EXT_bindable_uniform
#define GL_EXT_bindable_uniform                             1
#endif
#ifndef GL_EXT_blend_color
#define GL_EXT_blend_color                                  1
#endif
#ifndef GL_EXT_blend_equation_separate
#define GL_EXT_blend_equation_separate                      1
#endif
#ifndef GL_EXT_blend_func_separate
#define GL_EXT_blend_func_separate                          1
#endif
#ifndef GL_EXT_blend_minmax
#define GL_EXT_blend_minmax                                 1
#endif
#ifndef GL_EXT_blend_subtract
#define GL_EXT_blend_subtract                               1
#endif
#ifndef GL_EXT_buffer_storage
#define GL_EXT_buffer_storage                               1
#endif
#ifndef GL_EXT_clip_volume_hint
#define GL_EXT_clip_volume_hint                             1
#endif
#ifndef GL_EXT_color_buffer_half_float
#define GL_EXT_color_buffer_half_float                      1
#endif
#ifndef GL_EXT_color_table
#define GL_EXT_color_table                                  1
#endif
#ifndef GL_EXT_compiled_vertex_array
#define GL_EXT_compiled_vertex_array                        1
#endif
#ifndef GL_EXT_copy_image
#define GL_EXT_copy_image                                   1
#endif
#ifndef GL_EXT_debug_label
#define GL_EXT_debug_label                                  1
#endif
#ifndef GL_EXT_depth_bounds_test
#define GL_EXT_depth_bounds_test                            1
#endif
#ifndef GL_EXT_direct_state_access
#define GL_EXT_direct_state_access                          1
#endif
#ifndef GL_EXT_disjoint_timer_query
#define GL_EXT_disjoint_timer_query                         1
#endif
#ifndef GL_EXT_draw_buffers2
#define GL_EXT_draw_buffers2                                1
#endif
#ifndef GL_EXT_draw_buffers_indexed
#define GL_EXT_draw_buffers_indexed                         1
#endif
#ifndef GL_EXT_draw_elements_base_vertex
#define GL_EXT_draw_elements_base_vertex                    1
#endif
#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced                               1
#endif
#ifndef GL_EXT_draw_range_elements
#define GL_EXT_draw_range_elements                          1
#endif
#ifndef GL_EXT_fog_coord
#define GL_EXT_fog_coord                                    1
#endif
#ifndef GL_EXT_frag_depth
#define GL_EXT_frag_depth                                   1
#endif
#ifndef GL_EXT_framebuffer_blit
#define GL_EXT_framebuffer_blit                             1
#endif
#ifndef GL_EXT_framebuffer_mixed_formats
#define GL_EXT_framebuffer_mixed_formats                    1
#endif
#ifndef GL_EXT_framebuffer_multisample
#define GL_EXT_framebuffer_multisample                      1
#endif
#ifndef GL_EXT_framebuffer_multisample_blit_scaled
#define GL_EXT_framebuffer_multisample_blit_scaled          1
#endif
#ifndef GL_EXT_framebuffer_object
#define GL_EXT_framebuffer_object                           1
#endif
#ifndef GL_EXT_framebuffer_sRGB
#define GL_EXT_framebuffer_sRGB                             1
#endif
#ifndef GL_EXT_geometry_point_size
#define GL_EXT_geometry_point_size                          1
#endif
#ifndef GL_EXT_geometry_shader
#define GL_EXT_geometry_shader                              1
#endif
#ifndef GL_EXT_geometry_shader4
#define GL_EXT_geometry_shader4                             1
#endif
#ifndef GL_EXT_gpu_program_parameters
#define GL_EXT_gpu_program_parameters                       1
#endif
#ifndef GL_EXT_gpu_shader4
#define GL_EXT_gpu_shader4                                  1
#endif
#ifndef GL_EXT_gpu_shader5
#define GL_EXT_gpu_shader5                                  1
#endif
#ifndef GL_EXT_map_buffer_range
#define GL_EXT_map_buffer_range                             1
#endif
#ifndef GL_EXT_memory_object
#define GL_EXT_memory_object                                1
#endif
#ifndef GL_EXT_memory_object_fd
#define GL_EXT_memory_object_fd                             1
#endif
#ifndef GL_EXT_memory_object_win32
#define GL_EXT_memory_object_win32                          1
#endif
#ifndef GL_EXT_multi_draw_arrays
#define GL_EXT_multi_draw_arrays                            1
#endif
#ifndef GL_EXT_multi_draw_indirect
#define GL_EXT_multi_draw_indirect                          1
#endif
#ifndef GL_EXT_occlusion_query_boolean
#define GL_EXT_occlusion_query_boolean                      1
#endif
#ifndef GL_EXT_packed_depth_stencil
#define GL_EXT_packed_depth_stencil                         1
#endif
#ifndef GL_EXT_packed_float
#define GL_EXT_packed_float                                 1
#endif
#ifndef GL_EXT_packed_pixels
#define GL_EXT_packed_pixels                                1
#endif
#ifndef GL_EXT_pixel_buffer_object
#define GL_EXT_pixel_buffer_object                          1
#endif
#ifndef GL_EXT_point_parameters
#define GL_EXT_point_parameters                             1
#endif
#ifndef GL_EXT_polygon_offset_clamp
#define GL_EXT_polygon_offset_clamp                         1
#endif
#ifndef GL_EXT_primitive_bounding_box
#define GL_EXT_primitive_bounding_box                       1
#endif
#ifndef GL_EXT_post_depth_coverage
#define GL_EXT_post_depth_coverage                          1
#endif
#ifndef GL_EXT_provoking_vertex
#define GL_EXT_provoking_vertex                             1
#endif
#ifndef GL_EXT_raster_multisample
#define GL_EXT_raster_multisample                           1
#endif
#ifndef GL_EXT_render_snorm
#define GL_EXT_render_snorm                                 1
#endif
#ifndef GL_EXT_rescale_normal
#define GL_EXT_rescale_normal                               1
#endif
#ifndef GL_EXT_robustness
#define GL_EXT_robustness                                   1
#endif
#ifndef GL_EXT_secondary_color
#define GL_EXT_secondary_color                              1
#endif
#ifndef GL_EXT_separate_shader_objects
#define GL_EXT_separate_shader_objects                      1
#endif
#ifndef GL_EXT_separate_specular_color
#define GL_EXT_separate_specular_color                      1
#endif
#ifndef GL_EXT_shadow_funcs
#define GL_EXT_shadow_funcs                                 1
#endif
#ifndef GL_EXT_shader_image_load_formatted
#define GL_EXT_shader_image_load_formatted                  1
#endif
#ifndef GL_EXT_shader_image_load_store
#define GL_EXT_shader_image_load_store                      1
#endif
#ifndef GL_EXT_shader_implicit_conversions
#define GL_EXT_shader_implicit_conversions                  1
#endif
#ifndef GL_EXT_shader_integer_mix
#define GL_EXT_shader_integer_mix                           1
#endif
#ifndef GL_EXT_shader_io_blocks
#define GL_EXT_shader_io_blocks                             1
#endif
#ifndef GL_EXT_shader_texture_lod
#define GL_EXT_shader_texture_lod                           1
#endif
#ifndef GL_EXT_shadow_samplers
#define GL_EXT_shadow_samplers                              1
#endif
#ifndef GL_EXT_semaphore
#define GL_EXT_semaphore                                    1
#endif
#ifndef GL_EXT_semaphore_fd
#define GL_EXT_semaphore_fd                                 1
#endif
#ifndef GL_EXT_semaphore_win32
#define GL_EXT_semaphore_win32                              1
#endif
#ifndef GL_EXT_sparse_texture2
#define GL_EXT_sparse_texture2                              1
#endif
#ifndef GL_EXT_sRGB
#define GL_EXT_sRGB                                         1
#endif
#ifndef GL_EXT_sRGB_write_control
#define GL_EXT_sRGB_write_control                           1
#endif
#ifndef GL_EXT_stencil_two_side
#define GL_EXT_stencil_two_side                             1
#endif
#ifndef GL_EXT_stencil_wrap
#define GL_EXT_stencil_wrap                                 1
#endif
#ifndef GL_EXT_tessellation_point_size
#define GL_EXT_tessellation_point_size                      1
#endif
#ifndef GL_EXT_tessellation_shader
#define GL_EXT_tessellation_shader                          1
#endif
#ifndef GL_EXT_texture3D
#define GL_EXT_texture3D                                    1
#endif
#ifndef GL_EXT_texture_array
#define GL_EXT_texture_array                                1
#endif
#ifndef GL_EXT_texture_border_clamp
#define GL_EXT_texture_border_clamp                         1
#endif
#ifndef GL_EXT_texture_buffer
#define GL_EXT_texture_buffer                               1
#endif
#ifndef GL_EXT_texture_buffer_object
#define GL_EXT_texture_buffer_object                        1
#endif
#ifndef GL_EXT_texture_compression_latc
#define GL_EXT_texture_compression_latc                     1
#endif
#ifndef GL_EXT_texture_compression_rgtc
#define GL_EXT_texture_compression_rgtc                     1
#endif
#ifndef GL_EXT_texture_compression_s3tc
#define GL_EXT_texture_compression_s3tc                     1
#endif
#ifndef GL_EXT_texture_cube_map
#define GL_EXT_texture_cube_map                             1
#endif
#ifndef GL_EXT_texture_cube_map_array
#define GL_EXT_texture_cube_map_array                       1
#endif
#ifndef GL_EXT_texture_edge_clamp
#define GL_EXT_texture_edge_clamp                           1
#endif
#ifndef GL_EXT_texture_env_add
#define GL_EXT_texture_env_add                              1
#endif
#ifndef GL_EXT_texture_env_combine
#define GL_EXT_texture_env_combine                          1
#endif
#ifndef GL_EXT_texture_env_dot3
#define GL_EXT_texture_env_dot3                             1
#endif
#ifndef GL_EXT_texture_filter_anisotropic
#define GL_EXT_texture_filter_anisotropic                   1
#endif
#ifndef GL_EXT_texture_filter_minmax
#define GL_EXT_texture_filter_minmax                        1
#endif
#ifndef GL_EXT_texture_format_BGRA8888
#define GL_EXT_texture_format_BGRA8888                      1
#endif
#ifndef GL_EXT_texture_integer
#define GL_EXT_texture_integer                              1
#endif
#ifndef GL_EXT_texture_lod_bias
#define GL_EXT_texture_lod_bias                             1
#endif
#ifndef GL_EXT_texture_mirror_clamp
#define GL_EXT_texture_mirror_clamp                         1
#endif
#ifndef GL_EXT_texture_norm16
#define GL_EXT_texture_norm16                               1
#endif
#ifndef GL_EXT_texture_object
#define GL_EXT_texture_object                               1
#endif
#ifndef GL_EXT_texture_rg
#define GL_EXT_texture_rg                                   1
#endif
#ifndef GL_EXT_texture_shared_exponent
#define GL_EXT_texture_shared_exponent                      1
#endif
#ifndef GL_EXT_texture_sRGB
#define GL_EXT_texture_sRGB                                 1
#endif
#ifndef GL_EXT_texture_storage
#define GL_EXT_texture_storage                              1
#endif
#ifndef GL_EXT_texture_sRGB_decode
#define GL_EXT_texture_sRGB_decode                          1
#endif
#ifndef GL_EXT_texture_swizzle
#define GL_EXT_texture_swizzle                              1
#endif
#ifndef GL_EXT_texture_view
#define GL_EXT_texture_view                                 1
#endif
#ifndef GL_EXT_timer_query
#define GL_EXT_timer_query                                  1
#endif
#ifndef GL_EXT_transform_feedback
#define GL_EXT_transform_feedback                           1
#endif
#ifndef GL_EXT_transform_feedback2
#define GL_EXT_transform_feedback2                          1
#endif
#ifndef GL_EXT_unpack_subimage
#define GL_EXT_unpack_subimage                              1
#endif
#ifndef GL_EXT_vertex_array
#define GL_EXT_vertex_array                                 1
#endif
#ifndef GL_EXT_vertex_array_bgra
#define GL_EXT_vertex_array_bgra                            1
#endif
#ifndef GL_EXT_vertex_attrib_64bit
#define GL_EXT_vertex_attrib_64bit                          1
#endif
#ifndef GL_EXT_x11_sync_object
#define GL_EXT_x11_sync_object                              1
#endif
#ifndef GL_EXT_import_sync_object
#define GL_EXT_import_sync_object                           1
#endif
#ifndef GL_NVX_shared_sync_object
#define GL_NVX_shared_sync_object                           1
#endif
#ifndef GL_EXT_ycbcr_422
#define GL_EXT_ycbcr_422                                    1
#endif
#ifndef GL_HP_occlusion_test
#define GL_HP_occlusion_test                                1
#endif
#ifndef GL_IBM_rasterpos_clip
#define GL_IBM_rasterpos_clip                               1
#endif
#ifndef GL_IBM_texture_mirrored_repeat
#define GL_IBM_texture_mirrored_repeat                      1
#endif
#ifndef GL_KHR_blend_equation_advanced
#define GL_KHR_blend_equation_advanced                      1
#endif
#ifndef GL_KHR_blend_equation_advanced_coherent
#define GL_KHR_blend_equation_advanced_coherent             1
#endif
#ifndef GL_KHR_context_flush_control
#define GL_KHR_context_flush_control                        1
#endif
#ifndef GL_KHR_debug
#define GL_KHR_debug                                        1
#endif
#ifndef GL_KHR_robust_buffer_access_behavior
#define GL_KHR_robust_buffer_access_behavior                1
#endif
#ifndef GL_KHR_robustness
#define GL_KHR_robustness                                   1
#endif
#ifndef GL_KHR_texture_compression_astc_ldr
#define GL_KHR_texture_compression_astc_ldr                 1
#endif
#ifndef GL_NV_anc_buffer_object
#define GL_NV_anc_buffer_object                             1
#endif
#ifndef GL_NV_bgr
#define GL_NV_bgr                                           1
#endif
#ifndef GL_NV_bindless_multi_draw_indirect
#define GL_NV_bindless_multi_draw_indirect                  1
#endif
#ifndef GL_NV_bindless_multi_draw_indirect_count
#define GL_NV_bindless_multi_draw_indirect_count            1
#endif
#ifndef GL_NV_bindless_texture
#define GL_NV_bindless_texture                              1
#endif
#ifndef GL_NV_blend_square
#define GL_NV_blend_square                                  1
#endif
#ifndef GL_NV_blend_equation_advanced
#define GL_NV_blend_equation_advanced                       1
#endif
#ifndef GL_NV_blend_equation_advanced_coherent
#define GL_NV_blend_equation_advanced_coherent              1
#endif
#ifndef GL_NV_command_list
#define GL_NV_command_list                                  1
#endif
#ifndef GL_NV_compute_program5
#define GL_NV_compute_program5                              1
#endif
#ifndef GL_NV_compute_stream
#define GL_NV_compute_stream                                1
#endif
#ifndef GL_NV_conditional_render
#define GL_NV_conditional_render                            1
#endif
#ifndef GL_NV_conservative_raster
#define GL_NV_conservative_raster                           1
#endif
#ifndef GL_NV_constant_frame_rate_hint
#define GL_NV_constant_frame_rate_hint                      1
#endif
#ifndef GL_NV_copy_buffer
#define GL_NV_copy_buffer                                   1
#endif
#ifndef GL_NV_copy_depth_to_color
#define GL_NV_copy_depth_to_color                           1
#endif
#ifndef GL_NV_copy_image
#define GL_NV_copy_image                                    1
#endif
#ifndef GL_NV_deep_texture3D
#define GL_NV_deep_texture3D                                1
#endif
#ifndef GL_NV_depth_buffer_float
#define GL_NV_depth_buffer_float                            1
#endif
#ifndef GL_NV_depth_clamp
#define GL_NV_depth_clamp                                   1
#endif
#ifndef GL_NV_draw_buffers
#define GL_NV_draw_buffers                                  1
#endif
#ifndef GL_NV_draw_instanced
#define GL_NV_draw_instanced                                1
#endif
#ifndef GL_NV_draw_mesh
#define GL_NV_draw_mesh                                     1
#endif
#ifndef GL_NV_draw_texture
#define GL_NV_draw_texture                                  1
#endif
#ifndef GL_NV_draw_vulkan_image
#define GL_NV_draw_vulkan_image                             1
#endif
#ifndef GL_NV_EGL_stream_consumer_external
#define GL_NV_EGL_stream_consumer_external                  1
#endif
#ifndef GL_NV_ES1_1_compatibility
#define GL_NV_ES1_1_compatibility                           1
#endif
#ifndef GL_NV_ES3_1_compatibility
#define GL_NV_ES3_1_compatibility                           1
#endif
#ifndef GL_NV_explicit_attrib_location
#define GL_NV_explicit_attrib_location                      1
#endif
#ifndef GL_NV_explicit_multisample
#define GL_NV_explicit_multisample                          1
#endif
#ifndef GL_NV_extended_combiner_program
#define GL_NV_extended_combiner_program                     1
#endif
#ifndef GL_NV_fence
#define GL_NV_fence                                         1
#endif
#ifndef GL_NV_fill_rectangle
#define GL_NV_fill_rectangle                                1
#endif
#ifndef GL_NV_float_buffer
#define GL_NV_float_buffer                                  1
#endif
#ifndef GL_NV_fog_distance
#define GL_NV_fog_distance                                  1
#endif
#ifndef GL_NV_fragment_coverage_to_color
#define GL_NV_fragment_coverage_to_color                    1
#endif
#ifndef GL_NV_fragment_program
#define GL_NV_fragment_program                              1
#endif
#ifndef GL_NV_fragment_program2
#define GL_NV_fragment_program2                             1
#endif
#ifndef GL_NV_fragment_program4
#define GL_NV_fragment_program4                             1
#endif
#ifndef GL_NV_fragment_program4_1
#define GL_NV_fragment_program4_1                           1
#endif
#ifndef GL_NV_fragment_program5
#define GL_NV_fragment_program5                             1
#endif
#ifndef GL_NV_fragment_shader_interlock
#define GL_NV_fragment_shader_interlock                     1
#endif
#ifndef GL_NV_framebuffer_blit
#define GL_NV_framebuffer_blit                              1
#endif
#ifndef GL_NV_framebuffer_mixed_samples
#define GL_NV_framebuffer_mixed_samples                     1
#endif
#ifndef GL_NV_framebuffer_multisample
#define GL_NV_framebuffer_multisample                       1
#endif
#ifndef GL_NV_framebuffer_multisample_coverage
#define GL_NV_framebuffer_multisample_coverage              1
#endif
#ifndef GL_NV_generate_mipmap_sRGB
#define GL_NV_generate_mipmap_sRGB                          1
#endif
#ifndef GL_NV_geometry_program4
#define GL_NV_geometry_program4                             1
#endif
#ifndef GL_NV_geometry_program4_1
#define GL_NV_geometry_program4_1                           1
#endif
#ifndef GL_NV_geometry_program5
#define GL_NV_geometry_program5                             1
#endif
#ifndef GL_NV_geometry_shader4
#define GL_NV_geometry_shader4                              1
#endif
#ifndef GL_NV_geometry_shader_passthrough
#define GL_NV_geometry_shader_passthrough                   1
#endif
#ifndef GL_NV_get_tex_image
#define GL_NV_get_tex_image                                 1
#endif
#ifndef GL_NV_gpu_program4
#define GL_NV_gpu_program4                                  1
#endif
#ifndef GL_NV_gpu_program4_1
#define GL_NV_gpu_program4_1                                1
#endif
#ifndef GL_NV_gpu_program5
#define GL_NV_gpu_program5                                  1
#endif
#ifndef GL_NV_gpu_program5_mem_extended
#define GL_NV_gpu_program5_mem_extended                     1
#endif
#ifndef GL_NV_gpu_program_fp64
#define GL_NV_gpu_program_fp64                              1
#endif
#ifndef GL_NV_gpu_shader5
#define GL_NV_gpu_shader5                                   1
#endif
#ifndef GL_NV_half_float
#define GL_NV_half_float                                    1
#endif
#ifndef GL_NV_image_formats
#define GL_NV_image_formats                                 1
#endif
#ifndef GL_NV_instanced_arrays
#define GL_NV_instanced_arrays                              1
#endif
#ifndef GL_NV_internalformat_sample_query
#define GL_NV_internalformat_sample_query                   1
#endif
#ifndef GL_NV_light_max_exponent
#define GL_NV_light_max_exponent                            1
#endif
#ifndef GL_NV_mac_get_proc_address
#define GL_NV_mac_get_proc_address                          1
#endif
#ifndef GL_NV_multisample_coverage
#define GL_NV_multisample_coverage                          1
#endif
#ifndef GL_NV_multisample_filter_hint
#define GL_NV_multisample_filter_hint                       1
#endif
#ifndef GL_NV_occlusion_query
#define GL_NV_occlusion_query                               1
#endif
#ifndef GL_NV_occlusion_query_samples
#define GL_NV_occlusion_query_samples                       1
#endif
#ifndef GL_NV_non_square_matrices
#define GL_NV_non_square_matrices                           1
#endif
#ifndef GL_NV_pack_subimage
#define GL_NV_pack_subimage                                 1
#endif
#ifndef GL_NV_packed_depth_stencil
#define GL_NV_packed_depth_stencil                          1
#endif
#ifndef GL_NV_packed_float
#define GL_NV_packed_float                                  1
#endif
#ifndef GL_NV_packed_float_linear
#define GL_NV_packed_float_linear                           1
#endif
#ifndef GL_NV_parameter_buffer_object
#define GL_NV_parameter_buffer_object                       1
#endif
#ifndef GL_NV_parameter_buffer_object2
#define GL_NV_parameter_buffer_object2                      1
#endif
#ifndef GL_NV_path_rendering
#define GL_NV_path_rendering                                1
#endif
#ifndef GL_NV_path_rendering_shared_edge
#define GL_NV_path_rendering_shared_edge                    1
#endif
#ifndef GL_NV_pixel_buffer_object
#define GL_NV_pixel_buffer_object                           1
#endif
#ifndef GL_NV_pixel_data_range
#define GL_NV_pixel_data_range                              1
#endif
#ifndef GL_NV_point_sprite
#define GL_NV_point_sprite                                  1
#endif
#ifndef GL_NV_present_video
#define GL_NV_present_video                                 1
#endif
#ifndef GL_NV_primitive_restart
#define GL_NV_primitive_restart                             1
#endif
#ifndef GL_NV_read_buffer
#define GL_NV_read_buffer                                   1
#endif
#ifndef GL_NV_read_depth
#define GL_NV_read_depth                                    1
#endif
#ifndef GL_NV_read_depth_stencil
#define GL_NV_read_depth_stencil                            1
#endif
#ifndef GL_NV_read_stencil
#define GL_NV_read_stencil                                  1
#endif
#ifndef GL_NV_register_combiners
#define GL_NV_register_combiners                            1
#endif
#ifndef GL_NV_register_combiners2
#define GL_NV_register_combiners2                           1
#endif
#ifndef GL_NV_sample_locations
#define GL_NV_sample_locations                              1
#endif
#ifndef GL_NV_sample_mask_override_coverage
#define GL_NV_sample_mask_override_coverage                 1
#endif
#ifndef GL_NV_secure_context
#define GL_NV_secure_context                                1
#endif
#ifndef GL_NV_shader_atomic_counters
#define GL_NV_shader_atomic_counters                        1
#endif
#ifndef GL_NV_shader_atomic_float
#define GL_NV_shader_atomic_float                           1
#endif
#ifndef GL_NV_shader_atomic_float64
#define GL_NV_shader_atomic_float64                         1
#endif
#ifndef GL_NV_shader_atomic_fp16_vector
#define GL_NV_shader_atomic_fp16_vector                     1
#endif
#ifndef GL_NV_shader_atomic_int64
#define GL_NV_shader_atomic_int64                           1
#endif
#ifndef GL_NV_shader_buffer_store
#define GL_NV_shader_buffer_store                           1
#endif
#ifndef GL_NV_shader_storage_buffer_object
#define GL_NV_shader_storage_buffer_object                  1
#endif
#ifndef GL_NV_shader_thread_group
#define GL_NV_shader_thread_group                           1
#endif
#ifndef GL_NV_shader_thread_shuffle
#define GL_NV_shader_thread_shuffle                         1
#endif
#ifndef GL_NV_shadow_samplers_array
#define GL_NV_shadow_samplers_array                         1
#endif
#ifndef GL_NV_shadow_samplers_cube
#define GL_NV_shadow_samplers_cube                          1
#endif
#ifndef GL_NV_sRGB_formats
#define GL_NV_sRGB_formats                                  1
#endif
#ifndef GL_NV_tessellation_program5
#define GL_NV_tessellation_program5                         1
#endif
#ifndef GL_NV_texgen_reflection
#define GL_NV_texgen_reflection                             1
#endif
#ifndef GL_NV_texture_array
#define GL_NV_texture_array                                 1
#endif
#ifndef GL_NV_texture_barrier
#define GL_NV_texture_barrier                               1
#endif
#ifndef GL_NV_texture_border_clamp
#define GL_NV_texture_border_clamp                          1
#endif
#ifndef GL_NV_texture_compression_latc
#define GL_NV_texture_compression_latc                      1
#endif
#ifndef GL_NV_texture_compression_s3tc
#define GL_NV_texture_compression_s3tc                      1
#endif
#ifndef GL_NV_texture_compression_s3tc_update
#define GL_NV_texture_compression_s3tc_update               1
#endif
#ifndef GL_NV_texture_compression_vtc
#define GL_NV_texture_compression_vtc                       1
#endif
#ifndef GL_NV_texture_env_combine4
#define GL_NV_texture_env_combine4                          1
#endif
#ifndef GL_NV_texture_multisample
#define GL_NV_texture_multisample                           1
#endif
#ifndef GL_NV_texture_npot_2D_mipmap
#define GL_NV_texture_npot_2D_mipmap                        1
#endif
#ifndef GL_NV_texture_rectangle
#define GL_NV_texture_rectangle                             1
#endif
#ifndef GL_NV_texture_shader
#define GL_NV_texture_shader                                1
#endif
#ifndef GL_NV_texture_shader2
#define GL_NV_texture_shader2                               1
#endif
#ifndef GL_NV_texture_shader3
#define GL_NV_texture_shader3                               1
#endif
#ifndef GL_NV_timer_query
#define GL_NV_timer_query                                   1
#endif
#ifndef GL_NV_transform_feedback
#define GL_NV_transform_feedback                            1
#endif
#ifndef GL_NV_transform_feedback2
#define GL_NV_transform_feedback2                           1
#endif
#ifndef GL_NV_uniform_buffer_unified_memory
#define GL_NV_uniform_buffer_unified_memory                 1
#endif
#ifndef GL_NV_vdpau_interop
#define GL_NV_vdpau_interop                                 1
#endif
#ifndef GL_NV_vertex_array_range
#define GL_NV_vertex_array_range                            1
#endif
#ifndef GL_NV_vertex_array_range2
#define GL_NV_vertex_array_range2                           1
#endif
#ifndef GL_NV_vertex_attrib_integer_64bit
#define GL_NV_vertex_attrib_integer_64bit                   1
#endif
#ifndef GL_NV_vertex_program
#define GL_NV_vertex_program                                1
#endif
#ifndef GL_NV_vertex_program1_1
#define GL_NV_vertex_program1_1                             1
#endif
#ifndef GL_NV_vertex_program2
#define GL_NV_vertex_program2                               1
#endif
#ifndef GL_NV_vertex_program3
#define GL_NV_vertex_program3                               1
#endif
#ifndef GL_NV_vertex_program4
#define GL_NV_vertex_program4                               1
#endif
#ifndef GL_NV_vertex_program4_1
#define GL_NV_vertex_program4_1                             1
#endif
#ifndef GL_NV_vertex_program5
#define GL_NV_vertex_program5                               1
#endif
#ifndef GL_NV_viewport_array
#define GL_NV_viewport_array                                1
#endif
#ifndef GL_NV_viewport_array2
#define GL_NV_viewport_array2                               1
#endif
#ifndef GL_NVX_anc_capture
#define GL_NVX_anc_capture                                  1
#endif
#ifndef GL_NVX_linked_gpu_multicast
#define GL_NVX_linked_gpu_multicast                         1
#endif
#ifndef GL_NV_gpu_multicast
#define GL_NV_gpu_multicast                                 1
#endif
#ifndef GL_NV_video_capture
#define GL_NV_video_capture                                 1
#endif
#ifndef GL_NVX_sysmem_buffer
#define GL_NVX_sysmem_buffer                                1
#endif
#ifndef GL_NVX_conditional_render
#define GL_NVX_conditional_render                           1
#endif
#ifndef GL_NVX_gpu_memory_info
#define GL_NVX_gpu_memory_info                              1
#endif
#ifndef GL_NVX_gpu_sync_buffer
#define GL_NVX_gpu_sync_buffer                              1
#endif
#ifndef GL_NV_shader_buffer_load
#define GL_NV_shader_buffer_load                            1
#endif
#ifndef GL_NV_shader_noperspective_interpolation
#define GL_NV_shader_noperspective_interpolation            1
#endif
#ifndef GL_NV_vertex_buffer_unified_memory
#define GL_NV_vertex_buffer_unified_memory                  1
#endif
#ifndef GL_NVX_volatile_texture
#define GL_NVX_volatile_texture                             1
#endif
#ifndef GL_NVX_cross_process_interop
#define GL_NVX_cross_process_interop                        1
#endif
#ifndef GL_NVX_cuda_interop
#define GL_NVX_cuda_interop                                 1
#endif
#ifndef GL_NVX_nvenc_interop
#define GL_NVX_nvenc_interop                                1
#endif
#ifndef GL_NVX_debug_control
#define GL_NVX_debug_control                                1
#endif
#ifndef GL_NVX_devtools
#define GL_NVX_devtools                                     1
#endif
#ifndef GL_OES_compressed_ETC1_RGB8_texture
#define GL_OES_compressed_ETC1_RGB8_texture                 1
#endif
#ifndef GL_OES_compressed_paletted_texture
#define GL_OES_compressed_paletted_texture                  1
#endif
#ifndef GL_OES_depth_texture
#define GL_OES_depth_texture                                1
#endif
#ifndef GL_OES_depth_texture_cube_map
#define GL_OES_depth_texture_cube_map                       1
#endif
#ifndef GL_OES_draw_buffers_indexed
#define GL_OES_draw_buffers_indexed                         1
#endif
#ifndef GL_OES_draw_texture
#define GL_OES_draw_texture                                 1
#endif
#ifndef GL_OES_EGL_image_external
#define GL_OES_EGL_image_external                           1
#endif
#ifndef GL_OES_EGL_sync
#define GL_OES_EGL_sync                                     1
#endif
#ifndef GL_OES_framebuffer_object
#define GL_OES_framebuffer_object                           1
#endif
#ifndef GL_OES_geometry_point_size
#define GL_OES_geometry_point_size                          1
#endif
#ifndef GL_OES_geometry_shader
#define GL_OES_geometry_shader                              1
#endif
#ifndef GL_OES_get_program_binary
#define GL_OES_get_program_binary                           1
#endif
#ifndef GL_OES_gpu_shader5
#define GL_OES_gpu_shader5                                  1
#endif
#ifndef GL_OES_mapbuffer
#define GL_OES_mapbuffer                                    1
#endif
#ifndef GL_OES_matrix_get
#define GL_OES_matrix_get                                   1
#endif
#ifndef GL_OES_packed_depth_stencil
#define GL_OES_packed_depth_stencil                         1
#endif
#ifndef GL_OES_point_size_array
#define GL_OES_point_size_array                             1
#endif
#ifndef GL_OES_point_sprite
#define GL_OES_point_sprite                                 1
#endif
#ifndef GL_OES_read_format
#define GL_OES_read_format                                  1
#endif
#ifndef GL_OES_sample_shading
#define GL_OES_sample_shading                               1
#endif
#ifndef GL_OES_sample_variables
#define GL_OES_sample_variables                             1
#endif
#ifndef GL_OES_shader_image_atomic
#define GL_OES_shader_image_atomic                          1
#endif
#ifndef GL_OES_shader_io_blocks
#define GL_OES_shader_io_blocks                             1
#endif
#ifndef GL_OES_shader_multisample_interpolation
#define GL_OES_shader_multisample_interpolation             1
#endif
#ifndef GL_OES_surfaceless_context
#define GL_OES_surfaceless_context                          1
#endif
#ifndef GL_OES_tessellation_point_size
#define GL_OES_tessellation_point_size                      1
#endif
#ifndef GL_OES_tessellation_shader
#define GL_OES_tessellation_shader                          1
#endif
#ifndef GL_OES_texture_border_clamp
#define GL_OES_texture_border_clamp                         1
#endif
#ifndef GL_OES_texture_buffer
#define GL_OES_texture_buffer                               1
#endif
#ifndef GL_OES_texture_cube_map
#define GL_OES_texture_cube_map                             1
#endif
#ifndef GL_OES_texture_cube_map_array
#define GL_OES_texture_cube_map_array                       1
#endif
#ifndef GL_OES_texture_float
#define GL_OES_texture_float                                1
#endif
#ifndef GL_OES_texture_float_linear
#define GL_OES_texture_float_linear                         1
#endif
#ifndef GL_OES_texture_half_float
#define GL_OES_texture_half_float                           1
#endif
#ifndef GL_OES_texture_half_float_linear
#define GL_OES_texture_half_float_linear                    1
#endif
#ifndef GL_OES_texture_stencil8
#define GL_OES_texture_stencil8                             1
#endif
#ifndef GL_OES_texture_storage_multisample_2d_array
#define GL_OES_texture_storage_multisample_2d_array         1
#endif
#ifndef GL_OES_vertex_array_object
#define GL_OES_vertex_array_object                          1
#endif
#ifndef GL_OVR_multiview
#define GL_OVR_multiview                                    1
#endif
#ifndef GL_OVR_multiview2
#define GL_OVR_multiview2                                   1
#endif
#ifndef GL_S3_s3tc
#define GL_S3_s3tc                                          1
#endif
#ifndef GL_SGIS_generate_mipmap
#define GL_SGIS_generate_mipmap                             1
#endif
#ifndef GL_SGIS_texture_lod
#define GL_SGIS_texture_lod                                 1
#endif
#ifndef GL_SGIX_depth_texture
#define GL_SGIX_depth_texture                               1
#endif
#ifndef GL_SGIX_shadow
#define GL_SGIX_shadow                                      1
#endif
#ifndef GL_SUN_slice_accum
#define GL_SUN_slice_accum                                  1
#endif
#ifndef GL_WIN_swap_hint
#define GL_WIN_swap_hint                                    1
#endif

/* PixelFormat */
/*      GL_BGR_EXT */
/*      GL_BGRA_EXT */

/* GetPName */
/*      GL_ARRAY_ELEMENT_LOCK_COUNT_EXT */
/*      GL_ARRAY_ELEMENT_LOCK_FIRST_EXT */

/* GetColorTableParameterPNameEXT */
/*      GL_COLOR_TABLE_FORMAT_EXT */
/*      GL_COLOR_TABLE_WIDTH_EXT */
/*      GL_COLOR_TABLE_RED_SIZE_EXT */
/*      GL_COLOR_TABLE_GREEN_SIZE_EXT */
/*      GL_COLOR_TABLE_BLUE_SIZE_EXT */
/*      GL_COLOR_TABLE_ALPHA_SIZE_EXT */
/*      GL_COLOR_TABLE_LUMINANCE_SIZE_EXT */
/*      GL_COLOR_TABLE_INTENSITY_SIZE_EXT */

/* OpenGL12 */
#define GL_TEXTURE_BINDING_3D                               0x806A
#define GL_PACK_SKIP_IMAGES                                 0x806B
#define GL_PACK_IMAGE_HEIGHT                                0x806C
#define GL_UNPACK_SKIP_IMAGES                               0x806D
#define GL_UNPACK_IMAGE_HEIGHT                              0x806E
#define GL_TEXTURE_3D                                       0x806F
#define GL_PROXY_TEXTURE_3D                                 0x8070
#define GL_TEXTURE_DEPTH                                    0x8071
#define GL_TEXTURE_WRAP_R                                   0x8072
#define GL_MAX_3D_TEXTURE_SIZE                              0x8073
#define GL_BGR                                              0x80E0
#define GL_BGRA                                             0x80E1
#define GL_UNSIGNED_BYTE_3_3_2                              0x8032
#define GL_UNSIGNED_BYTE_2_3_3_REV                          0x8362
#define GL_UNSIGNED_SHORT_5_6_5                             0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV                         0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4                           0x8033
#define GL_UNSIGNED_SHORT_4_4_4_4_REV                       0x8365
#define GL_UNSIGNED_SHORT_5_5_5_1                           0x8034
#define GL_UNSIGNED_SHORT_1_5_5_5_REV                       0x8366
#define GL_UNSIGNED_INT_8_8_8_8                             0x8035
#define GL_UNSIGNED_INT_8_8_8_8_REV                         0x8367
#define GL_UNSIGNED_INT_10_10_10_2                          0x8036
#define GL_UNSIGNED_INT_2_10_10_10_REV                      0x8368
#define GL_RESCALE_NORMAL                                   0x803A
#define GL_LIGHT_MODEL_COLOR_CONTROL                        0x81F8
#define GL_SINGLE_COLOR                                     0x81F9
#define GL_SEPARATE_SPECULAR_COLOR                          0x81FA
#define GL_CLAMP_TO_EDGE                                    0x812F
#define GL_TEXTURE_MIN_LOD                                  0x813A
#define GL_TEXTURE_MAX_LOD                                  0x813B
#define GL_TEXTURE_BASE_LEVEL                               0x813C
#define GL_TEXTURE_MAX_LEVEL                                0x813D
#define GL_MAX_ELEMENTS_VERTICES                            0x80E8
#define GL_MAX_ELEMENTS_INDICES                             0x80E9
#define GL_ALIASED_POINT_SIZE_RANGE                         0x846D
#define GL_ALIASED_LINE_WIDTH_RANGE                         0x846E

/* OpenGL13 */
#define GL_ACTIVE_TEXTURE                                   0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE                            0x84E1
#define GL_MAX_TEXTURE_UNITS                                0x84E2
#define GL_TEXTURE0                                         0x84C0
#define GL_TEXTURE1                                         0x84C1
#define GL_TEXTURE2                                         0x84C2
#define GL_TEXTURE3                                         0x84C3
#define GL_TEXTURE4                                         0x84C4
#define GL_TEXTURE5                                         0x84C5
#define GL_TEXTURE6                                         0x84C6
#define GL_TEXTURE7                                         0x84C7
#define GL_TEXTURE8                                         0x84C8
#define GL_TEXTURE9                                         0x84C9
#define GL_TEXTURE10                                        0x84CA
#define GL_TEXTURE11                                        0x84CB
#define GL_TEXTURE12                                        0x84CC
#define GL_TEXTURE13                                        0x84CD
#define GL_TEXTURE14                                        0x84CE
#define GL_TEXTURE15                                        0x84CF
#define GL_TEXTURE16                                        0x84D0
#define GL_TEXTURE17                                        0x84D1
#define GL_TEXTURE18                                        0x84D2
#define GL_TEXTURE19                                        0x84D3
#define GL_TEXTURE20                                        0x84D4
#define GL_TEXTURE21                                        0x84D5
#define GL_TEXTURE22                                        0x84D6
#define GL_TEXTURE23                                        0x84D7
#define GL_TEXTURE24                                        0x84D8
#define GL_TEXTURE25                                        0x84D9
#define GL_TEXTURE26                                        0x84DA
#define GL_TEXTURE27                                        0x84DB
#define GL_TEXTURE28                                        0x84DC
#define GL_TEXTURE29                                        0x84DD
#define GL_TEXTURE30                                        0x84DE
#define GL_TEXTURE31                                        0x84DF
#define GL_NORMAL_MAP                                       0x8511
#define GL_REFLECTION_MAP                                   0x8512
#define GL_TEXTURE_CUBE_MAP                                 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP                         0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X                      0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X                      0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y                      0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y                      0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z                      0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z                      0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP                           0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE                        0x851C
#define GL_COMBINE                                          0x8570
#define GL_COMBINE_RGB                                      0x8571
#define GL_COMBINE_ALPHA                                    0x8572
#define GL_RGB_SCALE                                        0x8573
#define GL_ADD_SIGNED                                       0x8574
#define GL_INTERPOLATE                                      0x8575
#define GL_CONSTANT                                         0x8576
#define GL_PRIMARY_COLOR                                    0x8577
#define GL_PREVIOUS                                         0x8578
#define GL_SOURCE0_RGB                                      0x8580
#define GL_SOURCE1_RGB                                      0x8581
#define GL_SOURCE2_RGB                                      0x8582
#define GL_SOURCE0_ALPHA                                    0x8588
#define GL_SOURCE1_ALPHA                                    0x8589
#define GL_SOURCE2_ALPHA                                    0x858A
#define GL_OPERAND0_RGB                                     0x8590
#define GL_OPERAND1_RGB                                     0x8591
#define GL_OPERAND2_RGB                                     0x8592
#define GL_OPERAND0_ALPHA                                   0x8598
#define GL_OPERAND1_ALPHA                                   0x8599
#define GL_OPERAND2_ALPHA                                   0x859A
#define GL_SUBTRACT                                         0x84E7
#define GL_TRANSPOSE_MODELVIEW_MATRIX                       0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX                      0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX                         0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX                           0x84E6
#define GL_COMPRESSED_ALPHA                                 0x84E9
#define GL_COMPRESSED_LUMINANCE                             0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA                       0x84EB
#define GL_COMPRESSED_INTENSITY                             0x84EC
#define GL_COMPRESSED_RGB                                   0x84ED
#define GL_COMPRESSED_RGBA                                  0x84EE
#define GL_TEXTURE_COMPRESSION_HINT                         0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE                    0x86A0
#define GL_TEXTURE_COMPRESSED                               0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS                   0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS                       0x86A3
#define GL_DOT3_RGB                                         0x86AE
#define GL_DOT3_RGBA                                        0x86AF
#define GL_CLAMP_TO_BORDER                                  0x812D
#define GL_MULTISAMPLE                                      0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE                         0x809E
#define GL_SAMPLE_ALPHA_TO_ONE                              0x809F
#define GL_SAMPLE_COVERAGE                                  0x80A0
#define GL_SAMPLE_BUFFERS                                   0x80A8
#define GL_SAMPLES                                          0x80A9
#define GL_SAMPLE_COVERAGE_VALUE                            0x80AA
#define GL_SAMPLE_COVERAGE_INVERT                           0x80AB
#define GL_MULTISAMPLE_BIT                                  0x20000000

/* EXT_abgr */
#define GL_ABGR_EXT                                         0x8000

/* EXT_bgra */
#define GL_BGR_EXT                                          0x80E0
#define GL_BGRA_EXT                                         0x80E1

/* EXT_blend_color */
#define GL_CONSTANT_COLOR_EXT                               0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT                     0x8002
#define GL_CONSTANT_ALPHA_EXT                               0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT                     0x8004
#define GL_BLEND_COLOR_EXT                                  0x8005

/* EXT_blend_minmax */
#define GL_FUNC_ADD_EXT                                     0x8006
#define GL_MIN_EXT                                          0x8007
#define GL_MAX_EXT                                          0x8008
#define GL_BLEND_EQUATION_EXT                               0x8009

/* EXT_blend_subtract */
#define GL_FUNC_SUBTRACT_EXT                                0x800A
#define GL_FUNC_REVERSE_SUBTRACT_EXT                        0x800B

/* EXT_color_table */
#define GL_TABLE_TOO_LARGE_EXT                              0x8031
#define GL_COLOR_TABLE_FORMAT_EXT                           0x80D8
#define GL_COLOR_TABLE_WIDTH_EXT                            0x80D9
#define GL_COLOR_TABLE_RED_SIZE_EXT                         0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE_EXT                       0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE_EXT                        0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE_EXT                       0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE_EXT                   0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE_EXT                   0x80DF

/* EXT_packed_pixels */
#define GL_UNSIGNED_BYTE_3_3_2_EXT                          0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT                       0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT                       0x8034
#define GL_UNSIGNED_INT_8_8_8_8_EXT                         0x8035
#define GL_UNSIGNED_INT_10_10_10_2_EXT                      0x8036

/* EXT_rescale_normal */
#define GL_RESCALE_NORMAL_EXT                               0x803A

/* EXT_texture3D */
#define GL_PACK_SKIP_IMAGES                                 0x806B
#define GL_PACK_SKIP_IMAGES_EXT                             0x806B
#define GL_PACK_IMAGE_HEIGHT                                0x806C
#define GL_PACK_IMAGE_HEIGHT_EXT                            0x806C
#define GL_UNPACK_SKIP_IMAGES                               0x806D
#define GL_UNPACK_SKIP_IMAGES_EXT                           0x806D
#define GL_UNPACK_IMAGE_HEIGHT                              0x806E
#define GL_UNPACK_IMAGE_HEIGHT_EXT                          0x806E
#define GL_TEXTURE_3D                                       0x806F
#define GL_TEXTURE_3D_EXT                                   0x806F
#define GL_PROXY_TEXTURE_3D                                 0x8070
#define GL_PROXY_TEXTURE_3D_EXT                             0x8070
#define GL_TEXTURE_DEPTH                                    0x8071
#define GL_TEXTURE_DEPTH_EXT                                0x8071
#define GL_TEXTURE_WRAP_R                                   0x8072
#define GL_TEXTURE_WRAP_R_EXT                               0x8072
#define GL_MAX_3D_TEXTURE_SIZE                              0x8073
#define GL_MAX_3D_TEXTURE_SIZE_EXT                          0x8073

/* ATI_element_array */
#define GL_ELEMENT_ARRAY_ATI                                0x8768

/* EXT_vertex_array */
#define GL_VERTEX_ARRAY_EXT                                 0x8074
#define GL_NORMAL_ARRAY_EXT                                 0x8075
#define GL_COLOR_ARRAY_EXT                                  0x8076
#define GL_INDEX_ARRAY_EXT                                  0x8077
#define GL_TEXTURE_COORD_ARRAY_EXT                          0x8078
#define GL_EDGE_FLAG_ARRAY_EXT                              0x8079
#define GL_VERTEX_ARRAY_SIZE_EXT                            0x807A
#define GL_VERTEX_ARRAY_TYPE_EXT                            0x807B
#define GL_VERTEX_ARRAY_STRIDE_EXT                          0x807C
#define GL_VERTEX_ARRAY_COUNT_EXT                           0x807D
#define GL_NORMAL_ARRAY_TYPE_EXT                            0x807E
#define GL_NORMAL_ARRAY_STRIDE_EXT                          0x807F
#define GL_NORMAL_ARRAY_COUNT_EXT                           0x8080
#define GL_COLOR_ARRAY_SIZE_EXT                             0x8081
#define GL_COLOR_ARRAY_TYPE_EXT                             0x8082
#define GL_COLOR_ARRAY_STRIDE_EXT                           0x8083
#define GL_COLOR_ARRAY_COUNT_EXT                            0x8084
#define GL_INDEX_ARRAY_TYPE_EXT                             0x8085
#define GL_INDEX_ARRAY_STRIDE_EXT                           0x8086
#define GL_INDEX_ARRAY_COUNT_EXT                            0x8087
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT                     0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT                     0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT                   0x808A
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT                    0x808B
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT                       0x808C
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT                        0x808D
#define GL_VERTEX_ARRAY_POINTER_EXT                         0x808E
#define GL_NORMAL_ARRAY_POINTER_EXT                         0x808F
#define GL_COLOR_ARRAY_POINTER_EXT                          0x8090
#define GL_INDEX_ARRAY_POINTER_EXT                          0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT                  0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT                      0x8093

/* ARB_imaging */
#define GL_CONSTANT_COLOR                                   0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR                         0x8002
#define GL_CONSTANT_ALPHA                                   0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA                         0x8004
#define GL_BLEND_COLOR                                      0x8005
#define GL_FUNC_ADD                                         0x8006
#define GL_MIN                                              0x8007
#define GL_MAX                                              0x8008
#define GL_BLEND_EQUATION                                   0x8009
#define GL_FUNC_SUBTRACT                                    0x800A
#define GL_FUNC_REVERSE_SUBTRACT                            0x800B
#define GL_COLOR_MATRIX                                     0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH                         0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH                     0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE                      0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE                    0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE                     0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE                    0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS                       0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS                     0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS                      0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS                     0x80BB
#define GL_COLOR_TABLE                                      0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE                     0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE                    0x80D2
#define GL_PROXY_COLOR_TABLE                                0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE               0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE              0x80D5
#define GL_COLOR_TABLE_SCALE                                0x80D6
#define GL_COLOR_TABLE_BIAS                                 0x80D7
#define GL_COLOR_TABLE_FORMAT                               0x80D8
#define GL_COLOR_TABLE_WIDTH                                0x80D9
#define GL_COLOR_TABLE_RED_SIZE                             0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE                           0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE                            0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE                           0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE                       0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE                       0x80DF
#define GL_CONVOLUTION_1D                                   0x8010
#define GL_CONVOLUTION_2D                                   0x8011
#define GL_SEPARABLE_2D                                     0x8012
#define GL_CONVOLUTION_BORDER_MODE                          0x8013
#define GL_CONVOLUTION_FILTER_SCALE                         0x8014
#define GL_CONVOLUTION_FILTER_BIAS                          0x8015
#define GL_REDUCE                                           0x8016
#define GL_CONVOLUTION_FORMAT                               0x8017
#define GL_CONVOLUTION_WIDTH                                0x8018
#define GL_CONVOLUTION_HEIGHT                               0x8019
#define GL_MAX_CONVOLUTION_WIDTH                            0x801A
#define GL_MAX_CONVOLUTION_HEIGHT                           0x801B
#define GL_POST_CONVOLUTION_RED_SCALE                       0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE                     0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE                      0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE                     0x801F
#define GL_POST_CONVOLUTION_RED_BIAS                        0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS                      0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS                       0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS                      0x8023
#define GL_IGNORE_BORDER                                    0x8150
#define GL_CONSTANT_BORDER                                  0x8151
#define GL_REPLICATE_BORDER                                 0x8153
#define GL_CONVOLUTION_BORDER_COLOR                         0x8154
#define GL_HISTOGRAM                                        0x8024
#define GL_PROXY_HISTOGRAM                                  0x8025
#define GL_HISTOGRAM_WIDTH                                  0x8026
#define GL_HISTOGRAM_FORMAT                                 0x8027
#define GL_HISTOGRAM_RED_SIZE                               0x8028
#define GL_HISTOGRAM_GREEN_SIZE                             0x8029
#define GL_HISTOGRAM_BLUE_SIZE                              0x802A
#define GL_HISTOGRAM_ALPHA_SIZE                             0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE                         0x802C
#define GL_HISTOGRAM_SINK                                   0x802D
#define GL_MINMAX                                           0x802E
#define GL_MINMAX_FORMAT                                    0x802F
#define GL_MINMAX_SINK                                      0x8030

/* EXT_clip_volume_hint */
#define GL_CLIP_VOLUME_CLIPPING_HINT_EXT                    0x80F0

/* EXT_point_parameters */
#define GL_POINT_SIZE_MIN_EXT                               0x8126
#define GL_POINT_SIZE_MAX_EXT                               0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT                    0x8128
#define GL_DISTANCE_ATTENUATION_EXT                         0x8129

/* SGIX_shadow */
#define GL_TEXTURE_COMPARE_SGIX                             0x819A
#define GL_TEXTURE_COMPARE_OPERATOR_SGIX                    0x819B
#define GL_TEXTURE_LEQUAL_R_SGIX                            0x819C
#define GL_TEXTURE_GEQUAL_R_SGIX                            0x819D

/* SGIX_depth_texture */
#define GL_DEPTH_COMPONENT16_SGIX                           0x81A5
#define GL_DEPTH_COMPONENT24_SGIX                           0x81A6
#define GL_DEPTH_COMPONENT32_SGIX                           0x81A7

/* EXT_compiled_vertex_array */
#define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT                     0x81A8
#define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT                     0x81A9

/* ARB_multitexture */
#define GL_ACTIVE_TEXTURE_ARB                               0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB                        0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB                            0x84E2
#define GL_TEXTURE0_ARB                                     0x84C0
#define GL_TEXTURE1_ARB                                     0x84C1
#define GL_TEXTURE2_ARB                                     0x84C2
#define GL_TEXTURE3_ARB                                     0x84C3
#define GL_TEXTURE4_ARB                                     0x84C4
#define GL_TEXTURE5_ARB                                     0x84C5
#define GL_TEXTURE6_ARB                                     0x84C6
#define GL_TEXTURE7_ARB                                     0x84C7
#define GL_TEXTURE8_ARB                                     0x84C8
#define GL_TEXTURE9_ARB                                     0x84C9
#define GL_TEXTURE10_ARB                                    0x84CA
#define GL_TEXTURE11_ARB                                    0x84CB
#define GL_TEXTURE12_ARB                                    0x84CC
#define GL_TEXTURE13_ARB                                    0x84CD
#define GL_TEXTURE14_ARB                                    0x84CE
#define GL_TEXTURE15_ARB                                    0x84CF
#define GL_TEXTURE16_ARB                                    0x84D0
#define GL_TEXTURE17_ARB                                    0x84D1
#define GL_TEXTURE18_ARB                                    0x84D2
#define GL_TEXTURE19_ARB                                    0x84D3
#define GL_TEXTURE20_ARB                                    0x84D4
#define GL_TEXTURE21_ARB                                    0x84D5
#define GL_TEXTURE22_ARB                                    0x84D6
#define GL_TEXTURE23_ARB                                    0x84D7
#define GL_TEXTURE24_ARB                                    0x84D8
#define GL_TEXTURE25_ARB                                    0x84D9
#define GL_TEXTURE26_ARB                                    0x84DA
#define GL_TEXTURE27_ARB                                    0x84DB
#define GL_TEXTURE28_ARB                                    0x84DC
#define GL_TEXTURE29_ARB                                    0x84DD
#define GL_TEXTURE30_ARB                                    0x84DE
#define GL_TEXTURE31_ARB                                    0x84DF

/* EXT_fog_coord */
#define GL_FOG_COORDINATE_SOURCE_EXT                        0x8450
#define GL_FOG_COORDINATE_EXT                               0x8451
#define GL_FRAGMENT_DEPTH_EXT                               0x8452
#define GL_CURRENT_FOG_COORDINATE_EXT                       0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE_EXT                    0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT                  0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER_EXT                 0x8456
#define GL_FOG_COORDINATE_ARRAY_EXT                         0x8457

/* EXT_secondary_color */
#define GL_COLOR_SUM_EXT                                    0x8458
#define GL_CURRENT_SECONDARY_COLOR_EXT                      0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE_EXT                   0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE_EXT                   0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT                 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER_EXT                0x845D
#define GL_SECONDARY_COLOR_ARRAY_EXT                        0x845E

/* EXT_separate_specular_color */
#define GL_SINGLE_COLOR_EXT                                 0x81F9
#define GL_SEPARATE_SPECULAR_COLOR_EXT                      0x81FA
#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT                    0x81F8

/* EXT_stencil_wrap */
#define GL_INCR_WRAP_EXT                                    0x8507
#define GL_DECR_WRAP_EXT                                    0x8508

/* NV_texgen_reflection */
#define GL_NORMAL_MAP_NV                                    0x8511
#define GL_REFLECTION_MAP_NV                                0x8512

/* EXT_texture_cube_map */
#define GL_NORMAL_MAP_EXT                                   0x8511
#define GL_REFLECTION_MAP_EXT                               0x8512
#define GL_TEXTURE_CUBE_MAP_EXT                             0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_EXT                     0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT                  0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT                  0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT                  0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT                  0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT                  0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT                  0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_EXT                       0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT                    0x851C

/* ARB_texture_cube_map */
#define GL_NORMAL_MAP_ARB                                   0x8511
#define GL_REFLECTION_MAP_ARB                               0x8512
#define GL_TEXTURE_CUBE_MAP_ARB                             0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB                     0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB                  0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB                  0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB                  0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB                  0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB                  0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB                  0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB                       0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB                    0x851C

/* NV_vdpau_interop */
#define GL_SURFACE_STATE_NV                                 0x86EB
#define GL_SURFACE_REGISTERED_NV                            0x86FD
#define GL_SURFACE_MAPPED_NV                                0x8700
#define GL_WRITE_DISCARD_NV                                 0x88BE

/* NV_vertex_array_range */
#define GL_VERTEX_ARRAY_RANGE_NV                            0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_NV                     0x851E
#define GL_VERTEX_ARRAY_RANGE_VALID_NV                      0x851F
#define GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV                0x8520
#define GL_VERTEX_ARRAY_RANGE_POINTER_NV                    0x8521

/* NV_vertex_array_range2 */
#define GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV              0x8533

/* NV_register_combiners */
#define GL_REGISTER_COMBINERS_NV                            0x8522
#define GL_COMBINER0_NV                                     0x8550
#define GL_COMBINER1_NV                                     0x8551
#define GL_COMBINER2_NV                                     0x8552
#define GL_COMBINER3_NV                                     0x8553
#define GL_COMBINER4_NV                                     0x8554
#define GL_COMBINER5_NV                                     0x8555
#define GL_COMBINER6_NV                                     0x8556
#define GL_COMBINER7_NV                                     0x8557
#define GL_VARIABLE_A_NV                                    0x8523
#define GL_VARIABLE_B_NV                                    0x8524
#define GL_VARIABLE_C_NV                                    0x8525
#define GL_VARIABLE_D_NV                                    0x8526
#define GL_VARIABLE_E_NV                                    0x8527
#define GL_VARIABLE_F_NV                                    0x8528
#define GL_VARIABLE_G_NV                                    0x8529
/*      GL_ZERO */
#define GL_CONSTANT_COLOR0_NV                               0x852A
#define GL_CONSTANT_COLOR1_NV                               0x852B
/*      GL_FOG */
#define GL_PRIMARY_COLOR_NV                                 0x852C
#define GL_SECONDARY_COLOR_NV                               0x852D
#define GL_SPARE0_NV                                        0x852E
#define GL_SPARE1_NV                                        0x852F
/*      GL_TEXTURE0_ARB */
/*      GL_TEXTURE1_ARB */
#define GL_UNSIGNED_IDENTITY_NV                             0x8536
#define GL_UNSIGNED_INVERT_NV                               0x8537
#define GL_EXPAND_NORMAL_NV                                 0x8538
#define GL_EXPAND_NEGATE_NV                                 0x8539
#define GL_HALF_BIAS_NORMAL_NV                              0x853A
#define GL_HALF_BIAS_NEGATE_NV                              0x853B
#define GL_SIGNED_IDENTITY_NV                               0x853C
#define GL_SIGNED_NEGATE_NV                                 0x853D
#define GL_E_TIMES_F_NV                                     0x8531
#define GL_SPARE0_PLUS_SECONDARY_COLOR_NV                   0x8532
/*      GL_NONE */
#define GL_SCALE_BY_TWO_NV                                  0x853E
#define GL_SCALE_BY_FOUR_NV                                 0x853F
#define GL_SCALE_BY_ONE_HALF_NV                             0x8540
#define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV                     0x8541
#define GL_DISCARD_NV                                       0x8530
#define GL_COMBINER_INPUT_NV                                0x8542
#define GL_COMBINER_MAPPING_NV                              0x8543
#define GL_COMBINER_COMPONENT_USAGE_NV                      0x8544
#define GL_COMBINER_AB_DOT_PRODUCT_NV                       0x8545
#define GL_COMBINER_CD_DOT_PRODUCT_NV                       0x8546
#define GL_COMBINER_MUX_SUM_NV                              0x8547
#define GL_COMBINER_SCALE_NV                                0x8548
#define GL_COMBINER_BIAS_NV                                 0x8549
#define GL_COMBINER_AB_OUTPUT_NV                            0x854A
#define GL_COMBINER_CD_OUTPUT_NV                            0x854B
#define GL_COMBINER_SUM_OUTPUT_NV                           0x854C
#define GL_MAX_GENERAL_COMBINERS_NV                         0x854D
#define GL_NUM_GENERAL_COMBINERS_NV                         0x854E
#define GL_COLOR_SUM_CLAMP_NV                               0x854F

/* NV_fog_distance */
#define GL_FOG_DISTANCE_MODE_NV                             0x855A
#define GL_EYE_RADIAL_NV                                    0x855B
/*      GL_EYE_PLANE */
#define GL_EYE_PLANE_ABSOLUTE_NV                            0x855C

/* NV_fragment_program */
#define GL_FRAGMENT_PROGRAM_NV                              0x8870
#define GL_MAX_TEXTURE_COORDS_NV                            0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_NV                       0x8872
#define GL_FRAGMENT_PROGRAM_BINDING_NV                      0x8873
#define GL_PROGRAM_ERROR_STRING_NV                          0x8874
#define GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV         0x8868

/* NV_light_max_exponent */
#define GL_MAX_SHININESS_NV                                 0x8504
#define GL_MAX_SPOT_EXPONENT_NV                             0x8505

/* ARB_texture_env_combine */
#define GL_COMBINE_ARB                                      0x8570
#define GL_COMBINE_RGB_ARB                                  0x8571
#define GL_COMBINE_ALPHA_ARB                                0x8572
#define GL_RGB_SCALE_ARB                                    0x8573
#define GL_ADD_SIGNED_ARB                                   0x8574
#define GL_INTERPOLATE_ARB                                  0x8575
#define GL_CONSTANT_ARB                                     0x8576
#define GL_PRIMARY_COLOR_ARB                                0x8577
#define GL_PREVIOUS_ARB                                     0x8578
#define GL_SOURCE0_RGB_ARB                                  0x8580
#define GL_SOURCE1_RGB_ARB                                  0x8581
#define GL_SOURCE2_RGB_ARB                                  0x8582
#define GL_SOURCE0_ALPHA_ARB                                0x8588
#define GL_SOURCE1_ALPHA_ARB                                0x8589
#define GL_SOURCE2_ALPHA_ARB                                0x858A
#define GL_OPERAND0_RGB_ARB                                 0x8590
#define GL_OPERAND1_RGB_ARB                                 0x8591
#define GL_OPERAND2_RGB_ARB                                 0x8592
#define GL_OPERAND0_ALPHA_ARB                               0x8598
#define GL_OPERAND1_ALPHA_ARB                               0x8599
#define GL_OPERAND2_ALPHA_ARB                               0x859A
#define GL_SUBTRACT_ARB                                     0x84E7

/* EXT_texture_env_combine */
#define GL_COMBINE_EXT                                      0x8570
#define GL_COMBINE_RGB_EXT                                  0x8571
#define GL_COMBINE_ALPHA_EXT                                0x8572
#define GL_RGB_SCALE_EXT                                    0x8573
#define GL_ADD_SIGNED_EXT                                   0x8574
#define GL_INTERPOLATE_EXT                                  0x8575
#define GL_CONSTANT_EXT                                     0x8576
#define GL_PRIMARY_COLOR_EXT                                0x8577
#define GL_PREVIOUS_EXT                                     0x8578
#define GL_SOURCE0_RGB_EXT                                  0x8580
#define GL_SOURCE1_RGB_EXT                                  0x8581
#define GL_SOURCE2_RGB_EXT                                  0x8582
#define GL_SOURCE0_ALPHA_EXT                                0x8588
#define GL_SOURCE1_ALPHA_EXT                                0x8589
#define GL_SOURCE2_ALPHA_EXT                                0x858A
#define GL_OPERAND0_RGB_EXT                                 0x8590
#define GL_OPERAND1_RGB_EXT                                 0x8591
#define GL_OPERAND2_RGB_EXT                                 0x8592
#define GL_OPERAND0_ALPHA_EXT                               0x8598
#define GL_OPERAND1_ALPHA_EXT                               0x8599
#define GL_OPERAND2_ALPHA_EXT                               0x859A

/* NV_texture_env_combine4 */
#define GL_COMBINE4_NV                                      0x8503
#define GL_SOURCE3_RGB_NV                                   0x8583
#define GL_SOURCE3_ALPHA_NV                                 0x858B
#define GL_OPERAND3_RGB_NV                                  0x8593
#define GL_OPERAND3_ALPHA_NV                                0x859B

/* SUN_slice_accum */
#define GL_SLICE_ACCUM_SUN                                  0x85CC

/* EXT_texture_filter_anisotropic */
#define GL_TEXTURE_MAX_ANISOTROPY_EXT                       0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT                   0x84FF

/* SGIS_texture_lod */
#define GL_TEXTURE_MIN_LOD_SGIS                             0x813A
#define GL_TEXTURE_MAX_LOD_SGIS                             0x813B
#define GL_TEXTURE_BASE_LEVEL_SGIS                          0x813C
#define GL_TEXTURE_MAX_LEVEL_SGIS                           0x813D

/* EXT_texture_lod_bias */
#define GL_MAX_TEXTURE_LOD_BIAS_EXT                         0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT                       0x8500
#define GL_TEXTURE_LOD_BIAS_EXT                             0x8501

/* EXT_texture_edge_clamp */
#define GL_CLAMP_TO_EDGE_EXT                                0x812F

/* S3_s3tc */
#define GL_RGB_S3TC                                         0x83A0
#define GL_RGB4_S3TC                                        0x83A1
#define GL_RGBA_S3TC                                        0x83A2
#define GL_RGBA4_S3TC                                       0x83A3
#define GL_RGBA_DXT5_S3TC                                   0x83A4
#define GL_RGBA4_DXT5_S3TC                                  0x83A5

/* ARB_transpose_matrix */
#define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB                   0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX_ARB                  0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX_ARB                     0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX_ARB                       0x84E6

/* ARB_texture_compression */
#define GL_COMPRESSED_ALPHA_ARB                             0x84E9
#define GL_COMPRESSED_LUMINANCE_ARB                         0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB                   0x84EB
#define GL_COMPRESSED_INTENSITY_ARB                         0x84EC
#define GL_COMPRESSED_RGB_ARB                               0x84ED
#define GL_COMPRESSED_RGBA_ARB                              0x84EE
#define GL_TEXTURE_COMPRESSION_HINT_ARB                     0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB                0x86A0
#define GL_TEXTURE_COMPRESSED_ARB                           0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB               0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB                   0x86A3

/* EXT_texture_compression_s3tc */
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT                     0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT                    0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT                    0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT                    0x83F3

/* EXT_texture_compression_latc */
#define GL_COMPRESSED_LUMINANCE_LATC1_EXT                   0x8C70
#define GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT            0x8C71
#define GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT             0x8C72
#define GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT      0x8C73

/* EXT_texture_compression_rgtc */
#define GL_COMPRESSED_RED_RGTC1_EXT                         0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1_EXT                  0x8DBC
#define GL_COMPRESSED_RED_GREEN_RGTC2_EXT                   0x8DBD
#define GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT            0x8DBE

/* NV_fence */
#define GL_ALL_COMPLETED_NV                                 0x84F2
#define GL_FENCE_STATUS_NV                                  0x84F3
#define GL_FENCE_CONDITION_NV                               0x84F4

/* NV_mac_get_proc_address */
#define GL_ALL_EXTENSIONS_NV                                0x84FB
#define GL_MAC_GET_PROC_ADDRESS_NV                          0x84FC

/* NV_vertex_program */
#define GL_VERTEX_PROGRAM_NV                                0x8620
#define GL_VERTEX_STATE_PROGRAM_NV                          0x8621
#define GL_ATTRIB_ARRAY_SIZE_NV                             0x8623
#define GL_ATTRIB_ARRAY_STRIDE_NV                           0x8624
#define GL_ATTRIB_ARRAY_TYPE_NV                             0x8625
#define GL_CURRENT_ATTRIB_NV                                0x8626
#define GL_PROGRAM_LENGTH_NV                                0x8627
#define GL_PROGRAM_STRING_NV                                0x8628
#define GL_MODELVIEW_PROJECTION_NV                          0x8629
#define GL_IDENTITY_NV                                      0x862A
#define GL_INVERSE_NV                                       0x862B
#define GL_TRANSPOSE_NV                                     0x862C
#define GL_INVERSE_TRANSPOSE_NV                             0x862D
#define GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV                  0x862E
#define GL_MAX_TRACK_MATRICES_NV                            0x862F
#define GL_MATRIX0_NV                                       0x8630
#define GL_MATRIX1_NV                                       0x8631
#define GL_MATRIX2_NV                                       0x8632
#define GL_MATRIX3_NV                                       0x8633
#define GL_MATRIX4_NV                                       0x8634
#define GL_MATRIX5_NV                                       0x8635
#define GL_MATRIX6_NV                                       0x8636
#define GL_MATRIX7_NV                                       0x8637
#define GL_CURRENT_MATRIX_STACK_DEPTH_NV                    0x8640
#define GL_CURRENT_MATRIX_NV                                0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_NV                     0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_NV                       0x8643
#define GL_PROGRAM_PARAMETER_NV                             0x8644
#define GL_ATTRIB_ARRAY_POINTER_NV                          0x8645
#define GL_PROGRAM_TARGET_NV                                0x8646
#define GL_PROGRAM_RESIDENT_NV                              0x8647
#define GL_TRACK_MATRIX_NV                                  0x8648
#define GL_TRACK_MATRIX_TRANSFORM_NV                        0x8649
#define GL_VERTEX_PROGRAM_BINDING_NV                        0x864A
#define GL_PROGRAM_ERROR_POSITION_NV                        0x864B
#define GL_VERTEX_ATTRIB_ARRAY0_NV                          0x8650
#define GL_VERTEX_ATTRIB_ARRAY1_NV                          0x8651
#define GL_VERTEX_ATTRIB_ARRAY2_NV                          0x8652
#define GL_VERTEX_ATTRIB_ARRAY3_NV                          0x8653
#define GL_VERTEX_ATTRIB_ARRAY4_NV                          0x8654
#define GL_VERTEX_ATTRIB_ARRAY5_NV                          0x8655
#define GL_VERTEX_ATTRIB_ARRAY6_NV                          0x8656
#define GL_VERTEX_ATTRIB_ARRAY7_NV                          0x8657
#define GL_VERTEX_ATTRIB_ARRAY8_NV                          0x8658
#define GL_VERTEX_ATTRIB_ARRAY9_NV                          0x8659
#define GL_VERTEX_ATTRIB_ARRAY10_NV                         0x865A
#define GL_VERTEX_ATTRIB_ARRAY11_NV                         0x865B
#define GL_VERTEX_ATTRIB_ARRAY12_NV                         0x865C
#define GL_VERTEX_ATTRIB_ARRAY13_NV                         0x865D
#define GL_VERTEX_ATTRIB_ARRAY14_NV                         0x865E
#define GL_VERTEX_ATTRIB_ARRAY15_NV                         0x865F
#define GL_MAP1_VERTEX_ATTRIB0_4_NV                         0x8660
#define GL_MAP1_VERTEX_ATTRIB1_4_NV                         0x8661
#define GL_MAP1_VERTEX_ATTRIB2_4_NV                         0x8662
#define GL_MAP1_VERTEX_ATTRIB3_4_NV                         0x8663
#define GL_MAP1_VERTEX_ATTRIB4_4_NV                         0x8664
#define GL_MAP1_VERTEX_ATTRIB5_4_NV                         0x8665
#define GL_MAP1_VERTEX_ATTRIB6_4_NV                         0x8666
#define GL_MAP1_VERTEX_ATTRIB7_4_NV                         0x8667
#define GL_MAP1_VERTEX_ATTRIB8_4_NV                         0x8668
#define GL_MAP1_VERTEX_ATTRIB9_4_NV                         0x8669
#define GL_MAP1_VERTEX_ATTRIB10_4_NV                        0x866A
#define GL_MAP1_VERTEX_ATTRIB11_4_NV                        0x866B
#define GL_MAP1_VERTEX_ATTRIB12_4_NV                        0x866C
#define GL_MAP1_VERTEX_ATTRIB13_4_NV                        0x866D
#define GL_MAP1_VERTEX_ATTRIB14_4_NV                        0x866E
#define GL_MAP1_VERTEX_ATTRIB15_4_NV                        0x866F
#define GL_MAP2_VERTEX_ATTRIB0_4_NV                         0x8670
#define GL_MAP2_VERTEX_ATTRIB1_4_NV                         0x8671
#define GL_MAP2_VERTEX_ATTRIB2_4_NV                         0x8672
#define GL_MAP2_VERTEX_ATTRIB3_4_NV                         0x8673
#define GL_MAP2_VERTEX_ATTRIB4_4_NV                         0x8674
#define GL_MAP2_VERTEX_ATTRIB5_4_NV                         0x8675
#define GL_MAP2_VERTEX_ATTRIB6_4_NV                         0x8676
#define GL_MAP2_VERTEX_ATTRIB7_4_NV                         0x8677
#define GL_MAP2_VERTEX_ATTRIB8_4_NV                         0x8678
#define GL_MAP2_VERTEX_ATTRIB9_4_NV                         0x8679
#define GL_MAP2_VERTEX_ATTRIB10_4_NV                        0x867A
#define GL_MAP2_VERTEX_ATTRIB11_4_NV                        0x867B
#define GL_MAP2_VERTEX_ATTRIB12_4_NV                        0x867C
#define GL_MAP2_VERTEX_ATTRIB13_4_NV                        0x867D
#define GL_MAP2_VERTEX_ATTRIB14_4_NV                        0x867E
#define GL_MAP2_VERTEX_ATTRIB15_4_NV                        0x867F

/* NV_texture_shader */
#define GL_OFFSET_TEXTURE_RECTANGLE_NV                      0x864C
#define GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV                0x864D
#define GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV                 0x864E
#define GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV             0x86D9
#define GL_UNSIGNED_INT_S8_S8_8_8_NV                        0x86DA
#define GL_UNSIGNED_INT_8_8_S8_S8_REV_NV                    0x86DB
#define GL_DSDT_MAG_INTENSITY_NV                            0x86DC
#define GL_SHADER_CONSISTENT_NV                             0x86DD
#define GL_TEXTURE_SHADER_NV                                0x86DE
#define GL_SHADER_OPERATION_NV                              0x86DF
#define GL_CULL_MODES_NV                                    0x86E0
#define GL_OFFSET_TEXTURE_MATRIX_NV                         0x86E1
#define GL_OFFSET_TEXTURE_SCALE_NV                          0x86E2
#define GL_OFFSET_TEXTURE_BIAS_NV                           0x86E3
#define GL_OFFSET_TEXTURE_2D_MATRIX_NV                      GL_OFFSET_TEXTURE_MATRIX_NV
#define GL_OFFSET_TEXTURE_2D_SCALE_NV                       GL_OFFSET_TEXTURE_SCALE_NV
#define GL_OFFSET_TEXTURE_2D_BIAS_NV                        GL_OFFSET_TEXTURE_BIAS_NV
#define GL_PREVIOUS_TEXTURE_INPUT_NV                        0x86E4
#define GL_CONST_EYE_NV                                     0x86E5
#define GL_PASS_THROUGH_NV                                  0x86E6
#define GL_CULL_FRAGMENT_NV                                 0x86E7
#define GL_OFFSET_TEXTURE_2D_NV                             0x86E8
#define GL_DEPENDENT_AR_TEXTURE_2D_NV                       0x86E9
#define GL_DEPENDENT_GB_TEXTURE_2D_NV                       0x86EA
#define GL_DOT_PRODUCT_NV                                   0x86EC
#define GL_DOT_PRODUCT_DEPTH_REPLACE_NV                     0x86ED
#define GL_DOT_PRODUCT_TEXTURE_2D_NV                        0x86EE
#define GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV                  0x86F0
#define GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV                  0x86F1
#define GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV                  0x86F2
#define GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV        0x86F3
#define GL_HILO_NV                                          0x86F4
#define GL_DSDT_NV                                          0x86F5
#define GL_DSDT_MAG_NV                                      0x86F6
#define GL_DSDT_MAG_VIB_NV                                  0x86F7
#define GL_HILO16_NV                                        0x86F8
#define GL_SIGNED_HILO_NV                                   0x86F9
#define GL_SIGNED_HILO16_NV                                 0x86FA
#define GL_SIGNED_RGBA_NV                                   0x86FB
#define GL_SIGNED_RGBA8_NV                                  0x86FC
#define GL_SIGNED_RGB_NV                                    0x86FE
#define GL_SIGNED_RGB8_NV                                   0x86FF
#define GL_SIGNED_LUMINANCE_NV                              0x8701
#define GL_SIGNED_LUMINANCE8_NV                             0x8702
#define GL_SIGNED_LUMINANCE_ALPHA_NV                        0x8703
#define GL_SIGNED_LUMINANCE8_ALPHA8_NV                      0x8704
#define GL_SIGNED_ALPHA_NV                                  0x8705
#define GL_SIGNED_ALPHA8_NV                                 0x8706
#define GL_SIGNED_INTENSITY_NV                              0x8707
#define GL_SIGNED_INTENSITY8_NV                             0x8708
#define GL_DSDT8_NV                                         0x8709
#define GL_DSDT8_MAG8_NV                                    0x870A
#define GL_DSDT8_MAG8_INTENSITY8_NV                         0x870B
#define GL_SIGNED_RGB_UNSIGNED_ALPHA_NV                     0x870C
#define GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV                   0x870D
#define GL_HI_SCALE_NV                                      0x870E
#define GL_LO_SCALE_NV                                      0x870F
#define GL_DS_SCALE_NV                                      0x8710
#define GL_DT_SCALE_NV                                      0x8711
#define GL_MAGNITUDE_SCALE_NV                               0x8712
#define GL_VIBRANCE_SCALE_NV                                0x8713
#define GL_HI_BIAS_NV                                       0x8714
#define GL_LO_BIAS_NV                                       0x8715
#define GL_DS_BIAS_NV                                       0x8716
#define GL_DT_BIAS_NV                                       0x8717
#define GL_MAGNITUDE_BIAS_NV                                0x8718
#define GL_VIBRANCE_BIAS_NV                                 0x8719
#define GL_TEXTURE_BORDER_VALUES_NV                         0x871A
#define GL_TEXTURE_HI_SIZE_NV                               0x871B
#define GL_TEXTURE_LO_SIZE_NV                               0x871C
#define GL_TEXTURE_DS_SIZE_NV                               0x871D
#define GL_TEXTURE_DT_SIZE_NV                               0x871E
#define GL_TEXTURE_MAG_SIZE_NV                              0x871F

/* NV_texture_shader2 */
#define GL_DOT_PRODUCT_TEXTURE_3D_NV                        0x86EF

/* NV_texture_shader3 */
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV                  0x8850
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV            0x8851
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV           0x8852
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV     0x8853
#define GL_OFFSET_HILO_TEXTURE_2D_NV                        0x8854
#define GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV                 0x8855
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV             0x8856
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV      0x8857
#define GL_DEPENDENT_HILO_TEXTURE_2D_NV                     0x8858
#define GL_DEPENDENT_RGB_TEXTURE_3D_NV                      0x8859
#define GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV                0x885A
#define GL_DOT_PRODUCT_PASS_THROUGH_NV                      0x885B
#define GL_DOT_PRODUCT_TEXTURE_1D_NV                        0x885C
#define GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV              0x885D
#define GL_HILO8_NV                                         0x885E
#define GL_SIGNED_HILO8_NV                                  0x885F
#define GL_FORCE_BLUE_TO_ONE_NV                             0x8860

/* NV_register_combiners2 */
#define GL_PER_STAGE_CONSTANTS_NV                           0x8535

/* IBM_texture_mirrored_repeat */
#define GL_MIRRORED_REPEAT_IBM                              0x8370

/* ARB_texture_env_dot3 */
#define GL_DOT3_RGB_ARB                                     0x86AE
#define GL_DOT3_RGBA_ARB                                    0x86AF

/* EXT_texture_env_dot3 */
#define GL_DOT3_RGB_EXT                                     0x8740
#define GL_DOT3_RGBA_EXT                                    0x8741

/* APPLE_transform_hint */
#define GL_TRANSFORM_HINT_APPLE                             0x85B1

/* ARB_texture_border_clamp */
#define GL_CLAMP_TO_BORDER_ARB                              0x812D

/* NV_texture_rectangle */
#define GL_TEXTURE_RECTANGLE_NV                             0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_NV                     0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_NV                       0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_NV                    0x84F8

/* ARB_texture_rectangle */
#define GL_TEXTURE_RECTANGLE_ARB                            0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_ARB                    0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_ARB                      0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB                   0x84F8

/* ARB_multisample */
#define GL_MULTISAMPLE_ARB                                  0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB                     0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_ARB                          0x809F
#define GL_SAMPLE_COVERAGE_ARB                              0x80A0
#define GL_SAMPLE_BUFFERS_ARB                               0x80A8
#define GL_SAMPLES_ARB                                      0x80A9
#define GL_SAMPLE_COVERAGE_VALUE_ARB                        0x80AA
#define GL_SAMPLE_COVERAGE_INVERT_ARB                       0x80AB
#define GL_MULTISAMPLE_BIT_ARB                              0x20000000

/* NV_multisample_filter_hint */
#define GL_MULTISAMPLE_FILTER_HINT_NV                       0x8534

/* NV_packed_depth_stencil */
#define GL_DEPTH_STENCIL_NV                                 0x84F9
#define GL_UNSIGNED_INT_24_8_NV                             0x84FA

/* EXT_packed_depth_stencil */
#define GL_DEPTH_STENCIL_EXT                                0x84F9
#define GL_DEPTH24_STENCIL8_EXT                             0x88F0
#define GL_TEXTURE_STENCIL_SIZE_EXT                         0x88F1
#define GL_UNSIGNED_INT_24_8_EXT                            0x84FA

/* EXT_draw_range_elements */
#define GL_MAX_ELEMENTS_VERTICES_EXT                        0x80E8
#define GL_MAX_ELEMENTS_INDICES_EXT                         0x80E9

/* NV_pixel_data_range */
#define GL_WRITE_PIXEL_DATA_RANGE_NV                        0x8878
#define GL_READ_PIXEL_DATA_RANGE_NV                         0x8879
#define GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV                 0x887A
#define GL_READ_PIXEL_DATA_RANGE_LENGTH_NV                  0x887B
#define GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV                0x887C
#define GL_READ_PIXEL_DATA_RANGE_POINTER_NV                 0x887D

/* NV_path_rendering */
#define GL_CLOSE_PATH_NV                                    0x00
#define GL_MOVE_TO_NV                                       0x02
#define GL_RELATIVE_MOVE_TO_NV                              0x03
#define GL_LINE_TO_NV                                       0x04
#define GL_RELATIVE_LINE_TO_NV                              0x05
#define GL_HORIZONTAL_LINE_TO_NV                            0x06
#define GL_RELATIVE_HORIZONTAL_LINE_TO_NV                   0x07
#define GL_VERTICAL_LINE_TO_NV                              0x08
#define GL_RELATIVE_VERTICAL_LINE_TO_NV                     0x09
#define GL_QUADRATIC_CURVE_TO_NV                            0x0A
#define GL_RELATIVE_QUADRATIC_CURVE_TO_NV                   0x0B
#define GL_CUBIC_CURVE_TO_NV                                0x0C
#define GL_RELATIVE_CUBIC_CURVE_TO_NV                       0x0D
#define GL_SMOOTH_QUADRATIC_CURVE_TO_NV                     0x0E
#define GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV            0x0F
#define GL_SMOOTH_CUBIC_CURVE_TO_NV                         0x10
#define GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV                0x11
#define GL_SMALL_CCW_ARC_TO_NV                              0x12
#define GL_RELATIVE_SMALL_CCW_ARC_TO_NV                     0x13
#define GL_SMALL_CW_ARC_TO_NV                               0x14
#define GL_RELATIVE_SMALL_CW_ARC_TO_NV                      0x15
#define GL_LARGE_CCW_ARC_TO_NV                              0x16
#define GL_RELATIVE_LARGE_CCW_ARC_TO_NV                     0x17
#define GL_LARGE_CW_ARC_TO_NV                               0x18
#define GL_RELATIVE_LARGE_CW_ARC_TO_NV                      0x19
#define GL_CONIC_CURVE_TO_NV                                0x1A
#define GL_RELATIVE_CONIC_CURVE_TO_NV                       0x1B
#define GL_ROUNDED_RECT_NV                                  0xE8
#define GL_RELATIVE_ROUNDED_RECT_NV                         0xE9
#define GL_ROUNDED_RECT2_NV                                 0xEA
#define GL_RELATIVE_ROUNDED_RECT2_NV                        0xEB
#define GL_ROUNDED_RECT4_NV                                 0xEC
#define GL_RELATIVE_ROUNDED_RECT4_NV                        0xED
#define GL_ROUNDED_RECT8_NV                                 0xEE
#define GL_RELATIVE_ROUNDED_RECT8_NV                        0xEF
#define GL_RESTART_PATH_NV                                  0xF0
#define GL_DUP_FIRST_CUBIC_CURVE_TO_NV                      0xF2
#define GL_DUP_LAST_CUBIC_CURVE_TO_NV                       0xF4
#define GL_RECT_NV                                          0xF6
#define GL_RELATIVE_RECT_NV                                 0xF7
#define GL_CIRCULAR_CCW_ARC_TO_NV                           0xF8
#define GL_CIRCULAR_CW_ARC_TO_NV                            0xFA
#define GL_CIRCULAR_TANGENT_ARC_TO_NV                       0xFC
#define GL_ARC_TO_NV                                        0xFE
#define GL_RELATIVE_ARC_TO_NV                               0xFF
#define GL_PATH_FORMAT_SVG_NV                               0x9070
#define GL_PATH_FORMAT_PS_NV                                0x9071
#define GL_STANDARD_FONT_NAME_NV                            0x9072
#define GL_SYSTEM_FONT_NAME_NV                              0x9073
#define GL_FILE_NAME_NV                                     0x9074
#define GL_PATH_STROKE_WIDTH_NV                             0x9075
#define GL_PATH_END_CAPS_NV                                 0x9076
#define GL_PATH_INITIAL_END_CAP_NV                          0x9077
#define GL_PATH_TERMINAL_END_CAP_NV                         0x9078
#define GL_PATH_JOIN_STYLE_NV                               0x9079
#define GL_PATH_MITER_LIMIT_NV                              0x907A
#define GL_PATH_DASH_CAPS_NV                                0x907B
#define GL_PATH_INITIAL_DASH_CAP_NV                         0x907C
#define GL_PATH_TERMINAL_DASH_CAP_NV                        0x907D
#define GL_PATH_DASH_OFFSET_NV                              0x907E
#define GL_PATH_CLIENT_LENGTH_NV                            0x907F
#define GL_PATH_FILL_MODE_NV                                0x9080
#define GL_PATH_FILL_MASK_NV                                0x9081
#define GL_PATH_FILL_COVER_MODE_NV                          0x9082
#define GL_PATH_STROKE_COVER_MODE_NV                        0x9083
#define GL_PATH_STROKE_MASK_NV                              0x9084
#define GL_PATH_SAMPLE_QUALITY_NV                           0x9085
#define GL_PATH_STROKE_BOUND_NV                             0x9086
#define GL_PATH_STROKE_OVERSAMPLE_COUNT_NV                  0x9087
#define GL_COUNT_UP_NV                                      0x9088
#define GL_COUNT_DOWN_NV                                    0x9089
#define GL_PATH_OBJECT_BOUNDING_BOX_NV                      0x908A
#define GL_CONVEX_HULL_NV                                   0x908B
#define GL_MULTI_HULLS_NV                                   0x908C
#define GL_BOUNDING_BOX_NV                                  0x908D
#define GL_TRANSLATE_X_NV                                   0x908E
#define GL_TRANSLATE_Y_NV                                   0x908F
#define GL_TRANSLATE_2D_NV                                  0x9090
#define GL_TRANSLATE_3D_NV                                  0x9091
#define GL_AFFINE_2D_NV                                     0x9092
#define GL_PROJECTIVE_2D_NV                                 0x9093
#define GL_AFFINE_3D_NV                                     0x9094
#define GL_PROJECTIVE_3D_NV                                 0x9095
#define GL_TRANSPOSE_AFFINE_2D_NV                           0x9096
#define GL_TRANSPOSE_PROJECTIVE_2D_NV                       0x9097
#define GL_TRANSPOSE_AFFINE_3D_NV                           0x9098
#define GL_TRANSPOSE_PROJECTIVE_3D_NV                       0x9099
#define GL_UTF8_NV                                          0x909A
#define GL_UTF16_NV                                         0x909B
#define GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV                0x909C
#define GL_PATH_COMMAND_COUNT_NV                            0x909D
#define GL_PATH_COORD_COUNT_NV                              0x909E
#define GL_PATH_DASH_ARRAY_COUNT_NV                         0x909F
#define GL_PATH_COMPUTED_LENGTH_NV                          0x90A0
#define GL_PATH_FILL_BOUNDING_BOX_NV                        0x90A1
#define GL_PATH_STROKE_BOUNDING_BOX_NV                      0x90A2
#define GL_SQUARE_NV                                        0x90A3
#define GL_ROUND_NV                                         0x90A4
#define GL_TRIANGULAR_NV                                    0x90A5
#define GL_BEVEL_NV                                         0x90A6
#define GL_MITER_REVERT_NV                                  0x90A7
#define GL_MITER_TRUNCATE_NV                                0x90A8
#define GL_SKIP_MISSING_GLYPH_NV                            0x90A9
#define GL_USE_MISSING_GLYPH_NV                             0x90AA
#define GL_PATH_DASH_OFFSET_RESET_NV                        0x90B4
#define GL_MOVE_TO_RESETS_NV                                0x90B5
#define GL_MOVE_TO_CONTINUES_NV                             0x90B6
#define GL_BOLD_BIT_NV                                      0x01
#define GL_ITALIC_BIT_NV                                    0x02
#define GL_PATH_ERROR_POSITION_NV                           0x90AB
#define GL_PATH_FOG_GEN_MODE_NV                             0x90AC
#define GL_GLYPH_WIDTH_BIT_NV                               0x01
#define GL_GLYPH_HEIGHT_BIT_NV                              0x02
#define GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV                0x04
#define GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV                0x08
#define GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV          0x10
#define GL_GLYPH_VERTICAL_BEARING_X_BIT_NV                  0x20
#define GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV                  0x40
#define GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV            0x80
#define GL_GLYPH_HAS_KERNING_BIT_NV                         0x100
#define GL_FONT_X_MIN_BOUNDS_BIT_NV                         0x00010000
#define GL_FONT_Y_MIN_BOUNDS_BIT_NV                         0x00020000
#define GL_FONT_X_MAX_BOUNDS_BIT_NV                         0x00040000
#define GL_FONT_Y_MAX_BOUNDS_BIT_NV                         0x00080000
#define GL_FONT_UNITS_PER_EM_BIT_NV                         0x00100000
#define GL_FONT_ASCENDER_BIT_NV                             0x00200000
#define GL_FONT_DESCENDER_BIT_NV                            0x00400000
#define GL_FONT_HEIGHT_BIT_NV                               0x00800000
#define GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV                    0x01000000
#define GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV                   0x02000000
#define GL_FONT_UNDERLINE_POSITION_BIT_NV                   0x04000000
#define GL_FONT_UNDERLINE_THICKNESS_BIT_NV                  0x08000000
#define GL_FONT_HAS_KERNING_BIT_NV                          0x10000000
#define GL_FONT_NUM_GLYPH_INDICES_BIT_NV                    0x20000000
#define GL_ACCUM_ADJACENT_PAIRS_NV                          0x90AD
#define GL_ADJACENT_PAIRS_NV                                0x90AE
#define GL_FIRST_TO_REST_NV                                 0x90AF
#define GL_PATH_GEN_MODE_NV                                 0x90B0
#define GL_PATH_GEN_COEFF_NV                                0x90B1
#define GL_PATH_GEN_COLOR_FORMAT_NV                         0x90B2
#define GL_PATH_GEN_COMPONENTS_NV                           0x90B3
#define GL_PATH_STENCIL_FUNC_NV                             0x90B7
#define GL_PATH_STENCIL_REF_NV                              0x90B8
#define GL_PATH_STENCIL_VALUE_MASK_NV                       0x90B9
#define GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV              0x90BD
#define GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV               0x90BE
#define GL_PATH_COVER_DEPTH_FUNC_NV                         0x90BF
#define GL_FONT_GLYPHS_AVAILABLE_NV                         0x9368
#define GL_FONT_TARGET_UNAVAILABLE_NV                       0x9369
#define GL_FONT_UNAVAILABLE_NV                              0x936A
#define GL_FONT_UNINTELLIGIBLE_NV                           0x936B
#define GL_STANDARD_FONT_FORMAT_NV                          0x936C
#define GL_FRAGMENT_INPUT_NV                                0x936D
#define GL_PATH_MODELVIEW_STACK_DEPTH_NV                    0x0BA3
#define GL_PATH_PROJECTION_STACK_DEPTH_NV                   0x0BA4
#define GL_PATH_MODELVIEW_MATRIX_NV                         0x0BA6
#define GL_PATH_PROJECTION_MATRIX_NV                        0x0BA7
#define GL_PATH_MAX_MODELVIEW_STACK_DEPTH_NV                0x0D36
#define GL_PATH_MAX_PROJECTION_STACK_DEPTH_NV               0x0D38
#define GL_PATH_TRANSPOSE_MODELVIEW_MATRIX_NV               0x84E3
#define GL_PATH_TRANSPOSE_PROJECTION_MATRIX_NV              0x84E4

/* NV_packed_normal */
#define GL_UNSIGNED_INT_S10_S11_S11_REV_NV                  0x886B

/* NV_half_float */
#define GL_HALF_FLOAT_NV                                    0x140B

/* NV_copy_depth_to_color */
#define GL_DEPTH_STENCIL_TO_RGBA_NV                         0x886E
#define GL_DEPTH_STENCIL_TO_BGRA_NV                         0x886F

/* HP_occlusion_test */
#define GL_OCCLUSION_TEST_HP                                0x8165
#define GL_OCCLUSION_TEST_RESULT_HP                         0x8166

/* NV_occlusion_query */
#define GL_PIXEL_COUNTER_BITS_NV                            0x8864
#define GL_CURRENT_OCCLUSION_QUERY_ID_NV                    0x8865
#define GL_PIXEL_COUNT_NV                                   0x8866
#define GL_PIXEL_COUNT_AVAILABLE_NV                         0x8867

/* ARB_occlusion_query */
#define GL_QUERY_COUNTER_BITS_ARB                           0x8864
#define GL_CURRENT_QUERY_ARB                                0x8865
#define GL_QUERY_RESULT_ARB                                 0x8866
#define GL_QUERY_RESULT_AVAILABLE_ARB                       0x8867
#define GL_SAMPLES_PASSED_ARB                               0x8914

/* ARB_point_sprite */
#define GL_POINT_SPRITE_ARB                                 0x8861
#define GL_COORD_REPLACE_ARB                                0x8862

/* NV_point_sprite */
#define GL_POINT_SPRITE_NV                                  0x8861
#define GL_COORD_REPLACE_NV                                 0x8862
#define GL_POINT_SPRITE_R_MODE_NV                           0x8863

/* 3DFX_tbuffer */
#define GL_TBUFFER_WRITE_MASK_3DFX                          0x86D8

/* NV_depth_clamp */
#define GL_DEPTH_CLAMP_NV                                   0x864F

/* NV_float_buffer */
#define GL_FLOAT_R_NV                                       0x8880
#define GL_FLOAT_RG_NV                                      0x8881
#define GL_FLOAT_RGB_NV                                     0x8882
#define GL_FLOAT_RGBA_NV                                    0x8883
#define GL_FLOAT_R16_NV                                     0x8884
#define GL_FLOAT_R32_NV                                     0x8885
#define GL_FLOAT_RG16_NV                                    0x8886
#define GL_FLOAT_RG32_NV                                    0x8887
#define GL_FLOAT_RGB16_NV                                   0x8888
#define GL_FLOAT_RGB32_NV                                   0x8889
#define GL_FLOAT_RGBA16_NV                                  0x888A
#define GL_FLOAT_RGBA32_NV                                  0x888B
#define GL_TEXTURE_FLOAT_COMPONENTS_NV                      0x888C
#define GL_FLOAT_CLEAR_COLOR_VALUE_NV                       0x888D
#define GL_FLOAT_RGBA_MODE_NV                               0x888E

/* EXT_stencil_two_side */
#define GL_STENCIL_TEST_TWO_SIDE_EXT                        0x8910
#define GL_ACTIVE_STENCIL_FACE_EXT                          0x8911

/* EXT_blend_func_separate */
#define GL_BLEND_DST_RGB_EXT                                0x80C8
#define GL_BLEND_SRC_RGB_EXT                                0x80C9
#define GL_BLEND_DST_ALPHA_EXT                              0x80CA
#define GL_BLEND_SRC_ALPHA_EXT                              0x80CB

/* ARB_texture_mirrored_repeat */
#define GL_MIRRORED_REPEAT_ARB                              0x8370

/* ARB_depth_texture */
#define GL_DEPTH_COMPONENT16_ARB                            0x81A5
#define GL_DEPTH_COMPONENT24_ARB                            0x81A6
#define GL_DEPTH_COMPONENT32_ARB                            0x81A7
#define GL_TEXTURE_DEPTH_SIZE_ARB                           0x884A
#define GL_DEPTH_TEXTURE_MODE_ARB                           0x884B

/* ARB_shadow */
#define GL_TEXTURE_COMPARE_MODE_ARB                         0x884C
#define GL_TEXTURE_COMPARE_FUNC_ARB                         0x884D
#define GL_COMPARE_R_TO_TEXTURE_ARB                         0x884E

/* ARB_shadow_ambient */
#define GL_TEXTURE_COMPARE_FAIL_VALUE_ARB                   0x80BF

/* NV_force_software */
#define GL_FORCE_SOFTWARE_NV                                0x6007

/* NV_force_sysmem_texture */
#define GL_FORCE_SYSMEM_TEXTURE_NV                          0x6008

/* NV_pmapi_query */
#define GL_PMAPI_SHARED_MEMORY_POINTER_NV                   0x6009

/* ARB_point_parameters */
#define GL_POINT_SIZE_MIN_ARB                               0x8126
#define GL_POINT_SIZE_MAX_ARB                               0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_ARB                    0x8128
#define GL_POINT_DISTANCE_ATTENUATION_ARB                   0x8129

/* EXT_depth_bounds_test */
#define GL_DEPTH_BOUNDS_TEST_EXT                            0x8890
#define GL_DEPTH_BOUNDS_EXT                                 0x8891

/* EXT_debug_label */
#define GL_BUFFER_OBJECT_EXT                                0x9151
#define GL_SHADER_OBJECT_EXT                                0x8B48
#define GL_PROGRAM_OBJECT_EXT                               0x8B40
#define GL_VERTEX_ARRAY_OBJECT_EXT                          0x9154
#define GL_QUERY_OBJECT_EXT                                 0x9153
#define GL_PROGRAM_PIPELINE_OBJECT_EXT                      0x8A4F

/* EXT_direct_state_access */
#define GL_PROGRAM_MATRIX_EXT                               0x8E2D
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT                     0x8E2E
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT                   0x8E2F

/* ARB_vertex_program */
#define GL_VERTEX_PROGRAM_ARB                               0x8620
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB                    0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB                      0x8643
#define GL_COLOR_SUM_ARB                                    0x8458
#define GL_PROGRAM_FORMAT_ASCII_ARB                         0x8875
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB                  0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB                     0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB                   0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB                     0x8625
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB               0x886A
#define GL_CURRENT_VERTEX_ATTRIB_ARB                        0x8626
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB                  0x8645
#define GL_PROGRAM_LENGTH_ARB                               0x8627
#define GL_PROGRAM_FORMAT_ARB                               0x8876
#define GL_PROGRAM_BINDING_ARB                              0x8677
#define GL_PROGRAM_INSTRUCTIONS_ARB                         0x88A0
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB                     0x88A1
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB                  0x88A2
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB              0x88A3
#define GL_PROGRAM_TEMPORARIES_ARB                          0x88A4
#define GL_MAX_PROGRAM_TEMPORARIES_ARB                      0x88A5
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB                   0x88A6
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB               0x88A7
#define GL_PROGRAM_PARAMETERS_ARB                           0x88A8
#define GL_MAX_PROGRAM_PARAMETERS_ARB                       0x88A9
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB                    0x88AA
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB                0x88AB
#define GL_PROGRAM_ATTRIBS_ARB                              0x88AC
#define GL_MAX_PROGRAM_ATTRIBS_ARB                          0x88AD
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB                       0x88AE
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB                   0x88AF
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB                    0x88B0
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB                0x88B1
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB             0x88B2
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB         0x88B3
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB                 0x88B4
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB                   0x88B5
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB                  0x88B6
#define GL_PROGRAM_STRING_ARB                               0x8628
#define GL_PROGRAM_ERROR_POSITION_ARB                       0x864B
#define GL_CURRENT_MATRIX_ARB                               0x8641
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB                     0x88B7
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB                   0x8640
#define GL_MAX_VERTEX_ATTRIBS_ARB                           0x8869
#define GL_MAX_PROGRAM_MATRICES_ARB                         0x862F
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB               0x862E
#define GL_PROGRAM_ERROR_STRING_ARB                         0x8874
#define GL_MATRIX0_ARB                                      0x88C0
#define GL_MATRIX1_ARB                                      0x88C1
#define GL_MATRIX2_ARB                                      0x88C2
#define GL_MATRIX3_ARB                                      0x88C3
#define GL_MATRIX4_ARB                                      0x88C4
#define GL_MATRIX5_ARB                                      0x88C5
#define GL_MATRIX6_ARB                                      0x88C6
#define GL_MATRIX7_ARB                                      0x88C7
#define GL_MATRIX8_ARB                                      0x88C8
#define GL_MATRIX9_ARB                                      0x88C9
#define GL_MATRIX10_ARB                                     0x88CA
#define GL_MATRIX11_ARB                                     0x88CB
#define GL_MATRIX12_ARB                                     0x88CC
#define GL_MATRIX13_ARB                                     0x88CD
#define GL_MATRIX14_ARB                                     0x88CE
#define GL_MATRIX15_ARB                                     0x88CF
#define GL_MATRIX16_ARB                                     0x88D0
#define GL_MATRIX17_ARB                                     0x88D1
#define GL_MATRIX18_ARB                                     0x88D2
#define GL_MATRIX19_ARB                                     0x88D3
#define GL_MATRIX20_ARB                                     0x88D4
#define GL_MATRIX21_ARB                                     0x88D5
#define GL_MATRIX22_ARB                                     0x88D6
#define GL_MATRIX23_ARB                                     0x88D7
#define GL_MATRIX24_ARB                                     0x88D8
#define GL_MATRIX25_ARB                                     0x88D9
#define GL_MATRIX26_ARB                                     0x88DA
#define GL_MATRIX27_ARB                                     0x88DB
#define GL_MATRIX28_ARB                                     0x88DC
#define GL_MATRIX29_ARB                                     0x88DD
#define GL_MATRIX30_ARB                                     0x88DE
#define GL_MATRIX31_ARB                                     0x88DF

/* OpenGL14 */
#define GL_POINT_SIZE_MIN                                   0x8126
#define GL_POINT_SIZE_MAX                                   0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE                        0x8128
#define GL_POINT_DISTANCE_ATTENUATION                       0x8129
#define GL_FOG_COORDINATE_SOURCE                            0x8450
#define GL_FOG_COORDINATE                                   0x8451
#define GL_FRAGMENT_DEPTH                                   0x8452
#define GL_CURRENT_FOG_COORDINATE                           0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE                        0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE                      0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER                     0x8456
#define GL_FOG_COORDINATE_ARRAY                             0x8457
#define GL_COLOR_SUM                                        0x8458
#define GL_CURRENT_SECONDARY_COLOR                          0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE                       0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE                       0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE                     0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER                    0x845D
#define GL_SECONDARY_COLOR_ARRAY                            0x845E
#define GL_INCR_WRAP                                        0x8507
#define GL_DECR_WRAP                                        0x8508
#define GL_MAX_TEXTURE_LOD_BIAS                             0x84FD
#define GL_TEXTURE_FILTER_CONTROL                           0x8500
#define GL_TEXTURE_LOD_BIAS                                 0x8501
#define GL_GENERATE_MIPMAP                                  0x8191
#define GL_GENERATE_MIPMAP_HINT                             0x8192
#define GL_BLEND_DST_RGB                                    0x80C8
#define GL_BLEND_SRC_RGB                                    0x80C9
#define GL_BLEND_DST_ALPHA                                  0x80CA
#define GL_BLEND_SRC_ALPHA                                  0x80CB
#define GL_MIRRORED_REPEAT                                  0x8370
#define GL_DEPTH_COMPONENT16                                0x81A5
#define GL_DEPTH_COMPONENT24                                0x81A6
#define GL_DEPTH_COMPONENT32                                0x81A7
#define GL_TEXTURE_DEPTH_SIZE                               0x884A
#define GL_DEPTH_TEXTURE_MODE                               0x884B
#define GL_TEXTURE_COMPARE_MODE                             0x884C
#define GL_TEXTURE_COMPARE_FUNC                             0x884D
#define GL_COMPARE_R_TO_TEXTURE                             0x884E

/* SGIS_generate_mipmap */
#define GL_GENERATE_MIPMAP_SGIS                             0x8191
#define GL_GENERATE_MIPMAP_HINT_SGIS                        0x8192

/* NV_primitive_restart */
#define GL_PRIMITIVE_RESTART_NV                             0x8558
#define GL_PRIMITIVE_RESTART_INDEX_NV                       0x8559

/* SGIS_texture_color_mask */
#define GL_TEXTURE_COLOR_WRITEMASK_SGIS                     0x81EF

/* ARB_fragment_program */
#define GL_FRAGMENT_PROGRAM_ARB                             0x8804
/*      GL_PROGRAM_FORMAT_ASCII_ARB */
/*      GL_PROGRAM_LENGTH_ARB */
/*      GL_PROGRAM_FORMAT_ARB */
/*      GL_PROGRAM_BINDING_ARB */
/*      GL_PROGRAM_INSTRUCTIONS_ARB */
/*      GL_MAX_PROGRAM_INSTRUCTIONS_ARB */
/*      GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB */
/*      GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB */
/*      GL_PROGRAM_TEMPORARIES_ARB */
/*      GL_MAX_PROGRAM_TEMPORARIES_ARB */
/*      GL_PROGRAM_NATIVE_TEMPORARIES_ARB */
/*      GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB */
/*      GL_PROGRAM_PARAMETERS_ARB */
/*      GL_MAX_PROGRAM_PARAMETERS_ARB */
/*      GL_PROGRAM_NATIVE_PARAMETERS_ARB */
/*      GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB */
/*      GL_PROGRAM_ATTRIBS_ARB */
/*      GL_MAX_PROGRAM_ATTRIBS_ARB */
/*      GL_PROGRAM_NATIVE_ATTRIBS_ARB */
/*      GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB */
/*      GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB */
/*      GL_MAX_PROGRAM_ENV_PARAMETERS_ARB */
/*      GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB */
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB                     0x8805
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB                     0x8806
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB                     0x8807
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB              0x8808
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB              0x8809
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB              0x880A
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB                 0x880B
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB                 0x880C
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB                 0x880D
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB          0x880E
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB          0x880F
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB          0x8810
/*      GL_PROGRAM_STRING_ARB */
/*      GL_PROGRAM_ERROR_POSITION_ARB */
/*      GL_CURRENT_MATRIX_ARB */
/*      GL_TRANSPOSE_CURRENT_MATRIX_ARB */
/*      GL_CURRENT_MATRIX_STACK_DEPTH_ARB */
/*      GL_MAX_PROGRAM_MATRICES_ARB */
/*      GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB */
#define GL_MAX_TEXTURE_COORDS_ARB                           0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB                      0x8872
/*      GL_PROGRAM_ERROR_STRING_ARB */
/*      GL_MATRIX0_ARB */
/*      GL_MATRIX1_ARB */
/*      GL_MATRIX2_ARB */
/*      GL_MATRIX3_ARB */
/*      GL_MATRIX4_ARB */
/*      GL_MATRIX5_ARB */
/*      GL_MATRIX6_ARB */
/*      GL_MATRIX7_ARB */
/*      GL_MATRIX8_ARB */
/*      GL_MATRIX9_ARB */
/*      GL_MATRIX10_ARB */
/*      GL_MATRIX11_ARB */
/*      GL_MATRIX12_ARB */
/*      GL_MATRIX13_ARB */
/*      GL_MATRIX14_ARB */
/*      GL_MATRIX15_ARB */
/*      GL_MATRIX16_ARB */
/*      GL_MATRIX17_ARB */
/*      GL_MATRIX18_ARB */
/*      GL_MATRIX19_ARB */
/*      GL_MATRIX20_ARB */
/*      GL_MATRIX21_ARB */
/*      GL_MATRIX22_ARB */
/*      GL_MATRIX23_ARB */
/*      GL_MATRIX24_ARB */
/*      GL_MATRIX25_ARB */
/*      GL_MATRIX26_ARB */
/*      GL_MATRIX27_ARB */
/*      GL_MATRIX28_ARB */
/*      GL_MATRIX29_ARB */
/*      GL_MATRIX30_ARB */
/*      GL_MATRIX31_ARB */
/*      GL_PROGRAM_ERROR_STRING_ARB */
/*      GL_MATRIX0_ARB */
/*      GL_MATRIX1_ARB */
/*      GL_MATRIX2_ARB */
/*      GL_MATRIX3_ARB */
/*      GL_MATRIX4_ARB */
/*      GL_MATRIX5_ARB */
/*      GL_MATRIX6_ARB */
/*      GL_MATRIX7_ARB */
/*      GL_MATRIX8_ARB */
/*      GL_MATRIX9_ARB */
/*      GL_MATRIX10_ARB */
/*      GL_MATRIX11_ARB */
/*      GL_MATRIX12_ARB */
/*      GL_MATRIX13_ARB */
/*      GL_MATRIX14_ARB */
/*      GL_MATRIX15_ARB */
/*      GL_MATRIX16_ARB */
/*      GL_MATRIX17_ARB */
/*      GL_MATRIX18_ARB */
/*      GL_MATRIX19_ARB */
/*      GL_MATRIX20_ARB */
/*      GL_MATRIX21_ARB */
/*      GL_MATRIX22_ARB */
/*      GL_MATRIX23_ARB */
/*      GL_MATRIX24_ARB */
/*      GL_MATRIX25_ARB */
/*      GL_MATRIX26_ARB */
/*      GL_MATRIX27_ARB */
/*      GL_MATRIX28_ARB */
/*      GL_MATRIX29_ARB */
/*      GL_MATRIX30_ARB */
/*      GL_MATRIX31_ARB */

/* ARB_vertex_buffer_object */
#define GL_ARRAY_BUFFER_ARB                                 0x8892
#define GL_ELEMENT_ARRAY_BUFFER_ARB                         0x8893
#define GL_ARRAY_BUFFER_BINDING_ARB                         0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB                 0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING_ARB                  0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING_ARB                  0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING_ARB                   0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING_ARB                   0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB           0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB               0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB         0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB          0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB                  0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB           0x889F
#define GL_STREAM_DRAW_ARB                                  0x88E0
#define GL_STREAM_READ_ARB                                  0x88E1
#define GL_STREAM_COPY_ARB                                  0x88E2
#define GL_STATIC_DRAW_ARB                                  0x88E4
#define GL_STATIC_READ_ARB                                  0x88E5
#define GL_STATIC_COPY_ARB                                  0x88E6
#define GL_DYNAMIC_DRAW_ARB                                 0x88E8
#define GL_DYNAMIC_READ_ARB                                 0x88E9
#define GL_DYNAMIC_COPY_ARB                                 0x88EA
#define GL_READ_ONLY_ARB                                    0x88B8
#define GL_WRITE_ONLY_ARB                                   0x88B9
#define GL_READ_WRITE_ARB                                   0x88BA
#define GL_BUFFER_SIZE_ARB                                  0x8764
#define GL_BUFFER_USAGE_ARB                                 0x8765
#define GL_BUFFER_ACCESS_ARB                                0x88BB
#define GL_BUFFER_MAPPED_ARB                                0x88BC
#define GL_BUFFER_MAP_POINTER_ARB                           0x88BD

/* EXT_pixel_buffer_object */
#define GL_PIXEL_PACK_BUFFER_EXT                            0x88EB
#define GL_PIXEL_UNPACK_BUFFER_EXT                          0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_EXT                    0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_EXT                  0x88EF

/* NV_transform_feedback */
#define GL_BACK_PRIMARY_COLOR_NV                            0x8C77
#define GL_BACK_SECONDARY_COLOR_NV                          0x8C78
#define GL_TEXTURE_COORD_NV                                 0x8C79
#define GL_CLIP_DISTANCE_NV                                 0x8C7A
#define GL_VERTEX_ID_NV                                     0x8C7B
#define GL_PRIMITIVE_ID_NV                                  0x8C7C
#define GL_GENERIC_ATTRIB_NV                                0x8C7D
#define GL_TRANSFORM_FEEDBACK_ATTRIBS_NV                    0x8C7E
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV                0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV    0x8C80
#define GL_ACTIVE_VARYINGS_NV                               0x8C81
#define GL_ACTIVE_VARYING_MAX_LENGTH_NV                     0x8C82
#define GL_TRANSFORM_FEEDBACK_VARYINGS_NV                   0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_NV               0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV                0x8C85
#define GL_TRANSFORM_FEEDBACK_RECORD_NV                     0x8C86
#define GL_PRIMITIVES_GENERATED_NV                          0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV         0x8C88
#define GL_RASTERIZER_DISCARD_NV                            0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV       0x8C8B
#define GL_INTERLEAVED_ATTRIBS_NV                           0x8C8C
#define GL_SEPARATE_ATTRIBS_NV                              0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER_NV                     0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV             0x8C8F
#define GL_LAYER_NV                                         0x8DAA

/* NV_transform_feedback2 */
#define GL_TRANSFORM_FEEDBACK_NV                            0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV              0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV              0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING_NV                    0x8E25

/* EXT_transform_feedback2 */
#define GL_TRANSFORM_FEEDBACK_EXT                           0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_EXT             0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_EXT             0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING_EXT                   0x8E25

/* IBM_rasterpos_clip */
#define GL_RASTER_POSITION_UNCLIPPED_IBM                    0x19262

/* ATI_texture_mirror_once */
#define GL_MIRROR_CLAMP_ATI                                 0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_ATI                         0x8743

/* ATI_texture_env_combine3 */
#define GL_MODULATE_ADD_ATI                                 0x8744
#define GL_MODULATE_SIGNED_ADD_ATI                          0x8745
#define GL_MODULATE_SUBTRACT_ATI                            0x8746

/* ATI_texture_float */
#define GL_RGBA_FLOAT32_ATI                                 0x8814
#define GL_RGB_FLOAT32_ATI                                  0x8815
#define GL_ALPHA_FLOAT32_ATI                                0x8816
#define GL_INTENSITY_FLOAT32_ATI                            0x8817
#define GL_LUMINANCE_FLOAT32_ATI                            0x8818
#define GL_LUMINANCE_ALPHA_FLOAT32_ATI                      0x8819
#define GL_RGBA_FLOAT16_ATI                                 0x881A
#define GL_RGB_FLOAT16_ATI                                  0x881B
#define GL_ALPHA_FLOAT16_ATI                                0x881C
#define GL_INTENSITY_FLOAT16_ATI                            0x881D
#define GL_LUMINANCE_FLOAT16_ATI                            0x881E
#define GL_LUMINANCE_ALPHA_FLOAT16_ATI                      0x881F

/* ATI_pixel_format_float */
#define GL_RGBA_FLOAT_MODE_ATI                              0x8820
#define GL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI                  0x8835

/* ATI_draw_buffers */
#define GL_MAX_DRAW_BUFFERS_ATI                             0x8824
#define GL_DRAW_BUFFER0_ATI                                 0x8825
#define GL_DRAW_BUFFER1_ATI                                 0x8826
#define GL_DRAW_BUFFER2_ATI                                 0x8827
#define GL_DRAW_BUFFER3_ATI                                 0x8828
#define GL_DRAW_BUFFER4_ATI                                 0x8829
#define GL_DRAW_BUFFER5_ATI                                 0x882A
#define GL_DRAW_BUFFER6_ATI                                 0x882B
#define GL_DRAW_BUFFER7_ATI                                 0x882C
#define GL_DRAW_BUFFER8_ATI                                 0x882D
#define GL_DRAW_BUFFER9_ATI                                 0x882E
#define GL_DRAW_BUFFER10_ATI                                0x882F
#define GL_DRAW_BUFFER11_ATI                                0x8830
#define GL_DRAW_BUFFER12_ATI                                0x8831
#define GL_DRAW_BUFFER13_ATI                                0x8832
#define GL_DRAW_BUFFER14_ATI                                0x8833
#define GL_DRAW_BUFFER15_ATI                                0x8834

/* ARB_draw_buffers */
#define GL_MAX_DRAW_BUFFERS_ARB                             0x8824
#define GL_DRAW_BUFFER0_ARB                                 0x8825
#define GL_DRAW_BUFFER1_ARB                                 0x8826
#define GL_DRAW_BUFFER2_ARB                                 0x8827
#define GL_DRAW_BUFFER3_ARB                                 0x8828
#define GL_DRAW_BUFFER4_ARB                                 0x8829
#define GL_DRAW_BUFFER5_ARB                                 0x882A
#define GL_DRAW_BUFFER6_ARB                                 0x882B
#define GL_DRAW_BUFFER7_ARB                                 0x882C
#define GL_DRAW_BUFFER8_ARB                                 0x882D
#define GL_DRAW_BUFFER9_ARB                                 0x882E
#define GL_DRAW_BUFFER10_ARB                                0x882F
#define GL_DRAW_BUFFER11_ARB                                0x8830
#define GL_DRAW_BUFFER12_ARB                                0x8831
#define GL_DRAW_BUFFER13_ARB                                0x8832
#define GL_DRAW_BUFFER14_ARB                                0x8833
#define GL_DRAW_BUFFER15_ARB                                0x8834

/* NV_depth_buffer_float */
#define GL_DEPTH_COMPONENT32F_NV                            0x8DAB
#define GL_DEPTH32F_STENCIL8_NV                             0x8DAC
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV                0x8DAD
#define GL_DEPTH_BUFFER_FLOAT_MODE_NV                       0x8DAF

/* EXT_texture_mirror_clamp */
#define GL_MIRROR_CLAMP_EXT                                 0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_EXT                         0x8743
#define GL_MIRROR_CLAMP_TO_BORDER_EXT                       0x8912

/* EXT_blend_equation_separate */
#define GL_BLEND_EQUATION_RGB_EXT                           0x8009
#define GL_BLEND_EQUATION_ALPHA_EXT                         0x883D

/* ARB_shader_objects */
#define GL_PROGRAM_OBJECT_ARB                               0x8B40
#define GL_SHADER_OBJECT_ARB                                0x8B48
#define GL_OBJECT_TYPE_ARB                                  0x8B4E
#define GL_OBJECT_SUBTYPE_ARB                               0x8B4F
#define GL_OBJECT_DELETE_STATUS_ARB                         0x8B80
#define GL_OBJECT_COMPILE_STATUS_ARB                        0x8B81
#define GL_OBJECT_LINK_STATUS_ARB                           0x8B82
#define GL_OBJECT_VALIDATE_STATUS_ARB                       0x8B83
#define GL_OBJECT_INFO_LOG_LENGTH_ARB                       0x8B84
#define GL_OBJECT_ATTACHED_OBJECTS_ARB                      0x8B85
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB                       0x8B86
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB             0x8B87
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB                  0x8B88
#define GL_FLOAT_VEC2_ARB                                   0x8B50
#define GL_FLOAT_VEC3_ARB                                   0x8B51
#define GL_FLOAT_VEC4_ARB                                   0x8B52
#define GL_INT_VEC2_ARB                                     0x8B53
#define GL_INT_VEC3_ARB                                     0x8B54
#define GL_INT_VEC4_ARB                                     0x8B55
#define GL_BOOL_ARB                                         0x8B56
#define GL_BOOL_VEC2_ARB                                    0x8B57
#define GL_BOOL_VEC3_ARB                                    0x8B58
#define GL_BOOL_VEC4_ARB                                    0x8B59
#define GL_FLOAT_MAT2_ARB                                   0x8B5A
#define GL_FLOAT_MAT3_ARB                                   0x8B5B
#define GL_FLOAT_MAT4_ARB                                   0x8B5C
#define GL_SAMPLER_1D_ARB                                   0x8B5D
#define GL_SAMPLER_2D_ARB                                   0x8B5E
#define GL_SAMPLER_3D_ARB                                   0x8B5F
#define GL_SAMPLER_CUBE_ARB                                 0x8B60
#define GL_SAMPLER_1D_SHADOW_ARB                            0x8B61
#define GL_SAMPLER_2D_SHADOW_ARB                            0x8B62
#define GL_SAMPLER_2D_RECT_ARB                              0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW_ARB                       0x8B64

/* ARB_shading_language_100 */
#define GL_SHADING_LANGUAGE_VERSION_ARB                     0x8B8C

/* ARB_vertex_shader */
#define GL_VERTEX_SHADER_ARB                                0x8B31
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB                0x8B4A
#define GL_MAX_VARYING_FLOATS_ARB                           0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB               0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB             0x8B4D
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB                     0x8B89
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB           0x8B8A

/* ARB_fragment_shader */
#define GL_FRAGMENT_SHADER_ARB                              0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB              0x8B49
#define GL_DERIVATIVE_ACCURACY_HINT_ARB                     0x8B8B

/* EXT_Cg_shader */
#define GL_CG_VERTEX_SHADER_EXT                             0x890E
#define GL_CG_FRAGMENT_SHADER_EXT                           0x890F

/* EXT_separate_shader_objects */
#define GL_ACTIVE_PROGRAM_EXT                               0x8B8D
#define GL_VERTEX_SHADER_BIT_EXT                            0x00000001
#define GL_FRAGMENT_SHADER_BIT_EXT                          0x00000002
#define GL_ALL_SHADER_BITS_EXT                              0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE_EXT                            0x8258
#define GL_PROGRAM_PIPELINE_BINDING_EXT                     0x825A

/* OpenGL15 */
#define GL_FOG_COORD_SRC                                    0x8450
#define GL_FOG_COORD                                        0x8451
#define GL_CURRENT_FOG_COORD                                0x8453
#define GL_FOG_COORD_ARRAY_TYPE                             0x8454
#define GL_FOG_COORD_ARRAY_STRIDE                           0x8455
#define GL_FOG_COORD_ARRAY_POINTER                          0x8456
#define GL_FOG_COORD_ARRAY                                  0x8457
#define GL_SRC0_RGB                                         0x8580
#define GL_SRC1_RGB                                         0x8581
#define GL_SRC2_RGB                                         0x8582
#define GL_SRC0_ALPHA                                       0x8588
#define GL_SRC1_ALPHA                                       0x8589
#define GL_SRC2_ALPHA                                       0x858A
#define GL_QUERY_COUNTER_BITS                               0x8864
#define GL_CURRENT_QUERY                                    0x8865
#define GL_QUERY_RESULT                                     0x8866
#define GL_QUERY_RESULT_AVAILABLE                           0x8867
#define GL_SAMPLES_PASSED                                   0x8914
#define GL_ARRAY_BUFFER                                     0x8892
#define GL_ELEMENT_ARRAY_BUFFER                             0x8893
#define GL_ARRAY_BUFFER_BINDING                             0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING                     0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING                      0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING                      0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING                       0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING                       0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING               0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING                   0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING             0x889C
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING                   0x889D
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING               0x889F
#define GL_STREAM_DRAW                                      0x88E0
#define GL_STREAM_READ                                      0x88E1
#define GL_STREAM_COPY                                      0x88E2
#define GL_STATIC_DRAW                                      0x88E4
#define GL_STATIC_READ                                      0x88E5
#define GL_STATIC_COPY                                      0x88E6
#define GL_DYNAMIC_DRAW                                     0x88E8
#define GL_DYNAMIC_READ                                     0x88E9
#define GL_DYNAMIC_COPY                                     0x88EA
#define GL_READ_ONLY                                        0x88B8
#define GL_WRITE_ONLY                                       0x88B9
#define GL_READ_WRITE                                       0x88BA
#define GL_BUFFER_SIZE                                      0x8764
#define GL_BUFFER_USAGE                                     0x8765
#define GL_BUFFER_ACCESS                                    0x88BB
#define GL_BUFFER_MAPPED                                    0x88BC
#define GL_BUFFER_MAP_POINTER                               0x88BD

/* OpenGL20 */
#define GL_CURRENT_PROGRAM                                  0x8B8D
#define GL_SHADER_TYPE                                      0x8B4F
#define GL_DELETE_STATUS                                    0x8B80
#define GL_COMPILE_STATUS                                   0x8B81
#define GL_LINK_STATUS                                      0x8B82
#define GL_VALIDATE_STATUS                                  0x8B83
#define GL_INFO_LOG_LENGTH                                  0x8B84
#define GL_ATTACHED_SHADERS                                 0x8B85
#define GL_ACTIVE_UNIFORMS                                  0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH                        0x8B87
#define GL_SHADER_SOURCE_LENGTH                             0x8B88
#define GL_FLOAT_VEC2                                       0x8B50
#define GL_FLOAT_VEC3                                       0x8B51
#define GL_FLOAT_VEC4                                       0x8B52
#define GL_INT_VEC2                                         0x8B53
#define GL_INT_VEC3                                         0x8B54
#define GL_INT_VEC4                                         0x8B55
#define GL_BOOL                                             0x8B56
#define GL_BOOL_VEC2                                        0x8B57
#define GL_BOOL_VEC3                                        0x8B58
#define GL_BOOL_VEC4                                        0x8B59
#define GL_FLOAT_MAT2                                       0x8B5A
#define GL_FLOAT_MAT3                                       0x8B5B
#define GL_FLOAT_MAT4                                       0x8B5C
#define GL_SAMPLER_1D                                       0x8B5D
#define GL_SAMPLER_2D                                       0x8B5E
#define GL_SAMPLER_3D                                       0x8B5F
#define GL_SAMPLER_CUBE                                     0x8B60
#define GL_SAMPLER_1D_SHADOW                                0x8B61
#define GL_SAMPLER_2D_SHADOW                                0x8B62
#define GL_SHADING_LANGUAGE_VERSION                         0x8B8C
#define GL_VERTEX_SHADER                                    0x8B31
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS                    0x8B4A
#define GL_MAX_VARYING_FLOATS                               0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS                   0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS                 0x8B4D
#define GL_ACTIVE_ATTRIBUTES                                0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH                      0x8B8A
#define GL_FRAGMENT_SHADER                                  0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS                  0x8B49
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT                  0x8B8B
#define GL_MAX_VERTEX_ATTRIBS                               0x8869
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED                      0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE                         0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE                       0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE                         0x8625
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED                   0x886A
#define GL_CURRENT_VERTEX_ATTRIB                            0x8626
#define GL_VERTEX_ATTRIB_ARRAY_POINTER                      0x8645
#define GL_VERTEX_PROGRAM_POINT_SIZE                        0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE                          0x8643
#define GL_MAX_TEXTURE_COORDS                               0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS                          0x8872
#define GL_MAX_DRAW_BUFFERS                                 0x8824
#define GL_DRAW_BUFFER0                                     0x8825
#define GL_DRAW_BUFFER1                                     0x8826
#define GL_DRAW_BUFFER2                                     0x8827
#define GL_DRAW_BUFFER3                                     0x8828
#define GL_DRAW_BUFFER4                                     0x8829
#define GL_DRAW_BUFFER5                                     0x882A
#define GL_DRAW_BUFFER6                                     0x882B
#define GL_DRAW_BUFFER7                                     0x882C
#define GL_DRAW_BUFFER8                                     0x882D
#define GL_DRAW_BUFFER9                                     0x882E
#define GL_DRAW_BUFFER10                                    0x882F
#define GL_DRAW_BUFFER11                                    0x8830
#define GL_DRAW_BUFFER12                                    0x8831
#define GL_DRAW_BUFFER13                                    0x8832
#define GL_DRAW_BUFFER14                                    0x8833
#define GL_DRAW_BUFFER15                                    0x8834
#define GL_POINT_SPRITE                                     0x8861
#define GL_COORD_REPLACE                                    0x8862
#define GL_POINT_SPRITE_COORD_ORIGIN                        0x8CA0
#define GL_LOWER_LEFT                                       0x8CA1
#define GL_UPPER_LEFT                                       0x8CA2
#define GL_STENCIL_BACK_FUNC                                0x8800
#define GL_STENCIL_BACK_VALUE_MASK                          0x8CA4
#define GL_STENCIL_BACK_REF                                 0x8CA3
#define GL_STENCIL_BACK_FAIL                                0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL                     0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS                     0x8803
#define GL_STENCIL_BACK_WRITEMASK                           0x8CA5

/* NV_vertex_program2_option */
#define GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV                 0x88F4
#define GL_MAX_PROGRAM_CALL_DEPTH_NV                        0x88F5

/* NV_fragment_program2 */
/*      GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV */
/*      GL_MAX_PROGRAM_CALL_DEPTH_NV */
#define GL_MAX_PROGRAM_IF_DEPTH_NV                          0x88F6
#define GL_MAX_PROGRAM_LOOP_DEPTH_NV                        0x88F7
#define GL_MAX_PROGRAM_LOOP_COUNT_NV                        0x88F8

/* EXT_framebuffer_object */
#define GL_FRAMEBUFFER_EXT                                  0x8D40
#define GL_RENDERBUFFER_EXT                                 0x8D41
#define GL_STENCIL_INDEX_EXT                                0x8D45
#define GL_STENCIL_INDEX1_EXT                               0x8D46
#define GL_STENCIL_INDEX4_EXT                               0x8D47
#define GL_STENCIL_INDEX8_EXT                               0x8D48
#define GL_STENCIL_INDEX16_EXT                              0x8D49
#define GL_RENDERBUFFER_WIDTH_EXT                           0x8D42
#define GL_RENDERBUFFER_HEIGHT_EXT                          0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT                 0x8D44
#define GL_RENDERBUFFER_RED_SIZE_EXT                        0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE_EXT                      0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE_EXT                       0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE_EXT                      0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE_EXT                      0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE_EXT                    0x8D55
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT           0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT           0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT         0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT    0x8CD4
#define GL_COLOR_ATTACHMENT0_EXT                            0x8CE0
#define GL_COLOR_ATTACHMENT1_EXT                            0x8CE1
#define GL_COLOR_ATTACHMENT2_EXT                            0x8CE2
#define GL_COLOR_ATTACHMENT3_EXT                            0x8CE3
#define GL_COLOR_ATTACHMENT4_EXT                            0x8CE4
#define GL_COLOR_ATTACHMENT5_EXT                            0x8CE5
#define GL_COLOR_ATTACHMENT6_EXT                            0x8CE6
#define GL_COLOR_ATTACHMENT7_EXT                            0x8CE7
#define GL_COLOR_ATTACHMENT8_EXT                            0x8CE8
#define GL_COLOR_ATTACHMENT9_EXT                            0x8CE9
#define GL_COLOR_ATTACHMENT10_EXT                           0x8CEA
#define GL_COLOR_ATTACHMENT11_EXT                           0x8CEB
#define GL_COLOR_ATTACHMENT12_EXT                           0x8CEC
#define GL_COLOR_ATTACHMENT13_EXT                           0x8CED
#define GL_COLOR_ATTACHMENT14_EXT                           0x8CEE
#define GL_COLOR_ATTACHMENT15_EXT                           0x8CEF
#define GL_DEPTH_ATTACHMENT_EXT                             0x8D00
#define GL_STENCIL_ATTACHMENT_EXT                           0x8D20
#define GL_FRAMEBUFFER_COMPLETE_EXT                         0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT            0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT    0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT            0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT               0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT           0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT           0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT                      0x8CDD
#define GL_FRAMEBUFFER_BINDING_EXT                          0x8CA6
#define GL_RENDERBUFFER_BINDING_EXT                         0x8CA7
#define GL_MAX_COLOR_ATTACHMENTS_EXT                        0x8CDF
#define GL_MAX_RENDERBUFFER_SIZE_EXT                        0x84E8
#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT                0x0506

/* ARB_texture_float */
#define GL_TEXTURE_RED_TYPE_ARB                             0x8C10
#define GL_TEXTURE_GREEN_TYPE_ARB                           0x8C11
#define GL_TEXTURE_BLUE_TYPE_ARB                            0x8C12
#define GL_TEXTURE_ALPHA_TYPE_ARB                           0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE_ARB                       0x8C14
#define GL_TEXTURE_INTENSITY_TYPE_ARB                       0x8C15
#define GL_TEXTURE_DEPTH_TYPE_ARB                           0x8C16
#define GL_UNSIGNED_NORMALIZED_ARB                          0x8C17
#define GL_RGBA32F_ARB                                      0x8814
#define GL_RGB32F_ARB                                       0x8815
#define GL_ALPHA32F_ARB                                     0x8816
#define GL_INTENSITY32F_ARB                                 0x8817
#define GL_LUMINANCE32F_ARB                                 0x8818
#define GL_LUMINANCE_ALPHA32F_ARB                           0x8819
#define GL_RGBA16F_ARB                                      0x881A
#define GL_RGB16F_ARB                                       0x881B
#define GL_ALPHA16F_ARB                                     0x881C
#define GL_INTENSITY16F_ARB                                 0x881D
#define GL_LUMINANCE16F_ARB                                 0x881E
#define GL_LUMINANCE_ALPHA16F_ARB                           0x881F

/* ARB_half_float_pixel */
#define GL_HALF_FLOAT_ARB                                   0x140B

/* ARB_color_buffer_float */
#define GL_RGBA_FLOAT_MODE_ARB                              0x8820
#define GL_CLAMP_VERTEX_COLOR_ARB                           0x891A
#define GL_CLAMP_FRAGMENT_COLOR_ARB                         0x891B
#define GL_CLAMP_READ_COLOR_ARB                             0x891C
#define GL_FIXED_ONLY_ARB                                   0x891D

/* EXT_ycbcr_422 */
#define GL_CBYCRY_422_EXT                                   0x8C20
#define GL_YCBYCR_422_EXT                                   0x8C21
#define GL_TRANSFORM_YUV_TO_RGB_WITH_BT_601_EXT             0x8C22
#define GL_TRANSFORM_YUV_TO_RGB_WITH_BT_709_EXT             0x8C23
#define GL_TRANSFORM_RGB_TO_YUV_WITH_BT_601_EXT             0x8C24
#define GL_TRANSFORM_RGB_TO_YUV_WITH_BT_709_EXT             0x8C25

/* ARB_pixel_buffer_object */
#define GL_PIXEL_PACK_BUFFER_ARB                            0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB                          0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB                    0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB                  0x88EF

/* EXT_timer_query */
#define GL_TIME_ELAPSED_EXT                                 0x88BF

/* EXT_disjoint_timer_query */
#define GL_QUERY_COUNTER_BITS_EXT                           0x8864
#define GL_CURRENT_QUERY_EXT                                0x8865
#define GL_QUERY_RESULT_EXT                                 0x8866
#define GL_QUERY_RESULT_AVAILABLE_EXT                       0x8867
#define GL_TIMESTAMP_EXT                                    0x8E28
#define GL_GPU_DISJOINT_EXT                                 0x8EBB

/* NV_geometry_program4 */
#define GL_GEOMETRY_PROGRAM_NV                              0x8C26
#define GL_MAX_PROGRAM_OUTPUT_VERTICES_NV                   0x8C27
#define GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV           0x8C28
#define GL_GEOMETRY_VERTICES_OUT_EXT                        0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_EXT                          0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_EXT                         0x8DDC
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT             0x8C29
#define GL_LINES_ADJACENCY_EXT                              0xA
#define GL_LINE_STRIP_ADJACENCY_EXT                         0xB
#define GL_TRIANGLES_ADJACENCY_EXT                          0xC
#define GL_TRIANGLE_STRIP_ADJACENCY_EXT                     0xD
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT               0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT         0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT           0x8DA9
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT         0x8CD4
#define GL_PROGRAM_POINT_SIZE_EXT                           0x8642

/* NV_vertex_program4 */
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV                   0x88FD

/* EXT_texture_sRGB */
#define GL_SRGB_EXT                                         0x8C40
#define GL_SRGB8_EXT                                        0x8C41
#define GL_SRGB_ALPHA_EXT                                   0x8C42
#define GL_SRGB8_ALPHA8_EXT                                 0x8C43
#define GL_SLUMINANCE_ALPHA_EXT                             0x8C44
#define GL_SLUMINANCE8_ALPHA8_EXT                           0x8C45
#define GL_SLUMINANCE_EXT                                   0x8C46
#define GL_SLUMINANCE8_EXT                                  0x8C47
#define GL_COMPRESSED_SRGB_EXT                              0x8C48
#define GL_COMPRESSED_SRGB_ALPHA_EXT                        0x8C49
#define GL_COMPRESSED_SLUMINANCE_EXT                        0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA_EXT                  0x8C4B
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT                    0x8C4C
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT              0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT              0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT              0x8C4F

/* EXT_texture_sRGB_decode */
#define GL_TEXTURE_SRGB_DECODE_EXT                          0x8A48
#define GL_DECODE_EXT                                       0x8A49
#define GL_SKIP_DECODE_EXT                                  0x8A4A

/* EXT_texture_shared_exponent */
#define GL_RGB9_E5_EXT                                      0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV_EXT                     0x8C3E
#define GL_TEXTURE_SHARED_SIZE_EXT                          0x8C3F

/* EXT_packed_float */
#define GL_R11F_G11F_B10F_EXT                               0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV_EXT                 0x8C3B
#define GL_RGBA_SIGNED_COMPONENTS_EXT                       0x8C3C

/* NV_packed_float */
#define GL_R11F_G11F_B10F_NV                                0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV_NV                  0x8C3B

/* EXT_texture_array */
#define GL_TEXTURE_1D_ARRAY_EXT                             0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY_EXT                       0x8C19
#define GL_TEXTURE_2D_ARRAY_EXT                             0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY_EXT                       0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY_EXT                     0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY_EXT                     0x8C1D
#define GL_MAX_ARRAY_TEXTURE_LAYERS_EXT                     0x88FF
#define GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT                 0x884E
/*      GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT */

/* NV_gpu_program4 */
#define GL_PROGRAM_ATTRIB_COMPONENTS_NV                     0x8906
#define GL_PROGRAM_RESULT_COMPONENTS_NV                     0x8907
#define GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV                 0x8908
#define GL_MAX_PROGRAM_RESULT_COMPONENTS_NV                 0x8909
#define GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV                   0x8DA5
#define GL_MAX_PROGRAM_GENERIC_RESULTS_NV                   0x8DA6
/*      GL_MIN_PROGRAM_TEXEL_OFFSET_EXT */
/*      GL_MAX_PROGRAM_TEXEL_OFFSET_EXT */

/* EXT_texture_integer */
#define GL_RGBA32UI_EXT                                     0x8D70
#define GL_RGB32UI_EXT                                      0x8D71
#define GL_ALPHA32UI_EXT                                    0x8D72
#define GL_INTENSITY32UI_EXT                                0x8D73
#define GL_LUMINANCE32UI_EXT                                0x8D74
#define GL_LUMINANCE_ALPHA32UI_EXT                          0x8D75
#define GL_RGBA16UI_EXT                                     0x8D76
#define GL_RGB16UI_EXT                                      0x8D77
#define GL_ALPHA16UI_EXT                                    0x8D78
#define GL_INTENSITY16UI_EXT                                0x8D79
#define GL_LUMINANCE16UI_EXT                                0x8D7A
#define GL_LUMINANCE_ALPHA16UI_EXT                          0x8D7B
#define GL_RGBA8UI_EXT                                      0x8D7C
#define GL_RGB8UI_EXT                                       0x8D7D
#define GL_ALPHA8UI_EXT                                     0x8D7E
#define GL_INTENSITY8UI_EXT                                 0x8D7F
#define GL_LUMINANCE8UI_EXT                                 0x8D80
#define GL_LUMINANCE_ALPHA8UI_EXT                           0x8D81
#define GL_RGBA32I_EXT                                      0x8D82
#define GL_RGB32I_EXT                                       0x8D83
#define GL_ALPHA32I_EXT                                     0x8D84
#define GL_INTENSITY32I_EXT                                 0x8D85
#define GL_LUMINANCE32I_EXT                                 0x8D86
#define GL_LUMINANCE_ALPHA32I_EXT                           0x8D87
#define GL_RGBA16I_EXT                                      0x8D88
#define GL_RGB16I_EXT                                       0x8D89
#define GL_ALPHA16I_EXT                                     0x8D8A
#define GL_INTENSITY16I_EXT                                 0x8D8B
#define GL_LUMINANCE16I_EXT                                 0x8D8C
#define GL_LUMINANCE_ALPHA16I_EXT                           0x8D8D
#define GL_RGBA8I_EXT                                       0x8D8E
#define GL_RGB8I_EXT                                        0x8D8F
#define GL_ALPHA8I_EXT                                      0x8D90
#define GL_INTENSITY8I_EXT                                  0x8D91
#define GL_LUMINANCE8I_EXT                                  0x8D92
#define GL_LUMINANCE_ALPHA8I_EXT                            0x8D93
#define GL_RED_INTEGER_EXT                                  0x8D94
#define GL_GREEN_INTEGER_EXT                                0x8D95
#define GL_BLUE_INTEGER_EXT                                 0x8D96
#define GL_ALPHA_INTEGER_EXT                                0x8D97
#define GL_RGB_INTEGER_EXT                                  0x8D98
#define GL_RGBA_INTEGER_EXT                                 0x8D99
#define GL_BGR_INTEGER_EXT                                  0x8D9A
#define GL_BGRA_INTEGER_EXT                                 0x8D9B
#define GL_LUMINANCE_INTEGER_EXT                            0x8D9C
#define GL_LUMINANCE_ALPHA_INTEGER_EXT                      0x8D9D
#define GL_RGBA_INTEGER_MODE_EXT                            0x8D9E

/* NV_parameter_buffer_object */
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV         0x8DA0
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV             0x8DA1
#define GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV               0x8DA2
#define GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV             0x8DA3
#define GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV             0x8DA4

/* EXT_framebuffer_blit */
#define GL_READ_FRAMEBUFFER_EXT                             0x8CA8
#define GL_DRAW_FRAMEBUFFER_EXT                             0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING_EXT                     0x8CA6
#define GL_READ_FRAMEBUFFER_BINDING_EXT                     0x8CAA

/* BlitFramebufferBufferMask */
/*      GL_COLOR_BUFFER_BIT */
/*      GL_STENCIL_BUFFER_BIT */
/*      GL_DEPTH_BUFFER_BIT */

/* BlitFramebufferFilter */
/*      GL_NEAREST */
/*      GL_LINEAR */

/* EXT_framebuffer_multisample */
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT           0x8D56
#define GL_MAX_SAMPLES_EXT                                  0x8D57
#define GL_RENDERBUFFER_SAMPLES_EXT                         0x8CAB

/* EXT_texture_buffer_object */
#define GL_TEXTURE_BUFFER_EXT                               0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_EXT                      0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_EXT                       0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT            0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_EXT                        0x8C2E

/* ARB_texture_buffer_object */
#define GL_TEXTURE_BUFFER_ARB                               0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_ARB                      0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_ARB                       0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB            0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_ARB                        0x8C2E

/* EXT_gpu_shader4 */
#define GL_SAMPLER_1D_ARRAY_EXT                             0x8DC0
#define GL_SAMPLER_2D_ARRAY_EXT                             0x8DC1
#define GL_SAMPLER_BUFFER_EXT                               0x8DC2
#define GL_SAMPLER_1D_ARRAY_SHADOW_EXT                      0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW_EXT                      0x8DC4
#define GL_SAMPLER_CUBE_SHADOW_EXT                          0x8DC5
#define GL_UNSIGNED_INT_VEC2_EXT                            0x8DC6
#define GL_UNSIGNED_INT_VEC3_EXT                            0x8DC7
#define GL_UNSIGNED_INT_VEC4_EXT                            0x8DC8
#define GL_INT_SAMPLER_1D_EXT                               0x8DC9
#define GL_INT_SAMPLER_2D_EXT                               0x8DCA
#define GL_INT_SAMPLER_3D_EXT                               0x8DCB
#define GL_INT_SAMPLER_CUBE_EXT                             0x8DCC
#define GL_INT_SAMPLER_2D_RECT_EXT                          0x8DCD
#define GL_INT_SAMPLER_1D_ARRAY_EXT                         0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY_EXT                         0x8DCF
#define GL_INT_SAMPLER_BUFFER_EXT                           0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_1D_EXT                      0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D_EXT                      0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D_EXT                      0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE_EXT                    0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT                 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT                0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT                0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT                  0x8DD8
#define GL_MIN_PROGRAM_TEXEL_OFFSET_EXT                     0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET_EXT                     0x8905

/* EXT_geometry_shader4 */
#define GL_GEOMETRY_SHADER_EXT                              0x8DD9
/*      GL_GEOMETRY_VERTICES_OUT_EXT */
/*      GL_GEOMETRY_INPUT_TYPE_EXT */
/*      GL_GEOMETRY_OUTPUT_TYPE_EXT */
/*      GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT */
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT              0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_EXT                0x8DDE
#define GL_MAX_VARYING_COMPONENTS_EXT                       0x8B4B
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT              0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT                 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT         0x8DE1
/*      GL_LINES_ADJACENCY_EXT */
/*      GL_LINE_STRIP_ADJACENCY_EXT */
/*      GL_TRIANGLES_ADJACENCY_EXT */
/*      GL_TRIANGLE_STRIP_ADJACENCY_EXT */
/*      GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT */
/*      GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT */
/*      GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT */
/*      GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT */
/*      GL_PROGRAM_POINT_SIZE_EXT */

/* ARB_geometry_shader4 */
#define GL_GEOMETRY_SHADER_ARB                              0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_ARB                        0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_ARB                          0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_ARB                         0x8DDC
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB             0x8C29
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB              0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB                0x8DDE
#define GL_MAX_VARYING_COMPONENTS_ARB                       0x8B4B
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB              0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB                 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB         0x8DE1
#define GL_LINES_ADJACENCY_ARB                              0xA
#define GL_LINE_STRIP_ADJACENCY_ARB                         0xB
#define GL_TRIANGLES_ADJACENCY_ARB                          0xC
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB                     0xD
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB         0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB           0x8DA9
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB               0x8DA7
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_ARB         0x8CD4
#define GL_PROGRAM_POINT_SIZE_ARB                           0x8642

/* EXT_bindable_uniform */
#define GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT                 0x8DE2
#define GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT               0x8DE3
#define GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT               0x8DE4
#define GL_MAX_BINDABLE_UNIFORM_SIZE_EXT                    0x8DED
#define GL_UNIFORM_BUFFER_EXT                               0x8DEE
#define GL_UNIFORM_BUFFER_BINDING_EXT                       0x8DEF

/* OpenGL21 */
#define GL_PIXEL_PACK_BUFFER                                0x88EB
#define GL_PIXEL_UNPACK_BUFFER                              0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING                        0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING                      0x88EF
#define GL_SRGB                                             0x8C40
#define GL_SRGB8                                            0x8C41
#define GL_SRGB_ALPHA                                       0x8C42
#define GL_SRGB8_ALPHA8                                     0x8C43
#define GL_SLUMINANCE_ALPHA                                 0x8C44
#define GL_SLUMINANCE8_ALPHA8                               0x8C45
#define GL_SLUMINANCE                                       0x8C46
#define GL_SLUMINANCE8                                      0x8C47
#define GL_COMPRESSED_SRGB                                  0x8C48
#define GL_COMPRESSED_SRGB_ALPHA                            0x8C49
#define GL_COMPRESSED_SLUMINANCE                            0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA                      0x8C4B
#define GL_FLOAT_MAT2x3                                     0x8B65
#define GL_FLOAT_MAT2x4                                     0x8B66
#define GL_FLOAT_MAT3x2                                     0x8B67
#define GL_FLOAT_MAT3x4                                     0x8B68
#define GL_FLOAT_MAT4x2                                     0x8B69
#define GL_FLOAT_MAT4x3                                     0x8B6A
#define GL_CURRENT_RASTER_SECONDARY_COLOR                   0x845F

/* EXT_framebuffer_sRGB */
#define GL_FRAMEBUFFER_SRGB_EXT                             0x8DB9
#define GL_FRAMEBUFFER_SRGB_CAPABLE_EXT                     0x8DBA

/* NV_conditional_render */
#define GL_QUERY_WAIT_NV                                    0x8E13
#define GL_QUERY_NO_WAIT_NV                                 0x8E14
#define GL_QUERY_BY_REGION_WAIT_NV                          0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT_NV                       0x8E16

/* NV_constant_frame_rate_hint */
#define GL_CONSTANT_FRAME_RATE_HINT_NV                      0x8E8B

/* NVX_volatile_texture */
#define GL_TEXTURE_IMMUTABLE_NVX                            0x8DEB
#define GL_TEXTURE_VOLATILE_NVX                             0x8DEC

/* NV_framebuffer_multisample_coverage */
#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV                 0x8CAB
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV                    0x8E10
#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV                0x8E11
#define GL_MULTISAMPLE_COVERAGE_MODES_NV                    0x8E12

/* NV_present_video */
#define GL_FRAME_NV                                         0x8E26
#define GL_FIELDS_NV                                        0x8E27
#define GL_CURRENT_TIME_NV                                  0x8E28
#define GL_NUM_FILL_STREAMS_NV                              0x8E29
#define GL_PRESENT_TIME_NV                                  0x8E2A
#define GL_PRESENT_DURATION_NV                              0x8E2B

/* NV_multisample_coverage */
#define GL_COVERAGE_SAMPLES_NV                              0x80A9
#define GL_COLOR_SAMPLES_NV                                 0x8E20

/* NV_explicit_multisample */
#define GL_SAMPLE_POSITION_NV                               0x8E50
#define GL_SAMPLE_MASK_NV                                   0x8E51
#define GL_SAMPLE_MASK_VALUE_NV                             0x8E52
#define GL_TEXTURE_BINDING_RENDERBUFFER_NV                  0x8E53
#define GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV       0x8E54
#define GL_TEXTURE_RENDERBUFFER_NV                          0x8E55
#define GL_SAMPLER_RENDERBUFFER_NV                          0x8E56
#define GL_INT_SAMPLER_RENDERBUFFER_NV                      0x8E57
#define GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV             0x8E58
#define GL_MAX_SAMPLE_MASK_WORDS_NV                         0x8E59

/* NV_gpu_program5 */
#define GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV              0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV             0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV             0x8E5C
#define GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV    0x8E5D
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV             0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV             0x8E5F
/*      GL_INT64_NV */
/*      GL_UNSIGNED_INT64_NV */

/* NV_tessellation_program5 */
#define GL_TESS_CONTROL_PROGRAM_NV                          0x891E
#define GL_TESS_EVALUATION_PROGRAM_NV                       0x891F
#define GL_TESS_CONTROL_PROGRAM_PARAMETER_BUFFER_NV         0x8C74
#define GL_TESS_EVALUATION_PROGRAM_PARAMETER_BUFFER_NV      0x8C75
#define GL_MAX_PROGRAM_PATCH_ATTRIBS_NV                     0x86D8

/* NV_anc_buffer_object */
#define GL_ANC_FIELD1_HORZ_BUFFER_NV                        0x8E30
#define GL_ANC_FIELD1_VERT_PRE_BUFFER_NV                    0x8E31
#define GL_ANC_FIELD1_VERT_POST_BUFFER_NV                   0x8E32
#define GL_ANC_FIELD2_HORZ_BUFFER_NV                        0x8E33
#define GL_ANC_FIELD2_VERT_PRE_BUFFER_NV                    0x8E34
#define GL_ANC_FIELD2_VERT_POST_BUFFER_NV                   0x8E35
#define GL_ANC_FIELD1_HORZ_BUFFER_BINDING_NV                0x8E36
#define GL_ANC_FIELD1_VERT_PRE_BUFFER_BINDING_NV            0x8E37
#define GL_ANC_FIELD1_VERT_POST_BUFFER_BINDING_NV           0x8E38
#define GL_ANC_FIELD2_HORZ_BUFFER_BINDING_NV                0x8E39
#define GL_ANC_FIELD2_VERT_PRE_BUFFER_BINDING_NV            0x8E3A
#define GL_ANC_FIELD2_VERT_POST_BUFFER_BINDING_NV           0x8E3B
#define GL_ANC_FIELD1_HORZ_BUFFER_DIM_NV                    0x8E3C
#define GL_ANC_FIELD1_VERT_PRE_BUFFER_DIM_NV                0x8E3D
#define GL_ANC_FIELD1_VERT_POST_BUFFER_DIM_NV               0x8E3E
#define GL_ANC_FIELD2_HORZ_BUFFER_DIM_NV                    0x8E3F
#define GL_ANC_FIELD2_VERT_PRE_BUFFER_DIM_NV                0x8E40
#define GL_ANC_FIELD2_VERT_POST_BUFFER_DIM_NV               0x8E41

/* APPLE_ycbcr_422 */
#define GL_YCBCR_422_APPLE                                  0x85B9
#define GL_UNSIGNED_SHORT_8_8_APPLE                         0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE                     0x85BB

/* OpenGL30 */
#define GL_MAP_READ_BIT                                     0x0001
#define GL_MAP_WRITE_BIT                                    0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT                         0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT                        0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT                           0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT                           0x0020
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT              0x0001
#define GL_INVALID_FRAMEBUFFER_OPERATION                    0x0506
#define GL_MAX_CLIP_DISTANCES                               GL_MAX_CLIP_PLANES
#define GL_HALF_FLOAT                                       0x140B
#define GL_CLIP_DISTANCE0                                   GL_CLIP_PLANE0
#define GL_CLIP_DISTANCE1                                   GL_CLIP_PLANE1
#define GL_CLIP_DISTANCE2                                   GL_CLIP_PLANE2
#define GL_CLIP_DISTANCE3                                   GL_CLIP_PLANE3
#define GL_CLIP_DISTANCE4                                   GL_CLIP_PLANE4
#define GL_CLIP_DISTANCE5                                   GL_CLIP_PLANE5
#define GL_CLIP_DISTANCE6                                   0x3006
#define GL_CLIP_DISTANCE7                                   0x3007
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING            0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE            0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE                  0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE                0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE                 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE                0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE                0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE              0x8217
#define GL_FRAMEBUFFER_DEFAULT                              0x8218
#define GL_FRAMEBUFFER_UNDEFINED                            0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT                         0x821A
#define GL_MAJOR_VERSION                                    0x821B
#define GL_MINOR_VERSION                                    0x821C
#define GL_NUM_EXTENSIONS                                   0x821D
#define GL_CONTEXT_FLAGS                                    0x821E
#define GL_INDEX                                            0x8222
#define GL_DEPTH_BUFFER                                     0x8223
#define GL_STENCIL_BUFFER                                   0x8224
#define GL_COMPRESSED_RED                                   0x8225
#define GL_COMPRESSED_RG                                    0x8226
#define GL_RG                                               0x8227
#define GL_RG_INTEGER                                       0x8228
#define GL_R8                                               0x8229
#define GL_R16                                              0x822A
#define GL_RG8                                              0x822B
#define GL_RG16                                             0x822C
#define GL_R16F                                             0x822D
#define GL_R32F                                             0x822E
#define GL_RG16F                                            0x822F
#define GL_RG32F                                            0x8230
#define GL_R8I                                              0x8231
#define GL_R8UI                                             0x8232
#define GL_R16I                                             0x8233
#define GL_R16UI                                            0x8234
#define GL_R32I                                             0x8235
#define GL_R32UI                                            0x8236
#define GL_RG8I                                             0x8237
#define GL_RG8UI                                            0x8238
#define GL_RG16I                                            0x8239
#define GL_RG16UI                                           0x823A
#define GL_RG32I                                            0x823B
#define GL_RG32UI                                           0x823C
#define GL_MAX_RENDERBUFFER_SIZE                            0x84E8
#define GL_DEPTH_STENCIL                                    0x84F9
#define GL_UNSIGNED_INT_24_8                                0x84FA
#define GL_VERTEX_ARRAY_BINDING                             0x85B5
#define GL_RGBA32F                                          0x8814
#define GL_RGB32F                                           0x8815
#define GL_RGBA16F                                          0x881A
#define GL_RGB16F                                           0x881B
#define GL_COMPARE_REF_TO_TEXTURE                           GL_COMPARE_R_TO_TEXTURE
#define GL_DEPTH24_STENCIL8                                 0x88F0
#define GL_TEXTURE_STENCIL_SIZE                             0x88F1
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER                      0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS                         0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET                         0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET                         0x8905
#define GL_CLAMP_VERTEX_COLOR                               0x891A
#define GL_CLAMP_FRAGMENT_COLOR                             0x891B
#define GL_CLAMP_READ_COLOR                                 0x891C
#define GL_FIXED_ONLY                                       0x891D
#define GL_MAX_VARYING_COMPONENTS                           GL_MAX_VARYING_FLOATS
#define GL_TEXTURE_RED_TYPE                                 0x8C10
#define GL_TEXTURE_GREEN_TYPE                               0x8C11
#define GL_TEXTURE_BLUE_TYPE                                0x8C12
#define GL_TEXTURE_ALPHA_TYPE                               0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE                           0x8C14
#define GL_TEXTURE_INTENSITY_TYPE                           0x8C15
#define GL_TEXTURE_DEPTH_TYPE                               0x8C16
#define GL_UNSIGNED_NORMALIZED                              0x8C17
#define GL_TEXTURE_1D_ARRAY                                 0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY                           0x8C19
#define GL_TEXTURE_2D_ARRAY                                 0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY                           0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY                         0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY                         0x8C1D
#define GL_R11F_G11F_B10F                                   0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV                     0x8C3B
#define GL_RGB9_E5                                          0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV                         0x8C3E
#define GL_TEXTURE_SHARED_SIZE                              0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH            0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE                   0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS       0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS                      0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START                  0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE                   0x8C85
#define GL_PRIMITIVES_GENERATED                             0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN            0x8C88
#define GL_RASTERIZER_DISCARD                               0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS    0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS          0x8C8B
#define GL_INTERLEAVED_ATTRIBS                              0x8C8C
#define GL_SEPARATE_ATTRIBS                                 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER                        0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING                0x8C8F
#define GL_FRAMEBUFFER_BINDING                              0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING                         GL_FRAMEBUFFER_BINDING
#define GL_RENDERBUFFER_BINDING                             0x8CA7
#define GL_READ_FRAMEBUFFER                                 0x8CA8
#define GL_DRAW_FRAMEBUFFER                                 0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING                         0x8CAA
#define GL_RENDERBUFFER_SAMPLES                             0x8CAB
#define GL_DEPTH_COMPONENT32F                               0x8CAC
#define GL_DEPTH32F_STENCIL8                                0x8CAD
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE               0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME               0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL             0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE     0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER             0x8CD4
#define GL_FRAMEBUFFER_COMPLETE                             0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT                0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT        0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER               0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER               0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED                          0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS                            0x8CDF
#define GL_COLOR_ATTACHMENT0                                0x8CE0
#define GL_COLOR_ATTACHMENT1                                0x8CE1
#define GL_COLOR_ATTACHMENT2                                0x8CE2
#define GL_COLOR_ATTACHMENT3                                0x8CE3
#define GL_COLOR_ATTACHMENT4                                0x8CE4
#define GL_COLOR_ATTACHMENT5                                0x8CE5
#define GL_COLOR_ATTACHMENT6                                0x8CE6
#define GL_COLOR_ATTACHMENT7                                0x8CE7
#define GL_COLOR_ATTACHMENT8                                0x8CE8
#define GL_COLOR_ATTACHMENT9                                0x8CE9
#define GL_COLOR_ATTACHMENT10                               0x8CEA
#define GL_COLOR_ATTACHMENT11                               0x8CEB
#define GL_COLOR_ATTACHMENT12                               0x8CEC
#define GL_COLOR_ATTACHMENT13                               0x8CED
#define GL_COLOR_ATTACHMENT14                               0x8CEE
#define GL_COLOR_ATTACHMENT15                               0x8CEF
#define GL_DEPTH_ATTACHMENT                                 0x8D00
#define GL_STENCIL_ATTACHMENT                               0x8D20
#define GL_FRAMEBUFFER                                      0x8D40
#define GL_RENDERBUFFER                                     0x8D41
#define GL_RENDERBUFFER_WIDTH                               0x8D42
#define GL_RENDERBUFFER_HEIGHT                              0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT                     0x8D44
#define GL_STENCIL_INDEX1                                   0x8D46
#define GL_STENCIL_INDEX4                                   0x8D47
#define GL_STENCIL_INDEX8                                   0x8D48
#define GL_STENCIL_INDEX16                                  0x8D49
#define GL_RENDERBUFFER_RED_SIZE                            0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE                          0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE                           0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE                          0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE                          0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE                        0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE               0x8D56
#define GL_MAX_SAMPLES                                      0x8D57
#define GL_RGBA32UI                                         0x8D70
#define GL_RGB32UI                                          0x8D71
#define GL_RGBA16UI                                         0x8D76
#define GL_RGB16UI                                          0x8D77
#define GL_RGBA8UI                                          0x8D7C
#define GL_RGB8UI                                           0x8D7D
#define GL_RGBA32I                                          0x8D82
#define GL_RGB32I                                           0x8D83
#define GL_RGBA16I                                          0x8D88
#define GL_RGB16I                                           0x8D89
#define GL_RGBA8I                                           0x8D8E
#define GL_RGB8I                                            0x8D8F
#define GL_RED_INTEGER                                      0x8D94
#define GL_GREEN_INTEGER                                    0x8D95
#define GL_BLUE_INTEGER                                     0x8D96
#define GL_ALPHA_INTEGER                                    0x8D97
#define GL_RGB_INTEGER                                      0x8D98
#define GL_RGBA_INTEGER                                     0x8D99
#define GL_BGR_INTEGER                                      0x8D9A
#define GL_BGRA_INTEGER                                     0x8D9B
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV                   0x8DAD
#define GL_FRAMEBUFFER_SRGB                                 0x8DB9
#define GL_COMPRESSED_RED_RGTC1                             0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1                      0x8DBC
#define GL_COMPRESSED_RG_RGTC2                              0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2                       0x8DBE
#define GL_SAMPLER_1D_ARRAY                                 0x8DC0
#define GL_SAMPLER_2D_ARRAY                                 0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW                          0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW                          0x8DC4
#define GL_SAMPLER_CUBE_SHADOW                              0x8DC5
#define GL_UNSIGNED_INT_VEC2                                0x8DC6
#define GL_UNSIGNED_INT_VEC3                                0x8DC7
#define GL_UNSIGNED_INT_VEC4                                0x8DC8
#define GL_INT_SAMPLER_1D                                   0x8DC9
#define GL_INT_SAMPLER_2D                                   0x8DCA
#define GL_INT_SAMPLER_3D                                   0x8DCB
#define GL_INT_SAMPLER_CUBE                                 0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY                             0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY                             0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D                          0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D                          0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D                          0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE                        0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY                    0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY                    0x8DD7
#define GL_QUERY_WAIT                                       0x8E13
#define GL_QUERY_NO_WAIT                                    0x8E14
#define GL_QUERY_BY_REGION_WAIT                             0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT                          0x8E16

/* EXT_texture_swizzle */
#define GL_TEXTURE_SWIZZLE_R_EXT                            0x8E42
#define GL_TEXTURE_SWIZZLE_G_EXT                            0x8E43
#define GL_TEXTURE_SWIZZLE_B_EXT                            0x8E44
#define GL_TEXTURE_SWIZZLE_A_EXT                            0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA_EXT                         0x8E46

/* EXT_provoking_vertex */
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT     0x8E4C
#define GL_FIRST_VERTEX_CONVENTION_EXT                      0x8E4D
#define GL_LAST_VERTEX_CONVENTION_EXT                       0x8E4E
#define GL_PROVOKING_VERTEX_EXT                             0x8E4F

/* NV_vertex_buffer_unified_memory */
#define GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV                   0x8F1E
#define GL_ELEMENT_ARRAY_UNIFIED_NV                         0x8F1F
#define GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV                   0x8F20
#define GL_VERTEX_ARRAY_ADDRESS_NV                          0x8F21
#define GL_NORMAL_ARRAY_ADDRESS_NV                          0x8F22
#define GL_COLOR_ARRAY_ADDRESS_NV                           0x8F23
#define GL_INDEX_ARRAY_ADDRESS_NV                           0x8F24
#define GL_TEXTURE_COORD_ARRAY_ADDRESS_NV                   0x8F25
#define GL_EDGE_FLAG_ARRAY_ADDRESS_NV                       0x8F26
#define GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV                 0x8F27
#define GL_FOG_COORD_ARRAY_ADDRESS_NV                       0x8F28
#define GL_ELEMENT_ARRAY_ADDRESS_NV                         0x8F29
#define GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV                    0x8F2A
#define GL_VERTEX_ARRAY_LENGTH_NV                           0x8F2B
#define GL_NORMAL_ARRAY_LENGTH_NV                           0x8F2C
#define GL_COLOR_ARRAY_LENGTH_NV                            0x8F2D
#define GL_INDEX_ARRAY_LENGTH_NV                            0x8F2E
#define GL_TEXTURE_COORD_ARRAY_LENGTH_NV                    0x8F2F
#define GL_EDGE_FLAG_ARRAY_LENGTH_NV                        0x8F30
#define GL_SECONDARY_COLOR_ARRAY_LENGTH_NV                  0x8F31
#define GL_FOG_COORD_ARRAY_LENGTH_NV                        0x8F32
#define GL_ELEMENT_ARRAY_LENGTH_NV                          0x8F33

/* NV_shader_buffer_load */
#define GL_BUFFER_GPU_ADDRESS_NV                            0x8F1D
#define GL_GPU_ADDRESS_NV                                   0x8F34
#define GL_MAX_SHADER_BUFFER_ADDRESS_NV                     0x8F35

/* APPLE_rgb_422 */
#define GL_RGB_422_APPLE                                    0x8A1F

/* ARB_copy_buffer */
#define GL_TEXTURE_BUFFER                                   0x8C2A
#define GL_COPY_READ_BUFFER                                 0x8F36
#define GL_COPY_WRITE_BUFFER                                0x8F37

/* NV_video_capture */
#define GL_VIDEO_BUFFER_NV                                  0x9020
#define GL_VIDEO_BUFFER_BINDING_NV                          0x9021
#define GL_FIELD_UPPER_NV                                   0x9022
#define GL_FIELD_LOWER_NV                                   0x9023
#define GL_NUM_VIDEO_CAPTURE_STREAMS_NV                     0x9024
#define GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV              0x9025
#define GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV                0x9026
#define GL_LAST_VIDEO_CAPTURE_STATUS_NV                     0x9027
#define GL_VIDEO_BUFFER_PITCH_NV                            0x9028
#define GL_VIDEO_COLOR_CONVERSION_MATRIX_NV                 0x9029
#define GL_VIDEO_COLOR_CONVERSION_MAX_NV                    0x902A
#define GL_VIDEO_COLOR_CONVERSION_MIN_NV                    0x902B
#define GL_VIDEO_COLOR_CONVERSION_OFFSET_NV                 0x902C
#define GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV                  0x902D
#define GL_PARTIAL_SUCCESS_NV                               0x902E
#define GL_SUCCESS_NV                                       0x902F
#define GL_FAILURE_NV                                       0x9030
#define GL_YCBYCR8_422_NV                                   0x9031
#define GL_YCBAYCRA8_4224_NV                                0x9032
#define GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV                    0x9033
#define GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV         0x9034
#define GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV                    0x9035
#define GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV         0x9036
#define GL_Z4Y12Z4CB12Z4CR12_444_NV                         0x9037
#define GL_VIDEO_CAPTURE_FRAME_WIDTH_NV                     0x9038
#define GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV                    0x9039
#define GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV              0x903A
#define GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV              0x903B
#define GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV                  0x903C

/* NVX_anc_capture */
#define GL_ANC_CAPTURE_BUFFER_NVX                           0x903D
#define GL_ANC_CAPTURE_BUFFER_BINDING_NVX                   0x903E
#define GL_ANC_CAPTURE_BUFFER_PITCH_NVX                     0x903F
#define GL_ANC_CAPTURE_BUFFER_HEIGHT_NVX                    0x9040
#define GL_ANC_CAPTURE_BUFFER_DIM_NVX                       0x9041
#define GL_ANC_HORIZONTAL_NVX                               0x9042
#define GL_ANC_VERTICAL_PRE_NVX                             0x9043
#define GL_ANC_VERTICAL_POST_NVX                            0x9044

/* NVX_gpu_memory_info */
#define GL_GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX             0x9047
#define GL_GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX       0x9048
#define GL_GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX     0x9049
#define GL_GPU_MEMORY_INFO_EVICTION_COUNT_NVX               0x904A
#define GL_GPU_MEMORY_INFO_EVICTED_MEMORY_NVX               0x904B

/* VERSION_3_1 */
#define GL_UNIFORM_BUFFER                                   0x8A11
#define GL_UNIFORM_BUFFER_BINDING                           0x8A28
#define GL_UNIFORM_BUFFER_START                             0x8A29
#define GL_UNIFORM_BUFFER_SIZE                              0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS                        0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS                      0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS                      0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS                      0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS                      0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE                           0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS           0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS         0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS         0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT                  0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH             0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS                            0x8A36
#define GL_UNIFORM_TYPE                                     0x8A37
#define GL_UNIFORM_SIZE                                     0x8A38
#define GL_UNIFORM_NAME_LENGTH                              0x8A39
#define GL_UNIFORM_BLOCK_INDEX                              0x8A3A
#define GL_UNIFORM_OFFSET                                   0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE                             0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE                            0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR                             0x8A3E
#define GL_UNIFORM_BLOCK_BINDING                            0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE                          0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH                        0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS                    0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES             0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER        0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER      0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER      0x8A46
#define GL_RED_SNORM                                        0x8F90
#define GL_RG_SNORM                                         0x8F91
#define GL_RGB_SNORM                                        0x8F92
#define GL_RGBA_SNORM                                       0x8F93
#define GL_R8_SNORM                                         0x8F94
#define GL_RG8_SNORM                                        0x8F95
#define GL_RGB8_SNORM                                       0x8F96
#define GL_RGBA8_SNORM                                      0x8F97
#define GL_R16_SNORM                                        0x8F98
#define GL_RG16_SNORM                                       0x8F99
#define GL_RGB16_SNORM                                      0x8F9A
#define GL_RGBA16_SNORM                                     0x8F9B
#define GL_SIGNED_NORMALIZED                                0x8F9C
#define GL_PRIMITIVE_RESTART                                0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX                          0x8F9E
#define GL_INVALID_INDEX                                    0xFFFFFFFF

/* NV_shader_buffer_store */
#define GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV              0x00000010

/* EXT_shader_image_load_store */
#define GL_MAX_IMAGE_UNITS_EXT                              0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT 0x8F39
#define GL_IMAGE_BINDING_NAME_EXT                           0x8F3A
#define GL_IMAGE_BINDING_LEVEL_EXT                          0x8F3B
#define GL_IMAGE_BINDING_LAYERED_EXT                        0x8F3C
#define GL_IMAGE_BINDING_LAYER_EXT                          0x8F3D
#define GL_IMAGE_BINDING_ACCESS_EXT                         0x8F3E
#define GL_IMAGE_BINDING_FORMAT_EXT                         0x906E
#define GL_MAX_IMAGE_SAMPLES_EXT                            0x906D
#define GL_IMAGE_1D_EXT                                     0x904C
#define GL_IMAGE_2D_EXT                                     0x904D
#define GL_IMAGE_3D_EXT                                     0x904E
#define GL_IMAGE_2D_RECT_EXT                                0x904F
#define GL_IMAGE_CUBE_EXT                                   0x9050
#define GL_IMAGE_BUFFER_EXT                                 0x9051
#define GL_IMAGE_1D_ARRAY_EXT                               0x9052
#define GL_IMAGE_2D_ARRAY_EXT                               0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY_EXT                         0x9054
#define GL_IMAGE_2D_MULTISAMPLE_EXT                         0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT                   0x9056
#define GL_INT_IMAGE_1D_EXT                                 0x9057
#define GL_INT_IMAGE_2D_EXT                                 0x9058
#define GL_INT_IMAGE_3D_EXT                                 0x9059
#define GL_INT_IMAGE_2D_RECT_EXT                            0x905A
#define GL_INT_IMAGE_CUBE_EXT                               0x905B
#define GL_INT_IMAGE_BUFFER_EXT                             0x905C
#define GL_INT_IMAGE_1D_ARRAY_EXT                           0x905D
#define GL_INT_IMAGE_2D_ARRAY_EXT                           0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT                     0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE_EXT                     0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT               0x9061
#define GL_UNSIGNED_INT_IMAGE_1D_EXT                        0x9062
#define GL_UNSIGNED_INT_IMAGE_2D_EXT                        0x9063
#define GL_UNSIGNED_INT_IMAGE_3D_EXT                        0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT                   0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE_EXT                      0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER_EXT                    0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT                  0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT                  0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT            0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT            0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT      0x906C
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT              0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT_EXT                    0x00000002
#define GL_UNIFORM_BARRIER_BIT_EXT                          0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT_EXT                    0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT              0x00000020
#define GL_COMMAND_BARRIER_BIT_EXT                          0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT_EXT                     0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT_EXT                   0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT_EXT                    0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT_EXT                      0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT               0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT_EXT                   0x00001000
#define GL_ALL_BARRIER_BITS_EXT                             0xFFFFFFFF

/* VERSION_3_2 */
#define GL_DEPTH_CLAMP                                      0x864F
#define GL_TEXTURE_CUBE_MAP_SEAMLESS                        0x884F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION         0x8E4C
#define GL_FIRST_VERTEX_CONVENTION                          0x8E4D
#define GL_LAST_VERTEX_CONVENTION                           0x8E4E
#define GL_PROVOKING_VERTEX                                 0x8E4F
#define GL_MAX_SERVER_WAIT_TIMEOUT                          0x9111
#define GL_OBJECT_TYPE                                      0x9112
#define GL_SYNC_CONDITION                                   0x9113
#define GL_SYNC_STATUS                                      0x9114
#define GL_SYNC_FLAGS                                       0x9115
#define GL_SYNC_FENCE                                       0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE                       0x9117
#define GL_UNSIGNALED                                       0x9118
#define GL_SIGNALED                                         0x9119
#define GL_SYNC_FLUSH_COMMANDS_BIT                          0x00000001
#define GL_TIMEOUT_IGNORED                                  0xFFFFFFFFFFFFFFFFull
#define GL_ALREADY_SIGNALED                                 0x911A
#define GL_TIMEOUT_EXPIRED                                  0x911B
#define GL_CONDITION_SATISFIED                              0x911C
#define GL_WAIT_FAILED                                      0x911D
#define GL_SAMPLE_POSITION                                  0x8E50
#define GL_SAMPLE_MASK                                      0x8E51
#define GL_SAMPLE_MASK_VALUE                                0x8E52
#define GL_TEXTURE_2D_MULTISAMPLE                           0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE                     0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY                     0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY               0x9103
#define GL_MAX_SAMPLE_MASK_WORDS                            0x8E59
#define GL_MAX_COLOR_TEXTURE_SAMPLES                        0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES                        0x910F
#define GL_MAX_INTEGER_SAMPLES                              0x9110
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE                   0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY             0x9105
#define GL_TEXTURE_SAMPLES                                  0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS                   0x9107
#define GL_SAMPLER_2D_MULTISAMPLE                           0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE                       0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE              0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY                     0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY                 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY        0x910D

/* ARB_texture_cube_map_array */
#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB                       0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB               0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB                 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB                       0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB                0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB                   0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB          0x900F

/* ARB_texture_gather */
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB            0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB            0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB        0x8F9F

/* ARB_sample_shading */
#define GL_SAMPLE_SHADING_ARB                               0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB                     0x8C37

/* NV_gpu_shader5 */
#define GL_INT64_NV                                         0x140E
#define GL_UNSIGNED_INT64_NV                                0x140F
#define GL_INT8_NV                                          0x8FE0
#define GL_INT8_VEC2_NV                                     0x8FE1
#define GL_INT8_VEC3_NV                                     0x8FE2
#define GL_INT8_VEC4_NV                                     0x8FE3
#define GL_INT16_NV                                         0x8FE4
#define GL_INT16_VEC2_NV                                    0x8FE5
#define GL_INT16_VEC3_NV                                    0x8FE6
#define GL_INT16_VEC4_NV                                    0x8FE7
#define GL_INT64_VEC2_NV                                    0x8FE9
#define GL_INT64_VEC3_NV                                    0x8FEA
#define GL_INT64_VEC4_NV                                    0x8FEB
#define GL_UNSIGNED_INT8_NV                                 0x8FEC
#define GL_UNSIGNED_INT8_VEC2_NV                            0x8FED
#define GL_UNSIGNED_INT8_VEC3_NV                            0x8FEE
#define GL_UNSIGNED_INT8_VEC4_NV                            0x8FEF
#define GL_UNSIGNED_INT16_NV                                0x8FF0
#define GL_UNSIGNED_INT16_VEC2_NV                           0x8FF1
#define GL_UNSIGNED_INT16_VEC3_NV                           0x8FF2
#define GL_UNSIGNED_INT16_VEC4_NV                           0x8FF3
#define GL_UNSIGNED_INT64_VEC2_NV                           0x8FF5
#define GL_UNSIGNED_INT64_VEC3_NV                           0x8FF6
#define GL_UNSIGNED_INT64_VEC4_NV                           0x8FF7
#define GL_FLOAT16_NV                                       0x8FF8
#define GL_FLOAT16_VEC2_NV                                  0x8FF9
#define GL_FLOAT16_VEC3_NV                                  0x8FFA
#define GL_FLOAT16_VEC4_NV                                  0x8FFB

/* NV_texture_multisample */
#define GL_TEXTURE_COVERAGE_SAMPLES_NV                      0x9045
#define GL_TEXTURE_COLOR_SAMPLES_NV                         0x9046

/* ARB_texture_compression_bptc */
#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB                   0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB             0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB             0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB           0x8E8F

/* VERSION_3_3 */
#define GL_RGB10_A2UI                                       0x906F
#define GL_TEXTURE_SWIZZLE_R                                0x8E42
#define GL_TEXTURE_SWIZZLE_G                                0x8E43
#define GL_TEXTURE_SWIZZLE_B                                0x8E44
#define GL_TEXTURE_SWIZZLE_A                                0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA                             0x8E46
#define GL_SRC1_COLOR                                       0x88F9
#define GL_ONE_MINUS_SRC1_COLOR                             0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA                             0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS                     0x88FC
#define GL_SAMPLER_BINDING                                  0x8919
#define GL_ANY_SAMPLES_PASSED                               0x8C2F
#define GL_TIME_ELAPSED                                     0x88BF
#define GL_TIMESTAMP                                        0x8E28
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR                      0x88FE
#define GL_INT_2_10_10_10_REV                               0x8D9F

/* VERSION_4_0 */
#define GL_DRAW_INDIRECT_BUFFER                             0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING                     0x8F43
#define GL_DRAW_INDIRECT_UNIFIED_NV                         0x8F40
#define GL_DRAW_INDIRECT_ADDRESS_NV                         0x8F41
#define GL_DRAW_INDIRECT_LENGTH_NV                          0x8F42
#define GL_GEOMETRY_SHADER_INVOCATIONS                      0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS                  0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET                0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET                0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS               0x8E5D
/*      GL_MAX_VERTEX_STREAMS */
#define GL_DOUBLE_VEC2                                      0x8FFC
#define GL_DOUBLE_VEC3                                      0x8FFD
#define GL_DOUBLE_VEC4                                      0x8FFE
#define GL_DOUBLE_MAT2                                      0x8F46
#define GL_DOUBLE_MAT3                                      0x8F47
#define GL_DOUBLE_MAT4                                      0x8F48
#define GL_DOUBLE_MAT2x3                                    0x8F49
#define GL_DOUBLE_MAT2x4                                    0x8F4A
#define GL_DOUBLE_MAT3x2                                    0x8F4B
#define GL_DOUBLE_MAT3x4                                    0x8F4C
#define GL_DOUBLE_MAT4x2                                    0x8F4D
#define GL_DOUBLE_MAT4x3                                    0x8F4E
#define GL_SAMPLE_SHADING                                   0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE                         0x8C37
#define GL_PATCHES                                          0xE
#define GL_PATCH_VERTICES                                   0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL                        0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL                        0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES                     0x8E75
#define GL_TESS_GEN_MODE                                    0x8E76
#define GL_TESS_GEN_SPACING                                 0x8E77
#define GL_TESS_GEN_VERTEX_ORDER                            0x8E78
#define GL_TESS_GEN_POINT_MODE                              0x8E79
#define GL_ISOLINES                                         0x8E7A
#define GL_FRACTIONAL_ODD                                   0x8E7B
#define GL_FRACTIONAL_EVEN                                  0x8E7C
#define GL_MAX_PATCH_VERTICES                               0x8E7D
#define GL_MAX_TESS_GEN_LEVEL                               0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS              0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS           0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS             0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS          0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS               0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS                        0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS         0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS            0x8E86
#define GL_TESS_EVALUATION_SHADER                           0x8E87
#define GL_TESS_CONTROL_SHADER                              0x8E88
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS                  0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS               0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS                0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS             0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS     0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS  0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER  0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_TEXTURE_CUBE_MAP_ARRAY                           0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY                   0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY                     0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY                           0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW                    0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY                       0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY              0x900F
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET                0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET                0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS            0x8F9F
#define GL_TRANSFORM_FEEDBACK                               0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED                 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE                 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING                       0x8E25
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS                   0x8E70
#define GL_MAX_VERTEX_STREAMS                               0x8E71
#define GL_NEXT_BUFFER_NV                                   -2
#define GL_SKIP_COMPONENTS4_NV                              -3
#define GL_SKIP_COMPONENTS3_NV                              -4
#define GL_SKIP_COMPONENTS2_NV                              -5
#define GL_SKIP_COMPONENTS1_NV                              -6
#define GL_ACTIVE_SUBROUTINES                               0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS                       0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS              0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH                     0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH             0x8E49
#define GL_MAX_SUBROUTINES                                  0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS                 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES                       0x8E4A
#define GL_COMPATIBLE_SUBROUTINES                           0x8E4B
#define GL_MAX_PROGRAM_SUBROUTINE_PARAMETERS_NV             0x8F44
#define GL_MAX_PROGRAM_SUBROUTINE_NUM_NV                    0x8F45

/* VERSION_4_1 */
#define GL_SHADER_COMPILER                                  0x8DFA
#define GL_SHADER_BINARY_FORMATS                            0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS                        0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS                       0x8DFB
#define GL_MAX_VARYING_VECTORS                              0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS                     0x8DFD
#define GL_IMPLEMENTATION_COLOR_READ_TYPE                   0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT                 0x8B9B
#define GL_FIXED                                            0x140C
#define GL_RGB565                                           0x8D62
#define GL_LOW_FLOAT                                        0x8DF0
#define GL_MEDIUM_FLOAT                                     0x8DF1
#define GL_HIGH_FLOAT                                       0x8DF2
#define GL_LOW_INT                                          0x8DF3
#define GL_MEDIUM_INT                                       0x8DF4
#define GL_HIGH_INT                                         0x8DF5
#define GL_VERTEX_SHADER_BIT                                0x00000001
#define GL_FRAGMENT_SHADER_BIT                              0x00000002
#define GL_GEOMETRY_SHADER_BIT                              0x00000004
#define GL_TESS_CONTROL_SHADER_BIT                          0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT                       0x00000010
#define GL_ALL_SHADER_BITS                                  0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE                                0x8258
#define GL_ACTIVE_PROGRAM                                   0x8259
#define GL_PROGRAM_PIPELINE_BINDING                         0x825A
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT                  0x8257
#define GL_PROGRAM_BINARY_LENGTH                            0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS                       0x87FE
#define GL_PROGRAM_BINARY_FORMATS                           0x87FF
#define GL_MAX_VIEWPORTS                                    0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS                           0x825C
#define GL_VIEWPORT_BOUNDS_RANGE                            0x825D
#define GL_LAYER_PROVOKING_VERTEX                           0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX                  0x825F
#define GL_UNDEFINED_VERTEX                                 0x8260

/* VERSION_4_2 */
#define GL_COMPRESSED_RGBA_BPTC_UNORM                       0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM                 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT                 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT               0x8E8F
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH                    0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT                   0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH                    0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE                     0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH                      0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT                     0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH                      0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE                       0x912E
#define GL_TEXTURE_IMMUTABLE_FORMAT                         0x912F
#define GL_MIN_MAP_BUFFER_ALIGNMENT                         0x90BC
#define GL_ATOMIC_COUNTER_BUFFER                            0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING                    0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START                      0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE                       0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE                  0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS     0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS                0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS          0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS       0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS              0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS              0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS              0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS                       0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS                 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS              0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS                     0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS                     0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS                     0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE                   0x92D8
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS                    0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX              0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER                      0x92DB
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS               0x92DC
#define GL_MAX_IMAGE_UNITS                                  0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS    0x8F39
#define GL_MAX_IMAGE_SAMPLES                                0x906D
#define GL_MAX_VERTEX_IMAGE_UNIFORMS                        0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS                  0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS               0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS                      0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS                      0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS                      0x90CF
#define GL_IMAGE_BINDING_NAME                               0x8F3A
#define GL_IMAGE_BINDING_LEVEL                              0x8F3B
#define GL_IMAGE_BINDING_LAYERED                            0x8F3C
#define GL_IMAGE_BINDING_LAYER                              0x8F3D
#define GL_IMAGE_BINDING_ACCESS                             0x8F3E
#define GL_IMAGE_BINDING_FORMAT                             0x906E
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT                  0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT                        0x00000002
#define GL_UNIFORM_BARRIER_BIT                              0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT                        0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT                  0x00000020
#define GL_COMMAND_BARRIER_BIT                              0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT                         0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT                       0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT                        0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT                          0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT                   0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT                       0x00001000
#define GL_ALL_BARRIER_BITS                                 0xFFFFFFFF
#define GL_IMAGE_1D                                         0x904C
#define GL_IMAGE_2D                                         0x904D
#define GL_IMAGE_3D                                         0x904E
#define GL_IMAGE_2D_RECT                                    0x904F
#define GL_IMAGE_CUBE                                       0x9050
#define GL_IMAGE_BUFFER                                     0x9051
#define GL_IMAGE_1D_ARRAY                                   0x9052
#define GL_IMAGE_2D_ARRAY                                   0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY                             0x9054
#define GL_IMAGE_2D_MULTISAMPLE                             0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY                       0x9056
#define GL_INT_IMAGE_1D                                     0x9057
#define GL_INT_IMAGE_2D                                     0x9058
#define GL_INT_IMAGE_3D                                     0x9059
#define GL_INT_IMAGE_2D_RECT                                0x905A
#define GL_INT_IMAGE_CUBE                                   0x905B
#define GL_INT_IMAGE_BUFFER                                 0x905C
#define GL_INT_IMAGE_1D_ARRAY                               0x905D
#define GL_INT_IMAGE_2D_ARRAY                               0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY                         0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE                         0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY                   0x9061
#define GL_UNSIGNED_INT_IMAGE_1D                            0x9062
#define GL_UNSIGNED_INT_IMAGE_2D                            0x9063
#define GL_UNSIGNED_INT_IMAGE_3D                            0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT                       0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE                          0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER                        0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY                      0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY                      0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY                0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE                0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY          0x906C
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE                  0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE               0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS              0x90C9
#define GL_NUM_SAMPLE_COUNTS                                0x9380

/* VERSION_4_3 */
#define GL_VERTEX_ATTRIB_ARRAY_LONG                         0x874E
#define GL_NUM_SHADING_LANGUAGE_VERSIONS                    0x82E9
#define GL_COMPUTE_SHADER                                   0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS                       0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS                  0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS                       0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE                   0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS                   0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS               0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS                      0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS          0x8266
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS               0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT                     0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE                      0x91BF
#define GL_COMPUTE_WORK_GROUP_SIZE                          0x8267
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER       0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER                         0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING                 0x90EF
#define GL_COMPUTE_SHADER_BIT                               0x00000020
#define GL_DISPATCH_INDIRECT_UNIFIED_NV                     0x90FD
#define GL_DISPATCH_INDIRECT_ADDRESS_NV                     0x90FE
#define GL_DISPATCH_INDIRECT_LENGTH_NV                      0x90FF
#define GL_COMPRESSED_RGB8_ETC2                             0x9274
#define GL_COMPRESSED_SRGB8_ETC2                            0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2         0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2        0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC                        0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC                 0x9279
#define GL_COMPRESSED_R11_EAC                               0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC                        0x9271
#define GL_COMPRESSED_RG11_EAC                              0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC                       0x9273
#define GL_PRIMITIVE_RESTART_FIXED_INDEX                    0x8D69
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE                  0x8D6A
#define GL_MAX_ELEMENT_INDEX                                0x8D6B
#define GL_MAX_UNIFORM_LOCATIONS                            0x826E
#define GL_FRAMEBUFFER_DEFAULT_WIDTH                        0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT                       0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS                       0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES                      0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS       0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH                            0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT                           0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS                           0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES                          0x9318
#define GL_UNIFORM                                          0x92E1
#define GL_UNIFORM_BLOCK                                    0x92E2
#define GL_PROGRAM_INPUT                                    0x92E3
#define GL_PROGRAM_OUTPUT                                   0x92E4
#define GL_BUFFER_VARIABLE                                  0x92E5
#define GL_SHADER_STORAGE_BLOCK                             0x92E6
#define GL_VERTEX_SUBROUTINE                                0x92E8
#define GL_TESS_CONTROL_SUBROUTINE                          0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE                       0x92EA
#define GL_GEOMETRY_SUBROUTINE                              0x92EB
#define GL_FRAGMENT_SUBROUTINE                              0x92EC
#define GL_COMPUTE_SUBROUTINE                               0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM                        0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM                  0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM               0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM                      0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM                      0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM                       0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING                       0x92F4
#define GL_ACTIVE_RESOURCES                                 0x92F5
#define GL_MAX_NAME_LENGTH                                  0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES                         0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES                   0x92F8
#define GL_NAME_LENGTH                                      0x92F9
#define GL_TYPE                                             0x92FA
#define GL_ARRAY_SIZE                                       0x92FB
#define GL_OFFSET                                           0x92FC
#define GL_BLOCK_INDEX                                      0x92FD
#define GL_ARRAY_STRIDE                                     0x92FE
#define GL_MATRIX_STRIDE                                    0x92FF
#define GL_IS_ROW_MAJOR                                     0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX                      0x9301
#define GL_BUFFER_BINDING                                   0x9302
#define GL_BUFFER_DATA_SIZE                                 0x9303
#define GL_NUM_ACTIVE_VARIABLES                             0x9304
#define GL_ACTIVE_VARIABLES                                 0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER                      0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER                0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER             0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER                    0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER                    0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER                     0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE                             0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE                           0x930D
#define GL_LOCATION                                         0x930E
#define GL_LOCATION_INDEX                                   0x930F
#define GL_IS_PER_PATCH                                     0x92E7
#define GL_INTERNALFORMAT_SUPPORTED                         0x826F
#define GL_INTERNALFORMAT_PREFERRED                         0x8270
#define GL_INTERNALFORMAT_RED_SIZE                          0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE                        0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE                         0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE                        0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE                        0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE                      0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE                       0x8277
#define GL_INTERNALFORMAT_RED_TYPE                          0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE                        0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE                         0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE                        0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE                        0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE                      0x827D
#define GL_MAX_WIDTH                                        0x827E
#define GL_MAX_HEIGHT                                       0x827F
#define GL_MAX_DEPTH                                        0x8280
#define GL_MAX_LAYERS                                       0x8281
#define GL_MAX_COMBINED_DIMENSIONS                          0x8282
#define GL_COLOR_COMPONENTS                                 0x8283
#define GL_DEPTH_COMPONENTS                                 0x8284
#define GL_STENCIL_COMPONENTS                               0x8285
#define GL_COLOR_RENDERABLE                                 0x8286
#define GL_DEPTH_RENDERABLE                                 0x8287
#define GL_STENCIL_RENDERABLE                               0x8288
#define GL_FRAMEBUFFER_RENDERABLE                           0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED                   0x828A
#define GL_FRAMEBUFFER_BLEND                                0x828B
#define GL_READ_PIXELS                                      0x828C
#define GL_READ_PIXELS_FORMAT                               0x828D
#define GL_READ_PIXELS_TYPE                                 0x828E
#define GL_TEXTURE_IMAGE_FORMAT                             0x828F
#define GL_TEXTURE_IMAGE_TYPE                               0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT                         0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE                           0x8292
#define GL_MIPMAP                                           0x8293
#define GL_MANUAL_GENERATE_MIPMAP                           0x8294
#define GL_AUTO_GENERATE_MIPMAP                             0x8295
#define GL_COLOR_ENCODING                                   0x8296
#define GL_SRGB_READ                                        0x8297
#define GL_SRGB_WRITE                                       0x8298
#define GL_SRGB_DECODE                                      0x8299
#define GL_FILTER                                           0x829A
#define GL_VERTEX_TEXTURE                                   0x829B
#define GL_TESS_CONTROL_TEXTURE                             0x829C
#define GL_TESS_EVALUATION_TEXTURE                          0x829D
#define GL_GEOMETRY_TEXTURE                                 0x829E
#define GL_FRAGMENT_TEXTURE                                 0x829F
#define GL_COMPUTE_TEXTURE                                  0x82A0
#define GL_TEXTURE_SHADOW                                   0x82A1
#define GL_TEXTURE_GATHER                                   0x82A2
#define GL_TEXTURE_GATHER_SHADOW                            0x82A3
#define GL_SHADER_IMAGE_LOAD                                0x82A4
#define GL_SHADER_IMAGE_STORE                               0x82A5
#define GL_SHADER_IMAGE_ATOMIC                              0x82A6
#define GL_IMAGE_TEXEL_SIZE                                 0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS                        0x82A8
#define GL_IMAGE_PIXEL_FORMAT                               0x82A9
#define GL_IMAGE_PIXEL_TYPE                                 0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST              0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST            0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE             0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE           0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH                   0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT                  0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE                    0x82B3
#define GL_CLEAR_BUFFER                                     0x82B4
#define GL_TEXTURE_VIEW                                     0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS                         0x82B6
#define GL_FULL_SUPPORT                                     0x82B7
#define GL_CAVEAT_SUPPORT                                   0x82B8
#define GL_IMAGE_CLASS_4_X_32                               0x82B9
#define GL_IMAGE_CLASS_2_X_32                               0x82BA
#define GL_IMAGE_CLASS_1_X_32                               0x82BB
#define GL_IMAGE_CLASS_4_X_16                               0x82BC
#define GL_IMAGE_CLASS_2_X_16                               0x82BD
#define GL_IMAGE_CLASS_1_X_16                               0x82BE
#define GL_IMAGE_CLASS_4_X_8                                0x82BF
#define GL_IMAGE_CLASS_2_X_8                                0x82C0
#define GL_IMAGE_CLASS_1_X_8                                0x82C1
#define GL_IMAGE_CLASS_11_11_10                             0x82C2
#define GL_IMAGE_CLASS_10_10_10_2                           0x82C3
#define GL_VIEW_CLASS_128_BITS                              0x82C4
#define GL_VIEW_CLASS_96_BITS                               0x82C5
#define GL_VIEW_CLASS_64_BITS                               0x82C6
#define GL_VIEW_CLASS_48_BITS                               0x82C7
#define GL_VIEW_CLASS_32_BITS                               0x82C8
#define GL_VIEW_CLASS_24_BITS                               0x82C9
#define GL_VIEW_CLASS_16_BITS                               0x82CA
#define GL_VIEW_CLASS_8_BITS                                0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB                         0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA                        0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA                        0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA                        0x82CF
#define GL_VIEW_CLASS_RGTC1_RED                             0x82D0
#define GL_VIEW_CLASS_RGTC2_RG                              0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM                            0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT                            0x82D3
#define GL_SHADER_STORAGE_BUFFER                            0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING                    0x90D3
#define GL_SHADER_STORAGE_BUFFER_START                      0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE                       0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS                 0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS               0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS           0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS        0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS               0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS                0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS               0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS               0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE                    0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT           0x90DF
#define GL_SHADER_STORAGE_BARRIER_BIT                       0x00002000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES             0x8F39
#define GL_TEXTURE_BUFFER_OFFSET                            0x919D
#define GL_TEXTURE_BUFFER_SIZE                              0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT                  0x919F
#define GL_DEPTH_STENCIL_TEXTURE_MODE                       0x90EA
#define GL_VERTEX_ATTRIB_BINDING                            0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET                    0x82D5
#define GL_VERTEX_BINDING_DIVISOR                           0x82D6
#define GL_VERTEX_BINDING_OFFSET                            0x82D7
#define GL_VERTEX_BINDING_STRIDE                            0x82D8
#define GL_VERTEX_BINDING_BUFFER                            0x8F4F
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET                0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS                       0x82DA
#define GL_TEXTURE_VIEW_MIN_LEVEL                           0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS                          0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER                           0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS                          0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS                         0x82DF
#define GL_DEBUG_TYPE_MARKER                                0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP                            0x8269
#define GL_DEBUG_TYPE_POP_GROUP                             0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION                      0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH                      0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH                          0x826D
#define GL_BUFFER                                           0x82E0
#define GL_SHADER                                           0x82E1
#define GL_PROGRAM                                          0x82E2
#define GL_QUERY                                            0x82E3
#define GL_PROGRAM_PIPELINE                                 0x82E4
#define GL_SAMPLER                                          0x82E6
#define GL_DISPLAY_LIST                                     0x82E7
#define GL_MAX_LABEL_LENGTH                                 0x82E8
#define GL_DEBUG_OUTPUT_SYNCHRONOUS                         0x8242
#define GL_MAX_DEBUG_MESSAGE_LENGTH                         0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES                        0x9144
#define GL_DEBUG_LOGGED_MESSAGES                            0x9145
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH                 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION                          0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM                        0x8245
#define GL_DEBUG_SOURCE_API                                 0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM                       0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER                     0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY                         0x8249
#define GL_DEBUG_SOURCE_APPLICATION                         0x824A
#define GL_DEBUG_SOURCE_OTHER                               0x824B
#define GL_DEBUG_TYPE_ERROR                                 0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR                   0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR                    0x824E
#define GL_DEBUG_TYPE_PORTABILITY                           0x824F
#define GL_DEBUG_TYPE_PERFORMANCE                           0x8250
#define GL_DEBUG_TYPE_OTHER                                 0x8251
#define GL_DEBUG_SEVERITY_HIGH                              0x9146
#define GL_DEBUG_SEVERITY_MEDIUM                            0x9147
#define GL_DEBUG_SEVERITY_LOW                               0x9148
#define GL_CONTEXT_FLAG_DEBUG_BIT                           0x00000002
#define GL_DEBUG_OUTPUT                                     0x92E0

/* VERSION_4_4 */
#define GL_MAX_VERTEX_ATTRIB_STRIDE                         0x82E5
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED          0x8221
#define GL_MAP_PERSISTENT_BIT                               0x0040
#define GL_MAP_COHERENT_BIT                                 0x0080
#define GL_DYNAMIC_STORAGE_BIT                              0x0100
#define GL_CLIENT_STORAGE_BIT                               0x0200
#define GL_BUFFER_IMMUTABLE_STORAGE                         0x821F
#define GL_BUFFER_STORAGE_FLAGS                             0x8220
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT                 0x00004000
#define GL_CLEAR_TEXTURE                                    0x9365
#define GL_LOCATION_COMPONENT                               0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX                  0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE                 0x934C
#define GL_QUERY_RESULT_NO_WAIT                             0x9194
#define GL_QUERY_BUFFER                                     0x9192
#define GL_QUERY_BUFFER_BINDING                             0x9193
#define GL_QUERY_BUFFER_BARRIER_BIT                         0x00008000
#define GL_MIRROR_CLAMP_TO_EDGE                             0x8743
/*      GL_UNSIGNED_INT_10F_11F_11F_REV */

/* VERSION_4_5 */
#define GL_NEGATIVE_ONE_TO_ONE                              0x935E
#define GL_ZERO_TO_ONE                                      0x935F
#define GL_CLIP_ORIGIN                                      0x935C
#define GL_CLIP_DEPTH_MODE                                  0x935D
#define GL_QUERY_WAIT_INVERTED                              0x8E17
#define GL_QUERY_NO_WAIT_INVERTED                           0x8E18
#define GL_QUERY_BY_REGION_WAIT_INVERTED                    0x8E19
#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED                 0x8E1A
#define GL_MAX_CULL_DISTANCES                               0x82F9
#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES             0x82FA
#define GL_TEXTURE_TARGET                                   0x1006
#define GL_QUERY_TARGET                                     0x82EA
#define GL_TEXTURE_BINDING                                  0x82EB
#define GL_BARRIER_REGION_ALL_PIXELS                        0x8D6E
#define GL_BARRIER_REGION_SINGLE_PIXEL                      0x8D6D
#define GL_CONTEXT_RELEASE_BEHAVIOR                         0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH                   0x82FC
#define GL_GUILTY_CONTEXT_RESET                             0x8253
#define GL_INNOCENT_CONTEXT_RESET                           0x8254
#define GL_UNKNOWN_CONTEXT_RESET                            0x8255
#define GL_RESET_NOTIFICATION_STRATEGY                      0x8256
#define GL_NO_RESET_NOTIFICATION                            0x8261
#define GL_LOSE_CONTEXT_ON_RESET                            0x8252
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT                   0x00000004
#define GL_CONTEXT_LOST                                     0x0507
#define GL_CONTEXT_ROBUST_ACCESS                            0x90F3

/* VERSION_4_6 */
#define GL_PARAMETER_BUFFER                                 0x80EE
#define GL_PARAMETER_BUFFER_BINDING                         0x80EF

/* EXT_x11_sync_object */
#define GL_SYNC_X11_FENCE_EXT                               0x90E1

/* NVX_shared_sync_object */
#define GL_SHARED_SYNC_NVX                                  0x90E2
#define GL_SEMAPHORE_ALIGNMENT_NVX                          0x90E3
#define GL_SEMAPHORE_ALLOC_SIZE_NVX                         0x90E4
#define GL_SEMAPHORE_PAYLOAD_SIZE_NVX                       0x90E5
#define GL_SEMAPHORE_PAYLOAD_OFFSET_NVX                     0x90E7
#define GL_FENCE_TIME_NVX                                   0x90E8
#define GL_SYNC_GEQ_WRAPPING_NVX                            0x90E9
#define GL_SYNC_USE_EVENT_BIT_NVX                           0x00000002
#define GL_SYNC_COPY_OP_NVX                                 0x00000004

/* ARB_debug_output */
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB                     0x8242
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB                     0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB                    0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB                        0x9145
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB             0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB                      0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB                    0x8245
#define GL_DEBUG_SOURCE_API_ARB                             0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB                   0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB                 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB                     0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB                     0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB                           0x824B
#define GL_DEBUG_TYPE_ERROR_ARB                             0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB               0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB                0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB                       0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB                       0x8250
#define GL_DEBUG_TYPE_OTHER_ARB                             0x8251
#define GL_DEBUG_SEVERITY_HIGH_ARB                          0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB                        0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB                           0x9148

/* NV_deep_texture3D */
#define GL_MAX_DEEP_3D_TEXTURE_WIDTH_HEIGHT_NV              0x90D0
#define GL_MAX_DEEP_3D_TEXTURE_DEPTH_NV                     0x90D1

/* OES_texture_half_float */
#define GL_HALF_FLOAT_OES                                   0x8D61

/* OES_draw_texture */
#define GL_TEXTURE_CROP_RECT_OES                            0x8B9D

/* ARB_robustness */
#define GL_GUILTY_CONTEXT_RESET_ARB                         0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB                       0x8254
#define GL_UNKNOWN_CONTEXT_RESET_ARB                        0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_ARB                  0x8256
#define GL_NO_RESET_NOTIFICATION_ARB                        0x8261
#define GL_LOSE_CONTEXT_ON_RESET_ARB                        0x8252
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB               0x00000004

/* NV_program_binary_asm */
#define GL_PROGRAM_BINARY_NV                                0x8E21

/* AMD_seamless_cubemap_per_texture */
/*      GL_TEXTURE_CUBE_MAP_SEAMLESS */

/* ARB_shading_language_include */
#define GL_SHADER_INCLUDE_ARB                               0x8DAE
#define GL_NAMED_STRING_LENGTH_ARB                          0x8DE9
#define GL_NAMED_STRING_TYPE_ARB                            0x8DEA

/* NV_blend_equation_advanced */
#define GL_BLEND_PREMULTIPLIED_SRC_NV                       0x9280
#define GL_BLEND_OVERLAP_NV                                 0x9281
#define GL_UNCORRELATED_NV                                  0x9282
#define GL_DISJOINT_NV                                      0x9283
#define GL_CONJOINT_NV                                      0x9284
#define GL_SRC_NV                                           0x9286
#define GL_DST_NV                                           0x9287
#define GL_SRC_OVER_NV                                      0x9288
#define GL_DST_OVER_NV                                      0x9289
#define GL_SRC_IN_NV                                        0x928A
#define GL_DST_IN_NV                                        0x928B
#define GL_SRC_OUT_NV                                       0x928C
#define GL_DST_OUT_NV                                       0x928D
#define GL_SRC_ATOP_NV                                      0x928E
#define GL_DST_ATOP_NV                                      0x928F
#define GL_XOR_NV                                           0x1506
#define GL_MULTIPLY_NV                                      0x9294
#define GL_SCREEN_NV                                        0x9295
#define GL_OVERLAY_NV                                       0x9296
#define GL_DARKEN_NV                                        0x9297
#define GL_LIGHTEN_NV                                       0x9298
#define GL_COLORDODGE_NV                                    0x9299
#define GL_COLORBURN_NV                                     0x929A
#define GL_HARDLIGHT_NV                                     0x929B
#define GL_SOFTLIGHT_NV                                     0x929C
#define GL_DIFFERENCE_NV                                    0x929E
#define GL_EXCLUSION_NV                                     0x92A0
#define GL_INVERT_RGB_NV                                    0x92A3
#define GL_LINEARDODGE_NV                                   0x92A4
#define GL_LINEARBURN_NV                                    0x92A5
#define GL_VIVIDLIGHT_NV                                    0x92A6
#define GL_LINEARLIGHT_NV                                   0x92A7
#define GL_PINLIGHT_NV                                      0x92A8
#define GL_HARDMIX_NV                                       0x92A9
#define GL_HSL_HUE_NV                                       0x92AD
#define GL_HSL_SATURATION_NV                                0x92AE
#define GL_HSL_COLOR_NV                                     0x92AF
#define GL_HSL_LUMINOSITY_NV                                0x92B0
#define GL_PLUS_NV                                          0x9291
#define GL_PLUS_CLAMPED_NV                                  0x92B1
#define GL_PLUS_CLAMPED_ALPHA_NV                            0x92B2
#define GL_PLUS_DARKER_NV                                   0x9292
#define GL_MINUS_NV                                         0x929F
#define GL_MINUS_CLAMPED_NV                                 0x92B3
#define GL_CONTRAST_NV                                      0x92A1
#define GL_INVERT_OVG_NV                                    0x92B4
#define GL_RED_NV                                           0x1903
#define GL_GREEN_NV                                         0x1904
#define GL_BLUE_NV                                          0x1905

/* NV_blend_equation_advanced_coherent */
#define GL_BLEND_ADVANCED_COHERENT_NV                       0x9285

/* EXT_texture_storage */
#define GL_TEXTURE_IMMUTABLE_FORMAT_EXT                     0x912F
#define GL_RGBA32F_EXT                                      0x8814
#define GL_RGB32F_EXT                                       0x8815
#define GL_ALPHA32F_EXT                                     0x8816
#define GL_LUMINANCE32F_EXT                                 0x8818
#define GL_LUMINANCE_ALPHA32F_EXT                           0x8819
#define GL_ALPHA16F_EXT                                     0x881C
#define GL_LUMINANCE16F_EXT                                 0x881E
#define GL_LUMINANCE_ALPHA16F_EXT                           0x881F
#define GL_RGB10_A2_EXT                                     0x8059
#define GL_RGB10_EXT                                        0x8052
#define GL_BGRA8_EXT                                        0x93A1
#define GL_R8_EXT                                           0x8229
#define GL_RG8_EXT                                          0x822B
#define GL_R32F_EXT                                         0x822E
#define GL_RG32F_EXT                                        0x8230

/* OES_read_format */
#define GL_IMPLEMENTATION_COLOR_READ_TYPE_OES               0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES             0x8B9B

/* OES_compressed_paletted_texture */
#define GL_PALETTE4_RGB8_OES                                0x8B90
#define GL_PALETTE4_RGBA8_OES                               0x8B91
#define GL_PALETTE4_R5_G6_B5_OES                            0x8B92
#define GL_PALETTE4_RGBA4_OES                               0x8B93
#define GL_PALETTE4_RGB5_A1_OES                             0x8B94
#define GL_PALETTE8_RGB8_OES                                0x8B95
#define GL_PALETTE8_RGBA8_OES                               0x8B96
#define GL_PALETTE8_R5_G6_B5_OES                            0x8B97
#define GL_PALETTE8_RGBA4_OES                               0x8B98
#define GL_PALETTE8_RGB5_A1_OES                             0x8B99

/* PointSizePointerTypeOES */
/*      GL_FLOAT */
/*      GL_FIXED */

/* OES_point_size_array */
#define GL_POINT_SIZE_ARRAY_OES                             0x8B9C
#define GL_POINT_SIZE_ARRAY_TYPE_OES                        0x898A
#define GL_POINT_SIZE_ARRAY_STRIDE_OES                      0x898B
#define GL_POINT_SIZE_ARRAY_POINTER_OES                     0x898C
#define GL_POINT_SIZE_ARRAY_BUFFER_BINDING_OES              0x8B9F

/* OES_point_sprite */
#define GL_POINT_SPRITE_OES                                 0x8861
#define GL_COORD_REPLACE_OES                                0x8862

/* KHR_texture_compression_astc_ldr */
#define GL_COMPRESSED_RGBA_ASTC_4x4_KHR                     0x93B0
#define GL_COMPRESSED_RGBA_ASTC_5x4_KHR                     0x93B1
#define GL_COMPRESSED_RGBA_ASTC_5x5_KHR                     0x93B2
#define GL_COMPRESSED_RGBA_ASTC_6x5_KHR                     0x93B3
#define GL_COMPRESSED_RGBA_ASTC_6x6_KHR                     0x93B4
#define GL_COMPRESSED_RGBA_ASTC_8x5_KHR                     0x93B5
#define GL_COMPRESSED_RGBA_ASTC_8x6_KHR                     0x93B6
#define GL_COMPRESSED_RGBA_ASTC_8x8_KHR                     0x93B7
#define GL_COMPRESSED_RGBA_ASTC_10x5_KHR                    0x93B8
#define GL_COMPRESSED_RGBA_ASTC_10x6_KHR                    0x93B9
#define GL_COMPRESSED_RGBA_ASTC_10x8_KHR                    0x93BA
#define GL_COMPRESSED_RGBA_ASTC_10x10_KHR                   0x93BB
#define GL_COMPRESSED_RGBA_ASTC_12x10_KHR                   0x93BC
#define GL_COMPRESSED_RGBA_ASTC_12x12_KHR                   0x93BD
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR             0x93D0
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR             0x93D1
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR             0x93D2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR             0x93D3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR             0x93D4
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR             0x93D5
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR             0x93D6
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR             0x93D7
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR            0x93D8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR            0x93D9
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR            0x93DA
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR           0x93DB
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR           0x93DC
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR           0x93DD

/* NV_compute_program5 */
#define GL_COMPUTE_PROGRAM_NV                               0x90FB
#define GL_COMPUTE_PROGRAM_PARAMETER_BUFFER_NV              0x90FC

/* KHR_debug */
#define GL_DEBUG_TYPE_MARKER_KHR                            0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP_KHR                        0x8269
#define GL_DEBUG_TYPE_POP_GROUP_KHR                         0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION_KHR                  0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH_KHR                  0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH_KHR                      0x826D
#define GL_BUFFER_KHR                                       0x82E0
#define GL_SHADER_KHR                                       0x82E1
#define GL_PROGRAM_KHR                                      0x82E2
#define GL_QUERY_KHR                                        0x82E3
#define GL_PROGRAM_PIPELINE_KHR                             0x82E4
#define GL_SAMPLER_KHR                                      0x82E6
#define GL_DISPLAY_LIST_KHR                                 0x82E7
#define GL_MAX_LABEL_LENGTH_KHR                             0x82E8
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_KHR                     0x8242
#define GL_MAX_DEBUG_MESSAGE_LENGTH_KHR                     0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_KHR                    0x9144
#define GL_DEBUG_LOGGED_MESSAGES_KHR                        0x9145
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_KHR             0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_KHR                      0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_KHR                    0x8245
#define GL_DEBUG_SOURCE_API_KHR                             0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_KHR                   0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_KHR                 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_KHR                     0x8249
#define GL_DEBUG_SOURCE_APPLICATION_KHR                     0x824A
#define GL_DEBUG_SOURCE_OTHER_KHR                           0x824B
#define GL_DEBUG_TYPE_ERROR_KHR                             0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_KHR               0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_KHR                0x824E
#define GL_DEBUG_TYPE_PORTABILITY_KHR                       0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_KHR                       0x8250
#define GL_DEBUG_TYPE_OTHER_KHR                             0x8251
#define GL_DEBUG_SEVERITY_HIGH_KHR                          0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_KHR                        0x9147
#define GL_DEBUG_SEVERITY_LOW_KHR                           0x9148
#define GL_CONTEXT_FLAG_DEBUG_BIT_KHR                       0x00000002
#define GL_DEBUG_OUTPUT_KHR                                 0x92E0

/* EXT_framebuffer_multisample_blit_scaled */
#define GL_SCALED_RESOLVE_FASTEST_EXT                       0x90BA
#define GL_SCALED_RESOLVE_NICEST_EXT                        0x90BB

/* NV_pack_subimage */
#define GL_PACK_ROW_LENGTH_NV                               0x0D02
#define GL_PACK_SKIP_ROWS_NV                                0x0D03
#define GL_PACK_SKIP_PIXELS_NV                              0x0D04
#define GL_PACK_SKIP_IMAGES_NV                              0x806B
#define GL_PACK_IMAGE_HEIGHT_NV                             0x806C

/* EXT_color_buffer_half_float */
#define GL_RGBA16F_EXT                                      0x881A
#define GL_RGB16F_EXT                                       0x881B
#define GL_RG16F_EXT                                        0x822F
#define GL_R16F_EXT                                         0x822D
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE_EXT        0x8211
#define GL_UNSIGNED_NORMALIZED_EXT                          0x8C17

/* EXT_shadow_samplers */
#define GL_TEXTURE_COMPARE_MODE_EXT                         0x884C
#define GL_TEXTURE_COMPARE_FUNC_EXT                         0x884D
#define GL_COMPARE_REF_TO_TEXTURE_EXT                       0x884E
#define GL_SAMPLER_2D_SHADOW_EXT                            0x8B62

/* EXT_sRGB */
#define GL_SRGB_EXT                                         0x8C40
#define GL_SRGB_ALPHA_EXT                                   0x8C42
#define GL_SRGB8_ALPHA8_EXT                                 0x8C43
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING_EXT        0x8210

/* NV_framebuffer_multisample */
#define GL_RENDERBUFFER_SAMPLES_NV                          0x8CAB
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_NV            0x8D56
#define GL_MAX_SAMPLES_NV                                   0x8D57

/* NV_instanced_arrays */
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR_NV                   0x88FE

/* NV_internalformat_sample_query */
#define GL_MULTISAMPLES_NV                                  0x9371
#define GL_SUPERSAMPLE_SCALE_X_NV                           0x9372
#define GL_SUPERSAMPLE_SCALE_Y_NV                           0x9373
#define GL_CONFORMANT_NV                                    0x9374

/* NV_shadow_samplers_array */
#define GL_SAMPLER_2D_ARRAY_SHADOW_NV                       0x8DC4

/* NV_shadow_samplers_cube */
#define GL_SAMPLER_CUBE_SHADOW_NV                           0x8DC5

/* NV_sRGB_formats */
#define GL_SLUMINANCE_ALPHA_NV                              0x8C44
#define GL_SLUMINANCE_NV                                    0x8C46
#define GL_SRGB8_NV                                         0x8C41
#define GL_COMPRESSED_SRGB_NV                               0x8C48
#define GL_COMPRESSED_SRGB_ALPHA_NV                         0x8C49
#define GL_COMPRESSED_SLUMINANCE_NV                         0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA_NV                   0x8C4B
#define GL_COMPRESSED_SRGB_S3TC_DXT1_NV                     0x8C4C
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_NV               0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_NV               0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_NV               0x8C4F
#define GL_ETC1_SRGB8_NV                                    0x88EE

/* NV_texture_border_clamp */
#define GL_TEXTURE_BORDER_COLOR_NV                          0x1004
#define GL_CLAMP_TO_BORDER_NV                               0x812D

/* OES_texture_border_clamp */
#define GL_TEXTURE_BORDER_COLOR_OES                         0x1004
#define GL_CLAMP_TO_BORDER_OES                              0x812D

/* OES_texture_buffer */
#define GL_TEXTURE_BUFFER_OES                               0x8C2A
#define GL_TEXTURE_BUFFER_BINDING_OES                       0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_OES                      0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_OES                       0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_OES            0x8C2D
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT_OES              0x919F
#define GL_SAMPLER_BUFFER_OES                               0x8DC2
#define GL_INT_SAMPLER_BUFFER_OES                           0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_OES                  0x8DD8
#define GL_IMAGE_BUFFER_OES                                 0x9051
#define GL_INT_IMAGE_BUFFER_OES                             0x905C
#define GL_UNSIGNED_INT_IMAGE_BUFFER_OES                    0x9067
#define GL_TEXTURE_BUFFER_OFFSET_OES                        0x919D
#define GL_TEXTURE_BUFFER_SIZE_OES                          0x919E

/* OES_depth_texture_cube_map */
#define GL_DEPTH_COMPONENT                                  0x1902
#define GL_DEPTH_STENCIL_OES                                0x84F9
#define GL_UNSIGNED_SHORT                                   0x1403
#define GL_UNSIGNED_INT                                     0x1405
#define GL_DEPTH24_STENCIL8_OES                             0x88F0

/* OES_EGL_image_external */
#define GL_TEXTURE_EXTERNAL_OES                             0x8D65
#define GL_SAMPLER_EXTERNAL_OES                             0x8D66
#define GL_TEXTURE_BINDING_EXTERNAL_OES                     0x8D67
#define GL_REQUIRED_TEXTURE_IMAGE_UNITS_OES                 0x8D68

/* NV_fragment_coverage_to_color */
#define GL_FRAGMENT_COVERAGE_TO_COLOR_NV                    0x92DD
#define GL_FRAGMENT_COVERAGE_COLOR_NV                       0x92DE

/* EXT_raster_multisample */
#define GL_RASTER_MULTISAMPLE_EXT                           0x9327
#define GL_RASTER_SAMPLES_EXT                               0x9328
#define GL_MAX_RASTER_SAMPLES_EXT                           0x9329
#define GL_RASTER_FIXED_SAMPLE_LOCATIONS_EXT                0x932A
#define GL_MULTISAMPLE_RASTERIZATION_ALLOWED_EXT            0x932B
#define GL_EFFECTIVE_RASTER_SAMPLES_EXT                     0x932C

/* NV_texture_array */
#define GL_TEXTURE_2D_ARRAY_NV                              0x8C1A
#define GL_TEXTURE_BINDING_2D_ARRAY_NV                      0x8C1D
#define GL_MAX_ARRAY_TEXTURE_LAYERS_NV                      0x88FF
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_NV          0x8CD4
#define GL_SAMPLER_2D_ARRAY_NV                              0x8DC1
#define GL_UNPACK_SKIP_IMAGES_NV                            0x806D
#define GL_UNPACK_IMAGE_HEIGHT_NV                           0x806E

/* OES_framebuffer_object */
#define GL_FRAMEBUFFER_OES                                  0x8D40
#define GL_RENDERBUFFER_OES                                 0x8D41
#define GL_DEPTH_COMPONENT16_OES                            0x81A5
#define GL_RGBA4_OES                                        0x8056
#define GL_RGB5_A1_OES                                      0x8057
#define GL_RGB565_OES                                       0x8D62
#define GL_STENCIL_INDEX1_OES                               0x8D46
#define GL_STENCIL_INDEX4_OES                               0x8D47
#define GL_STENCIL_INDEX8_OES                               0x8D48
#define GL_RENDERBUFFER_WIDTH_OES                           0x8D42
#define GL_RENDERBUFFER_HEIGHT_OES                          0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_OES                 0x8D44
#define GL_RENDERBUFFER_RED_SIZE_OES                        0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE_OES                      0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE_OES                       0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE_OES                      0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE_OES                      0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE_OES                    0x8D55
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_OES           0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_OES           0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TOESURE_LEVEL_OES         0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TOESURE_CUBE_MAP_FACE_OES 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TOESURE_3D_ZOFFSET_OES    0x8CD4
#define GL_COLOR_ATTACHMENT0_OES                            0x8CE0
#define GL_DEPTH_ATTACHMENT_OES                             0x8D00
#define GL_STENCIL_ATTACHMENT_OES                           0x8D20
#define GL_NONE_OES                                         0
#define GL_FRAMEBUFFER_COMPLETE_OES                         0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_OES            0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_OES    0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_OES            0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_OES               0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_OES           0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_OES           0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED_OES                      0x8CDD
#define GL_FRAMEBUFFER_BINDING_OES                          0x8CA6
#define GL_RENDERBUFFER_BINDING_OES                         0x8CA7
#define GL_MAX_RENDERBUFFER_SIZE_OES                        0x84E8
#define GL_INVALID_FRAMEBUFFER_OPERATION_OES                0x0506

/* EXT_unpack_subimage */
#define GL_UNPACK_ROW_LENGTH_EXT                            0x0CF2
#define GL_UNPACK_SKIP_ROWS_EXT                             0x0CF3
#define GL_UNPACK_SKIP_PIXELS_EXT                           0x0CF4

/* ARB_seamless_cubemap_per_texture */
/*      GL_TEXTURE_CUBE_MAP_SEAMLESS */

/* NV_shader_thread_group */
#define GL_WARP_SIZE_NV                                     0x9339
#define GL_WARPS_PER_SM_NV                                  0x933A
#define GL_SM_COUNT_NV                                      0x933B

/* NV_framebuffer_mixed_samples */
#define GL_DEPTH_SAMPLES_NV                                 0x932D
#define GL_STENCIL_SAMPLES_NV                               0x932E
#define GL_MIXED_DEPTH_SAMPLES_SUPPORTED_NV                 0x932F
#define GL_MIXED_STENCIL_SAMPLES_SUPPORTED_NV               0x9330
#define GL_COVERAGE_MODULATION_TABLE_NV                     0x9331
#define GL_COVERAGE_MODULATION_NV                           0x9332
#define GL_COVERAGE_MODULATION_TABLE_SIZE_NV                0x9333

/* NV_fill_rectangle */
#define GL_FILL_RECTANGLE_NV                                0x933C

/* NV_sample_locations */
#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_NV                 0x933D
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_NV              0x933E
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_NV             0x933F
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_NV       0x9340
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_NV                  0x9341
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_NV     0x9342
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_NV        0x9343
#define GL_SAMPLE_LOCATION_NV                               0x8E50

/* NV_path_rendering_shared_edge */
#define GL_SHARED_EDGE_NV                                   0xC0

/* ARB_compute_variable_group_size */
#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB          0x90EB
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB                 0x91BF
#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB       0x9344
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB              0x9345

/* OES_compressed_ETC1_RGB8_texture */
#define GL_ETC1_RGB8_OES                                    0x8D64

/* NV_conservative_raster */
#define GL_CONSERVATIVE_RASTERIZATION_NV                    0x9346
#define GL_SUBPIXEL_PRECISION_BIAS_X_BITS_NV                0x9347
#define GL_SUBPIXEL_PRECISION_BIAS_Y_BITS_NV                0x9348
#define GL_MAX_SUBPIXEL_PRECISION_BIAS_BITS_NV              0x9349

/* NV_viewport_array */
#define GL_MAX_VIEWPORTS_NV                                 0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS_NV                        0x825C
#define GL_VIEWPORT_BOUNDS_RANGE_NV                         0x825D
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX_NV               0x825F

/* NV_viewport_array2 */
#define GL_VIEWPORT_SWIZZLE_POSITIVE_X_NV                   0x9350
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_X_NV                   0x9351
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Y_NV                   0x9352
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Y_NV                   0x9353
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Z_NV                   0x9354
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Z_NV                   0x9355
#define GL_VIEWPORT_SWIZZLE_POSITIVE_W_NV                   0x9356
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_W_NV                   0x9357
#define GL_VIEWPORT_SWIZZLE_X_NV                            0x9358
#define GL_VIEWPORT_SWIZZLE_Y_NV                            0x9359
#define GL_VIEWPORT_SWIZZLE_Z_NV                            0x935A
#define GL_VIEWPORT_SWIZZLE_W_NV                            0x935B

/* NV_copy_buffer */
#define GL_COPY_READ_BUFFER_NV                              0x8F36
#define GL_COPY_WRITE_BUFFER_NV                             0x8F37

/* ARB_sparse_buffer */
#define GL_SPARSE_STORAGE_BIT_ARB                           0x0400
#define GL_SPARSE_BUFFER_PAGE_SIZE_ARB                      0x82F8

/* ARB_sparse_texture */
#define GL_TEXTURE_SPARSE_ARB                               0x91A6
#define GL_VIRTUAL_PAGE_SIZE_INDEX_ARB                      0x91A7
#define GL_NUM_SPARSE_LEVELS_ARB                            0x91AA
#define GL_NUM_VIRTUAL_PAGE_SIZES_ARB                       0x91A8
#define GL_VIRTUAL_PAGE_SIZE_X_ARB                          0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_ARB                          0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_ARB                          0x9197
#define GL_MAX_SPARSE_TEXTURE_SIZE_ARB                      0x9198
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB                   0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB              0x919A
#define GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB       0x91A9

/* ARB_bindless_texture */
#define GL_UNSIGNED_INT64_ARB                               0x140F

/* ARB_indirect_parameters */
#define GL_PARAMETER_BUFFER_ARB                             0x80EE
#define GL_PARAMETER_BUFFER_BINDING_ARB                     0x80EF

/* EXT_occlusion_query_boolean */
#define GL_ANY_SAMPLES_PASSED_EXT                           0x8C2F
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE_EXT              0x8D6A
#define GL_CURRENT_QUERY_EXT                                0x8865
#define GL_QUERY_RESULT_EXT                                 0x8866
#define GL_QUERY_RESULT_AVAILABLE_EXT                       0x8867

/* NV_occlusion_query_samples */
#define GL_SAMPLES_PASSED_NV                                0x8914

/* NV_timer_query */
#define GL_TIME_ELAPSED_NV                                  0x88BF
#define GL_TIMESTAMP_NV                                     0x8E28

/* NV_texture_compression_latc */
#define GL_COMPRESSED_LUMINANCE_LATC1_NV                    0x8C70
#define GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_NV             0x8C71
#define GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_NV              0x8C72
#define GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_NV       0x8C73

/* NV_bgr */
#define GL_BGR_NV                                           0x80E0

/* EXT_texture_filter_minmax */
#define GL_TEXTURE_REDUCTION_MODE_EXT                       0x9366
#define GL_WEIGHTED_AVERAGE_EXT                             0x9367

/* EXT_map_buffer_range */
#define GL_MAP_READ_BIT_EXT                                 0x0001
#define GL_MAP_WRITE_BIT_EXT                                0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT_EXT                     0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT_EXT                    0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT_EXT                       0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT_EXT                       0x0020

/* EXT_robustness */
#define GL_GUILTY_CONTEXT_RESET_EXT                         0x8253
#define GL_INNOCENT_CONTEXT_RESET_EXT                       0x8254
#define GL_UNKNOWN_CONTEXT_RESET_EXT                        0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_EXT                  0x8256
#define GL_NO_RESET_NOTIFICATION_EXT                        0x8261
#define GL_LOSE_CONTEXT_ON_RESET_EXT                        0x8252
#define GL_CONTEXT_ROBUST_ACCESS_EXT                        0x90F3

/* KHR_robustness */
#define GL_GUILTY_CONTEXT_RESET_KHR                         0x8253
#define GL_INNOCENT_CONTEXT_RESET_KHR                       0x8254
#define GL_UNKNOWN_CONTEXT_RESET_KHR                        0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_KHR                  0x8256
#define GL_NO_RESET_NOTIFICATION_KHR                        0x8261
#define GL_LOSE_CONTEXT_ON_RESET_KHR                        0x8252
#define GL_CONTEXT_ROBUST_ACCESS_KHR                        0x90F3
#define GL_CONTEXT_LOST_KHR                                 0x0507

/* NV_non_square_matrices */
#define GL_FLOAT_MAT2x3_NV                                  0x8B65
#define GL_FLOAT_MAT2x4_NV                                  0x8B66
#define GL_FLOAT_MAT3x2_NV                                  0x8B67
#define GL_FLOAT_MAT3x4_NV                                  0x8B68
#define GL_FLOAT_MAT4x2_NV                                  0x8B69
#define GL_FLOAT_MAT4x3_NV                                  0x8B6A

/* NV_framebuffer_blit */
#define GL_READ_FRAMEBUFFER_NV                              0x8CA8
#define GL_DRAW_FRAMEBUFFER_NV                              0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING_NV                      0x8CA6
#define GL_READ_FRAMEBUFFER_BINDING_NV                      0x8CAA

/* OES_matrix_get */
#define GL_MODELVIEW_MATRIX_FLOAT_AS_INT_BITS_OES           0x898D
#define GL_PROJECTION_MATRIX_FLOAT_AS_INT_BITS_OES          0x898E
#define GL_TEXTURE_MATRIX_FLOAT_AS_INT_BITS_OES             0x898F

/* OES_texture_cube_map */
#define GL_TEXTURE_GEN_MODE_OES                             0x2500
#define GL_NORMAL_MAP_OES                                   0x8511
#define GL_REFLECTION_MAP_OES                               0x8512
#define GL_TEXTURE_CUBE_MAP_OES                             0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_OES                     0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_OES                  0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_OES                  0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_OES                  0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_OES                  0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_OES                  0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_OES                  0x851A
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_OES                    0x851C
#define GL_TEXTURE_GEN_STR_OES                              0x8D60

/* OES_texture_cube_map_array */

/* OES_sample_shading */
#define GL_SAMPLE_SHADING_OES                               0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_OES                     0x8C37

/* OES_shader_multisample_interpolation */
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_OES            0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_OES            0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS_OES           0x8E5D

/* OES_texture_storage_multisample_2d_array */
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY_OES                 0x9102
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY_OES         0x9105
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY_OES                 0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY_OES             0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY_OES    0x910D

/* OES_surfaceless_context */
#define GL_FRAMEBUFFER_UNDEFINED_OES                        0x8219

/* EXT_gpu_shader5 */
#define GL_GEOMETRY_SHADER_INVOCATIONS_EXT                  0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS_EXT              0x8E5A
#define GL_MAX_VERTEX_STREAMS_EXT                           0x8E71

/* EXT_tessellation_shader */
#define GL_PATCHES_EXT                                      0xE
#define GL_PATCH_VERTICES_EXT                               0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL_EXT                    0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL_EXT                    0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES_EXT                 0x8E75
#define GL_TESS_GEN_MODE_EXT                                0x8E76
#define GL_TESS_GEN_SPACING_EXT                             0x8E77
#define GL_TESS_GEN_VERTEX_ORDER_EXT                        0x8E78
#define GL_TESS_GEN_POINT_MODE_EXT                          0x8E79
#define GL_ISOLINES_EXT                                     0x8E7A
#define GL_FRACTIONAL_ODD_EXT                               0x8E7B
#define GL_FRACTIONAL_EVEN_EXT                              0x8E7C
#define GL_MAX_PATCH_VERTICES_EXT                           0x8E7D
#define GL_MAX_TESS_GEN_LEVEL_EXT                           0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS_EXT          0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS_EXT       0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS_EXT         0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS_EXT      0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS_EXT           0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS_EXT                    0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS_EXT     0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS_EXT        0x8E86
#define GL_TESS_EVALUATION_SHADER_EXT                       0x8E87
#define GL_TESS_CONTROL_SHADER_EXT                          0x8E88
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS_EXT              0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS_EXT           0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS_EXT            0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS_EXT         0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS_EXT 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS_EXT 0x8E1F

/* OES_tessellation_shader */
#define GL_PATCHES_OES                                      0xE
#define GL_PATCH_VERTICES_OES                               0x8E72
#define GL_TESS_CONTROL_OUTPUT_VERTICES_OES                 0x8E75
#define GL_TESS_GEN_MODE_OES                                0x8E76
#define GL_TESS_GEN_SPACING_OES                             0x8E77
#define GL_TESS_GEN_VERTEX_ORDER_OES                        0x8E78
#define GL_TESS_GEN_POINT_MODE_OES                          0x8E79
#define GL_ISOLINES_OES                                     0x8E7A
#define GL_QUADS_OES                                        0x0007
#define GL_FRACTIONAL_ODD_OES                               0x8E7B
#define GL_FRACTIONAL_EVEN_OES                              0x8E7C
#define GL_MAX_PATCH_VERTICES_OES                           0x8E7D
#define GL_MAX_TESS_GEN_LEVEL_OES                           0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS_OES          0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS_OES       0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS_OES         0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS_OES      0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS_OES           0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS_OES                    0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS_OES     0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS_OES        0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS_OES              0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS_OES           0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS_OES            0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS_OES         0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS_OES 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS_OES 0x8E1F
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS_OES      0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS_OES   0x92CE
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS_OES             0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS_OES          0x92D4
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS_OES              0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS_OES           0x90CC
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS_OES       0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS_OES    0x90D9
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED_OES      0x8221
#define GL_IS_PER_PATCH_OES                                 0x92E7
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER_OES            0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER_OES         0x9308
#define GL_TESS_EVALUATION_SHADER_OES                       0x8E87
#define GL_TESS_CONTROL_SHADER_OES                          0x8E88
#define GL_TESS_CONTROL_SHADER_BIT_OES                      0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT_OES                   0x00000010

/* EXT_texture_cube_map_array */
#define GL_TEXTURE_CUBE_MAP_ARRAY_EXT                       0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_EXT               0x900A
#define GL_SAMPLER_CUBE_MAP_ARRAY_EXT                       0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_EXT                0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_EXT                   0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_EXT          0x900F

/* EXT_texture_view */
#define GL_TEXTURE_VIEW_MIN_LEVEL_EXT                       0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS_EXT                      0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER_EXT                       0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS_EXT                      0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS_EXT                     0x82DF

/* NV_pixel_buffer_object */
#define GL_PIXEL_PACK_BUFFER_NV                             0x88EB
#define GL_PIXEL_UNPACK_BUFFER_NV                           0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_NV                     0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_NV                   0x88EF

/* EXT_texture_rg */
#define GL_RED_EXT                                          0x1903
#define GL_RG_EXT                                           0x8227
#define GL_R8_EXT                                           0x8229
#define GL_RG8_EXT                                          0x822B

/* EXT_texture_border_clamp */
#define GL_TEXTURE_BORDER_COLOR_EXT                         0x1004
#define GL_CLAMP_TO_BORDER_EXT                              0x812D

/* KHR_blend_equation_advanced */
#define GL_MULTIPLY_KHR                                     0x9294
#define GL_SCREEN_KHR                                       0x9295
#define GL_OVERLAY_KHR                                      0x9296
#define GL_DARKEN_KHR                                       0x9297
#define GL_LIGHTEN_KHR                                      0x9298
#define GL_COLORDODGE_KHR                                   0x9299
#define GL_COLORBURN_KHR                                    0x929A
#define GL_HARDLIGHT_KHR                                    0x929B
#define GL_SOFTLIGHT_KHR                                    0x929C
#define GL_DIFFERENCE_KHR                                   0x929E
#define GL_EXCLUSION_KHR                                    0x92A0
#define GL_HSL_HUE_KHR                                      0x92AD
#define GL_HSL_SATURATION_KHR                               0x92AE
#define GL_HSL_COLOR_KHR                                    0x92AF
#define GL_HSL_LUMINOSITY_KHR                               0x92B0

/* KHR_blend_equation_advanced_coherent */
#define GL_BLEND_ADVANCED_COHERENT_KHR                      0x9285

/* EXT_sRGB_write_control */
#define GL_FRAMEBUFFER_SRGB_EXT                             0x8DB9

/* EXT_texture_buffer */
#define GL_TEXTURE_BUFFER_BINDING_EXT                       0x8C2A
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT_EXT              0x919F
#define GL_TEXTURE_BUFFER_OFFSET_EXT                        0x919D
#define GL_TEXTURE_BUFFER_SIZE_EXT                          0x919E

/* EXT_geometry_shader */
#define GL_GEOMETRY_LINKED_VERTICES_OUT_EXT                 0x8916
#define GL_GEOMETRY_LINKED_INPUT_TYPE_EXT                   0x8917
#define GL_GEOMETRY_LINKED_OUTPUT_TYPE_EXT                  0x8918

/* OES_geometry_shader */
#define GL_GEOMETRY_SHADER_OES                              0x8DD9
#define GL_GEOMETRY_SHADER_BIT_OES                          0x00000004
#define GL_GEOMETRY_LINKED_VERTICES_OUT_OES                 0x8916
#define GL_GEOMETRY_LINKED_INPUT_TYPE_OES                   0x8917
#define GL_GEOMETRY_LINKED_OUTPUT_TYPE_OES                  0x8918
#define GL_GEOMETRY_SHADER_INVOCATIONS_OES                  0x887F
#define GL_LAYER_PROVOKING_VERTEX_OES                       0x825E
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_OES              0x8DDF
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS_OES                  0x8A2C
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS_OES     0x8A32
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS_OES                0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS_OES               0x9124
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_OES                 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_OES         0x8DE1
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS_OES              0x8E5A
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_OES             0x8C29
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS_OES          0x92CF
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS_OES                 0x92D5
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS_OES                  0x90CD
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS_OES           0x90D7
#define GL_FIRST_VERTEX_CONVENTION_OES                      0x8E4D
#define GL_LAST_VERTEX_CONVENTION_OES                       0x8E4E
#define GL_UNDEFINED_VERTEX_OES                             0x8260
#define GL_PRIMITIVES_GENERATED_OES                         0x8C87
#define GL_LINES_ADJACENCY_OES                              0xA
#define GL_LINE_STRIP_ADJACENCY_OES                         0xB
#define GL_TRIANGLES_ADJACENCY_OES                          0xC
#define GL_TRIANGLE_STRIP_ADJACENCY_OES                     0xD
#define GL_FRAMEBUFFER_DEFAULT_LAYERS_OES                   0x9312
#define GL_MAX_FRAMEBUFFER_LAYERS_OES                       0x9317
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_OES         0x8DA8
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_OES               0x8DA7
#define GL_REFERENCED_BY_GEOMETRY_SHADER_OES                0x9309

/* EXT_primitive_bounding_box */
#define GL_PRIMITIVE_BOUNDING_BOX_EXT                       0x92BE

/* NV_compute_stream */
#define GL_MAX_COMPUTE_STREAMS_NV                           0x92BC
#define GL_COMPUTE_STREAM_NV                                0x92BD

/* ARB_pipeline_statistics_query */
#define GL_VERTICES_SUBMITTED_ARB                           0x82EE
#define GL_PRIMITIVES_SUBMITTED_ARB                         0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS_ARB                    0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES_ARB                  0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB           0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB           0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS_ARB                  0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS_ARB                   0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES_ARB                    0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES_ARB                   0x82F7

/* ARB_transform_feedback_overflow_query */
#define GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB                  0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB           0x82ED

/* NV_uniform_buffer_unified_memory */
#define GL_UNIFORM_BUFFER_UNIFIED_NV                        0x936E
#define GL_UNIFORM_BUFFER_ADDRESS_NV                        0x936F
#define GL_UNIFORM_BUFFER_LENGTH_NV                         0x9370

/* EXT_polygon_offset_clamp */
#define GL_POLYGON_OFFSET_CLAMP_EXT                         0x8E1B

/* NV_command_list */
#define GL_TERMINATE_SEQUENCE_COMMAND_NV                    0x0000
#define GL_NOP_COMMAND_NV                                   0x0001
#define GL_DRAW_ELEMENTS_COMMAND_NV                         0x0002
#define GL_DRAW_ARRAYS_COMMAND_NV                           0x0003
#define GL_DRAW_ELEMENTS_STRIP_COMMAND_NV                   0x0004
#define GL_DRAW_ARRAYS_STRIP_COMMAND_NV                     0x0005
#define GL_DRAW_ELEMENTS_INSTANCED_COMMAND_NV               0x0006
#define GL_DRAW_ARRAYS_INSTANCED_COMMAND_NV                 0x0007
#define GL_ELEMENT_ADDRESS_COMMAND_NV                       0x0008
#define GL_ATTRIBUTE_ADDRESS_COMMAND_NV                     0x0009
#define GL_UNIFORM_ADDRESS_COMMAND_NV                       0x000a
#define GL_BLEND_COLOR_COMMAND_NV                           0x000b
#define GL_STENCIL_REF_COMMAND_NV                           0x000c
#define GL_LINE_WIDTH_COMMAND_NV                            0x000d
#define GL_POLYGON_OFFSET_COMMAND_NV                        0x000e
#define GL_ALPHA_REF_COMMAND_NV                             0x000f
#define GL_VIEWPORT_COMMAND_NV                              0x0010
#define GL_SCISSOR_COMMAND_NV                               0x0011

/* EXT_buffer_storage */
#define GL_MAP_PERSISTENT_BIT_EXT                           0x0040
#define GL_MAP_COHERENT_BIT_EXT                             0x0080
#define GL_DYNAMIC_STORAGE_BIT_EXT                          0x0100
#define GL_CLIENT_STORAGE_BIT_EXT                           0x0200
#define GL_BUFFER_IMMUTABLE_STORAGE_EXT                     0x821F
#define GL_BUFFER_STORAGE_FLAGS_EXT                         0x8220
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT_EXT             0x00004000

/* ARB_parallel_shader_compile */
#define GL_MAX_SHADER_COMPILER_THREADS_ARB                  0x91B0
#define GL_COMPLETION_STATUS_ARB                            0x91B1

/* NVX_linked_gpu_multicast */
#define GL_MAX_LGPU_GPUS_NVX                                0x92BA
#define GL_LGPU_SEPARATE_STORAGE_BIT_NVX                    0x0800

/* NV_gpu_multicast */
#define GL_MULTICAST_GPUS_NV                                0x92BA
#define GL_MAX_DISPLAY_VIEWPORTS_NV                         0x954A
#define GL_DISPLAY_VIEWPORT_NV                              0x954B
#define GL_DISPLAY_VIEWPORT_GPU_MASK_NV                     0x954C
#define GL_PER_GPU_STORAGE_BIT_NV                           0x0800
#define GL_GPU_SHARED_STORAGE_BIT_NV                        0x1000

/* NV_robustness_video_memory_purge */
#define GL_PURGED_CONTEXT_RESET_NV                          0x92BB

/* NVX_multigpu_info */
#define GL_CURRENT_AFR_GPU_NVX                              0x9560
#define GL_NUM_AFR_GPUS_NVX                                 0x9561
#define GL_MAX_AFR_GPUS_NVX                                 0x9562

/* NVX_cross_process_interop */
#define GL_TEXTURE_EXTERNAL_NVX                             0x9570
#define GL_EXTERNAL_HANDLE_TYPE_ANDROID_NATIVE_BUFFER_NVX   0x9571
#define GL_BUFFER_OBJECT_NVX                                0x9151
#define GL_TEXTURE_TARGET_NVX                               0x1006
#define GL_EXTERNAL_STORAGE_BIT_NVX                         0x2000

/* EXT_external_objects */
#define GL_TEXTURE_TILING_EXT                               0x9580
#define GL_DEDICATED_MEMORY_OBJECT_EXT                      0x9581
#define GL_NUM_TILING_TYPES_EXT                             0x9582
#define GL_TILING_TYPES_EXT                                 0x9583
#define GL_OPTIMAL_TILING_EXT                               0x9584
#define GL_LINEAR_TILING_EXT                                0x9585
#define GL_HANDLE_TYPE_OPAQUE_FD_EXT                        0x9586
#define GL_HANDLE_TYPE_OPAQUE_WIN32_EXT                     0x9587
#define GL_HANDLE_TYPE_OPAQUE_WIN32_KMT_EXT                 0x9588
#define GL_HANDLE_TYPE_D3D12_TILEPOOL_EXT                   0x9589
#define GL_HANDLE_TYPE_D3D12_RESOURCE_EXT                   0x958A
#define GL_HANDLE_TYPE_D3D11_IMAGE_EXT                      0x958B
#define GL_HANDLE_TYPE_D3D11_IMAGE_KMT_EXT                  0x958C
#define GL_LAYOUT_GENERAL_EXT                               0x958D
#define GL_LAYOUT_COLOR_ATTACHMENT_EXT                      0x958E
#define GL_LAYOUT_DEPTH_STENCIL_ATTACHMENT_EXT              0x958F
#define GL_LAYOUT_DEPTH_STENCIL_READ_ONLY_EXT               0x9590
#define GL_LAYOUT_SHADER_READ_ONLY_EXT                      0x9591
#define GL_LAYOUT_TRANSFER_SRC_EXT                          0x9592
#define GL_LAYOUT_TRANSFER_DST_EXT                          0x9593
#define GL_HANDLE_TYPE_D3D12_FENCE_EXT                      0x9594
#define GL_D3D12_FENCE_VALUE_EXT                            0x9595
#define GL_NUM_DEVICE_UUIDS_EXT                             0x9596
#define GL_DEVICE_UUID_EXT                                  0x9597
#define GL_DRIVER_UUID_EXT                                  0x9598
#define GL_DEVICE_LUID_EXT                                  0x9599
#define GL_DEVICE_NODE_MASK_EXT                             0x959A
#define GL_PROTECTED_MEMORY_OBJECT_EXT                      0x959B
#define GL_UUID_SIZE_EXT                                    16
#define GL_LUID_SIZE_EXT                                    8

/* NV_texture_dirty_tile_map */
#define GL_DIRTY_TILE_MAP_CLEAN_COLOR_MASK_NV               0x9572
#define GL_DIRTY_TILE_MAP_TILE_WIDTH_NV                     0x9573
#define GL_DIRTY_TILE_MAP_TILE_HEIGHT_NV                    0x9574
#define GL_DIRTY_TILE_MAP_STRIDE_NV                         0x9575
#define GL_DIRTY_TILE_MAP_SIZE_NV                           0x9576
#define GL_NUM_DIRTY_TILE_MAP_CLEAN_COLORS_NV               0x9577
#define GL_DIRTY_TILE_MAP_CLEAN_COLOR_NV                    0x9578

/* OVR_multiview */
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_NUM_VIEWS_OVR     0x9630
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_BASE_VIEW_INDEX_OVR 0x9632
#define GL_MAX_VIEWS_OVR                                    0x9631
#define GL_FRAMEBUFFER_INCOMPLETE_VIEW_TARGETS_OVR          0x9633

/*************************************************************/



#ifdef __cplusplus
}
#endif

#endif /* __glext_h_ */
