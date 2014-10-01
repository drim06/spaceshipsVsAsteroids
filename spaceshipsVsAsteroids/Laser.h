#pragma once
#include "Missile.h"
#include "GraphicPrimitives.h"

class Laser : public Missile
{
	int power_;
	float rapidity_;
	float red_, green_, blue_;
	float posX_, posY_;

public:
	Laser(float posX, float posY):
		posX_(0.0f),
		posY_(0.0f),
		power_(10),
		rapidity_(0.002f),
		red_(0.0f),
		green_(0.0f),
		blue_(1.0f)
	{}

	~Laser();

	void draw();
	void tick();
};

