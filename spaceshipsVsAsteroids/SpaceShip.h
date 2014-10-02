#pragma once

class SpaceShip // classe abstraite 
{
public:
	virtual void draw() = 0;
	virtual float getWeaponPosX() const = 0; 
	virtual float getWeaponPosY() const = 0; 
	virtual bool canShoot(const int&) const = 0;
};