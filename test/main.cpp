#include <vector>

#include <SFGL/Graphics/loadShader.hpp>
#include <SFGL/Graphics/Window.hpp>

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