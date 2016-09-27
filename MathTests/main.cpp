#include <cassert>
#include <cstdio>
#include "Test.h"

#include "vec2.h"
#include "vec3.h"
#include "flops.h"


int main()
{
	//////////////////////////////////////
	// Vector Tests

	vec2 N = normal(vec2{ 1,1 });
	assert(fequals(magnitude(N), 1));

	// Dot product with an AXIS should give us the coordinate value
	// along that axis.
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4));

	// Anglebetween the X-Axis should give us the angle of the vector.
	assert(fequals(angleBetween(vec2{ 0,1 }, vec2{ 0,1 }),
												deg2rad(90)));	
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }),
												deg2rad(45)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }),
												angle(vec2{ 1,1 })));

	// Angle of 0 should be the X-Axis
	assert((fromAngle(0) == vec2{1,0}));
	assert((fromAngle(deg2rad(90)) == vec2{ 0,1 }));

	// Testing cross product
		// Ensure that the Z-axis results from
		// crossing the X-axis and Y-Axis
	assert((cross(vec3{ 1,0,0 }, vec3{ 0,1,0 })
									== vec3{0,0,1}));

	// reversing the operands will give me the back-facing vector.
	assert((cross(vec3{ 0,1,0 }, vec3{ 1,0,0 })
									== vec3{ 0,0,-1 }));
	return 0;
}

