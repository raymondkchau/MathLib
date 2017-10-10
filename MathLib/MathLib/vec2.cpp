#include "vec2.h"
#include <cmath>
#include <cfloat>

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
			return false;
		}
	}
	return true;
}