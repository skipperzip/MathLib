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

// sqrt(v.x*v.x + v.y*v.y)
float magnitude(const vec2 &v);

// v/magnitude(v)
vec2 normal(const vec2 &v);

//////////////////////////////
///////// 4 new functions!
float dot(const vec2 &rhs, const vec2 &lhs);
float angleBetween(const vec2 &rhs, const vec2 &lhs);

////////////////////////////
// 3D Cross Product vec3 cross(const vec3 &lhs, const vec3 &rhs);

////////////////////////////
// 2D Only!
// right-handed. 
vec2 perp(const vec2 &v);
// arctangent!
vec2 angle(const vec2 &v);