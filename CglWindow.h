#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stdexcept>

namespace Cgl
{
	class Window
	{
	public:
		Window(uint16_t width, uint16_t height, const char* title);
		~Window();
		void makeContextCurrent();
		void swapBuffers();
		void pollEvents();
		bool shouldClose();
		//void setShouldClose(bool value);
		//void getWindowSize(int& width, int& height);
		//void setViewport();
		//bool isKeyPressed(int key);
		//void clear(float r, float g, float b, float a);
		void windowInputEvents();
		GLFWwindow* getMainWindow() { return mainWindow; };
		
		
		uint16_t width;
		uint16_t height;
		const char* windowTitle;
	private:
		//bool pollWindowSpecificEvents;
		GLFWwindow* mainWindow;
	};
}
