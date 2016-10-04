#include "Rigidbody.h"

Rigidbody::Rigidbody()
{
	acceleration = vec2{ 0,0 };
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	angularAcceleration = 0.0f;
}

void Rigidbody::integrate(Transform &trans, float deltaTime)
{
	velocity = velocity + acceleration * deltaTime;
	angularVelocity = angularVelocity + angularAcceleration * deltaTime;

	trans.position = trans.position + velocity * deltaTime;
	trans.facing = trans.facing + angularVelocity * deltaTime;
}