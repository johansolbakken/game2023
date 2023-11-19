#include "renderer.h"

#include <glad/glad.h>
#include <vector>
#include <memory>

#include "shader.h"
#include "buffer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct RendererData
{
	uint32_t quadVAO = 0;
	uint32_t quadVBO = 0;
	uint32_t quadEBO = 0;

	glm::mat4 projectionMatrix = glm::mat4(1.0f);

	Shader* quadColorShader = nullptr;
};

static RendererData s_data = {};

void Renderer::init()
{
	s_data.quadColorShader = new Shader("shaders/quad_color.vs", "shaders/quad_color.fs");

	std::vector<float> quadVertices = {
			// positions		// texture coords	// color
			-0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
			0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, 1.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
	};

	std::vector<uint32_t> quadIndices = {
			0, 1, 2,
			2, 3, 0
	};

	glGenVertexArrays(1, &s_data.quadVAO);
	glGenBuffers(1, &s_data.quadVBO);
	glGenBuffers(1, &s_data.quadEBO);

	glBindVertexArray(s_data.quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, s_data.quadVBO);

	glBufferData(GL_ARRAY_BUFFER, quadVertices.size() * sizeof(float), &quadVertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_data.quadEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, quadIndices.size() * sizeof(uint32_t), &quadIndices[0], GL_STATIC_DRAW);

	// vertex positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	// vertex texture coords
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));

	glBindVertexArray(0);
}

void Renderer::clear(const glm::vec4& color)
{
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::updateViewport(int width, int height)
{
	glViewport(0, 0, width, height);
}

void Renderer::beginScene(const glm::mat4& viewProjectionMatrix)
{
	s_data.projectionMatrix = viewProjectionMatrix;
}

void Renderer::endScene()
{
}

void Renderer::drawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
{
	s_data.quadColorShader->use();
	s_data.quadColorShader->setVec4("u_color", color);
	s_data.quadColorShader->setMat4("u_projection", s_data.projectionMatrix);

	glBindVertexArray(s_data.quadVAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer::drawMesh(const Mesh& mesh, const glm::mat4& modelMatrix)
{

}

