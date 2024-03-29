#include "metalshader.h"

#include <filesystem>
#include <iostream>

MetalShader::MetalShader(const std::string &vertexShaderSource, const std::string &fragmentShaderSource)
{
    if (vertexShaderSource.empty() || fragmentShaderSource.empty())
    {
        std::cout << "Shader source is empty" << std::endl;
        return;
    }

    if (!std::filesystem::exists(vertexShaderSource))
    {
        std::cout << "Vertex shader source file does not exist" << std::endl;
        return;
    }

    if (!std::filesystem::exists(fragmentShaderSource))
    {
        std::cout << "Fragment shader source file does not exist" << std::endl;
        return;
    }

/*
    m_id = glCreateProgram();

    uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char *vertexShaderSourceCStr = vertexShaderSource.c_str();
    GL_CALL(glShaderSource(vertexShader, 1, &vertexShaderSourceCStr, nullptr));
    GL_CALL(glCompileShader(vertexShader));

    uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char *fragmentShaderSourceCStr = fragmentShaderSource.c_str();
    GL_CALL(glShaderSource(fragmentShader, 1, &fragmentShaderSourceCStr, nullptr));
    GL_CALL(glCompileShader(fragmentShader));

    GL_CALL(glAttachShader(m_id, vertexShader));
    GL_CALL(glAttachShader(m_id, fragmentShader));
    GL_CALL(glLinkProgram(m_id));

    GL_CALL(glDeleteShader(vertexShader));
    GL_CALL(glDeleteShader(fragmentShader));*/
}

MetalShader::~MetalShader()
{
    //GL_CALL(glDeleteProgram(m_id));
}

void MetalShader::use() const
{
    //GL_CALL(glUseProgram(m_id));
}

void MetalShader::setVec4(const std::string &name, const glm::vec4 &vec) const
{
    //GL_CALL(glUniform4f(glGetUniformLocation(m_id, name.c_str()), vec.x, vec.y, vec.z, vec.w));
}

void MetalShader::setMat4(const std::string &name, const glm::mat4 &mat) const
{
    //GL_CALL(glUniformMatrix4fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, &mat[0][0]));
}

void MetalShader::setVec3(const std::string &name, const glm::vec3 &vec) const
{
    //GL_CALL(glUniform3f(glGetUniformLocation(m_id, name.c_str()), vec.x, vec.y, vec.z));
}