#include <vector>

#include <SFGL/loadShader.hpp>
#include <SFGL/window.hpp>
#include <SFGL/Triangel.hpp>
#include <SFGL/Rectangel.hpp>

using namespace sfgl;

std::vector<RectangelData> Rectangels;

Window window;

int main()
{
	window.Create();
	
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
		window.ClearScreen();

		Rectangel::Draw(Rectangels);

		window.Draw();

		if (window.GetKey(GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			window.ShouldClose(1);
		}
	} while (!window.ShouldClose());

	Rectangel::Clean(Rectangels);

	window.Clean();

	return EXIT_SUCCESS;
}