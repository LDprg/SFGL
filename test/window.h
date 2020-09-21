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

		/**
		*	Creates the Window
		*/
		void Create();

		/**
		*	Get the glfw Window Handle.
		*	@return glfw Window Handle
		*/
		GLFWwindow* GetHandle();

		/**
		*	Draw the Window
		*/
		void Draw();

		/**
		*	Clear the Window
		*/
		void ClearScreen();

		/**
		*	Get Key Event
		*	@param key Key
		*	@return Event Type
		*/
		int GetKey(int key);

		/**
		*	Close the Window in the next Frame
		*	@param is Window is closing
		*/
		void ShouldClose(int state);

		/**
		*	Return if Window should close
		*	@return 1 if Window is closing
		*/
		int ShouldClose();

		/**
		*	Clean Window Variabeln
		*/
		void Clean();

	}
}