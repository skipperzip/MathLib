#pragma once
#pragma once
#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"

class EnemyChaser
{
public:
	int RIGHT = 0;
	int LEFT = 0;
	int FORWARD = 1;
	int STOP = 0;

	void locate(Transform &Enemy, Transform &Chaser);


	void update(SpaceshipLocomotion &loco);
};