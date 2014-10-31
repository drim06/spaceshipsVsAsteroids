#pragma once
#include "Missile.h"
#include "GraphicPrimitives.h"
#include "Enemy.h"

class RapidFire : public Missile
{
	float width_, height_;
	float vectX_, vectY_;

public:
	RapidFire(float posX, float posY, float vectX, float vectY) :
		width_(0.05f),
		height_(0.007f),
		vectX_(vectX),
		vectY_(vectY)
	{
		posX_ = posX;
		posY_ = posY - (0.008f / 2.f);	
		power_ = 40;
		rapidity_ = 0.09f;
		red_ = 0.f;
		green_ = 0.f;
		blue_ = 0.8f;
	}

	void draw();
	void tick();
	bool hit(Enemy& enemy);
};

