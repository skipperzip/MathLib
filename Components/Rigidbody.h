#pragma once

#include "vec2.h"

#include "Transform.h"

class Rigidbody
{
public:
	vec2 velocity;	// represents the change in position

	void integrate(Transform &trans, float deltaTime);	// performs integration :)
};