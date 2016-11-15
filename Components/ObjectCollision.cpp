#include "ObjectCollision.h"


void PlayerAsteroidCollision(PlayerShip & player, Asteroid & as)
{
	CollisionData result = 
	DynamicResolution(player.transform, player.rigidbody, player.collider,
						as.transform, as.rigidbody, as.collider);

	if (result.penetrationDepth >= 0)
	{
		// Some sort of negative feedback for colliding
		player.transform.m_scale *= .9f;
	}
}

void AsteroidCollision(Asteroid & as1, Asteroid & as2)
{
	DynamicResolution(as1.transform, as1.rigidbody, as1.collider,
					  as2.transform, as2.rigidbody, as2.collider);
}

void BulletAsteroidCollision(GravBullet &b, Asteroid &a)
{
	if (!b.isAlive) return;

	CollisionData result = 
		DynamicResolution(b.transform, b.rigidbody, b.collider,
					  a.transform, a.rigidbody, a.collider);

	if(result.penetrationDepth >= 0)
	{
		b.timer = 0;
	}
}

void TractorAsteroidCollision(TractorBeam & tractor, Asteroid & asteroid)
{
	if (!tractor.isAlive) return;

	CollisionData result =
				ColliderCollision(tractor.transform, tractor.collider,
						asteroid.transform, asteroid.collider);

	if (result.penetrationDepth >= 0)
	{
		vec2 dir = normal(tractor.transform.getGlobalPosition()-
						  asteroid.transform.getGlobalPosition());

		asteroid.rigidbody.addForce(dir * 500);
	}
}


