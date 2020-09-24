#pragma once

#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "Verticies.h"

namespace sfgl
{

	///	Struct of the data of a TriangelData
	struct TriangelData
	{
		///	Postion of TriangelData Edge		
		float EdgePos[3][2];

		///	Color of TriangelData Edge
		float EdgeColor[3][3];

		///	Vertex 
		std::shared_ptr<VerticiesData> Vertex;
	};

	namespace Triangel
	{

		/// Swap two Triangels
		/// @param	T1 First TriangelData
		/// @param	T2 Second TriangelData
		void Swap(TriangelData& T1, TriangelData& T2);

		///	Create Vertex of TriangelData 
		///	@param Triangels A list of Triangels
		void Create(std::vector<TriangelData>& Triangels);

		///	Create Vertex of TriangelData 
		///	@param Triangels A TriangelData
		void Create(TriangelData& Triangels);

		///	Update Vertex of TriangelData 
		///	@param Triangels A list of Triangels
		void Update(std::vector<TriangelData>& Triangels);

		///	Update Vertex of TriangelData 
		///	@param Triangels A TriangelData
		void Update(TriangelData& Triangels);

		///	Draw Vertex of TriangelData 
		///	@param Triangels A list of Triangels
		void Draw(std::vector<TriangelData>& Triangels);

		///	Draw Vertex of TriangelData 
		///	@param Triangels A TriangelData
		void Draw(TriangelData& Triangels);

		///	Clean Vertex of TriangelData 
		///	@param Triangels A list of Triangels
		void Clean(std::vector<TriangelData>& Triangels);

		///	Clean Vertex of TriangelData 
		///	@param Triangels A TriangelData
		void Clean(TriangelData& Triangels);
	}
}