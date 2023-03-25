#pragma once

#include <glm/glm.hpp>

class Renderer
{
public:
    static void init();
    static void clear(const glm::vec4& color);
    static void drawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
};