#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"

void main()
{
	sfw::initContext();
	Transform trans(400, 300, 30,30, 23);


        // Various Syntax for calling constructors
        int j = int(4);
        int k(4);      // works in c-tor
        int l = { 4 };
        int n{ 4 };     // works in c-tor

        Transform tl = Transform(400, 300);
        Transform tn = {400, 300};
        Transform tm(400, 300);
        Transform tq{ 400,300 };

	//trans.position = vec2{400,300};
	trans.facing = deg2rad(45);
	trans.scale = vec2{24,8};
        
        vec2 basis    = { 40,0};
        float ang_vec = 0;

	while (sfw::stepContext())
	{
                ang_vec += sfw::getDeltaTime();
                vec2 incident = fromAngle(ang_vec)*40;                
                float proj = dot(basis, normal(incident));
                
                // Draw the data in diff colors.
                sfw::drawLine(400,300,400+basis.x, 300+basis.y,RED);
                sfw::drawLine(400,300,400+incident.x,300+incident.y, CYAN);
                sfw::drawLine(400, 300, 400+proj, 300, GREEN);
                //sfw::drawLine();

                //trans.debugDraw();
	}

	sfw::termContext();
}