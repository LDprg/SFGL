#pragma once

#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

struct verticies
{
	GLuint vertexBuffer;
	GLuint colorBuffer;

	std::vector <GLfloat> vertexBufferData;
	std::vector <GLfloat> colorBufferData;
};

void VerticiesUpdate(std::vector<verticies> &Verticies);
void VerticiesDraw(std::vector<verticies> &Verticies);
void VerticiesClean(std::vector<verticies> &Verticies);