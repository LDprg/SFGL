#pragma once

#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "Verticies.h"

namespace sfgl
{
	namespace Triangel
	{

		///	Struct of the data of a Triangel
		struct Triangel
		{
			///	Postion of Triangel Edge		
			float EdgePos[3][2];

			///	Color of Triangel Edge
			float EdgeColor[3][3];

			///	Vertex 
			std::shared_ptr<Verticies::Verticies> Vertex;
		};

		/// Swap two Triangels
		/// @param	T1 First Triangel
		/// @param	T2 Second Triangel
		void Swap(Triangel& T1, Triangel& T2);

		///	Create Vertex of Triangel 
		///	@param Triangels A list of Triangels
		void Create(std::vector<Triangel>& Triangels);

		///	Create Vertex of Triangel 
		///	@param Triangels A Triangel
		void Create(Triangel& Triangels);

		///	Update Vertex of Triangel 
		///	@param Triangels A list of Triangels
		void Update(std::vector<Triangel>& Triangels);

		///	Update Vertex of Triangel 
		///	@param Triangels A Triangel
		void Update(Triangel& Triangels);

		///	Draw Vertex of Triangel 
		///	@param Triangels A list of Triangels
		void Draw(std::vector<Triangel>& Triangels);

		///	Draw Vertex of Triangel 
		///	@param Triangels A Triangel
		void Draw(Triangel& Triangels);

		///	Clean Vertex of Triangel 
		///	@param Triangels A list of Triangels
		void Clean(std::vector<Triangel>& Triangels);

		///	Clean Vertex of Triangel 
		///	@param Triangels A Triangel
		void Clean(Triangel& Triangels);
	}
}