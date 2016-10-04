#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"

void main()
{
	float W = 1200, H = 1200;
	sfw::initContext(W, H);
	float steps = 100;

	vec2 start = { 200, 300 },
		end = { 900, 800 },
		mid = { 0, 1100};

	while (sfw::stepContext())
	{
		sfw::drawCircle(start.x,start.y,12);
		sfw::drawCircle(mid.x, mid.y, 12);
		sfw::drawCircle(end.x, end.y, 12);

		if (sfw::getKey('S')) mid.y -= sfw::getDeltaTime() * 100;
		if (sfw::getKey('W')) mid.y += sfw::getDeltaTime() * 100;
		if (sfw::getKey('A')) mid.x -= sfw::getDeltaTime() * 100;
		if (sfw::getKey('D')) mid.x += sfw::getDeltaTime() * 100;


		// i is the number lines we draw.
		for (int i = 0; i < steps; ++i)
		{
			float t1 = i / steps;
			float t2 = (i + 1) / steps;

			vec2 v1 = quadBezier(start, mid, end, t1);
			vec2 v2 = quadBezier(start, mid, end, t2);

			sfw::drawLine(v1.x,v1.y, v2.x,v2.y);
		}
	}
	sfw::termContext();
}