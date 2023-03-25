#pragma once

#include <glm/glm.hpp>

#include "mesh.h"

class Renderer
{
public:
    static void init();
    static void clear(const glm::vec4& color);
    static void updateViewport(int width, int height);
    static void drawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
    static void drawMesh(const Mesh& mesh, const glm::mat4& modelMatrix);
};