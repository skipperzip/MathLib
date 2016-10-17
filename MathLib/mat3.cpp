#include "mat3.h"

vec3 mat3::operator[](unsigned idx) const
{
	return c[idx];
}

vec3 & mat3::operator[](unsigned idx)
{
	return c[idx];
}



mat3 mat3Identity()
{
	return mat3 {1,0,0, 0,1,0, 0,0,1};
}

/*
	ABC     ADG
	DEF T = BEH
	GHI		CFI
*/
mat3 transpose(const mat3 & A)
{
	mat3 retval;

	for (unsigned i = 0; i < 3; ++i)
		for (unsigned j = 0; j < 3; ++j)
			retval[i][j] = A[j][i];

	return retval;
}

bool operator==(const mat3 & A, const mat3 & B)
{
	bool retval = true;

	for (int i = 0; i < 3; ++i)
			retval = retval && A[i] == B[i];

	return retval;

/*	return A[0] == B[0] &&
		   A[1] == B[1] &&
		   A[2] == B[2];*/	
}

bool operator!=(const mat3 & A, const mat3 & B)
{
	return !(A == B);
}

mat3 operator+(const mat3 & A, const mat3 & B)
{
	mat3 retval;

	for (int i = 0; i < 3; ++i)
		retval[i] = A[i] + B[i];

	return retval;
}

mat3 operator-(const mat3 & A, const mat3 & B)
{
	return A + -B;
}

mat3 operator-(const mat3 & A)
{
	return A*-1;
}

mat3 operator*(const mat3 & A, float s)
{
	mat3 retval;

	for (int i = 0; i < 3; ++i)
		retval[i] = A[i] * s;

	return retval;
}

mat3 operator*(float s, const mat3 & A)
{
	return A*s;
}



mat3 operator*(const mat3 & A, const mat3 & B)
{
	mat3 retval;

	mat3 At = transpose(A);

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			retval[i][j] = dot(At[j], B[i]);
	
	return retval;
}

vec3 operator*(const mat3 & A, const vec3 & V)
{
	vec3 retval;
	mat3 At = transpose(A);

	for (int i = 0; i < 3; ++i)
			retval[i] = dot(At[i], V);

	return retval;
}



float determinant(const mat3 & A)
{
	return dot(A[0], cross(A[1],A[2]));
}


mat3 inverse(const mat3 & A)
{
	mat3 retval;

	retval[0] = cross(A[1], A[2]);
	retval[1] = cross(A[2], A[0]);
	retval[2] = cross(A[0], A[1]);

	return 1 / determinant(A) *
				transpose(retval);
}

mat3 scale(float w, float h)
{
	mat3 retval = mat3Identity();
	retval[0][0] = w;
	retval[1][1] = h;
	return retval;
}

mat3 translate(float x, float y)
{
	mat3 retval = mat3Identity();
	retval[2][0] = x;
	retval[2][1] = y;
	return retval;
}

mat3 rotate(float a)
{
	vec2 d = fromAngle(a);
	mat3 retval = mat3Identity();
	retval[0].xy = d;
	retval[1].xy = -perp(d);
	return retval;
}
