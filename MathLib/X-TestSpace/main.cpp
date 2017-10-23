#include <iostream>
#include "vec2.h"
#include "vec3.h"
#include "mathutils.h"

int main()
{
	vec2 vecA = { 1, 2 };
	vec2 vecB = { 4, 8 };
	vec2 vecC = vecA + vecB;

	vecA = { 7, 1 };
	vecB = { 3, 2 };
	vecC = operator+(vecA, vecB);

	vecA = { 2, 5 };
	vecB = { 4, 8 };
	vecC = operator-(vecA, vecB);

	vecA = { 2, 2 };
	float multi = 3;
	vecC = operator*(vecA, multi);

	vecA = { 6, 6 };
	float div = 2;
	vecC = operator*(vecA, div);
	
	vecA = { 5, 2 };
	-vecA;

	vecA = { 7, 1 };
	vecB = { 7, 1 };
	bool equals = operator==(vecA, vecB);
	std::cout << equals << std::endl;

	vecA = { 2, 5 };
	vecB = { 4, 8 };
	bool notequals = operator!=(vecA, vecB);
	std::cout << notequals << std::endl;

	vecA = { 2, 2 };
	multi = 3;
	vecC = operator*=(vecA, multi);

	vecA = { 6, 6 };
	div = 2;
	vecC = operator/=(vecA, div);
	vecA / 2;

	std::cout << "I don't know what I'm doing but its working so I think its right." << std::endl;

	vecA = { 0, 1 };
	vecB = { 1, 1 };
	vecC = { -2, 3 };

	std::cout << vecA.x << ", " << vecA.y << std::endl;
	std::cout << "Magnitude: " << magnitude(vecA) << std::endl;

	std::cout << vecB.x << ", " << vecB.y << std::endl;
	std::cout << "Magnitude: " << magnitude(vecB) << std::endl;

	std::cout << vecC.x << ", " << vecC.y << std::endl;
	std::cout << "Magnitude: " << magnitude(vecC) << std::endl;

	std::cout << std::endl;
	std::cout << "Testing Vec3" << std::endl;
	
	vec3 a{ 9,3,1 };
	vec3 b{ 7,2,4 };
	vec3 c{ 9,4,7 };

	vec3 result = clamp(a, b, c);

	std::cout << result.x << ", " << result.y << ", " << result.z << std::endl;

	a = { 8,2,8 };
	b = { 1,1,0 };
	c = { 1,2,0 };

	result = clamp(a, b, c);

	std::cout << result.x << ", " << result.y << ", " << result.z << std::endl;

	a = { 4,5,6 };
	b = { 4,7,4 };
	c = { 8,9,7 };

	result = clamp(a, b, c);

	std::cout << result.x << ", " << result.y << ", " << result.z << std::endl;

	while (true);
}