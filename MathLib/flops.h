#pragma once

/////////////
// 0.0000001
bool fequals(float lhs, float rhs);

float deg2rad(float deg);
float rad2deg(float rad);



//////////////////////////
// Basic Curving Stuff
float linearHalf(float x);
float growFast(float x);
float growSlow(float x);
float HardAngle(float x);
float bounce(float x);
float bounceFlip(float x);
float parabFlip(float x);

///////////////////////////////////
// Curving Functions (legit)

// Linear interpolation
float lerp(float start, float end, float alpha);

float quadBezier(float start, float mid, float end, float alpha);

// Challenge, extra exercise....
float cubicBezier(float start, float mid1, 
							float mid2, float end, float alpha);

float hermiteSpline(float start, float s_tan,
							float end, float e_tan, float alpha);

float cardinalSpline(float start, float mid,
						float end, float tightness, float alpha);

float catRomSpline(float start, float mid, float end, float alpha);
	// cardinalSpline(start, mid, end, .5, alpha);

/*******************
 Implement the above functions based upon the slides.

 Write 2 tests for each,
	where alpha = 0 and alpha = 1

Then try to draw them in the range of screen
*/