#pragma once

#include <glm/glm.hpp>

class MetalRendererApi 
{
public:
    static void init();
    static void shutdown();
    static void clear(const glm::vec4& color);
    static void updateViewport(int width, int height);
};
