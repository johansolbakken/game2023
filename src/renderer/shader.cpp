#include "shader.h"

#include <glad/glad.h>

#include "renderer/opengl.h"

Shader::Shader(const std::string &vertexShaderSource, const std::string &fragmentShaderSource)
{
    m_id = glCreateProgram();

    uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char *vertexShaderSourceCStr = vertexShaderSource.c_str();
    GL_CALL(glShaderSource(vertexShader, 1, &vertexShaderSourceCStr, NULL));
    GL_CALL(glCompileShader(vertexShader));

    uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char *fragmentShaderSourceCStr = fragmentShaderSource.c_str();
    GL_CALL(glShaderSource(fragmentShader, 1, &fragmentShaderSourceCStr, NULL));
    GL_CALL(glCompileShader(fragmentShader));

    GL_CALL(glAttachShader(m_id, vertexShader));
    GL_CALL(glAttachShader(m_id, fragmentShader));
    GL_CALL(glLinkProgram(m_id));

    GL_CALL(glDeleteShader(vertexShader));
    GL_CALL(glDeleteShader(fragmentShader));
}

Shader::~Shader()
{
    GL_CALL(glDeleteProgram(m_id));
}

void Shader::use()
{
    GL_CALL(glUseProgram(m_id));
}

void Shader::setVec4(const std::string &name, const glm::vec4 &vec) const
{
    GL_CALL(glUniform4f(glGetUniformLocation(m_id, name.c_str()), vec.x, vec.y, vec.z, vec.w));
}

void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const
{
    GL_CALL(glUniformMatrix4fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, &mat[0][0]));
}

void Shader::setVec3(const std::string &name, const glm::vec3 &vec) const
{
    GL_CALL(glUniform3f(glGetUniformLocation(m_id, name.c_str()), vec.x, vec.y, vec.z));
}