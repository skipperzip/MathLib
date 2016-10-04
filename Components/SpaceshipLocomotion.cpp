#include "SpaceshipLocomotion.h"

#include "sfwdraw.h"

// using namespace sfw;
// using sfw::getKey;

SpaceshipLocomotion::SpaceshipLocomotion()
{
	thrust = 0.0f;
	maxThrust = 100.0f;

	turn = 0.0f;
	maxTurn = 100.0f;
	turnSpeed = 1.0f;

	speed = 10.0f;
}

void SpaceshipLocomotion::doThrust()
{
	if (sfw::getKey('W')) thrust = 1;
}

void SpaceshipLocomotion::doTurn()
{
	if (sfw::getKey('Q')) turn += 1;
	if (sfw::getKey('E')) turn -= 1;
}

void SpaceshipLocomotion::update(Rigidbody &rigidbody, float deltaTime)
{
	// apply the values to my rigidbody
	// what happens with thrust?
	// what happens with turn?

	// zero out the thrust values
	thrust = 0.0f;
	turn = 0.0f;
}