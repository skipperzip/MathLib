#include "Test.h"
#include <cmath> // Access Math Functions
// This is the develop branch!


int doNothing(int x)
{
	return x*x + 2*x + 5;
}

float test_quad(float x)
{
	return x*x + 2*x - 7;
}

quad_results quad(float a, float b, float c)
{
	// The area under a square root
	// is often called a determinant
		// For testing, use perfect squares!

	// IF the det is less than 0,
		// there can't be any roots!
	
	// IF the det IS 0,
		// you'll see that there is 1 root!
}