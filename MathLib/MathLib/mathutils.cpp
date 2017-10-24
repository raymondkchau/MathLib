#include "mathutils.h"

int min(const int a, const int b)
{
	return a < b ? a : b;
}

float min(const float a, const float b)
{
	return a < b ? a : b;
}

float max(const float a, const float b)
{
	return a > b ? a : b;
}