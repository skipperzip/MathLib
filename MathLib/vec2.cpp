#include "vec2.h"
#include <cmath>
#include "flops.h"

vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{lhs.x + rhs.x, lhs.y + rhs.y};
}

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x - rhs.x, lhs.y - rhs.y };
}

vec2 operator/(const vec2 & lhs, float rhs)
{
	return vec2{ lhs.x/rhs, lhs.y/rhs };
}

vec2 operator*(const vec2 & lhs, float rhs)
{
	return vec2{ lhs.x * rhs, lhs.y * rhs };
}
vec2 operator*(float lhs, const vec2 & rhs)
{
	return vec2{ lhs * rhs.x, lhs * rhs.y };
}

vec2 operator-(const vec2 & v)
{
	return v*-1;
}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs + rhs;
}

vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs - rhs;
}

vec2 & operator*=(vec2 & lhs, float rhs)
{
	return lhs = lhs * rhs;
}

vec2 & operator/=(vec2 & lhs, float rhs)
{
	return lhs = lhs / rhs;
}


bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	return fequals(lhs.x, rhs.x) && fequals(lhs.y, rhs.y);
}

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	return !fequals(lhs.x, rhs.x) || !fequals(lhs.y, rhs.y);
}

float magnitude(const vec2 & v)
{
	return sqrt(v.x*v.x + v.y*v.y);
}

vec2 normal(const vec2 & v)
{
	return v / magnitude(v);
}

float dot(const vec2 & lhs, const vec2 & rhs)
{
	return lhs.x*rhs.x + lhs.y*rhs.y;
}

float angleBetween(const vec2 & lhs, const vec2 & rhs)
{
	return acos(dot(normal(lhs), normal(rhs)));
}

vec2 perp(const vec2 & v)
{
	return {v.y,-v.x};
}

float angle(const vec2 & v)
{
	return atan2f(v.y, v.x);
}

vec2 fromAngle(float a)
{
	return vec2{cos(a), sin(a)};
}

vec2 lerp(const vec2 &start, const vec2 &end, float alpha)
{
	vec2 retval;
	retval.x = lerp(start.x, end.x, alpha);
	retval.y = lerp(start.y, end.y, alpha);
	return retval;
}

vec2 quadBezier(const vec2 &start, const vec2 &mid, const vec2 &end, float alpha)
{
	vec2 retval;
	retval.x = quadBezier(start.x, mid.x, end.x, alpha);
	retval.y = quadBezier(start.y, mid.y, end.y, alpha);
	return retval;
}

vec2 catRomSpline(const vec2 & start, const vec2 & mid, const vec2 & end, float alpha)
{
	vec2 retval;
	retval.x = catRomSpline(start.x, mid.x, end.x, alpha);
	retval.y = catRomSpline(start.y, mid.y, end.y, alpha);
	return retval;
}
