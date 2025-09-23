#include "CglWindow.h"

Cgl::Window::Window(int width, int height, const char* title)
{
	if (!glfwInit())
	{
		throw std::runtime_error("Failed to initialize GLFW");
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	mainWindow = glfwCreateWindow(width, height, title, NULL, NULL);
	if (mainWindow == NULL)
	{
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}
	makeContextCurrent();
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		throw std::runtime_error("Failed to initialize GLAD");
	}
	glViewport(0, 0, width, height);
}

Cgl::Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
}

void Cgl::Window::pollEvents()
{
	glfwPollEvents();
}

void Cgl::Window::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{

}
