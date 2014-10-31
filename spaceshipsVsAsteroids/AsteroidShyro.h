#pragma once
#include "Enemy.h"
#include "GraphicPrimitives.h"

class AsteroidShyro : public Enemy
{
	float width_, height_;
public:
	AsteroidShyro(int const rows) :
		width_(0.13f), height_(0.05f)
	{
		rows_ = rows;
		health_ = 2500;
		posX_ = (1.0f - 0.42f);
		posY_ = 1 - rows*0.171667f - 0.171667f / 2;
		rapidity_ = 0.004f;
		dropMoney_ = 50;
		dropScore_ = 150;
		power_ = 25;
		red_ = 1.0f;
		green_ = 0.5f;
		blue_ = 0.4f;
	}

	void draw();
	bool hit(SpaceShip&);
};

