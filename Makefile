#OBJS specifies which files to compile as part of the project
OBJS = main.cpp LoadShaders.cpp controls.cpp

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS =

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = 

#COMPILER_FLAGS specifies the additional compilation options we're using
#-w suppresses all warnings
#-Wl,-subsystem,windows gets rid of the console window
#COMPILER_FLAGS = -w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSOIL -lopengl32 -lglfw3 -lglew32 -lglu32 -lgdi32

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = Application

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS)  $(LINKER_FLAGS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
