#pragma once

#include "vec2.h"
#include "Transform.h"

class Rigidbody
{
public:
	Rigidbody();

	float mass, drag, angularDrag;

	vec2 force, impulse;
	vec2 velocity;				// represents the change in position
	vec2 acceleration;			// represents the change in velocity

	float torque;
	float angularVelocity;		// represents the change in rotation
	float angularAcceleration;	// represents the change in ang vel

	void addForce(const vec2 &force);
	void addImpulse(const vec2 &impulse);
	void addTorque(float torque);

	void integrate(Transform &trans, float deltaTime);	// performs integration :)

	void debugDraw(const Transform &trans);
};