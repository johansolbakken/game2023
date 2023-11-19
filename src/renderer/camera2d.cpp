//
// Created by Johan Solbakken on 25/03/2023.
//

#include "camera2d.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>

Camera2D::Camera2D()
{
	m_position = glm::vec3(0.0f, 0.0f, 0.0f);
	m_scale = 1.0;
}

Camera2D::~Camera2D()
{
}

void Camera2D::init(int screenWidth, int screenHeight)
{
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;
	m_orthoMatrix = glm::ortho(0.0f, (float)m_screenWidth, 0.0f, (float)m_screenHeight);
}

void Camera2D::update()
{
	glm::mat4 translateMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(m_position.x, m_position.y, 0.0f));
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(m_scale, m_scale, 0.0f));
	m_cameraMatrix = m_orthoMatrix * translateMatrix * scaleMatrix;
}

void Camera2D::setPosition(const glm::vec2& position)
{
	m_position = glm::vec3(position, 0.0f);
}

void Camera2D::setScale(float scale)
{
	m_scale = scale;
}


