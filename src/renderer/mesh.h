#pragma once

#include <vector>
#include <string>

struct aiNode;
struct aiScene;
struct aiMesh;

class Mesh
{
public:
	explicit Mesh(const std::string& path);

	~Mesh();

	[[nodiscard]] const std::vector<float>& getVertices() const;

	[[nodiscard]] const std::vector<float>& getNormals() const;

	[[nodiscard]] const std::vector<float>& getTexCoords() const;

	[[nodiscard]] const std::vector<uint32_t>& getIndices() const;

	[[nodiscard]] uint32_t getVAO() const;

private:
	void loadFbx(const std::string& path);

private:
	std::vector<float> m_vertices;
	std::vector<float> m_normals;
	std::vector<float> m_texCoords;
	std::vector<uint32_t> m_indices;

	uint32_t m_vao;
	uint32_t m_vbo;
	uint32_t m_ebo;
};