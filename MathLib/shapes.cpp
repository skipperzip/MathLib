#include "shapes.h"
#include "flops.h"

Circle operator*(const mat3 & T, const Circle & C)
{
	Circle retval;
	
	retval.pos = (T*vec3{C.pos.x, C.pos.y, 1}).xy;


	float mY = magnitude(T * vec3{0, C.rad, 0});
	float mX = magnitude(T * vec3{C.rad, 0, 0});

	retval.rad = mX > mY? mX : mY;

	return retval;
}

bool operator==(const Circle & A, const Circle & B)
{
	return A.pos == B.pos && fequals(A.rad, B.rad);
}
