#include "mat2.h"
#include "flops.h"

bool operator==(const mat2 & A, const mat2 & B)
{
	return A[0] == B[0] && A[1] == B[1];
}

bool operator!=(const mat2 & A, const mat2 & B)
{
	return !(A == B);
}

mat2 operator+(const mat2 & A, const mat2 & B)
{
	mat2 retval;
	retval[0] = A[0] + B[0];
	retval[1] = A[1] + B[1];
	return retval;
}

mat2 operator-(const mat2 & A, const mat2 & B)
{
	mat2 retval;
	retval[0] = A[0] - B[0];
	retval[1] = A[1] - B[1];
	return retval;
}

mat2 operator*(const mat2 & A, float s)
{
	mat2 retval;
	retval[0] = A[0] * s;
	retval[1] = A[1] * s;
	return retval;
}

mat2 operator*(float s, const mat2 & A)
{
	return A * s;
}

mat2 operator-(const mat2 & A)
{
	return A*-1;
}

// A C   A B
// B D = C D 
mat2 transpose(const mat2 &A)
{
	mat2 retval = A;

	retval.mm[1][0] = A.mm[0][1];
	retval.mm[0][1] = A.mm[1][0];

	return A;
}


mat2 operator*(const mat2 & A, const mat2 & B)
{
	// flip the values using transpose,
	// so that I can access rows as vectors
	mat2 At = transpose(A);
	mat2 retval;

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			retval[j][i] = dot(At[i],B[j]);

	return retval;
}

vec2 operator*(const mat2 & A, const vec2 & V)
{
	mat2 At = transpose(A);
	vec2 retval;

	retval[0] = dot(At[0], V);
	retval[1] = dot(At[1], V);

	return retval;
}

mat2 mat2Identity() { return mat2 {1,0,0,1}; }





vec2 mat2::operator[](unsigned idx) const
{
	return vec2();
}

vec2 & mat2::operator[](unsigned idx)
{
	// TODO: insert return statement here
}

float determinant(const mat2 & A)
{
	return 0.0f;
}

mat2 inverse(const mat2 & A)
{
	return mat2();
}
