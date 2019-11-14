//-----------------------------------------------------------------------------
// Generated with NVIDIA Nsight Graphics 2019.3.0.0
// 
// File: FrameReset00.cpp
// 
//-----------------------------------------------------------------------------

#include <vector>
#include <sstream>

#include "NvEW_GL.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "NvEW_GLX.h"
#include "Helpers.h"
#include "Resources.h"
#include "Application.h"

//-----------------------------------------------------------------------------
// ResetInitialFrameState00
//-----------------------------------------------------------------------------
void ResetInitialFrameState00(bool firstTime)
{
    BEGIN_DATA_SCOPE_FUNCTION();

    // Switch to staging context
    NV_EXEC_GL(glFinish());
    glXMakeCurrent(display_0x5607e7cb38c0, glxDrawable_400000b, Context_uid_4_Staging);

    // Program_uidof_14
    {
        BEGIN_DATA_SCOPE();

        // Set uniform values
        {
            BEGIN_DATA_SCOPE();

            NV_EXEC_GL(glUseProgram(Program_uid_14));

            static GLfloat GLfloat_temp_5[16] = { 
                HexToFloat(0x3FF73729/*1.93137f*/), 0.0f, 0.0f, 0.0f, 0.0f, HexToFloat(0x401A8279/*2.41421f*/), 0.0f, 0.0f, 
                0.0f, 0.0f, HexToFloat(0xBF80068D/*-1.0002f*/), HexToFloat(0xBF800000/*-1.0f*/), HexToFloat(0xC310DA52/*-144.853f*/), HexToFloat(0xC210DA51/*-36.2132f*/), HexToFloat(0x4295A144/*74.815f*/), HexToFloat(0x42960000/*75.0f*/)
            };
            NV_EXEC_GL(glUniformMatrix4fv(Uniform_prog_284_loc_0, 1, GL_ZERO, GLfloat_temp_5));

            NV_EXEC_GL(glUniform1i(Uniform_prog_284_loc_1, 1));
            NV_EXEC_GL(glUniform1i(Uniform_prog_284_loc_2, 0));
            NV_EXEC_GL(glUniform1i(Uniform_prog_284_loc_3, 2));
            NV_EXEC_GL(glUniform1f(Uniform_prog_284_loc_4, HexToFloat(0x43000000/*128.0f*/)));
            NV_EXEC_GL(glUniform1i(Uniform_prog_284_loc_5, 4));
            NV_EXEC_GL(glUniform1i(Uniform_prog_284_loc_6, 3));
            NV_EXEC_GL(glUniform1i(Uniform_prog_284_loc_7, 0));
            NV_EXEC_GL(glUniform1i(Uniform_prog_284_loc_8, 1));
            NV_EXEC_GL(glUniform3f(Uniform_prog_284_loc_9, HexToFloat(0x42960000/*75.0f*/), HexToFloat(0x41700000/*15.0f*/), HexToFloat(0x42960000/*75.0f*/)));
        }
    }

    // Switch to rendering context
    NV_EXEC_GL(glFinish());
    glXMakeCurrent(display_0x5607e7cb38c0, glxDrawable_400000b, Context_uid_4);

    // OpenGL_Context_uidof_4
    {
        BEGIN_DATA_SCOPE();

        // Vertex Array
        {
            BEGIN_DATA_SCOPE();

            glBindBuffer(GL_ARRAY_BUFFER, Buffer_uid_18);
            glBindVertexArray(VertexArray_uid_15);
            glBindBuffer(GL_PARAMETER_BUFFER, 0);
        }

        // Transformation
        {
            BEGIN_DATA_SCOPE();

            glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, TransformFeedback_uid_5);
        }

        // Texture Units
        {
            BEGIN_DATA_SCOPE();

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, Texture_uid_19);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, Texture_uid_21);
            glActiveTexture(GL_TEXTURE2);
            glBindTexture(GL_TEXTURE_2D, Texture_uid_23);
            glActiveTexture(GL_TEXTURE3);
            glBindTexture(GL_TEXTURE_2D, Texture_uid_25);
            glActiveTexture(GL_TEXTURE4);
            glBindTexture(GL_TEXTURE_2D, Texture_uid_27);
            glActiveTexture(GL_TEXTURE4);
        }

        // Framebuffers
        {
            BEGIN_DATA_SCOPE();

            glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
            glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
        }

        // Program Bindings
        {
            BEGIN_DATA_SCOPE();

            glUseProgram(Program_uid_14);
            glBindProgramPipeline(0);
        }

        // Legacy program objects
        {
            BEGIN_DATA_SCOPE();

            glBindProgramARB(GL_VERTEX_PROGRAM_ARB, 0);
            glBindProgramARB(GL_TESS_CONTROL_PROGRAM_NV, 0);
            glBindProgramARB(GL_TESS_EVALUATION_PROGRAM_NV, 0);
            glBindProgramARB(GL_GEOMETRY_PROGRAM_NV, 0);
            glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, 0);
        }

        // Buffer Object Bindings
        {
            BEGIN_DATA_SCOPE();

            glBindBuffer(GL_ATOMIC_COUNTER_BUFFER, 0);
            glBindBuffer(GL_TRANSFORM_FEEDBACK_BUFFER, 0);
            glBindBuffer(GL_UNIFORM_BUFFER, 0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Buffer_uid_17);
            glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
        }
    }
}
