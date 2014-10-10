#pragma once
#include "GraphicPrimitives.h"
#include "Enemy.h"
#include "SpaceShip.h"

class Asteroid : public Enemy
{
public:
	Asteroid(int const rows)
	{
		rows_ = rows;
		coeffReducteur_ = 0.0f;
		health_ = 100;
		posX_ = (1.0f - 0.42f);
		posY_ = 1 - rows*0.171667f - 0.171667f / 2;
		rapidity_ = 0.01f;
		dropMoney_ = 20;
		dropScore_ = 20;
		power_ = 10;
		red_ = 0.9f;
		green_ = 0.9f;
		blue_ = 0.9f;
	}

	~Asteroid();

	void draw();
	bool hit(SpaceShip&);
	void shrink();
};

