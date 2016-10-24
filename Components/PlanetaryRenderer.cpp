#include "PlanetaryRenderer.h"

#include "sfwdraw.h"

PlanetaryRenderer::PlanetaryRenderer(unsigned a_color, float a_size)
{
	color = a_color;
	size = a_size;
}

void PlanetaryRenderer::draw(const mat3& T, Transform & planetTrans)
{
	/*
	How do you encode the radius as a vector
	so that you can transform it using a matrix?

	What if scaling is non-uniform?
	*/

	mat3 glob = T * planetTrans.getGlobalTransform();

	//right (x direction), up (y direction), position
	// magnitude of the radius transformed as a vector
	float xRad = magnitude(glob * vec3{ size,  0, 0 });
	float yRad = magnitude(glob * vec3{  0, size, 0 });

	vec2 pos = glob[2].xy;

	float rad = xRad > yRad? xRad : yRad;

	sfw::drawCircle(pos.x, pos.y, rad, 12U, color);
}
