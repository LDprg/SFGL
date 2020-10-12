# compile Test 
add_executable(SFGLTest "./main.cpp")

target_include_directories(SFGLTest PUBLIC "${PROJECT_SOURCE_DIR}/include")

if (WIN32)
	target_include_directories(SFGLTest PUBLIC "${PROJECT_SOURCE_DIR}/externalLib/windows/include")
endif (WIN32)

target_include_directories(SFGLTest PUBLIC "${PROJECT_SOURCE_DIR}/externalLib/include")

# add libary directory
if (WIN32)
	target_link_directories(SFGLTest PUBLIC "${PROJECT_SOURCE_DIR}/externalLib/windows/lib")
endif (WIN32)

# add libary
if (WIN32)
	target_link_libraries(SFGLTest glfw3)
	target_link_libraries(SFGLTest SFGL)
endif (WIN32)

if (UNIX)
	target_link_libraries(SFGLTest glfw)
	target_link_libraries(SFGLTest SFGL)
endif (UNIX)

target_link_libraries(SFGLTest ${CMAKE_DL_LIBS})

target_include_directories(SFGLTest PUBLIC
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
                           $<INSTALL_INTERFACE:include>)