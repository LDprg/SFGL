#pragma once

#include <iostream>
#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "loadShader.h"

namespace sfgl
{
	namespace Window
	{
		///	Struct of the data of a Rectangel
		struct Window
		{
			/// Window Handle
			GLFWwindow* window;

			/// Vertex Array ID
			GLuint VertexArrayID;

			/// Shader Program ID
			GLuint programID;
		};

		///	Creates the Window
		void Create(Window &window);

		/// Draw the Window
		void Draw(Window& window);

		///	Clear the Window
		void ClearScreen(Window& window);

		///	Get Key Event
		///	@param key Key
		///	@return Event Type
		int GetKey(Window& window, int key);

		///	Close the Window in the next Frame
		///	@param state should Window close
		void ShouldClose(Window& window, int state);

		///	Return if Window should close
		///	@return is Window closing
		inline int ShouldClose(Window& window)
		{
			return	glfwWindowShouldClose(window.window);
		}

		///	Clean Window Variabeln
		void Clean(Window& window);

	}
}