#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"


void main()
{
	sfw::initContext(800,800);

	while (sfw::stepContext())
	{
		for (int i = 0; i < 100; ++i)
		{
			float x1 = i / 100.f;// 0-1 range.
			float y1 = linearHalf(x1);

			float x2 = (i + 1) / 100.f;			
			float y2 = linearHalf(x2);

			x1 *= 800;
			x2 *= 800;
			y1 *= 800;
			y2 *= 800;

			sfw::drawLine(x1,y1,x2,y2);
		}
	}

	sfw::termContext();
}