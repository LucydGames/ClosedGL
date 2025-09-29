#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stdexcept>

namespace Cgl
{
	class Window
	{
	public:
		Window(int width, int height, const char* title);
		~Window();
		void makeContextCurrent();
		//void swapBuffers();
		void pollEvents();
		//bool shouldClose();
		//void setShouldClose(bool value);
		//void getWindowSize(int& width, int& height);
		//void setViewport();
		//bool isKeyPressed(int key);
		//void clear(float r, float g, float b, float a);
		void framebufferSizeCallback([[maybe_unused]] GLFWwindow* window, int width, int height);
		//void setFramebufferSizeCallback();
	private:
		GLFWwindow* mainWindow;
	};
}
