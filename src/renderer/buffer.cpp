#include "buffer.h"

#include "platform/metal/metalbuffer.h"

std::shared_ptr<VertexBuffer> VertexBuffer::create(const std::vector<float> &data)
{
	return std::make_shared<MetalVertexBuffer>(data);
}

std::shared_ptr<IndexBuffer> IndexBuffer::create(const std::vector<uint32_t> &data)
{
	return std::make_shared<MetalIndexBuffer>(data);
}