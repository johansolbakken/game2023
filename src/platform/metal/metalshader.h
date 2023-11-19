#pragma once

#include "renderer/shader.h"

class MetalShader : public Shader
{
public:
    MetalShader(const std::string &vertexSource, const std::string &fragmentSource);
    ~MetalShader() override;

    void use() const override;
    void setVec4(const std::string& name, const glm::vec4& vec) const override;
    void setMat4(const std::string& name, const glm::mat4& mat) const override;
    void setVec3(const std::string& name, const glm::vec3& vec) const override;

private:
    uint32_t m_id;
};