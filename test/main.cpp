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
std::vector<std::shared_ptr<verticies>> Verticies;

int main()
{
	WindowCreate();

	verticies Vertice;

	Vertice.vertexBufferData.emplace_back(0.0f);
	Vertice.vertexBufferData.emplace_back(1.0f);
	Vertice.vertexBufferData.emplace_back(1.0f);
	Vertice.vertexBufferData.emplace_back(-1.0f);
	Vertice.vertexBufferData.emplace_back(-1.0f);
	Vertice.vertexBufferData.emplace_back(-1.0f);
		  
	Vertice.colorBufferData.emplace_back(1.f);
	Vertice.colorBufferData.emplace_back(0.f);
	Vertice.colorBufferData.emplace_back(0.f);
	Vertice.colorBufferData.emplace_back(0.f);
	Vertice.colorBufferData.emplace_back(1.f);
	Vertice.colorBufferData.emplace_back(0.f);
	Vertice.colorBufferData.emplace_back(0.f);
	Vertice.colorBufferData.emplace_back(0.f);
	Vertice.colorBufferData.emplace_back(1.f);

	Verticies.emplace_back(std::make_shared<verticies>(Vertice));

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