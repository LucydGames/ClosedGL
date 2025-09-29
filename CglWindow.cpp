#include "CglWindow.h"

namespace Cgl
{
	
	Window::Window(uint16_t w, uint16_t h, const char* title) : width{ w }, height{ h }, windowTitle{ title }
	{
		if (!glfwInit())
		{
			throw std::runtime_error("Failed to initialize GLFW");
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		mainWindow = glfwCreateWindow(width, height, windowTitle, NULL, NULL);
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
		glViewport(0, 0, 800, 600);
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(mainWindow);
		
	}

	
	Window::~Window()
	{
		glfwDestroyWindow(mainWindow);
		mainWindow = nullptr;
		glfwTerminate();
	}
	void Window::makeContextCurrent()
	{
		glfwMakeContextCurrent(mainWindow);
		
	}
	void Window::pollEvents()
	{
		glfwPollEvents();
	}

	
	
}