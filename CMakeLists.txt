# cmake VERSION
cmake_minimum_required(VERSION 3.8.0)

# project name
project("SFGL")

# set the C++17 standard
set(CMAKE_CXX_STANDARD 17)

set(DOC true)

# put all cpp into Libary var
file(GLOB SFGL_SRC "./src/SFGL/*.cpp" "./src/SFGL/*/*.cpp")

#define Präprozessor
add_compile_definitions(DEBUG)
remove_definitions(GLFW_DLL)

# compiles Libary
add_library(SFGL STATIC "./externalLib/src/gl3w.c" ${SFGL_SRC})

# set .lib extension
if (WIN32)
	set_target_properties(SFGL PROPERTIES SUFFIX ".lib")
endif (WIN32)

if (UNIX)
	if (POLICY CMP0072)
		cmake_policy (SET CMP0072 OLD)
	endif(POLICY CMP0072)

	find_package(glfw3 REQUIRED)
	find_package(OpenGL REQUIRED)
endif (UNIX)

# add include directory
target_include_directories(SFGL PUBLIC "${PROJECT_SOURCE_DIR}/include")

if (WIN32)
	target_include_directories(SFGL PUBLIC "${PROJECT_SOURCE_DIR}/externalLib/windows/include")
endif (WIN32)

target_include_directories(SFGL PUBLIC "${PROJECT_SOURCE_DIR}/externalLib/include")

add_subdirectory(test)

if(DOC)
	add_subdirectory(doc)	
endif (DOC)