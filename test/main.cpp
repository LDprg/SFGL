#include <iostream>
#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

//#include <glm/glm.hpp>

//#include "loadTexture.h"

#include "window.h"
#include "Verticies.h"
#include "Triangel.h"

std::vector<Triangel> Triangels;
std::vector<verticies> Verticies;

int main()
{
	WindowCreate();

	Verticies.emplace_back();

	Verticies[0].vertexBufferData.emplace_back(0.0f);
	Verticies[0].vertexBufferData.emplace_back(1.0f);
	Verticies[0].vertexBufferData.emplace_back(1.0f);
	Verticies[0].vertexBufferData.emplace_back(-1.0f);
	Verticies[0].vertexBufferData.emplace_back(-1.0f);
	Verticies[0].vertexBufferData.emplace_back(-1.0f);

	Verticies[0].colorBufferData.emplace_back(1.f);
	Verticies[0].colorBufferData.emplace_back(0.f);
	Verticies[0].colorBufferData.emplace_back(0.f);
	Verticies[0].colorBufferData.emplace_back(0.f);
	Verticies[0].colorBufferData.emplace_back(1.f);
	Verticies[0].colorBufferData.emplace_back(0.f);
	Verticies[0].colorBufferData.emplace_back(0.f);
	Verticies[0].colorBufferData.emplace_back(0.f);
	Verticies[0].colorBufferData.emplace_back(1.f);

	VerticiesUpdate(Verticies);

	do
	{
		WindowClearScreen();

		VerticiesDraw(Verticies);

		WindowDraw();

		if (glfwGetKey(WindowGetHandle(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(WindowGetHandle(), 1);
		}
	} while (!WindowShouldClose());

	VerticiesClean(Verticies);

	WindowClean();

	return EXIT_SUCCESS;
}