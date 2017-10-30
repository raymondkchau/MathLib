#pragma once
#include "shapes.h"
#include "sfwdraw.h"

void drawCircle(const circle &c)
{
	sfw::drawCircle(c.position.x, c.position.y, c.radius);
}