#pragma once

#include "renderer/buffer.h"

class MetalVertexBuffer : public VertexBuffer
{
public:
	MetalVertexBuffer(const std::vector<float> &data);

	~MetalVertexBuffer() override;

	void bind() const override;

	void unbind() const override;

private:
	uint32_t m_rendererID;
};

class MetalIndexBuffer : public IndexBuffer
{
public:
	MetalIndexBuffer(const std::vector<uint32_t> &data);

	~MetalIndexBuffer() override;

	void bind() const override;

	void unbind() const override;

	inline unsigned int getCount() const override
	{
		return m_count;
	}

private:
	uint32_t m_rendererID;
	uint32_t m_count;
};
