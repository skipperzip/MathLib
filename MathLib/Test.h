#pragma once

int doNothing(int x);

// Problem a:
float test_quad(float x);

//Problem b:

// Note: Create structures whenever you feel they'll help!
struct quad_results
{
	float left_root, right_root;
	int roots; //0, 1, 2
};

quad_results quad(float a, float b, float c);


// problem b.
float ilerp(float start, float end, float t);

// problem c.
struct Point { float x, y; };
float distance(const Point &P1, const Point &P2);

// problem d.
struct Point3D { float x, y, z; };
float inner(const Point3D &P1, const Point3D &P2);

struct Plane { Point3D abc; float d; };
float point_plane_distance(const Plane &pl, const Point3D &pt);

Point3D bezier(float t, const Point3D &p1, const Point3D &p2,
						const Point3D &p3, const Point3D &p4);

// problem e.
// Point-Plane Distance....

// problem f.
// Bezier Curve....