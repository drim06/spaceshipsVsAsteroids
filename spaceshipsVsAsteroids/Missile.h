#pragma once
#include "Enemy.h"

class Missile
{
protected:
	int power_;
	float rapidity_;
	float red_, green_, blue_;
	float posX_, posY_;
	bool inScreen_;

public:
	virtual void draw() = 0;
	virtual void tick() = 0;
	virtual bool hit(Enemy&) = 0;

	virtual float getPosX() const{
		return posX_;
	}

	virtual void dealDamage(Enemy& enemy){
		enemy.receiveDamage(power_);
	}
};

