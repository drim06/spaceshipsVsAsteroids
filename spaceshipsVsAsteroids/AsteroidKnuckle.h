#pragma once
#include "Enemy.h"
#include "GraphicPrimitives.h"

class AsteroidKnuckle : public Enemy
{
	float width_, height_;
public:
	AsteroidKnuckle(int const rows) :
		width_(0.13f), height_(0.05f)
	{
		rows_ = rows;
		health_ = 1000;
		posX_ = (1.0f - 0.42f);
		posY_ = 1 - rows*0.171667f - 0.171667f / 2;
		rapidity_ = 0.007f;
		dropMoney_ = 25;
		dropScore_ = 75;
		power_ = 20;
		red_ = 1.0f;
		green_ = 0.6f;
		blue_ = 1.0f;
	}

	void draw();
	bool hit(SpaceShip&);
};

