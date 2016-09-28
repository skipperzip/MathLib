#pragma once

struct vec3 { float x, y, z; };

vec3 operator+(const vec3 &lhs, const vec3 &rhs);
vec3 operator-(const vec3 &lhs, const vec3 &rhs);
vec3 operator/(const vec3 &lhs, float rhs);
vec3 operator*(const vec3 &lhs, float rhs);
vec3 operator*(float lhs, const vec3 &rhs);
vec3 operator-(const vec3 &v);

vec3 &operator+=(vec3 &lhs, const vec3 &rhs);
vec3 &operator-=(vec3 &lhs, const vec3 &rhs);
vec3 &operator*=(vec3 &lhs, float rhs);
vec3 &operator/=(vec3 &lhs, float rhs);


bool operator==(const vec3 &lhs, const vec3 &rhs);
bool operator!=(const vec3 &lhs, const vec3 &rhs);


// Pythagorean theorem
// sqrt(v.x*v.x + v.y*v.y + v.z*v.z)
float magnitude(const vec3 &v);

// Reduce vector's length to 1
// v/magnitude(v)
vec3 normal(const vec3 &v);
// Scalar Projection : width of the right angle between two vectors
// x1*x2 + y1*y2 + z1*z2
float dot(const vec3 &lhs, const vec3 &rhs);

// Find the angle between two vectors
// acos(dot(normal(v1), normal(v2)))
float angleBetween(const vec3 &lhs, const vec3 &rhs);


// Find a vector perpendicular to the plane created by two vectors
// (y1z2 - z1y2, z1x3 - x1z3, x1y2 - x2y1)
vec3 cross(const vec3 &lhs, const vec3 &rhs);