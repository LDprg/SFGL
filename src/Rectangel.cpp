#include "SFGL\Rectangel.hpp"

void sfgl::Rectangel::Swap(RectangelData& R1, RectangelData& R2)
{
	std::swap(R1, R2);
}

void sfgl::Rectangel::Create(std::vector<RectangelData>& Rectangels)
{
	for (int i = 0; i < Rectangels.size(); i++)
	{
		Create(Rectangels[i]);
	}
}

void sfgl::Rectangel::Create(RectangelData& Rectangels)
{
	Rectangels.Vertex = std::shared_ptr<VerticiesData>(new VerticiesData);

	Rectangels.Vertex->vertexBufferData.reserve(8);
	Rectangels.Vertex->colorBufferData.reserve(12);
}

void sfgl::Rectangel::Update(std::vector<RectangelData>& Rectangels)
{
	for (int i = 0; i < Rectangels.size(); i++)
	{
		Update(Rectangels[i]);
	}
}

void sfgl::Rectangel::Update(RectangelData& Rectangels)
{
	Rectangels.Vertex->vertexBufferData.clear();

	Rectangels.Vertex->vertexBufferData.emplace_back(Rectangels.EdgePos[0][0]);
	Rectangels.Vertex->vertexBufferData.emplace_back(Rectangels.EdgePos[0][1]);

	Rectangels.Vertex->vertexBufferData.emplace_back(Rectangels.EdgePos[0][0]);
	Rectangels.Vertex->vertexBufferData.emplace_back(Rectangels.EdgePos[1][1]);

	Rectangels.Vertex->vertexBufferData.emplace_back(Rectangels.EdgePos[1][0]);
	Rectangels.Vertex->vertexBufferData.emplace_back(Rectangels.EdgePos[0][1]);

	Rectangels.Vertex->vertexBufferData.emplace_back(Rectangels.EdgePos[1][0]);
	Rectangels.Vertex->vertexBufferData.emplace_back(Rectangels.EdgePos[1][1]);

	Rectangels.Vertex->colorBufferData.clear();

	for (int j = 0; j < 4; j++)
	{
		Rectangels.Vertex->colorBufferData.emplace_back(Rectangels.EdgeColor[0]);
		Rectangels.Vertex->colorBufferData.emplace_back(Rectangels.EdgeColor[1]);
		Rectangels.Vertex->colorBufferData.emplace_back(Rectangels.EdgeColor[2]);
	}

	Verticies::Update(Rectangels.Vertex);
}

void sfgl::Rectangel::Draw(std::vector<RectangelData>& Rectangels)
{
	for (int i = 0; i < Rectangels.size(); i++)
	{
		Draw(Rectangels[i]);
	}
}

void sfgl::Rectangel::Draw(RectangelData& Rectangels)
{
	Verticies::Draw(Rectangels.Vertex, GL_TRIANGLE_STRIP);
}

void sfgl::Rectangel::Clean(std::vector<RectangelData>& Rectangels)
{
	for (int i = 0; i < Rectangels.size(); i++)
	{
		Clean(Rectangels[i]);
	}
}

void sfgl::Rectangel::Clean(RectangelData& Rectangels)
{
	Verticies::Clean(Rectangels.Vertex);
}
