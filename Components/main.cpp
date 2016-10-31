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


void main()
{
	float SCREEN_WIDTH = 1200, SCREEN_HEIGHT = 1200;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);

	
	Transform playerTransform(200, 200);
	playerTransform.m_scale = vec2{ 20, 10 };
	
	Rigidbody playerRigidbody;
	SpaceshipController playerCtrl;
	SpaceshipLocomotion playerLoco;
	SpaceshipRenderer playerRender;

	Transform cameraTransform;

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);


		cameraTransform.m_position
			= lerp(cameraTransform.m_position,
				playerTransform.getGlobalPosition(),
				sfw::getDeltaTime() * 10);


		//////////////////////////////////////////////////////////////
		////////////// Rendering Stuff

		mat3 proj = translate(600, 600) * scale(2, 2);
		mat3 view = inverse(cameraTransform.getGlobalTransform());
		mat3 camera = proj * view;


		playerRender.draw(camera, playerTransform);


		///////////////////////
		///// Debug Drawing
		cameraTransform.debugDraw(camera);

		playerTransform.debugDraw(camera);
		playerRigidbody.debugDraw(camera, playerTransform);



		//////////////////////////
		///// Test Drawing
		drawAABB(camera
			* playerTransform.getGlobalTransform()
			* AABB { 0, 0, 1, 2 }, RED);

		drawPlane(camera
			* playerTransform.getGlobalTransform()
			* Plane { 0, 0, 0, 1 }, WHITE);
	}
	sfw::termContext();
}