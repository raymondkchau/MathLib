#pragma once
#include "vec2.h"
#include "vec3.h"

//Matrices are column-major as opposed to row major.
//[0 3 6]
//[1 4 7]
//[2 5 8]
// read in the order of 0-8.

union mat3
{
	vec3 c[3]; //selects column
	float m[9]; //straight through, straight forward
	float mm[3][3]; //col(y), row(x)

	vec3 &operator[](size_t index) { return c[index]; }
	const vec3 &operator[](size_t index) const { return c[index]; }

	static mat3 identity()
	{
		return mat3{ 1,0,0,
					 0,1,0,
					 0,0,1 };
	}

	static mat3 zero()
	{
		return mat3{ 0,0,0,
					 0,0,0,
					 0,0,0 };
	}
};

//arithmetic operators
mat3 operator+(const mat3 &a, const mat3 &b); //not really used
mat3 operator-(const mat3 &a, const mat3 &b); //not really used
mat3 operator*(const mat3 &a, const mat3 &b); //combine transformations
vec3 operator*(const mat3 &a, const vec3 &b); //apply transforms

//logical operators
bool operator==(const mat3 &a, const mat3 &b);

//misc functions
mat3 transpose(const mat3 &a); //flips rows and columns
float determinant(const mat3 &a);
mat3 inverse(const mat3 &a);
mat3 translate(const vec2 &a);
mat3 scale(const vec2 &a);
mat3 rotate(float deg);