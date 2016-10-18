#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "SpaceshipLocomotion.h"
#include "SpaceshipController.h"

#include "PlanetaryMotor.h"

void main()
{
	float SCREEN_WIDTH = 1200, SCREEN_HEIGHT = 1200;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	float steps = 100;

	vec2 start = { 200, 300 },
		end = { 900, 800 },
		mid = { 0, 1100}; 


	Transform playerTransform(200, 200);
	Transform ST1(100, 0);
	Transform ST2(100, 0);
	Transform ST3(100, 0);
	Transform ST4(100, 0);

	ST1.m_parent = &playerTransform;
	ST2.m_parent = &ST1;
	ST3.m_parent = &ST2;
	ST4.m_parent = &ST3;
	

	Rigidbody playerRigidbody;
	SpaceshipController playerCtrl;
	SpaceshipLocomotion playerLoco;

	Transform sunTransform;
	sunTransform.m_position = vec2{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	Rigidbody sunRbody;
	PlanetaryMotor sunMotor;
	sunMotor.m_rotationSpeed = 20;

	Transform arturoPlanetTransform;
	arturoPlanetTransform.m_position = vec2{ 100, 0 };
	arturoPlanetTransform.m_parent = &sunTransform;

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		// Wrap the player's position within the screen bounds
		if (playerTransform.m_position.x > SCREEN_WIDTH)
			playerTransform.m_position.x = 0.0f;
		else if (playerTransform.m_position.x < 0.0f)
			playerTransform.m_position.x = SCREEN_WIDTH;

		if (playerTransform.m_position.y > SCREEN_HEIGHT)
			playerTransform.m_position.y = 0.0f;
		else if (playerTransform.m_position.y < 0.0f)
			playerTransform.m_position.y = SCREEN_HEIGHT;

		//// Apply rigidbody forces
		//playerCtrl.update(playerLoco);
		//playerLoco.update(playerTransform, playerRigidbody);
		//playerRigidbody.integrate(playerTransform, deltaTime);
		//
		//// Draw the player
		//playerTransform.debugDraw();
		//playerRigidbody.debugDraw(playerTransform);

		//ST1.debugDraw();
		//ST2.debugDraw();
		//ST3.debugDraw();
		//ST4.debugDraw();

		
		sunMotor.update(sunRbody);
		sunRbody.integrate(sunTransform, deltaTime);
		sunTransform.debugDraw();

		arturoPlanetTransform.debugDraw();
	}
	sfw::termContext();
}