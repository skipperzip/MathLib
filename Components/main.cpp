#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"
#include "Rigidbody.h"

void main()
{
	float SCREEN_WIDTH = 400, SCREEN_HEIGHT = 400;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	float steps = 100;

	vec2 start = { 200, 300 },
		end = { 900, 800 },
		mid = { 0, 1100}; 

	Transform playerTransform(200,200);
	Rigidbody playerRigidbody;
	playerRigidbody.velocity = vec2{ 0,0 };

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		// Change the rigidbody's velocity according to input
		if (sfw::getKey('W')) playerRigidbody.velocity.y += 10.0f;
		if (sfw::getKey('S')) playerRigidbody.velocity.y -= 10.0f;
		if (sfw::getKey('A')) playerRigidbody.velocity.x -= 10.0f;
		if (sfw::getKey('D')) playerRigidbody.velocity.x += 10.0f;

		// Apply rigidbody forces
		playerRigidbody.integrate(playerTransform, deltaTime);
		
		// Draw the player
		playerTransform.debugDraw();
	}
	sfw::termContext();
}