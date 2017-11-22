#pragma once
#include "vec2.h"
#include "mat3.h"

class Transform
{
public:
	vec2 position;
	vec2 dimension;
	float angle;
	Transform *e_parent;
	Transform()
	{
		position = { 0,0 };
		dimension = { 1,1 };
		angle = 0;
		e_parent = nullptr;
	}
	Transform(vec2 a_pos, vec2 a_dim, float a_angle)
	{
		position = a_pos; //vec2{ 0,0};
		dimension = a_dim; //vec2{ 0,0 };
		angle = a_angle; //0;
		e_parent = nullptr;
	}

	mat3 getLocalTransform() const
	{
		return rotate(angle) * translate(position) * scale(dimension);
	}

	mat3 getGlobalTransform() const
	{
		if (e_parent != nullptr)
		{
			return e_parent->getGlobalTransform() * getLocalTransform();
		}
		else
		{
			return getLocalTransform();
		}
	}
};
//how do I use this??

//void DrawMatrix(const mat3 &t, float drawing_scale);
//void DrawTexture(unsigned sprite, const mat3 &t);