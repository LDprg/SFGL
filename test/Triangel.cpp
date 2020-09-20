#include "Triangel.h"

void Triangel2Verticies(std::vector<Triangel> &Triangels, std::vector<std::shared_ptr<verticies>>& Verticies)
{
	for (int i = 0; i < Triangels.size(); i++)
	{
		while (Triangels.size() > Verticies.size()- Triangels.size()*i)
		{
			Verticies.emplace_back(std::make_shared<verticies>());
		}

		Verticies[i]->vertexBufferData.clear();

		for (int j = 0; j < 3; j++)
		{
			Verticies[i]->vertexBufferData.emplace_back(Triangels[i].EdgePos[j][0]);
			Verticies[i]->vertexBufferData.emplace_back(Triangels[i].EdgePos[j][1]);
		}

		Verticies[i]->colorBufferData.clear();
		
		for (int j = 0; j < 3; j++)
		{
			Verticies[i]->colorBufferData.emplace_back(Triangels[i].EdgeColor[j][0]);
			Verticies[i]->colorBufferData.emplace_back(Triangels[i].EdgeColor[j][1]);
			Verticies[i]->colorBufferData.emplace_back(Triangels[i].EdgeColor[j][2]);
		}
	}
}