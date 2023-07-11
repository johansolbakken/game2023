#pragma once

#include <string>

class Texture
{
public:
	Texture(const std::string& path);

	~Texture();

	uint32_t getID() const;

	const std::string& getPath() const;

	void bind() const;

	void unbind() const;

private:
	uint32_t m_id;
	std::string m_path;
};

