#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "SpaceshipLocomotion.h"
#include "SpaceshipController.h"

#include "PlanetaryMotor.h"
#include "PlanetaryRenderer.h"

void main()
{
	float SCREEN_WIDTH = 1200, SCREEN_HEIGHT = 1200;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	float steps = 100;

	vec2 start = { 200, 300 },
		end = { 900, 800 },
		mid = { 0, 1100}; 



	//Transform ST1(100, 0);
	//Transform ST2(100, 0);
	//Transform ST3(100, 0);
	//Transform ST4(100, 0);

	//ST1.m_parent = &playerTransform;
	//ST2.m_parent = &ST1;
	//ST3.m_parent = &ST2;
	//ST4.m_parent = &ST3;
	
	Transform playerTransform(200, 200);
	Rigidbody playerRigidbody;
	SpaceshipController playerCtrl;
	SpaceshipLocomotion playerLoco;

	// Sun
	Transform sunTransform;
	sunTransform.m_position = vec2{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	Rigidbody sunRbody;
	PlanetaryMotor sunMotor;
	sunMotor.m_rotationSpeed = 5;
	PlanetaryRenderer sunRenderer(YELLOW, 100);

	// Planet
	Transform plan1;
	plan1.m_position = vec2{ 150, 0 };
	plan1.m_parent = &sunTransform;
	Rigidbody plan1RB;
	PlanetaryMotor plan1motor;
	plan1motor.m_rotationSpeed = 7;
	PlanetaryRenderer plan1renderer(GREEN, 20);

	// Moon
	Transform moon1;
	moon1.m_position = vec2{ 50, 0 };
	moon1.m_parent = &plan1;
	Rigidbody moon1RB;
	PlanetaryMotor moon1motor;
	moon1motor.m_rotationSpeed = 12;
	PlanetaryRenderer moon1renderer(WHITE, 7);


	Transform cameraTransform;

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		// Apply rigidbody forces
		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);
		
		// Draw the player
		
		// Update Logic
		sunMotor.update(sunRbody);
		plan1motor.update(plan1RB);
		moon1motor.update(moon1RB);

		moon1RB.integrate(moon1, deltaTime);
		plan1RB.integrate(plan1, deltaTime);
		sunRbody.integrate(sunTransform, deltaTime);

		// Drawing
		//sunRenderer.draw(sunTransform);
		//plan1renderer.draw(plan1);
		//moon1renderer.draw(moon1);
		
		cameraTransform.m_position
					= lerp(cameraTransform.m_position,
						   playerTransform.getGlobalPosition(),
						   sfw::getDeltaTime() * 10);
	
		mat3 proj = translate(600, 600) * scale(3, 3);
		mat3 view = inverse(cameraTransform.getGlobalTransform());

		mat3 camera = proj * view;

		playerTransform.debugDraw(camera);
		sunTransform.debugDraw(camera);
		plan1.debugDraw(camera);
		moon1.debugDraw(camera);
		cameraTransform.debugDraw(camera);
	}
	sfw::termContext();
}