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

// (-b +/- sqrt(b*b - 4*a*c))/(2*a)
quad_results quad(float a, float b, float c)
{
	quad_results retval;
	float d = b*b - 4*a*c;
	if      (d  < 0) retval.roots = 0;
	else if (d  > 0) retval.roots = 2;
	else if (d == 0) retval.roots = 1;

	retval.left_root  = (-b - sqrt(d)) / (2 * a);
	retval.right_root = (-b + sqrt(d)) / (2 * a);

	return retval;
}

//int quad(float a, float b, float c, float &out_left, float &out_right)
//{
//	quad_results retval;
//	int out_roots;
//	float d = b*b - 4 * a*c;
//	if		(d  < 0) out_roots = 0;
//	else if (d  > 0) out_roots = 2;
//	else if (d == 0) out_roots = 1;
//
//	out_left  = (-b - sqrt(d)) / (2 * a);
//	out_right = (-b + sqrt(d)) / (2 * a);
// return out_roots;
//}