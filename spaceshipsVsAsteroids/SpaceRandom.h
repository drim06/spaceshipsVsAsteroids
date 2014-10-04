#pragma once
#include "SpaceShip.h"
#include "GraphicPrimitives.h"
#include "Square.h"
#include "Player.h"

class SpaceRandom : public SpaceShip
{
	Square& square_;
	Player& player_;
	int tickOnCreation_;
	

public:
	SpaceRandom(Square& square, Player& player) :
		square_(square),
		player_(player)
	{
		weaponPosX_ = square_.getPosX() + square_.getSide();
		weaponPosY_ = square_.getPosY() + square_.getSide() / 2;
		frequency_ = 150;
		cost_ = 150;
		player_.loseMoney(cost_);
		spaceShipValue_ = 3;
		red_ = 0.2f;
		green_ = 0.1f;
		blue_ = 1.0f;
	}

	void draw();
};
