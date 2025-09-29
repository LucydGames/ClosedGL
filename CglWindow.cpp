#include "CglWindow.h"

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{

	glViewport(0, 0, width, height);
	//glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT);
	//glfwSwapBuffers(window);
}

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
		glfwSetFramebufferSizeCallback(mainWindow, framebufferSizeCallback);
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
	void Window::swapBuffers()
	{
		glfwSwapBuffers(mainWindow);
	}
	void Window::pollEvents()
	{
		glfwPollEvents();
	}

	bool Window::shouldClose()
	{
		if (glfwWindowShouldClose(mainWindow))
			return true;
		else
			return false;
	}

	void Window::windowInputEvents() // Should it be in poll events? idk
	{
		if (glfwGetKey(mainWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(mainWindow, true);
	}

	
	
}