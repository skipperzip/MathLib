#include "PlanetaryMotor.h"

void PlanetaryMotor::update(Rigidbody & planetRbody)
{
	planetRbody.addTorque(m_rotationSpeed);
}
