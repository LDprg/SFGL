#pragma once

#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "Verticies.h"

struct Triangel
{
	float EdgePos[3][2];
	float EdgeColor[3][3];
};

void Triangel2Verticies(std::vector<Triangel> &Triangels, std::vector<std::shared_ptr<verticies>> &Verticies);