#include "main.hpp"

extern glm::vec3 position;

vector<unsigned short> indices;
vector<GLfloat> vertices;
vector<GLfloat> texcoord;

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

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwPollEvents();
    glfwSetCursorPos(window, WIDTH/2, HEIGHT/2);

	glClearColor(0.5f, 0.5f, 0.8f, 1.0f);

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
            float h = Simplex::iqfBm (vert, 3.8, 4.2f, 5.7f);
            vertices.push_back(vert.x);
            vertices.push_back(h);
            vertices.push_back(vert.y);
            texcoord.push_back((float)i);
            texcoord.push_back((float)j);
        }
	}
}

void createTextures(){
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
}

void createProgram(){
    programTessID = LoadShaders( "terrain.vert", "terrain.tesc", "terrain.tese", "terrain.frag");
    programGeomID  = LoadShaders( "terrenofBm.vert", "Geodesic.geom", "Geodesic.frag");
}

void getLocations(){
        MatrixID            = glGetUniformLocation(activeShader, "MVP");
        ModelMatrixID       = glGetUniformLocation(activeShader, "M");
        ViewMatrixID        = glGetUniformLocation(activeShader, "V");
        ProjectionMatrixID  = glGetUniformLocation(activeShader, "P");
        cameraPosIDX        = glGetUniformLocation(activeShader, "px");
        cameraPosIDY        = glGetUniformLocation(activeShader, "py");
        cameraPosIDZ        = glGetUniformLocation(activeShader, "pz");
        groundID            = glGetUniformLocation(activeShader, "terra");
        waterID             = glGetUniformLocation(activeShader, "agua");
        grassID             = glGetUniformLocation(activeShader, "grama");
        iceID               = glGetUniformLocation(activeShader, "snow");
        mountainID          = glGetUniformLocation(activeShader, "mountain");
        enableTessID        = glGetUniformLocation(activeShader, "tess");
}
void deleteBuffers(){
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &elementbuffer);
    glDeleteBuffers(1, &texturebuffer);
}

void deleteProgram(){
    glDeleteProgram(programTessID);
    glDeleteProgram(programGeomID);
}

void deleteVertexArray(){
    glDeleteVertexArrays(1, &VertexArrayID);
}

int main(int argv, char** argc){
    cout<<"Press J to get the Geometry Shader"<<endl;
    cout<<"Press K to get the Adapt Tessellation Shader"<<endl;
    cout<<"Press L to get the Uniform Tessellation Shader"<<endl;

    init();

    createBuffer();

    createProgram();
    createVerticesIndexes();
    bindBuffer();

    createTextures();

    glm::vec3 camerapos = position;

    activeShader = programTessID;
    do{

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use our shader
        bool tIsCurrentlyPressed = (glfwGetKey( window, GLFW_KEY_T ) == GLFW_PRESS);
        if (!tIsPressed && tIsCurrentlyPressed){
            enableTess = (enableTess+1)%3;
        }
        tIsPressed = tIsCurrentlyPressed;

        getLocations();
        glUseProgram(activeShader);

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

        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
        glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix[0][0]);
        glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &ViewMatrix[0][0]);
        glUniformMatrix4fv(ProjectionMatrixID, 1, GL_FALSE, &ProjectionMatrix[0][0]);
        glUniform1f(cameraPosIDX, px);
        glUniform1f(cameraPosIDY, py);
        glUniform1f(cameraPosIDZ, pz);
        glUniform1i(groundID, 0);
        glUniform1i(waterID,  1);
        glUniform1i(grassID, 2);
        glUniform1i(iceID, 3);
        glUniform1i(mountainID, 4);
        glUniform1i(enableTessID, enableTess);

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
        // Index buffer
            glDrawElements(GL_PATCHES, indices.size(), GL_UNSIGNED_SHORT, (void*)0);

        }
        else{
            glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_SHORT, (void*)0);
        }
        glDisableVertexAttribArray(0);

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0 );

    deleteBuffers();
    deleteProgram();
    deleteVertexArray();

    glfwTerminate();

    return 0;
}
