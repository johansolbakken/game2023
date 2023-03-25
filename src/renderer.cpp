#include "renderer.h"

#include <glad/glad.h>
#include <vector>

#include "shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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
    Shader* meshShader;
    Shader* meshDirectionalLightShader;

    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
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

    s_data.meshShader = new Shader(
        R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        layout (location = 1) in vec3 aNormal;
        layout (location = 2) in vec2 aTexCoords;

        out vec3 FragPos;
        out vec3 Normal;
        out vec2 TexCoords;
        
        uniform mat4 uModelMatrix;
        uniform mat4 uViewMatrix;
        uniform mat4 uProjectionMatrix;
        
        void main()
        {
            gl_Position = uProjectionMatrix * uViewMatrix * uModelMatrix * vec4(aPos, 1.0);
        }
        
        )",
        R"(
        #version 330 core
        out vec4 FragColor;

        in vec3 FragPos;
        in vec3 Normal;

        void main()
        {
            FragColor = vec4(Normal, 1.0f);
        }
        )");

    s_data.viewMatrix = glm::mat4(1.0f);
    s_data.projectionMatrix = glm::mat4(1.0f);

    s_data.meshDirectionalLightShader = new Shader(
        R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        layout (location = 1) in vec3 aNormal;
        layout (location = 2) in vec2 aTexCoords;

        out vec3 FragPos;
        out vec3 Normal;
        out vec2 TexCoords;
        
        uniform mat4 uModelMatrix;
        uniform mat4 uViewMatrix;
        uniform mat4 uProjectionMatrix;
        
        void main()
        {
            gl_Position = uProjectionMatrix * uViewMatrix * uModelMatrix * vec4(aPos, 1.0);
        }
        
        )",
        R"(
        #version 330 core
        out vec4 FragColor;

        in vec3 FragPos;
        in vec3 Normal;
        in vec2 TexCoords;

        uniform vec3 uLightColor;
        uniform vec3 uLightDirection;

        void main()
        {
            vec3 lightColor = uLightColor;
            vec3 lightDirection = normalize(uLightDirection);

            vec3 ambient = 0.1 * lightColor;
            vec3 norm = normalize(Normal);
            float diff = max(dot(norm, lightDirection), 0.0);
            vec3 diffuse = diff * lightColor;

            vec3 result = (ambient + diffuse) * vec3(1.0, 0.5, 0.31);
            FragColor = vec4(result, 1.0f);
        }
        )");
}

void Renderer::clear(const glm::vec4 &color)
{
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::updateViewport(int width, int height)
{
    glViewport(0, 0, width, height);
    s_data.projectionMatrix = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
}

void Renderer::drawQuad(const glm::vec2 &position, const glm::vec2 &size, const glm::vec4 &color)
{
    s_data.quadColorShader->use();
    s_data.quadColorShader->setVec4("uColor", color);

    glBindVertexArray(s_data.quadVAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer::drawMesh(const Mesh &mesh, const glm::mat4 &modelMatrix)
{
    s_data.meshDirectionalLightShader->use();
    s_data.meshDirectionalLightShader->setMat4("uModelMatrix", modelMatrix);
    s_data.meshDirectionalLightShader->setMat4("uViewMatrix", s_data.viewMatrix);
    s_data.meshDirectionalLightShader->setMat4("uProjectionMatrix", s_data.projectionMatrix);
    s_data.meshDirectionalLightShader->setVec3("uLightColor", glm::vec3(1.0f, 1.0f, 1.0f));
    s_data.meshDirectionalLightShader->setVec3("uLightDirection", glm::vec3(0.0f, -1.0f, 0.0f));

    glBindVertexArray(mesh.getVAO());
    glDrawElements(GL_TRIANGLES, mesh.getIndices().size(), GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}

