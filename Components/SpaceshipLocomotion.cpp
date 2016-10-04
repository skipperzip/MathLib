#include "SpaceshipLocomotion.h"

#include "sfwdraw.h"

SpaceshipLocomotion::SpaceshipLocomotion()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;

	speed = 900.0f;
	maxSpeed = 1000.0f;
}

void SpaceshipLocomotion::doThrust(float value)
{
	vertThrust = value;
}

void SpaceshipLocomotion::doTurn(float value)
{
	horzThrust = value;
}

void SpaceshipLocomotion::update(Rigidbody &rigidbody, float deltaTime)
{
	// apply the values to my rigidbody
	rigidbody.acceleration.x = horzThrust * speed;
	rigidbody.acceleration.y = vertThrust * speed;

	// if we are moving faster than our max speed...
	if (magnitude(rigidbody.velocity) > maxSpeed)
	{
		// gets the direction
		vec2 dir = normal(rigidbody.velocity);
		
		// rescale the velocity to clamp to the max speed
		rigidbody.velocity = dir * maxSpeed;
	}

	// zero out the thrust values
	vertThrust = 0.0f;
	horzThrust = 0.0f;
}