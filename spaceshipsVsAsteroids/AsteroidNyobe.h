#pragma once
#include "Enemy.h"
#include "GraphicPrimitives.h"

class AsteroidNyobe : public Enemy
{
public:
	AsteroidNyobe(int const rows)
	{
		rows_ = rows;
		coeffReducteur_ = 0.0f;
		health_ = 400;
		posX_ = (1.0f - 0.42f);
		posY_ = 1 - rows*0.171667f - 0.171667f / 2;
		rapidity_ = 0.003f;
		dropMoney_ = 25;
		power_ = 10;
		red_ = 0.3f;
		green_ = 0.9f;
		blue_ = 0.3f;
	}

	void draw();
	bool hit(SpaceShip&);
	void shrink();
};
