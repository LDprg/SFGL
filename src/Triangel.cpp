#include "SFGL/Triangel.hpp"

void sfgl::Triangel::Swap(TriangelData& T1, TriangelData& T2)
{
	std::swap(T1, T2);
}

void  sfgl::Triangel::Create(std::vector<TriangelData>& Triangels)
{
	for (int i = 0; i < Triangels.size(); i++)
	{
		Create(Triangels[i]);
	}
}

void  sfgl::Triangel::Create(TriangelData& Triangels)
{
	Triangels.Vertex = std::shared_ptr<VerticiesData>(new VerticiesData);

	Triangels.Vertex->vertexBufferData.reserve(6);
	Triangels.Vertex->colorBufferData.reserve(9);
}

void  sfgl::Triangel::Update(std::vector<TriangelData>& Triangels)
{
	for (int i = 0; i < Triangels.size();i++)
	{
		Update(Triangels[i]);
	}
}

void  sfgl::Triangel::Update(TriangelData& Triangels)
{
	Triangels.Vertex->vertexBufferData.clear();

	for (int j = 0; j < 3; j++)
	{
		Triangels.Vertex->vertexBufferData.emplace_back(Triangels.EdgePos[j][0]);
		Triangels.Vertex->vertexBufferData.emplace_back(Triangels.EdgePos[j][1]);
	}

	Triangels.Vertex->colorBufferData.clear();

	for (int j = 0; j < 3; j++)
	{
		Triangels.Vertex->colorBufferData.emplace_back(Triangels.EdgeColor[j][0]);
		Triangels.Vertex->colorBufferData.emplace_back(Triangels.EdgeColor[j][1]);
		Triangels.Vertex->colorBufferData.emplace_back(Triangels.EdgeColor[j][2]);
	}
			
	Verticies::Update(Triangels.Vertex);
}

void  sfgl::Triangel::Draw(std::vector<TriangelData>& Triangels)
{
	for (int i = 0; i < Triangels.size(); i++)
	{
		Draw(Triangels[i]);
	}
}

void  sfgl::Triangel::Draw(TriangelData& Triangels)
{
	Verticies::Draw(Triangels.Vertex, GL_TRIANGLES);
}

void  sfgl::Triangel::Clean(std::vector<TriangelData>& Triangels)
{
	for (int i = 0; i < Triangels.size(); i++)
	{
		Clean(Triangels[i]);
	}
}

void  sfgl::Triangel::Clean(TriangelData& Triangels)
{
	Verticies::Clean(Triangels.Vertex);
}