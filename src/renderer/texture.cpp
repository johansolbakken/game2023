//
// Created by Johan Solbakken on 25/03/2023.
//

#include "texture.h"

#include <glad/glad.h>

#include <stb_image.h>

#include <iostream>

#include "renderer/opengl.h"

Texture::Texture(const std::string &file_path)
{
	GL_CALL(glGenTextures(1, &m_id));
	GL_CALL(glBindTexture(GL_TEXTURE_2D, m_id));

	// set the texture wrapping/filtering options (on the currently bound texture object)
	GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
	GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
	GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

	// load and generate the texture
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load(file_path.c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		GLenum format;
		if (nrChannels == 1)
		{
			format = GL_RED;
		}
		else if (nrChannels == 3)
		{
			format = GL_RGB;
		}
		else if (nrChannels == 4)
		{
			format = GL_RGBA;
		}
		GL_CALL(glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data));
		GL_CALL(glGenerateMipmap(GL_TEXTURE_2D));
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}

Texture::~Texture()
{
	GL_CALL(glDeleteTextures(1, &m_id));
}

void Texture::bind() const
{
	GL_CALL(glBindTexture(GL_TEXTURE_2D, m_id));
}

void Texture::unbind() const
{
	GL_CALL(glBindTexture(GL_TEXTURE_2D, 0));
}