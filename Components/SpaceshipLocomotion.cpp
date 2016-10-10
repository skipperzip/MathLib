#include "SpaceshipLocomotion.h"

#include "sfwdraw.h"

SpaceshipLocomotion::SpaceshipLocomotion()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;
	stopAction = 0.0f;
	breakPower = 4.0f;

	// Angles per second
	turnSpeed = 4.0f;

	// Pixels per second
	speed = 900.0f;
	maxSpeed = 1000.0f;
}

void SpaceshipLocomotion::doThrust(float value)
	{ vertThrust += value; }

void SpaceshipLocomotion::doTurn(float value)
	{ horzThrust += value; }

void SpaceshipLocomotion::doStop(float value)
	{ stopAction += value; }

void SpaceshipLocomotion::update(const Transform &trans,
										Rigidbody &rigidbody)
{
	rigidbody.addForce(trans.getUp() * speed * vertThrust);
	rigidbody.addTorque(turnSpeed * horzThrust);
	
	rigidbody.addForce(-rigidbody.velocity * breakPower * stopAction);
	rigidbody.addTorque(-rigidbody.angularVelocity * breakPower * stopAction);

	horzThrust = vertThrust = stopAction = 0;
}