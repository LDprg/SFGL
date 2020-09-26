#pragma once

#include <vector>

#include <GL/gl3w.h>

#include <GLFW/glfw3.h>

#include "Verticies.hpp"

namespace sfgl
{

	///	Struct of the data of a RectangelData
	struct RectangelData
	{
		///	Postion of RectangelData Edge		
		float EdgePos[2][2];

		///	Color of RectangelData Edge
		float EdgeColor[3];

		///	Vertex 
		std::shared_ptr<VerticiesData> Vertex;
	};

	namespace Rectangel
	{

		/// Swap two Rectangels
		/// @param	R1 First RectangelData
		/// @param	R2 Second RectangelData
		void Swap(RectangelData& R1, RectangelData& R2);

		///	Create Vertex of RectangelData 
		///	@param Rectangels A list of Rectangels
		void Create(std::vector<RectangelData>& Rectangels);

		///	Create Vertex of RectangelData 
		///	@param Rectangels A RectangelData
		void Create(RectangelData& Rectangels);

		///	Update Vertex of RectangelData 
		///	@param Rectangels A list of Rectangels
		void Update(std::vector<RectangelData>& Rectangels);

		///	Update Vertex of RectangelData 
		///	@param Rectangels A RectangelData
		void Update(RectangelData& Rectangels);

		///	Draw Vertex of RectangelData 
		///	@param Rectangels A list of Rectangels
		void Draw(std::vector<RectangelData>& Rectangels);

		///	Draw Vertex of RectangelData 
		///	@param Rectangels A RectangelData
		void Draw(RectangelData& Rectangels);

		///	Clean Vertex of RectangelData 
		///	@param Rectangels A list of Rectangels
		void Clean(std::vector<RectangelData>& Rectangels);

		///	Clean Vertex of RectangelData 
		///	@param Rectangels A RectangelData
		void Clean(RectangelData& Rectangels);
	}
}