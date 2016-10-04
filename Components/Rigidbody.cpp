#include "Rigidbody.h"

void Rigidbody::integrate(Transform &trans, float deltaTime)
{
	// perform euler integration! :)
	trans.position = trans.position + velocity * deltaTime;
}