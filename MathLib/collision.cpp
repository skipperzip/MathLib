#include "collision.h"


CollisionData1D collisionDetection1D(float Amin, float Amax,
									 float Bmin, float Bmax)
{
	CollisionData1D retval;

	// How do you evaluate the penetration depth?
	retval.penetrationDepth;

	// How do you calculate the Collision Normal?
	retval.collisionNormal;

	retval.result = retval.penetrationDepth >= 0;
	retval.MTV = retval.penetrationDepth 
					* retval.collisionNormal;
	return retval;
}
