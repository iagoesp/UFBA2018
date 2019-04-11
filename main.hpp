#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <typeinfo>
#include <cmath>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "stb_image.h"
#include "SOIL.h"
#include "simplex.h"
#include "LoadShaders.hpp"
//#include "controls.hpp"
#include "vectormath/vectormath.h"

#define QTDTEXTURAS 5
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

vector<unsigned short> indices;
vector<GLfloat> vertices;
vector<GLfloat> texcoord;

bool tIsPressed, pIsPressed, enablePolygon, cIsPressed, enableCull, plusIsPressed, minusIsPressed, shiftMinusIsPressed, shiftPlusIsPressed, mIsPressed, pos2IsPressed, pos2 = true, noise2IsPressed, noise=true;

static GLuint index = 32.0;
static GLfloat meshSize = 128.0;

static GLsizei IndexCount;
static float TessLevelInner;
static float TessLevelOuter;

const char* filenames[QTDTEXTURAS] = {"container.jpg",
                                    "agua.jpg",
                                    "grama.jpg",
                                    "snow.jpg",
                                    "mountain.jpg"};

GLuint allTextures[QTDTEXTURAS];
float deltaTime = 0.0f;
float lastFrame = 0.0f;
bool firstMouse = true;
float lastX = (float)WIDTH / 2.0;
float lastY = (float)HEIGHT / 2.0;


float px, py, pz;
int enableTess = 0, modeMouse=0;
int width, height, nrChannels;

GLuint MatrixID, ModelMatrixID, ViewMatrixID, ProjectionMatrixID,
    cameraPosIDX, cameraPosIDY, cameraPosIDZ, ampValue, octavesValue,
    lacunarityValue, LightID, TessLevelInnerID, TessLevelOuterID, TextureID,
    TextureID2, groundID, waterID, grassID, iceID, mountainID, enableTessID,
    VertexArrayID, vertexbuffer, elementbuffer, texturebuffer, pos2ID, noiseID;

int initGL();
int init();
void createBuffer();
void bindBuffer();
void deleteBuffers();
void clearVectors();
void createVerticesIndexes();
void disableVertexAttribs();
void createProgram();
void deleteProgram();
void createTextures();
void setUnifLoc();
void setUnif();
void pressButtons();
void draw();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void swapBuffers();
