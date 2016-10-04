#pragma once

#include "Rigidbody.h"

class SpaceshipLocomotion
{
	SpaceshipLocomotion();

	float thrust;		// forward movement
	float maxThrust;	// max forward movement
	float thrustSpeed;	// rate of change for our thrust

	float turn;			// turn
	float maxTurn;		// max turn
	float turnSpeed;	// rate of change for our turn

	float speed;		// movement speed

public:
	void doThrust(float deltaTime);
	void doTurn(float deltaTime);

	void integrate(Rigidbody &rigidbody);
};