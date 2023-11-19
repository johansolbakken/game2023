#include "opengl.h"

#include <iostream>

void glClearErrors()
{
    while (glGetError() != GL_NO_ERROR);
}

void glLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (" << error << "): " << function << " " << file << ":" << line << std::endl;
    }
}