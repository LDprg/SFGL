#include "Triangel.h"

std::vector<verticies> Triangles;

void Triangel2Verticies(std::vector<Triangel> &Triangels, std::vector<verticies>& Verticies)
{
	for (int i = 0; i < Triangels.size(); i++)
	{
		Verticies[i].vertexBufferData.clear();

		for (int i = 0; i < 3; i++)
		{
			Verticies[i].vertexBufferData.emplace_back((GLfloat)Triangels[i].EdgePos[i*2].x);
			Verticies[i].vertexBufferData.emplace_back((GLfloat)Triangels[i].EdgePos[i*2 + 1].y);
		}

		Verticies[i].colorBufferData.clear();
		
		for (int i = 0; i < 3; i++)
		{
			Verticies[i].vertexBufferData.emplace_back((GLfloat)Triangels[i].EdgeColor[i*3].r);
			Verticies[i].vertexBufferData.emplace_back((GLfloat)Triangels[i].EdgeColor[i*3 + 1].g);
			Verticies[i].vertexBufferData.emplace_back((GLfloat)Triangels[i].EdgeColor[i*3 + 2].b);
		}
	}
}

void TriangelCreate()
{
	Triangles.emplace_back();

	Triangles[0].vertexBufferData.emplace_back(0.0f);
	Triangles[0].vertexBufferData.emplace_back(1.0f);
	Triangles[0].vertexBufferData.emplace_back(1.0f);
	Triangles[0].vertexBufferData.emplace_back(-1.0f);
	Triangles[0].vertexBufferData.emplace_back(-1.0f);
	Triangles[0].vertexBufferData.emplace_back(-1.0f);
			
	Triangles[0].colorBufferData.emplace_back(1.f);
	Triangles[0].colorBufferData.emplace_back(0.f);
	Triangles[0].colorBufferData.emplace_back(0.f);
	Triangles[0].colorBufferData.emplace_back(0.f);
	Triangles[0].colorBufferData.emplace_back(1.f);
	Triangles[0].colorBufferData.emplace_back(0.f);
	Triangles[0].colorBufferData.emplace_back(0.f);
	Triangles[0].colorBufferData.emplace_back(0.f);
	Triangles[0].colorBufferData.emplace_back(1.f);

	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &Triangles[0].vertexBuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, Triangles[0].vertexBuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * Triangles[0].vertexBufferData.size(), Triangles[0].vertexBufferData.data(), GL_STATIC_DRAW);

	// Generate 1 buffer, put the resulting identifier in colorbuffer
	glGenBuffers(1, &Triangles[0].colorBuffer);
	// The following commands will talk about our 'colorbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, Triangles[0].colorBuffer);
	// Give our color to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * Triangles[0].colorBufferData.size(), Triangles[0].colorBufferData.data(), GL_STATIC_DRAW);
}

void TriangelDraw()
{
	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, Triangles[0].vertexBuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		2,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	// 2nd attribute buffer : color
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, Triangles[0].colorBuffer);
	glVertexAttribPointer(
		1,                  // attribute 1. No particular reason for 1, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, (GLsizei)Triangles[0].vertexBufferData.size() / 2); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glDisableVertexAttribArray(0);
}

void TriangelClean()
{
	// Cleanup VBO
	glDeleteBuffers(1, &Triangles[0].vertexBuffer);
	glDeleteBuffers(1, &Triangles[0].colorBuffer);
}