#pragma once

#include <string>
#include <memory>

class Texture
{
public:
	virtual ~Texture() = default;

	virtual uint32_t getID() const = 0;

	virtual const std::string& getPath() const = 0;

	virtual void bind() const = 0;

	virtual void unbind() const = 0;

	static std::shared_ptr<Texture> create(const std::string& path);
};

