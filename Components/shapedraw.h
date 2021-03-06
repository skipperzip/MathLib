#pragma once
#include "shapes.h"


void drawCircle(const Circle &c, unsigned color);

//draw four lines where the
//box is!
void drawAABB(const AABB &B, unsigned color);


void drawPlane(const Plane &P, unsigned color);

void drawHull(const Hull &H, unsigned color);