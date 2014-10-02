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
		weaponPosX_(0.0f),
		weaponPosY_(-0.5f),
		red_(1.0f),
		green_(0.0f),
		blue_(0.0f)
	{
		/*float squarePosX = square_.getPosX();
		float squarePosY = square_.getPosY();
		float squareSide = square_.getSide();
		weaponPosX_ = squarePosX + squareSide;
		weaponPosY_ = squarePosY + squareSide / 2;*/
	}

	~SpaceCruiser();

	void draw();
	//float getWeaponPosX() const;
	//float getWeaponPosY() const;

};

