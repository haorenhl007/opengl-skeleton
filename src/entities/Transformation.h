#pragma once

#include <glm\glm.hpp>

class Transformation
{
public:
	Transformation(glm::vec3 position = glm::vec3(0, 0, 0), glm::vec3 rotation = glm::vec3(0, 0, 0), glm::vec3 scale = glm::vec3(1, 1, 1))
		:m_position(position), m_rotation(rotation), m_scale(scale) {};

	inline void ChangePosition(glm::vec3 position) { m_position += position; }
	inline void ChangeRotation(glm::vec3 rotation) { m_rotation += rotation; }
	inline void ChangeScale(glm::vec3 scale) { m_scale += scale; }

	inline glm::vec3 GetPosition() { return m_position; }
	inline glm::vec3 GetRotation() { return m_rotation; }
	inline glm::vec3 GetScale() { return m_scale; }

	inline void SetPosition(glm::vec3 position) { m_position = position; }
	inline void SetRotation(glm::vec3 rotation) { m_rotation = rotation; }
	inline void SetScale(glm::vec3 scale) { m_scale = scale; }

private:
	glm::vec3 m_position;
	glm::vec3 m_rotation;
	glm::vec3 m_scale;
};