#include <iostream>
#include "vec2.h"
#include "vec3.h"
#include "mat3.h"
#include "shapes.h"
#include "DrawShapes.h"
#include "Rigidbody.h"
#include "mathutils.h"
#include "sfwdraw.h"
#include "HelperDraw.h"

void main()
{
	//unsigned int imgButt = sfw::loadTextureMap("res/avacado.png");

	/*
	sfw::initContext(800, 600, "Fucking Goddamn Bullshit");
	sfw::setBackgroundColor(BLACK);

	while (sfw::stepContext())
	{
		update();
	}

	sfw::termContext();
	*/

	sfw::initContext();

	Transform transform;
	Rigidbody rigidbody;

	circle circ;
	transform.position = vec2{ 400,300 };
	rigidbody.velocity = normalize(vec2{ 800,600 });

	circ.position = { 400, 300 };
	circ.radius = 25;

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();
		rigidbody.integrate(transform, dt); //?

		drawCircle(transform.getGlobalTransform() * circ);
		DrawMatrix(transform.getGlobalTransform(), 40);

		DrawSquare({ 350, 250 }, { 450, 350 }, dt);

		
		//linear movement
		if (sfw::getKey('W')) { rigidbody.velocity = { 0,100 }; }
		if (sfw::getKey('A')) { rigidbody.velocity = { -100,0 }; }
		if (sfw::getKey('S')) { rigidbody.velocity = { 0,-100 }; }
		if (sfw::getKey('D')) { rigidbody.velocity = { 100,0 }; }
		
		/*
		//speeds up movement, slippery
		if (sfw::getKey('W')) { circ.rigidbody.acceleration = { 0,100 }; }
		if (sfw::getKey('A')) { circ.rigidbody.acceleration = { -100,0 }; }
		if (sfw::getKey('S')) { circ.rigidbody.acceleration = { 0,-100 }; }
		if (sfw::getKey('D')) { circ.rigidbody.acceleration = { 100,0 }; }
		*/

		/*
		//ramps up movement, I assume like a car
		if (sfw::getKey('W')) { rigidbody.jerk = { 0,100 }; }
		if (sfw::getKey('A')) { rigidbody.jerk = { -100,0 }; }
		if (sfw::getKey('S')) { rigidbody.jerk = { 0,-100 }; }
		if (sfw::getKey('D')) { rigidbody.jerk = { 100,0 }; }
		*/
		/*
		//applies forces such as gravity or be used to accelerate
		rigidbody.force += { 0,-10 }; //gravity
		//moving jets
		if (sfw::getKey('W')) { rigidbody.force += { 0,100 }; }
		if (sfw::getKey('A')) { rigidbody.force += { -100,0 }; }
		if (sfw::getKey('S')) { rigidbody.force += { 0,-100 }; }
		if (sfw::getKey('D')) { rigidbody.force += { 100,0 }; }
		*/
		/*
		rigidbody.force += { 0,-10 }; //gravity
		if (sfw::getKey('W')) { rigidbody.force += transform.getGlobalTransform()[1].xy * 100; // gets the up direction of the "ship" and applies a speed thingy
		if (sfw::getKey('A')) { rigidbody.torque += 360;
		if (sfw::getKey('D')) { rigidbody.torque += -360;

		//boost, works better with a timer and a bool to prevent overuse
		if (sfw::getKey('Q')) { rigidbody.impluse += transform.getGlobalTransform()[1] * 10;

		//a simple braking force
		if(sfw::getKey(' '))
		{
			rigidbody.force += -rigidbody.velocity * 20;
			rigidbody.torque += -rigidbody.angularVelocity * 20;
		}
		*/

		circ.rigidbody.integrate(transform, dt);

		//DrawMatrix(transform.getGlobalTransform(), 12);
	}

	sfw::termContext();
}