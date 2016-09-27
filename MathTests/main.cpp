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

	// Equivalence
	assert((vec2{ 0,0 } == vec2{ 0, 0 }));
	assert((vec2{ 1,0 } == vec2{ 1,0 }));

	// Addition
	assert((vec2{ 1,1 } + vec2{ -1,0 } == vec2{ 0,1 }));

	// Assignment Addition
	vec2 var = {4,0};
	var += vec2{-3,1};
	assert((var == vec2{1,1}));

	// Normalization and Magnitude
	vec2 N = normal(vec2{1,1});
	assert(N.x == N.y);

	// 1/3 = .33333333
// Any irrational or repeating
// decimal number is not representable.
// if the decimal can't fit in 7 places
// we get something called floating point
// error.

	// float == float
	// check to see if vals are
	// ALMOST the same.

	assert(magnitude(N) == 1);
	assert(normal(N) == N);
	assert((normal(vec2{ 0,1 }) == vec2{ 0,1 }));

	assert(fequals(1, .9999999f));
	return 0;
}

