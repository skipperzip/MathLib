#pragma once

#include "Rigidbody.h"

class SpaceshipLocomotion
{
	float thrust;		// forward movement	(0-1 value)
	float maxThrust;	// max forward movement

	float turn;			// turn				(-1 to 1 value)
	float maxTurn;		// max turn
	float turnSpeed;	// rate of change for our turn

	float speed;		// movement speed

public:
	SpaceshipLocomotion();

	void doThrust();
	void doTurn();

	void update(Rigidbody &rigidbody, float deltaTime);
};