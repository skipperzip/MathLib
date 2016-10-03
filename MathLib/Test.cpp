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

float ilerp(float start, float end, float t)
{
	return start + t * (end - start);
}


float distance(const Point &P1, const Point &P2)
{
	return sqrt((P1.x - P2.x)*(P1.x - P2.x) + (P1.y - P2.y)*(P1.y - P2.y));
}

float inner(const Point3D &P1, const Point3D &P2)
{
	return P1.x*P2.x + P1.y*P2.y + P1.z*P2.z;
}

float point_plane_distance(const Plane &pl, const Point3D &pt)
{
	return (inner(pl.abc, pt) + pl.d) /
			sqrt(pl.abc.x * pl.abc.x
			   + pl.abc.y * pl.abc.y 
			   + pl.abc.z * pl.abc.z);
}

Point3D bezier(float t, const Point3D &p1, const Point3D &p2,
						const Point3D &p3, const Point3D &p4)
{
	float ot = 1 - t;
	Point3D r;
	r.x = ot*ot*ot*p1.x + 3 * ot*ot*t*p2.x + 3 * ot*t*t*p3.x + t*t*t*p4.x;
	r.y = ot*ot*ot*p1.y + 3 * ot*ot*t*p2.y + 3 * ot*t*t*p3.y + t*t*t*p4.y;
	r.z = ot*ot*ot*p1.z + 3 * ot*ot*t*p2.z + 3 * ot*t*t*p3.z + t*t*t*p4.z;
	// A^3 + 3A^2B + 3AB^2 + B^3
	return r;
}
