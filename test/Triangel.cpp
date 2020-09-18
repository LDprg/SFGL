#include "Triangel.h"

void Triangel2Verticies(std::vector<Triangel> &Triangels, std::vector<verticies>& Verticies)
{
	for (int i = 0; i < Triangels.size(); i++)
	{
		Verticies[i].vertexBufferData.clear();

		for (int i = 0; i < 3; i++)
		{
			Verticies[i].vertexBufferData.emplace_back(Triangels[i].EdgePos[i*2].x);
			Verticies[i].vertexBufferData.emplace_back(Triangels[i].EdgePos[i*2 + 1].y);
		}

		Verticies[i].colorBufferData.clear();
		
		for (int i = 0; i < 3; i++)
		{
			Verticies[i].vertexBufferData.emplace_back(Triangels[i].EdgeColor[i*3].r);
			Verticies[i].vertexBufferData.emplace_back(Triangels[i].EdgeColor[i*3 + 1].g);
			Verticies[i].vertexBufferData.emplace_back(Triangels[i].EdgeColor[i*3 + 2].b);
		}
	}
}