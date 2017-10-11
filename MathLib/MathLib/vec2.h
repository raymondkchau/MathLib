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
float magnitude(const vec2 &vector);
vec2 normal(const vec2 &vector);
vec2 normalize(vec2 &vector);
float dot(const vec2 &a, const vec2 &b);
float dist(const vec2 &a, const vec2 &b);
vec2 perp(const vec2 &v);
vec2 lerp(const vec2 &s, const vec2 &e, float a);
vec2 min(const vec2 &a, const vec2 &b);
vec2 max(const vec2 &a, const vec2 &b);