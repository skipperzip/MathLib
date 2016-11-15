#pragma once
#include "shapes.h"
#include "Transform.h"
#include "collision.h"
#include "Rigidbody.h"

class Collider
{
public:
	AABB box;
	Hull hull;

	Collider();
	Collider(const vec2 *verts, int size);
	void DebugDraw(const mat3 &T, const Transform &trans);
};


CollisionData ColliderCollision(const Transform &AT, const Collider &AC,
								const Transform &BT, const Collider &BC);




CollisionData StaticResolution(Transform &AT, Rigidbody &AR, const Collider &AC,
								const Transform &BT, const Collider &BC,
								float bounciness = 1);



// You could potentially factor the surface normal in some way
// to affect the resulting direction of the collision
	// do a weighted average of the collision normal and the velocity's normal	
	//velocity +/- = magnitude(velocity) * (normal(velocity) + collisionNormal)/2;
CollisionData DynamicResolution(Transform &AT, Rigidbody &AR, const Collider &AC,
							    Transform &BT, Rigidbody &BR, const Collider &BC,
								float bounciness = 1);

