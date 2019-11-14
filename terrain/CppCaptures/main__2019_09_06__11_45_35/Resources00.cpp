//-----------------------------------------------------------------------------
// Generated with NVIDIA Nsight Graphics 2019.3.0.0
// 
// File: Resources00.cpp
// 
//-----------------------------------------------------------------------------

#include <vector>

#include "Helpers.h"
#include "Resources.h"
#include "WindowSystem.h"

//-----------------------------------------------------------------------------
// CreateResources00
//-----------------------------------------------------------------------------
void CreateResources00()
{
    BEGIN_DATA_SCOPE_FUNCTION();

    // Create Context_uid_4 and its staging resource
    {
        BEGIN_DATA_SCOPE();

        static int int_temp_1[7] = { 0x2091, 0x0004, 0x2092, 0x0003, 0x9126, GLX_WINDOW_BIT, 0x0000 };
        Context_uid_4 = glXCreateContextAttribsARB(display_0x5607e7cb38c0, glxFBConfig_0x5607e7d20350, NULL, true, int_temp_1);

        // Create Context_uid_4_Staging
        {
            BEGIN_DATA_SCOPE();

            Context_uid_4_Staging = glXCreateContextAttribsARB(display_0x5607e7cb38c0, glxFBConfig_0x5607e7d20350, Context_uid_4, true, int_temp_1);
            NV_EXEC_GL(glFinish());
            glXMakeCurrent(display_0x5607e7cb38c0, glxDrawable_400000b, Context_uid_4_Staging);
            NV_EXEC_GL(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));
        }
    }

    // Switch to staging context
    NV_EXEC_GL(glFinish());
    glXMakeCurrent(display_0x5607e7cb38c0, glxDrawable_400000b, Context_uid_4_Staging);

    // Create Program_uid_14
    Program_uid_14 = glCreateProgram();

    // Create Buffer_uid_16
    NV_EXEC_GL(glGenBuffers(1, &Buffer_uid_16));

    // Create Buffer_uid_17
    NV_EXEC_GL(glGenBuffers(1, &Buffer_uid_17));

    // Create Buffer_uid_18
    NV_EXEC_GL(glGenBuffers(1, &Buffer_uid_18));

    // Create Texture_uid_19
    NV_EXEC_GL(glGenTextures(1, &Texture_uid_19));
    NV_EXEC_GL(glActiveTexture(GL_TEXTURE0));
    NV_EXEC_GL(glBindTexture(GL_TEXTURE_2D, Texture_uid_19));

    // Create Texture_uid_21
    NV_EXEC_GL(glGenTextures(1, &Texture_uid_21));
    NV_EXEC_GL(glActiveTexture(GL_TEXTURE0));
    NV_EXEC_GL(glBindTexture(GL_TEXTURE_2D, Texture_uid_21));

    // Create Texture_uid_23
    NV_EXEC_GL(glGenTextures(1, &Texture_uid_23));
    NV_EXEC_GL(glActiveTexture(GL_TEXTURE0));
    NV_EXEC_GL(glBindTexture(GL_TEXTURE_2D, Texture_uid_23));

    // Create Texture_uid_25
    NV_EXEC_GL(glGenTextures(1, &Texture_uid_25));
    NV_EXEC_GL(glActiveTexture(GL_TEXTURE0));
    NV_EXEC_GL(glBindTexture(GL_TEXTURE_2D, Texture_uid_25));

    // Create Texture_uid_27
    NV_EXEC_GL(glGenTextures(1, &Texture_uid_27));
    NV_EXEC_GL(glActiveTexture(GL_TEXTURE0));
    NV_EXEC_GL(glBindTexture(GL_TEXTURE_2D, Texture_uid_27));

    // Switch to rendering context
    NV_EXEC_GL(glFinish());
    glXMakeCurrent(display_0x5607e7cb38c0, glxDrawable_400000b, Context_uid_4);

    // Create TransformFeedback_uid_5
    TransformFeedback_uid_5 = 0;

    // Create VertexArray_uid_6
    VertexArray_uid_6 = 0;

    // Create VertexArray_uid_15
    NV_EXEC_GL(glGenVertexArrays(1, &VertexArray_uid_15));
}

//-----------------------------------------------------------------------------
// OnBeforeWinResourcesInit00
//-----------------------------------------------------------------------------
void OnBeforeWinResourcesInit00()
{
    BEGIN_DATA_SCOPE_FUNCTION();

    InitFunctions_GLX();
}

//-----------------------------------------------------------------------------
// CreateWinResources00
//-----------------------------------------------------------------------------
void CreateWinResources00()
{
    BEGIN_DATA_SCOPE_FUNCTION();

    WindowSystemInstance().CreateDisplay();
    display_0x5607e7cb38c0 = (*reinterpret_cast<Display**>(WindowSystemInstance().GetDisplayAddr()));
    glxFBConfig_0 = 0;
    int int_temp_2 = 0;
    static GLXFBConfig* pGLXFBConfig_temp_1 = NULL;
    pGLXFBConfig_temp_1 = glXGetFBConfigs(display_0x5607e7cb38c0, DefaultScreen(display_0x5607e7cb38c0), &int_temp_2);
    NV_THROW_IF(int_temp_2 == 0, "Failed to choose GLX FBconfig. Note that configs might not be compatible across different software versions.");
    glxFBConfig_0x5607e7d20350 = pGLXFBConfig_temp_1[0];

    static int int_temp_3[63] = { 
        GLX_FBCONFIG_ID, 0x0107, GLX_BUFFER_SIZE, 0x0020, GLX_LEVEL, 0x0000, GLX_DOUBLEBUFFER, GLX_WINDOW_BIT, 
        GLX_STEREO, 0x0000, GLX_AUX_BUFFERS, 0x0004, GLX_RED_SIZE, 0x0008, GLX_GREEN_SIZE, 0x0008, 
        GLX_BLUE_SIZE, 0x0008, GLX_ALPHA_SIZE, 0x0008, GLX_DEPTH_SIZE, 0x0018, GLX_STENCIL_SIZE, 0x0008, 
        GLX_ACCUM_RED_SIZE, 0x0010, GLX_ACCUM_GREEN_SIZE, 0x0010, GLX_ACCUM_BLUE_SIZE, 0x0010, GLX_ACCUM_ALPHA_SIZE, 0x0010, 
        GLX_RENDER_TYPE, GLX_WINDOW_BIT, GLX_DRAWABLE_TYPE, 0x0007, GLX_X_RENDERABLE, GLX_WINDOW_BIT, 0x800b, 0x0024, 
        GLX_X_VISUAL_TYPE, 0x8002, GLX_CONFIG_CAVEAT, GLX_NONE, GLX_TRANSPARENT_TYPE, GLX_NONE, GLX_TRANSPARENT_INDEX_VALUE, 0x0000, 
        GLX_TRANSPARENT_RED_VALUE, 0x0000, GLX_TRANSPARENT_GREEN_VALUE, 0x0000, GLX_TRANSPARENT_BLUE_VALUE, 0x0000, GLX_TRANSPARENT_ALPHA_VALUE, 0x0000, 
        0x8016, 0x4000, 0x8017, 0x4000, 0x8018, 0x10000000, 0x0000 };

    GLXFBConfig GLXFBConfig_temp_1 = GLXChooseConfig(display_0x5607e7cb38c0, int_temp_3, pGLXFBConfig_temp_1, int_temp_2);
    glxFBConfig_0x5607e7d20350 = (GLXFBConfig_temp_1 ? GLXFBConfig_temp_1 : glxFBConfig_0x5607e7d20350);
    {
        BEGIN_DATA_SCOPE();

        auto windowData = std::make_tuple(&glxFBConfig_0x5607e7d20350, nullptr, 0);
        WindowSystemInstance().CreateNativeWindow(&windowData, 1280, 1023);
        glxDrawable_400000b = (*reinterpret_cast<GLXDrawable*>(WindowSystemInstance().GetWindowAddr()));
    }
}

//-----------------------------------------------------------------------------
// OnAfterWinResourcesInit00
//-----------------------------------------------------------------------------
void OnAfterWinResourcesInit00()
{
    BEGIN_DATA_SCOPE_FUNCTION();

    InitFunctions_GL();
}

//-----------------------------------------------------------------------------
// ReleaseResources00
//-----------------------------------------------------------------------------
void ReleaseResources00()
{
    BEGIN_DATA_SCOPE_FUNCTION();

    // Switch to staging context
    NV_EXEC_GL(glFinish());
    glXMakeCurrent(display_0x5607e7cb38c0, glxDrawable_400000b, Context_uid_4_Staging);

    // Release Texture_uid_27
    NV_EXEC_GL(glDeleteTextures(1, &Texture_uid_27));

    // Release Texture_uid_25
    NV_EXEC_GL(glDeleteTextures(1, &Texture_uid_25));

    // Release Texture_uid_23
    NV_EXEC_GL(glDeleteTextures(1, &Texture_uid_23));

    // Release Texture_uid_21
    NV_EXEC_GL(glDeleteTextures(1, &Texture_uid_21));

    // Release Texture_uid_19
    NV_EXEC_GL(glDeleteTextures(1, &Texture_uid_19));

    // Release Buffer_uid_18
    NV_EXEC_GL(glDeleteBuffers(1, &Buffer_uid_18));

    // Release Buffer_uid_17
    NV_EXEC_GL(glDeleteBuffers(1, &Buffer_uid_17));

    // Release Buffer_uid_16
    NV_EXEC_GL(glDeleteBuffers(1, &Buffer_uid_16));

    // Release Program_uid_14
    NV_EXEC_GL(glDeleteProgram(Program_uid_14));

    // Switch to rendering context
    NV_EXEC_GL(glFinish());
    glXMakeCurrent(display_0x5607e7cb38c0, glxDrawable_400000b, Context_uid_4);

    // Release VertexArray_uid_15
    NV_EXEC_GL(glDeleteVertexArrays(1, &VertexArray_uid_15));

    // Release TransformFeedback_uid_5
    NV_EXEC_GL(glDeleteTransformFeedbacks(1, &TransformFeedback_uid_5));

    // Release Context_uid_4 and its staging resource
    glXDestroyContext(display_0x5607e7cb38c0, Context_uid_4);
    glXDestroyContext(display_0x5607e7cb38c0, Context_uid_4_Staging);
}

//-----------------------------------------------------------------------------
// ReleaseWinResources00
//-----------------------------------------------------------------------------
void ReleaseWinResources00()
{
    BEGIN_DATA_SCOPE_FUNCTION();

    WindowSystemInstance().DestroyWindow(&glxDrawable_400000b);
    WindowSystemInstance().DestroyDisplay();
}

//-----------------------------------------------------------------------------
// OnAfterWinResourcesReleased00
//-----------------------------------------------------------------------------
void OnAfterWinResourcesReleased00()
{
    BEGIN_DATA_SCOPE_FUNCTION();

    DeInitFunctions_GL();
    DeInitFunctions_GLX();
}

//-----------------------------------------------------------------------------
// Captured Resources
//-----------------------------------------------------------------------------
GLXFBConfig glxFBConfig_0;
Uniform Uniform_prog_284_loc_9;
Uniform Uniform_prog_284_loc_8;
Uniform Uniform_prog_284_loc_7;
Uniform Uniform_prog_284_loc_6;
Uniform Uniform_prog_284_loc_5;
Uniform Uniform_prog_284_loc_4;
Uniform Uniform_prog_284_loc_3;
Uniform Uniform_prog_284_loc_2;
Uniform Uniform_prog_284_loc_1;
Uniform Uniform_prog_284_loc_0;
Context Context_uid_4;
TransformFeedback TransformFeedback_uid_5;
VertexArray VertexArray_uid_6;
Program Program_uid_14;
VertexArray VertexArray_uid_15;
Buffer Buffer_uid_16;
Buffer Buffer_uid_17;
Buffer Buffer_uid_18;
Texture Texture_uid_19;
Texture Texture_uid_21;
Texture Texture_uid_23;
Texture Texture_uid_25;
Texture Texture_uid_27;
GLXDrawable glxDrawable_400000b;
Display* display_0x5607e7cb38c0 = NULL;
GLXFBConfig glxFBConfig_0x5607e7d20350;
Context Context_uid_4_Staging;
