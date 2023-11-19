#include "mesh.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>

Mesh::Mesh(const std::string& file_path)
{
	loadFbx(file_path);
/*
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	// vertex normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	// vertex texture coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));

	glBindVertexArray(0);*/
}

Mesh::~Mesh()
{
	// glDeleteVertexArrays(1, &m_vao);
	// glDeleteBuffers(1, &m_vbo);
	// glDeleteBuffers(1, &m_ebo);
}

const std::vector<float>& Mesh::getVertices() const
{
	return m_vertices;
}

const std::vector<float>& Mesh::getNormals() const
{
	return m_normals;
}

const std::vector<float>& Mesh::getTexCoords() const
{
	return m_texCoords;
}

const std::vector<uint32_t>& Mesh::getIndices() const
{
	return m_indices;
}

uint32_t Mesh::getVAO() const
{
	return m_vao;
}

void Mesh::loadFbx(const std::string& path)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
		return;
	}

	//processNode(scene->mRootNode, scene);
}

