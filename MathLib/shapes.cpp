#include "shapes.h"
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














/*
vec2 t[4];

t[0] = (T * vec3{ box.min().x, box.max().y, 1 }).xy;
t[1] = (T * vec3{ box.max().x, box.max().y, 1 }).xy;
t[2] = (T * vec3{ box.max().x, box.min().y, 1 }).xy;
t[3] = (T * vec3{ box.min().x, box.min().y, 1 }).xy;

vec2 min = t[0], max = t[0];

for (int i = 1; i < 4; ++i)
{
	min.x = t[i].x < min.x ? t[i].x : min.x;
	min.y = t[i].y < min.y ? t[i].y : min.y;

	max.x = t[i].x > max.x ? t[i].x : max.x;
	max.y = t[i].y > max.y ? t[i].y : max.y;
}

retval.he = (max - min) / 2;
retval.pos = (max + min) / 2;

*/