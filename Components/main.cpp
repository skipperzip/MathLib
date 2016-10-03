#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"

void main()
{
	float W = 1200, H = 1200;
	sfw::initContext(W, H);
	float steps = 100;
	while (sfw::stepContext())
	{
		// i is the number lines we draw.
		for (int i = 0; i < steps; ++i)
		{
			float x1 = i / steps;// 0-1 range.
			// i+1 is the next point!
			float x2 = (i + 1) / steps;
			// call the function for both points.
			float y1 = quadBezier(.5f, 0, 1, x1);
			float y2 = quadBezier(.5f, 0, 1, x2);

			x1 *= W;
			y1 *= H;
			x2 *= W;
			y2 *= H;

			sfw::drawLine(x1,y1, x2,y2);
		}
	}
	sfw::termContext();
}