#include "EnemyDriver.h"
#include <iostream>
#include "sfwdraw.h"
#include "flops.h"



void EnemyDriver::locate(Transform &Player, Transform &Enemy)
{
	RIGHT = 0;
	LEFT = 0;
	FORWARD = 1;
	STOP = 0;
	float direction = Enemy.m_facing;
	direction = rad2deg(direction);
	vec2 FindVec(Enemy.m_position.x - Player.m_position.x, Enemy.m_position.y - Player.m_position.y);
	float distance(sqrt (((Enemy.m_position.x - Player.m_position.x) * (Enemy.m_position.x - Player.m_position.x)) + ((Enemy.m_position.y - Player.m_position.y) + (Enemy.m_position.y - Player.m_position.y))) );
	float angleTurn = angleBetween(FindVec, Enemy.getDirection());
	angleTurn = rad2deg(angleTurn);

	if (angleTurn <= 90 && angleTurn > 0) LEFT = 1;
	if (angleTurn >= 90 && angleTurn < 180) RIGHT = 1;

	if (angleTurn < 85 && angleTurn > 95) 

	{
		STOP = 1;
		FORWARD = 0;
		LEFT = 0;
		RIGHT = 0;
	}

	

}




void EnemyDriver::update(SpaceshipLocomotion & loco)
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
