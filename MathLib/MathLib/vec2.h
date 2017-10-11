#pragma once

//the float and struct share the same address, so they essentially have the same variables
//but can be called through multiple different ways, hence union
union vec2
{
	//access by array
	float v[2];

	//access by individual component
	struct { float x, y; };

	//subscript operators
	float operator[](unsigned index);
	float operator[](unsigned index) const;
};

//arithmetic operators
vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);
vec2 operator*(const vec2 &lhs, const float multi);
vec2 operator*(const float multi, const vec2 &lhs);
vec2 operator/(const vec2 &lhs, const float div);
vec2 operator-(const vec2 &lhs);

//compound assignment operators
vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 &lhs, const vec2 &rhs);
vec2 &operator*=(vec2 &lhs, const float multi);
vec2 &operator/=(vec2 &lhs, const float div);

//logical operators
bool operator==(const vec2 &lhs, const vec2 &rhs);
bool operator!=(const vec2 &lhs, const vec2 &rhs);

//misc functions
float magnitude(vec2 vector);
vec2 normal(vec2 vector);
const vec2 normalize(vec2 vector);