#pragma once
#include "vec2.h"

/**
For mat2 and mat3!!!!
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
mat2 operator*(const mat2 &A, const vec2 &V);

float determinant(const mat2 &A);
mat2 inverse(const mat2 &A);