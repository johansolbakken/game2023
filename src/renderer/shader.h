#pragma once

#include <string>
#include <glm/glm.hpp>
#include <memory>

class Shader
{
public:
    virtual ~Shader() = default;

    virtual void use() const = 0;
    virtual void setVec4(const std::string& name, const glm::vec4& vec) const = 0;
    virtual void setMat4(const std::string& name, const glm::mat4& mat) const = 0;
    virtual void setVec3(const std::string& name, const glm::vec3& vec) const = 0;

    static std::shared_ptr<Shader> create(const std::string& vertexSource, const std::string& fragmentSource);
};