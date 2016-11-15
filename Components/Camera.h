#pragma once
#include "Transform.h"

class Camera
{
public:
	mat3 projection;
	Transform transform;

	Camera();
	mat3 getCameraMatrix() const;
	void update(float deltaTime, class GameState &gs);
};