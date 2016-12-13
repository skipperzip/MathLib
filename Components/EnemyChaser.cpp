#include "EnemyChaser.h"
#include <iostream>
#include "sfwdraw.h"
#include "flops.h"



void EnemyChaser::locate(Transform &Enemy, Transform &Chaser)
{
	RIGHT = 0;
	LEFT = 0;
	FORWARD = 1;
	STOP = 0;
	vec2 FindVec(Chaser.m_position.x - Enemy.m_position.x, Chaser.m_position.y - Enemy.m_position.y);
	float angleTurn = angleBetween(FindVec, Chaser.getDirection());
	angleTurn = rad2deg(angleTurn);

	if (angleTurn <= 85 && angleTurn > 0) LEFT = 1;
	if (angleTurn >= 100 && angleTurn < 180) RIGHT = 1;

	if (angleTurn < 85 && angleTurn > 95)

	{
		STOP = 1;
		FORWARD = 0;
	}


}
void EnemyChaser::update(SpaceshipLocomotion & loco)
{
	float hInput = 0.0f;
	hInput -= RIGHT;
	hInput += LEFT;

	float vInput = 0.0f;
	vInput += FORWARD;
	vInput -= STOP;

	float bInput = STOP;

	loco.doStop(bInput);
	loco.doTurn(hInput);
	loco.doThrust(vInput);
}
