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
        std::string errorString;
        switch (error)
        {
        case GL_INVALID_ENUM:
            errorString = "GL_INVALID_ENUM";
            break;
        case GL_INVALID_VALUE:
            errorString = "GL_INVALID_VALUE";
            break;
        case GL_INVALID_OPERATION:
            errorString = "GL_INVALID_OPERATION";
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            errorString = "GL_INVALID_FRAMEBUFFER_OPERATION";
            break;
        case GL_OUT_OF_MEMORY:
            errorString = "GL_OUT_OF_MEMORY";
            break;
        case GL_STACK_UNDERFLOW:
            errorString = "GL_STACK_UNDERFLOW";
            break;
        case GL_STACK_OVERFLOW:
            errorString = "GL_STACK_OVERFLOW";
            break;
        default:
            errorString = "UNKNOWN_ERROR";
            break;
        }

        std::cout << "[OpenGL Error] (" << errorString << "): " << function << " " << file << ":" << line << std::endl;
    }
}