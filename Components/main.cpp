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

void main()
{
	float SCREEN_WIDTH = 1200, SCREEN_HEIGHT = 1200;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);


	Transform playerTransform(200, 200);
	playerTransform.m_scale = vec2{ 10, 10 };

	Rigidbody playerRigidbody;
	SpaceshipController playerCtrl;
	SpaceshipLocomotion playerLoco;
	SpaceshipRenderer playerRender;


	//////////////////////
	//// Setup the Collider!
	vec2 hullVrts[] = { { 0, 3 },
						{-2,-3 },
					    { 2,-3 } };	
	Collider playerCollider(hullVrts, 3);


	Transform cameraTransform;

	

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		// Logic
		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);

		// Camera setup
		cameraTransform.m_position = playerTransform.getGlobalPosition();		
		mat3 proj = translate(600, 600) * scale(2, 2);
		mat3 view = inverse(cameraTransform.getGlobalTransform());
		mat3 camera = proj * view;

		// debug drawing stuff
		playerTransform.debugDraw(camera);
		playerRigidbody.debugDraw(camera, playerTransform);
		playerCollider.DebugDraw(camera, playerTransform);
	}
	sfw::termContext();
}

/*
class Player
{
	Transform transform;
	Rigidbody rigidbody;
	Collider  collider;
};
*/