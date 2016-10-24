#include "SpaceshipRenderer.h"
#include "sfwdraw.h"

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
	
	sfw::drawLine(L.x, L.y, F.x, F.y, color);
	sfw::drawLine(F.x, F.y, R.x, R.y, color);
	sfw::drawLine(R.x, R.y, L.x, L.y, color);
}
