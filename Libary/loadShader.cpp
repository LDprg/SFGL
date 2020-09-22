#include "SFGL/loadShader.h"

namespace sfgl
{
	namespace Shader
	{

		GLuint loadFromFile(const char* vertex_file_path, const char* fragment_file_path)
		{
			// Create the shaders
			GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
			GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

			// Read the Vertex Shader code from the file
			std::string VertexShaderCode = "";
			std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
			if (VertexShaderStream.is_open())
			{
				VertexShaderCode.assign(std::istreambuf_iterator<char>(VertexShaderStream), std::istreambuf_iterator<char>());
				VertexShaderStream.close();
			}
			else
			{
				printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
				getchar();
				return 0;
			}

			// Read the Fragment Shader code from the file
			std::string FragmentShaderCode = "";
			std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
			if (FragmentShaderStream.is_open())
			{
				FragmentShaderCode.assign(std::istreambuf_iterator<char>(FragmentShaderStream), std::istreambuf_iterator<char>());
				FragmentShaderStream.close();
			}

			GLint Result = GL_FALSE;
			int InfoLogLength;

			// Compile Vertex Shader
			printf("Compiling shader : %s\n", vertex_file_path);
			char const* VertexSourcePointer = VertexShaderCode.c_str();
			glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
			glCompileShader(VertexShaderID);

			// Check Vertex Shader
			glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
			glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
			if (InfoLogLength > 0)
			{
				std::vector<char> VertexShaderErrorMessage((unsigned __int64)InfoLogLength + 1);
				glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
				printf("%s\n", &VertexShaderErrorMessage[0]);
			}

			// Compile Fragment Shader
			printf("Compiling shader : %s\n", fragment_file_path);
			char const* FragmentSourcePointer = FragmentShaderCode.c_str();
			glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
			glCompileShader(FragmentShaderID);

			// Check Fragment Shader
			glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
			glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
			if (InfoLogLength > 0)
			{
				std::vector<char> FragmentShaderErrorMessage((unsigned __int64)InfoLogLength + 1);
				glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
				printf("%s\n", &FragmentShaderErrorMessage[0]);
			}

			// Link the program
			printf("Linking program\n");
			GLuint ProgramID = glCreateProgram();
			glAttachShader(ProgramID, VertexShaderID);
			glAttachShader(ProgramID, FragmentShaderID);
			glLinkProgram(ProgramID);

			// Check the program
			glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
			glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
			if (InfoLogLength > 0)
			{
				std::vector<char> ProgramErrorMessage((unsigned __int64)InfoLogLength + 1);
				glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
				printf("%s\n", &ProgramErrorMessage[0]);
			}

			glDetachShader(ProgramID, VertexShaderID);
			glDetachShader(ProgramID, FragmentShaderID);

			glDeleteShader(VertexShaderID);
			glDeleteShader(FragmentShaderID);

			return ProgramID;
		}

		GLuint loadStd()
		{
			// Create the shaders
			GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
			GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

			const char VertexShaderCode[] = 
				"#version 330 core\n"
				"layout(location = 0) in vec2 vertexPosition;"
				"layout(location = 1) in vec3 vertexColor;"
				"out vec3 fragColor;"
				"void main()"
				"{"
				"	gl_Position.xy = vertexPosition;"
				"	gl_Position.z = 0;"
				"	gl_Position.w = 1;"
				"	fragColor = vertexColor;"
				"}";

			// Read the Fragment Shader code from the file
			const char FragmentShaderCode[] = 
				"#version 330 core\n"
				"in vec3 fragColor;"
				"out vec3 color;"
				"void main()"
				"{"
				"	color = fragColor;"
				"}";

			GLint Result = GL_FALSE;
			int InfoLogLength;

			// Compile Vertex Shader
			printf("Compiling Vertex Shader");
			char const* VertexSourcePointer = VertexShaderCode;
			glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
			glCompileShader(VertexShaderID);

			// Check Vertex Shader
			glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
			glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
			if (InfoLogLength > 0)
			{
				std::vector<char> VertexShaderErrorMessage((unsigned __int64)InfoLogLength + 1);
				glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
				printf("%s\n", &VertexShaderErrorMessage[0]);
			}

			// Compile Fragment Shader
			printf("Compiling Fragment Shader");
			char const* FragmentSourcePointer = FragmentShaderCode;
			glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
			glCompileShader(FragmentShaderID);

			// Check Fragment Shader
			glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
			glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
			if (InfoLogLength > 0)
			{
				std::vector<char> FragmentShaderErrorMessage((unsigned __int64)InfoLogLength + 1);
				glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
				printf("%s\n", &FragmentShaderErrorMessage[0]);
			}

			// Link the program
			printf("Linking program\n");
			GLuint ProgramID = glCreateProgram();
			glAttachShader(ProgramID, VertexShaderID);
			glAttachShader(ProgramID, FragmentShaderID);
			glLinkProgram(ProgramID);

			// Check the program
			glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
			glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
			if (InfoLogLength > 0)
			{
				std::vector<char> ProgramErrorMessage((unsigned __int64)InfoLogLength + 1);
				glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
				printf("%s\n", &ProgramErrorMessage[0]);
			}

			glDetachShader(ProgramID, VertexShaderID);
			glDetachShader(ProgramID, FragmentShaderID);

			glDeleteShader(VertexShaderID);
			glDeleteShader(FragmentShaderID);

			return ProgramID;
		}

	}
}