#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include <GL/gl3w.h>


#include <GLFW/glfw3.h>


namespace sfgl
{

	/// clas of Verticies
	class Verticies
	{
		/// Vertex Buffer
		GLuint vertexBuffer;
		/// Color Buffer
		GLuint colorBuffer;

		/// Data for Vertex Buffer
		std::vector <GLfloat> vertexBufferData;
		/// Data for Color Buffer
		std::vector <GLfloat> colorBufferData;

		///	Update the Verticies Buffers with Buffer Data
		///	@param	Verticies A list of shared pointer of Verticies
		void Update(std::vector<std::shared_ptr<Verticies>> Verticies);

		///	Update the Verticies Buffers with Buffer Data
		///	@param	Verticies shared pointer of Verticies
		void Update(std::shared_ptr<Verticies> Verticies);

		///	Draw the Verticies
		///	@param	Verticies A list of shared pointer of Verticies
		/// @param 	mode OpenGL draw mode
		void Draw(std::vector<std::shared_ptr<Verticies>> Verticies, GLenum mode);

		///	Draw the Verticies
		///	@param	Verticies shared pointer of Verticies
		/// @param 	mode OpenGL draw mode
		void Draw(std::shared_ptr<Verticies> Verticies, GLenum mode);

		///	Clean Verticies
		///	@param	Verticies A list of shared pointer of Verticies
		void Clean(std::vector<std::shared_ptr<Verticies>> Verticies);

		///	Clean Verticies 
		///	@param	Verticies shared pointer of Verticies
		void Clean(std::shared_ptr<Verticies> Verticies);

	};
}