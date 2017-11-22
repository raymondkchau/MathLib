#pragma once
#include "vec3.h"
#include "mat3.h"
#include "Rigidbody.h"
#include <cmath>
struct circle
{
	Rigidbody rigidbody;
	Transform transform;
	vec2 position;
	float radius;
};

struct shot
{
	circle circle;
	float timeAlive;
};

//transformations:
//position, rotation, scale

/*
[ sx  0  0 ]
[ 0  sy  0 ]
[ 0   0  1 ]
*/

//axis aligned bounding box
//places a box around an object to determine whether we need to calculate
//collision
//is a rectangle without rotation
struct AABB
{
	vec2 position;
	vec2 extents; //distance from the edges to the center(position), basically half the width and height

	//four points
	//position width and height
	//min and max

};

circle operator*(const mat3 &m, const circle &c)
{
	circle ret = c;

	ret.position = (m * vec3{ c.position.x, c.position.y, 1.f }).xy;

	vec2 scale;
	scale.x = magnitude(m[0].xy);
	scale.y = magnitude(m[1].xy);

	ret.radius *= fmaxf(scale.x, scale.y);

	return ret;
}

//AABB transformation
AABB operator*(const mat3 &m, AABB &b)
{
	//try and indepently research a solution
	//why not just call the min and max of the rectangle we're drawing
	//and use those variables to determine the size of the AABB?
	//we're already using the coordinates for drawing it by calling its
	//vec3

	b.position = m[2].xy;
	//b.extents = m max x coordinates, m max y coordinates, m min x, m min y;
	//throw the extents into a draw box function
	//???
	//Profit?

	return AABB();
}