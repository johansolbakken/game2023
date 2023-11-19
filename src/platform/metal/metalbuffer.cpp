#include "metalbuffer.h"

MetalVertexBuffer::MetalVertexBuffer(const std::vector<float>& data)
{
	//GL_CALL(glGenBuffers(1, &m_rendererID));
	//GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_rendererID));
	//GL_CALL(glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW));
}

MetalVertexBuffer::~MetalVertexBuffer()
{
	// GL_CALL(glDeleteBuffers(1, &m_rendererID));
}

void MetalVertexBuffer::bind() const
{
	// GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_rendererID));
}

void MetalVertexBuffer::unbind() const
{
	// GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

MetalIndexBuffer::MetalIndexBuffer(const std::vector<uint32_t>& data)	
{
	// GL_CALL(glGenBuffers(1, &m_rendererID));
	// GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
	// GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(unsigned int), &data[0], GL_STATIC_DRAW));
	// m_count = data.size();
}

MetalIndexBuffer::~MetalIndexBuffer()
{
	//GL_CALL(glDeleteBuffers(1, &m_rendererID));
}

void MetalIndexBuffer::bind() const
{
	//GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
}

void MetalIndexBuffer::unbind() const
{
	//GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

