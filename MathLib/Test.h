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
float lerp(float start, float end, float t);

// problem c.
struct Point { float x, y; };
float distance(Point P1, Point P2);
float distance(float x1, float y1, float x2, float y2);

// problem d.
struct Point3D { float x, y, z; };
float inner(Point3D P1, Point3D P2);
float inner(float x1, float y1, float z1,
				float x2, float y2, float z2);

// problem e.
// Point-Plane Distance....

// problem f.
// Bezier Curve....