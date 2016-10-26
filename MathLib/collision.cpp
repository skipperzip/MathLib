#include "collision.h"


CollisionData1D collisionDetection1D(float Amin, float Amax,
									 float Bmin, float Bmax)
{
	CollisionData1D retval;

	// How do you evaluate the penetration depth?
	retval.penetrationDepth;

	// How do you calculate the Collision Normal?
	// -1 or 1
	retval.collisionNormal;

	return retval;
}

bool CollisionData1D::result() const
{
	return penetrationDepth >= 0;
}

float CollisionData1D::MTV() const
{
	return penetrationDepth * collisionNormal;
}
