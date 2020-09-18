#pragma once

#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "Verticies.h"

struct Triangel
{
	glm::vec2 EdgePos[3];
	glm::vec3 EdgeColor[3];
};

void Triangel2Verticies(std::vector<Triangel> &Triangels, std::vector<verticies> &Verticies);