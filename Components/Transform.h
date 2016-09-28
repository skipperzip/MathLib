#pragma once

#include "vec2.h"

class Transform
{
public:
 //       Transform();
        // make, create, or init functions
        // all fill similar roles.

        // Constructors exist to ensure that
        // a created object has meaningful defaults
        Transform(float x = 0, float y = 0,
                float w = 1, float h = 1, float a = 0);

        vec2  position;
	vec2  scale;
	float facing;

	vec2 getDirection();
	void setDirection(const vec2 &dir);

	void debugDraw();
};

// Default constructor gets called 40 times,
// one for each transform in the array.
// Transform trans[40];