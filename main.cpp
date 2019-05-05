#include "main.hpp"
#include "camera.h"

Camera camera(glm::vec3(00.0f, 50.0f, 00.0f));

int main(int argv, char** argc){
    init();

    createBuffer();

    createProgram();
    createVerticesIndexes();
    bindBuffer();

    createTextures();

    activeShader = programTessID;
    do{

        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        // Clear the screen

        setUnifLoc();

        pressButtons();
        setUnif();
        draw();
        disableVertexAttribs();

        swapBuffers();
    }

    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0 );

    deleteBuffers();
    deleteProgram();

    glfwTerminate();

    return 0;
}

int initGL(){
    glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow( WIDTH, HEIGHT, projectTitle, NULL, NULL);
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

	return 0;
}

int init(){
    initGL();

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwPollEvents();
    glfwSetCursorPos(window, WIDTH/2, HEIGHT/2);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

void createBuffer(){
	glGenVertexArrays(1, &VertexArrayID);
    glGenBuffers(1, &vertexbuffer);
    glGenBuffers(1, &elementbuffer);
}

void bindBuffer(){
    glBindVertexArray(VertexArrayID);

    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), &indices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &texturebuffer);
    glBindBuffer(GL_ARRAY_BUFFER, texturebuffer);
    glBufferData(GL_ARRAY_BUFFER, texcoord.size() * sizeof(GLfloat), texcoord.data(), GL_STATIC_DRAW);
}

void deleteBuffers(){
    glDeleteVertexArrays(1, &VertexArrayID);
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &elementbuffer);
    glDeleteBuffers(1, &texturebuffer);
}

void clearVectors(){
    indices.clear();
    vertices.clear();
    texcoord.clear();
}

void createVerticesIndexes(){
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

    for (GLfloat i = 0 ; i <= index ; i+=1.0){
		for (GLfloat j = 0 ; j <= index ; j+=1.0) {
            glm::vec2 vert = vec2((float)(i*tamAmostra), (float)(j*tamAmostra));
            float h = 1.0;//Simplex::iqfBm(vert, 3.8, 4.2f, 5.7f);
            vertices.push_back(vert.x);
            vertices.push_back(h);
            vertices.push_back(vert.y);
            texcoord.push_back((float)i);
            texcoord.push_back((float)j);
        }
	}
}

void disableVertexAttribs(){
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
}

void createProgram(){
    programTessID = LoadShaders( "terrain.vert", "terrain.tesc", "terrain.tese", "terrain.frag");
    programGeomID  = LoadShaders( "terrenofBm.vert", "Geodesic.geom", "Geodesic.frag");
}

void deleteProgram(){
    glDeleteProgram(programTessID);
    glDeleteProgram(programGeomID);
}

void createTextures(){
    for(int i = 0; i < QTDTEXTURAS; i++){
        unsigned char* texturas;

        glGenTextures(1, &allTextures[i]);

        // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // load image, create texture and generate mipmaps
        // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
        texturas = SOIL_load_image(filenames[i], &width, &height, &nrChannels, SOIL_LOAD_RGB);
        if (texturas)
        {
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, allTextures[i]);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texturas);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << filenames[i] << std::endl;
        }
        stbi_image_free(texturas);
    }
}

void setUnifLoc(){
    glUseProgram(activeShader);

    MatrixID            = glGetUniformLocation(activeShader, "MVP");
    cameraPosIDX        = glGetUniformLocation(activeShader, "px");
    cameraPosIDY        = glGetUniformLocation(activeShader, "py");
    cameraPosIDZ        = glGetUniformLocation(activeShader, "pz");
    groundID            = glGetUniformLocation(activeShader, "terra");
    waterID             = glGetUniformLocation(activeShader, "agua");
    grassID             = glGetUniformLocation(activeShader, "grama");
    iceID               = glGetUniformLocation(activeShader, "snow");
    mountainID          = glGetUniformLocation(activeShader, "mountain");
    enableTessID        = glGetUniformLocation(activeShader, "tess");
    pos2ID              = glGetUniformLocation(activeShader, "pos2");
    noiseID              = glGetUniformLocation(activeShader, "noised");
}

void setUnif(){
//    computeMatricesFromInputs(window);
    glm::mat4 MVP = camera.getProjectionMatrix(WIDTH, HEIGHT) * camera.getViewMatrix() * glm::mat4(1.0);
    float px = camera.Position.x; float py = camera.Position.y; float pz = camera.Position.z;

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniform1f(cameraPosIDX, px);
    glUniform1f(cameraPosIDY, py);
    glUniform1f(cameraPosIDZ, pz);
    glUniform1i(groundID, 0);
    glUniform1i(waterID,  1);
    glUniform1i(grassID, 2);
    glUniform1i(iceID, 3);
    glUniform1i(mountainID, 4);
    glUniform1i(enableTessID, enableTess);
    glUniform1f(noiseID, noise);
    glUniform1f(pos2ID, pos2);
}

void pressButtons(){
    bool noiseIsCurrentlyPressed = (glfwGetKey( window, GLFW_KEY_F ) == GLFW_PRESS);
    if (!noise2IsPressed && noiseIsCurrentlyPressed){
        noise = !noise;
        if(noise)
            cout<<"noise = true"<<endl;
        else
            cout<<"noise = false"<<endl;
    }
    noise2IsPressed = noiseIsCurrentlyPressed;

    bool pos2IsCurrentlyPressed = (glfwGetKey( window, GLFW_KEY_C ) == GLFW_PRESS);
    if (!pos2IsPressed && pos2IsCurrentlyPressed){
        pos2 = !pos2;
        if(pos2)
            cout<<"cpu = true"<<endl;
        else
            cout<<"cpu = false"<<endl;
    }
    pos2IsPressed = pos2IsCurrentlyPressed;

    bool mIsCurrentlyPressed = (glfwGetKey( window, GLFW_KEY_M ) == GLFW_PRESS);
    if (!mIsPressed && mIsCurrentlyPressed){
        modeMouse = !modeMouse;
        if(modeMouse){
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            glfwMakeContextCurrent(0);
            glfwWaitEventsTimeout(5000);
        }
        else{
            glfwMakeContextCurrent(window);
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        }
        //glfwPollEvents();
    }
    mIsPressed = mIsCurrentlyPressed;

    bool cIsCurrentlyPressed = (glfwGetKey( window, GLFW_KEY_C ) == GLFW_PRESS);
    if (!cIsPressed && cIsCurrentlyPressed){
        enableCull = !enableCull;
        if(enableCull)
            glEnable(GL_CULL_FACE);
        else
            glDisable(GL_CULL_FACE);
    }
    cIsPressed = cIsCurrentlyPressed;

    bool tIsCurrentlyPressed = (glfwGetKey( window, GLFW_KEY_T ) == GLFW_PRESS &&
                                !(glfwGetKey( window, GLFW_KEY_RIGHT_SHIFT ) == GLFW_PRESS || glfwGetKey( window, GLFW_KEY_LEFT_SHIFT ) == GLFW_PRESS));
    if (!tIsPressed && tIsCurrentlyPressed){
        enableTess = (enableTess+1)%3;
    }
    tIsPressed = tIsCurrentlyPressed;

    bool pIsCurrentlyPressed = (glfwGetKey( window, GLFW_KEY_T ) == GLFW_PRESS &&
                                (glfwGetKey( window, GLFW_KEY_RIGHT_SHIFT ) == GLFW_PRESS || glfwGetKey( window, GLFW_KEY_LEFT_SHIFT ) == GLFW_PRESS));
    if (!pIsPressed && pIsCurrentlyPressed){
        enablePolygon = !enablePolygon;
        if(enablePolygon)
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    pIsPressed = pIsCurrentlyPressed;

    bool plusIsCurrentlyPressed = (glfwGetKey( window, GLFW_KEY_KP_ADD ) == GLFW_PRESS &&
                                         !(glfwGetKey( window, GLFW_KEY_RIGHT_SHIFT ) == GLFW_PRESS || glfwGetKey( window, GLFW_KEY_LEFT_SHIFT ) == GLFW_PRESS));
    if (!plusIsPressed && plusIsCurrentlyPressed){
        GLuint saveIndex = index;
        saveIndex*=2;
//        if(saveIndex > meshSize)
//            saveIndex=meshSize;
        index = saveIndex;
        clearVectors();
        createVerticesIndexes();
        bindBuffer();
        cout<<"index = "<<index<<" e tamanho da malha = "<<meshSize<<endl<<"Quantidades dos v�rtices = "<<vertices.size()<<" e quantidade dos �ndices"<<indices.size()<<endl;
    }
    plusIsPressed = plusIsCurrentlyPressed;

    bool minusIsCurrentlyPressed = (glfwGetKey( window, GLFW_KEY_KP_SUBTRACT ) == GLFW_PRESS &&
                                         !(glfwGetKey( window, GLFW_KEY_RIGHT_SHIFT ) == GLFW_PRESS || glfwGetKey( window, GLFW_KEY_LEFT_SHIFT ) == GLFW_PRESS));
    if (!minusIsPressed && minusIsCurrentlyPressed){
        GLuint saveIndex = index;
        saveIndex/=2;
        if(saveIndex<2)
            saveIndex=2;
        index = saveIndex;
        clearVectors();
        createVerticesIndexes();
        bindBuffer();
        cout<<"index = "<<index<<" e tamanho da malha = "<<meshSize<<endl<<"Quantidades dos v�rtices = "<<vertices.size()<<" e quantidade dos �ndices"<<indices.size()<<endl;
    }
    minusIsPressed = minusIsCurrentlyPressed;

    bool shiftPlusIsCurrentlyPressed = (glfwGetKey( window, GLFW_KEY_KP_ADD ) == GLFW_PRESS &&
                                         (glfwGetKey( window, GLFW_KEY_RIGHT_SHIFT ) == GLFW_PRESS || glfwGetKey( window, GLFW_KEY_LEFT_SHIFT ) == GLFW_PRESS));
    if (!shiftPlusIsPressed && shiftPlusIsCurrentlyPressed){
        meshSize*=2;
        clearVectors();
        createVerticesIndexes();
        bindBuffer();
        cout<<"index = "<<index<<" e tamanho da malha = "<<meshSize<<endl<<"Quantidades dos v�rtices = "<<vertices.size()<<" e quantidade dos �ndices"<<indices.size()<<endl;
    }
    shiftPlusIsPressed = shiftPlusIsCurrentlyPressed;

    bool shiftMinusIsCurrentlyPressed = (glfwGetKey( window, GLFW_KEY_KP_SUBTRACT ) == GLFW_PRESS &&
                                         (glfwGetKey( window, GLFW_KEY_RIGHT_SHIFT ) == GLFW_PRESS || glfwGetKey( window, GLFW_KEY_LEFT_SHIFT ) == GLFW_PRESS));
    if (!shiftMinusIsPressed && shiftMinusIsCurrentlyPressed){
        GLuint saveMesh = meshSize;
        saveMesh/=2;
        if(meshSize<2)
            meshSize=2;
        if(index > saveMesh)
            saveMesh=index;
        meshSize = saveMesh;
        clearVectors();
        createVerticesIndexes();
        bindBuffer();
        cout<<"index = "<<index<<" e tamanho da malha = "<<meshSize<<endl<<"Quantidades dos v�rtices = "<<vertices.size()<<" e quantidade dos �ndices"<<indices.size()<<endl;
    }
    shiftMinusIsPressed = shiftMinusIsCurrentlyPressed;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

void draw(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPatchParameteri(GL_PATCH_VERTICES, 3);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    // color attribute
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));

    // texture coord attribute
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, texturebuffer);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    // Index buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
    if(activeShader == programTessID){
        glDrawElements(GL_PATCHES, indices.size(), GL_UNSIGNED_SHORT, (void*)0);

    }
    else{
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_SHORT, (void*)0);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}

void swapBuffers(){
    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
}
