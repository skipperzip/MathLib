#pragma once

union vec2
{
	float v[2];

	struct // untagged
	{
		float x, y;
	};

	float  operator[](unsigned idx) const;
	float &operator[](unsigned idx);
};

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

float angleBetween(const vec2 &lhs, const vec2 &rhs);

float dist(const vec2 &a, const vec2 &b);

vec2 perp(const vec2 &v);


float angle(const vec2 &v);

vec2 fromAngle(float a);


////////////////////////////////////
//////// Curves and stuff.

// Use the float version and just call them for the  X and Y separately!

vec2 lerp(const vec2 &start, const vec2 &end, float alpha);

vec2 quadBezier(const vec2 &start, const vec2 &mid, const vec2 &end, float alpha);

vec2 hermiteSpline(const vec2 &start, const vec2 &s_tan, const vec2 &end, const vec2 &e_tan, float alpha);

vec2 cardinalSpline(const vec2 &start, const vec2 &mid, const vec2 &end,
					float tightness, float alpha);

vec2 catRomSpline(const vec2 &start, const vec2 &mid, const vec2 &end, float alpha);
