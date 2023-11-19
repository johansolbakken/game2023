#pragma once

#include <glm/glm.hpp>

class Camera2D
{
public:
	Camera2D();

	~Camera2D();

	void init(int screenWidth, int screenHeight);

	void update();

	void setPosition(const glm::vec2& position);

	void setScale(float scale);

	[[nodiscard]] const glm::mat4& getCameraMatrix() const
	{
		return m_cameraMatrix;
	}

private:
	int m_screenWidth = 0;
	int m_screenHeight = 0;
	float m_scale = 0.0f;
	glm::vec2 m_position = glm::vec2(0.0f);
	glm::mat4 m_cameraMatrix = glm::mat4(1.0f);
	glm::mat4 m_orthoMatrix = glm::mat4(1.0f);
};


