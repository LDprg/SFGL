#include "window.h"

namespace sfgl
{

	static GLFWwindow* w_window;
	static GLuint w_VertexArrayID;
	static GLuint w_programID;

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
		w_window = glfwCreateWindow(1024, 768, "SFGL", nullptr, nullptr);
		if (!w_window)
		{
			glfwTerminate();
			throw std::runtime_error("Failed to create Window!");
		}

		// Create OpenGL context
		glfwMakeContextCurrent(w_window);

		//Init glew
		if (glewInit() != GLEW_OK)
		{
			throw std::runtime_error("Failed to initialize GLEW");
		}

		// Ensure we can capture the escape key being pressed below
		glfwSetInputMode(w_window, GLFW_STICKY_KEYS, GL_TRUE);

		// Enable depth test
		glEnable(GL_DEPTH_TEST);
		// Accept fragment if it closer to the camera than the former one
		glDepthFunc(GL_LESS);

		glGenVertexArrays(1, &w_VertexArrayID);
		glBindVertexArray(w_VertexArrayID);

		// Create and compile our GLSL program from the shaders
		w_programID = LoadShaders("shader.vert", "shader.frag");
	}

	GLFWwindow* WindowGetHandle()
	{
		return w_window;
	}

	void WindowDraw()
	{
		// Swap buffer
		glfwSwapBuffers(w_window);
		glfwPollEvents();

		// Use shader
		glUseProgram(w_programID);
	}

	void WindowClearScreen()
	{
		// Dark blue background
		glClearColor(0.f, 0.f, 0.4f, 0.f);
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	int WindowGetKey(int key)
	{
		return glfwGetKey(w_window, key);
	}

	void WindowShouldClose(int state)
	{
		glfwSetWindowShouldClose(w_window, state);
	}

	int WindowShouldClose()
	{
		return	glfwWindowShouldClose(w_window);
	}

	void WindowClean()
	{
		glDeleteVertexArrays(1, &w_VertexArrayID);
		glDeleteProgram(w_programID);

		// Close OpenGL window and terminate GLFW
		glfwDestroyWindow(w_window);
		glfwTerminate();
	}

}