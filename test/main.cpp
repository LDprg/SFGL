#include <iostream>
#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

//#include <glm/glm.hpp>

//#include "loadTexture.h"

#include "window.h"
#include "Verticies.h"
#include "Triangel.h"

using namespace sfgl;

std::vector<Triangel> Triangels;
std::vector<std::shared_ptr<verticies>> Verticies;

int main()
{
	WindowCreate();
	
	Triangel triangle;

	triangle.EdgePos[0][0] = 0.f;
	triangle.EdgePos[0][1] = 1.f;
	triangle.EdgePos[1][0] = 1.f;
	triangle.EdgePos[1][1] = -1.f;
	triangle.EdgePos[2][0] = -1.f;
	triangle.EdgePos[2][1] = -1.f;

	triangle.EdgeColor[0][0] = 1.f;
	triangle.EdgeColor[0][1] = 0.f;
	triangle.EdgeColor[0][2] = 0.f;
	triangle.EdgeColor[1][0] = 0.f;
	triangle.EdgeColor[1][1] = 1.f;
	triangle.EdgeColor[1][2] = 0.f;
	triangle.EdgeColor[2][0] = 0.f;
	triangle.EdgeColor[2][1] = 0.f;
	triangle.EdgeColor[2][2] = 1.f;

	Triangels.emplace_back(triangle);

	Triangel2Verticies(Triangels, Verticies);

	VerticiesUpdate(Verticies);

	do
	{
		WindowClearScreen();

		VerticiesDraw(Verticies);

		WindowDraw();

		if (WindowGetKey(GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			WindowShouldClose(1);
		}
	} while (!WindowShouldClose());

	VerticiesClean(Verticies);

	WindowClean();

	return EXIT_SUCCESS;
}