#pragma once

class SpaceShip // classe abstraite 
{
public:
	virtual void draw() = 0;
	virtual float getWeaponPosX() = 0;
	virtual float getWeaponPosY() = 0;
};