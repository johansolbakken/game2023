#include "renderer.h"

#include <vector>

#include "shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct RendererData
{
	uint32_t quadVAO = 0;
	uint32_t quadVBO = 0;
	uint32_t quadEBO = 0;

	glm::mat4 projectionMatrix = glm::mat4(1.0f);

	std::shared_ptr<Shader> quadColorShader;
};

static RendererData s_data = {};

void Renderer::init()
{
	s_data.quadColorShader = Shader::create("assets/shaders/quad_color.vs", "assets/shaders/quad_color.fs");

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
/*
	GL_CALL(glGenVertexArrays(1, &s_data.quadVAO));
	GL_CALL(glGenBuffers(1, &s_data.quadVBO));
	GL_CALL(glGenBuffers(1, &s_data.quadEBO));

	GL_CALL(glBindVertexArray(s_data.quadVAO));
	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, s_data.quadVBO));

	GL_CALL(glBufferData(GL_ARRAY_BUFFER, quadVertices.size() * sizeof(float), &quadVertices[0], GL_STATIC_DRAW));

	GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_data.quadEBO));
	GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, quadIndices.size() * sizeof(uint32_t), &quadIndices[0], GL_STATIC_DRAW));

	// vertex positions
	GL_CALL(glEnableVertexAttribArray(0));
	GL_CALL(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0));
	// vertex texture coords
	GL_CALL(glEnableVertexAttribArray(1));
	GL_CALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float))));

	GL_CALL(glBindVertexArray(0));*/
}

void Renderer::shutdown()
{
	// GL_CALL(glDeleteVertexArrays(1, &s_data.quadVAO));
	// GL_CALL(glDeleteBuffers(1, &s_data.quadVBO));
	// GL_CALL(glDeleteBuffers(1, &s_data.quadEBO));
}

void Renderer::clear(const glm::vec4& color)
{
	// GL_CALL(glClearColor(color.r, color.g, color.b, color.a));
	// GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::updateViewport(int width, int height)
{
	// GL_CALL(glViewport(0, 0, width, height));
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

	// GL_CALL(glBindVertexArray(s_data.quadVAO));
	// GL_CALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
}

void Renderer::drawMesh(const Mesh& mesh, const glm::mat4& modelMatrix)
{

}

