#include <iostream>
#include "vec2.h"
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

	while (true);
}