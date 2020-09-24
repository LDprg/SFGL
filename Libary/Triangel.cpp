#include "SFGL/Triangel.h"

void sfgl::Triangel::Swap(Triangel& T1, Triangel& T2)
{
	std::swap(T1, T2);
}

void  sfgl::Triangel::Create(std::vector<Triangel>& Triangels)
{
	for (int i = 0; i < Triangels.size(); i++)
	{
		Create(Triangels[i]);
	}
}

void  sfgl::Triangel::Create(Triangel& Triangels)
{
	Triangels.Vertex = std::shared_ptr<Verticies::Verticies>(new Verticies::Verticies);

	Triangels.Vertex->vertexBufferData.reserve(6);
	Triangels.Vertex->colorBufferData.reserve(9);
}

void  sfgl::Triangel::Update(std::vector<Triangel>& Triangels)
{
	for (int i = 0; i < Triangels.size();i++)
	{
		Update(Triangels[i]);
	}
}

void  sfgl::Triangel::Update(Triangel& Triangels)
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

void  sfgl::Triangel::Draw(std::vector<Triangel>& Triangels)
{
	for (int i = 0; i < Triangels.size(); i++)
	{
		Draw(Triangels[i]);
	}
}

void  sfgl::Triangel::Draw(Triangel& Triangels)
{
	Verticies::Draw(Triangels.Vertex, GL_TRIANGLES);
}

void  sfgl::Triangel::Clean(std::vector<Triangel>& Triangels)
{
	for (int i = 0; i < Triangels.size(); i++)
	{
		Clean(Triangels[i]);
	}
}

void  sfgl::Triangel::Clean(Triangel& Triangels)
{
	Verticies::Clean(Triangels.Vertex);
}
