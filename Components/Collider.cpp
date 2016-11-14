#include "Collider.h"
#include "shapedraw.h"
#include <cmath>

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