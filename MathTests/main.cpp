#include <cassert>
#include <cstdio>

#include <cmath>
#include "vec2.h"
#include "vec3.h"
#include "flops.h"

#include "mat2.h"
#include "mat3.h"

#include "shapes.h"

int main()
{
	assert(fequals(0, 0.000001));
	//////////////////////////////////////
	// Vector Tests

	// if the vector only extends in one axis, then it's
	// magnitude will be the extent within that axis!
	assert(fequals(magnitude(vec2{ 5,0 }), 5));

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
	assert((fromAngle(0) == vec2{ 1,0 }));
	assert((fromAngle(deg2rad(90)) == vec2{ 0,1 }));
	assert((fromAngle(deg2rad(45))) == normal(vec2{ 1,1 }));

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

	/////////////////////////////////////////////////
	/////////////// Matrix Tests
	/* Matrix multiplication--> think of each as variables
		layout the result and perform the dot products of
		rows and columns!
		  b0 b2
		  b1 b3
	a0 a2 r0 r2
	a1 a3 r1 r3

	r0 = a0*b0 + a2*b1
	r1 = a1*b0 + a3*b1
	r2 = a0*b2 + a2*b3
	r3 = a1*b2 + a3*b3
	*/
	mat2 m0 = mat2{ 0,0,0,0 };
	mat2 mI = mat2Identity();
	mat2 t0 = mat2{ 4,3,0,1 };
	vec2 v0 = vec2{ 1,0 };
	assert(m0 == m0);
	assert(mI * 2 == 2 * mI);
	assert((mI * 2 == mat2{ 2,0,0,2 }));
	assert(mI + m0 == mI);
	assert(mI - mI == m0);
	assert(mI*-1 == -mI);

	assert(mI * mI == mI);
	assert(mI * (mat2{ 1,2,3,4 }) == (mat2{ 1,2,3,4 }));

	assert(mI * v0 == v0);
	assert((t0 * v0 == vec2{ 4,0 }));

	assert(transpose(mI) == mI);

	auto fff = determinant(mI);
	mat2 bbb = inverse(mI);
	assert(inverse(mI) == mI);

	bbb = inverse(t0) * t0;
	//assert(inverse(t0) * t0 == mI);

	mat3 t03 = {};
	mat3 mI3 = mat3Identity();


	assert(mI3*inverse(mI3) == mI3);



	vec3 j = { 2,5,1 };

	assert((scale(5, 1) * j == vec3{ 10,5,1 }));

	assert((rotate(deg2rad(90)) * j == vec3{ -5,2,1 }));

	assert((translate(0, 3)*j == vec3{ 2,8,1 }));

	mat3 S = scale(2, 1);
	mat3 T = translate(4, 3);
	mat3 R = rotate(deg2rad(90));

	//mat3 RES = { 0,-1,0, 2,0,0, 4,3,1 };

	//bool r0 = (S*T*R == RES);
	//bool r1 = (S*R*T == RES);
	//bool r2 = (R*S*T == RES);
	//bool r3 = (R*T*S == RES);
	//bool r4 = (T*S*R == RES);
	//bool r5 = (T*R*S == RES);




	vec3 test
		= rotate(deg2rad(-90)) * translate(10, 0) *
		  rotate(deg2rad(45))  * translate(4, 0) *
		  rotate(deg2rad(45))  * translate(-6, 0) *
		  translate(6, 4)      *  vec3 { 0, 0, 1 };

	assert((test == vec3{2*sqrtf(2), -6-2*sqrtf(2) , 1}));




	vec2 WP[] = { {12,-8}, {15,18},{5,8},{-22,-5},
				  {4,-2},{-6,9},{18,88},{-22,-90} };

	mat3 RES = translate(12, -8) * rotate(deg2rad(80)); // setup starting orientation.

	for (int i = 0; i < 8-1; ++i)
	{
		vec2 D = WP[i + 1] - WP[i];

		float current  = atan2f(RES[0].y, RES[0].x);
		float target   = atan2f(D.y, D.x);
		float distance = magnitude(D);

		mat3 R = rotate(target - current);
		mat3 T = translate(distance, 0);

		RES = RES * R * T;
	}




	Circle c = {0, 0, 5};
	

	assert((translate(4, 0) * c == Circle{ 4, 0, 5 }));

	assert((scale( 2, 1) * c == Circle{ 0, 0, 10 }));
	assert((scale( 2, 2) * c == Circle{ 0, 0, 10 }));
	assert((scale( 1, 2) * c == Circle{ 0, 0, 10 }));

	assert((scale(-1, 1) * c == Circle{ 0, 0, 5 }));
	assert((rotate(45) * c == Circle{ 0,0,5 }));
	return 0;
}

