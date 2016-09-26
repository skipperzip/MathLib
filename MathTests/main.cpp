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
	
	// Testing Distance formula
	assert(distance({ 0, 0}, { 0,0 }) == 0);
	assert(distance({ 0, 0}, { 5,0 }) == 5);
	assert(distance({ 0,-5}, { 0,0 }) == 5);
	assert(distance({ 3,0 }, { 0,4 }) == 5);

	// Inner Product
	assert(inner({ 1,1,0 }, {-1,1,0 }) == 0);
	assert(inner({ 1,1,1 }, { 1,1,1 }) == 3);

	// Point-Plane Distance
	assert(point_plane_distance({ 0,0,1,0 }, { 0,0,0 }) == 0);
	assert(point_plane_distance({ 0,0,1,0 }, { 0,0,1 }) == 1);

	// Bezier
	assert(bezier(  0,  { 0,0,0 }, { 1,0,0 }, { 2,0,0 }, { 3,0,0 }).x == 0);
	assert(bezier(  1,  { 0,0,0 }, { 1,0,0 }, { 2,0,0 }, { 3,0,0 }).x == 3);
	assert(bezier(0.5f, { 0,0,0 }, { 1,0,0 }, { 2,0,0 }, { 3,0,0 }).x == 1.5);

	return 0;
}

