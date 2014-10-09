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
		posY_ = posY - (0.02f / 2.f);	// pour placer le rectangle à la bonne hauteur : posY - largeur rectangle /2
		power_ = 35;
		rapidity_ = 0.03f;
		red_ = 0.8f;
		green_ = 0.0f;
		blue_ = 0.0f;
	}

	~Laser();

	void draw();
	void tick();
	bool hit(Enemy& enemy);
};

