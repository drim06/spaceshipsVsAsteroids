#pragma once
#include "Missile.h"
#include "GraphicPrimitives.h"
#include "Enemy.h"

class Venom : public Missile
{
	float width_, height_;
	float vectX_, vectY_;

public:
	Venom(float posX, float posY, float vectX, float vectY) :
		width_(0.01f),
		height_(0.01f),
		vectX_(vectX),
		vectY_(vectY)
	{
		posX_ = posX - (0.008f / 2.f);;
		posY_ = posY - (0.008f / 2.f);	// pour placer le rectangle à la bonne hauteur : posY - largeur rectangle /2
		power_ = 100;
		rapidity_ = 0.01f;
		red_ = 0.0f;
		green_ = 1.0f;
		blue_ = 0.0f;
	}

	void draw();
	void tick();
	bool hit(Enemy& enemy);
};

