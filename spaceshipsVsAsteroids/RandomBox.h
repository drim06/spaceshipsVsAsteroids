#pragma once
#include "Missile.h"
#include "GraphicPrimitives.h"
#include "Enemy.h"

class RandomBox : public Missile
{
	float width_, height_;
	float vectX_, vectY_;

public:
	RandomBox(float posX, float posY, float vectX, float vectY) :
		width_(0.05f),
		height_(0.007f),
		vectX_(vectX),
		vectY_(vectY)
	{
		posX_ = posX;
		posY_ = posY - (0.008f / 2.f);	// pour placer le rectangle � la bonne hauteur : posY - largeur rectangle /2
		power_ = 15;
		rapidity_ = 0.018f;
		red_ = 0.f;
		green_ = 0.95f;
		blue_ = 0.2f;
	}

	void draw();
	void tick();
	bool hit(Enemy& enemy);
};

