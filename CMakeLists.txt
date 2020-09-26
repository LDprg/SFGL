# cmake VERSION
cmake_minimum_required(VERSION 3.18.1)

# project name
project(sfgl-cmake)

# set the C++17 standard
set(CMAKE_CXX_STANDARD 17)

# add include directory
include_directories(includes)
include_directories(externalLib/includes)

# add libary directory
link_directories(externalLib/lib)
link_directories(build)

# put all cpp into Libary var
file(GLOB LibarySrc src/*.cpp)

#define Präprozessor
add_compile_definitions(GLEW_STATIC)
add_compile_definitions(_DEBUG)
add_compile_definitions(_CONSOLE)

# compiles Libary
add_library(SFGL STATIC externalLib/src/gl3w.c ${LibarySrc})

# set .lib extension
set_target_properties(SFGL PROPERTIES SUFFIX ".lib")

# compile Test 
add_executable(SFGLTest test/main.cpp)

# add libary
target_link_libraries(SFGLTest opengl32)
target_link_libraries(SFGLTest glfw3)
target_link_libraries(SFGLTest libSFGL)