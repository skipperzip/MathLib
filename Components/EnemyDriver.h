#pragma once
#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"

class EnemyDriver
{
public:
	int RIGHT = 0;
	int LEFT = 0;
	int FORWARD = 1;
	int STOP = 0;

	void locate(Transform &Player, Transform &Enemy);


	void update(SpaceshipLocomotion &loco);
};