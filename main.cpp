#define QuantText 5

#include <vector>
#include <iostream>
#include <string>
//#include "stb_image.h"

//////#include "filesystem.h"
#include "vectormath/vectormath.h"
#include <cstdlib>
// Include GLEW
#include <GL/glew.h>
#include "stb_image.h"
#include "SOIL.h"
//#include "SOIL.c"

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;
using namespace std;

#include "LoadShaders.hpp"
#include "controls.hpp"
extern glm::vec3 position;

bool adapt = true;
bool unif  = false;
bool geom = false;
static GLsizei IndexCount;
static float TessLevelInner;
static float TessLevelOuter;
GLuint allTextures[QuantText];
const char* filenames[QuantText] = {"container.jpg",
                                    "agua.jpg",
                                    "grama.jpg",
                                    "snow.jpg",
                                    "mountain.jpg"};


int main(int argv, char** argc){
    cout<<"Press J to get the Geometry Shader"<<endl;
    cout<<"Press K to get the Adapt Tessellation Shader"<<endl;
    cout<<"Press L to get the Uniform Tessellation Shader"<<endl;

    glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow( 1280, 1024, "IPSinewave_v6", NULL, NULL);
	if( window == NULL ){
    cout << "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		cout<<"Failed to initialize GLEW\n";
		glfwTerminate();
		return -1;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwPollEvents();
    glfwSetCursorPos(window, 1280/2, 1024/2);

	glClearColor(0.5f, 0.5f, 0.8f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	//glEnable(GL_CULL_FACE);
    //	if()
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	//GLuint programAdaptID = LoadShaders( "terrenofBm.vert","tessAdapt.frag");
    GLuint programAdaptID = LoadShaders( "terrenofBm.vert", "tessAdapt.tesc","tessAdapt.tese", "tessAdapt.frag");
    GLuint programGeomID  = LoadShaders( "terrenofBm.vert", "Geodesic.geom", "Geodesic.frag");
    GLuint programUnifID  = LoadShaders( "terrenofBm.vert", "tessUnif.tesc", "tessAdapt.tese", "tessAdapt.frag");



    GLuint MatrixID, ModelMatrixID, ViewMatrixID, ProjectionMatrixID,
    cameraPosIDX, cameraPosIDY, cameraPosIDZ, ampValue, octavesValue,
    lacunarityValue, LightID, TessLevelInnerID, TessLevelOuterID, TextureID, TextureID2, groundID, waterID, grassID, iceID, mountainID;


    vector<unsigned short> indices;
    const GLuint index = 10.0;
    const GLfloat meshSize = 80.0;
    float tamAmostra = meshSize / (float)index;
    for (GLuint i = 0 ; i < index ; i++){
		for (GLuint j = 0 ; j < index ; j++) {
			indices.push_back( i*(index+1) 		+ j);		// V0
			indices.push_back( i*(index+1) 		+ (j+1));	// V1
			indices.push_back( (i+1)*(index+1) 	+ j);		// V2

			indices.push_back( i*(index+1) 		+ (j+1));	// V1
			indices.push_back( (i+1)*(index+1) 	+ (j+1));	// V3
			indices.push_back( (i+1)*(index+1) 	+ j);		// V2
		}
	}

    float amp = 4.0;
    glm::vec3 lightPos = glm::vec3(4,4,4);
    int oct = rand() % 100; cout<<oct<<endl;
    float lac = rand() % 8; cout<<lac<<endl;
    vector<GLfloat> vertices;
    vector<GLfloat> texcoord;

    for (GLfloat i = 0 ; i <= index ; i+=1.0){
		for (GLfloat j = 0 ; j <= index ; j+=1.0) {
            vertices.push_back((float)(i*tamAmostra));
            vertices.push_back((float)(j*tamAmostra));
            texcoord.push_back((float)i);
            texcoord.push_back((float)j);
        }
	}

    IndexCount = sizeof(indices) / sizeof(indices[0]);

    // Create the VBO for positions:
    GLuint vertexbuffer;
    //GLsizei stride = 2 * sizeof(float);

    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

    // Create the VBO for indices:
    GLuint elementbuffer;
    glGenBuffers(1, &elementbuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), &indices[0], GL_STATIC_DRAW);

    GLuint texturebuffer;
    glGenBuffers(1, &texturebuffer);
    glBindBuffer(GL_ARRAY_BUFFER, texturebuffer);
    glBufferData(GL_ARRAY_BUFFER, texcoord.size() * sizeof(GLfloat), texcoord.data(), GL_STATIC_DRAW);


    glGenTextures(1, &allTextures[0]);

     // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char *textura1 = SOIL_load_image(filenames[0], &width, &height, &nrChannels, SOIL_LOAD_RGB);
    if (textura1)
    {
        glActiveTexture(GL_TEXTURE0 + 0);
        glBindTexture(GL_TEXTURE_2D, allTextures[0]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, textura1);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(textura1);

    glGenTextures(1, &allTextures[1]);

      // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char *data = SOIL_load_image(filenames[1], &width, &height, &nrChannels, SOIL_LOAD_RGB);
    if (data)
    {
        glActiveTexture(GL_TEXTURE0 + 1); // Texture unit 1
        glBindTexture(GL_TEXTURE_2D, allTextures[1]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    glGenTextures(1, &allTextures[2]);

      // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char *grama = SOIL_load_image(filenames[2], &width, &height, &nrChannels, SOIL_LOAD_RGB);
    if (grama)
    {
        glActiveTexture(GL_TEXTURE0 + 2); // Texture unit 1
        glBindTexture(GL_TEXTURE_2D, allTextures[2]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, grama);
        glGenerateMipmap(GL_TEXTURE_2D);

    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(grama);

    glGenTextures(1, &allTextures[3]);

      // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char *ice = SOIL_load_image(filenames[3], &width, &height, &nrChannels, SOIL_LOAD_RGB);
    if (ice)
    {
        glActiveTexture(GL_TEXTURE0 + 3); // Texture unit 1
        glBindTexture(GL_TEXTURE_2D, allTextures[3]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, ice);
        glGenerateMipmap(GL_TEXTURE_2D);

    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(ice);

    glGenTextures(1, &allTextures[4]);

      // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char *mountain = SOIL_load_image(filenames[4], &width, &height, &nrChannels, SOIL_LOAD_RGB);
    if (mountain)
    {
        glActiveTexture(GL_TEXTURE0 + 4); // Texture unit 1
        glBindTexture(GL_TEXTURE_2D, allTextures[4]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, mountain);
        glGenerateMipmap(GL_TEXTURE_2D);

    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(mountain);


    //GLuint normalbuffer;
    //glGenBuffers(1, &normalbuffer);
    //glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
//	glBufferData(GL_ARRAY_BUFFER, indexed_normals.size() * sizeof(glm::vec3), &indexed_normals[0], GL_STATIC_DRAW);


    // For speed computation
    TessLevelInner = 1.0f;
    TessLevelOuter = 4.0f;
    glm::vec3 camerapos = position;

    do{

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use our shader
        //glUseProgram(programAdaptID);
        if (glfwGetKey( window, GLFW_KEY_J ) == GLFW_PRESS){
            MatrixID             = glGetUniformLocation(programAdaptID, "MVP");
            ModelMatrixID        = glGetUniformLocation(programAdaptID, "M");
            ViewMatrixID         = glGetUniformLocation(programAdaptID, "V");
            ProjectionMatrixID   = glGetUniformLocation(programAdaptID, "P");
            cameraPosIDX         = glGetUniformLocation(programAdaptID, "px");
            cameraPosIDY         = glGetUniformLocation(programAdaptID, "py");
            cameraPosIDZ         = glGetUniformLocation(programAdaptID, "pz");
            ampValue             = glGetUniformLocation(programAdaptID, "amp");
            octavesValue         = glGetUniformLocation(programAdaptID, "oct");
            lacunarityValue      = glGetUniformLocation(programAdaptID, "lac");
            LightID              = glGetUniformLocation(programAdaptID, "LightPosition_worldspace");
            groundID = glGetUniformLocation(programAdaptID, "terra");
            waterID  = glGetUniformLocation(programAdaptID, "agua");
            grassID  = glGetUniformLocation(programAdaptID, "grama");
            iceID  = glGetUniformLocation(programAdaptID, "snow");
            mountainID  = glGetUniformLocation(programAdaptID, "mountain");
            glUseProgram(programAdaptID);
            adapt = true;
            unif = false;
            geom = false;
        }
        if (glfwGetKey( window, GLFW_KEY_K ) == GLFW_PRESS){
            MatrixID             = glGetUniformLocation(programUnifID, "MVP");
            ModelMatrixID        = glGetUniformLocation(programUnifID, "M");
            ViewMatrixID         = glGetUniformLocation(programUnifID, "V");
            ProjectionMatrixID   = glGetUniformLocation(programUnifID, "P");
            cameraPosIDX         = glGetUniformLocation(programUnifID, "px");
            cameraPosIDY         = glGetUniformLocation(programUnifID, "py");
            cameraPosIDZ         = glGetUniformLocation(programUnifID, "pz");
            ampValue             = glGetUniformLocation(programUnifID, "amp");
            octavesValue         = glGetUniformLocation(programUnifID, "oct");
            lacunarityValue      = glGetUniformLocation(programUnifID, "lac");
            LightID              = glGetUniformLocation(programUnifID, "LightPosition_worldspace");
           glUseProgram(programUnifID);
           adapt = false;
           unif = true;
           geom = false;
        }

        if (glfwGetKey( window, GLFW_KEY_L ) == GLFW_PRESS){
            MatrixID             = glGetUniformLocation(programGeomID, "MVP");
            ModelMatrixID        = glGetUniformLocation(programGeomID, "M");
            ViewMatrixID         = glGetUniformLocation(programGeomID, "V");
            ProjectionMatrixID   = glGetUniformLocation(programGeomID, "P");
            cameraPosIDX         = glGetUniformLocation(programGeomID, "px");
            cameraPosIDY         = glGetUniformLocation(programGeomID, "py");
            cameraPosIDZ         = glGetUniformLocation(programGeomID, "pz");
            ampValue             = glGetUniformLocation(programGeomID, "amp");
            octavesValue         = glGetUniformLocation(programGeomID, "oct");
            lacunarityValue      = glGetUniformLocation(programGeomID, "lac");
            LightID              = glGetUniformLocation(programGeomID, "LightPosition_worldspace");
           glUseProgram(programGeomID);
           adapt = false;
           unif = false;
           geom = true;
        }

        // Compute the MVP matrix from keyboard and mouse input
        computeMatricesFromInputs(window);
        glm::mat4 ProjectionMatrix = getProjectionMatrix();
        glm::mat4 ViewMatrix = getViewMatrix();
        glm::mat4 ModelMatrix = glm::mat4(1.0);
        glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

        // Send our transformation to the currently bound shader,
        // in the "MVP" uniform
        float px = position.x; float py = position.y; float pz = position.z;

               //cout<<"     min = "<<minnn<<" e max = "<<maxxx<<endl;
        if (glfwGetKey( window, GLFW_KEY_U ) == GLFW_PRESS){
           glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }
        if (glfwGetKey( window, GLFW_KEY_I ) == GLFW_PRESS){
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
        if (glfwGetKey( window, GLFW_KEY_O ) == GLFW_PRESS){
            glEnable(GL_CULL_FACE);
        }
        if (glfwGetKey( window, GLFW_KEY_P ) == GLFW_PRESS){
            glDisable(GL_CULL_FACE);
        }
        if (glfwGetKey( window, GLFW_KEY_M ) == GLFW_PRESS){
            oct = rand() % 7;
            cout<<oct<<endl;
        }
        if (glfwGetKey( window, GLFW_KEY_N ) == GLFW_PRESS){
            lac = rand() % 11;
            cout<<lac<<endl;
        }

        if(adapt){
            glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
            glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix[0][0]);
            glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &ViewMatrix[0][0]);
            glUniformMatrix4fv(ProjectionMatrixID, 1, GL_FALSE, &ProjectionMatrix[0][0]);
            glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);
            glUniform1f(cameraPosIDX, px);
            glUniform1f(cameraPosIDY, py);
            glUniform1f(cameraPosIDZ, pz);
            glUniform1f(ampValue,amp);
            glUniform1i(octavesValue,oct);
            glUniform1f(lacunarityValue,lac);
            glUniform1i(groundID, 0);
            glUniform1i(waterID,  1);
            glUniform1i(grassID, 2);
            glUniform1i(iceID, 3);
            glUniform1i(mountainID, 4);
        }
        else if(unif){
            glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
            glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix[0][0]);
            glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &ViewMatrix[0][0]);
            glUniformMatrix4fv(ProjectionMatrixID, 1, GL_FALSE, &ProjectionMatrix[0][0]);
            glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);
            glUniform1f( TessLevelInnerID, TessLevelInner );
            glUniform1f( TessLevelOuterID, TessLevelOuter );
            glUniform1f(cameraPosIDX, px);
            glUniform1f(cameraPosIDY, py);
            glUniform1f(cameraPosIDZ, pz);
            glUniform1f(ampValue,amp);
            glUniform1i(octavesValue,oct);
            glUniform1f(lacunarityValue,lac);

        }
        else if(geom){
            glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
            glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix[0][0]);
            glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &ViewMatrix[0][0]);
            glUniformMatrix4fv(ProjectionMatrixID, 1, GL_FALSE, &ProjectionMatrix[0][0]);
            glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);
            glUniform1f(cameraPosIDX, px);
            glUniform1f(cameraPosIDY, py);
            glUniform1f(cameraPosIDZ, pz);
            glUniform1f(ampValue,amp);
            glUniform1i(octavesValue,oct);
            glUniform1f(lacunarityValue,lac);
        }

        if(adapt || unif)
            glPatchParameteri(GL_PATCH_VERTICES, 3);


        // 1rst attribute buffer : vertices
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

        // color attribute
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));

        // texture coord attribute
        glEnableVertexAttribArray(2);
        glBindBuffer(GL_ARRAY_BUFFER, texturebuffer);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

        // Index buffer
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
       // glBindTexture(GL_TEXTURE_2D, texture);

        // Draw the triangles !
        if(adapt || unif){
            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

        // Index buffer
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
            glDrawElements(GL_PATCHES, indices.size(), GL_UNSIGNED_SHORT, (void*)0);

        }
        else{
            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

            // Index buffer
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);

            glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_SHORT, (void*)0);
        }
        glDisableVertexAttribArray(0);

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0 );

        // Cleanup VBO and shader
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &elementbuffer);
    if(adapt)
        glDeleteProgram(programAdaptID);
    else if(unif)
        glDeleteProgram(programUnifID);
    else if(geom)
        glDeleteProgram(programGeomID);
    glDeleteVertexArrays(1, &VertexArrayID);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
