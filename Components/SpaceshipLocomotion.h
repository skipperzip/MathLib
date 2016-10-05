#pragma once

#include "Rigidbody.h"

class SpaceshipLocomotion
{
	float vertThrust;	// vertical	  (-1 to 1 value)
	float horzThrust;	// horizontal (-1 to 1 value)
	float stopAction;

	float breakPower;
	float turnSpeed;
	float speed;		// movement speed
	float maxSpeed;		// max move speed

public:
	SpaceshipLocomotion();

	void doThrust(float value);
	void doTurn(float value);

	void doStop(float value);

	void update(const Transform &trans, Rigidbody &rigidbody);
};