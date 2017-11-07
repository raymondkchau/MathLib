#pragma once
#include "vec2.h"
#include "transform.h"

class Rigidbody
{
	//to use, put inside of whatever you're planning to use, such as the circle
public:
	vec2 velocity; //speed * direction
	vec2 acceleration; //A = F/M
	vec2 jerk; //optional
	vec2 force; //continuous forces
	vec3 impulse; //sudden force such as an explosion or boost or a jump
	float mass;
	float drag; //mimics wind resistance or friction, only included to makes things eventually stop

	float angularVelocity,
		  angularAcceleration,
	  	  torque;
	float angularDrag;

	//the sum of all forces applied to an object
	//A = F/M
	// F = MA

	Rigidbody() : velocity{ 0,0 },
				  acceleration{ 0,0 },
				  jerk{ 0,0 },
				  force{ 0,0 },
				  impulse{ 0,0 },
				  mass(1),
				  drag(1), //accepts floats
				  angularVelocity(0),
				  angularAcceleration(0),
				  torque(0),
				  angularDrag(1) //accepts floats
	{

	}

	//verlet may be more preferable
	void integrate(Transform &t, float dt)
	{
		//linear motion
		acceleration = force / mass;
		//acceleration += jerk * dt;
		velocity += acceleration * dt + vec2{impulse[0], impulse[1]} / mass;
		t.position += velocity * dt;

		impulse = { 0,0 };
		force = -velocity * drag;

		//angular motion (sort of)
		angularAcceleration = torque / mass;
		angularVelocity = angularAcceleration * dt;
		t.angle += angularVelocity * dt;

		torque = -angularVelocity * angularDrag;
	}
};