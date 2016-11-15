#pragma once

#include "PlayerShip.h"
#include "Camera.h"
/*
	init
	- Called once at application start.
	- Used for loading resources (like textures).
	
	play/exec/enter
	- Called once as we transition into an application state.
	- Used to reset the logic of the state (ie. new game, reset timers).
	
	exit
	- Called once as we transition out of a state.
	- Not terribly useful!

	term
	- Called once at application shutdown
	- Used to free resources (like textures).
	
	step/update/tick
	- Called once every frame.
	- Used to update logic.

	draw/render
	- Called once every frame.
	- Used to issue draw commands.
*/

class GameState
{

public:
	PlayerShip player;
	Camera camera;
	
	void play();				  //
	void update(float deltaTime); // equivalent of step
	void draw();
};