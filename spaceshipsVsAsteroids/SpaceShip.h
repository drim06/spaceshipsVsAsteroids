#pragma once

class SpaceShip // classe abstraite 
{
protected:
	float weaponPosX_, weaponPosY_;
	int frequency_;
	float red_, green_, blue_;
	int cost_;
	int spaceShipValue_;
	int health_;
	

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

	void receiveDamage(int x){
		if (health_ - x < 0){
			health_ = 0;
		}
		else {
			health_ -= x;
		}
	}
}; 