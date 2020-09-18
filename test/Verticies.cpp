#include "Verticies.h"

void VerticiesUpdate(std::vector<verticies> &Verticies)
{
	for (verticies i : Verticies)
	{
		// Generate 1 buffer, put the resulting identifier in vertexbuffer
		glGenBuffers(1, &Verticies[0].vertexBuffer);
		// The following commands will talk about our 'vertexbuffer' buffer
		glBindBuffer(GL_ARRAY_BUFFER, Verticies[0].vertexBuffer);
		// Give our vertices to OpenGL.
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * Verticies[0].vertexBufferData.size(), Verticies[0].vertexBufferData.data(), GL_STATIC_DRAW);

		// Generate 1 buffer, put the resulting identifier in colorbuffer
		glGenBuffers(1, &Verticies[0].colorBuffer);
		// The following commands will talk about our 'colorbuffer' buffer
		glBindBuffer(GL_ARRAY_BUFFER, Verticies[0].colorBuffer);
		// Give our color to OpenGL.
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * Verticies[0].colorBufferData.size(), Verticies[0].colorBufferData.data(), GL_STATIC_DRAW);
	}
}

void VerticiesDraw(std::vector<verticies> &Verticies)
{
	for (verticies i : Verticies)
	{
		// 1st attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, i.vertexBuffer);
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
		glBindBuffer(GL_ARRAY_BUFFER, i.colorBuffer);
		glVertexAttribPointer(
			1,                  // attribute 1. No particular reason for 1, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, i.vertexBufferData.size()/2); // Starting from vertex 0; 3 vertices total -> 1 triangle
		glDisableVertexAttribArray(0);
	}
}

void VerticiesClean(std::vector<verticies> &Verticies)
{
	for (verticies i : Verticies)
	{
		// Cleanup VBO
		glDeleteBuffers(1, &i.vertexBuffer);
		glDeleteBuffers(1, &i.colorBuffer);
	}
}