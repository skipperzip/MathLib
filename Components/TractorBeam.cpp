#include "TractorBeam.h"

TractorBeam::TractorBeam()
{
	// shape of the tractor beam
	vec2 hullVrts[] = { { .1f,.3f },{-.1f,.3f},{ -4.f,6.f },{ 4.f,6.f } };
	collider = Collider(hullVrts, 4);

	transform.m_scale = vec2{100,100};
	isAlive = false;
	oneFrame = false;
}

void TractorBeam::update(float deltaTime, GameState & gs)
{
	// This a 'logic gate' to ensure that the bullet stays
	// alive for at LEAST one frame.
	// If the player holds the button down, we want to make
	// sure isAlive is true and oneFrame is false.

	// See the player's update function to see how it is spawned!
	if (oneFrame)
	{
		isAlive = false;
		oneFrame = false;
	}
	if (isAlive)
	{
		oneFrame = true;
	}
}

void TractorBeam::draw(const mat3 & camera)
{
	if (!isAlive) return;
	collider.DebugDraw(camera, transform);
}
