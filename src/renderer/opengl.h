#pragma once

#include <glad/glad.h>

#ifndef NDEBUG
#ifdef _WIN32
#define ASSERT(x) if (!(x)) __debugbreak();
#else // _WIN32
#define ASSERT(x) if (!(x)) __builtin_trap();
#endif // _WIN32
#else   // !NDEBUG
#define ASSERT(x) x
#endif // !NDEBUG

#define GL_CALL(x) \
    glClearErrors(); \
    x; \
    glLogCall(#x, __FILE__, __LINE__)

void glClearErrors();
void glLogCall(const char* function, const char* file, int line);