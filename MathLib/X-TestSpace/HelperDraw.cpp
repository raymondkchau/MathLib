#include "HelperDraw.h"
#include "sfwdraw.h"
void DrawMatrix(const mat3 & t, float drawing_scale)
{
	vec2 pos = t[2].xy;
	vec2 right = pos + (t[1].xy * drawing_scale);
	vec2 up = pos + (t[0].xy * drawing_scale);

	sfw::drawCircle(pos.x, pos.y, drawing_scale / 4);
	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	sfw::drawLine(pos.x, pos.y, up.x, up.y, GREEN);
}
