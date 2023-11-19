#include "window.h"

#include <GLFW/glfw3.h>
#include <iostream>

void error_callback(int error, const char* description)
{
	std::cerr << "[GLFW] Error: " << description << std::endl;
}

Window::Window()
{
	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return;
	}

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	m_window = glfwCreateWindow(800, 600, "Metal", nullptr, nullptr);
	if (!m_window)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
}

Window::~Window()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void Window::update()
{
	glfwPollEvents();
}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(m_window);
}
