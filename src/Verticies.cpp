#include "SFGL/Verticies.hpp"

void sfgl::Verticies::Update(std::vector<std::shared_ptr<VerticiesData>> Verticies)
{
	for (int i = 0; i < Verticies.size(); i++)
	{
		Update(Verticies[i]);
	}
}

void sfgl::Verticies::Update(std::shared_ptr<VerticiesData> Verticies)
{
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &Verticies->vertexBuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, Verticies->vertexBuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * Verticies->vertexBufferData.size(), Verticies->vertexBufferData.data(), GL_STATIC_DRAW);

	// Generate 1 buffer, put the resulting identifier in colorbuffer
	glGenBuffers(1, &Verticies->colorBuffer);
	// The following commands will talk about our 'colorbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, Verticies->colorBuffer);
	// Give our color to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * Verticies->colorBufferData.size(), Verticies->colorBufferData.data(), GL_STATIC_DRAW);
}

void sfgl::Verticies::Draw(std::vector<std::shared_ptr<VerticiesData>> Verticies, GLenum mode)
{
	for (int i = 0; i < Verticies.size(); i++)
	{
		Draw(Verticies[i], mode);
	}
}

void sfgl::Verticies::Draw(std::shared_ptr<VerticiesData> Verticies, GLenum mode)
{
	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, Verticies->vertexBuffer);
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
	glBindBuffer(GL_ARRAY_BUFFER, Verticies->colorBuffer);
	glVertexAttribPointer(
		1,                  // attribute 1. No particular reason for 1, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	// Draw the triangle !
	glDrawArrays(/*GL_TRIANGLE_STRIP*/mode, 0, (GLsizei)Verticies->vertexBufferData.size() / 2); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glDisableVertexAttribArray(0);
}

void sfgl::Verticies::Clean(std::vector<std::shared_ptr<VerticiesData>> Verticies)
{
	for (int i = 0; i < Verticies.size(); i++)
	{
		Clean(Verticies[i]);
	}
}

void sfgl::Verticies::Clean(std::shared_ptr<VerticiesData> Verticies)
{
	// Cleanup VBO
	glDeleteBuffers(1, &Verticies->vertexBuffer);
	glDeleteBuffers(1, &Verticies->colorBuffer);
}
