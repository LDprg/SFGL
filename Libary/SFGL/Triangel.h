#pragma once

#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "Verticies.h"

namespace sfgl
{

	///	Struct of the data of a Triangel
	struct Triangel
	{
		///	Postion of Triangel Edge		
		float EdgePos[3][2];

		///	Color of Triangel Edge
		float EdgeColor[3][3];
	};

	///	Convert Triangel to Verticies
	///	@param Triangels A list of Triangels
	///	@param Vertex A list of shared pointer to Verticies
	void Triangel2Verticies(std::vector<Triangel>& Triangels, std::vector<std::shared_ptr<Verticies::Verticies>>& Vertex);

}