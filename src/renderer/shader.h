#pragma once

#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
    Shader(const std::string &vertexSource, const std::string &fragmentSource);
    ~Shader();

    void use();
    void setVec4(const std::string& name, const glm::vec4& vec) const;
    void setMat4(const std::string& name, const glm::mat4& mat) const;
    void setVec3(const std::string& name, const glm::vec3& vec) const;

private:
    uint32_t m_id;
};