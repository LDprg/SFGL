#pragma once

#include <iostream>
#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

namespace sfgl
{
	namespace Verticies
	{

		/// struct of the data of Verticies
		struct Verticies
		{
			/// Vertex Buffer
			GLuint vertexBuffer;
			/// Color Buffer
			GLuint colorBuffer;

			/// Data for Vertex Buffer
			std::vector <GLfloat> vertexBufferData;
			/// Data for Color Buffer
			std::vector <GLfloat> colorBufferData;
		};

		///	Update the Verticies Buffers with Buffer Data
		///	@param	Verticies A list of shared pointer of Verticies
		void Update(std::vector<std::shared_ptr<Verticies>> Verticies);

		///	Update the Verticies Buffers with Buffer Data
		///	@param	Verticies shared pointer of Verticies
		void Update(std::shared_ptr<Verticies> Verticies);

		///	Draw the Verticies
		///	@param	Verticies A list of shared pointer of Verticies
		void Draw(std::vector<std::shared_ptr<Verticies>> Verticies);

		///	Draw the Verticies
		///	@param	Verticies shared pointer of Verticies
		void Draw(std::shared_ptr<Verticies> Verticies);

		///	Clean Verticies Data
		///	@param	Verticies A list of shared pointer of Verticies
		void Clean(std::vector<std::shared_ptr<Verticies>> Verticies);

		///	Clean Verticies Data
		///	@param	Verticies shared pointer of Verticies
		void Clean(std::shared_ptr<Verticies> Verticies);

	}
}