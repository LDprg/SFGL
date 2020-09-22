#include "SFGL/Triangel.h"

namespace sfgl
{
	namespace Triangel
	{
		void Swap(Triangel& T1, Triangel& T2)
		{
			std::swap(T1, T2);
		}

		void Create(std::vector<Triangel>& Triangels)
		{
			for (int i = 0; i < Triangels.size(); i++)
			{
				Create(Triangels[i]);
			}
		}

		void Create(Triangel& Triangels)
		{
			Triangels.Vertex = std::shared_ptr<Verticies::Verticies>(new Verticies::Verticies);

			Triangels.Vertex->vertexBufferData.reserve(6);
			Triangels.Vertex->colorBufferData.reserve(9);
		}

		void Update(std::vector<Triangel>& Triangels)
		{
			for (int i = 0; i < Triangels.size();i++)
			{
				Update(Triangels[i]);
			}
		}

		void Update(Triangel& Triangels)
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

		void Draw(std::vector<Triangel>& Triangels)
		{
			for (int i = 0; i < Triangels.size(); i++)
			{
				Draw(Triangels[i]);
			}
		}

		void Draw(Triangel& Triangels)
		{
			Verticies::Draw(Triangels.Vertex, GL_TRIANGLES);
		}

		void Clean(std::vector<Triangel>& Triangels)
		{
			for (int i = 0; i < Triangels.size(); i++)
			{
				Clean(Triangels[i]);
			}
		}

		void Clean(Triangel& Triangels)
		{
			Verticies::Clean(Triangels.Vertex);
		}

	}
}