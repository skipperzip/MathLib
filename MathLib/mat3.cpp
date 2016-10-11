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
	A + -B;
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
	// rows of the first X columns of the second.
	mat3 retval;

	//retval.m[0] = A.m[0] * B.m[0] + A.m[3] * B.m[1] + A.m[6] * B.m[2];
	//retval.m[1] = A.m[1] * B.m[0] + A.m[4] * B.m[1] + A.m[7] * B.m[2];
	//retval.m[2] = A.m[2] * B.m[0] + A.m[5] * B.m[1] + A.m[8] * B.m[2];

	//retval.m[0] = A.m[0] * B.m[3] + A.m[3] * B.m[4] + A.m[6] * B.m[5];
	//retval.m[1] = A.m[1] * B.m[3] + A.m[4] * B.m[4] + A.m[7] * B.m[5];
	//retval.m[2] = A.m[2] * B.m[3] + A.m[5] * B.m[4] + A.m[8] * B.m[5];

	//retval.m[0] = A.m[0] * B.m[6] + A.m[3] * B.m[7] + A.m[6] * B.m[8];
	//retval.m[1] = A.m[1] * B.m[6] + A.m[4] * B.m[7] + A.m[7] * B.m[8];
	//retval.m[2] = A.m[2] * B.m[6] + A.m[5] * B.m[7] + A.m[8] * B.m[8];

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


/*
	Long form.
	Matrix Minors.
	Triple Cross Product.

	A * inverse(A) = Identity
		9 variables in the inverse.


	A/A = 1;
*/
float determinant(const mat3 & A)
{
	return dot(A[0], cross(A[1],A[2]));
}


// inverse by the
// triple cross product

// For working with cameras!
// inverse(identity)*identity = identity
// inverse(anyMatrix)*anyMatrix = identity
mat3 inverse(const mat3 & A)
{
	mat3 retval;

	retval[0] = cross(A[1], A[2]);
	retval[1] = cross(A[2], A[0]);
	retval[2] = cross(A[0], A[1]);

	return 1 / determinant(A) *
				transpose(retval);
}