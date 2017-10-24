#include "mat3.h"
#include "vec3.h"
#include "mathutils.h"
#include <cmath>
#include <cfloat>

mat3 operator+(const mat3 &a, const mat3 &b)
{
	mat3 temp;
	for (int i = 0; i < 9; i++)
	{
		temp[i] = a[i] + b[i];
	}
	return temp;
}

mat3 operator-(const mat3 &a, const mat3 &b)
{
	mat3 temp;
	for (int i = 0; i < 9; i++)
	{
		temp[i] = a[i] - b[i];
	}
	return temp;
}

mat3 operator*(const mat3 &a, const mat3 &b)
{
	mat3 temp = { (a.m[0] * b.m[0]) + (a.m[1] * b.m[3]) + (a.m[2] * b.m[6]), //c1, r1
				  (a.m[3] * b.m[0]) + (a.m[4] * b.m[3]) + (a.m[5] * b.m[6]), //c2, r1
				  (a.m[6] * b.m[0]) + (a.m[7] * b.m[3]) + (a.m[8] * b.m[6]), //c3, r1
				  (a.m[0] * b.m[1]) + (a.m[1] * b.m[4]) + (a.m[2] * b.m[7]), //c1, r2
				  (a.m[3] * b.m[1]) + (a.m[4] * b.m[4]) + (a.m[5] * b.m[7]), //c2, r2
				  (a.m[6] * b.m[1]) + (a.m[7] * b.m[4]) + (a.m[8] * b.m[7]), //c3, r2
				  (a.m[0] * b.m[2]) + (a.m[1] * b.m[5]) + (a.m[2] * b.m[8]), //c1, r3
				  (a.m[3] * b.m[2]) + (a.m[4] * b.m[5]) + (a.m[5] * b.m[8]), //c2, r3
				  (a.m[6] * b.m[2]) + (a.m[7] * b.m[5]) + (a.m[8] * b.m[8]), //c3, r3
				};
	return temp;
}

vec3 operator*(const mat3 &a, const vec3 &b) //figure out later
{
	vec3 temp = { dot(a.c[0], b),
				  dot(a.c[1], b),
				  dot(a.c[2], b) };
	return temp;
}

bool operator==(const mat3 &a, const mat3 &b)
{
	const int qty = (sizeof(a.m) / sizeof(a.m[0]));
	for (int i = 0; i < qty; i++)
	{
		//is the discrepancy within acceptable limits?
		if (std::abs(a.m[i] - b.m[i]) < FLT_EPSILON)
		{
			return true;
		}
	}
	return false;
}

mat3 transpose(const mat3 &a)
{
	mat3 t = a;
	t.m[1] = a.m[3];
	t.m[3] = a.m[1];
	t.m[2] = a.m[6];
	t.m[6] = a.m[2];
	t.m[5] = a.m[7];
	t.m[7] = a.m[5];

	return t;
}