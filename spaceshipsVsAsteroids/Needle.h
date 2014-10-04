#pragma once
#include "Missile.h"
#include "GraphicPrimitives.h"
#include "Enemy.h"

class Needle : public Missile
{
	float width_, height_;

public:
	Needle(float posX, float posY) :
		width_(0.05f),
		height_(0.007f)
	{
		posX_ = posX;
		posY_ = posY - (0.008f / 2.f);	// pour placer le rectangle à la bonne hauteur : posY - largeur rectangle /2
		power_ = 5;
		rapidity_ = 0.009f;
		red_ = 1.f;
		green_ = 0.95f;
		blue_ = 0.2f;
	}

	void draw();
	void tick();
	bool hit(Enemy& enemy);
};

