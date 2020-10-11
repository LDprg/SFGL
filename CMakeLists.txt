# cmake VERSION
cmake_minimum_required(VERSION 3.16.0)

# project name
project(sfgl-cmake)

# set the C++17 standard
set(CMAKE_CXX_STANDARD 17)

# add include directory
include_directories("./includes")
if (WIN32)
	include_directories("./externalLib/windows/includes")
endif (WIN32)

if (UNIX)
	include_directories("./externalLib/linux/gl3w/include")
endif (UNIX)

# add libary directory
if (WIN32)
	link_directories("./externalLib/windows/lib")
endif (WIN32)

link_directories("./build")

# put all cpp into Libary var
file(GLOB LibarySrc "./src/*.cpp")

#define Präprozessor
add_compile_definitions(DEBUG)
remove_definitions(GLFW_DLL)

# compiles Libary
add_library(SFGL STATIC "./externalLib/linux/gl3w/src/gl3w.c" ${LibarySrc})

# set .lib extension
if (WIN32)
	set_target_properties(SFGL PROPERTIES SUFFIX ".lib")
endif (WIN32)

# compile Test 
add_executable(SFGLTest "./test/main.cpp")

if (UNIX)
	find_package(glfw3 REQUIRED)
	find_package(OpenGL REQUIRED)
endif (UNIX)

# add libary
if (WIN32)
	target_link_libraries(SFGLTest opengl32)
	target_link_libraries(SFGLTest glfw3)
	target_link_libraries(SFGLTest libSFGL)
endif (WIN32)

if (UNIX)
	target_link_libraries(SFGLTest glfw)
	target_link_libraries(SFGLTest libSFGL.a)
endif (UNIX)

target_link_libraries(SFGLTest ${CMAKE_DL_LIBS})

target_include_directories(SFGLTest PUBLIC
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
                           $<INSTALL_INTERFACE:include>)

if(WIN32)
	find_package(Doxygen REQUIRED)

	add_custom_target(doc ALL
    	            COMMAND ${DOXYGEN_EXECUTABLE} ./config.doxy
       		        WORKING_DIRECTORY ../)
endif (WIN32)