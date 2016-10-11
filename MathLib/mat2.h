#pragma once
#include "vec2.h"

/**
[ column 1 ] [ column 2 ] Layout
[...0][...1] [...2][...3] array
[ 0 0][ 0 1] [ 1 0][ 1 1] 2d array
[ 0  {x, y}] [ 1  {x, y}] vectors
**/

union mat2
{
	float m[4];      // single dimensional array
	float mm[2][2];  // multidimensional array
	vec2  c[2];      // column vectors

	vec2  operator[](unsigned idx) const;
	vec2 &operator[](unsigned idx);
};

mat2 mat2Identity();
mat2 transpose(const mat2 &A);

bool operator==(const mat2 &A, const mat2 &B);
bool operator!=(const mat2 &A, const mat2 &B);

mat2 operator+(const mat2 &A, const mat2 &B);
mat2 operator-(const mat2 &A, const mat2 &B);
mat2 operator-(const mat2 &A);

mat2 operator*(const mat2 &A, float s);
mat2 operator*(float s, const mat2 &A);
mat2 operator*(const mat2 &A, const mat2 &B);
vec2 operator*(const mat2 &A, const vec2 &V);

float determinant(const mat2 &A);
mat2 inverse(const mat2 &A);