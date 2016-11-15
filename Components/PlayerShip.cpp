#include "PlayerShip.h"
#include "GameState.h"


PlayerShip::PlayerShip()
{
	vec2 hullVrts[] = { { 0, 3 }, { -2,-3 }, { 2,-3 } };
	collider = Collider(hullVrts, 3);

	transform.m_scale = vec2{ 10,10 };
}

void PlayerShip::update(float deltaTime, GameState &gs)
{
	controller.update(locomotion);
	locomotion.update(transform, rigidbody);

	rigidbody.integrate(transform, deltaTime);

	// Ideally you make a function in a bullet manager or the game state
	// which creates the bullets automatically based on parameters.
	// This solution is kind of hacky!

	// Tractor beam spawning example!
	if (sfw::getKey('T'))
	{
		gs.tractor.isAlive = true; // reset the beam
		gs.tractor.oneFrame = false;
		// have it look where we are looking
		gs.tractor.transform.m_position = transform.m_position;
		gs.tractor.transform.m_facing = transform.m_facing;
	}

	// Bullet spawning Example!
	if (sfw::getKey('F') && !gs.bullet.isAlive)
	{
		// bring it to life
		gs.bullet.timer = 2.f;

		// set up it's position and stuff
		gs.bullet.transform.m_position = transform.m_position;
		gs.bullet.transform.m_facing = transform.m_facing;

		//reset velocity
		gs.bullet.rigidbody.velocity = vec2{ 0,0 };
		// get it moving
		gs.bullet.rigidbody.addImpulse(transform.getUp() * 3000.f);
	}
}

void PlayerShip::draw(const mat3 &camera)
{
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}