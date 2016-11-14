#include "shapes.h"
#include <cmath>
#include "flops.h"

Circle operator*(const mat3 & T, const Circle & C)
{
	Circle retval;
	
	retval.pos = (T*vec3{C.pos.x, C.pos.y, 1}).xy;


	float mY = magnitude(T * vec3{0, C.rad, 0});
	float mX = magnitude(T * vec3{C.rad, 0, 0});

	retval.rad = mX > mY? mX : mY;

	return retval;
}

bool operator==(const Circle & A, const Circle & B)
{
	return A.pos == B.pos && fequals(A.rad, B.rad);
}



vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}


/*
	STUB for AABB Transformation

	min : pos - he
	max : pos + he

	pos : (max + min) / 2
	he  : (max - min) / 2
*/
AABB operator*(const mat3 & T, const AABB & box)
{	
	AABB retval = box;	
	vec3 tP[4];

	// First we want to transform the points
	tP[0] = T * vec3{ box.min().x, box.min().y, 1 };
	tP[1] = T * vec3{ box.max().x, box.max().y, 1 };
	tP[2] = T * vec3{ box.max().x, box.min().y, 1 };
	tP[3] = T * vec3{ box.min().x, box.max().y, 1 };

	// find the minimum and maximum extents
	vec2 minv = tP[0].xy;
	vec2 maxv = tP[0].xy;
	
	for (int i = 1; i < 4; ++i)
	{
		minv = min(minv, tP[i].xy);
		maxv = max(maxv, tP[i].xy);
	}

	// evaluate the position and dimensions
	retval.pos = (minv + maxv) / 2;
	retval.he  = (maxv - minv) / 2;
	return retval;
}

/*
[rs rs tx][x]
[rs rs ty][y] = rs*x + rs*y + tx*0
[ 0  0  1][0]
*/
Plane operator*(const mat3 & T, const Plane & P)
{
	Plane retval;
	retval.pos = 
		(T * vec3{ P.pos.x, P.pos.y, 1 }).xy;
		
	retval.dir =
		normal(T * vec3{ P.dir.x, P.dir.y, 0 }).xy;

	return retval;
}


bool operator==(const Plane & A, const Plane & B)
{
	return A.pos == B.pos && A.dir == B.dir;
}

Hull operator*(const mat3 & T, const Hull & H)
{
	Hull retval;
	retval.size = H.size;
	for (int i = 0; i < H.size; ++i)
	{
		// positions need a 1 in the z
		retval.vertices[i] = (T * vec3{ H.vertices[i].x, H.vertices[i].y, 1 }).xy;

		// directions need a 0 in the z
		retval.normals[i]  = normal((T * vec3{ H.normals[i].x, H.normals[i].y, 0 }).xy);
	}
	return retval;
}

float Hull::min(const vec2 & axis) const
{
	float amin = INFINITY;
	for (int i = 0; i < size; ++i)
		amin = fminf(dot(axis, vertices[i]), amin);
	return amin;
}

float Hull::max(const vec2 & axis) const
{
	float amax = -INFINITY;
	for (int i = 0; i < size; ++i)
		amax = fmaxf(dot(axis, vertices[i]), amax);
	return amax;
}

Hull::Hull(const vec2 *a_vertices, unsigned a_size)
{
	size = a_size;
	
	for (int i = 0; i < size && i < 16; ++i)
	{
		vertices[i] = a_vertices[i];
		normals[i] = -perp(normal(a_vertices[(i+1)%size]
								- a_vertices[i]));
	}
}

Hull::Hull() { size = 0; }

// 0, 1, 2, 3

// 0--1
// 1--2
// 2--3
// 3--0