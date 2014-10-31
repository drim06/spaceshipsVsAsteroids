#pragma once
#include "SpaceShip.h"
#include "GraphicPrimitives.h"
#include "Square.h"
#include "Laser.h"
#include "Player.h"

class SpaceCruiser : public SpaceShip
{
	Square& square_;
	Player& player_;
	int tickOnCreation_;


public:
	SpaceCruiser(Square& square, Player& player) :
		square_(square),
		player_(player)
	{
		weaponPosX_ = square_.getPosX() + square_.getSide();
		weaponPosY_ = square_.getPosY() + square_.getSide() / 2;
		frequency_ = 30;
		cost_ = 40;
		player_.loseMoney(cost_);
		spaceShipValue_ = 1;
		health_ = 15;
		red_ = 1.0f;
		green_ = 0.0f;
		blue_ = 0.0f;
	}

	SpaceCruiser(Square& square, Player& player, bool isInShop) :
		square_(square),
		player_(player)
	{
		weaponPosX_ = square_.getPosX() + square_.getSide();
		weaponPosY_ = square_.getPosY() + square_.getSide() / 2;
		spaceShipValue_ = 1;
		cost_ = 40;
		costTxt_ = new char[100];
		utility::itoa(cost_, costTxt_);
		health_ = 15;
		red_ = 1.0f;
		green_ = 0.0f;
		blue_ = 0.0f;
	}

	void draw();
	void cleanSquare();
};

