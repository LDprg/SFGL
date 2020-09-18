#pragma once

#include <iostream>
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

void VerticiesUpdate(std::vector<std::shared_ptr<verticies>> Verticies);
void VerticiesDraw(std::vector<std::shared_ptr<verticies>> &Verticies);
void VerticiesClean(std::vector<std::shared_ptr<verticies>> &Verticies);