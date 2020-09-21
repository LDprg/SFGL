#include "Triangel.h"

namespace sfgl
{

	void Triangel2Verticies(std::vector<Triangel>& Triangels, std::vector<std::shared_ptr<Verticies>>& Vertex)
	{
		for (int i = 0; i < Triangels.size(); i++)
		{
			while (Triangels.size() > Vertex.size() - Triangels.size() * i)
			{
				Vertex.emplace_back(std::make_shared<Verticies>());
			}

			Vertex[i]->vertexBufferData.clear();

			for (int j = 0; j < 3; j++)
			{
				Vertex[i]->vertexBufferData.emplace_back(Triangels[i].EdgePos[j][0]);
				Vertex[i]->vertexBufferData.emplace_back(Triangels[i].EdgePos[j][1]);
			}

			Vertex[i]->colorBufferData.clear();

			for (int j = 0; j < 3; j++)
			{
				Vertex[i]->colorBufferData.emplace_back(Triangels[i].EdgeColor[j][0]);
				Vertex[i]->colorBufferData.emplace_back(Triangels[i].EdgeColor[j][1]);
				Vertex[i]->colorBufferData.emplace_back(Triangels[i].EdgeColor[j][2]);
			}
		}
	}

}