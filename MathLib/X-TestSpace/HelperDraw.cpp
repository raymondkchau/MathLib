#include "HelperDraw.h"
#include "sfwdraw.h"
#include <cmath>

void DrawMatrix(const mat3 & t, float drawing_scale)
{
	vec2 pos = t[2].xy;
	vec2 up = pos + (t[1].xy * drawing_scale);
	vec2 right = pos + (t[0].xy * drawing_scale);

	sfw::drawCircle(pos.x, pos.y, drawing_scale / 4);
	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	sfw::drawLine(pos.x, pos.y, up.x, up.y, GREEN);
}

void DrawSquare(const vec2 &a, const vec2 &b, float angle)
{
	float minx = a.x;
	float miny = a.y;
	float maxx = b.x;
	float maxy = b.y;

	//bottom line
	sfw::drawLine(minx, miny, maxx, miny);
	//left line
	sfw::drawLine(minx, miny, minx, maxy);
	//right line
	sfw::drawLine(maxx, miny, maxx, maxy);
	//top line
	sfw::drawLine(minx, maxy, maxx, maxy);
}