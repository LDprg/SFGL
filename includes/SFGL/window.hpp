#pragma once

#include <iostream>
#include <vector>

#include <GL/gl3w.h>

#include <GLFW/glfw3.h>

#include "loadShader.hpp"

namespace sfgl
{

	///	Struct of the data of a RectangelData
	struct WindowData
	{
		/// WindowData Handle
		GLFWwindow* window;

		/// Vertex Array ID
		GLuint VertexArrayID;

		/// Shader Program ID
		GLuint programID;
	};

	namespace Window
	{

		///	Creates the WindowData
		/// @param window WindowData
		void Create(WindowData&window);

		/// Draw the WindowData
		/// @param window WindowData
		void Draw(WindowData& window);

		///	Clear the WindowData
		/// @param window WindowData
		void ClearScreen(WindowData& window);

		///	Get Key Event
		/// @param window WindowData
		///	@param key Key
		///	@return Event Type
		int GetKey(WindowData& window, int key);

		///	Close the WindowData in the next Frame
		/// @param window WindowData
		///	@param state should WindowData close
		void ShouldClose(WindowData& window, int state);

		///	Return if WindowData should close
		/// @param window WindowData
		///	@return is WindowData closing
		inline int ShouldClose(WindowData& window)
		{
			return	glfwWindowShouldClose(window.window);
		}

		///	Clean WindowData Variabeln
		/// @param window WindowData
		void Clean(WindowData& window);

	}
}