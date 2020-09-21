#pragma once

#include <iostream>
#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

namespace sfgl
{

	/**
	*	A struct of the data of verticies
	*/
	struct verticies
	{
		GLuint vertexBuffer;
		GLuint colorBuffer;

		std::vector <GLfloat> vertexBufferData;
		std::vector <GLfloat> colorBufferData;
	};

	/**
	*	Update	Verticies Buffers with Buffer Data
	*	@param	Verticies A list of shared pointer of Verticies
	*	@todo	Remove Buffer Data for more performance
	*/
	void VerticiesUpdate(std::vector<std::shared_ptr<verticies>> Verticies);

	/**
	*	Draw the Verticies
	*	@param	Verticies A list of shared pointer of Verticies
	*/
	void VerticiesDraw(std::vector<std::shared_ptr<verticies>>& Verticies);

	/**
	*	Clean Verticies Data
	*	@param	Verticies A list of shared pointer of Verticies
	*/
	void VerticiesClean(std::vector<std::shared_ptr<verticies>>& Verticies);

}