#pragma once
#include "SpaceShip.h"
#include "GraphicPrimitives.h"
#include "Square.h"
#include "Player.h"

class SpaceSnake : public SpaceShip
{
	Square& square_;
	Player& player_;
	int tickOnCreation_;


public:
	SpaceSnake(Square& square, Player& player) :
		square_(square),
		player_(player)
	{
		weaponPosX_ = square_.getPosX() + square_.getSide();
		weaponPosY_ = square_.getPosY() + square_.getSide() / 2;
		frequency_ = 350;
		cost_ = 400;
		health_ = 100;
		player_.loseMoney(cost_);
		spaceShipValue_ = 4;
		red_ = 0.0f;
		green_ = 1.0f;
		blue_ = 0.0f;
	}

	void draw();
	void cleanSquare();
};