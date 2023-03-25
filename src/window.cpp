#include "window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Window::Window()
{
    glfwInit();
    m_window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(m_window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Window::update()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose(m_window);
}
