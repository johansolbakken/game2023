#include "shader.h"

#include "platform/metal/metalshader.h"

std::shared_ptr<Shader> Shader::create(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
    return std::make_shared<MetalShader>(vertexShaderPath, fragmentShaderPath);
}
