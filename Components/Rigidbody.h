#pragma once

#include "vec2.h"

#include "Transform.h"

class Rigidbody
{
public:
	Rigidbody();

	vec2 velocity;				// represents the change in position
	float angularVelocity;		// represents the change in rotation

	vec2 acceleration;			// represents the change in velocity
	float angularAcceleration;	// represents the change in ang vel

	void addForce(const vec2 &force);
	void addImpulse(const vec2 &impulse);

	void addTorque(float torque);

	void integrate(Transform &trans, float deltaTime);	// performs integration :)
};