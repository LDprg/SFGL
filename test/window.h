#pragma once

#include <iostream>
#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "loadShader.h"

namespace sfgl
{

	/**
	*	Creates the Window
	*/
	void WindowCreate();

	/**
	*	Get the glfw Window Handle.
	*	@return glfw Window Handle
	*/
	GLFWwindow* WindowGetHandle();

	/**
	*	Draw the Window
	*/
	void WindowDraw();

	/**
	*	Clear the Window
	*/
	void WindowClearScreen();

	/**
	*	Get Key Event
	*	@param key Key
	*	@return Event Type
	*/
	int WindowGetKey(int key);

	/**
	*	Close the Window in the next Frame
	*	@param is Window is closing
	*/
	void WindowShouldClose(int state);

	/**
	*	Return if Window should close
	*	@return 1 if Window is closing
	*/
	int WindowShouldClose();

	/**
	*	Clean Window Variabeln
	*/
	void WindowClean();

}