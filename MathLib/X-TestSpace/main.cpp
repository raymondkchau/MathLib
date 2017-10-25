#include <iostream>
#include "vec2.h"
#include "vec3.h"
#include "mat3.h"
#include "mathutils.h"
#include "sfwdraw.h"

//initializing public stuff
unsigned int imgButt = sfw::loadTextureMap("res/avacado.png");

void update()
{
	//called per frame
	sfw::drawTexture(imgButt, 400, 300, 100, 100);
}

void main()
{
	sfw::initContext(800, 600, "Fucking Goddamn Bullshit");
	sfw::setBackgroundColor(BLACK);

	while (sfw::stepContext())
	{
		update();
	}

	sfw::termContext();
}