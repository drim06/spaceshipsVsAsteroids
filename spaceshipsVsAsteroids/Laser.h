#pragma once
#include "Missile.h"
#include "GraphicPrimitives.h"
#include "Enemy.h"

class Laser : public Missile
{
	float width_, height_;

public:
	Laser(float posX, float posY) :
		width_(0.05f),
		height_(0.015f)
	{
		posX_ = posX;
		posY_ = posY - (0.02f / 2.f);
		power_ = 35;
		rapidity_ = 0.04f;
		red_ = 0.8f;
		green_ = 0.0f;
		blue_ = 0.0f;
	}

	void draw();
	void tick();
	bool hit(Enemy& enemy);
};

