#pragma once

struct CollisionData1D
{
	bool  result;		    // penetrationDepth > 0
	float penetrationDepth; // how much overlap
	float collisionNormal;  // -1 or 1
	float MTV;				// penetrationDepth * collisionNormal
};


CollisionData1D collisionDetection1D(float Amin, float Amax,
									 float Bmin, float Bmax);