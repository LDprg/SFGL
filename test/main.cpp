#include <vector>

#include <SFGL/loadShader.h>
#include <SFGL/window.h>
#include <SFGL/Triangel.h>
#include <SFGL/Rectangel.h>

using namespace sfgl;

std::vector<Rectangel::Rectangel> Rectangels;

int main()
{
	Window::Create();
	
	Rectangel::Rectangel rectangel;

	rectangel.EdgePos[0][0] = 1.f;
	rectangel.EdgePos[0][1] = 1.f;
	rectangel.EdgePos[1][0] = 0.f;
	rectangel.EdgePos[1][1] = 0.f;

	rectangel.EdgeColor[0] = 1.f;
	rectangel.EdgeColor[1] = 1.f;
	rectangel.EdgeColor[2] = 0.f;

	Rectangels.emplace_back(rectangel);

	Rectangel::Create(Rectangels);

	Rectangel::Update(Rectangels);

	do
	{
		Window::ClearScreen();

		Rectangel::Draw(Rectangels);

		Window::Draw();

		if (Window::GetKey(GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			Window::ShouldClose(1);
		}
	} while (!Window::ShouldClose());

	Rectangel::Clean(Rectangels);

	Window::Clean();

	return EXIT_SUCCESS;
}