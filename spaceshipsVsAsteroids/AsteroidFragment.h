#pragma once
#include "Enemy.h"

class AsteroidFragment : public Enemy
{
	float width_, height_;
public:
	AsteroidFragment(int const rows) :
		width_(0.04f), height_(0.01f)
	{
		rows_ = rows;
		health_ = 30;
		posX_ = (1.0f - 0.42f);
		posY_ = 1 - rows*0.171667f - 0.171667f / 2;
		rapidity_ = 0.02f;
		dropMoney_ = 10;
		dropScore_ = 5;
		power_ = 5;
		red_ = 0.9f;
		green_ = 0.9f;
		blue_ = 0.4f;
	}

	void draw();
	bool hit(SpaceShip&);
};