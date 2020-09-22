#pragma once

#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "Verticies.h"

namespace sfgl
{
	namespace Rectangel
	{

		///	Struct of the data of a Rectangel
		struct Rectangel
		{
			///	Postion of Rectangel Edge		
			float EdgePos[2][2];

			///	Color of Rectangel Edge
			float EdgeColor[3];

			///	Vertex 
			std::shared_ptr<Verticies::Verticies> Vertex;
		};

		/// Swap two Rectangels
		/// @param	T1 First Rectangel
		/// @param	T2 Second Rectangel
		void Swap(Rectangel& R1, Rectangel& R2);

		///	Create Vertex of Rectangel 
		///	@param Rectangels A list of Rectangels
		void Create(std::vector<Rectangel>& Rectangels);

		///	Create Vertex of Rectangel 
		///	@param Rectangels A Rectangel
		void Create(Rectangel& Rectangels);

		///	Update Vertex of Rectangel 
		///	@param Rectangels A list of Rectangels
		void Update(std::vector<Rectangel>& Rectangels);

		///	Update Vertex of Rectangel 
		///	@param Rectangels A Rectangel
		void Update(Rectangel& Rectangels);

		///	Draw Vertex of Rectangel 
		///	@param Rectangels A list of Rectangels
		void Draw(std::vector<Rectangel>& Rectangels);

		///	Draw Vertex of Rectangel 
		///	@param Rectangels A Rectangel
		void Draw(Rectangel& Rectangels);

		///	Clean Vertex of Rectangel 
		///	@param Rectangels A list of Rectangels
		void Clean(std::vector<Rectangel>& Rectangels);

		///	Clean Vertex of Rectangel 
		///	@param Rectangels A Rectangel
		void Clean(Rectangel& Rectangels);
	}
}