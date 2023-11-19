//
// Created by Johan Solbakken on 25/03/2023.
//

#include "buffer.h"

#include <glad/glad.h>

#include "renderer/opengl.h"

VertexBuffer::VertexBuffer(const std::vector<float>& data)
{
	GL_CALL(glGenBuffers(1, &m_rendererID));
	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_rendererID));
	GL_CALL(glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	GL_CALL(glDeleteBuffers(1, &m_rendererID));
}

void VertexBuffer::bind() const
{
	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_rendererID));
}

void VertexBuffer::unbind() const
{
	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

IndexBuffer::IndexBuffer(const std::vector<unsigned int>& data)
{
	GL_CALL(glGenBuffers(1, &m_rendererID));
	GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
	GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(unsigned int), &data[0], GL_STATIC_DRAW));
	m_count = data.size();
}

IndexBuffer::~IndexBuffer()
{
	GL_CALL(glDeleteBuffers(1, &m_rendererID));
}

void IndexBuffer::bind() const
{
	GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
}

void IndexBuffer::unbind() const
{
	GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

