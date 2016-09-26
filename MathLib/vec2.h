#pragma once

struct vec2 { float x, y; };

vec2 operator+(const vec2 &lhs, const vec2 &rhs);
// need subtraction

vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator*(float rhs, const vec2 &lhs);
// need division

vec2 operator-(const vec2 &v);

vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
// need -=, /=, *=

bool operator==(const vec2 &lhs, const vec2 &rhs);
// need !=  

float magnitude(const vec2 &v);