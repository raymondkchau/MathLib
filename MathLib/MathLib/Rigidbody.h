#pragma once
#include "vec2.h"
#include "transform.h"

class Rigidbody
{
public:
	vec2 velocity; //speed * direction
	vec2 acceleration; //A = F/M
	vec2 jerk; //optional
	vec2 force; //continuous forces
	vec2 impulse; //sudden force such as an explosion or boost or a jump
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
				  drag(0.25f),
				  angularVelocity(0),
				  angularAcceleration(0),
				  torque(0),
				  angularDrag(0.25f)
	{

	}

	//verlet may be more preferable
	void integrate(Transform &t, float dt)
	{
		//linear motion
		acceleration = force / mass;
		//acceleration += jerk * dt;
		velocity += acceleration * dt + impulse / mass;
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