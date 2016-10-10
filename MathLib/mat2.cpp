#include "mat2.h"
#include "flops.h"

bool operator==(const mat2 & A, const mat2 & B)
{
	return  fequals(A.m[0], B.m[0]) &&
			fequals(A.m[1], B.m[1]) &&
			fequals(A.m[2], B.m[2]) && 
			fequals(A.m[3], B.m[3]);

	// using vectors
	// return A[0] == B[0] && A[1] == B[1];
}

mat2 operator+(const mat2 & A, const mat2 & B)
{
	return mat2 { A.m[0] + B.m[0], A.m[1] + B.m[1],
		          A.m[2] + B.m[2], A.m[3] + B.m[3] };
}

mat2 transpose(const mat2 &A)
{
	// copy the diagonal
	mat2 retval = A;

	// what values here need to change?
	// .m[1] and .m[2]
	
	retval.mm[1][0] = A.mm[0][1];
	retval.mm[0][1] = A.mm[1][0];

	return A;
}

/*
	Our matrices are what we call column-major:
		mat[C][R]


		trans[R][C], mat[C][R]

	
*/
