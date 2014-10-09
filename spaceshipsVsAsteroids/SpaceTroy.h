#pragma once
#include "SpaceShip.h"
#include "GraphicPrimitives.h"
#include "Square.h"
#include "Player.h"

class SpaceTroy : public SpaceShip
{
	Square& square_;
	Player& player_;
	int tickOnCreation_;
	

public:
	SpaceTroy(Square& square, Player& player) :
		square_(square),
		player_(player)
	{
		weaponPosX_ = square_.getPosX() + square_.getSide();
		weaponPosY_ = square_.getPosY() + square_.getSide() / 2;
		frequency_ = 150;
		cost_ = 200;
		health_ = 30;
		player_.loseMoney(cost_);
		spaceShipValue_ = 3;
		red_ = 0.2f;
		green_ = 0.1f;
		blue_ = 1.0f;
	}

	SpaceTroy(Square& square, Player& player, bool isInShop) :
		square_(square),
		player_(player)
	{
		weaponPosX_ = square_.getPosX() + square_.getSide();
		weaponPosY_ = square_.getPosY() + square_.getSide() / 2;
		spaceShipValue_ = 3;
		health_ = 15;
		cost_ = 200;
		costTxt_ = new char[100];
		utility::itoa(cost_, costTxt_);
		red_ = 0.2f;
		green_ = 0.1f;
		blue_ = 1.0f;
	}

	void draw();
	void cleanSquare();
};
