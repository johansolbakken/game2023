#pragma once

#include <vector>
#include <memory>

class VertexBuffer
{
public:
	virtual ~VertexBuffer() = default;

	virtual void bind() const = 0;

	virtual void unbind() const = 0;

	static std::shared_ptr<VertexBuffer> create(const std::vector<float> &data);
};

class IndexBuffer
{
public:
	virtual ~IndexBuffer() = default;

	virtual void bind() const = 0;

	virtual void unbind() const = 0;

	virtual uint32_t getCount() const = 0;

	static std::shared_ptr<IndexBuffer> create(const std::vector<uint32_t> &data);
};
