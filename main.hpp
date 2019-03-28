#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "stb_image.h"
#include "SOIL.h"
#include "simplex.h"
#include "LoadShaders.hpp"
#include "controls.hpp"
#include "vectormath/vectormath.h"

#define QuantText 5
#define HEIGHT 1024
#define WIDTH   1280

const char* projectTitle = "Terrain";

using namespace glm;
using namespace std;

GLFWwindow* window;
float amp;
glm::vec3 lightPos;
GLuint programGeomID;
GLuint programTessID;
GLuint activeShader;

bool gIsCurrentlyPressed, tIsPressed, gIsPressed, enableTessShader = true;

const GLuint index = 20.0;
const GLfloat meshSize = 80.0;

static GLsizei IndexCount;
static float TessLevelInner;
static float TessLevelOuter;
GLuint allTextures[QuantText];

const char* filenames[QuantText] = {"container.jpg",
                                    "agua.jpg",
                                    "grama.jpg",
                                    "snow.jpg",
                                    "mountain.jpg"};

float px, py, pz;
int enableTess = 0;

GLuint MatrixID, ModelMatrixID, ViewMatrixID, ProjectionMatrixID,
    cameraPosIDX, cameraPosIDY, cameraPosIDZ, ampValue, octavesValue,
    lacunarityValue, LightID, TessLevelInnerID, TessLevelOuterID, TextureID,
    TextureID2, groundID, waterID, grassID, iceID, mountainID, enableTessID,
    VertexArrayID, vertexbuffer, elementbuffer, texturebuffer;
