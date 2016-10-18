#pragma once

#include "Rigidbody.h"

class PlanetaryMotor
{
public:
	float m_rotationSpeed;

	void update(Rigidbody &planetRbody);
};