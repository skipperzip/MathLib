#include "SpaceshipRenderer.h"
#include "sfwdraw.h"
#include "shapes.h"
#include "shapedraw.h"

SpaceshipRenderer::SpaceshipRenderer()
{
	color = MAGENTA;
}

void SpaceshipRenderer::draw(const mat3 & T, const Transform & ship)
{
	mat3 glob = T * ship.getGlobalTransform();

	// if your ship flies in the Right direction
	// then orient your ship accordingly

	vec3 F = glob * vec3{  0, 2, 1 };
	vec3 L = glob * vec3{ -1,-1, 1 };
	vec3 R = glob * vec3{  1,-1, 1 };
	vec3 B = glob * vec3{  0, -2, 1 };
	
	sfw::drawLine(L.x, L.y, F.x, F.y, color);
	sfw::drawLine(F.x, F.y, R.x, R.y, color);
	sfw::drawLine(R.x, R.y, B.x, B.y, color);
	sfw::drawLine(B.x, B.y, L.x, L.y, color);


	vec3 F1 = glob * vec3{  -1,  -2,  1 };
	vec3 L1 = glob * vec3{ -1, 2,  1 };
	vec3 R1 = glob * vec3{  1, -2,  1 };
	vec3 B1 = glob * vec3{  1, 2,  1 }; 

	sfw::drawLine(L1.x, L1.y, F1.x, F1.y, 0x888888FF);
	sfw::drawLine(F1.x, F1.y, R1.x, R1.y, 0x888888FF);
	sfw::drawLine(R1.x, R1.y, B1.x, B1.y, 0x888888FF);
	sfw::drawLine(B1.x, B1.y, L1.x, L1.y, 0x888888FF);
}

