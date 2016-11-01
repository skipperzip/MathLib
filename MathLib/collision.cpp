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


// TODO:
// Deal with non-colliding velocities properly.
CollisionDataSwept boxCollisionSwept(const AABB & A, const vec2 & dA,
									 const AABB & B, const vec2 & dB)
{
	CollisionDataSwept retval;
	
	// Discrete results in case there is no movement along the axis.
	CollisionData1D Xdis = collisionDetection1D(A.min().x, A.max().x, B.min().x, B.max().x);
	CollisionData1D Ydis = collisionDetection1D(A.min().x, A.max().x, B.min().x, B.max().x);

	// Swept results along each axis
	SweptCollisionData1D Xres = sweptDetection1D(A.min().x, A.max().x, dA.x,
												 B.min().x, B.max().x, dB.x);

	SweptCollisionData1D Yres = sweptDetection1D(A.min().y, A.max().y, dA.y,
												 B.min().y, B.max().y, dB.y);
	// whether or not to use swept along that axis.
	bool xSwept = (dA.x - dB.x != 0);
	bool ySwept = (dA.y - dB.y != 0);

	
	// if x is sweeping and happens latest OR y is not sweeping
	if (Yres.entryTime < Xres.entryTime || xSwept && !ySwept)
	{
		retval.collisionNormal = vec2{ 1,0 } * Xres.collisionNormal;
		retval.entryTime = Xres.entryTime;

		retval.collides = ySwept || Ydis.result();
	}
	else if (ySwept)
	{
		retval.collisionNormal = vec2{ 0,1 } * Yres.collisionNormal;
		retval.entryTime = Yres.entryTime;
		retval.collides = xSwept || Xdis.result();
	}

	if (Yres.exitTime < Xres.exitTime || ySwept && !xSwept)

		retval.exitTime = Yres.exitTime;
	else if (xSwept)
		retval.exitTime = Xres.exitTime;

	return retval;
}

CollisionData planeBoxCollision(const Plane & P,
								const AABB  & B)
{
	CollisionData retval;
	// Project the corners of the box onto the plane's axis.	
	float pTL = dot(P.dir, vec2{B.min().x, B.max().y});
	float pBR = dot(P.dir, vec2{B.max().x, B.min().y});
	float pTR = dot(P.dir, B.max());
	float pBL = dot(P.dir, B.min());

	float pBmin = fminf(fminf(pTL, pTR), fminf(pBR, pBL));
	//float pBmax = fmaxf(fmaxf(pTL, pTR), fmaxf(pBR, pBL));

	// Projecting plane's point onto the axis
	float pPmax = dot(P.dir, P.pos);

	retval.collisionNormal = P.dir;

	retval.penetrationDepth = pPmax - pBmin;
	return retval;
}

CollisionDataSwept planeBoxCollisionSwept(const Plane & P, const vec2 &Pvel,
										  const AABB & B,  const vec2 & Bvel)
{
	CollisionDataSwept retval;

	float pTL = dot(P.dir, vec2{ B.min().x, B.max().y });
	float pBR = dot(P.dir, vec2{ B.max().x, B.min().y });
	float pTR = dot(P.dir, B.max());
	float pBL = dot(P.dir, B.min());

	float pBmin = fminf(fminf(pTL, pTR), fminf(pBR, pBL));
	float pBmax = fmaxf(fmaxf(pTL, pTR), fmaxf(pBR, pBL));

	float pBvel = dot(P.dir, Bvel);
	float pPvel = dot(P.dir, Pvel);

	float pPmax = dot(P.dir, P.pos);

	retval.entryTime = (pBmin - pPmax) / (pPvel - pBvel);
	retval.exitTime  = (pBmax - pPmax) / (pPvel - pBvel);

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

bool CollisionDataSwept::result() const
{
	return entryTime >= 0 && entryTime <= 1 && collides;
}
