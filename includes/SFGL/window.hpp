#pragma once

#include <iostream>
#include <vector>

#include <GL/gl3w.h>

#include <GLFW/glfw3.h>

#include "loadShader.hpp"

namespace sfgl
{

	///	Struct of the data of a RectangelData
	class Window
	{
	public:
		/// WindowData Handle
		GLFWwindow* mWindow;

		/// Vertex Array ID
		GLuint mVertexArrayID;

		/// Shader Program ID
		GLuint mProgramID;

		///	Creates the Window
		void Create();

		/// Draw the Window
		void Draw()
		{
			// Swap buffer
			glfwSwapBuffers(mWindow);
			glfwPollEvents();

			// Use shader
			glUseProgram(mProgramID);
		}

		///	Clear the Window
		void ClearScreen()
		{
			// Dark blue background
			glClearColor(0.f, 0.f, 0.4f, 0.f);
			// Clear the screen
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		///	Get Key Event
		///	@param key Key
		///	@return Event Type
		int GetKey(int key)
		{
			return glfwGetKey(mWindow, key);
		}

		///	Close the Window in the next Frame
		///	@param state should Window close
		void ShouldClose(int state)
		{
			glfwSetWindowShouldClose(mWindow, state);
		}

		///	Return if Windowshould close
		///	@return is Window closing
		int ShouldClose()
		{
			return	glfwWindowShouldClose(mWindow);
		}

		///	Clean Window Variabel
		void Clean()
		{
			glDeleteVertexArrays(1, &mVertexArrayID);
			glDeleteProgram(mProgramID);

			// Close OpenGL WindowData and terminate GLFW
			glfwDestroyWindow(mWindow);
			glfwTerminate();
		}

	};
}