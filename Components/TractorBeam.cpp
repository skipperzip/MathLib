#include "TractorBeam.h"

TractorBeam::TractorBeam()
{
	vec2 hullVrts[] = { { .1f,.3f },{-.1f,.3f},{ -4.f,6.f },{ 4.f,6.f } };
	collider = Collider(hullVrts, 4);

	transform.m_scale = vec2{100,100};
	isAlive = false;
	oneFrame = false;
}

void TractorBeam::update(float deltaTime, GameState & gs)
{
	// We need to disable the tractor beam, but we want it to work
	// for ONE frame.
	// So we can't disable the tractor beam here right away.
	// Instead, we'll use a boolean to act as a gate to ensure we last
	// one frame.
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
