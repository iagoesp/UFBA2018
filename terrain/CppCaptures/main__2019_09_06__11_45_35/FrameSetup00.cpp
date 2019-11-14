//-----------------------------------------------------------------------------
// Generated with NVIDIA Nsight Graphics 2019.3.0.0
// 
// File: FrameSetup00.cpp
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
// SetInitialFrameState00
//-----------------------------------------------------------------------------
void SetInitialFrameState00()
{
    BEGIN_DATA_SCOPE_FUNCTION();

    // Switch to staging context
    NV_EXEC_GL(glFinish());
    glXMakeCurrent(display_0x5607e7cb38c0, glxDrawable_400000b, Context_uid_4_Staging);

    // Buffer_uidof_16
    {
        BEGIN_DATA_SCOPE();

        NV_EXEC_GL(glBindBuffer(GL_COPY_WRITE_BUFFER, Buffer_uid_16));
        NV_EXEC_GL(glBufferData(GL_COPY_WRITE_BUFFER, 13068, NV_GET_RESOURCE(GLvoid*, 0), GL_STATIC_DRAW));
    }

    NV_CHECK_INIT(Buffer_uid_16);

    // Buffer_uidof_17
    {
        BEGIN_DATA_SCOPE();

        NV_EXEC_GL(glBindBuffer(GL_COPY_WRITE_BUFFER, Buffer_uid_17));
        NV_EXEC_GL(glBufferData(GL_COPY_WRITE_BUFFER, 12288, NV_GET_RESOURCE(GLvoid*, 1), GL_STATIC_DRAW));
    }

    NV_CHECK_INIT(Buffer_uid_17);

    // Buffer_uidof_18
    {
        BEGIN_DATA_SCOPE();

        NV_EXEC_GL(glBindBuffer(GL_COPY_WRITE_BUFFER, Buffer_uid_18));
        NV_EXEC_GL(glBufferData(GL_COPY_WRITE_BUFFER, 8712, NV_GET_RESOURCE(GLvoid*, 2), GL_STATIC_DRAW));
    }

    NV_CHECK_INIT(Buffer_uid_18);

    // Program_uidof_14
    {
        BEGIN_DATA_SCOPE();

        // Create new temp shader
        static GLuint GLuint_temp_5 = glCreateShader(GL_VERTEX_SHADER);
        NV_THROW_IF(!GLuint_temp_5, "Failed to create shader");
        {
            BEGIN_DATA_SCOPE();

            auto blobProxy = GetDatabase().Read<const GLchar*>({3});

            static const GLchar* pconstGLchar_temp_5 = blobProxy.Get();
            static const GLint constGLint_temp_5 = 6400ull;
            NV_EXEC_GL(glShaderSource(GLuint_temp_5, 1, &pconstGLchar_temp_5, &constGLint_temp_5));
        }

        NV_EXEC_GL(glCompileShader(GLuint_temp_5));

        static GLint GLint_temp_6 = GL_ZERO;
        NV_EXEC_GL(glGetShaderiv(GLuint_temp_5, GL_COMPILE_STATUS, &GLint_temp_6));

        NV_THROW_IF(!GLint_temp_6, "Failed to compile shader");
        NV_EXEC_GL(glAttachShader(Program_uid_14, GLuint_temp_5));

        // Create new temp shader
        static GLuint GLuint_temp_6 = glCreateShader(GL_TESS_CONTROL_SHADER);
        NV_THROW_IF(!GLuint_temp_6, "Failed to create shader");
        {
            BEGIN_DATA_SCOPE();

            auto blobProxy = GetDatabase().Read<const GLchar*>({4});

            static const GLchar* pconstGLchar_temp_6 = blobProxy.Get();
            static const GLint constGLint_temp_6 = 1736ull;
            NV_EXEC_GL(glShaderSource(GLuint_temp_6, 1, &pconstGLchar_temp_6, &constGLint_temp_6));
        }

        NV_EXEC_GL(glCompileShader(GLuint_temp_6));

        static GLint GLint_temp_7 = GL_ZERO;
        NV_EXEC_GL(glGetShaderiv(GLuint_temp_6, GL_COMPILE_STATUS, &GLint_temp_7));

        NV_THROW_IF(!GLint_temp_7, "Failed to compile shader");
        NV_EXEC_GL(glAttachShader(Program_uid_14, GLuint_temp_6));

        // Create new temp shader
        static GLuint GLuint_temp_7 = glCreateShader(GL_TESS_EVALUATION_SHADER);
        NV_THROW_IF(!GLuint_temp_7, "Failed to create shader");
        {
            BEGIN_DATA_SCOPE();

            auto blobProxy = GetDatabase().Read<const GLchar*>({5});

            static const GLchar* pconstGLchar_temp_7 = blobProxy.Get();
            static const GLint constGLint_temp_7 = 3608ull;
            NV_EXEC_GL(glShaderSource(GLuint_temp_7, 1, &pconstGLchar_temp_7, &constGLint_temp_7));
        }

        NV_EXEC_GL(glCompileShader(GLuint_temp_7));

        static GLint GLint_temp_8 = GL_ZERO;
        NV_EXEC_GL(glGetShaderiv(GLuint_temp_7, GL_COMPILE_STATUS, &GLint_temp_8));

        NV_THROW_IF(!GLint_temp_8, "Failed to compile shader");
        NV_EXEC_GL(glAttachShader(Program_uid_14, GLuint_temp_7));

        // Create new temp shader
        static GLuint GLuint_temp_8 = glCreateShader(GL_FRAGMENT_SHADER);
        NV_THROW_IF(!GLuint_temp_8, "Failed to create shader");
        {
            BEGIN_DATA_SCOPE();

            auto blobProxy = GetDatabase().Read<const GLchar*>({6});

            static const GLchar* pconstGLchar_temp_8 = blobProxy.Get();
            static const GLint constGLint_temp_8 = 10714ull;
            NV_EXEC_GL(glShaderSource(GLuint_temp_8, 1, &pconstGLchar_temp_8, &constGLint_temp_8));
        }

        NV_EXEC_GL(glCompileShader(GLuint_temp_8));

        static GLint GLint_temp_9 = GL_ZERO;
        NV_EXEC_GL(glGetShaderiv(GLuint_temp_8, GL_COMPILE_STATUS, &GLint_temp_9));

        NV_THROW_IF(!GLint_temp_9, "Failed to compile shader");
        NV_EXEC_GL(glAttachShader(Program_uid_14, GLuint_temp_8));

        // Set linked bound attribute locations
        {
            BEGIN_DATA_SCOPE();

            NV_EXEC_GL(glBindAttribLocation(Program_uid_14, 2u, "aTexCoord"));
            NV_EXEC_GL(glBindAttribLocation(Program_uid_14, 0u, "position"));
        }

        // Switch to rendering context
        glXMakeCurrent(display_0x5607e7cb38c0, glxDrawable_400000b, Context_uid_4);
        NV_EXEC_GL(glLinkProgram(Program_uid_14));

        // Switch to staging context
        NV_EXEC_GL(glFinish());
        glXMakeCurrent(display_0x5607e7cb38c0, glxDrawable_400000b, Context_uid_4_Staging);

        static GLint GLint_temp_10 = GL_ZERO;
        NV_EXEC_GL(glGetProgramiv(Program_uid_14, GL_LINK_STATUS, &GLint_temp_10));

        NV_THROW_IF(!GLint_temp_10, "Failed to link program Program_uid_14");

        // Detach and destroy temp shaders
        {
            BEGIN_DATA_SCOPE();

            NV_EXEC_GL(glDetachShader(Program_uid_14, GLuint_temp_5));
            NV_EXEC_GL(glDeleteShader(GLuint_temp_5));
            NV_EXEC_GL(glDetachShader(Program_uid_14, GLuint_temp_6));
            NV_EXEC_GL(glDeleteShader(GLuint_temp_6));
            NV_EXEC_GL(glDetachShader(Program_uid_14, GLuint_temp_7));
            NV_EXEC_GL(glDeleteShader(GLuint_temp_7));
            NV_EXEC_GL(glDetachShader(Program_uid_14, GLuint_temp_8));
            NV_EXEC_GL(glDeleteShader(GLuint_temp_8));
        }

        // Query program variable locations
        {
            BEGIN_DATA_SCOPE();

            // Query uniforms for Program_uidof_14
            {
                BEGIN_DATA_SCOPE();

                Uniform_prog_284_loc_0 = glGetUniformLocation(Program_uid_14, "MVP");
                Uniform_prog_284_loc_1 = glGetUniformLocation(Program_uid_14, "agua");
                Uniform_prog_284_loc_2 = glGetUniformLocation(Program_uid_14, "frag");
                Uniform_prog_284_loc_3 = glGetUniformLocation(Program_uid_14, "grama");
                Uniform_prog_284_loc_4 = glGetUniformLocation(Program_uid_14, "mesh");
                Uniform_prog_284_loc_5 = glGetUniformLocation(Program_uid_14, "montanha");
                Uniform_prog_284_loc_6 = glGetUniformLocation(Program_uid_14, "neve");
                Uniform_prog_284_loc_7 = glGetUniformLocation(Program_uid_14, "terra");
                Uniform_prog_284_loc_8 = glGetUniformLocation(Program_uid_14, "tess");
                Uniform_prog_284_loc_9 = glGetUniformLocation(Program_uid_14, "viewPos");
            }
        }

        // Set uniform values
        {
            BEGIN_DATA_SCOPE();

            NV_EXEC_GL(glUseProgram(Program_uid_14));

            static GLfloat GLfloat_temp_4[16] = { 
                HexToFloat(0x3FF73729/*1.93137f*/), 0.0f, 0.0f, 0.0f, 0.0f, HexToFloat(0x401A8279/*2.41421f*/), 0.0f, 0.0f, 
                0.0f, 0.0f, HexToFloat(0xBF80068D/*-1.0002f*/), HexToFloat(0xBF800000/*-1.0f*/), HexToFloat(0xC310DA52/*-144.853f*/), HexToFloat(0xC210DA51/*-36.2132f*/), HexToFloat(0x4295A144/*74.815f*/), HexToFloat(0x42960000/*75.0f*/)
            };
            NV_EXEC_GL(glUniformMatrix4fv(Uniform_prog_284_loc_0, 1, GL_ZERO, GLfloat_temp_4));

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

    NV_CHECK_INIT(Program_uid_14);

    // Texture_uidof_19
    {
        BEGIN_DATA_SCOPE();

        NV_EXEC_GL(glActiveTexture(GL_TEXTURE0));
        NV_EXEC_GL(glBindTexture(GL_TEXTURE_2D, Texture_uid_19));
        NV_EXEC_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
    }

    // Data for Texture_uidof_19
    {
        BEGIN_DATA_SCOPE();

        NV_EXEC_GL(glActiveTexture(GL_TEXTURE0));
        NV_EXEC_GL(glBindTexture(GL_TEXTURE_2D, Texture_uid_19));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 0u, GL_RGB, 512, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 7)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 1u, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 8)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 2u, GL_RGB, 128, 128, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 9)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 3u, GL_RGB, 64, 64, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 10)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 4u, GL_RGB, 32, 32, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 11)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 5u, GL_RGB, 16, 16, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 12)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 6u, GL_RGB, 8, 8, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 13)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 7u, GL_RGB, 4, 4, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 14)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 8u, GL_RGB, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 15)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 9u, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 16)));
        NV_EXEC_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0u));
        NV_EXEC_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1000u));
    }

    NV_CHECK_INIT(Texture_uid_19);

    // Texture_uidof_21
    {
        BEGIN_DATA_SCOPE();

        NV_EXEC_GL(glActiveTexture(GL_TEXTURE0));
        NV_EXEC_GL(glBindTexture(GL_TEXTURE_2D, Texture_uid_21));
        NV_EXEC_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
    }

    // Data for Texture_uidof_21
    {
        BEGIN_DATA_SCOPE();

        NV_EXEC_GL(glActiveTexture(GL_TEXTURE0));
        NV_EXEC_GL(glBindTexture(GL_TEXTURE_2D, Texture_uid_21));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 0u, GL_RGB, 1024, 1024, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 17)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 1u, GL_RGB, 512, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 18)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 2u, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 19)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 3u, GL_RGB, 128, 128, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 20)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 4u, GL_RGB, 64, 64, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 21)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 5u, GL_RGB, 32, 32, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 22)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 6u, GL_RGB, 16, 16, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 23)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 7u, GL_RGB, 8, 8, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 24)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 8u, GL_RGB, 4, 4, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 25)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 9u, GL_RGB, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 26)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 10u, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 27)));
        NV_EXEC_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0u));
        NV_EXEC_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1000u));
    }

    NV_CHECK_INIT(Texture_uid_21);

    // Texture_uidof_23
    {
        BEGIN_DATA_SCOPE();

        NV_EXEC_GL(glActiveTexture(GL_TEXTURE0));
        NV_EXEC_GL(glBindTexture(GL_TEXTURE_2D, Texture_uid_23));
        NV_EXEC_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
    }

    // Data for Texture_uidof_23
    {
        BEGIN_DATA_SCOPE();

        NV_EXEC_GL(glActiveTexture(GL_TEXTURE0));
        NV_EXEC_GL(glBindTexture(GL_TEXTURE_2D, Texture_uid_23));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 0u, GL_RGB, 1300, 1300, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 28)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 1u, GL_RGB, 650, 650, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 29)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 2u, GL_RGB, 325, 325, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 30)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 3u, GL_RGB, 162, 162, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 31)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 4u, GL_RGB, 81, 81, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 32)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 5u, GL_RGB, 40, 40, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 33)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 6u, GL_RGB, 20, 20, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 34)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 7u, GL_RGB, 10, 10, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 35)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 8u, GL_RGB, 5, 5, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 36)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 9u, GL_RGB, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 37)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 10u, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 38)));
        NV_EXEC_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0u));
        NV_EXEC_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1000u));
    }

    NV_CHECK_INIT(Texture_uid_23);

    // Texture_uidof_25
    {
        BEGIN_DATA_SCOPE();

        NV_EXEC_GL(glActiveTexture(GL_TEXTURE0));
        NV_EXEC_GL(glBindTexture(GL_TEXTURE_2D, Texture_uid_25));
        NV_EXEC_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
    }

    // Data for Texture_uidof_25
    {
        BEGIN_DATA_SCOPE();

        NV_EXEC_GL(glActiveTexture(GL_TEXTURE0));
        NV_EXEC_GL(glBindTexture(GL_TEXTURE_2D, Texture_uid_25));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 0u, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 39)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 1u, GL_RGB, 128, 128, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 40)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 2u, GL_RGB, 64, 64, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 41)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 3u, GL_RGB, 32, 32, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 42)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 4u, GL_RGB, 16, 16, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 43)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 5u, GL_RGB, 8, 8, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 44)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 6u, GL_RGB, 4, 4, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 45)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 7u, GL_RGB, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 46)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 8u, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 47)));
        NV_EXEC_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0u));
        NV_EXEC_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1000u));
    }

    NV_CHECK_INIT(Texture_uid_25);

    // Data for Texture_uidof_27
    {
        BEGIN_DATA_SCOPE();

        NV_EXEC_GL(glActiveTexture(GL_TEXTURE0));
        NV_EXEC_GL(glBindTexture(GL_TEXTURE_2D, Texture_uid_27));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 0u, GL_RGB, 512, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 48)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 1u, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 49)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 2u, GL_RGB, 128, 128, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 50)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 3u, GL_RGB, 64, 64, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 51)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 4u, GL_RGB, 32, 32, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 52)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 5u, GL_RGB, 16, 16, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 53)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 6u, GL_RGB, 8, 8, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 54)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 7u, GL_RGB, 4, 4, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 55)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 8u, GL_RGB, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 56)));
        NV_EXEC_GL(glTexImage2D(GL_TEXTURE_2D, 9u, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, NV_GET_RESOURCE(GLvoid*, 57)));
        NV_EXEC_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0u));
        NV_EXEC_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1000u));
    }

    NV_CHECK_INIT(Texture_uid_27);

    // Switch to rendering context
    NV_EXEC_GL(glFinish());
    glXMakeCurrent(display_0x5607e7cb38c0, glxDrawable_400000b, Context_uid_4);
    NV_CHECK_INIT(TransformFeedback_uid_5);
    NV_CHECK_INIT(VertexArray_uid_6);

    // VertexArray_uidof_15
    {
        BEGIN_DATA_SCOPE();

        NV_EXEC_GL(glBindVertexArray(VertexArray_uid_15));
        NV_EXEC_GL(glBindBuffer(GL_ARRAY_BUFFER, Buffer_uid_16));
        NV_EXEC_GL(glVertexAttribPointer(0u, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0));
        NV_EXEC_GL(glVertexAttribPointer(1u, 3, GL_FLOAT, GL_FALSE, 32, (GLvoid*)0xc));
        NV_EXEC_GL(glBindBuffer(GL_ARRAY_BUFFER, Buffer_uid_18));
        NV_EXEC_GL(glVertexAttribPointer(2u, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0));
        NV_EXEC_GL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Buffer_uid_17));
    }

    NV_CHECK_INIT(VertexArray_uid_15);

    // OpenGL_Context_uidof_4
    {
        BEGIN_DATA_SCOPE();

        // Patch
        {
            BEGIN_DATA_SCOPE();

            glPatchParameteri(GL_PATCH_VERTICES, 3);

            static float float_temp_3[4] = { HexToFloat(0x3F800000/*1.0f*/), HexToFloat(0x3F800000/*1.0f*/), HexToFloat(0x3F800000/*1.0f*/), HexToFloat(0x3F800000/*1.0f*/) };
            glPatchParameterfv(GL_PATCH_DEFAULT_OUTER_LEVEL, float_temp_3);

            static float float_temp_4[2] = { HexToFloat(0x3F800000/*1.0f*/), HexToFloat(0x3F800000/*1.0f*/) };
            glPatchParameterfv(GL_PATCH_DEFAULT_INNER_LEVEL, float_temp_4);
        }

        // Vertex Array
        {
            BEGIN_DATA_SCOPE();

            glBindBuffer(GL_ARRAY_BUFFER, Buffer_uid_18);
            glBindVertexArray(VertexArray_uid_15);
            glBindBuffer(GL_PARAMETER_BUFFER, 0);
            glDisable(GL_PRIMITIVE_RESTART);
            glPrimitiveRestartIndex(0);
            glDisable(GL_PRIMITIVE_RESTART_FIXED_INDEX);
        }

        // Transformation
        {
            BEGIN_DATA_SCOPE();

            glViewportIndexedf(0, 0.0f, 0.0f, HexToFloat(0x44A00000/*1280.0f*/), HexToFloat(0x447FC000/*1023.0f*/));
            glDepthRangeIndexed(0, 0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glViewportIndexedf(1, 0.0f, 0.0f, HexToFloat(0x44A00000/*1280.0f*/), HexToFloat(0x447FC000/*1023.0f*/));
            glDepthRangeIndexed(1, 0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glViewportIndexedf(2, 0.0f, 0.0f, HexToFloat(0x44A00000/*1280.0f*/), HexToFloat(0x447FC000/*1023.0f*/));
            glDepthRangeIndexed(2, 0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glViewportIndexedf(3, 0.0f, 0.0f, HexToFloat(0x44A00000/*1280.0f*/), HexToFloat(0x447FC000/*1023.0f*/));
            glDepthRangeIndexed(3, 0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glViewportIndexedf(4, 0.0f, 0.0f, HexToFloat(0x44A00000/*1280.0f*/), HexToFloat(0x447FC000/*1023.0f*/));
            glDepthRangeIndexed(4, 0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glViewportIndexedf(5, 0.0f, 0.0f, HexToFloat(0x44A00000/*1280.0f*/), HexToFloat(0x447FC000/*1023.0f*/));
            glDepthRangeIndexed(5, 0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glViewportIndexedf(6, 0.0f, 0.0f, HexToFloat(0x44A00000/*1280.0f*/), HexToFloat(0x447FC000/*1023.0f*/));
            glDepthRangeIndexed(6, 0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glViewportIndexedf(7, 0.0f, 0.0f, HexToFloat(0x44A00000/*1280.0f*/), HexToFloat(0x447FC000/*1023.0f*/));
            glDepthRangeIndexed(7, 0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glViewportIndexedf(8, 0.0f, 0.0f, HexToFloat(0x44A00000/*1280.0f*/), HexToFloat(0x447FC000/*1023.0f*/));
            glDepthRangeIndexed(8, 0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glViewportIndexedf(9, 0.0f, 0.0f, HexToFloat(0x44A00000/*1280.0f*/), HexToFloat(0x447FC000/*1023.0f*/));
            glDepthRangeIndexed(9, 0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glViewportIndexedf(10, 0.0f, 0.0f, HexToFloat(0x44A00000/*1280.0f*/), HexToFloat(0x447FC000/*1023.0f*/));
            glDepthRangeIndexed(10, 0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glViewportIndexedf(11, 0.0f, 0.0f, HexToFloat(0x44A00000/*1280.0f*/), HexToFloat(0x447FC000/*1023.0f*/));
            glDepthRangeIndexed(11, 0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glViewportIndexedf(12, 0.0f, 0.0f, HexToFloat(0x44A00000/*1280.0f*/), HexToFloat(0x447FC000/*1023.0f*/));
            glDepthRangeIndexed(12, 0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glViewportIndexedf(13, 0.0f, 0.0f, HexToFloat(0x44A00000/*1280.0f*/), HexToFloat(0x447FC000/*1023.0f*/));
            glDepthRangeIndexed(13, 0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glViewportIndexedf(14, 0.0f, 0.0f, HexToFloat(0x44A00000/*1280.0f*/), HexToFloat(0x447FC000/*1023.0f*/));
            glDepthRangeIndexed(14, 0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glViewportIndexedf(15, 0.0f, 0.0f, HexToFloat(0x44A00000/*1280.0f*/), HexToFloat(0x447FC000/*1023.0f*/));
            glDepthRangeIndexed(15, 0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glDisable(GL_CLIP_DISTANCE0);
            glDisable(GL_CLIP_DISTANCE1);
            glDisable(GL_CLIP_DISTANCE2);
            glDisable(GL_CLIP_DISTANCE3);
            glDisable(GL_CLIP_DISTANCE4);
            glDisable(GL_CLIP_DISTANCE5);
            glDisable(GL_CLIP_DISTANCE0+6);
            glDisable(GL_CLIP_DISTANCE0+7);
            glDisable(GL_DEPTH_CLAMP);
            glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, TransformFeedback_uid_5);
            glClipControl(36001u, 37726u);
        }

        // Coloring
        {
            BEGIN_DATA_SCOPE();

            glClampColor(GL_CLAMP_READ_COLOR, GL_FIXED_ONLY);
            glProvokingVertex(GL_LAST_VERTEX_CONVENTION);
        }

        // Rasterization
        {
            BEGIN_DATA_SCOPE();

            glDisable(GL_RASTERIZER_DISCARD);
            glPointSize(HexToFloat(0x3F800000/*1.0f*/));
            glPointParameterf(GL_POINT_FADE_THRESHOLD_SIZE, HexToFloat(0x3F800000/*1.0f*/));
            glPointParameteri(GL_POINT_SPRITE_COORD_ORIGIN, GL_UPPER_LEFT);
            glLineWidth(HexToFloat(0x3F800000/*1.0f*/));
            glDisable(GL_LINE_SMOOTH);
            glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
            glFrontFace(GL_CCW);
            glDisable(GL_POLYGON_SMOOTH);
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glPolygonOffset(0.0f, 0.0f);
            glDisable(GL_POLYGON_OFFSET_POINT);
            glDisable(GL_POLYGON_OFFSET_LINE);
            glDisable(GL_POLYGON_OFFSET_FILL);

            // Extension
            {
                BEGIN_DATA_SCOPE();

                glPolygonOffsetClampEXT(0.0f, 0.0f, 0.0f);
            }
        }

        // Multisampling
        {
            BEGIN_DATA_SCOPE();

            glEnable(GL_MULTISAMPLE);
            glDisable(GL_SAMPLE_ALPHA_TO_COVERAGE);
            glDisable(GL_SAMPLE_ALPHA_TO_ONE);
            glDisable(GL_SAMPLE_COVERAGE);
            glSampleCoverage(HexToFloat(0x3F800000/*1.0f*/), 0);
            glDisable(GL_SAMPLE_SHADING);
            glMinSampleShadingARB(0.0f);
            glDisable(GL_SAMPLE_MASK);
            glSampleMaski(0, 0xFFFFFFFFu);
            glSampleMaski(1, 0xFFFFFFFFu);
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

        // Texture
        {
            BEGIN_DATA_SCOPE();

            glActiveTexture(GL_TEXTURE4);
        }

        // Pixel Operations
        {
            BEGIN_DATA_SCOPE();

            glDisablei(GL_SCISSOR_TEST, 0);
            glScissorIndexed(0, 0, 0, 1280, 1024);
            glDisablei(GL_SCISSOR_TEST, 1);
            glScissorIndexed(1, 0, 0, 1280, 1024);
            glDisablei(GL_SCISSOR_TEST, 2);
            glScissorIndexed(2, 0, 0, 1280, 1024);
            glDisablei(GL_SCISSOR_TEST, 3);
            glScissorIndexed(3, 0, 0, 1280, 1024);
            glDisablei(GL_SCISSOR_TEST, 4);
            glScissorIndexed(4, 0, 0, 1280, 1024);
            glDisablei(GL_SCISSOR_TEST, 5);
            glScissorIndexed(5, 0, 0, 1280, 1024);
            glDisablei(GL_SCISSOR_TEST, 6);
            glScissorIndexed(6, 0, 0, 1280, 1024);
            glDisablei(GL_SCISSOR_TEST, 7);
            glScissorIndexed(7, 0, 0, 1280, 1024);
            glDisablei(GL_SCISSOR_TEST, 8);
            glScissorIndexed(8, 0, 0, 1280, 1024);
            glDisablei(GL_SCISSOR_TEST, 9);
            glScissorIndexed(9, 0, 0, 1280, 1024);
            glDisablei(GL_SCISSOR_TEST, 10);
            glScissorIndexed(10, 0, 0, 1280, 1024);
            glDisablei(GL_SCISSOR_TEST, 11);
            glScissorIndexed(11, 0, 0, 1280, 1024);
            glDisablei(GL_SCISSOR_TEST, 12);
            glScissorIndexed(12, 0, 0, 1280, 1024);
            glDisablei(GL_SCISSOR_TEST, 13);
            glScissorIndexed(13, 0, 0, 1280, 1024);
            glDisablei(GL_SCISSOR_TEST, 14);
            glScissorIndexed(14, 0, 0, 1280, 1024);
            glDisablei(GL_SCISSOR_TEST, 15);
            glScissorIndexed(15, 0, 0, 1280, 1024);
            glDisable(GL_STENCIL_TEST);
            glStencilFuncSeparate(GL_FRONT, GL_ALWAYS, 0, -1);
            glStencilOpSeparate(GL_FRONT, GL_KEEP, GL_KEEP, GL_KEEP);
            glStencilFuncSeparate(GL_BACK, 519, 0, -1);
            glStencilOpSeparate(GL_BACK, GL_KEEP, GL_KEEP, GL_KEEP);
            glEnable(GL_DEPTH_TEST);
            glDisable(GL_DEPTH_BOUNDS_TEST_EXT);
            glDepthBoundsEXT(0.0, HexToDouble(0x3FF0000000000000/*1.0*/));
            glDepthFunc(GL_LESS);
            glDisablei(GL_BLEND, 0);
            glBlendEquationi(0, GL_FUNC_ADD);
            glBlendFuncSeparateiARB(0, GL_ONE, GL_ZERO, GL_ONE, GL_ZERO);
            glDisablei(GL_BLEND, 1);
            glBlendEquationi(1, GL_FUNC_ADD);
            glBlendFuncSeparateiARB(1, GL_ONE, GL_ZERO, GL_ONE, GL_ZERO);
            glDisablei(GL_BLEND, 2);
            glBlendEquationi(2, GL_FUNC_ADD);
            glBlendFuncSeparateiARB(2, GL_ONE, GL_ZERO, GL_ONE, GL_ZERO);
            glDisablei(GL_BLEND, 3);
            glBlendEquationi(3, GL_FUNC_ADD);
            glBlendFuncSeparateiARB(3, GL_ONE, GL_ZERO, GL_ONE, GL_ZERO);
            glDisablei(GL_BLEND, 4);
            glBlendEquationi(4, GL_FUNC_ADD);
            glBlendFuncSeparateiARB(4, GL_ONE, GL_ZERO, GL_ONE, GL_ZERO);
            glDisablei(GL_BLEND, 5);
            glBlendEquationi(5, GL_FUNC_ADD);
            glBlendFuncSeparateiARB(5, GL_ONE, GL_ZERO, GL_ONE, GL_ZERO);
            glDisablei(GL_BLEND, 6);
            glBlendEquationi(6, GL_FUNC_ADD);
            glBlendFuncSeparateiARB(6, GL_ONE, GL_ZERO, GL_ONE, GL_ZERO);
            glDisablei(GL_BLEND, 7);
            glBlendEquationi(7, GL_FUNC_ADD);
            glBlendFuncSeparateiARB(7, GL_ONE, GL_ZERO, GL_ONE, GL_ZERO);
            glBlendColor(0.0f, 0.0f, 0.0f, 0.0f);
            glDisable(GL_FRAMEBUFFER_SRGB);
            glEnable(GL_DITHER);
            glDisable(GL_COLOR_LOGIC_OP);
            glLogicOp(GL_COPY);
        }

        // Framebuffer Control
        {
            BEGIN_DATA_SCOPE();

            glColorMaski(0, 1, 1, 1, 1);
            glColorMaski(1, 1, 1, 1, 1);
            glColorMaski(2, 1, 1, 1, 1);
            glColorMaski(3, 1, 1, 1, 1);
            glColorMaski(4, 1, 1, 1, 1);
            glColorMaski(5, 1, 1, 1, 1);
            glColorMaski(6, 1, 1, 1, 1);
            glColorMaski(7, 1, 1, 1, 1);
            glDepthMask(GL_TRUE);
            glStencilMaskSeparate(GL_FRONT, -1);
            glStencilMaskSeparate(GL_BACK, -1);
            glClearColor(0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glClearDepth(HexToDouble(0x3FF0000000000000/*1.0*/));
            glClearStencil(0);
        }

        // Framebuffers
        {
            BEGIN_DATA_SCOPE();

            glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
            glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
        }

        // Pixels
        {
            BEGIN_DATA_SCOPE();

            glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
            glPixelStorei(GL_PACK_ALIGNMENT, 4);
            glPixelStorei(GL_UNPACK_SWAP_BYTES, 0);
            glPixelStorei(GL_UNPACK_LSB_FIRST, 0);
            glPixelStorei(GL_UNPACK_IMAGE_HEIGHT, 0);
            glPixelStorei(GL_UNPACK_SKIP_IMAGES, 0);
            glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
            glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
            glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
            glPixelStorei(GL_UNPACK_COMPRESSED_BLOCK_WIDTH, 0);
            glPixelStorei(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT, 0);
            glPixelStorei(GL_UNPACK_COMPRESSED_BLOCK_DEPTH, 0);
            glPixelStorei(GL_UNPACK_COMPRESSED_BLOCK_SIZE, 0);
            glPixelStorei(GL_PACK_SWAP_BYTES, 0);
            glPixelStorei(GL_PACK_LSB_FIRST, 0);
            glPixelStorei(GL_PACK_IMAGE_HEIGHT, 0);
            glPixelStorei(GL_PACK_SKIP_IMAGES, 0);
            glPixelStorei(GL_PACK_ROW_LENGTH, 0);
            glPixelStorei(GL_PACK_SKIP_ROWS, 0);
            glPixelStorei(GL_PACK_SKIP_PIXELS, 0);
            glPixelStorei(GL_PACK_COMPRESSED_BLOCK_WIDTH, 0);
            glPixelStorei(GL_PACK_COMPRESSED_BLOCK_HEIGHT, 0);
            glPixelStorei(GL_PACK_COMPRESSED_BLOCK_DEPTH, 0);
            glPixelStorei(GL_PACK_COMPRESSED_BLOCK_SIZE, 0);
        }

        // Program Bindings
        {
            BEGIN_DATA_SCOPE();

            glUseProgram(Program_uid_14);
            glBindProgramPipeline(0);
        }

        // Uniform Buffers
        {
            BEGIN_DATA_SCOPE();

            glDisableClientState(GL_UNIFORM_BUFFER_UNIFIED_NV);
        }

        // Vertex And Geometry Shader State
        {
            BEGIN_DATA_SCOPE();

            glVertexAttrib4f(0, 0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glVertexAttrib4f(1, 0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glVertexAttrib4f(2, 0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glVertexAttrib4f(3, 0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glVertexAttrib4f(4, 0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glVertexAttrib4f(5, 0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glVertexAttrib4f(6, 0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glVertexAttrib4f(7, 0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glVertexAttrib4f(8, 0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glVertexAttrib4f(9, 0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glVertexAttrib4f(10, 0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glVertexAttrib4f(11, 0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glVertexAttrib4f(12, 0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glVertexAttrib4f(13, 0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glVertexAttrib4f(14, 0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glVertexAttrib4f(15, 0.0f, 0.0f, 0.0f, HexToFloat(0x3F800000/*1.0f*/));
            glDisable(GL_VERTEX_PROGRAM_POINT_SIZE);
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

    NV_CHECK_INIT(Context_uid_4);
    FreeCachedMemory();
}
