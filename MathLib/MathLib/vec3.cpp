#include "vec3.h"
#include "mathutils.h"
#include <cmath>
#include <cfloat>
#include <math.h>
#include <iostream>

vec3 operator+(const vec3 &a, const vec3 &b)
{
	return{ a[0] + b[0], a[1] + b[1], a[2] + b[2] };
}

vec3 operator-(const vec3 &a, const vec3 &b)
{
	return{ a[0] - b[0], a[1] - b[1], a[2] - b[2] };
}

vec3 operator*(const vec3 &a, const float multi)
{
	return{ a[0] * multi, a[1] * multi, a[2] * multi };
}

vec3 operator*(const float multi, const vec3 &a)
{
	return{ a[0] * multi, a[1] * multi, a[2] * multi };
}

vec3 operator/(const vec3 &a, const float div)
{
	return{ a[0] / div, a[1] / div, a[2] / div };
}

vec3 operator+=(vec3 &lhs, const vec3 &rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

vec3 operator-=(vec3 &lhs, const vec3 &rhs)
{
	lhs = lhs - rhs;
	return lhs;
}

vec3 operator*=(vec3 &lhs, const float multi)
{
	lhs = { lhs[0] * multi, lhs[1] * multi, lhs[2] * multi };
	return lhs;
}

vec3 operator/=(vec3 &lhs, const float div)
{
	lhs = { lhs[0] / div, lhs[1] / div, lhs[2] / div };
	return lhs;
}

bool operator==(const vec3 &lhs, const vec3 &rhs)
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

bool operator!=(const vec3 &lhs, const vec3 &rhs)
{
	return !(lhs == rhs);
}

float vec3::operator[](unsigned index)
{
	return v[index];
}

float vec3::operator[](unsigned index) const
{
	return v[index];
}

float magnitude(const vec3 &a)
{
	float x = powf(a[0], 2);
	float y = powf(a[1], 2);
	float z = powf(a[2], 2);

	return sqrtf(x + y + z);
}

vec3 normal(const vec3 &a)
{
	return a / magnitude(a);
}

vec3 normalize(vec3 &a)
{
	return a / magnitude(a);
}

float dot(const vec3 &a, const vec3 &b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

float cross(const vec3 &a, const vec3 &b)
{
	return ((a[1] * b[2]) - (a[2] * b[1]), (a[2] * b[0]) - (a[0] * b[2]), (a[0] * b[1]) - (a[1] * b[0]));
}

float dist(const vec3 &a, const vec3 &b)
{
	return magnitude(a - b);
}

vec3 min(const vec3 &a, const vec3 &b)
{
	vec3 temp;
	temp.x = min(a.x, b.x);
	temp.y = min(a.y, b.y);
	temp.z = min(a.z, b.z);

	return temp;
}

vec3 max(const vec3 &a, const vec3 &b)
{
	vec3 temp;
	temp.x = max(a.x, b.x);
	temp.y = max(a.y, b.y);
	temp.z = max(a.z, b.z);

	return temp;
}

vec3 clamp(const vec3 &a, const vec3 minvec3, const vec3 maxvec3)
{
	vec3 temp;
	temp.x = min(a.x, maxvec3.x);
	temp.y = min(a.y, maxvec3.y);
	temp.z = min(a.z, maxvec3.z);

	temp.x = max(temp.x, minvec3.x);
	temp.y = max(temp.y, minvec3.y);
	temp.z = max(temp.z, minvec3.z);

	return temp;
}