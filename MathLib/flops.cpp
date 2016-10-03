#include "flops.h"
#include <cmath>

// FLT_EPSILON in <cfloat> is an okay threshold.
// float equivalence
// We want to see if two floats are negligbly close
// enough to be considered the same.
bool fequals(float lhs, float rhs)
{
	return fabsf(lhs-rhs) <= 0.00001f;
}

float deg2rad(float deg)
{
	return 0.0174533 * deg;
}

float rad2deg(float rad)
{
	return 57.2958 * rad;
}

float linearHalf(float x)
{
	return 0.5f*x;
}

// a. is probably something like a quadratic.
float growFast(float x)
{
	return x*x*x*x;
}
// One's Complement Concept.
float growSlow(float x)
{
	return 1 - growFast(1 - x);
}

float HardAngle(float x)
{
	return x < 0.5 ? 2 * x : -2 * (x - 1);
}

float bounce(float x)
{
	return abs(cos(x*10)*(1-x));
}
float bounceFlip(float x)
{
	return 1 - bounce(x);
}

float parabFlip(float x)
{
	return 1 - (2 * x - 1)*(2 * x - 1);
	// How do I shift a parabola over?
	// How do I control how wide it gets?
	// How do I change its direction?
}

//c.
// when x 0-0.5 : y = 0 - 1,
// when x 0.5-1 : y = 1 - 0
// Will look like a sharp right angle as it approaches the top of the screen.

//d. Do the bounce! but bounce off the Y=1 line.

//e. Create a parabola that arcs from
//   0 to 0 peaking at y=1 when x=0.5.


////// Linear Blending

float lerp(float start, float end, float alpha)
{
	return (1-alpha)*start + (alpha)*end;
}

float quadBezier(float start, float mid, float end, float alpha)
{
	return
		lerp(
			lerp(start, mid, alpha),
			lerp(mid,   end, alpha),
		alpha);
}

float hermiteSpline(float start, float s_tan, float end, float e_tan, float alpha)
{
	return 0;
}

float cardinalSpline(float start, float mid, float end, float tightness, float alpha)
{
	return 0;
}

float catRomSpline(float start, float mid, float end, float alpha)
{
	return 0;
}