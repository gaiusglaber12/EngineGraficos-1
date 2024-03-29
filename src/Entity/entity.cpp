#include "entity.h"

namespace GL
{
	Entity::Entity()
	{
		this->render = nullptr;

		v3Pos = glm::vec3(0.0f);
		v3Rot = glm::vec3(0.0f);
		v3Scale = glm::vec3(1.0f);
		color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

		translate = glm::mat4(1.0f);
		rotationX = glm::mat4(1.0f);
		rotationY = glm::mat4(1.0f);
		rotationZ = glm::mat4(1.0f);
		scale = glm::mat4(1.0f);
		model = glm::mat4(1.0f);

		VAO = 0;
		VBO = 0;
		EBO = 0;
		tam = 0;
		vertexs = 0;
		vertices = 0;

		hasCollider = false;
		moveable = false;

		UpdateModel();
	}

	Entity::Entity(Render* render)
	{
		this->render = render;

		SetPos(0.0f, 0.0f, 0.0f);
		SetRotX(0.0f);
		SetRotY(0.0f);
		SetRotZ(0.0f);
		SetScale(1.0f, 1.0f, 1.0f);
		SetColor(1.0f, 1.0f, 1.0f, 1.0f);

		VAO = 0;
		VBO = 0;
		EBO = 0;
		tam = 0;
		vertexs = 0;
		vertices = 0;

		hasCollider = false;
		moveable = false;

		UpdateModel();
	}

	Entity::~Entity()
	{
	}

	void Entity::SetPos(float x, float y, float z)
	{
		v3Pos = glm::vec3(x, y, z);
		translate = glm::translate(glm::mat4(1.0f), v3Pos);
		UpdateModel();
	}

	void Entity::SetPos(glm::vec3 pos)
	{
		SetPos(pos.x, pos.y, pos.z);
	}

	void Entity::SetRotX(float x) 
	{
		v3Rot[0] = x;
		glm::vec3 axis = glm::vec3(1, 0, 0);
		rotationX = glm::rotate(glm::mat4(1.0f), glm::radians(x), axis);
		UpdateModel();
	}

	void Entity::SetRotY(float y) 
	{
		v3Rot[1] = y;
		glm::vec3 axis = glm::vec3(0, 1, 0);
		rotationY = glm::rotate(glm::mat4(1.0f), glm::radians(y), axis);
		UpdateModel();
	}

	void Entity::SetRotZ(float z) 
	{
		v3Rot[2] = z;
		glm::vec3 axis = glm::vec3(0, 0, 1);
		rotationZ = glm::rotate(glm::mat4(1.0f), glm::radians(z), axis);
		UpdateModel();
	}

	void Entity::SetScale(float size)
	{
		SetScale(size, size, size);
	}

	void Entity::SetScale(float x, float y, float z)
	{
		v3Scale = glm::vec3(x, y, z);
		scale = glm::scale(glm::mat4(1.0f), v3Scale);
		UpdateModel();
	}

	void Entity::SetColor(float r, float g, float b, float a)
	{
		this->color = glm::vec4(r, g, b, a);
	}

	void Entity::SetCollider(bool col)
	{
		hasCollider = col;
	}

	void Entity::SetMoveable(bool mov)
	{
		moveable = mov;
	}

	glm::mat4 Entity::GetRotation()
	{
		return (rotationX * rotationY * rotationZ);
	}

	void Entity::UpdateModel()
	{
		model = translate * GetRotation() * scale;
	}

	float Entity::GetPosX()
	{
		return v3Pos[0];
	}

	float Entity::GetPosY()
	{
		return v3Pos[1];
	}

	float Entity::GetPosZ()
	{
		return v3Pos[2];
	}

	glm::vec3 Entity::GetPos()
	{
		return v3Pos;
	}

	float Entity::GetRotX()
	{
		return v3Rot[0];
	}

	float Entity::GetRotY()
	{
		return v3Rot[1];
	}

	float Entity::GetRotZ()
	{
		return v3Rot[2];
	}

	float Entity::GetScaleX()
	{
		return v3Scale[0];
	}

	float Entity::GetScaleY()
	{
		return v3Scale[1];
	}

	float Entity::GetScaleZ()
	{
		return v3Scale[2];
	}

	glm::vec3 Entity::GetPivot()
	{
		return v3Pos;
	}

	bool Entity::IsMoveable()
	{
		return moveable;
	}

	bool Entity::HasCollider()
	{
		return hasCollider;
	}

	void Entity::Draw(unsigned int shaderId)
	{
		render->Draw(model, VAO, VBO, EBO, vertices, tam, vertexs, shaderId);
	}

	void Entity::DeInit()
	{
		render->UnBind(VAO, VBO, EBO);
	}
}