#include "SFGL/window.hpp"

void error_callback(int error, const char* description)
{
	std::cerr << "Error " << error << ": " << description << std::endl;
}


void sfgl::Window::Create()
{
	glfwSetErrorCallback(error_callback);

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
	mWindow = glfwCreateWindow(1024, 768, "SFGL", nullptr, nullptr);

	if (mWindow == nullptr)
	{
		glfwTerminate();
		throw std::runtime_error("Failed to create Window!");
	}

	// Create OpenGL context
	glfwMakeContextCurrent(mWindow);

	//Init glew
	if (gl3wInit() != GL3W_OK)
	{
		throw std::runtime_error("Failed to initialize GLEW");
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(mWindow, GLFW_STICKY_KEYS, GL_TRUE);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	glGenVertexArrays(1, &mVertexArrayID);
	glBindVertexArray(mVertexArrayID);

	// Create and compile our GLSL program from the shaders
	//mProgramID = Shader::loadFromFile("shader.vert", "shader.frag");
	mProgramID = Shader::loadStd();
}