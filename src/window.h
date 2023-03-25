#pragma once

struct GLFWwindow;

class Window
{
public:
    Window();
    ~Window();
    void update();
    bool shouldClose();

private:
    GLFWwindow *m_window = nullptr;
};