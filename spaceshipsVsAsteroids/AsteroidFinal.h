#pragma once
#include "Enemy.h"
#include "GraphicPrimitives.h"

class AsteroidFinal : public Enemy
{
	float width_, height_;
public:
	AsteroidFinal(int const rows) :
		width_(0.13f), height_(0.05f)
	{
		rows_ = rows;
		coeffReducteur_ = 0.0f;
		health_ = 20000;
		posX_ = (1.0f - 0.42f);
		posY_ = 1 - rows*0.171667f - 0.171667f / 2;
		rapidity_ = 0.0028f;
		dropMoney_ = 0;
		dropScore_ = 500;
		power_ = 100;
		red_ = 1.0f - (rand() % 100) / 100.f;
		green_ = 1.0f - (rand() % 100) / 100.f;
		blue_ = 1.0f - (rand() % 100) /100.f;
	}

	void draw();
	bool hit(SpaceShip&);
	void shrink();
};

