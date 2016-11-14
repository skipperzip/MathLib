#include "shapedraw.h"
#include "sfwdraw.h"

void drawCircle(const Circle & C, unsigned color)
{
	sfw::drawCircle(C.pos.x, C.pos.y, C.rad, 12U, color);
}

void drawAABB(const AABB &box, unsigned color)
{
	vec2 A = vec2{ box.min().x, box.max().y };
	vec2 B = vec2{ box.max().x, box.max().y };
	vec2 C = vec2{ box.max().x, box.min().y };
	vec2 D = vec2{ box.min().x, box.min().y };

	sfw::drawLine(A.x, A.y, B.x, B.y, color);
	sfw::drawLine(B.x, B.y, C.x, C.y, color);
	sfw::drawLine(C.x, C.y, D.x, D.y, color);
	sfw::drawLine(D.x, D.y, A.x, A.y, color);
}

void drawPlane(const Plane & P, unsigned color)
{
	sfw::drawCircle(P.pos.x, P.pos.y, 12, 12, color);

	sfw::drawLine(P.pos.x, P.pos.y,
		P.pos.x + P.dir.x * 10, P.pos.y + P.dir.y * 10, color);

	vec2 left = perp(P.dir);
	vec2 right = -perp(P.dir);

	sfw::drawLine(P.pos.x, P.pos.y,
		P.pos.x + left.x * 120, P.pos.y + left.y * 120, color);

	sfw::drawLine(P.pos.x, P.pos.y,
		P.pos.x + right.x * 120, P.pos.y + right.y * 120, color);
}


void drawHull(const Hull &H, unsigned color)
{
	// loop through each pair of neighboring vertices
	// and draw a line between them.
	
	// Loop is setup the same way as the Hull constructor
	for (int i = 0; i < H.size && i < 16; ++i)
	{	
		sfw::drawLine(H.vertices[i].x, H.vertices[i].y,
				      H.vertices[(i + 1) % H.size].x,
					  H.vertices[(i + 1) % H.size].y, color);
	}	
}