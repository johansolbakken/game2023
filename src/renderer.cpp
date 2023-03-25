#include "renderer.h"

#include <glad/glad.h>
#include <vector>

#include "shader.h"

std::vector<float> quadVertices = {
    -0.5f, -0.5f, 0.0f, 0.0f,
    0.5f, -0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, 1.0f, 1.0f,
    -0.5f, 0.5f, 0.0f, 1.0f};

std::vector<unsigned int> quadIndices = {
    0, 1, 2,
    2, 3, 0};

struct RendererData
{
    uint32_t quadVAO;
    uint32_t quadVBO;
    uint32_t quadEBO;
    Shader* quadColorShader;
};

static RendererData s_data;

void Renderer::init()
{
    glGenVertexArrays(1, &s_data.quadVAO);
    glGenBuffers(1, &s_data.quadVBO);
    glGenBuffers(1, &s_data.quadEBO);

    glBindVertexArray(s_data.quadVAO);

    glBindBuffer(GL_ARRAY_BUFFER, s_data.quadVBO);
    glBufferData(GL_ARRAY_BUFFER, quadVertices.size() * sizeof(float), &quadVertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_data.quadEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, quadIndices.size() * sizeof(unsigned int), &quadIndices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)(2 * sizeof(float)));

    // generate quad color shader
    s_data.quadColorShader = new Shader(R"(
        #version 330 core
        layout (location = 0) in vec2 aPos;
        void main()
        {
            gl_Position = vec4(aPos, 0.0, 1.0);
        }
    )", R"(
        #version 330 core
        out vec4 FragColor;
        uniform vec4 uColor;
        void main()
        {
            FragColor = uColor;
        }
    )");
}

void Renderer::clear(const glm::vec4 &color)
{
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::drawQuad(const glm::vec2 &position, const glm::vec2 &size, const glm::vec4 &color)
{
    s_data.quadColorShader->use();
    s_data.quadColorShader->setVec4("uColor", color);

    glBindVertexArray(s_data.quadVAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}