//-----------------------------------------------------------------------------
// Generated with NVIDIA Nsight Graphics 2019.3.0.0
// 
// File: Frame0Part00.cpp
// 
//-----------------------------------------------------------------------------

#include "Resources.h"
#include "Helpers.h"
#include "Threading.h"

//-----------------------------------------------------------------------------
// RunFrame0Part00
//-----------------------------------------------------------------------------
void RunFrame0Part00()
{
    BEGIN_DATA_SCOPE_FUNCTION();

    NV_EXEC(glUseProgram(Program_uid_14));

    static GLfloat GLfloat_temp_1[16] = { 
        HexToFloat(0x3FF73729/*1.93137f*/), 0.0f, 0.0f, 0.0f, 0.0f, HexToFloat(0x401A8279/*2.41421f*/), 0.0f, 0.0f, 
        0.0f, 0.0f, HexToFloat(0xBF80068D/*-1.0002f*/), HexToFloat(0xBF800000/*-1.0f*/), HexToFloat(0xC310DA52/*-144.853f*/), HexToFloat(0xC210DA51/*-36.2132f*/), HexToFloat(0x4295A144/*74.815f*/), HexToFloat(0x42960000/*75.0f*/)
    };
    NV_EXEC(glUniformMatrix4fv(Uniform_prog_284_loc_0, 1, GL_FALSE, GLfloat_temp_1));

    NV_EXEC(glUniform3f(Uniform_prog_284_loc_9, HexToFloat(0x42960000/*75.0f*/), HexToFloat(0x41700000/*15.0f*/), HexToFloat(0x42960000/*75.0f*/)));
    NV_EXEC(glUniform1i(Uniform_prog_284_loc_7, 0));
    NV_EXEC(glUniform1i(Uniform_prog_284_loc_1, 1));
    NV_EXEC(glUniform1i(Uniform_prog_284_loc_3, 2));
    NV_EXEC(glUniform1i(Uniform_prog_284_loc_6, 3));
    NV_EXEC(glUniform1i(Uniform_prog_284_loc_5, 4));
    NV_EXEC(glUniform1i(Uniform_prog_284_loc_8, 1));
    //NV_EXEC(glUniform1f(-1/*INFO: Non-existent uniform*/, 0.0f));
    NV_EXEC(glUniform1i(Uniform_prog_284_loc_2, 0));
    NV_EXEC(glUniform1f(Uniform_prog_284_loc_4, HexToFloat(0x43000000/*128.0f*/)));

    // Clear #0 [0...0]
    NV_EXEC(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

    NV_EXEC(glPatchParameteri(GL_PATCH_VERTICES, 3));
    NV_EXEC(glEnableVertexAttribArray(0u));
    NV_EXEC(glBindBuffer(GL_ARRAY_BUFFER, Buffer_uid_16));
    NV_EXEC(glVertexAttribPointer(0u, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0));
    NV_EXEC(glEnableVertexAttribArray(1u));
    NV_EXEC(glVertexAttribPointer(1u, 3, GL_FLOAT, GL_FALSE, 32, (GLvoid*)0xc));
    NV_EXEC(glEnableVertexAttribArray(2u));
    NV_EXEC(glBindBuffer(GL_ARRAY_BUFFER, Buffer_uid_18));
    NV_EXEC(glVertexAttribPointer(2u, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0));
    NV_EXEC(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Buffer_uid_17));

    // Draw #0 [0...0]
    NV_EXEC(glDrawElements(GL_PATCHES, 6144, GL_UNSIGNED_SHORT, (GLvoid*)0));

    NV_EXEC(glDisableVertexAttribArray(0u));
    NV_EXEC(glDisableVertexAttribArray(1u));
    NV_EXEC(glDisableVertexAttribArray(2u));
    NV_EXEC(glXSwapBuffers(display_0x5607e7cb38c0, glxDrawable_400000b));
}
