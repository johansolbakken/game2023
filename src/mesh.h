#pragma once

#include <vector>
#include <string>

struct aiNode;
struct aiScene;

class Mesh
{
public:
    Mesh(const std::string& path);
    ~Mesh();

    const std::vector<float>& getVertices() const;
    const std::vector<float>& getNormals() const;
    const std::vector<float>& getTexCoords() const;
    const std::vector<uint32_t>& getIndices() const;

    uint32_t getVAO() const;

private:
    void loadModel(const std::string& path);
    void processNode(aiNode* node, const aiScene* scene);

private:
    std::vector<float> m_vertices;
    std::vector<float> m_normals;
    std::vector<float> m_texCoords;
    std::vector<uint32_t> m_indices;

    uint32_t m_vao;
    uint32_t m_vbo;
    uint32_t m_ebo;
};