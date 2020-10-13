#include <vector>

#include <SFGL/loadShader.hpp>
#include <SFGL/window.hpp>

using namespace sfgl;

Window window;

int main()
{
	window.Create();

	do
	{
		window.ClearScreen();


		window.Draw();

		if (window.GetKey(GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			window.ShouldClose(1);
		}
	} while (!window.ShouldClose());

	window.Clean();

	return EXIT_SUCCESS;
}