#pragma once
#include "shapes.h"
#include "Transform.h"
#include "collision.h"

class Collider
{
public:
	AABB box;
	Hull hull;

	Collider(const vec2 *verts, int size);
	void DebugDraw(const mat3 &T, const Transform &trans);
};


CollisionData ColliderCollision(const Transform &AT, const Collider &AC,
								const Transform &BT, const Collider &BC);