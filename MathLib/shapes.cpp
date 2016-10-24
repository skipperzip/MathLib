#include "shapes.h"

Circle operator*(const mat3 & T, const Circle & C)
{
	Circle retval;
	
	// How do you transform position?
	retval.pos = (T*vec3{C.pos.x, C.pos.y, 1}).xy;

	// How do you transform the radius?
		// A circle's representation of scale
	float mX = magnitude(T * vec3{0, C.rad, 0});
	float mY = magnitude(T * vec3{C.rad, 0, 0});

	retval.rad = mX > mY? mX : mY;

	return retval;
}
