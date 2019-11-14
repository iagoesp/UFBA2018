

$(info building on local host...)

CC     = gcc
CXX    = g++
AR     = ar
RANLIB = ranlib
STRIP  = strip
NM     = nm
LD     = $(if $(wildcard *.cpp),$(CXX),$(CC))

COMMON_CFLAGS = -Os                  \
                -g                   \
                -O2                  \
                -fomit-frame-pointer \
                -finline-functions   \
                -finline-limit=300   \
                -fgcse-after-reload  \
                -fno-strict-aliasing \
                -Wall                \
                -Wcast-align         \
                -Wno-unused-variable

COMMON_CPPFLAGS = -std=c++11 $(ADDITIONAL_INC) $(ADDITIONAL_PRE_DEFINE)

INCLUDE_PATHS :=

LIB_PATHS :=

LD_FLAGS := -Wl,--unresolved-symbols=ignore-in-shared-libs -pthread

ADDITIONAL_PRE_DEFINE :=
ADDITIONAL_PRE_DEFINE += -DWINAPI_GLX


NV_WINSYS = x11

ifeq ($(NV_WINSYS),xcb)
    # libxcb-icccm4 and libxcb-icccm4-dev are required
    NV_PLATFORM_WINSYS_LIBS = -ldl -lxcb -lxcb-icccm
    NV_PLATFORM_WINSYS_SRC  = WindowSystem_Xcb.cpp
    ADDITIONAL_PRE_DEFINE += -DVK_USE_PLATFORM_XCB_KHR
else ifeq ($(NV_WINSYS),x11)
    NV_PLATFORM_WINSYS_LIBS = -lX11 -lXau -ldl
    NV_PLATFORM_WINSYS_SRC  = WindowSystem_X11.cpp
    ADDITIONAL_PRE_DEFINE += -DVK_USE_PLATFORM_XLIB_KHR
else ifeq ($(NV_WINSYS),vulkan-d2d)
    # Using Vulkan direct-to-display backend
    NV_PLATFORM_WINSYS_LIBS = -ldl
    NV_PLATFORM_WINSYS_SRC  = WindowSystem_D2d.cpp
else
    $(error Unknown window system)
endif

ADDITIONAL_INC :=


SOURCE_FILES := $(NV_PLATFORM_WINSYS_SRC)
SOURCE_FILES += Application.cpp
SOURCE_FILES += Frame0Part00.cpp
SOURCE_FILES += FrameReset00.cpp
SOURCE_FILES += FrameSetup00.cpp
SOURCE_FILES += Helpers.cpp
SOURCE_FILES += Main.cpp
SOURCE_FILES += NvEW_GL.cpp
SOURCE_FILES += NvEW_GLX.cpp
SOURCE_FILES += PerfMarkersReset.cpp
SOURCE_FILES += PerfMarkersSetup.cpp
SOURCE_FILES += ReadOnlyDatabase.cpp
SOURCE_FILES += ReplayProcedures.cpp
SOURCE_FILES += Resources00.cpp
SOURCE_FILES += ThreadPool.cpp
SOURCE_FILES += Threading.cpp
SOURCE_FILES += WinResourcesReset.cpp
SOURCE_FILES += WinResourcesSetup.cpp

SOURCE_FILES += LinuxApplication.cpp

LINKING_LIBS := $(NV_PLATFORM_WINSYS_LIBS)
LINKING_LIBS += -lrt
LINKING_LIBS += -lpthread
LINKING_LIBS += -ldl
LINKING_LIBS += -lGL


RESOURCES :=
RESOURCES += data.bin
RESOURCES += data.bin.rec


OBJECT_FILES=$(addprefix int/, $(SOURCE_FILES:.cpp=.o))
DEP_FILES=$(addprefix int/, $(SOURCE_FILES:.cpp=.d))

all: bin/main__2019_09_06__11_45_41

ifneq ($(MAKECMDGOALS),clean)
-include $(DEP_FILES)
endif

# Rule for generating object files
int/%.o: %.cpp int/%.d
	$(CXX) $(COMMON_CFLAGS) $(COMMON_CPPFLAGS) $(INCLUDE_PATHS) -c $(patsubst %.o,%.cpp,$(@:int/%=%)) -o $@

# Rule for generateing dep file
int/%.d:
	@if [ -d "int" ] ; then :; else mkdir -p int ; fi
	$(CXX) -MT '$(patsubst %.d,%.o,$@)' -MM $(COMMON_CFLAGS) $(COMMON_CPPFLAGS) $(INCLUDE_PATHS) -c $(patsubst %.d,%.cpp,$(@:int/%=%)) -o $@

clean:
	rm -rf int bin

bin/main__2019_09_06__11_45_41 : $(OBJECT_FILES)
	@mkdir -p bin
	cp -u $(RESOURCES) bin
	$(LD) -o $@ $(LD_FLAGS) $(LIB_PATHS) $(OBJECT_FILES) $(LINKING_LIBS)
