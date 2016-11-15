#include "Collider.h"
#include "shapedraw.h"
#include <cmath>

Collider::Collider()
{
}

Collider::Collider(const vec2 * verts, int size)
				: hull(verts,size)
{
	vec2 boxMin = { INFINITY,  INFINITY},
		 boxMax = {-INFINITY, -INFINITY};

	for (int i = 0; i < size; ++i)
	{
		boxMin = min(boxMin, verts[i]);
		boxMax = max(boxMax, verts[i]);
	}

	box.pos = (boxMin + boxMax) / 2;
	box.he  = (boxMax - boxMin) / 2;
}

void Collider::DebugDraw(const mat3 & T,
							const Transform & trans)
{
	mat3 glob = T * trans.getGlobalTransform();

	drawAABB(glob * box , 0x888888ff);
	drawHull(glob * hull, 0x888888ff);
}

CollisionData ColliderCollision(const Transform & AT, const Collider & AC,
								const Transform & BT, const Collider & BC)
{
	CollisionData retval;

	// very fast test helps us determine if something more complex
	// is needed
	retval = boxCollision(AT.getGlobalTransform() * AC.box,
						  BT.getGlobalTransform() * BC.box);

	// It's likely there is a collision
	// So we can use a more expensive evaluation
	if(retval.penetrationDepth >= 0)
		retval = HullCollision(AT.getGlobalTransform() * AC.hull,
							   BT.getGlobalTransform() * BC.hull);

	return retval;
}

CollisionData StaticResolution(Transform & AT, Rigidbody & AR, const Collider & AC,
								const Transform & BT, const Collider & BC,
								float bounciness)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);
	if (results.penetrationDepth >= 0)
	{
		vec2 MTV = results.penetrationDepth * results.collisionNormal;
		AT.m_position -= MTV;

		AR.velocity = reflect(AR.velocity, results.collisionNormal) * bounciness;
	}

	return results;
}



CollisionData DynamicResolution(Transform & AT, Rigidbody & AR, const Collider & AC,
					Transform & BT, Rigidbody & BR, const Collider & BC, float bounciness)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);
	if (results.penetrationDepth >= 0)
	{
		///////////////////////////////////////////////
		/////// Correction
		vec2 MTV = results.penetrationDepth * results.collisionNormal;

		// As long as the MTV is applied, in some way,
			// You will avoid jitter

		float am = magnitude(AR.mass * AR.velocity); //  9
		float bm = magnitude(BR.mass * BR.velocity); //  1
		float cm = am + bm;							 // 10

		AT.m_position -= MTV * (1 - am / cm); // 1-9/10 : 1/10
		BT.m_position += MTV * (1 - bm / cm); // 1-1/10 : 9/10

		//////////////////////////////////////////////////
		/// Resolution
		vec2  A = AR.velocity;		// Velocity for A
		float P = AR.mass;			// Mass for A
		vec2  X;					// final velocity for A

		vec2  B = BR.velocity;		// Velocity for B
		float Q = BR.mass;			// mass for B
		vec2  Y;					// final velocity for Y

		float E = bounciness;		// coefficient of restitution

		//// Solve the system of linear equations!
	//A * P + B * Q = X * P + Y * Q   : conservation of momentum
	//X - Y = -E(A - B)    			  : linear collision

		X = (A*P + B*Q + -E*(A - B)*Q) / (Q + P);
		Y = E*(A - B) + X;

		AR.velocity = X;
		BR.velocity = Y;
	}
	return results;
}
