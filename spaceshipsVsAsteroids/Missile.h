#pragma once
#include "Enemy.h"
class Missile
{
public:
	virtual void draw() = 0;
	virtual void tick() = 0;
	virtual float getPosX() const = 0;
	virtual bool hit(const Enemy&) = 0;
	virtual void dealDamage(Enemy&) = 0;
};

