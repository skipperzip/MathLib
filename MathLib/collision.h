#pragma once
#include "vec2.h"
#include "shapes.h"

struct CollisionData1D
{
	float penetrationDepth; // how much overlap
	float collisionNormal;  // -1 or 1

	bool result() const;
	float MTV()   const;
};

CollisionData1D collisionDetection1D(float Amin, float Amax,
									 float Bmin, float Bmax);

struct SweptCollisionData1D
{
	float entryTime, exitTime;
	float collisionNormal;  // -1 or 1

	bool result() const; // Entry time is between 0 and 1
};

SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel,
									  float Bmin, float Bmax, float Bvel);


struct CollisionData
{
	float penetrationDepth;
	vec2 collisionNormal;

	bool result() const;
	vec2 MTV() const;
};

CollisionData boxCollision(const AABB &A,
						   const AABB &B);

struct CollisionDataSwept
{
	float entryTime, exitTime;
	vec2 collisionNormal;
	bool collides;

	bool result() const;
};

CollisionDataSwept boxCollisionSwept(const AABB &A, const vec2 &dA,
						             const AABB &B, const vec2 &dB);
// Determine the 4 points on the box.
// Project them onto the plane's axis.
// Find the minimum and maximum along the axis.
// Perform 1D SAT discrete detection.
CollisionData planeBoxCollision(const Plane &P,
								const AABB &B);


// You also project the velocity.

CollisionDataSwept planeBoxCollisionSwept(const Plane & P, const vec2 &Pvel,
	const AABB & B, const vec2 & Bvel);




/*
	For each axis defined by the surface normals of the hulls:
		find the minimum and maximum extents for those shapes
			do this by projecting each point and finding the smallest and largest
		Perform 1D SAT along that axis using the extents

	The smallest penetration depth represents the final result.

*/
CollisionData HullCollision(const Hull &A, const Hull &B);

/*
	The most normal of axes you'll deal with is 32.
*/

/*
	bestResult.penetrationDepth = -INFINITY

	for each axis of A:
		for A, loop to project points and finding min/max (similar to plane vs box)
		for B, loop to project points and finding min/max
		
		currentResult = 1DSAT(amin, amax, bmin, bmax)
		
		if(currentResult.penetrationDepth < bestResult.penetrationDepth)
			bestResult = currentResult;

	for each axis of B:
		for A, loop to project points and finding min/max
		for B, loop to project points and finding min/max

		currentResult = 1DSAT(amin, amax, bmin, bmax)

		if(currentResult.penetrationDepth < bestResult.penetrationDepth)
			bestResult = currentResult;
	*/