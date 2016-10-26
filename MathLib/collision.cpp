#include "collision.h"
#include <cmath>

CollisionData1D collisionDetection1D(float Amin, float Amax,
									 float Bmin, float Bmax)
{
	CollisionData1D retval;

	float pDr = Amax - Bmin;
	float pDl = Bmax - Amin;
	
	retval.penetrationDepth = fmin(pDr, pDl);

	retval.collisionNormal = copysignf(1, pDl - pDr);

	return retval;
}

SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel,
									  float Bmin, float Bmax, float Bvel)
{
	SweptCollisionData1D retval;

	float tl = (Amin - Bmax) / (Bvel - Avel);
	float tr = (Bmin - Amax) / (Avel - Bvel);

	retval.entryTime = fmin(tl, tr);
	retval.exitTime  = fmax(tl, tr);
	
	retval.collisionNormal = copysignf(1, tl - tr);

	return retval;
}




bool CollisionData1D::result() const
		{ return penetrationDepth >= 0; }

float CollisionData1D::MTV() const
		{ return penetrationDepth * collisionNormal; }

bool SweptCollisionData1D::result() const
{
	return entryTime >= 0 && entryTime <= 1;
}


CollisionData boxCollision(const AABB & A, const AABB & B)
{
	CollisionData retval;

	CollisionData1D XCD = 
		collisionDetection1D(A.min().x, A.max().x,
							 B.min().x, B.max().x);

	CollisionData1D YCD =
		collisionDetection1D(A.min().y, A.max().y,
							 B.min().y, B.max().y);

	if (XCD.penetrationDepth < YCD.penetrationDepth)
	{
		retval.penetrationDepth = XCD.penetrationDepth;
		retval.collisionNormal = 
					   vec2{1,0} * XCD.collisionNormal;
	}
	else
	{
		retval.penetrationDepth = YCD.penetrationDepth;
		retval.collisionNormal =
						vec2{0,1} * YCD.collisionNormal;
	}
	return retval;
}

bool CollisionData::result() const
{
	return penetrationDepth >= 0;
}

vec2 CollisionData::MTV() const
{
	return collisionNormal * penetrationDepth;
}
