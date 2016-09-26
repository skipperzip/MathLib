#include <cassert>
#include <cstdio>
#include "Test.h"


int main()
{
	printf("Testing doNothing\n");
	assert(doNothing( 0) == 5);
	assert(doNothing(-1) == 4);
	assert(doNothing( 1) == 8);

	assert(test_quad( 0) == -7);
	assert(test_quad(-1) == -8);
	assert(test_quad( 1) == -4);

	// Testing Quadratic Function...
	assert(quad(1,  0, 0).roots == 1);
	assert(quad(1, -2, 0).roots == 2);
	assert(quad(1,  0, 4).roots == 0);

	assert(quad(1, -2, 0).left_root  == 0);
	assert(quad(1, -2, 0).right_root == 2);
	assert(quad(1, 0, 0).left_root == quad(1, 0, 0).right_root);

	// Testing Linear Interpolation
	assert(lerp(0,  1,  0)  ==  0);
	assert(lerp(0,  1,  1)  ==  1);
	assert(lerp(0,  1, -1)  == -1);
	assert(lerp(1, -1, .5f) ==  0);
	
	return 0;
}

