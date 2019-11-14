//-----------------------------------------------------------------------------
// Generated with NVIDIA Nsight Graphics 2019.3.0.0
// 
// File: Resources.h
// 
//-----------------------------------------------------------------------------

#pragma once

#include "NvEW_GL.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "NvEW_GLX.h"

#include <cstdint>
#include <limits>

//-----------------------------------------------------------------------------
// GL resource typedefs
//-----------------------------------------------------------------------------
typedef GLint Uniform;
typedef GLuint UniformBlock;
typedef GLuint ShaderStorageBlock;
typedef GLuint Buffer;
typedef GLuint Shader;
typedef GLuint Program;
typedef GLuint Texture;
typedef GLuint64 TextureHandle;
typedef GLuint VertexArray;
typedef GLuint FrameBuffer;
typedef GLuint ProgramPipeline;
typedef GLuint Query;
typedef GLuint RenderBuffer;
typedef GLuint Sampler;
typedef GLuint TransformFeedback;
typedef unsigned char ClientSideBuffer;
typedef GLuint LegacyProgram;
typedef GLuint Memory;
typedef GLuint Semaphore;

//-----------------------------------------------------------------------------
// GL indirect structs
//-----------------------------------------------------------------------------
struct glDrawElementsIndirectCommand
{
    GLuint count;
    GLuint drawCount;
    GLuint firstIndex;
    GLuint baseVertex;
    GLuint baseInstance;
};

typedef glDrawElementsIndirectCommand glDrawElementsIndirectCountCommand;
typedef glDrawElementsIndirectCountCommand glDrawElementsIndirectCountARBCommand;

struct glDrawArraysIndirectCommand
{
    GLuint count;
    GLuint instanceCount;
    GLuint first;
    GLuint baseInstance;
};

typedef glDrawArraysIndirectCommand glDrawArraysIndirectCountCommand;
typedef glDrawArraysIndirectCountCommand glDrawArraysIndirectCountARBCommand;

//-----------------------------------------------------------------------------
// Invalid GL object handles
//-----------------------------------------------------------------------------
const Buffer INVALID_BUFFER = (std::numeric_limits<GLuint>::max)();
const FrameBuffer INVALID_FRAMEBUFFER = (std::numeric_limits<GLuint>::max)();
const Program INVALID_PROGRAM = (std::numeric_limits<GLuint>::max)();
const ProgramPipeline INVALID_PROGRAM_PIPELINE = (std::numeric_limits<GLuint>::max)();
const Query INVALID_QUERY = (std::numeric_limits<GLuint>::max)();
const RenderBuffer INVALID_RENDERBUFFER = (std::numeric_limits<GLuint>::max)();
const Sampler INVALID_SAMPLER = (std::numeric_limits<GLuint>::max)();
const Shader INVALID_SHADER = (std::numeric_limits<GLuint>::max)();
const Texture INVALID_TEXTURE = (std::numeric_limits<GLuint>::max)();
const TransformFeedback INVALID_TRANSFORM_FEEDBACK = (std::numeric_limits<GLuint>::max)();
const VertexArray INVALID_VERTEX_ARRAY = (std::numeric_limits<GLuint>::max)();

//-----------------------------------------------------------------------------
// Invalid GL sync objects
//-----------------------------------------------------------------------------
const GLsync INVALID_SYNC = GLsync(0);

//-----------------------------------------------------------------------------
// Invalid GLSL variables
//-----------------------------------------------------------------------------
const ShaderStorageBlock INVALID_SHADER_STORAGE_BLOCK = (std::numeric_limits<GLuint>::max)();
const Uniform INVALID_UNIFORM = (std::numeric_limits<GLint>::max)();
const UniformBlock INVALID_UNIFORM_BLOCK = (std::numeric_limits<GLuint>::max)();
typedef GLXContext Context;

//-----------------------------------------------------------------------------
// Captured Resources
//-----------------------------------------------------------------------------
extern GLXFBConfig glxFBConfig_0;
extern Uniform Uniform_prog_284_loc_9;
extern Uniform Uniform_prog_284_loc_8;
extern Uniform Uniform_prog_284_loc_7;
extern Uniform Uniform_prog_284_loc_6;
extern Uniform Uniform_prog_284_loc_5;
extern Uniform Uniform_prog_284_loc_4;
extern Uniform Uniform_prog_284_loc_3;
extern Uniform Uniform_prog_284_loc_2;
extern Uniform Uniform_prog_284_loc_1;
extern Uniform Uniform_prog_284_loc_0;
extern Context Context_uid_4;
extern TransformFeedback TransformFeedback_uid_5;
extern VertexArray VertexArray_uid_6;
extern Program Program_uid_14;
extern VertexArray VertexArray_uid_15;
extern Buffer Buffer_uid_16;
extern Buffer Buffer_uid_17;
extern Buffer Buffer_uid_18;
extern Texture Texture_uid_19;
extern Texture Texture_uid_21;
extern Texture Texture_uid_23;
extern Texture Texture_uid_25;
extern Texture Texture_uid_27;
extern GLXDrawable glxDrawable_440000b;
extern Display* display_0x559eaa677cd0;
extern GLXFBConfig glxFBConfig_0x559eaa6e1b60;
extern Context Context_uid_4_Staging;
