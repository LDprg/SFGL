#include <iostream>
#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

//#include <glm/glm.hpp>

//#include "loadTexture.h"

#include "window.h"
#include "Triangel.h"

int main()
{
	WindowCreate();

	TriangelCreate();

	do
	{
		WindowClearScreen();

		TriangelDraw();

		WindowDraw();

		if (glfwGetKey(WindowGetHandle(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(WindowGetHandle(), 1);
		}
	} while (!WindowShouldClose());

	TriangelClean();

	WindowClean();

	return EXIT_SUCCESS;
}