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

/*
To Do:
- Figure out spawning with a prefab-like thing
- Make it so you can shoot like a machine gun
- Probably add in functions for the bullets and shit for updates so its more organized
- Add in basic AI
- Add in collision
- Figure out how to delete shit so memory doesn't fucking implode
*/

void main()
{
	//unsigned int imgButt = sfw::loadTextureMap("res/avacado.png");

	sfw::initContext(800, 600, "Testing Garbage");

	circle circ;
	circ.rigidbody.velocity = normalize(vec2{ 800, 600 });

	circ.position = { 400, 300 };
	circ.radius = 25;
	circ.transform.position = circ.position;

	shot shot;
	shot.circle.position = { 0, 0 };
	shot.timeAlive = 2.0f;

	float lastShot = 1.0f;
	float boost = 1.0f;

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		if(lastShot < 1.0f)
		{ 
			std::cout << "Time from Last Shot: " << lastShot << std::endl;
			lastShot += sfw::getDeltaTime();
		}

		if (boost < 1.0f)
		{
			std::cout << "Time from Last Boost: " << boost << std::endl;
			boost += sfw::getDeltaTime();
		}

		circ.rigidbody.integrate(circ.transform, dt); //applies the transforms from rigidbody into transform
		DrawMatrix(circ.transform.getGlobalTransform(), 40); //draws the transforms
		
		//circ.rigidbody.force += { 0,-10 }; //applies constant force, like gravity
		if (sfw::getKey('W')) { circ.rigidbody.force += circ.transform.getGlobalTransform()[1].xy * 100; } // gets the up direction of the "ship" and applies a force
		if (sfw::getKey('A')) { circ.transform.angle += 1; } //rotates left
		if (sfw::getKey('D')) { circ.transform.angle -= 1; } //rotates right

		//boost, works better with a timer and a bool to prevent overuse
		if (sfw::getKey('Q') && boost >= 1.0f)
		{
			boost = 0;
			circ.rigidbody.impulse += circ.transform.getGlobalTransform()[1] * 200;
		}

		//a simple braking force
		if(sfw::getKey('F'))
		{
			circ.rigidbody.force += -circ.rigidbody.velocity * 20;
			circ.rigidbody.torque += -circ.rigidbody.angularVelocity * 20;
		}

		//testing shooting
		if (sfw::getKey(' ') && lastShot >= 1.0f)
		{
			//spawn a bullet
			lastShot = 0; //resets time since last shot
			shot.timeAlive = 0; //resets shot life
			shot.circle = circ; //makes the bullet spawn location at the player and where the player is facing
		}
		
		if (shot.timeAlive < 1.0f)
		{
			//bullet update and destruction
			DrawMatrix(shot.circle.transform.getGlobalTransform(), 60); //draws the bullet, a placeholder
			shot.circle.rigidbody.integrate(shot.circle.transform, dt); //applies the changes from rigidbody
			shot.circle.rigidbody.impulse += shot.circle.transform.getGlobalTransform()[1] * 100; //makes changes into rigidbody
			shot.timeAlive += sfw::getDeltaTime(); //keeps track of last time player has shot
			std::cout << "Bullet Time Alive: " << shot.timeAlive << std::endl; //debug notes
		}

		if (sfw::getKey(KEY_ESCAPE)) //Esc ends game
		{
			sfw::termContext();
		}
	}

	sfw::termContext(); //clicking the X ends game
}

/*
//linear movement
if (sfw::getKey('W')) { rigidbody.velocity = { 0,100 }; }
if (sfw::getKey('A')) { rigidbody.velocity = { -100,0 }; }
if (sfw::getKey('S')) { rigidbody.velocity = { 0,-100 }; }
if (sfw::getKey('D')) { rigidbody.velocity = { 100,0 }; }
*/

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