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
	float coeffReducteur_;

public:
	Asteroid(int const rows) :
		rows_(rows),
		posX_(1.0f - 0.42f),
		posY_(1- rows*0.171667f-0.171667f/2),
		rapidity_(0.002f),
		health_(100),
		coeffReducteur_(0.0f),
		red_(0.0f),
		green_(1.0f),
		blue_(0.1f)
	{}

	~Asteroid();

	void draw();
	void tick();
	float getPosX() const;
	float getPosY() const;
	void receiveDamage(int);
	bool isAlive() const;
	void shrink();
};

