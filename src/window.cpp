#include "SFGL/window.hpp"

void sfgl::Window::Create(WindowData& window)
{
	// Init GLFW
	if (!glfwInit())
	{
		throw std::runtime_error("Failed to initialize GLFW");
	}

	glfwWindowHint(GLFW_SAMPLES, 4);	// 4 * MSAA
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	// OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);	//Just for MacOS compatiblility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	// No old OpenGL

	// Create WindowData
	window.window = glfwCreateWindow(1024, 768, "SFGL", nullptr, nullptr);
	if (!window.window)
	{
		glfwTerminate();
		throw std::runtime_error("Failed to create Window!");
	}

	// Create OpenGL context
	glfwMakeContextCurrent(window.window);

	//Init glew
	if (gl3wInit() != GL3W_OK)
	{
		throw std::runtime_error("Failed to initialize GLEW");
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window.window, GLFW_STICKY_KEYS, GL_TRUE);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	glGenVertexArrays(1, &window.VertexArrayID);
	glBindVertexArray(window.VertexArrayID);

	// Create and compile our GLSL program from the shaders
	//w_programID = Shader::loadFromFile("shader.vert", "shader.frag");
	window.programID = Shader::loadStd();
}

void sfgl::Window::Draw(WindowData& window)
{
	// Swap buffer
	glfwSwapBuffers(window.window);
	glfwPollEvents();

	// Use shader
	glUseProgram(window.programID);
}

void sfgl::Window::ClearScreen(WindowData& window)
{
	// Dark blue background
	glClearColor(0.f, 0.f, 0.4f, 0.f);
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

int sfgl::Window::GetKey(WindowData& window, int key)
{
	return glfwGetKey(window.window, key);
}

void sfgl::Window::ShouldClose(WindowData& window, int state)
{
	glfwSetWindowShouldClose(window.window, state);
}

void sfgl::Window::Clean(WindowData& window)
{
	glDeleteVertexArrays(1, &window.VertexArrayID);
	glDeleteProgram(window.programID);

	// Close OpenGL WindowData and terminate GLFW
	glfwDestroyWindow(window.window);
	glfwTerminate();
}
