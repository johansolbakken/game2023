#pragma once

#include "renderer/texture.h"

class MetalTexture : public Texture
{
public:
	MetalTexture(const std::string& path);

	~MetalTexture() override;

	uint32_t getID() const override;

	const std::string& getPath() const override;

	void bind() const override;

	void unbind() const override;

private:
	uint32_t m_id;
	std::string m_path;
};

