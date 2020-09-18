#include "window.h"

GLFWwindow* m_window;
GLuint m_VertexArrayID;
GLuint m_programID;

void WindowCreate()
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

	// Create window
	m_window = glfwCreateWindow(1024, 768, "SFGL", nullptr, nullptr);
	if (!m_window)
	{
		glfwTerminate();
		throw std::runtime_error("Failed to create Window!");
	}

	// Create OpenGL context
	glfwMakeContextCurrent(m_window);

	//Init glew
	if (glewInit() != GLEW_OK)
	{
		throw std::runtime_error("Failed to initialize GLEW");
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	glGenVertexArrays(1, &m_VertexArrayID);
	glBindVertexArray(m_VertexArrayID);

	// Create and compile our GLSL program from the shaders
	m_programID = LoadShaders("shader.vert", "shader.frag");
}

GLFWwindow* WindowGetHandle()
{
	return m_window;
}

void WindowDraw()
{
	// Swap buffer
	glfwSwapBuffers(m_window);
	glfwPollEvents();

	// Use shader
	glUseProgram(m_programID);
}

void WindowClearScreen()
{
	// Dark blue background
	glClearColor(0.f, 0.f, 0.4f, 0.f);
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

int WindowShouldClose()
{
	return	glfwWindowShouldClose(m_window);
}

void WindowClean()
{
	glDeleteVertexArrays(1, &m_VertexArrayID);
	glDeleteProgram(m_programID);

	// Close OpenGL window and terminate GLFW
	glfwDestroyWindow(m_window);
	glfwTerminate();
}