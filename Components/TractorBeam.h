#pragma once
#include "Transform.h"
#include "Collider.h"


///////////////////
// By request:

/*
Tractor beam should spit out a beam thingy and drag objects close to us.

To accomplish this, we only need a transform and a collider.

The tractor beam will behave kind of like a bullet, but it doesn't move
and only lasts one frame. If the player holds the button down, we'll just
respawn the tractor beam every frame.

Instead of complicating things, we'll just make a hit-box that represents
our beam area, and then implement an interaction function to govern what
happens when things are in the beam.

We won't use static/dynamic collision either! You could think of the tractor
beam like it was a trigger.
*/
class TractorBeam
{
public:
	Transform	transform;
	Collider	collider;

	bool isAlive;
	bool oneFrame;

	TractorBeam();

	void update(float deltaTime,class GameState &gs);

	void draw(const mat3 &camera);
};