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
        HexToFloat(0x3FB80191/*1.43755f*/), HexToFloat(0xBF149621/*-0.580416f*/), HexToFloat(0xBF1F889B/*-0.623178f*/), HexToFloat(0xBF1F8071/*-0.623054f*/), HexToFloat(0x349A8279/*2.87797e-07f*/), HexToFloat(0x4010267F/*2.25235f*/), HexToFloat(0xBEB85ADE/*-0.360068f*/), HexToFloat(0xBEB8516F/*-0.359996f*/), 
        HexToFloat(0xBFA51902/*-1.28983f*/), HexToFloat(0xBF259A8E/*-0.64689f*/), HexToFloat(0xBF31CE08/*-0.69455f*/), HexToFloat(0xBF31C4EF/*-0.694411f*/), HexToFloat(0xC12BCD4C/*-10.7376f*/), HexToFloat(0x420ACF25/*34.7023f*/), HexToFloat(0x42A79D96/*83.8078f*/), HexToFloat(0x42A7FB66/*83.991f*/)
    };
    NV_EXEC(glUniformMatrix4fv(Uniform_prog_284_loc_0, 1, GL_FALSE, GLfloat_temp_1));

    NV_EXEC(glUniform3f(Uniform_prog_284_loc_9, HexToFloat(0x426FB2F5/*59.9248f*/), HexToFloat(0x41869BB5/*16.826f*/), HexToFloat(0x4269DA20/*58.463f*/)));
    NV_EXEC(glUniform1i(Uniform_prog_284_loc_7, 0));
    NV_EXEC(glUniform1i(Uniform_prog_284_loc_1, 1));
    NV_EXEC(glUniform1i(Uniform_prog_284_loc_3, 2));
    NV_EXEC(glUniform1i(Uniform_prog_284_loc_6, 3));
    NV_EXEC(glUniform1i(Uniform_prog_284_loc_5, 4));
    NV_EXEC(glUniform1i(Uniform_prog_284_loc_8, 1));
    //NV_EXEC(glUniform1f(-1/*INFO: Non-existent uniform*/, 0.0f));
    NV_EXEC(glUniform1i(Uniform_prog_284_loc_2, 2));
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
    NV_EXEC(glXSwapBuffers(display_0x559eaa677cd0, glxDrawable_440000b));
}
