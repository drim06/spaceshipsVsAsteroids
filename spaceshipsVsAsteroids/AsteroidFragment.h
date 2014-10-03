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
		coeffReducteur_ = 0.0f;
		health_ = 25;
		posX_ = (1.0f - 0.42f);
		posY_ = 1 - rows*0.171667f - 0.171667f / 2;
		rapidity_ = 0.005f;
		red_ = 0.0f;
		green_ = 1.0f;
		blue_ = 0.0f;
	}
	~AsteroidFragment();

	void draw();
	void shrink();
};