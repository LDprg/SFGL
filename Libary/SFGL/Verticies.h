#pragma once

#include <iostream>
#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>


namespace sfgl
{

	/// struct of the data of VerticiesData
	struct VerticiesData
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

	namespace Verticies
	{	

		///	Update the VerticiesData Buffers with Buffer Data
		///	@param	VerticiesData A list of shared pointer of VerticiesData
		void Update(std::vector<std::shared_ptr<VerticiesData>> Verticies);

		///	Update the VerticiesData Buffers with Buffer Data
		///	@param	VerticiesData shared pointer of VerticiesData
		void Update(std::shared_ptr<VerticiesData> Verticies);

		///	Draw the VerticiesData
		///	@param	VerticiesData A list of shared pointer of VerticiesData
		void Draw(std::vector<std::shared_ptr<VerticiesData>> Verticies, GLenum mode);

		///	Draw the VerticiesData
		///	@param	VerticiesData shared pointer of VerticiesData
		void Draw(std::shared_ptr<VerticiesData> Verticies, GLenum mode);

		///	Clean VerticiesData Data
		///	@param	VerticiesData A list of shared pointer of VerticiesData
		void Clean(std::vector<std::shared_ptr<VerticiesData>> Verticies);

		///	Clean VerticiesData Data
		///	@param	VerticiesData shared pointer of VerticiesData
		void Clean(std::shared_ptr<VerticiesData> Verticies);

	}
}