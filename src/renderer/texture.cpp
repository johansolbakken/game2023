#include "texture.h"

#include "platform/metal/metaltexture.h"

std::shared_ptr<Texture> Texture::create(const std::string& path) {
	return std::make_shared<MetalTexture>(path);
}