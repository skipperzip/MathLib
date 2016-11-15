#include "Camera.h"
#include "GameState.h"

///////////////////////////
// Projection is the 'lens'
// the translation should be HALF of the screen width and height
// Scale is how big/small we want things to be-- or the 'zoom' sort of.
Camera::Camera()
{
	projection = translate(600, 600) * scale(2.f, 2.f);
}

mat3 Camera::getCameraMatrix() const
{
	return projection * inverse(transform.getGlobalTransform());
}

void Camera::update(float deltaTime, GameState & gs)
{
	transform.m_position = gs.player.transform.getGlobalPosition();
}