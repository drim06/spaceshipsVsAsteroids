#pragma once
#include "SpaceShip.h"
#include "Player.h"
class Enemy // classe abstraite 
{
protected:
	float posX_, posY_;
	float rapidity_;
	float red_, green_, blue_;
	int health_;
	int rows_;
	int dropMoney_, dropScore_;
	int power_;

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

	int getDropMoney() const{
		return dropMoney_;
	}

	int getDropScore() const{
		return dropScore_;
	}

	void dealDamageToPlayer(Player& player){
		player.loseHealth(power_);
	}

	void dealDamage(SpaceShip& spaceShip){
		spaceShip.receiveDamage(power_);
	}
};

