#include <cassert>
#include <cstdio>
#include "Test.h"


int main()
{
	// Testing Tests!
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

	assert(quad(1, 0, 0).left_root
						== quad(1, 0, 0).right_root);
	return 0;
}

