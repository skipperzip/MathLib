#include "GameState.h"

void GameState::play()
{
	player.transform.m_position = vec2{ 200,200 };
	player.transform.m_facing = 0;
}

void GameState::update(float deltaTime)
{
	player.update(deltaTime, *this);
	camera.update(deltaTime, *this);
}

void GameState::draw()
{
	mat3 cam = camera.getCameraMatrix();

	player.draw(cam);
}