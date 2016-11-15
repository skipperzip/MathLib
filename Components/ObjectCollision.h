#pragma once

#include "Asteroid.h"
#include "PlayerShip.h"
#include "GravBullet.h"
#include "TractorBeam.h"

void PlayerAsteroidCollision(PlayerShip &player, Asteroid &as);

void AsteroidCollision(Asteroid &as1, Asteroid &as2);


void BulletAsteroidCollision(GravBullet &bullet, Asteroid &asteroid);


void TractorAsteroidCollision(TractorBeam &tractor, Asteroid &asteroid);