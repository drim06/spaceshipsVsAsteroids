#pragma once
#include "SpaceShip.h"
#include "GraphicPrimitives.h"
#include "Square.h"
#include "Player.h"

class SpaceFalcon : public SpaceShip
{
	Square& square_;
	Player& player_;
	int tickOnCreation_;

public:
	SpaceFalcon(Square& square, Player& player) :
		square_(square),
		player_(player)
	{
		weaponPosX_ = square_.getPosX() + square_.getSide();
		weaponPosY_ = square_.getPosY() + square_.getSide() / 2;
		frequency_ = 50;
		cost_ = 75;
		player_.loseMoney(cost_);
		health_ = 20;
		spaceShipValue_ = 2;
		red_ = 1.0f;
		green_ = 1.0f;
		blue_ = 0.0f;
	}

	SpaceFalcon(Square& square, Player& player, bool isInShop) :
		square_(square),
		player_(player)
	{
		weaponPosX_ = square_.getPosX() + square_.getSide();
		weaponPosY_ = square_.getPosY() + square_.getSide() / 2;
		spaceShipValue_ = 2;
		health_ = 15;
		red_ = 1.0f;
		green_ = 1.0f;
		blue_ = 0.0f;
	}

	void draw();
	void cleanSquare();
};