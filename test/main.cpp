#include <vector>

#include <SFGL/loadShader.hpp>
#include <SFGL/window.hpp>
#include <SFGL/Triangel.hpp>
#include <SFGL/Rectangel.hpp>

using namespace sfgl;

std::vector<RectangelData> Rectangels;

WindowData window;

int main()
{
	Window::Create(window);
	
	RectangelData rectangel;

	rectangel.EdgePos[0][0] = 1.f;
	rectangel.EdgePos[0][1] = 1.f;
	rectangel.EdgePos[1][0] = 0.f;
	rectangel.EdgePos[1][1] = 0.f;

	rectangel.EdgeColor[0] = 0.f;
	rectangel.EdgeColor[1] = 1.f;
	rectangel.EdgeColor[2] = 0.f;

	Rectangels.emplace_back(rectangel);

	Rectangel::Create(Rectangels);

	Rectangel::Update(Rectangels);

	do
	{
		Window::ClearScreen(window);

		Rectangel::Draw(Rectangels);

		Window::Draw(window);

		if (Window::GetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			Window::ShouldClose(window, 1);
		}
	} while (!Window::ShouldClose(window));

	Rectangel::Clean(Rectangels);

	Window::Clean(window);

	return EXIT_SUCCESS;
}