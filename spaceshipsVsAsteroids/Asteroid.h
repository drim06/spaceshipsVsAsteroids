#pragma once
#include "GraphicPrimitives.h"
#include "Enemy.h"

class Asteroid : public Enemy
{
private:
	float posX_, posY_;
	int const rows_;
	float red_, green_, blue_;
	float rapidity_;
	int health_;

public:
	Asteroid(int const rows) :
		rows_(rows),
		posX_(1.0f),
		posY_(0.0f),
		rapidity_(0.002f),
		health_(100),
		red_(0.0f),
		green_(1.0f),
		blue_(0.1f)
	{}

	~Asteroid();

	void draw();
	void tick();
};

