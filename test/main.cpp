#include <vector>

#include <SFGL/loadShader.h>
#include <SFGL/window.h>
#include <SFGL/Triangel.h>

using namespace sfgl;

std::vector<Triangel::Triangel> Triangels;

int main()
{
	Window::Create();
	
	Triangel::Triangel triangle;

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

	triangle.EdgePos[0][0] = 1.f;
	triangle.EdgePos[0][1] = 0.f;
	triangle.EdgePos[1][0] = 1.f;
	triangle.EdgePos[1][1] = -1.f;
	triangle.EdgePos[2][0] = -0.f;
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

	Triangel::Swap(Triangels[0], Triangels[1]);

	Triangel::Create(Triangels);

	Triangel::Update(Triangels);

	do
	{
		Window::ClearScreen();

		Triangel::Draw(Triangels);

		Window::Draw();

		if (Window::GetKey(GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			Window::ShouldClose(1);
		}
	} while (!Window::ShouldClose());

	Triangel::Clean(Triangels);

	Window::Clean();

	return EXIT_SUCCESS;
}