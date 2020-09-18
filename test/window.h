#pragma once

#include <iostream>
#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "loadShader.hpp"

void WindowCreate();
GLFWwindow* WindowGetHandle();
void WindowDraw();
void WindowClearScreen();
int WindowShouldClose();
void WindowClean();