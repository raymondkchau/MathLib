#pragma once

union vec3
{
	float v[3];
	
	struct { float x, y, z; };

	float operator[](unsigned index);
	float operator[](unsigned index) const;
};

//arithmetic operators
vec3 operator+(const vec3 &a, const vec3 &b);
vec3 operator-(const vec3 &a, const vec3 &b);
vec3 operator*(const vec3 &a, const float multi);
vec3 operator*(const float multi, const vec3 &a);
vec3 operator/(const vec3 &a, const float div);

//compound assignment operators
vec3 operator+=(vec3 &lhs, const vec3 &rhs);
vec3 operator-=(vec3 &lhs, const vec3 &rhs);
vec3 operator*=(vec3 &lhs, const float multi);
vec3 operator/=(vec3 &lhs, const float div);

//logical operators
bool operator==(const vec3 &lhs, const vec3 &rhs);
bool operator!=(const vec3 &lhs, const vec3 &rhs);

//misc functions
float magnitude(const vec3 &a);
vec3 normal(const vec3 &a);
vec3 normalize(vec3 &a);
float dot(const vec3 &a, const vec3 &b);
float cross(const vec3 &a, const vec3 &b);
float dist(const vec3 &a, const vec3 &b);
vec3 min(const vec3 &a, const vec3 &b);
vec3 max(const vec3 &a, const vec3 &b);
vec3 clamp(const vec3 &a, const vec3 minvec3, const vec3 maxvec3);