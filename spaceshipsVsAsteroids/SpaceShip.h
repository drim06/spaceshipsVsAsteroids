#pragma once
#include "GraphicPrimitives.h"
#include "utility.h"

class SpaceShip // classe abstraite 
{
protected:
	float weaponPosX_, weaponPosY_;
	int frequency_;
	float red_, green_, blue_;
	int cost_;
	int spaceShipValue_;
	int health_;
	char* costTxt_;
	

public:
	virtual void draw() = 0;
	virtual void cleanSquare() = 0;

	float getWeaponPosX() const{
		return weaponPosX_;
	}

	float getWeaponPosY() const{
		return weaponPosY_;
	}

	bool canShoot(const int& x) const{
		return x % frequency_ == 0;
	}

	int getSpaceShipValue() const{
		return spaceShipValue_;
	}

	bool isAlive() const{
		return health_ > 0;
	}

	int getCost() const {
		return cost_;
	}

	void receiveDamage(int x){
		if (health_ - x < 0){
			health_ = 0;
		}
		else {
			health_ -= x;
		}
	}

	virtual void drawCost(){
		GraphicPrimitives::drawText2D(
			"$",
			weaponPosX_ - 0.12f,
			weaponPosY_ + 0.1f,
			1.f,
			0.8f,
			0.f);
		GraphicPrimitives::drawText2D(
			costTxt_,// 40$
			weaponPosX_ - 0.09f,
			weaponPosY_+0.1f,
			1.f,
			0.8f,
			0.f);
	}
}; 