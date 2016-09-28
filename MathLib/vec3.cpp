#include "vec3.h"

vec3 cross(const vec3 & lhs, const vec3 & rhs)
{
	return vec3
	{lhs.y*rhs.z - lhs.z*rhs.y,
	 lhs.z*rhs.x - lhs.x*rhs.z,
	 lhs.x*rhs.y - lhs.y*rhs.x};

}
