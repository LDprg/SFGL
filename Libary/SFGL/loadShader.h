#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

namespace sfgl
{
	namespace Shader
	{

		///	Loading Shaders from File
		///	@param vertex_file_path Path for vertex shader
		///	@param fragment_file_path Path for fragment shader
		///	@return Shader Program ID
		GLuint loadFromFile(const char* vertex_file_path, const char* fragment_file_path);

		///	Loading std Shaders 
		///	@return Shader Program ID
		GLuint loadStd();
	}
}