#pragma once

#include "Asteroid.h"
#include "PlayerShip.h"


void PlayerAsteroidCollision(PlayerShip &player, Asteroid &as);

void AsteroidCollision(Asteroid &as1, Asteroid &as2);