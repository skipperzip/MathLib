#pragma once

#include "Asteroid.h"
#include "PlayerShip.h"
#include "GravBullet.h"
#include "TractorBeam.h"

/*
These are interactions between objects.

In general, they occur on collision, but they can be as specialized
or do whatever you want them to.

Each time you introduce a new game object, you may want to create a 
custom interaction between that object and another object.
*/

void PlayerAsteroidCollision(PlayerShip &player, Asteroid &as);

void AsteroidCollision(Asteroid &as1, Asteroid &as2);




void BulletAsteroidCollision(GravBullet &bullet, Asteroid &asteroid);

void TractorAsteroidCollision(TractorBeam &tractor, Asteroid &asteroid);