
#define GLFW_INCLUDE_NONE
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"CglWindow.h"
#include<iostream>


void framebufferSizeCallback([[maybe_unused]] GLFWwindow* window, int width, int height)
{
	

	glViewport(0, 0, width, height);
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);
}

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* mainWindow = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (mainWindow == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(mainWindow);
	/*
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	*/
	gladLoadGL();
	glViewport(0, 0, 800, 600);
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(mainWindow);
	glfwSetFramebufferSizeCallback(mainWindow, framebufferSizeCallback);
	while (!glfwWindowShouldClose(mainWindow))
	{
		glfwPollEvents();
		//glfwSwapBuffers(MainWindow);
		if (glfwGetKey(mainWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(mainWindow, true);
		
		
		//glfwSwapBuffers(mainWindow);
	
	}
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
	return 0;
}
