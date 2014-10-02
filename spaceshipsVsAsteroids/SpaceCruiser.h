#pragma once
#include "SpaceShip.h"
#include "GraphicPrimitives.h"
#include "Square.h"
#include "Laser.h"

class SpaceCruiser : public SpaceShip
{
private:
	float red_, green_, blue_;
	const Square& square_;
	float weaponPosX_, weaponPosY_;

public:
	SpaceCruiser(const Square& square) :
		square_(square),
		weaponPosX_(square_.getPosX() + square_.getSide()),
		weaponPosY_(square_.getPosY() + square_.getSide() / 2),
		red_(1.0f),
		green_(0.0f),
		blue_(0.0f)
	{}

	~SpaceCruiser();

	void draw();
	float getWeaponPosX();
	float getWeaponPosY();

};

