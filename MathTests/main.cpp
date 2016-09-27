#include <cassert>
#include <cstdio>
#include "Test.h"
#include "vec2.h"
#include "vec3.h"


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
	assert(magnitude(N) == 1);

	return 0;
}

