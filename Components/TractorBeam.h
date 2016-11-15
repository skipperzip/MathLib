#pragma once
#include "Transform.h"
#include "Collider.h"

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