#include <cassert>
#include <cstdio>
#include "Test.h"

#include "vec2.h"
#include "vec3.h"
#include "flops.h"


int main()
{
	assert(fequals(0, 0.000001));
	//////////////////////////////////////
	// Vector Tests
	
	// if the vector only extends in one axis, then it's
	// magnitude will be the extent within that axis!
	assert(fequals(magnitude(vec2{5,0}),5));

	// magnitude of the normal should be 1
	vec2 N = normal(vec2{ 1,1 });
	assert(fequals(magnitude(N), 1));

	// Dot product with an AXIS should give us the coordinate value
	// along that axis.
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4));

	// Anglebetween the X-Axis should give us the angle of the vector.
	assert(fequals(angleBetween(vec2{ 0,1 }, vec2{ 1,0 }), deg2rad(90)));	
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), deg2rad(45)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), angle(vec2{ 1,1 })));

	// Angle of 0 should be the X-Axis
	assert((fromAngle(0) == vec2{1,0}));
	assert((fromAngle(deg2rad(90)) == vec2{ 0,1 }));
	assert((fromAngle(deg2rad(45))) == normal(vec2{1,1}));

	 //Testing cross product
		 //Ensure that the Z-axis results from
		 //crossing the X-axis and Y-Axis
//	assert((cross(vec3{ 1,0,0 }, vec3{ 0,1,0 }) == vec3{0,0,1}));

	// reversing the operands will give me the back-facing vector.
//	assert( (cross(vec3{ 0,1,0 }, vec3{ 1,0,0 }) == vec3{ 0,0,-1 }) );


	assert(fequals(lerp(.23, 124, 0), .23));
	assert(fequals(lerp(.23, 124, 1), 124));

	assert(fequals(quadBezier(15, 40, 21, 0), 15));
	assert(fequals(quadBezier(15, 40, 21, 1), 21));

	assert(fequals(hermiteSpline(15, 40, 21, 10, 0), 15));
	assert(fequals(hermiteSpline(15, 40, 21, 10, 1), 21));

	assert(fequals(cardinalSpline(15, 40, 21, .2f, 0), 15));
	assert(fequals(cardinalSpline(15, 40, 21, .1f, 1), 21));

	assert(fequals(catRomSpline(15, 40, 21, 0), 15));
	assert(fequals(catRomSpline(15, 40, 21, 1), 21));
	
	return 0;
}

