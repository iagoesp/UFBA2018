//---------------------------------------------------------------------------
// File: gl.h
//
// Copyright (c) NVIDIA Corporation.  All rights reserved.
//---------------------------------------------------------------------------

#ifndef __gl_h_
#define __gl_h_

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

typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;
typedef int GLfixed;
typedef int GLclampx;


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

/*************************************************************/

/* Version */
#define GL_VERSION_1_1                                      1
#define GL_VERSION_1_2                                      1
#define GL_VERSION_1_3                                      1
#define GL_VERSION_1_4                                      1
#define GL_VERSION_1_5                                      1
#define GL_VERSION_2_0                                      1
#define GL_VERSION_2_1                                      1
#define GL_VERSION_3_0                                      1
#define GL_VERSION_3_1                                      1
#define GL_VERSION_3_2                                      1
#define GL_VERSION_3_3                                      1
#define GL_VERSION_4_0                                      1
#define GL_VERSION_4_1                                      1
#define GL_VERSION_4_2                                      1
#define GL_VERSION_4_3                                      1
#define GL_VERSION_4_4                                      1
#define GL_VERSION_4_5                                      1
#define GL_VERSION_4_6                                      1

/* AttribMask */
#define GL_CURRENT_BIT                                      0x00000001
#define GL_POINT_BIT                                        0x00000002
#define GL_LINE_BIT                                         0x00000004
#define GL_POLYGON_BIT                                      0x00000008
#define GL_POLYGON_STIPPLE_BIT                              0x00000010
#define GL_PIXEL_MODE_BIT                                   0x00000020
#define GL_LIGHTING_BIT                                     0x00000040
#define GL_FOG_BIT                                          0x00000080
#define GL_DEPTH_BUFFER_BIT                                 0x00000100
#define GL_ACCUM_BUFFER_BIT                                 0x00000200
#define GL_STENCIL_BUFFER_BIT                               0x00000400
#define GL_VIEWPORT_BIT                                     0x00000800
#define GL_TRANSFORM_BIT                                    0x00001000
#define GL_ENABLE_BIT                                       0x00002000
#define GL_COLOR_BUFFER_BIT                                 0x00004000
#define GL_HINT_BIT                                         0x00008000
#define GL_EVAL_BIT                                         0x00010000
#define GL_LIST_BIT                                         0x00020000
#define GL_TEXTURE_BIT                                      0x00040000
#define GL_SCISSOR_BIT                                      0x00080000
#define GL_ALL_ATTRIB_BITS                                  0xFFFFFFFF

/* ClearBufferMask */
/*      GL_COLOR_BUFFER_BIT */
/*      GL_ACCUM_BUFFER_BIT */
/*      GL_STENCIL_BUFFER_BIT */
/*      GL_DEPTH_BUFFER_BIT */

/* ClientAttribMask */
#define GL_CLIENT_PIXEL_STORE_BIT                           0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT                          0x00000002
#define GL_CLIENT_ALL_ATTRIB_BITS                           0xFFFFFFFF

/* Boolean */
#define GL_FALSE                                            0
#define GL_TRUE                                             1

/* BeginMode */
#define GL_POINTS                                           0x0000
#define GL_LINES                                            0x0001
#define GL_LINE_LOOP                                        0x0002
#define GL_LINE_STRIP                                       0x0003
#define GL_TRIANGLES                                        0x0004
#define GL_TRIANGLE_STRIP                                   0x0005
#define GL_TRIANGLE_FAN                                     0x0006
#define GL_QUADS                                            0x0007
#define GL_QUAD_STRIP                                       0x0008
#define GL_POLYGON                                          0x0009

/* AccumOp */
#define GL_ACCUM                                            0x0100
#define GL_LOAD                                             0x0101
#define GL_RETURN                                           0x0102
#define GL_MULT                                             0x0103
#define GL_ADD                                              0x0104

/* AlphaFunction */
#define GL_NEVER                                            0x0200
#define GL_LESS                                             0x0201
#define GL_EQUAL                                            0x0202
#define GL_LEQUAL                                           0x0203
#define GL_GREATER                                          0x0204
#define GL_NOTEQUAL                                         0x0205
#define GL_GEQUAL                                           0x0206
#define GL_ALWAYS                                           0x0207

/* BlendingFactorDest */
#define GL_ZERO                                             0
#define GL_ONE                                              1
#define GL_SRC_COLOR                                        0x0300
#define GL_ONE_MINUS_SRC_COLOR                              0x0301
#define GL_SRC_ALPHA                                        0x0302
#define GL_ONE_MINUS_SRC_ALPHA                              0x0303
#define GL_DST_ALPHA                                        0x0304
#define GL_ONE_MINUS_DST_ALPHA                              0x0305

/* BlendingFactorSrc */
/*      GL_ZERO */
/*      GL_ONE */
#define GL_DST_COLOR                                        0x0306
#define GL_ONE_MINUS_DST_COLOR                              0x0307
#define GL_SRC_ALPHA_SATURATE                               0x0308
/*      GL_SRC_ALPHA */
/*      GL_ONE_MINUS_SRC_ALPHA */
/*      GL_DST_ALPHA */
/*      GL_ONE_MINUS_DST_ALPHA */

/* ColorMaterialFace */
/*      GL_FRONT */
/*      GL_BACK */
/*      GL_FRONT_AND_BACK */

/* ColorMaterialParameter */
/*      GL_AMBIENT */
/*      GL_DIFFUSE */
/*      GL_SPECULAR */
/*      GL_EMISSION */
/*      GL_AMBIENT_AND_DIFFUSE */

/* ColorPointerType */
/*      GL_BYTE */
/*      GL_UNSIGNED_BYTE */
/*      GL_SHORT */
/*      GL_UNSIGNED_SHORT */
/*      GL_INT */
/*      GL_UNSIGNED_INT */
/*      GL_FLOAT */
/*      GL_DOUBLE */

/* CullFaceMode */
/*      GL_FRONT */
/*      GL_BACK */
/*      GL_FRONT_AND_BACK */

/* DepthFunction */
/*      GL_NEVER */
/*      GL_LESS */
/*      GL_EQUAL */
/*      GL_LEQUAL */
/*      GL_GREATER */
/*      GL_NOTEQUAL */
/*      GL_GEQUAL */
/*      GL_ALWAYS */

/* DrawBufferMode */
#define GL_NONE                                             0
#define GL_FRONT_LEFT                                       0x0400
#define GL_FRONT_RIGHT                                      0x0401
#define GL_BACK_LEFT                                        0x0402
#define GL_BACK_RIGHT                                       0x0403
#define GL_FRONT                                            0x0404
#define GL_BACK                                             0x0405
#define GL_LEFT                                             0x0406
#define GL_RIGHT                                            0x0407
#define GL_FRONT_AND_BACK                                   0x0408
#define GL_AUX0                                             0x0409
#define GL_AUX1                                             0x040A
#define GL_AUX2                                             0x040B
#define GL_AUX3                                             0x040C
#define GL_AUX4                                             0x040D
#define GL_AUX5                                             0x040E
#define GL_AUX6                                             0x040F
#define GL_AUX7                                             0x0410

/* EnableCap */
/*      GL_FOG */
/*      GL_LIGHTING */
/*      GL_TEXTURE_1D */
/*      GL_TEXTURE_2D */
/*      GL_LINE_STIPPLE */
/*      GL_POLYGON_STIPPLE */
/*      GL_CULL_FACE */
/*      GL_ALPHA_TEST */
/*      GL_BLEND */
/*      GL_INDEX_LOGIC_OP */
/*      GL_COLOR_LOGIC_OP */
/*      GL_DITHER */
/*      GL_STENCIL_TEST */
/*      GL_DEPTH_TEST */
/*      GL_CLIP_PLANE0 */
/*      GL_CLIP_PLANE1 */
/*      GL_CLIP_PLANE2 */
/*      GL_CLIP_PLANE3 */
/*      GL_CLIP_PLANE4 */
/*      GL_CLIP_PLANE5 */
/*      GL_LIGHT0 */
/*      GL_LIGHT1 */
/*      GL_LIGHT2 */
/*      GL_LIGHT3 */
/*      GL_LIGHT4 */
/*      GL_LIGHT5 */
/*      GL_LIGHT6 */
/*      GL_LIGHT7 */
/*      GL_TEXTURE_GEN_S */
/*      GL_TEXTURE_GEN_T */
/*      GL_TEXTURE_GEN_R */
/*      GL_TEXTURE_GEN_Q */
/*      GL_MAP1_VERTEX_3 */
/*      GL_MAP1_VERTEX_4 */
/*      GL_MAP1_COLOR_4 */
/*      GL_MAP1_INDEX */
/*      GL_MAP1_NORMAL */
/*      GL_MAP1_TEXTURE_COORD_1 */
/*      GL_MAP1_TEXTURE_COORD_2 */
/*      GL_MAP1_TEXTURE_COORD_3 */
/*      GL_MAP1_TEXTURE_COORD_4 */
/*      GL_MAP2_VERTEX_3 */
/*      GL_MAP2_VERTEX_4 */
/*      GL_MAP2_COLOR_4 */
/*      GL_MAP2_INDEX */
/*      GL_MAP2_NORMAL */
/*      GL_MAP2_TEXTURE_COORD_1 */
/*      GL_MAP2_TEXTURE_COORD_2 */
/*      GL_MAP2_TEXTURE_COORD_3 */
/*      GL_MAP2_TEXTURE_COORD_4 */
/*      GL_POINT_SMOOTH */
/*      GL_LINE_SMOOTH */
/*      GL_POLYGON_SMOOTH */
/*      GL_SCISSOR_TEST */
/*      GL_COLOR_MATERIAL */
/*      GL_NORMALIZE */
/*      GL_AUTO_NORMAL */
/*      GL_POLYGON_OFFSET_POINT */
/*      GL_POLYGON_OFFSET_LINE */
/*      GL_POLYGON_OFFSET_FILL */
/*      GL_VERTEX_ARRAY */
/*      GL_NORMAL_ARRAY */
/*      GL_COLOR_ARRAY */
/*      GL_INDEX_ARRAY */
/*      GL_TEXTURE_COORD_ARRAY */
/*      GL_EDGE_FLAG_ARRAY */

/* ErrorCode */
#define GL_NO_ERROR                                         0
#define GL_INVALID_ENUM                                     0x0500
#define GL_INVALID_VALUE                                    0x0501
#define GL_INVALID_OPERATION                                0x0502
#define GL_STACK_OVERFLOW                                   0x0503
#define GL_STACK_UNDERFLOW                                  0x0504
#define GL_OUT_OF_MEMORY                                    0x0505
#define GL_TABLE_TOO_LARGE                                  0x8031

/* FeedbackType */
#define GL_2D                                               0x0600
#define GL_3D                                               0x0601
#define GL_3D_COLOR                                         0x0602
#define GL_3D_COLOR_TEXTURE                                 0x0603
#define GL_4D_COLOR_TEXTURE                                 0x0604

/* FeedBackToken */
#define GL_PASS_THROUGH_TOKEN                               0x0700
#define GL_POINT_TOKEN                                      0x0701
#define GL_LINE_TOKEN                                       0x0702
#define GL_POLYGON_TOKEN                                    0x0703
#define GL_BITMAP_TOKEN                                     0x0704
#define GL_DRAW_PIXEL_TOKEN                                 0x0705
#define GL_COPY_PIXEL_TOKEN                                 0x0706
#define GL_LINE_RESET_TOKEN                                 0x0707

/* FogMode */
/*      GL_LINEAR */
#define GL_EXP                                              0x0800
#define GL_EXP2                                             0x0801

/* FogParameter */
/*      GL_FOG_COLOR */
/*      GL_FOG_DENSITY */
/*      GL_FOG_END */
/*      GL_FOG_INDEX */
/*      GL_FOG_MODE */
/*      GL_FOG_START */

/* FrontFaceDirection */
#define GL_CW                                               0x0900
#define GL_CCW                                              0x0901

/* GetMapQuery */
#define GL_COEFF                                            0x0A00
#define GL_ORDER                                            0x0A01
#define GL_DOMAIN                                           0x0A02

/* GetPixelMap */
#define GL_PIXEL_MAP_I_TO_I                                 0x0C70
#define GL_PIXEL_MAP_S_TO_S                                 0x0C71
#define GL_PIXEL_MAP_I_TO_R                                 0x0C72
#define GL_PIXEL_MAP_I_TO_G                                 0x0C73
#define GL_PIXEL_MAP_I_TO_B                                 0x0C74
#define GL_PIXEL_MAP_I_TO_A                                 0x0C75
#define GL_PIXEL_MAP_R_TO_R                                 0x0C76
#define GL_PIXEL_MAP_G_TO_G                                 0x0C77
#define GL_PIXEL_MAP_B_TO_B                                 0x0C78
#define GL_PIXEL_MAP_A_TO_A                                 0x0C79

/* GetPointervPName */
#define GL_VERTEX_ARRAY_POINTER                             0x808E
#define GL_NORMAL_ARRAY_POINTER                             0x808F
#define GL_COLOR_ARRAY_POINTER                              0x8090
#define GL_INDEX_ARRAY_POINTER                              0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER                      0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER                          0x8093

/* GetPName */
#define GL_CURRENT_COLOR                                    0x0B00
#define GL_CURRENT_INDEX                                    0x0B01
#define GL_CURRENT_NORMAL                                   0x0B02
#define GL_CURRENT_TEXTURE_COORDS                           0x0B03
#define GL_CURRENT_RASTER_COLOR                             0x0B04
#define GL_CURRENT_RASTER_INDEX                             0x0B05
#define GL_CURRENT_RASTER_TEXTURE_COORDS                    0x0B06
#define GL_CURRENT_RASTER_POSITION                          0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID                    0x0B08
#define GL_CURRENT_RASTER_DISTANCE                          0x0B09
#define GL_POINT_SMOOTH                                     0x0B10
#define GL_POINT_SIZE                                       0x0B11
#define GL_SMOOTH_POINT_SIZE_RANGE                          0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY                    0x0B13
#define GL_POINT_SIZE_RANGE                                 GL_SMOOTH_POINT_SIZE_RANGE
#define GL_POINT_SIZE_GRANULARITY                           GL_SMOOTH_POINT_SIZE_GRANULARITY
#define GL_LINE_SMOOTH                                      0x0B20
#define GL_LINE_WIDTH                                       0x0B21
#define GL_SMOOTH_LINE_WIDTH_RANGE                          0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY                    0x0B23
#define GL_LINE_WIDTH_RANGE                                 GL_SMOOTH_LINE_WIDTH_RANGE
#define GL_LINE_WIDTH_GRANULARITY                           GL_SMOOTH_LINE_WIDTH_GRANULARITY
#define GL_LINE_STIPPLE                                     0x0B24
#define GL_LINE_STIPPLE_PATTERN                             0x0B25
#define GL_LINE_STIPPLE_REPEAT                              0x0B26
#define GL_LIST_MODE                                        0x0B30
#define GL_MAX_LIST_NESTING                                 0x0B31
#define GL_LIST_BASE                                        0x0B32
#define GL_LIST_INDEX                                       0x0B33
#define GL_POLYGON_MODE                                     0x0B40
#define GL_POLYGON_SMOOTH                                   0x0B41
#define GL_POLYGON_STIPPLE                                  0x0B42
#define GL_EDGE_FLAG                                        0x0B43
#define GL_CULL_FACE                                        0x0B44
#define GL_CULL_FACE_MODE                                   0x0B45
#define GL_FRONT_FACE                                       0x0B46
#define GL_LIGHTING                                         0x0B50
#define GL_LIGHT_MODEL_LOCAL_VIEWER                         0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE                             0x0B52
#define GL_LIGHT_MODEL_AMBIENT                              0x0B53
#define GL_SHADE_MODEL                                      0x0B54
#define GL_COLOR_MATERIAL_FACE                              0x0B55
#define GL_COLOR_MATERIAL_PARAMETER                         0x0B56
#define GL_COLOR_MATERIAL                                   0x0B57
#define GL_FOG                                              0x0B60
#define GL_FOG_INDEX                                        0x0B61
#define GL_FOG_DENSITY                                      0x0B62
#define GL_FOG_START                                        0x0B63
#define GL_FOG_END                                          0x0B64
#define GL_FOG_MODE                                         0x0B65
#define GL_FOG_COLOR                                        0x0B66
#define GL_DEPTH_RANGE                                      0x0B70
#define GL_DEPTH_TEST                                       0x0B71
#define GL_DEPTH_WRITEMASK                                  0x0B72
#define GL_DEPTH_CLEAR_VALUE                                0x0B73
#define GL_DEPTH_FUNC                                       0x0B74
#define GL_ACCUM_CLEAR_VALUE                                0x0B80
#define GL_STENCIL_TEST                                     0x0B90
#define GL_STENCIL_CLEAR_VALUE                              0x0B91
#define GL_STENCIL_FUNC                                     0x0B92
#define GL_STENCIL_VALUE_MASK                               0x0B93
#define GL_STENCIL_FAIL                                     0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL                          0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS                          0x0B96
#define GL_STENCIL_REF                                      0x0B97
#define GL_STENCIL_WRITEMASK                                0x0B98
#define GL_MATRIX_MODE                                      0x0BA0
#define GL_NORMALIZE                                        0x0BA1
#define GL_VIEWPORT                                         0x0BA2
#define GL_MODELVIEW_STACK_DEPTH                            0x0BA3
#define GL_PROJECTION_STACK_DEPTH                           0x0BA4
#define GL_TEXTURE_STACK_DEPTH                              0x0BA5
#define GL_MODELVIEW_MATRIX                                 0x0BA6
#define GL_PROJECTION_MATRIX                                0x0BA7
#define GL_TEXTURE_MATRIX                                   0x0BA8
#define GL_ATTRIB_STACK_DEPTH                               0x0BB0
#define GL_CLIENT_ATTRIB_STACK_DEPTH                        0x0BB1
#define GL_ALPHA_TEST                                       0x0BC0
#define GL_ALPHA_TEST_FUNC                                  0x0BC1
#define GL_ALPHA_TEST_REF                                   0x0BC2
#define GL_DITHER                                           0x0BD0
#define GL_BLEND_DST                                        0x0BE0
#define GL_BLEND_SRC                                        0x0BE1
#define GL_BLEND                                            0x0BE2
#define GL_LOGIC_OP_MODE                                    0x0BF0
#define GL_INDEX_LOGIC_OP                                   0x0BF1
#define GL_LOGIC_OP                                         GL_INDEX_LOGIC_OP
#define GL_COLOR_LOGIC_OP                                   0x0BF2
#define GL_AUX_BUFFERS                                      0x0C00
#define GL_DRAW_BUFFER                                      0x0C01
#define GL_READ_BUFFER                                      0x0C02
#define GL_SCISSOR_BOX                                      0x0C10
#define GL_SCISSOR_TEST                                     0x0C11
#define GL_INDEX_CLEAR_VALUE                                0x0C20
#define GL_INDEX_WRITEMASK                                  0x0C21
#define GL_COLOR_CLEAR_VALUE                                0x0C22
#define GL_COLOR_WRITEMASK                                  0x0C23
#define GL_INDEX_MODE                                       0x0C30
#define GL_RGBA_MODE                                        0x0C31
#define GL_DOUBLEBUFFER                                     0x0C32
#define GL_STEREO                                           0x0C33
#define GL_RENDER_MODE                                      0x0C40
#define GL_PERSPECTIVE_CORRECTION_HINT                      0x0C50
#define GL_POINT_SMOOTH_HINT                                0x0C51
#define GL_LINE_SMOOTH_HINT                                 0x0C52
#define GL_POLYGON_SMOOTH_HINT                              0x0C53
#define GL_FOG_HINT                                         0x0C54
#define GL_TEXTURE_GEN_S                                    0x0C60
#define GL_TEXTURE_GEN_T                                    0x0C61
#define GL_TEXTURE_GEN_R                                    0x0C62
#define GL_TEXTURE_GEN_Q                                    0x0C63
#define GL_PIXEL_MAP_I_TO_I_SIZE                            0x0CB0
#define GL_PIXEL_MAP_S_TO_S_SIZE                            0x0CB1
#define GL_PIXEL_MAP_I_TO_R_SIZE                            0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE                            0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE                            0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE                            0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE                            0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE                            0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE                            0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE                            0x0CB9
#define GL_UNPACK_SWAP_BYTES                                0x0CF0
#define GL_UNPACK_LSB_FIRST                                 0x0CF1
#define GL_UNPACK_ROW_LENGTH                                0x0CF2
#define GL_UNPACK_SKIP_ROWS                                 0x0CF3
#define GL_UNPACK_SKIP_PIXELS                               0x0CF4
#define GL_UNPACK_ALIGNMENT                                 0x0CF5
#define GL_PACK_SWAP_BYTES                                  0x0D00
#define GL_PACK_LSB_FIRST                                   0x0D01
#define GL_PACK_ROW_LENGTH                                  0x0D02
#define GL_PACK_SKIP_ROWS                                   0x0D03
#define GL_PACK_SKIP_PIXELS                                 0x0D04
#define GL_PACK_ALIGNMENT                                   0x0D05
#define GL_MAP_COLOR                                        0x0D10
#define GL_MAP_STENCIL                                      0x0D11
#define GL_INDEX_SHIFT                                      0x0D12
#define GL_INDEX_OFFSET                                     0x0D13
#define GL_RED_SCALE                                        0x0D14
#define GL_RED_BIAS                                         0x0D15
#define GL_ZOOM_X                                           0x0D16
#define GL_ZOOM_Y                                           0x0D17
#define GL_GREEN_SCALE                                      0x0D18
#define GL_GREEN_BIAS                                       0x0D19
#define GL_BLUE_SCALE                                       0x0D1A
#define GL_BLUE_BIAS                                        0x0D1B
#define GL_ALPHA_SCALE                                      0x0D1C
#define GL_ALPHA_BIAS                                       0x0D1D
#define GL_DEPTH_SCALE                                      0x0D1E
#define GL_DEPTH_BIAS                                       0x0D1F
#define GL_MAX_EVAL_ORDER                                   0x0D30
#define GL_MAX_LIGHTS                                       0x0D31
#define GL_MAX_CLIP_PLANES                                  0x0D32
#define GL_MAX_TEXTURE_SIZE                                 0x0D33
#define GL_MAX_PIXEL_MAP_TABLE                              0x0D34
#define GL_MAX_ATTRIB_STACK_DEPTH                           0x0D35
#define GL_MAX_MODELVIEW_STACK_DEPTH                        0x0D36
#define GL_MAX_NAME_STACK_DEPTH                             0x0D37
#define GL_MAX_PROJECTION_STACK_DEPTH                       0x0D38
#define GL_MAX_TEXTURE_STACK_DEPTH                          0x0D39
#define GL_MAX_VIEWPORT_DIMS                                0x0D3A
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH                    0x0D3B
#define GL_SUBPIXEL_BITS                                    0x0D50
#define GL_INDEX_BITS                                       0x0D51
#define GL_RED_BITS                                         0x0D52
#define GL_GREEN_BITS                                       0x0D53
#define GL_BLUE_BITS                                        0x0D54
#define GL_ALPHA_BITS                                       0x0D55
#define GL_DEPTH_BITS                                       0x0D56
#define GL_STENCIL_BITS                                     0x0D57
#define GL_ACCUM_RED_BITS                                   0x0D58
#define GL_ACCUM_GREEN_BITS                                 0x0D59
#define GL_ACCUM_BLUE_BITS                                  0x0D5A
#define GL_ACCUM_ALPHA_BITS                                 0x0D5B
#define GL_NAME_STACK_DEPTH                                 0x0D70
#define GL_AUTO_NORMAL                                      0x0D80
#define GL_MAP1_COLOR_4                                     0x0D90
#define GL_MAP1_INDEX                                       0x0D91
#define GL_MAP1_NORMAL                                      0x0D92
#define GL_MAP1_TEXTURE_COORD_1                             0x0D93
#define GL_MAP1_TEXTURE_COORD_2                             0x0D94
#define GL_MAP1_TEXTURE_COORD_3                             0x0D95
#define GL_MAP1_TEXTURE_COORD_4                             0x0D96
#define GL_MAP1_VERTEX_3                                    0x0D97
#define GL_MAP1_VERTEX_4                                    0x0D98
#define GL_MAP2_COLOR_4                                     0x0DB0
#define GL_MAP2_INDEX                                       0x0DB1
#define GL_MAP2_NORMAL                                      0x0DB2
#define GL_MAP2_TEXTURE_COORD_1                             0x0DB3
#define GL_MAP2_TEXTURE_COORD_2                             0x0DB4
#define GL_MAP2_TEXTURE_COORD_3                             0x0DB5
#define GL_MAP2_TEXTURE_COORD_4                             0x0DB6
#define GL_MAP2_VERTEX_3                                    0x0DB7
#define GL_MAP2_VERTEX_4                                    0x0DB8
#define GL_MAP1_GRID_DOMAIN                                 0x0DD0
#define GL_MAP1_GRID_SEGMENTS                               0x0DD1
#define GL_MAP2_GRID_DOMAIN                                 0x0DD2
#define GL_MAP2_GRID_SEGMENTS                               0x0DD3
#define GL_TEXTURE_1D                                       0x0DE0
#define GL_TEXTURE_2D                                       0x0DE1
#define GL_FEEDBACK_BUFFER_POINTER                          0x0DF0
#define GL_FEEDBACK_BUFFER_SIZE                             0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE                             0x0DF2
#define GL_SELECTION_BUFFER_POINTER                         0x0DF3
#define GL_SELECTION_BUFFER_SIZE                            0x0DF4
#define GL_POLYGON_OFFSET_UNITS                             0x2A00
#define GL_POLYGON_OFFSET_POINT                             0x2A01
#define GL_POLYGON_OFFSET_LINE                              0x2A02
#define GL_POLYGON_OFFSET_FILL                              0x8037
#define GL_POLYGON_OFFSET_FACTOR                            0x8038
#define GL_TEXTURE_BINDING_1D                               0x8068
#define GL_TEXTURE_BINDING_2D                               0x8069
#define GL_TEXTURE_BINDING_3D                               0x806A
#define GL_VERTEX_ARRAY                                     0x8074
#define GL_NORMAL_ARRAY                                     0x8075
#define GL_COLOR_ARRAY                                      0x8076
#define GL_INDEX_ARRAY                                      0x8077
#define GL_TEXTURE_COORD_ARRAY                              0x8078
#define GL_EDGE_FLAG_ARRAY                                  0x8079
#define GL_VERTEX_ARRAY_SIZE                                0x807A
#define GL_VERTEX_ARRAY_TYPE                                0x807B
#define GL_VERTEX_ARRAY_STRIDE                              0x807C
#define GL_NORMAL_ARRAY_TYPE                                0x807E
#define GL_NORMAL_ARRAY_STRIDE                              0x807F
#define GL_COLOR_ARRAY_SIZE                                 0x8081
#define GL_COLOR_ARRAY_TYPE                                 0x8082
#define GL_COLOR_ARRAY_STRIDE                               0x8083
#define GL_INDEX_ARRAY_TYPE                                 0x8085
#define GL_INDEX_ARRAY_STRIDE                               0x8086
#define GL_TEXTURE_COORD_ARRAY_SIZE                         0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE                         0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE                       0x808A
#define GL_EDGE_FLAG_ARRAY_STRIDE                           0x808C
/*      GL_VERTEX_ARRAY_COUNT_EXT */
/*      GL_NORMAL_ARRAY_COUNT_EXT */
/*      GL_COLOR_ARRAY_COUNT_EXT */
/*      GL_INDEX_ARRAY_COUNT_EXT */
/*      GL_TEXTURE_COORD_ARRAY_COUNT_EXT */
/*      GL_EDGE_FLAG_ARRAY_COUNT_EXT */

/* GetTextureParameter */
/*      GL_TEXTURE_MAG_FILTER */
/*      GL_TEXTURE_MIN_FILTER */
/*      GL_TEXTURE_WRAP_S */
/*      GL_TEXTURE_WRAP_T */
#define GL_TEXTURE_WIDTH                                    0x1000
#define GL_TEXTURE_HEIGHT                                   0x1001
#define GL_TEXTURE_INTERNAL_FORMAT                          0x1003
#define GL_TEXTURE_COMPONENTS                               GL_TEXTURE_INTERNAL_FORMAT
#define GL_TEXTURE_BORDER_COLOR                             0x1004
#define GL_TEXTURE_BORDER                                   0x1005
#define GL_TEXTURE_RED_SIZE                                 0x805C
#define GL_TEXTURE_GREEN_SIZE                               0x805D
#define GL_TEXTURE_BLUE_SIZE                                0x805E
#define GL_TEXTURE_ALPHA_SIZE                               0x805F
#define GL_TEXTURE_LUMINANCE_SIZE                           0x8060
#define GL_TEXTURE_INTENSITY_SIZE                           0x8061
#define GL_TEXTURE_PRIORITY                                 0x8066
#define GL_TEXTURE_RESIDENT                                 0x8067

/* HintMode */
#define GL_DONT_CARE                                        0x1100
#define GL_FASTEST                                          0x1101
#define GL_NICEST                                           0x1102

/* HintTarget */
/*      GL_PERSPECTIVE_CORRECTION_HINT */
/*      GL_POINT_SMOOTH_HINT */
/*      GL_LINE_SMOOTH_HINT */
/*      GL_POLYGON_SMOOTH_HINT */
/*      GL_FOG_HINT */

/* IndexMaterialParameterSGI */
/*      GL_INDEX_OFFSET */

/* IndexPointerType */
/*      GL_SHORT */
/*      GL_INT */
/*      GL_FLOAT */
/*      GL_DOUBLE */

/* IndexFunctionSGI */
/*      GL_NEVER */
/*      GL_LESS */
/*      GL_EQUAL */
/*      GL_LEQUAL */
/*      GL_GREATER */
/*      GL_NOTEQUAL */
/*      GL_GEQUAL */
/*      GL_ALWAYS */

/* LightModelParameter */
/*      GL_LIGHT_MODEL_AMBIENT */
/*      GL_LIGHT_MODEL_LOCAL_VIEWER */
/*      GL_LIGHT_MODEL_TWO_SIDE */

/* LightParameter */
#define GL_AMBIENT                                          0x1200
#define GL_DIFFUSE                                          0x1201
#define GL_SPECULAR                                         0x1202
#define GL_POSITION                                         0x1203
#define GL_SPOT_DIRECTION                                   0x1204
#define GL_SPOT_EXPONENT                                    0x1205
#define GL_SPOT_CUTOFF                                      0x1206
#define GL_CONSTANT_ATTENUATION                             0x1207
#define GL_LINEAR_ATTENUATION                               0x1208
#define GL_QUADRATIC_ATTENUATION                            0x1209

/* ListMode */
#define GL_COMPILE                                          0x1300
#define GL_COMPILE_AND_EXECUTE                              0x1301

/* DataType */
#define GL_BYTE                                             0x1400
#define GL_UNSIGNED_BYTE                                    0x1401
#define GL_SHORT                                            0x1402
#define GL_UNSIGNED_SHORT                                   0x1403
#define GL_INT                                              0x1404
#define GL_UNSIGNED_INT                                     0x1405
#define GL_FLOAT                                            0x1406
#define GL_2_BYTES                                          0x1407
#define GL_3_BYTES                                          0x1408
#define GL_4_BYTES                                          0x1409
#define GL_DOUBLE                                           0x140A
#define GL_DOUBLE_EXT                                       0x140A

/* ListNameType */
/*      GL_BYTE */
/*      GL_UNSIGNED_BYTE */
/*      GL_SHORT */
/*      GL_UNSIGNED_SHORT */
/*      GL_INT */
/*      GL_UNSIGNED_INT */
/*      GL_FLOAT */
/*      GL_2_BYTES */
/*      GL_3_BYTES */
/*      GL_4_BYTES */

/* LogicOp */
#define GL_CLEAR                                            0x1500
#define GL_AND                                              0x1501
#define GL_AND_REVERSE                                      0x1502
#define GL_COPY                                             0x1503
#define GL_AND_INVERTED                                     0x1504
#define GL_NOOP                                             0x1505
#define GL_XOR                                              0x1506
#define GL_OR                                               0x1507
#define GL_NOR                                              0x1508
#define GL_EQUIV                                            0x1509
#define GL_INVERT                                           0x150A
#define GL_OR_REVERSE                                       0x150B
#define GL_COPY_INVERTED                                    0x150C
#define GL_OR_INVERTED                                      0x150D
#define GL_NAND                                             0x150E
#define GL_SET                                              0x150F

/* MapTarget */
/*      GL_MAP1_COLOR_4 */
/*      GL_MAP1_INDEX */
/*      GL_MAP1_NORMAL */
/*      GL_MAP1_TEXTURE_COORD_1 */
/*      GL_MAP1_TEXTURE_COORD_2 */
/*      GL_MAP1_TEXTURE_COORD_3 */
/*      GL_MAP1_TEXTURE_COORD_4 */
/*      GL_MAP1_VERTEX_3 */
/*      GL_MAP1_VERTEX_4 */
/*      GL_MAP2_COLOR_4 */
/*      GL_MAP2_INDEX */
/*      GL_MAP2_NORMAL */
/*      GL_MAP2_TEXTURE_COORD_1 */
/*      GL_MAP2_TEXTURE_COORD_2 */
/*      GL_MAP2_TEXTURE_COORD_3 */
/*      GL_MAP2_TEXTURE_COORD_4 */
/*      GL_MAP2_VERTEX_3 */
/*      GL_MAP2_VERTEX_4 */

/* MaterialFace */
/*      GL_FRONT */
/*      GL_BACK */
/*      GL_FRONT_AND_BACK */

/* MaterialParameter */
#define GL_EMISSION                                         0x1600
#define GL_SHININESS                                        0x1601
#define GL_AMBIENT_AND_DIFFUSE                              0x1602
#define GL_COLOR_INDEXES                                    0x1603
/*      GL_AMBIENT */
/*      GL_DIFFUSE */
/*      GL_SPECULAR */

/* MatrixMode */
#define GL_MODELVIEW                                        0x1700
#define GL_PROJECTION                                       0x1701
#define GL_TEXTURE                                          0x1702

/* MeshMode1 */
/*      GL_POINT */
/*      GL_LINE */

/* MeshMode2 */
/*      GL_POINT */
/*      GL_LINE */
/*      GL_FILL */

/* NormalPointerType */
/*      GL_BYTE */
/*      GL_SHORT */
/*      GL_INT */
/*      GL_FLOAT */
/*      GL_DOUBLE */

/* PixelCopyType */
#define GL_COLOR                                            0x1800
#define GL_DEPTH                                            0x1801
#define GL_STENCIL                                          0x1802

/* PixelFormat */
#define GL_COLOR_INDEX                                      0x1900
#define GL_STENCIL_INDEX                                    0x1901
#define GL_DEPTH_COMPONENT                                  0x1902
#define GL_RED                                              0x1903
#define GL_GREEN                                            0x1904
#define GL_BLUE                                             0x1905
#define GL_ALPHA                                            0x1906
#define GL_RGB                                              0x1907
#define GL_RGBA                                             0x1908
#define GL_LUMINANCE                                        0x1909
#define GL_LUMINANCE_ALPHA                                  0x190A

/* PixelMap */
/*      GL_PIXEL_MAP_I_TO_I */
/*      GL_PIXEL_MAP_S_TO_S */
/*      GL_PIXEL_MAP_I_TO_R */
/*      GL_PIXEL_MAP_I_TO_G */
/*      GL_PIXEL_MAP_I_TO_B */
/*      GL_PIXEL_MAP_I_TO_A */
/*      GL_PIXEL_MAP_R_TO_R */
/*      GL_PIXEL_MAP_G_TO_G */
/*      GL_PIXEL_MAP_B_TO_B */
/*      GL_PIXEL_MAP_A_TO_A */

/* PixelStoreParameter */
/*      GL_UNPACK_SWAP_BYTES */
/*      GL_UNPACK_LSB_FIRST */
/*      GL_UNPACK_ROW_LENGTH */
/*      GL_UNPACK_SKIP_ROWS */
/*      GL_UNPACK_SKIP_PIXELS */
/*      GL_UNPACK_ALIGNMENT */
/*      GL_PACK_SWAP_BYTES */
/*      GL_PACK_LSB_FIRST */
/*      GL_PACK_ROW_LENGTH */
/*      GL_PACK_SKIP_ROWS */
/*      GL_PACK_SKIP_PIXELS */
/*      GL_PACK_ALIGNMENT */

/* PixelTransferParameter */
/*      GL_MAP_COLOR */
/*      GL_MAP_STENCIL */
/*      GL_INDEX_SHIFT */
/*      GL_INDEX_OFFSET */
/*      GL_RED_SCALE */
/*      GL_RED_BIAS */
/*      GL_GREEN_SCALE */
/*      GL_GREEN_BIAS */
/*      GL_BLUE_SCALE */
/*      GL_BLUE_BIAS */
/*      GL_ALPHA_SCALE */
/*      GL_ALPHA_BIAS */
/*      GL_DEPTH_SCALE */
/*      GL_DEPTH_BIAS */

/* PixelType */
#define GL_BITMAP                                           0x1A00
/*      GL_BYTE */
/*      GL_UNSIGNED_BYTE */
/*      GL_SHORT */
/*      GL_UNSIGNED_SHORT */
/*      GL_INT */
/*      GL_UNSIGNED_INT */
/*      GL_FLOAT */

/* PolygonMode */
#define GL_POINT                                            0x1B00
#define GL_LINE                                             0x1B01
#define GL_FILL                                             0x1B02

/* ReadBufferMode */
/*      GL_FRONT_LEFT */
/*      GL_FRONT_RIGHT */
/*      GL_BACK_LEFT */
/*      GL_BACK_RIGHT */
/*      GL_FRONT */
/*      GL_BACK */
/*      GL_LEFT */
/*      GL_RIGHT */
/*      GL_AUX0 */
/*      GL_AUX1 */
/*      GL_AUX2 */
/*      GL_AUX3 */
/*      GL_AUX4 */
/*      GL_AUX5 */
/*      GL_AUX6 */
/*      GL_AUX7 */

/* RenderingMode */
#define GL_RENDER                                           0x1C00
#define GL_FEEDBACK                                         0x1C01
#define GL_SELECT                                           0x1C02

/* ShadingModel */
#define GL_FLAT                                             0x1D00
#define GL_SMOOTH                                           0x1D01

/* StencilFunction */
/*      GL_NEVER */
/*      GL_LESS */
/*      GL_EQUAL */
/*      GL_LEQUAL */
/*      GL_GREATER */
/*      GL_NOTEQUAL */
/*      GL_GEQUAL */
/*      GL_ALWAYS */

/* StencilOp */
/*      GL_ZERO */
#define GL_KEEP                                             0x1E00
#define GL_REPLACE                                          0x1E01
#define GL_INCR                                             0x1E02
#define GL_DECR                                             0x1E03
/*      GL_INVERT */

/* StringName */
#define GL_VENDOR                                           0x1F00
#define GL_RENDERER                                         0x1F01
#define GL_VERSION                                          0x1F02
#define GL_EXTENSIONS                                       0x1F03

/* TexCoordPointerType */
/*      GL_SHORT */
/*      GL_INT */
/*      GL_FLOAT */
/*      GL_DOUBLE */

/* TextureCoordName */
#define GL_S                                                0x2000
#define GL_T                                                0x2001
#define GL_R                                                0x2002
#define GL_Q                                                0x2003

/* TextureEnvMode */
#define GL_MODULATE                                         0x2100
#define GL_DECAL                                            0x2101
/*      GL_BLEND */
/*      GL_REPLACE */
/*      GL_ADD */

/* TextureEnvParameter */
#define GL_TEXTURE_ENV_MODE                                 0x2200
#define GL_TEXTURE_ENV_COLOR                                0x2201

/* TextureEnvTarget */
#define GL_TEXTURE_ENV                                      0x2300

/* TextureGenMode */
#define GL_EYE_LINEAR                                       0x2400
#define GL_OBJECT_LINEAR                                    0x2401
#define GL_SPHERE_MAP                                       0x2402

/* TextureGenParameter */
#define GL_TEXTURE_GEN_MODE                                 0x2500
#define GL_OBJECT_PLANE                                     0x2501
#define GL_EYE_PLANE                                        0x2502

/* TextureMagFilter */
#define GL_NEAREST                                          0x2600
#define GL_LINEAR                                           0x2601

/* TextureMinFilter */
/*      GL_NEAREST */
/*      GL_LINEAR */
#define GL_NEAREST_MIPMAP_NEAREST                           0x2700
#define GL_LINEAR_MIPMAP_NEAREST                            0x2701
#define GL_NEAREST_MIPMAP_LINEAR                            0x2702
#define GL_LINEAR_MIPMAP_LINEAR                             0x2703

/* TextureParameterName */
#define GL_TEXTURE_MAG_FILTER                               0x2800
#define GL_TEXTURE_MIN_FILTER                               0x2801
#define GL_TEXTURE_WRAP_S                                   0x2802
#define GL_TEXTURE_WRAP_T                                   0x2803
/*      GL_TEXTURE_BORDER_COLOR */
/*      GL_TEXTURE_PRIORITY */

/* TextureTarget */
/*      GL_TEXTURE_1D */
/*      GL_TEXTURE_2D */
#define GL_PROXY_TEXTURE_1D                                 0x8063
#define GL_PROXY_TEXTURE_2D                                 0x8064

/* TextureWrapMode */
#define GL_CLAMP                                            0x2900
#define GL_REPEAT                                           0x2901

/* PixelInternalFormat */
#define GL_R3_G3_B2                                         0x2A10
#define GL_ALPHA4                                           0x803B
#define GL_ALPHA8                                           0x803C
#define GL_ALPHA12                                          0x803D
#define GL_ALPHA16                                          0x803E
#define GL_LUMINANCE4                                       0x803F
#define GL_LUMINANCE8                                       0x8040
#define GL_LUMINANCE12                                      0x8041
#define GL_LUMINANCE16                                      0x8042
#define GL_LUMINANCE4_ALPHA4                                0x8043
#define GL_LUMINANCE6_ALPHA2                                0x8044
#define GL_LUMINANCE8_ALPHA8                                0x8045
#define GL_LUMINANCE12_ALPHA4                               0x8046
#define GL_LUMINANCE12_ALPHA12                              0x8047
#define GL_LUMINANCE16_ALPHA16                              0x8048
#define GL_INTENSITY                                        0x8049
#define GL_INTENSITY4                                       0x804A
#define GL_INTENSITY8                                       0x804B
#define GL_INTENSITY12                                      0x804C
#define GL_INTENSITY16                                      0x804D
#define GL_RGB4                                             0x804F
#define GL_RGB5                                             0x8050
#define GL_RGB8                                             0x8051
#define GL_RGB10                                            0x8052
#define GL_RGB12                                            0x8053
#define GL_RGB16                                            0x8054
#define GL_RGBA2                                            0x8055
#define GL_RGBA4                                            0x8056
#define GL_RGB5_A1                                          0x8057
#define GL_RGBA8                                            0x8058
#define GL_RGB10_A2                                         0x8059
#define GL_RGBA12                                           0x805A
#define GL_RGBA16                                           0x805B

/* InterleavedArrayFormat */
#define GL_V2F                                              0x2A20
#define GL_V3F                                              0x2A21
#define GL_C4UB_V2F                                         0x2A22
#define GL_C4UB_V3F                                         0x2A23
#define GL_C3F_V3F                                          0x2A24
#define GL_N3F_V3F                                          0x2A25
#define GL_C4F_N3F_V3F                                      0x2A26
#define GL_T2F_V3F                                          0x2A27
#define GL_T4F_V4F                                          0x2A28
#define GL_T2F_C4UB_V3F                                     0x2A29
#define GL_T2F_C3F_V3F                                      0x2A2A
#define GL_T2F_N3F_V3F                                      0x2A2B
#define GL_T2F_C4F_N3F_V3F                                  0x2A2C
#define GL_T4F_C4F_N3F_V4F                                  0x2A2D

/* VertexPointerType */
/*      GL_SHORT */
/*      GL_INT */
/*      GL_FLOAT */
/*      GL_DOUBLE */

/* ClipPlaneName */
#define GL_CLIP_PLANE0                                      0x3000
#define GL_CLIP_PLANE1                                      0x3001
#define GL_CLIP_PLANE2                                      0x3002
#define GL_CLIP_PLANE3                                      0x3003
#define GL_CLIP_PLANE4                                      0x3004
#define GL_CLIP_PLANE5                                      0x3005

/* LightName */
#define GL_LIGHT0                                           0x4000
#define GL_LIGHT1                                           0x4001
#define GL_LIGHT2                                           0x4002
#define GL_LIGHT3                                           0x4003
#define GL_LIGHT4                                           0x4004
#define GL_LIGHT5                                           0x4005
#define GL_LIGHT6                                           0x4006
#define GL_LIGHT7                                           0x4007

/* OpenGL12 */
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
#define GL_CONSTANT_COLOR                                   0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR                         0x8002
#define GL_CONSTANT_ALPHA                                   0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA                         0x8004
#define GL_BLEND_COLOR                                      0x8005
#define GL_BLEND_EQUATION                                   0x8009
#define GL_FUNC_ADD                                         0x8006
#define GL_MIN                                              0x8007
#define GL_MAX                                              0x8008
#define GL_FUNC_SUBTRACT                                    0x800A
#define GL_FUNC_REVERSE_SUBTRACT                            0x800B
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
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING               0x889F
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
#define GL_BLEND_EQUATION_RGB                               0x8009
#define GL_BLEND_EQUATION_ALPHA                             0x883D

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
#define GL_BUFFER_ACCESS_FLAGS                              0x911F
#define GL_BUFFER_MAP_LENGTH                                0x9120
#define GL_BUFFER_MAP_OFFSET                                0x9121
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
#define GL_CLAMP_VERTEX_COLOR                               0x891A
#define GL_CLAMP_FRAGMENT_COLOR                             0x891B
#define GL_CLAMP_READ_COLOR                                 0x891C
#define GL_FIXED_ONLY                                       0x891D

/* OpenGL31 */
#define GL_TEXTURE_BUFFER                                   0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE                          0x8C2B
#define GL_TEXTURE_BINDING_BUFFER                           0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING                0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT                            0x8C2E
#define GL_COPY_READ_BUFFER                                 0x8F36
#define GL_COPY_WRITE_BUFFER                                0x8F37
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
#define GL_TEXTURE_RECTANGLE                                0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE                        0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE                          0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE                       0x84F8
#define GL_SAMPLER_2D_RECT                                  0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW                           0x8B64
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
#define GL_INVALID_INDEX                                    0xFFFFFFFF
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

/* OpenGL32 */
#define GL_TEXTURE_CUBE_MAP_SEAMLESS                        0x884F
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS                     0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS                    0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS                   0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS                    0x9125
#define GL_GEOMETRY_VERTICES_OUT                            0x8916
#define GL_GEOMETRY_INPUT_TYPE                              0x8917
#define GL_GEOMETRY_OUTPUT_TYPE                             0x8918
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
#define GL_DEPTH_CLAMP                                      0x864F
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
#define GL_CONTEXT_PROFILE_MASK                             0x9126
#define GL_CONTEXT_CORE_PROFILE_BIT                         0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT                0x00000002
#define GL_GEOMETRY_SHADER                                  0x8DD9
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS                 0x8C29
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS                  0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES                     0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS             0x8DE1
#define GL_LINES_ADJACENCY                                  0xA
#define GL_LINE_STRIP_ADJACENCY                             0xB
#define GL_TRIANGLES_ADJACENCY                              0xC
#define GL_TRIANGLE_STRIP_ADJACENCY                         0xD
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS             0x8DA8
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED                   0x8DA7
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER             0x8CD4
#define GL_PROGRAM_POINT_SIZE                               0x8642

/* OpenGL33 */
#define GL_RGB10_A2UI                                       0x906F
#define GL_TEXTURE_SWIZZLE_R                                0x8E42
#define GL_TEXTURE_SWIZZLE_G                                0x8E43
#define GL_TEXTURE_SWIZZLE_B                                0x8E44
#define GL_TEXTURE_SWIZZLE_A                                0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA                             0x8E46
#define GL_SAMPLER_BINDING                                  0x8919
#define GL_ANY_SAMPLES_PASSED                               0x8C2F
#define GL_SRC1_COLOR                                       0x88F9
#define GL_ONE_MINUS_SRC1_COLOR                             0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA                             0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS                     0x88FC
#define GL_TIME_ELAPSED                                     0x88BF
#define GL_TIMESTAMP                                        0x8E28
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR                      0x88FE
#define GL_INT_2_10_10_10_REV                               0x8D9F

/* OpenGL40 */
#define GL_DRAW_INDIRECT_BUFFER                             0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING                     0x8F43
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

/* OpenGL41 */
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

/* OpenGL42 */
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

/* OpenGL43 */
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
#define GL_TEXTURE_VIEW_MIN_LEVEL                           0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS                          0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER                           0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS                          0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS                         0x82DF
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

/* OpenGL44 */
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

/* OpenGL45 */
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
#define GL_TRANSFORM_FEEDBACK_PAUSED                        0x8E23
#define GL_TRANSFORM_FEEDBACK_ACTIVE                        0x8E24
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

/* OpenGL46 */
#define GL_PARAMETER_BUFFER                                 0x80EE
#define GL_PARAMETER_BUFFER_BINDING                         0x80EF

/*************************************************************/

#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glNewList(GLuint list, GLenum mode);
GLAPI void GLAPIENTRY glEndList();
GLAPI void GLAPIENTRY glCallList(GLuint list);
GLAPI void GLAPIENTRY glCallLists(GLsizei n, GLenum type, const GLvoid* lists);
GLAPI void GLAPIENTRY glDeleteLists(GLuint list, GLsizei range);
GLAPI GLuint GLAPIENTRY glGenLists(GLsizei range);
GLAPI void GLAPIENTRY glListBase(GLuint base);
GLAPI void GLAPIENTRY glBegin(GLenum mode);
GLAPI void GLAPIENTRY glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte* bitmap);
GLAPI void GLAPIENTRY glColor3b(GLbyte red, GLbyte green, GLbyte blue);
GLAPI void GLAPIENTRY glColor3bv(const GLbyte* v);
GLAPI void GLAPIENTRY glColor3d(GLdouble red, GLdouble green, GLdouble blue);
GLAPI void GLAPIENTRY glColor3dv(const GLdouble* v);
GLAPI void GLAPIENTRY glColor3f(GLfloat red, GLfloat green, GLfloat blue);
GLAPI void GLAPIENTRY glColor3fv(const GLfloat* v);
GLAPI void GLAPIENTRY glColor3i(GLint red, GLint green, GLint blue);
GLAPI void GLAPIENTRY glColor3iv(const GLint* v);
GLAPI void GLAPIENTRY glColor3s(GLshort red, GLshort green, GLshort blue);
GLAPI void GLAPIENTRY glColor3sv(const GLshort* v);
GLAPI void GLAPIENTRY glColor3ub(GLubyte red, GLubyte green, GLubyte blue);
GLAPI void GLAPIENTRY glColor3ubv(const GLubyte* v);
GLAPI void GLAPIENTRY glColor3ui(GLuint red, GLuint green, GLuint blue);
GLAPI void GLAPIENTRY glColor3uiv(const GLuint* v);
GLAPI void GLAPIENTRY glColor3us(GLushort red, GLushort green, GLushort blue);
GLAPI void GLAPIENTRY glColor3usv(const GLushort* v);
GLAPI void GLAPIENTRY glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
GLAPI void GLAPIENTRY glColor4bv(const GLbyte* v);
GLAPI void GLAPIENTRY glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
GLAPI void GLAPIENTRY glColor4dv(const GLdouble* v);
GLAPI void GLAPIENTRY glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI void GLAPIENTRY glColor4fv(const GLfloat* v);
GLAPI void GLAPIENTRY glColor4i(GLint red, GLint green, GLint blue, GLint alpha);
GLAPI void GLAPIENTRY glColor4iv(const GLint* v);
GLAPI void GLAPIENTRY glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha);
GLAPI void GLAPIENTRY glColor4sv(const GLshort* v);
GLAPI void GLAPIENTRY glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
GLAPI void GLAPIENTRY glColor4ubv(const GLubyte* v);
GLAPI void GLAPIENTRY glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha);
GLAPI void GLAPIENTRY glColor4uiv(const GLuint* v);
GLAPI void GLAPIENTRY glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha);
GLAPI void GLAPIENTRY glColor4usv(const GLushort* v);
GLAPI void GLAPIENTRY glEdgeFlag(GLboolean flag);
GLAPI void GLAPIENTRY glEdgeFlagv(const GLboolean* flag);
GLAPI void GLAPIENTRY glEnd();
GLAPI void GLAPIENTRY glIndexd(GLdouble c);
GLAPI void GLAPIENTRY glIndexdv(const GLdouble* c);
GLAPI void GLAPIENTRY glIndexf(GLfloat c);
GLAPI void GLAPIENTRY glIndexfv(const GLfloat* c);
GLAPI void GLAPIENTRY glIndexi(GLint c);
GLAPI void GLAPIENTRY glIndexiv(const GLint* c);
GLAPI void GLAPIENTRY glIndexs(GLshort c);
GLAPI void GLAPIENTRY glIndexsv(const GLshort* c);
GLAPI void GLAPIENTRY glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz);
GLAPI void GLAPIENTRY glNormal3bv(const GLbyte* v);
GLAPI void GLAPIENTRY glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz);
GLAPI void GLAPIENTRY glNormal3dv(const GLdouble* v);
GLAPI void GLAPIENTRY glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);
GLAPI void GLAPIENTRY glNormal3fv(const GLfloat* v);
GLAPI void GLAPIENTRY glNormal3i(GLint nx, GLint ny, GLint nz);
GLAPI void GLAPIENTRY glNormal3iv(const GLint* v);
GLAPI void GLAPIENTRY glNormal3s(GLshort nx, GLshort ny, GLshort nz);
GLAPI void GLAPIENTRY glNormal3sv(const GLshort* v);
GLAPI void GLAPIENTRY glRasterPos2d(GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glRasterPos2dv(const GLdouble* v);
GLAPI void GLAPIENTRY glRasterPos2f(GLfloat x, GLfloat y);
GLAPI void GLAPIENTRY glRasterPos2fv(const GLfloat* v);
GLAPI void GLAPIENTRY glRasterPos2i(GLint x, GLint y);
GLAPI void GLAPIENTRY glRasterPos2iv(const GLint* v);
GLAPI void GLAPIENTRY glRasterPos2s(GLshort x, GLshort y);
GLAPI void GLAPIENTRY glRasterPos2sv(const GLshort* v);
GLAPI void GLAPIENTRY glRasterPos3d(GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glRasterPos3dv(const GLdouble* v);
GLAPI void GLAPIENTRY glRasterPos3f(GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glRasterPos3fv(const GLfloat* v);
GLAPI void GLAPIENTRY glRasterPos3i(GLint x, GLint y, GLint z);
GLAPI void GLAPIENTRY glRasterPos3iv(const GLint* v);
GLAPI void GLAPIENTRY glRasterPos3s(GLshort x, GLshort y, GLshort z);
GLAPI void GLAPIENTRY glRasterPos3sv(const GLshort* v);
GLAPI void GLAPIENTRY glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glRasterPos4dv(const GLdouble* v);
GLAPI void GLAPIENTRY glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glRasterPos4fv(const GLfloat* v);
GLAPI void GLAPIENTRY glRasterPos4i(GLint x, GLint y, GLint z, GLint w);
GLAPI void GLAPIENTRY glRasterPos4iv(const GLint* v);
GLAPI void GLAPIENTRY glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI void GLAPIENTRY glRasterPos4sv(const GLshort* v);
GLAPI void GLAPIENTRY glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
GLAPI void GLAPIENTRY glRectdv(const GLdouble* v1, const GLdouble* v2);
GLAPI void GLAPIENTRY glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
GLAPI void GLAPIENTRY glRectfv(const GLfloat* v1, const GLfloat* v2);
GLAPI void GLAPIENTRY glRecti(GLint x1, GLint y1, GLint x2, GLint y2);
GLAPI void GLAPIENTRY glRectiv(const GLint* v1, const GLint* v2);
GLAPI void GLAPIENTRY glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
GLAPI void GLAPIENTRY glRectsv(const GLshort* v1, const GLshort* v2);
GLAPI void GLAPIENTRY glTexCoord1d(GLdouble s);
GLAPI void GLAPIENTRY glTexCoord1dv(const GLdouble* v);
GLAPI void GLAPIENTRY glTexCoord1f(GLfloat s);
GLAPI void GLAPIENTRY glTexCoord1fv(const GLfloat* v);
GLAPI void GLAPIENTRY glTexCoord1i(GLint s);
GLAPI void GLAPIENTRY glTexCoord1iv(const GLint* v);
GLAPI void GLAPIENTRY glTexCoord1s(GLshort s);
GLAPI void GLAPIENTRY glTexCoord1sv(const GLshort* v);
GLAPI void GLAPIENTRY glTexCoord2d(GLdouble s, GLdouble t);
GLAPI void GLAPIENTRY glTexCoord2dv(const GLdouble* v);
GLAPI void GLAPIENTRY glTexCoord2f(GLfloat s, GLfloat t);
GLAPI void GLAPIENTRY glTexCoord2fv(const GLfloat* v);
GLAPI void GLAPIENTRY glTexCoord2i(GLint s, GLint t);
GLAPI void GLAPIENTRY glTexCoord2iv(const GLint* v);
GLAPI void GLAPIENTRY glTexCoord2s(GLshort s, GLshort t);
GLAPI void GLAPIENTRY glTexCoord2sv(const GLshort* v);
GLAPI void GLAPIENTRY glTexCoord3d(GLdouble s, GLdouble t, GLdouble r);
GLAPI void GLAPIENTRY glTexCoord3dv(const GLdouble* v);
GLAPI void GLAPIENTRY glTexCoord3f(GLfloat s, GLfloat t, GLfloat r);
GLAPI void GLAPIENTRY glTexCoord3fv(const GLfloat* v);
GLAPI void GLAPIENTRY glTexCoord3i(GLint s, GLint t, GLint r);
GLAPI void GLAPIENTRY glTexCoord3iv(const GLint* v);
GLAPI void GLAPIENTRY glTexCoord3s(GLshort s, GLshort t, GLshort r);
GLAPI void GLAPIENTRY glTexCoord3sv(const GLshort* v);
GLAPI void GLAPIENTRY glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
GLAPI void GLAPIENTRY glTexCoord4dv(const GLdouble* v);
GLAPI void GLAPIENTRY glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GLAPI void GLAPIENTRY glTexCoord4fv(const GLfloat* v);
GLAPI void GLAPIENTRY glTexCoord4i(GLint s, GLint t, GLint r, GLint q);
GLAPI void GLAPIENTRY glTexCoord4iv(const GLint* v);
GLAPI void GLAPIENTRY glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q);
GLAPI void GLAPIENTRY glTexCoord4sv(const GLshort* v);
GLAPI void GLAPIENTRY glVertex2d(GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glVertex2dv(const GLdouble* v);
GLAPI void GLAPIENTRY glVertex2f(GLfloat x, GLfloat y);
GLAPI void GLAPIENTRY glVertex2fv(const GLfloat* v);
GLAPI void GLAPIENTRY glVertex2i(GLint x, GLint y);
GLAPI void GLAPIENTRY glVertex2iv(const GLint* v);
GLAPI void GLAPIENTRY glVertex2s(GLshort x, GLshort y);
GLAPI void GLAPIENTRY glVertex2sv(const GLshort* v);
GLAPI void GLAPIENTRY glVertex3d(GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glVertex3dv(const GLdouble* v);
GLAPI void GLAPIENTRY glVertex3f(GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glVertex3fv(const GLfloat* v);
GLAPI void GLAPIENTRY glVertex3i(GLint x, GLint y, GLint z);
GLAPI void GLAPIENTRY glVertex3iv(const GLint* v);
GLAPI void GLAPIENTRY glVertex3s(GLshort x, GLshort y, GLshort z);
GLAPI void GLAPIENTRY glVertex3sv(const GLshort* v);
GLAPI void GLAPIENTRY glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glVertex4dv(const GLdouble* v);
GLAPI void GLAPIENTRY glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glVertex4fv(const GLfloat* v);
GLAPI void GLAPIENTRY glVertex4i(GLint x, GLint y, GLint z, GLint w);
GLAPI void GLAPIENTRY glVertex4iv(const GLint* v);
GLAPI void GLAPIENTRY glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI void GLAPIENTRY glVertex4sv(const GLshort* v);
GLAPI void GLAPIENTRY glClipPlane(GLenum plane, const GLdouble* equation);
GLAPI void GLAPIENTRY glColorMaterial(GLenum face, GLenum mode);
GLAPI void GLAPIENTRY glCullFace(GLenum mode);
GLAPI void GLAPIENTRY glFogf(GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glFogfv(GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glFogi(GLenum pname, GLint param);
GLAPI void GLAPIENTRY glFogiv(GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glFrontFace(GLenum mode);
GLAPI void GLAPIENTRY glHint(GLenum target, GLenum mode);
GLAPI void GLAPIENTRY glLightf(GLenum light, GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glLightfv(GLenum light, GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glLighti(GLenum light, GLenum pname, GLint param);
GLAPI void GLAPIENTRY glLightiv(GLenum light, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glLightModelf(GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glLightModelfv(GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glLightModeli(GLenum pname, GLint param);
GLAPI void GLAPIENTRY glLightModeliv(GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glLineStipple(GLint factor, GLushort pattern);
GLAPI void GLAPIENTRY glLineWidth(GLfloat width);
GLAPI void GLAPIENTRY glMaterialf(GLenum face, GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glMaterialfv(GLenum face, GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glMateriali(GLenum face, GLenum pname, GLint param);
GLAPI void GLAPIENTRY glMaterialiv(GLenum face, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glPointSize(GLfloat size);
GLAPI void GLAPIENTRY glPolygonMode(GLenum face, GLenum mode);
GLAPI void GLAPIENTRY glPolygonStipple(const GLubyte* mask);
GLAPI void GLAPIENTRY glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glShadeModel(GLenum mode);
GLAPI void GLAPIENTRY glTexParameterf(GLenum target, GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glTexParameterfv(GLenum target, GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glTexParameteri(GLenum target, GLenum pname, GLint param);
GLAPI void GLAPIENTRY glTexParameteriv(GLenum target, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glTexEnvf(GLenum target, GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glTexEnvfv(GLenum target, GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glTexEnvi(GLenum target, GLenum pname, GLint param);
GLAPI void GLAPIENTRY glTexEnviv(GLenum target, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glTexGend(GLenum coord, GLenum pname, GLdouble param);
GLAPI void GLAPIENTRY glTexGendv(GLenum coord, GLenum pname, const GLdouble* params);
GLAPI void GLAPIENTRY glTexGenf(GLenum coord, GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glTexGenfv(GLenum coord, GLenum pname, const GLfloat* params);
GLAPI void GLAPIENTRY glTexGeni(GLenum coord, GLenum pname, GLint param);
GLAPI void GLAPIENTRY glTexGeniv(GLenum coord, GLenum pname, const GLint* params);
GLAPI void GLAPIENTRY glFeedbackBuffer(GLsizei size, GLenum type, GLfloat* buffer);
GLAPI void GLAPIENTRY glSelectBuffer(GLsizei size, GLuint* buffer);
GLAPI GLint GLAPIENTRY glRenderMode(GLenum mode);
GLAPI void GLAPIENTRY glInitNames();
GLAPI void GLAPIENTRY glLoadName(GLuint name);
GLAPI void GLAPIENTRY glPassThrough(GLfloat token);
GLAPI void GLAPIENTRY glPopName();
GLAPI void GLAPIENTRY glPushName(GLuint name);
GLAPI void GLAPIENTRY glDrawBuffer(GLenum mode);
GLAPI void GLAPIENTRY glClear(GLbitfield mask);
GLAPI void GLAPIENTRY glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI void GLAPIENTRY glClearIndex(GLfloat c);
GLAPI void GLAPIENTRY glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
GLAPI void GLAPIENTRY glClearStencil(GLint s);
GLAPI void GLAPIENTRY glClearDepth(GLclampd depth);
GLAPI void GLAPIENTRY glStencilMask(GLuint mask);
GLAPI void GLAPIENTRY glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLAPI void GLAPIENTRY glDepthMask(GLboolean flag);
GLAPI void GLAPIENTRY glIndexMask(GLuint mask);
GLAPI void GLAPIENTRY glAccum(GLenum op, GLfloat value);
GLAPI void GLAPIENTRY glDisable(GLenum cap);
GLAPI void GLAPIENTRY glEnable(GLenum cap);
GLAPI void GLAPIENTRY glFinish();
GLAPI void GLAPIENTRY glFlush();
GLAPI void GLAPIENTRY glPopAttrib();
GLAPI void GLAPIENTRY glPushAttrib(GLbitfield mask);
GLAPI void GLAPIENTRY glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble* points);
GLAPI void GLAPIENTRY glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat* points);
GLAPI void GLAPIENTRY glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble* points);
GLAPI void GLAPIENTRY glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat* points);
GLAPI void GLAPIENTRY glMapGrid1d(GLint un, GLdouble u1, GLdouble u2);
GLAPI void GLAPIENTRY glMapGrid1f(GLint un, GLfloat u1, GLfloat u2);
GLAPI void GLAPIENTRY glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
GLAPI void GLAPIENTRY glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
GLAPI void GLAPIENTRY glEvalCoord1d(GLdouble u);
GLAPI void GLAPIENTRY glEvalCoord1dv(const GLdouble* u);
GLAPI void GLAPIENTRY glEvalCoord1f(GLfloat u);
GLAPI void GLAPIENTRY glEvalCoord1fv(const GLfloat* u);
GLAPI void GLAPIENTRY glEvalCoord2d(GLdouble u, GLdouble v);
GLAPI void GLAPIENTRY glEvalCoord2dv(const GLdouble* u);
GLAPI void GLAPIENTRY glEvalCoord2f(GLfloat u, GLfloat v);
GLAPI void GLAPIENTRY glEvalCoord2fv(const GLfloat* u);
GLAPI void GLAPIENTRY glEvalMesh1(GLenum mode, GLint i1, GLint i2);
GLAPI void GLAPIENTRY glEvalPoint1(GLint i);
GLAPI void GLAPIENTRY glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
GLAPI void GLAPIENTRY glEvalPoint2(GLint i, GLint j);
GLAPI void GLAPIENTRY glAlphaFunc(GLenum func, GLclampf ref);
GLAPI void GLAPIENTRY glBlendFunc(GLenum sfactor, GLenum dfactor);
GLAPI void GLAPIENTRY glLogicOp(GLenum opcode);
GLAPI void GLAPIENTRY glStencilFunc(GLenum func, GLint ref, GLuint mask);
GLAPI void GLAPIENTRY glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
GLAPI void GLAPIENTRY glDepthFunc(GLenum func);
GLAPI void GLAPIENTRY glPixelZoom(GLfloat xfactor, GLfloat yfactor);
GLAPI void GLAPIENTRY glPixelTransferf(GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glPixelTransferi(GLenum pname, GLint param);
GLAPI void GLAPIENTRY glPixelStoref(GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glPixelStorei(GLenum pname, GLint param);
GLAPI void GLAPIENTRY glPixelMapfv(GLenum map, GLint mapsize, const GLfloat* values);
GLAPI void GLAPIENTRY glPixelMapuiv(GLenum map, GLint mapsize, const GLuint* values);
GLAPI void GLAPIENTRY glPixelMapusv(GLenum map, GLint mapsize, const GLushort* values);
GLAPI void GLAPIENTRY glReadBuffer(GLenum mode);
GLAPI void GLAPIENTRY glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
GLAPI void GLAPIENTRY glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
GLAPI void GLAPIENTRY glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glGetBooleanv(GLenum pname, GLboolean* params);
GLAPI void GLAPIENTRY glGetClipPlane(GLenum plane, GLdouble* equation);
GLAPI void GLAPIENTRY glGetDoublev(GLenum pname, GLdouble* params);
GLAPI GLenum GLAPIENTRY glGetError();
GLAPI void GLAPIENTRY glGetFloatv(GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetIntegerv(GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetLightfv(GLenum light, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetLightiv(GLenum light, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetMapdv(GLenum target, GLenum query, GLdouble* v);
GLAPI void GLAPIENTRY glGetMapfv(GLenum target, GLenum query, GLfloat* v);
GLAPI void GLAPIENTRY glGetMapiv(GLenum target, GLenum query, GLint* v);
GLAPI void GLAPIENTRY glGetMaterialfv(GLenum face, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetMaterialiv(GLenum face, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetPixelMapfv(GLenum map, GLfloat* values);
GLAPI void GLAPIENTRY glGetPixelMapuiv(GLenum map, GLuint* values);
GLAPI void GLAPIENTRY glGetPixelMapusv(GLenum map, GLushort* values);
GLAPI void GLAPIENTRY glGetPolygonStipple(GLubyte* mask);
GLAPI const GLubyte* GLAPIENTRY glGetString(GLenum name);
GLAPI void GLAPIENTRY glGetTexEnvfv(GLenum target, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetTexEnviv(GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetTexGendv(GLenum coord, GLenum pname, GLdouble* params);
GLAPI void GLAPIENTRY glGetTexGenfv(GLenum coord, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetTexGeniv(GLenum coord, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels);
GLAPI void GLAPIENTRY glGetTexParameterfv(GLenum target, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetTexParameteriv(GLenum target, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params);
GLAPI void GLAPIENTRY glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params);
GLAPI GLboolean GLAPIENTRY glIsEnabled(GLenum cap);
GLAPI GLboolean GLAPIENTRY glIsList(GLuint list);
GLAPI void GLAPIENTRY glDepthRange(GLclampd zNear, GLclampd zFar);
GLAPI void GLAPIENTRY glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLAPI void GLAPIENTRY glLoadIdentity();
GLAPI void GLAPIENTRY glLoadMatrixf(const GLfloat* m);
GLAPI void GLAPIENTRY glLoadMatrixd(const GLdouble* m);
GLAPI void GLAPIENTRY glMatrixMode(GLenum mode);
GLAPI void GLAPIENTRY glMultMatrixf(const GLfloat* m);
GLAPI void GLAPIENTRY glMultMatrixd(const GLdouble* m);
GLAPI void GLAPIENTRY glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLAPI void GLAPIENTRY glPopMatrix();
GLAPI void GLAPIENTRY glPushMatrix();
GLAPI void GLAPIENTRY glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glScaled(GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glScalef(GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glTranslated(GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glTranslatef(GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glArrayElement(GLint i);
GLAPI void GLAPIENTRY glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
GLAPI void GLAPIENTRY glDisableClientState(GLenum array);
GLAPI void GLAPIENTRY glDrawArrays(GLenum mode, GLint first, GLsizei count);
GLAPI void GLAPIENTRY glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices);
GLAPI void GLAPIENTRY glEdgeFlagPointer(GLsizei stride, const GLvoid* pointer);
GLAPI void GLAPIENTRY glEnableClientState(GLenum array);
GLAPI void GLAPIENTRY glGetPointerv(GLenum pname, GLvoid** params);
GLAPI void GLAPIENTRY glIndexPointer(GLenum type, GLsizei stride, const GLvoid* pointer);
GLAPI void GLAPIENTRY glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid* pointer);
GLAPI void GLAPIENTRY glNormalPointer(GLenum type, GLsizei stride, const GLvoid* pointer);
GLAPI void GLAPIENTRY glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
GLAPI void GLAPIENTRY glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
GLAPI void GLAPIENTRY glPolygonOffset(GLfloat factor, GLfloat units);
GLAPI void GLAPIENTRY glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI void GLAPIENTRY glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI void GLAPIENTRY glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void GLAPIENTRY glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI GLboolean GLAPIENTRY glAreTexturesResident(GLsizei n, const GLuint* textures, GLboolean* residences);
GLAPI void GLAPIENTRY glBindTexture(GLenum target, GLuint texture);
GLAPI void GLAPIENTRY glDeleteTextures(GLsizei n, const GLuint* textures);
GLAPI void GLAPIENTRY glGenTextures(GLsizei n, GLuint* textures);
GLAPI GLboolean GLAPIENTRY glIsTexture(GLuint texture);
GLAPI void GLAPIENTRY glPrioritizeTextures(GLsizei n, const GLuint* textures, const GLclampf* priorities);
GLAPI void GLAPIENTRY glIndexub(GLubyte c);
GLAPI void GLAPIENTRY glIndexubv(const GLubyte* c);
GLAPI void GLAPIENTRY glPopClientAttrib();
GLAPI void GLAPIENTRY glPushClientAttrib(GLbitfield mask);
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
GLAPI void GLAPIENTRY glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
GLAPI void GLAPIENTRY glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
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
GLAPI void GLAPIENTRY glGetShaderiv(GLuint program, GLenum pname, GLint* params);
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
GLAPI void GLAPIENTRY glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
GLAPI void GLAPIENTRY glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
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
GLAPI void GLAPIENTRY glEnablei(GLenum target, GLuint index);
GLAPI void GLAPIENTRY glDisablei(GLenum target, GLuint index);
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
GLAPI void GLAPIENTRY glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length);
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
GLAPI void GLAPIENTRY glClampColor(GLenum target, GLenum clamp);
GLAPI void GLAPIENTRY glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI void GLAPIENTRY glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar** uniformNames, GLuint* uniformIndices);
GLAPI void GLAPIENTRY glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
GLAPI GLuint GLAPIENTRY glGetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName);
GLAPI void GLAPIENTRY glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
GLAPI void GLAPIENTRY glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
GLAPI void GLAPIENTRY glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
GLAPI void GLAPIENTRY glPrimitiveRestart();
GLAPI void GLAPIENTRY glPrimitiveRestartIndex(GLuint index);
GLAPI void GLAPIENTRY glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
GLAPI void GLAPIENTRY glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount);
GLAPI void GLAPIENTRY glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer);
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
GLAPI void GLAPIENTRY glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
GLAPI void GLAPIENTRY glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
GLAPI void GLAPIENTRY glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLint basevertex);
GLAPI void GLAPIENTRY glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei drawcount, const GLint* basevertex);
GLAPI void GLAPIENTRY glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void GLAPIENTRY glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void GLAPIENTRY glGetMultisamplefv(GLenum pname, GLuint index, GLfloat* val);
GLAPI void GLAPIENTRY glSampleMaski(GLuint index, GLbitfield mask);
GLAPI void GLAPIENTRY glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level);
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
GLAPI void GLAPIENTRY glMultiTexCoordP1ui(GLenum target, GLenum type, GLuint coords);
GLAPI void GLAPIENTRY glMultiTexCoordP1uiv(GLenum target, GLenum type, const GLuint* coords);
GLAPI void GLAPIENTRY glMultiTexCoordP2ui(GLenum target, GLenum type, GLuint coords);
GLAPI void GLAPIENTRY glMultiTexCoordP2uiv(GLenum target, GLenum type, const GLuint* coords);
GLAPI void GLAPIENTRY glMultiTexCoordP3ui(GLenum target, GLenum type, GLuint coords);
GLAPI void GLAPIENTRY glMultiTexCoordP3uiv(GLenum target, GLenum type, const GLuint* coords);
GLAPI void GLAPIENTRY glMultiTexCoordP4ui(GLenum target, GLenum type, GLuint coords);
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
GLAPI void GLAPIENTRY glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint* params);
GLAPI GLuint GLAPIENTRY glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar* name);
GLAPI void GLAPIENTRY glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
GLAPI void GLAPIENTRY glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei bufSize, GLsizei* length, GLint* params);
GLAPI GLint GLAPIENTRY glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar* name);
GLAPI GLint GLAPIENTRY glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar* name);
GLAPI void GLAPIENTRY glTexBufferRange(GLenum target, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void GLAPIENTRY glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void GLAPIENTRY glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void GLAPIENTRY glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64* params);
GLAPI void GLAPIENTRY glClearBufferData(GLenum target, GLenum internalFormat, GLenum format, GLenum type, const GLvoid* data);
GLAPI void GLAPIENTRY glClearBufferSubData(GLenum target, GLenum internalFormat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid* data);
GLAPI void GLAPIENTRY glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void GLAPIENTRY glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void GLAPIENTRY glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void GLAPIENTRY glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void GLAPIENTRY glVertexAttribBinding(GLuint attribindex, GLuint bindingindex);
GLAPI void GLAPIENTRY glVertexBindingDivisor(GLuint bindingindex, GLuint divisor);
GLAPI void GLAPIENTRY glBufferStorage(GLenum target, GLsizeiptr size, const GLvoid* data, GLbitfield flags);
GLAPI void GLAPIENTRY glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const GLvoid* data);
GLAPI void GLAPIENTRY glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* data);
GLAPI void GLAPIENTRY glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
GLAPI void GLAPIENTRY glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes);
GLAPI void GLAPIENTRY glBindTextures(GLuint first, GLsizei count, const GLuint* textures);
GLAPI void GLAPIENTRY glBindSamplers(GLuint first, GLsizei count, const GLuint* samplers);
GLAPI void GLAPIENTRY glBindImageTextures(GLuint first, GLsizei count, const GLuint* textures);
GLAPI void GLAPIENTRY glBindVertexBuffers(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);
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
GLAPI void GLAPIENTRY glMultiDrawArraysIndirectCount(GLenum mode, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLAPI void GLAPIENTRY glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLNEWLISTPROC)(GLuint list, GLenum mode);
typedef void (GLAPIENTRYP PFNGLENDLISTPROC)();
typedef void (GLAPIENTRYP PFNGLCALLLISTPROC)(GLuint list);
typedef void (GLAPIENTRYP PFNGLCALLLISTSPROC)(GLsizei n, GLenum type, const GLvoid* lists);
typedef void (GLAPIENTRYP PFNGLDELETELISTSPROC)(GLuint list, GLsizei range);
typedef GLuint (GLAPIENTRYP PFNGLGENLISTSPROC)(GLsizei range);
typedef void (GLAPIENTRYP PFNGLLISTBASEPROC)(GLuint base);
typedef void (GLAPIENTRYP PFNGLBEGINPROC)(GLenum mode);
typedef void (GLAPIENTRYP PFNGLBITMAPPROC)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte* bitmap);
typedef void (GLAPIENTRYP PFNGLCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
typedef void (GLAPIENTRYP PFNGLCOLOR3BVPROC)(const GLbyte* v);
typedef void (GLAPIENTRYP PFNGLCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
typedef void (GLAPIENTRYP PFNGLCOLOR3DVPROC)(const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
typedef void (GLAPIENTRYP PFNGLCOLOR3FVPROC)(const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLCOLOR3IPROC)(GLint red, GLint green, GLint blue);
typedef void (GLAPIENTRYP PFNGLCOLOR3IVPROC)(const GLint* v);
typedef void (GLAPIENTRYP PFNGLCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
typedef void (GLAPIENTRYP PFNGLCOLOR3SVPROC)(const GLshort* v);
typedef void (GLAPIENTRYP PFNGLCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
typedef void (GLAPIENTRYP PFNGLCOLOR3UBVPROC)(const GLubyte* v);
typedef void (GLAPIENTRYP PFNGLCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
typedef void (GLAPIENTRYP PFNGLCOLOR3UIVPROC)(const GLuint* v);
typedef void (GLAPIENTRYP PFNGLCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
typedef void (GLAPIENTRYP PFNGLCOLOR3USVPROC)(const GLushort* v);
typedef void (GLAPIENTRYP PFNGLCOLOR4BPROC)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
typedef void (GLAPIENTRYP PFNGLCOLOR4BVPROC)(const GLbyte* v);
typedef void (GLAPIENTRYP PFNGLCOLOR4DPROC)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
typedef void (GLAPIENTRYP PFNGLCOLOR4DVPROC)(const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLCOLOR4FPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (GLAPIENTRYP PFNGLCOLOR4FVPROC)(const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLCOLOR4IPROC)(GLint red, GLint green, GLint blue, GLint alpha);
typedef void (GLAPIENTRYP PFNGLCOLOR4IVPROC)(const GLint* v);
typedef void (GLAPIENTRYP PFNGLCOLOR4SPROC)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
typedef void (GLAPIENTRYP PFNGLCOLOR4SVPROC)(const GLshort* v);
typedef void (GLAPIENTRYP PFNGLCOLOR4UBPROC)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
typedef void (GLAPIENTRYP PFNGLCOLOR4UBVPROC)(const GLubyte* v);
typedef void (GLAPIENTRYP PFNGLCOLOR4UIPROC)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
typedef void (GLAPIENTRYP PFNGLCOLOR4UIVPROC)(const GLuint* v);
typedef void (GLAPIENTRYP PFNGLCOLOR4USPROC)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
typedef void (GLAPIENTRYP PFNGLCOLOR4USVPROC)(const GLushort* v);
typedef void (GLAPIENTRYP PFNGLEDGEFLAGPROC)(GLboolean flag);
typedef void (GLAPIENTRYP PFNGLEDGEFLAGVPROC)(const GLboolean* flag);
typedef void (GLAPIENTRYP PFNGLENDPROC)();
typedef void (GLAPIENTRYP PFNGLINDEXDPROC)(GLdouble c);
typedef void (GLAPIENTRYP PFNGLINDEXDVPROC)(const GLdouble* c);
typedef void (GLAPIENTRYP PFNGLINDEXFPROC)(GLfloat c);
typedef void (GLAPIENTRYP PFNGLINDEXFVPROC)(const GLfloat* c);
typedef void (GLAPIENTRYP PFNGLINDEXIPROC)(GLint c);
typedef void (GLAPIENTRYP PFNGLINDEXIVPROC)(const GLint* c);
typedef void (GLAPIENTRYP PFNGLINDEXSPROC)(GLshort c);
typedef void (GLAPIENTRYP PFNGLINDEXSVPROC)(const GLshort* c);
typedef void (GLAPIENTRYP PFNGLNORMAL3BPROC)(GLbyte nx, GLbyte ny, GLbyte nz);
typedef void (GLAPIENTRYP PFNGLNORMAL3BVPROC)(const GLbyte* v);
typedef void (GLAPIENTRYP PFNGLNORMAL3DPROC)(GLdouble nx, GLdouble ny, GLdouble nz);
typedef void (GLAPIENTRYP PFNGLNORMAL3DVPROC)(const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLNORMAL3FPROC)(GLfloat nx, GLfloat ny, GLfloat nz);
typedef void (GLAPIENTRYP PFNGLNORMAL3FVPROC)(const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLNORMAL3IPROC)(GLint nx, GLint ny, GLint nz);
typedef void (GLAPIENTRYP PFNGLNORMAL3IVPROC)(const GLint* v);
typedef void (GLAPIENTRYP PFNGLNORMAL3SPROC)(GLshort nx, GLshort ny, GLshort nz);
typedef void (GLAPIENTRYP PFNGLNORMAL3SVPROC)(const GLshort* v);
typedef void (GLAPIENTRYP PFNGLRASTERPOS2DPROC)(GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLRASTERPOS2DVPROC)(const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLRASTERPOS2FPROC)(GLfloat x, GLfloat y);
typedef void (GLAPIENTRYP PFNGLRASTERPOS2FVPROC)(const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLRASTERPOS2IPROC)(GLint x, GLint y);
typedef void (GLAPIENTRYP PFNGLRASTERPOS2IVPROC)(const GLint* v);
typedef void (GLAPIENTRYP PFNGLRASTERPOS2SPROC)(GLshort x, GLshort y);
typedef void (GLAPIENTRYP PFNGLRASTERPOS2SVPROC)(const GLshort* v);
typedef void (GLAPIENTRYP PFNGLRASTERPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLRASTERPOS3DVPROC)(const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLRASTERPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLRASTERPOS3FVPROC)(const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLRASTERPOS3IPROC)(GLint x, GLint y, GLint z);
typedef void (GLAPIENTRYP PFNGLRASTERPOS3IVPROC)(const GLint* v);
typedef void (GLAPIENTRYP PFNGLRASTERPOS3SPROC)(GLshort x, GLshort y, GLshort z);
typedef void (GLAPIENTRYP PFNGLRASTERPOS3SVPROC)(const GLshort* v);
typedef void (GLAPIENTRYP PFNGLRASTERPOS4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLRASTERPOS4DVPROC)(const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLRASTERPOS4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLRASTERPOS4FVPROC)(const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLRASTERPOS4IPROC)(GLint x, GLint y, GLint z, GLint w);
typedef void (GLAPIENTRYP PFNGLRASTERPOS4IVPROC)(const GLint* v);
typedef void (GLAPIENTRYP PFNGLRASTERPOS4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (GLAPIENTRYP PFNGLRASTERPOS4SVPROC)(const GLshort* v);
typedef void (GLAPIENTRYP PFNGLRECTDPROC)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
typedef void (GLAPIENTRYP PFNGLRECTDVPROC)(const GLdouble* v1, const GLdouble* v2);
typedef void (GLAPIENTRYP PFNGLRECTFPROC)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
typedef void (GLAPIENTRYP PFNGLRECTFVPROC)(const GLfloat* v1, const GLfloat* v2);
typedef void (GLAPIENTRYP PFNGLRECTIPROC)(GLint x1, GLint y1, GLint x2, GLint y2);
typedef void (GLAPIENTRYP PFNGLRECTIVPROC)(const GLint* v1, const GLint* v2);
typedef void (GLAPIENTRYP PFNGLRECTSPROC)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
typedef void (GLAPIENTRYP PFNGLRECTSVPROC)(const GLshort* v1, const GLshort* v2);
typedef void (GLAPIENTRYP PFNGLTEXCOORD1DPROC)(GLdouble s);
typedef void (GLAPIENTRYP PFNGLTEXCOORD1DVPROC)(const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD1FPROC)(GLfloat s);
typedef void (GLAPIENTRYP PFNGLTEXCOORD1FVPROC)(const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD1IPROC)(GLint s);
typedef void (GLAPIENTRYP PFNGLTEXCOORD1IVPROC)(const GLint* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD1SPROC)(GLshort s);
typedef void (GLAPIENTRYP PFNGLTEXCOORD1SVPROC)(const GLshort* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD2DPROC)(GLdouble s, GLdouble t);
typedef void (GLAPIENTRYP PFNGLTEXCOORD2DVPROC)(const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD2FPROC)(GLfloat s, GLfloat t);
typedef void (GLAPIENTRYP PFNGLTEXCOORD2FVPROC)(const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD2IPROC)(GLint s, GLint t);
typedef void (GLAPIENTRYP PFNGLTEXCOORD2IVPROC)(const GLint* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD2SPROC)(GLshort s, GLshort t);
typedef void (GLAPIENTRYP PFNGLTEXCOORD2SVPROC)(const GLshort* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD3DPROC)(GLdouble s, GLdouble t, GLdouble r);
typedef void (GLAPIENTRYP PFNGLTEXCOORD3DVPROC)(const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD3FPROC)(GLfloat s, GLfloat t, GLfloat r);
typedef void (GLAPIENTRYP PFNGLTEXCOORD3FVPROC)(const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD3IPROC)(GLint s, GLint t, GLint r);
typedef void (GLAPIENTRYP PFNGLTEXCOORD3IVPROC)(const GLint* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD3SPROC)(GLshort s, GLshort t, GLshort r);
typedef void (GLAPIENTRYP PFNGLTEXCOORD3SVPROC)(const GLshort* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD4DPROC)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (GLAPIENTRYP PFNGLTEXCOORD4DVPROC)(const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD4FPROC)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (GLAPIENTRYP PFNGLTEXCOORD4FVPROC)(const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD4IPROC)(GLint s, GLint t, GLint r, GLint q);
typedef void (GLAPIENTRYP PFNGLTEXCOORD4IVPROC)(const GLint* v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD4SPROC)(GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (GLAPIENTRYP PFNGLTEXCOORD4SVPROC)(const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEX2DPROC)(GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLVERTEX2DVPROC)(const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEX2FPROC)(GLfloat x, GLfloat y);
typedef void (GLAPIENTRYP PFNGLVERTEX2FVPROC)(const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEX2IPROC)(GLint x, GLint y);
typedef void (GLAPIENTRYP PFNGLVERTEX2IVPROC)(const GLint* v);
typedef void (GLAPIENTRYP PFNGLVERTEX2SPROC)(GLshort x, GLshort y);
typedef void (GLAPIENTRYP PFNGLVERTEX2SVPROC)(const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEX3DPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLVERTEX3DVPROC)(const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEX3FPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLVERTEX3FVPROC)(const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEX3IPROC)(GLint x, GLint y, GLint z);
typedef void (GLAPIENTRYP PFNGLVERTEX3IVPROC)(const GLint* v);
typedef void (GLAPIENTRYP PFNGLVERTEX3SPROC)(GLshort x, GLshort y, GLshort z);
typedef void (GLAPIENTRYP PFNGLVERTEX3SVPROC)(const GLshort* v);
typedef void (GLAPIENTRYP PFNGLVERTEX4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLVERTEX4DVPROC)(const GLdouble* v);
typedef void (GLAPIENTRYP PFNGLVERTEX4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLVERTEX4FVPROC)(const GLfloat* v);
typedef void (GLAPIENTRYP PFNGLVERTEX4IPROC)(GLint x, GLint y, GLint z, GLint w);
typedef void (GLAPIENTRYP PFNGLVERTEX4IVPROC)(const GLint* v);
typedef void (GLAPIENTRYP PFNGLVERTEX4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (GLAPIENTRYP PFNGLVERTEX4SVPROC)(const GLshort* v);
typedef void (GLAPIENTRYP PFNGLCLIPPLANEPROC)(GLenum plane, const GLdouble* equation);
typedef void (GLAPIENTRYP PFNGLCOLORMATERIALPROC)(GLenum face, GLenum mode);
typedef void (GLAPIENTRYP PFNGLCULLFACEPROC)(GLenum mode);
typedef void (GLAPIENTRYP PFNGLFOGFPROC)(GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLFOGFVPROC)(GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLFOGIPROC)(GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLFOGIVPROC)(GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLFRONTFACEPROC)(GLenum mode);
typedef void (GLAPIENTRYP PFNGLHINTPROC)(GLenum target, GLenum mode);
typedef void (GLAPIENTRYP PFNGLLIGHTFPROC)(GLenum light, GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLLIGHTFVPROC)(GLenum light, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLLIGHTIPROC)(GLenum light, GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLLIGHTIVPROC)(GLenum light, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLLIGHTMODELFPROC)(GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLLIGHTMODELFVPROC)(GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLLIGHTMODELIPROC)(GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLLIGHTMODELIVPROC)(GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLLINESTIPPLEPROC)(GLint factor, GLushort pattern);
typedef void (GLAPIENTRYP PFNGLLINEWIDTHPROC)(GLfloat width);
typedef void (GLAPIENTRYP PFNGLMATERIALFPROC)(GLenum face, GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLMATERIALFVPROC)(GLenum face, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLMATERIALIPROC)(GLenum face, GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLMATERIALIVPROC)(GLenum face, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLPOINTSIZEPROC)(GLfloat size);
typedef void (GLAPIENTRYP PFNGLPOLYGONMODEPROC)(GLenum face, GLenum mode);
typedef void (GLAPIENTRYP PFNGLPOLYGONSTIPPLEPROC)(const GLubyte* mask);
typedef void (GLAPIENTRYP PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLSHADEMODELPROC)(GLenum mode);
typedef void (GLAPIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLTEXIMAGE1DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLTEXENVFPROC)(GLenum target, GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLTEXENVFVPROC)(GLenum target, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLTEXENVIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLTEXENVIVPROC)(GLenum target, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLTEXGENDPROC)(GLenum coord, GLenum pname, GLdouble param);
typedef void (GLAPIENTRYP PFNGLTEXGENDVPROC)(GLenum coord, GLenum pname, const GLdouble* params);
typedef void (GLAPIENTRYP PFNGLTEXGENFPROC)(GLenum coord, GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLTEXGENFVPROC)(GLenum coord, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRYP PFNGLTEXGENIPROC)(GLenum coord, GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLTEXGENIVPROC)(GLenum coord, GLenum pname, const GLint* params);
typedef void (GLAPIENTRYP PFNGLFEEDBACKBUFFERPROC)(GLsizei size, GLenum type, GLfloat* buffer);
typedef void (GLAPIENTRYP PFNGLSELECTBUFFERPROC)(GLsizei size, GLuint* buffer);
typedef GLint (GLAPIENTRYP PFNGLRENDERMODEPROC)(GLenum mode);
typedef void (GLAPIENTRYP PFNGLINITNAMESPROC)();
typedef void (GLAPIENTRYP PFNGLLOADNAMEPROC)(GLuint name);
typedef void (GLAPIENTRYP PFNGLPASSTHROUGHPROC)(GLfloat token);
typedef void (GLAPIENTRYP PFNGLPOPNAMEPROC)();
typedef void (GLAPIENTRYP PFNGLPUSHNAMEPROC)(GLuint name);
typedef void (GLAPIENTRYP PFNGLDRAWBUFFERPROC)(GLenum mode);
typedef void (GLAPIENTRYP PFNGLCLEARPROC)(GLbitfield mask);
typedef void (GLAPIENTRYP PFNGLCLEARACCUMPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (GLAPIENTRYP PFNGLCLEARINDEXPROC)(GLfloat c);
typedef void (GLAPIENTRYP PFNGLCLEARCOLORPROC)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
typedef void (GLAPIENTRYP PFNGLCLEARSTENCILPROC)(GLint s);
typedef void (GLAPIENTRYP PFNGLCLEARDEPTHPROC)(GLclampd depth);
typedef void (GLAPIENTRYP PFNGLSTENCILMASKPROC)(GLuint mask);
typedef void (GLAPIENTRYP PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (GLAPIENTRYP PFNGLDEPTHMASKPROC)(GLboolean flag);
typedef void (GLAPIENTRYP PFNGLINDEXMASKPROC)(GLuint mask);
typedef void (GLAPIENTRYP PFNGLACCUMPROC)(GLenum op, GLfloat value);
typedef void (GLAPIENTRYP PFNGLDISABLEPROC)(GLenum cap);
typedef void (GLAPIENTRYP PFNGLENABLEPROC)(GLenum cap);
typedef void (GLAPIENTRYP PFNGLFINISHPROC)();
typedef void (GLAPIENTRYP PFNGLFLUSHPROC)();
typedef void (GLAPIENTRYP PFNGLPOPATTRIBPROC)();
typedef void (GLAPIENTRYP PFNGLPUSHATTRIBPROC)(GLbitfield mask);
typedef void (GLAPIENTRYP PFNGLMAP1DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble* points);
typedef void (GLAPIENTRYP PFNGLMAP1FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat* points);
typedef void (GLAPIENTRYP PFNGLMAP2DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble* points);
typedef void (GLAPIENTRYP PFNGLMAP2FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat* points);
typedef void (GLAPIENTRYP PFNGLMAPGRID1DPROC)(GLint un, GLdouble u1, GLdouble u2);
typedef void (GLAPIENTRYP PFNGLMAPGRID1FPROC)(GLint un, GLfloat u1, GLfloat u2);
typedef void (GLAPIENTRYP PFNGLMAPGRID2DPROC)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
typedef void (GLAPIENTRYP PFNGLMAPGRID2FPROC)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
typedef void (GLAPIENTRYP PFNGLEVALCOORD1DPROC)(GLdouble u);
typedef void (GLAPIENTRYP PFNGLEVALCOORD1DVPROC)(const GLdouble* u);
typedef void (GLAPIENTRYP PFNGLEVALCOORD1FPROC)(GLfloat u);
typedef void (GLAPIENTRYP PFNGLEVALCOORD1FVPROC)(const GLfloat* u);
typedef void (GLAPIENTRYP PFNGLEVALCOORD2DPROC)(GLdouble u, GLdouble v);
typedef void (GLAPIENTRYP PFNGLEVALCOORD2DVPROC)(const GLdouble* u);
typedef void (GLAPIENTRYP PFNGLEVALCOORD2FPROC)(GLfloat u, GLfloat v);
typedef void (GLAPIENTRYP PFNGLEVALCOORD2FVPROC)(const GLfloat* u);
typedef void (GLAPIENTRYP PFNGLEVALMESH1PROC)(GLenum mode, GLint i1, GLint i2);
typedef void (GLAPIENTRYP PFNGLEVALPOINT1PROC)(GLint i);
typedef void (GLAPIENTRYP PFNGLEVALMESH2PROC)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
typedef void (GLAPIENTRYP PFNGLEVALPOINT2PROC)(GLint i, GLint j);
typedef void (GLAPIENTRYP PFNGLALPHAFUNCPROC)(GLenum func, GLclampf ref);
typedef void (GLAPIENTRYP PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
typedef void (GLAPIENTRYP PFNGLLOGICOPPROC)(GLenum opcode);
typedef void (GLAPIENTRYP PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
typedef void (GLAPIENTRYP PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
typedef void (GLAPIENTRYP PFNGLDEPTHFUNCPROC)(GLenum func);
typedef void (GLAPIENTRYP PFNGLPIXELZOOMPROC)(GLfloat xfactor, GLfloat yfactor);
typedef void (GLAPIENTRYP PFNGLPIXELTRANSFERFPROC)(GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLPIXELTRANSFERIPROC)(GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLPIXELSTOREFPROC)(GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLPIXELMAPFVPROC)(GLenum map, GLint mapsize, const GLfloat* values);
typedef void (GLAPIENTRYP PFNGLPIXELMAPUIVPROC)(GLenum map, GLint mapsize, const GLuint* values);
typedef void (GLAPIENTRYP PFNGLPIXELMAPUSVPROC)(GLenum map, GLint mapsize, const GLushort* values);
typedef void (GLAPIENTRYP PFNGLREADBUFFERPROC)(GLenum mode);
typedef void (GLAPIENTRYP PFNGLCOPYPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
typedef void (GLAPIENTRYP PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLDRAWPIXELSPROC)(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean* params);
typedef void (GLAPIENTRYP PFNGLGETCLIPPLANEPROC)(GLenum plane, GLdouble* equation);
typedef void (GLAPIENTRYP PFNGLGETDOUBLEVPROC)(GLenum pname, GLdouble* params);
typedef GLenum (GLAPIENTRYP PFNGLGETERRORPROC)();
typedef void (GLAPIENTRYP PFNGLGETFLOATVPROC)(GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETINTEGERVPROC)(GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETLIGHTFVPROC)(GLenum light, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETLIGHTIVPROC)(GLenum light, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETMAPDVPROC)(GLenum target, GLenum query, GLdouble* v);
typedef void (GLAPIENTRYP PFNGLGETMAPFVPROC)(GLenum target, GLenum query, GLfloat* v);
typedef void (GLAPIENTRYP PFNGLGETMAPIVPROC)(GLenum target, GLenum query, GLint* v);
typedef void (GLAPIENTRYP PFNGLGETMATERIALFVPROC)(GLenum face, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETMATERIALIVPROC)(GLenum face, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETPIXELMAPFVPROC)(GLenum map, GLfloat* values);
typedef void (GLAPIENTRYP PFNGLGETPIXELMAPUIVPROC)(GLenum map, GLuint* values);
typedef void (GLAPIENTRYP PFNGLGETPIXELMAPUSVPROC)(GLenum map, GLushort* values);
typedef void (GLAPIENTRYP PFNGLGETPOLYGONSTIPPLEPROC)(GLubyte* mask);
typedef const GLubyte* (GLAPIENTRYP PFNGLGETSTRINGPROC)(GLenum name);
typedef void (GLAPIENTRYP PFNGLGETTEXENVFVPROC)(GLenum target, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETTEXENVIVPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETTEXGENDVPROC)(GLenum coord, GLenum pname, GLdouble* params);
typedef void (GLAPIENTRYP PFNGLGETTEXGENFVPROC)(GLenum coord, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETTEXGENIVPROC)(GLenum coord, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum target, GLint level, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum target, GLint level, GLenum pname, GLint* params);
typedef GLboolean (GLAPIENTRYP PFNGLISENABLEDPROC)(GLenum cap);
typedef GLboolean (GLAPIENTRYP PFNGLISLISTPROC)(GLuint list);
typedef void (GLAPIENTRYP PFNGLDEPTHRANGEPROC)(GLclampd zNear, GLclampd zFar);
typedef void (GLAPIENTRYP PFNGLFRUSTUMPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (GLAPIENTRYP PFNGLLOADIDENTITYPROC)();
typedef void (GLAPIENTRYP PFNGLLOADMATRIXFPROC)(const GLfloat* m);
typedef void (GLAPIENTRYP PFNGLLOADMATRIXDPROC)(const GLdouble* m);
typedef void (GLAPIENTRYP PFNGLMATRIXMODEPROC)(GLenum mode);
typedef void (GLAPIENTRYP PFNGLMULTMATRIXFPROC)(const GLfloat* m);
typedef void (GLAPIENTRYP PFNGLMULTMATRIXDPROC)(const GLdouble* m);
typedef void (GLAPIENTRYP PFNGLORTHOPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (GLAPIENTRYP PFNGLPOPMATRIXPROC)();
typedef void (GLAPIENTRYP PFNGLPUSHMATRIXPROC)();
typedef void (GLAPIENTRYP PFNGLROTATEDPROC)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLROTATEFPROC)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLSCALEDPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLSCALEFPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLTRANSLATEDPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLTRANSLATEFPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLARRAYELEMENTPROC)(GLint i);
typedef void (GLAPIENTRYP PFNGLCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLDISABLECLIENTSTATEPROC)(GLenum array);
typedef void (GLAPIENTRYP PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices);
typedef void (GLAPIENTRYP PFNGLEDGEFLAGPOINTERPROC)(GLsizei stride, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLENABLECLIENTSTATEPROC)(GLenum array);
typedef void (GLAPIENTRYP PFNGLGETPOINTERVPROC)(GLenum pname, GLvoid** params);
typedef void (GLAPIENTRYP PFNGLINDEXPOINTERPROC)(GLenum type, GLsizei stride, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLINTERLEAVEDARRAYSPROC)(GLenum format, GLsizei stride, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLNORMALPOINTERPROC)(GLenum type, GLsizei stride, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLTEXCOORDPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLVERTEXPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
typedef void (GLAPIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
typedef void (GLAPIENTRYP PFNGLCOPYTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (GLAPIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (GLAPIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (GLAPIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
typedef GLboolean (GLAPIENTRYP PFNGLARETEXTURESRESIDENTPROC)(GLsizei n, const GLuint* textures, GLboolean* residences);
typedef void (GLAPIENTRYP PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
typedef void (GLAPIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint* textures);
typedef void (GLAPIENTRYP PFNGLGENTEXTURESPROC)(GLsizei n, GLuint* textures);
typedef GLboolean (GLAPIENTRYP PFNGLISTEXTUREPROC)(GLuint texture);
typedef void (GLAPIENTRYP PFNGLPRIORITIZETEXTURESPROC)(GLsizei n, const GLuint* textures, const GLclampf* priorities);
typedef void (GLAPIENTRYP PFNGLINDEXUBPROC)(GLubyte c);
typedef void (GLAPIENTRYP PFNGLINDEXUBVPROC)(const GLubyte* c);
typedef void (GLAPIENTRYP PFNGLPOPCLIENTATTRIBPROC)();
typedef void (GLAPIENTRYP PFNGLPUSHCLIENTATTRIBPROC)(GLbitfield mask);
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
typedef void (GLAPIENTRYP PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
typedef void (GLAPIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
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
typedef void (GLAPIENTRYP PFNGLGETSHADERIVPROC)(GLuint program, GLenum pname, GLint* params);
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
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
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
typedef void (GLAPIENTRYP PFNGLENABLEIPROC)(GLenum target, GLuint index);
typedef void (GLAPIENTRYP PFNGLDISABLEIPROC)(GLenum target, GLuint index);
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
typedef void (GLAPIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
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
typedef void (GLAPIENTRYP PFNGLCLAMPCOLORPROC)(GLenum target, GLenum clamp);
typedef void (GLAPIENTRYP PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (GLAPIENTRYP PFNGLGETUNIFORMINDICESPROC)(GLuint program, GLsizei uniformCount, const GLchar** uniformNames, GLuint* uniformIndices);
typedef void (GLAPIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
typedef GLuint (GLAPIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar* uniformBlockName);
typedef void (GLAPIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
typedef void (GLAPIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
typedef void (GLAPIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
typedef void (GLAPIENTRYP PFNGLPRIMITIVERESTARTPROC)();
typedef void (GLAPIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint index);
typedef void (GLAPIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount);
typedef void (GLAPIENTRYP PFNGLTEXBUFFERPROC)(GLenum target, GLenum internalformat, GLuint buffer);
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
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
typedef void (GLAPIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLint basevertex);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei drawcount, const GLint* basevertex);
typedef void (GLAPIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (GLAPIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (GLAPIENTRYP PFNGLGETMULTISAMPLEFVPROC)(GLenum pname, GLuint index, GLfloat* val);
typedef void (GLAPIENTRYP PFNGLSAMPLEMASKIPROC)(GLuint index, GLbitfield mask);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
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
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDP1UIPROC)(GLenum target, GLenum type, GLuint coords);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDP1UIVPROC)(GLenum target, GLenum type, const GLuint* coords);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDP2UIPROC)(GLenum target, GLenum type, GLuint coords);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDP2UIVPROC)(GLenum target, GLenum type, const GLuint* coords);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDP3UIPROC)(GLenum target, GLenum type, GLuint coords);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDP3UIVPROC)(GLenum target, GLenum type, const GLuint* coords);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDP4UIPROC)(GLenum target, GLenum type, GLuint coords);
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
typedef void (GLAPIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint program, GLenum programInterface, GLenum pname, GLint* params);
typedef GLuint (GLAPIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint program, GLenum programInterface, const GLchar* name);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei bufSize, GLsizei* length, GLint* params);
typedef GLint (GLAPIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint program, GLenum programInterface, const GLchar* name);
typedef GLint (GLAPIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)(GLuint program, GLenum programInterface, const GLchar* name);
typedef void (GLAPIENTRYP PFNGLTEXBUFFERRANGEPROC)(GLenum target, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (GLAPIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (GLAPIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (GLAPIENTRYP PFNGLGETINTERNALFORMATI64VPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64* params);
typedef void (GLAPIENTRYP PFNGLCLEARBUFFERDATAPROC)(GLenum target, GLenum internalFormat, GLenum format, GLenum type, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCLEARBUFFERSUBDATAPROC)(GLenum target, GLenum internalFormat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLBINDVERTEXBUFFERPROC)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBIFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBLFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBBINDINGPROC)(GLuint attribindex, GLuint bindingindex);
typedef void (GLAPIENTRYP PFNGLVERTEXBINDINGDIVISORPROC)(GLuint bindingindex, GLuint divisor);
typedef void (GLAPIENTRYP PFNGLBUFFERSTORAGEPROC)(GLenum target, GLsizeiptr size, const GLvoid* data, GLbitfield flags);
typedef void (GLAPIENTRYP PFNGLCLEARTEXIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLCLEARTEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* data);
typedef void (GLAPIENTRYP PFNGLBINDBUFFERSBASEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
typedef void (GLAPIENTRYP PFNGLBINDBUFFERSRANGEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes);
typedef void (GLAPIENTRYP PFNGLBINDTEXTURESPROC)(GLuint first, GLsizei count, const GLuint* textures);
typedef void (GLAPIENTRYP PFNGLBINDSAMPLERSPROC)(GLuint first, GLsizei count, const GLuint* samplers);
typedef void (GLAPIENTRYP PFNGLBINDIMAGETEXTURESPROC)(GLuint first, GLsizei count, const GLuint* textures);
typedef void (GLAPIENTRYP PFNGLBINDVERTEXBUFFERSPROC)(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);
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
typedef void (GLAPIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)(GLenum mode, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)(GLenum mode, GLenum type, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);


#ifdef __cplusplus
}
#endif

#endif /* __gl_h_ */
