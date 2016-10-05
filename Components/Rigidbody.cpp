#include "Rigidbody.h"

Rigidbody::Rigidbody()
{
	mass = 1;
	force = vec2{ 0,0 };
	impulse = vec2{ 0,0 };
	acceleration = vec2{ 0,0 };
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	angularAcceleration = 0.0f;
	torque = 0;
}

void Rigidbody::addForce(const vec2 &a_force)
	{ force   += a_force;   }
void Rigidbody::addImpulse(const vec2 &a_impulse)
	{ impulse += a_impulse; }
void Rigidbody::addTorque(float a_torque)
	{ torque += a_torque; }


void Rigidbody::integrate(Transform &trans, float deltaTime)
{
	acceleration    = force / mass;
	velocity       += acceleration * deltaTime + impulse / mass;
	trans.position += velocity * deltaTime;
	force = impulse = { 0,0 };

	angularAcceleration  = torque / mass;
	angularVelocity     += angularAcceleration * deltaTime;
	trans.facing        += angularVelocity * deltaTime;
	torque = 0;
}