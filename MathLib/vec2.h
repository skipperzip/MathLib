#pragma once

struct vec2 { float x, y; };

vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);
vec2 operator/(const vec2 &lhs, float rhs);
vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator*(float lhs, const vec2 &rhs);
vec2 operator-(const vec2 &v);

vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 &lhs, const vec2 &rhs);
vec2 &operator*=(vec2 &lhs, float rhs);
vec2 &operator/=(vec2 &lhs, float rhs);


bool operator==(const vec2 &lhs, const vec2 &rhs);
bool operator!=(const vec2 &lhs, const vec2 &rhs);


// Pythagorean theorem
// sqrt(v.x*v.x + v.y*v.y)
float magnitude(const vec2 &v);

// Reduce vector's length to 1
// v/magnitude(v)
vec2 normal(const vec2 &v);

// Scalar Projection : width of the right angle between two vectors
// x1*x2 + y1*y2
float dot(const vec2 &lhs, const vec2 &rhs);

// Find the angle between two vectors
// acos(dot(normal(v1), normal(v2)))
float angleBetween(const vec2 &lhs, const vec2 &rhs);

// Find a right angle perpendicular vector (2D only!)
// (y,-x)
vec2 perp(const vec2 &v);

// Find the angle of the vector (2D only!)
// atan2f(y,x)
float angle(const vec2 &v);

// vec2{cos(a), sin(a)};
vec2 fromAngle(float a);
//{
//	return vec2{cos(a), sin(a)};
//}