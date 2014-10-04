#pragma once
#include "SpaceShip.h"
class Enemy // classe abstraite 
{
protected:
	float posX_, posY_;
	float rapidity_;
	int health_;
	float red_, green_, blue_;
	int rows_;
	float coeffReducteur_;
	int dropMoney_;

public: 
	virtual void draw() = 0;
	virtual bool hit(SpaceShip&) = 0;

	void tick(){
		posX_ -= rapidity_;
	}

	float getPosX()const {
		return posX_;
	}

	float getPosY() const{
		return posY_;
	}

	void receiveDamage(int x){
		health_ -= x;
	}

	bool isAlive() const{
		return health_ > 0;
	}

	int getDropMoney(){
		return dropMoney_;
	}
};

