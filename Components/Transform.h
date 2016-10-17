#pragma once

#include "vec2.h"
#include "mat3.h"

class Transform
{
public:
	// Transform();
	// make, create, or init functions
	// all fill similar roles.
	vec2  m_position;
	vec2  m_scale;
	float m_facing;

	// Constructors exist to ensure that
	// a created object has meaningful defaults
	Transform(float x = 0, float y = 0,
		float w = 1, float h = 1, float a = 0);

	vec2 getUp() const;
	vec2 getDirection() const;
	void setDirection(const vec2 &dir);


	mat3 getLocalTransform() const;

	void debugDraw(const mat3 &T = mat3Identity()) const;
};

// Default constructor gets called 40 times,
// one for each transform in the array.
// Transform trans[40];