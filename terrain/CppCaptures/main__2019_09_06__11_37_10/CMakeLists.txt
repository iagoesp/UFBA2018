
cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0054 NEW)

# Support for visual studio build
set(CMAKE_VS_INCLUDE_INSTALL_TO_DEFAULT_BUILD 1)

# Choose an available Windows SDK in order to meet the Direct3D feature level
if(WIN32 AND NOT ${CMAKE_SYSTEM_VERSION})
    # The required version
    set(REQUIRED_WIN_SDK_VERSION )

    # Detect all the Windows SDKs that exist on the machine.
    set(WIN_SDK_VERSIONS "")
    
    # We have to check "Windows.h" to verify if the SDK is really installed because there's no reliable registry value since v10.
    macro(AddWinSDKIfInstalled SDK_INCLUDE_PATH SDK_VERSION)
        if(EXISTS "${SDK_INCLUDE_PATH}/um/Windows.h")
            list(APPEND WIN_SDK_VERSIONS "${SDK_VERSION}")
        endif()
    endmacro()

    # Start at v8.1 because the minimum Visual Studio support version is 2015.
    get_filename_component(WIN_SDK_V81_ROOT "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows Kits\\Installed Roots;KitsRoot81]" ABSOLUTE CACHE)
    if(NOT ${WIN_SDK_V81_ROOT})
        set(WIN_SDK_V81_ROOT "%ProgramFiles%/Windows Kits/8.1")
    endif()
    if(IS_DIRECTORY ${WIN_SDK_V81_ROOT})
        AddWinSDKIfInstalled(${WIN_SDK_V81_ROOT}/Include 8.1)
    endif()

    get_filename_component(WIN_SDK_V10_ROOT "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows Kits\\Installed Roots;KitsRoot10]" ABSOLUTE CACHE)
    if(NOT ${WIN_SDK_V10_ROOT})
        set(WIN_SDK_V10_ROOT "%ProgramFiles%/Windows Kits/10")
    endif()
    if(IS_DIRECTORY ${WIN_SDK_V10_ROOT})
        file(GLOB SUB_FOLDERS RELATIVE ${WIN_SDK_V10_ROOT}/Include ${WIN_SDK_V10_ROOT}/Include/*)
        foreach(SUB_FOLDER ${SUB_FOLDERS})
            AddWinSDKIfInstalled(${WIN_SDK_V10_ROOT}/Include/${SUB_FOLDER} ${SUB_FOLDERS})
        endforeach()
    endif()

    # Select the first available version
    foreach(WIN_SDK_VERSION ${WIN_SDK_VERSIONS})
        if (${WIN_SDK_VERSION} VERSION_GREATER_EQUAL ${REQUIRED_WIN_SDK_VERSION})
            set(CMAKE_SYSTEM_VERSION ${WIN_SDK_VERSION})
            break()
        endif()
    endforeach()

    if(NOT ${CMAKE_SYSTEM_VERSION})
        message(FATAL_ERROR "Failed to find a Windows SDK that available to use. The minimum version required is ${REQUIRED_WIN_SDK_VERSION}")
    endif()
endif()

# Set project name
set(CPPCAP_PROJECT_NAME main__2019_09_06__11_37_10)
set(CPP_PROJECT_NAME_NOTIMESTAMP main)

project(${CPP_PROJECT_NAME_NOTIMESTAMP})

# The target name is trim so that cmake path lengths are short; the actual
# executable will be renamed via a property below
set(EXECUTABLE_TARGET cppcap)

# As there's no default LINUX variable, add one.
if(UNIX AND NOT APPLE)
    set(LINUX 1)
endif()

# Information of original capture
set(NV_ORIGINAL_OS LINUX)
set(NV_ORIGINAL_WINSYS x11)
set(NV_ORIGINAL_ARCH 64)

# Value of NV_ORIGINAL_OS is WIN32 or LINUX
# ${${NV_ORIGINAL_OS}} is 1 only if this project is built on the same platform than original capture.
set(NV_BUILD_ON_ORIGINAL_PLATFORM ${${NV_ORIGINAL_OS}})

# Determine default window system if not specified by "-DNV_WINSYS"
if(NOT NV_WINSYS)
    if(NV_BUILD_ON_ORIGINAL_PLATFORM)
        set(NV_WINSYS ${NV_ORIGINAL_WINSYS})
    else()
        if(LINUX)
            set(NV_WINSYS xcb)
        elseif(WIN32)
            set(NV_WINSYS win32)
        endif()
    endif()
endif()

# Make NV_WINSYS to be an option selectable in cmake-GUI
set(NV_WINSYS "${NV_WINSYS}" CACHE STRING "Select window system type to interact with graphics API")
if(LINUX)
    set_property(CACHE NV_WINSYS PROPERTY STRINGS xcb x11 vulkan-d2d)
elseif(WIN32)
    set_property(CACHE NV_WINSYS PROPERTY STRINGS win32)
endif()

if(NV_WINSYS STREQUAL xcb)
    set(NV_USE_XCB 1)
elseif(NV_WINSYS STREQUAL x11)
    set(NV_USE_X11 1)
elseif(NV_WINSYS STREQUAL vulkan-d2d)
    set(NV_USE_D2D 1)
elseif(NV_WINSYS STREQUAL win32)
    set(NV_USE_WIN32 1)
else()
    message(FATAL_ERROR "Specified wrong 'NV_WINSYS' argument. Must be one of 'xcb'/'x11'/'vulkan-d2d' on Linux or 'win32' on Windows.")
endif()

# Determine bitwise
if(CMAKE_SIZEOF_VOID_P STREQUAL "8")
    set(NV_USE_64BIT 1)
elseif(CMAKE_SIZEOF_VOID_P STREQUAL "4")
    set(NV_USE_32BIT 1)
else()
    message(FATAL_ERROR "Unrecognized bitwise.")
endif()

if(NV_USE_64BIT)
    link_directories(

    )
endif()

if(NV_USE_32BIT)
    link_directories(

    )
endif()

# Checking arch mismatch
if((NV_USE_64BIT AND NV_ORIGINAL_ARCH STREQUAL 64) OR (NV_USE_32BIT AND NV_ORIGINAL_ARCH STREQUAL 32))
    message(STATUS "Building ${NV_ORIGINAL_ARCH}-bit app.")
elseif(NV_USE_64BIT AND NV_ORIGINAL_ARCH STREQUAL 32)
    message(WARNING "Application originally targeted 32-bit; compiling now as 64-bit.")
elseif(NV_USE_32BIT AND NV_ORIGINAL_ARCH STREQUAL 64)
    message(FATAL_ERROR "Application originally targeted 64-bit; compiling now as 32-bit.")
else()
    message(FATAL_ERROR "Unrecognized original bitwise.")
endif()

add_executable(${EXECUTABLE_TARGET}
    Application.cpp
    Frame0Part00.cpp
    FrameReset00.cpp
    FrameSetup00.cpp
    Helpers.cpp
    Main.cpp
    NvEW_GL.cpp
    NvEW_GLX.cpp
    PerfMarkersReset.cpp
    PerfMarkersSetup.cpp
    ReadOnlyDatabase.cpp
    ReplayProcedures.cpp
    Resources00.cpp
    ThreadPool.cpp
    Threading.cpp
    WinResourcesReset.cpp
    WinResourcesSetup.cpp
)

set_target_properties(${EXECUTABLE_TARGET} PROPERTIES OUTPUT_NAME ${CPPCAP_PROJECT_NAME})

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(${EXECUTABLE_TARGET} PRIVATE
        -std=c++11
        -fvisibility=hidden)
endif()

option(NV_USE_MANAGED_WINSYS "Use replayer managed windowing system" OFF)
if(NV_USE_MANAGED_WINSYS OR NOT NV_BUILD_ON_ORIGINAL_PLATFORM OR NOT NV_WINSYS STREQUAL NV_ORIGINAL_WINSYS)
    target_compile_definitions(${EXECUTABLE_TARGET} PRIVATE NV_USE_MANAGED_WINSYS)
endif()

target_compile_definitions(${EXECUTABLE_TARGET} PRIVATE
    WINAPI_GLX
)

if(WIN32)
    target_compile_definitions(${EXECUTABLE_TARGET} PRIVATE
        NOMINMAX)
endif()

target_include_directories(${EXECUTABLE_TARGET} PRIVATE
)

# Link libraries
target_link_libraries(${EXECUTABLE_TARGET} PRIVATE
    rt
    pthread
    dl
    GL
)

if(NV_USE_64BIT)
    target_link_libraries(${EXECUTABLE_TARGET} PRIVATE
)
endif()

if(NV_USE_32BIT)
    target_link_libraries(${EXECUTABLE_TARGET} PRIVATE
)
endif()

# Install targets
if(NOT NV_INSTALL_FOLDER)
    set(NV_INSTALL_FOLDER bin)
endif()
install(TARGETS ${EXECUTABLE_TARGET} RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/${NV_INSTALL_FOLDER}/)

set(RESOURCE_FILES_OR_FOLDERS)

if(NV_USE_64BIT)
    list(APPEND RESOURCE_FILES_OR_FOLDERS
)
endif()

if(NV_USE_32BIT)
    list(APPEND RESOURCE_FILES_OR_FOLDERS
)
endif()

if(RESOURCE_FILES_OR_FOLDERS)
    set(RESOURCES)
    foreach(FILE_OR_FOLDER ${RESOURCE_FILES_OR_FOLDERS})
        if(IS_DIRECTORY ${FILE_OR_FOLDER})
            file(GLOB SUB_FILES ${FILE_OR_FOLDER}/*.*)
            list(APPEND RESOURCES ${SUB_FILES})
        else()
            list(APPEND RESOURCES ${FILE_OR_FOLDER})
        endif()
    endforeach()
    install(FILES ${RESOURCES} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/${NV_INSTALL_FOLDER}/)
endif()

# Set platform specific properties.
if(WIN32)
    target_compile_definitions(${EXECUTABLE_TARGET} PRIVATE UNICODE)
    target_sources(${EXECUTABLE_TARGET} PRIVATE
        Win32Application.cpp)
endif()

if(LINUX)
    target_sources(${EXECUTABLE_TARGET} PRIVATE
        LinuxApplication.cpp)
endif()

# Set window system specific properties
if(NV_USE_XCB)
    target_compile_definitions(${EXECUTABLE_TARGET} PRIVATE NV_USE_XCB=1 VK_USE_PLATFORM_XCB_KHR)
    target_link_libraries(${EXECUTABLE_TARGET} PRIVATE
        dl
        xcb
        xcb-icccm
        pthread)
    target_sources(${EXECUTABLE_TARGET} PRIVATE
        WindowSystem_Xcb.cpp)
endif()

if(NV_USE_X11)
    target_compile_definitions(${EXECUTABLE_TARGET} PRIVATE NV_USE_X11=1 VK_USE_PLATFORM_XLIB_KHR)
    target_link_libraries(${EXECUTABLE_TARGET} PRIVATE
        dl
        X11
        Xau
        pthread)
    target_sources(${EXECUTABLE_TARGET} PRIVATE
        WindowSystem_X11.cpp)
endif()

if(NV_USE_D2D)
    target_compile_definitions(${EXECUTABLE_TARGET} PRIVATE NV_USE_D2D=1)
    target_link_libraries(${EXECUTABLE_TARGET} PRIVATE
        dl
        pthread)
    target_sources(${EXECUTABLE_TARGET} PRIVATE
        WindowSystem_D2d.cpp)
endif()

if(NV_USE_WIN32)
    target_compile_definitions(${EXECUTABLE_TARGET} PRIVATE _CRT_SECURE_NO_DEPRECATE NV_USE_WIN32=1 VK_USE_PLATFORM_WIN32_KHR)
    target_sources(${EXECUTABLE_TARGET} PRIVATE
        WindowSystem_Win32.cpp)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${EXECUTABLE_TARGET} PRIVATE -W3 -MP -Ob2 -wd4351 -wd4819 -bigobj)
    target_compile_options(${EXECUTABLE_TARGET} PRIVATE $<$<CONFIG:DEBUG>:-MTd>)
    target_compile_options(${EXECUTABLE_TARGET} PRIVATE $<$<CONFIG:RELEASE>:-Oi -MT>)
endif()
