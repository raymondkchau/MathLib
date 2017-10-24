#include "vec2.h"
#include "mathutils.h"
#include <cmath>
#include <cfloat>
#include <math.h>
#include <iostream>

vec2 operator+(const vec2 &lhs, const vec2 &rhs)
{
	return{ lhs.x + rhs.x, lhs.y + rhs.y };
}

vec2 operator-(const vec2 &lhs, const vec2 &rhs)
{
	return{ lhs.x - rhs.x, lhs.y - rhs.y };
}

vec2 operator*(const vec2 &lhs, const float multi)
{
	return{ lhs.x * multi, lhs.y * multi };
}

vec2 operator*(const float multi, const vec2 &lhs)
{
	return{ lhs.x * multi, lhs.y * multi };
}

vec2 operator/(const vec2 &lhs, const float div)
{
	return{ lhs.x / div, lhs.y / div };
}

vec2 operator-(const vec2 &lhs)
{
	return{ lhs.x * -1, lhs.y * -1 };
}

vec2 &operator+=(vec2 &lhs, const vec2 &rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

vec2 &operator-=(vec2 &lhs, const vec2 &rhs)
{
	lhs = lhs - rhs;
	return lhs;
}

vec2 &operator*=(vec2 &lhs, const float multi)
{
	lhs = { lhs.x * multi, lhs.y * multi };
	return lhs;
}

vec2 &operator/=(vec2 &lhs, const float div)
{
	lhs = { lhs.x / div, lhs.y / div };
	return lhs;
}



bool operator==(const vec2 &lhs, const vec2 &rhs)
{
	//this isn't quite right but game engines tend to do something
	//fairly close to this process

	//floating-point math is weird! check this out!
	//http://floating-point-gui.de/errors/comparison/

	const int qty = (sizeof(lhs.v) / sizeof(lhs.v[0]));
	for (int i = 0; i < qty; i++)
	{
		//is the discrepancy within acceptable limits?
		if (std::abs(lhs.v[i] - rhs.v[i]) < FLT_EPSILON)
		{
			return true;
		}
	}
	return false;
}

bool operator!=(const vec2 &lhs, const vec2 &rhs)
{
	return !(lhs == rhs);
}

float vec2::operator[](unsigned index)
{
	return v[index];
}

float vec2::operator[](unsigned index) const
{
	return v[index];
}

float magnitude(const vec2 &vector)
{
	float x = powf(vector.x, 2);
	float y = powf(vector.y, 2);

	return sqrtf(x + y);
}

vec2 normal(const vec2 &vector)
{
	float mag = magnitude(vector);
	return vector / mag;
}

vec2 normalize(vec2 &vector)
{
	return vector / magnitude(vector);
}

float dot(const vec2 &a, const vec2 &b)
{
	return a.x * b.x + a.y * b.y;
}

float dist(const vec2 &a, const vec2 &b)
{
	return magnitude(a - b);
}

vec2 perp(const vec2 &v)
{
	return vec2{ v.y, -v.x };
}

vec2 lerp(const vec2 &s, const vec2 &e, float a)
{
	return s + a * (e - s);
}

vec2 min(const vec2 &a, const vec2 &b)
{
	vec2 temp;
	temp.x = min(a.x, b.y);
	temp.y = min(a.y, b.y);

	return temp;
}

vec2 max(const vec2 &a, const vec2 &b)
{
	vec2 temp;
	temp.x = max(a.x, b.x);
	temp.y = max(a.y, b.y);

	return temp;
}