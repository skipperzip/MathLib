#pragma once
#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"

/*
	As per request!

	The bullet works the same way as an asteroid.
	The only difference is that we want to give it a
	new position, rotation when we fire and want it to
	become inactive after a little why (or collision).

	It would be /best/ to manage bullets in an array so we could
	support potentially hundreds of them, but this example doesn't
	provide support for that just yet.
*/
class GravBullet
{
public:
	Transform	transform;
	Collider	collider;
	Rigidbody	rigidbody;

	float timer;
	bool isAlive;
	
	GravBullet();

	void update(float deltaTime,
						class GameState &gs);

	void draw(const mat3 &camera);
};