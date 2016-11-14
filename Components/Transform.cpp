#include "Transform.h"
#include "sfwdraw.h"
#include "shapedraw.h"

Transform::Transform(float x, float y, float w, float h, float a)
{
	m_position.x = x;
	m_position.y = y;

	m_scale.x = w;
	m_scale.y = h;

	m_facing = a;

	m_parent = nullptr;
}

vec2 Transform::getUp() const
{
	return -perp(getDirection());
}


vec2 Transform::getDirection() const
{
	return fromAngle(m_facing);
}


void Transform::setDirection(const vec2 &dir)
{
	m_facing = angle(dir);
}

vec2 Transform::getGlobalPosition() const
{
	return getGlobalTransform()[2].xy;
}

// First column of the Global Transform.
vec2 Transform::getGlobalright() const
{
	return getGlobalTransform()[0].xy;
}

vec2 Transform::getGlobalUp() const
{
	return getGlobalTransform()[1].xy;
}

float Transform::getGlobalAngle() const
{
	//atan2f(y,x)
	return angle(getGlobalright());
}


/*
	This function gets our global transform!
*/
mat3 Transform::getGlobalTransform() const
{
	if (m_parent == nullptr)
		return getLocalTransform();
	else
		return m_parent->getGlobalTransform() * getLocalTransform();
}



mat3 Transform::getLocalTransform() const
{
	mat3 T = translate(m_position.x, m_position.y);
	mat3 S = scale(m_scale.x, m_scale.y);
	mat3 R = rotate(m_facing);

	return T * R * S;
}

void Transform::debugDraw(const mat3 &T) const
{
	// Use global transform for stuff now!
	mat3 L = T * getGlobalTransform();
	
	vec3 pos = L[2];

	vec3 right = L * vec3{ 1, 0, 1 };
	vec3 up    = L * vec3{ 0, 1, 1 };

	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	sfw::drawLine(pos.x, pos.y, up.x, up.y, GREEN);

	// Draw line to parent if possible.
	vec3 sgp = m_parent ? T * m_parent->getGlobalTransform()[2] : pos;
	sfw::drawLine(sgp.x, sgp.y, pos.x, pos.y, BLUE);

	drawCircle(L * Circle{0, 0, 1}, 0x888888FF);
}
