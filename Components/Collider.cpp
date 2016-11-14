#include "Collider.h"
#include "shapedraw.h"

Collider::Collider(const vec2 * verts, int size)
				: hull(verts,size)
{
	/* Determine the AABB properties.
		Min = Find the smallest X and Y among verts.
		Max = Find the largest X and Y among verts.
		
		pos = (Min + Max)/2
		dim = (Max - Min)/2
	*/

	box = { {0,0},{3,3} };
}

void Collider::DebugDraw(const mat3 & T,
							const Transform & trans)
{
	drawAABB(T * trans.getGlobalTransform() * box, 0x888888ff);

	// Draw the convex hull!
		// You'll need a drawing function for hulls!
}
