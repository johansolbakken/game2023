#pragma once

#include <vector>

class VertexBuffer
{
public:
	VertexBuffer(const std::vector<float>& data);

	~VertexBuffer();

	void bind() const;

	void unbind() const;

private:
	unsigned int m_rendererID;
};

class IndexBuffer
{
public:
	IndexBuffer(const std::vector<unsigned int>& data);

	~IndexBuffer();

	void bind() const;

	void unbind() const;

	inline unsigned int getCount() const
	{
		return m_count;
	}

private:
	unsigned int m_rendererID;
	unsigned int m_count;
};

