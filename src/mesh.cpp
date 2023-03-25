#include "mesh.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>

#include <glad/glad.h>

Mesh::Mesh(const std::string &file_path)
{
    loadModel(file_path);

    // create buffers/arrays and fill them with data from the m_vertices and m_indices vectors
    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ebo);

    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), &m_vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(uint32_t), &m_indices[0], GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_vao);
    glDeleteBuffers(1, &m_vbo);
    glDeleteBuffers(1, &m_ebo);
}

enum class ModelType {
    FBX,
    GLTF2
};

void Mesh::loadModel(const std::string &file_path)
{
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(file_path, aiProcess_Triangulate | aiProcess_FlipUVs);
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
    }
    processNode(scene->mRootNode, scene);
}

void Mesh::processNode(aiNode *node, const aiScene *scene)
{
    for (uint32_t i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        for (uint32_t j = 0; j < mesh->mNumVertices; j++)
        {
            m_vertices.push_back(mesh->mVertices[j].x);
            m_vertices.push_back(mesh->mVertices[j].y);
            m_vertices.push_back(mesh->mVertices[j].z);
            m_normals.push_back(mesh->mNormals[j].x);
            m_normals.push_back(mesh->mNormals[j].y);
            m_normals.push_back(mesh->mNormals[j].z);
            if (mesh->mTextureCoords[0])
            {
                m_texCoords.push_back(mesh->mTextureCoords[0][j].x);
                m_texCoords.push_back(mesh->mTextureCoords[0][j].y);
            }
            else
            {
                m_texCoords.push_back(0.0f);
                m_texCoords.push_back(0.0f);
            }
        }
        for (uint32_t j = 0; j < mesh->mNumFaces; j++)
        {
            aiFace face = mesh->mFaces[j];
            for (uint32_t k = 0; k < face.mNumIndices; k++)
            {
                m_indices.push_back(face.mIndices[k]);
            }
        }
    }
    for (uint32_t i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene);
    }
}

const std::vector<float> &Mesh::getVertices() const
{
    return m_vertices;
}

const std::vector<float> &Mesh::getNormals() const
{
    return m_normals;
}

const std::vector<float> &Mesh::getTexCoords() const
{
    return m_texCoords;
}

const std::vector<uint32_t> &Mesh::getIndices() const
{
    return m_indices;
}

uint32_t Mesh::getVAO() const
{
    return m_vao;
}