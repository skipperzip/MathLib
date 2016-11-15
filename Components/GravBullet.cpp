#include "GravBullet.h"

GravBullet::GravBullet()
{
	timer = 0;

	vec2 hullVrts[] = { { -.1f, 0 },{ 0,.2f },{ .1f,0 } };
	collider = Collider(hullVrts, 3);
	transform.m_scale = vec2{ 40,40 };	
	rigidbody.mass = 10;
}

void GravBullet::update(float deltaTime, GameState & gs)
{
	// The timer always counts down- if it dies, then we 
	// don't update or draw. If we don't do these things,
	// nobody even knows it exists.

	// When the bullet spawns, the timer can be set
	// along with a velocity and position (player update).
	timer -= deltaTime;
	isAlive = timer > 0;
	
	if (!isAlive) return;

	rigidbody.integrate(transform, deltaTime);
}

void GravBullet::draw(const mat3 & camera)
{
	if (!isAlive) return;

	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}

