#pragma once

#include "mat3.h"

// Bounding Volumes
	// Simplifications of more complex ideas.
struct Circle
{
	vec2  pos; // offset
	float rad;
};

// Treat the radius as an X-aligned vector and Y-aligned vector,
// multiply them by the matrix, get their magnitude.
// The largest magnitude will be the new radius.

// Should transform both position and radius by the matrix.
Circle operator*(const mat3 &T, const Circle &C);

//
// Are the positions and radii equals
	// A.pos == B.pos && fequals(A.rad, B.rad)
bool  operator==(const Circle &A, const Circle &B);


// Either store a minimum and a maximum
// position and dimension
struct AABB
{
	vec2 pos,
		  he; // half-extents
				// x = half-width
			    // y = half-height

	vec2 min() const; // bottom left corner
	vec2 max() const; // top right corner
};

AABB  operator*(const mat3 &T, const AABB  &A);
bool  operator==(const AABB &A, const AABB &B);


struct Plane  { };
struct Ray    { };
struct Hull   { };



Plane  operator*(const mat3 &T, const Plane  &P);
Ray    operator*(const mat3 &T, const Ray    &R);
Hull   operator*(const mat3 &T, const Hull   &H);
