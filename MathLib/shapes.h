#pragma once

#include "mat3.h"


struct Circle
{
	vec2  pos;
	float rad;
};
Circle operator*(const mat3 &T, const Circle &C);

//

bool  operator==(const Circle &A, const Circle &B);



struct AABB
{
	vec2 pos,
		  he; 

	vec2 min() const; 
	vec2 max() const;
};

AABB  operator*(const mat3 &T, const AABB  &A);
bool  operator==(const AABB &A, const AABB &B);


struct Plane 
{
	vec2 pos, dir;
};

Plane  operator*(const mat3 &T, const Plane  &P);
bool  operator==(const Plane &A, const Plane &B);




struct Ray    { };
Ray    operator*(const mat3 &T, const Ray    &R);




/*
	We may want to ensure that it is convex.
	We want to be able to calculate surface normals.
*/

struct Hull
{
	vec2 vertices[16];
	vec2 normals[16];
	unsigned int size;

	// assume a CW winding order.
		// loop through every neighboring pair of vertices
			// evaluate the normal of each pair (store it).
	Hull(const vec2 *a_vertices, unsigned a_size);

	Hull(); // empty hull constructor
};

// If the convex hulls are the same size,
	// Loop through and compare their normals and vertices
bool   operator==(const Hull &A, const Hull &B);

// Multiply each vertex and normal by the matrix
Hull   operator* (const mat3 &T, const Hull &H);

// loop through each vertex and normal, multiply by matrix:
	// Mat3 * Position  {x, y, 1} (for vertices)
	// Mat3 * Direction {x, y, 0} (for normals)
/*

[1    x]
[  1  y]
[     1]
*/