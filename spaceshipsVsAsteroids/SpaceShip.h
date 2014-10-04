#pragma once

class SpaceShip // classe abstraite 
{
protected:
	float weaponPosX_, weaponPosY_;
	int frequency_;
	float red_, green_, blue_;
	int cost_;
	int spaceShipValue_;
	

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
}; 