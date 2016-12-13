#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "SpaceshipLocomotion.h"
#include "SpaceshipController.h"
#include "SpaceshipRenderer.h"
#include "shapedraw.h"
#include "shapes.h"
#include "collider.h"
#include "EnemyDriver.h"
#include "EnemyChaser.h"
#include <cstdio>
int input = 1;
void main()
{

	float SCREEN_WIDTH = 1200, SCREEN_HEIGHT = 1200;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);


	Transform playerTransform(200, 200);
	playerTransform.m_scale = vec2{ 10, 10 };
	//Player
	Rigidbody playerRigidbody;
	SpaceshipController playerCtrl;
	SpaceshipLocomotion playerLoco;
	SpaceshipRenderer playerRender;
	// Setup the Collider!
	vec2 hullVrts[] ={ 
	{ 0, 3 },
	{ -2,-3 },
	{ 2,-3 } };
	Collider playerCollider(hullVrts, 3);
	//PlayerEnd?


	//EnemyPlayer
	Transform halTransform(0, 0);
	halTransform.m_scale = vec2{ 8,8 };
	Collider halCollider(hullVrts, 3);
	Rigidbody halRigidbody;
	EnemyDriver Hal;
	SpaceshipLocomotion Haloco;
	//EnemyPlayerEnd

	Transform JeffreyTransform(-200, -200);
	JeffreyTransform.m_scale = vec2{ 8,8 };
	Collider JeffreyCollider(hullVrts, 3);
	Rigidbody JeffreyRigidbody;
	EnemyChaser Jeffrey;
	SpaceshipLocomotion Jeffreyloco;
	//EnemyChaserEnd

	Transform cameraTransform;
	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		// Logic
		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);

		Hal.locate(playerTransform, halTransform);
		Haloco.update(halTransform, halRigidbody);
		Hal.update(Haloco);
		halRigidbody.integrate(halTransform, deltaTime); 

		Jeffrey.locate(halTransform, JeffreyTransform);
		Jeffreyloco.update(JeffreyTransform, JeffreyRigidbody);
		Jeffrey.update(Jeffreyloco);
		JeffreyRigidbody.integrate(JeffreyTransform, deltaTime);


		DynamicResolution(playerTransform, playerRigidbody, playerCollider,
			halTransform, halRigidbody, halCollider);

		// Camera setup
		if (sfw::getKey('1'))
		{
			input = 1;
		}
		if (sfw::getKey('2'))
		{
			input = 2;
		}
		if (sfw::getKey('3'))
		{
			input = 3;
		}

		if (input == 1)  cameraTransform.m_position = playerTransform.getGlobalPosition();
		if (input == 2)  cameraTransform.m_position = halTransform.getGlobalPosition();
		if (input == 3)	 cameraTransform.m_position = JeffreyTransform.getGlobalPosition();
	
		mat3 proj = translate(600, 600) * scale(2, 2);
		mat3 view = inverse(cameraTransform.getGlobalTransform());
		mat3 camera = proj * view;

		// debug drawing stuff
		JeffreyTransform.debugDraw(camera);
		JeffreyCollider.DebugDraw(camera, JeffreyTransform);
		JeffreyRigidbody.debugDraw(camera, JeffreyTransform);

		halTransform.debugDraw(camera);
		halCollider.DebugDraw(camera, halTransform);
		halRigidbody.debugDraw(camera, halTransform);

		playerTransform.debugDraw(camera);
		playerRigidbody.debugDraw(camera, playerTransform);
		playerCollider.DebugDraw(camera, playerTransform);
	}
	sfw::termContext();
}