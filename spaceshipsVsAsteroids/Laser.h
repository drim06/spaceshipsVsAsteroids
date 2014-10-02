#pragma once
#include "Missile.h"
#include "GraphicPrimitives.h"
#include "Enemy.h"

class Laser : public Missile
{
	int power_;
	float rapidity_;
	float red_, green_, blue_;
	float posX_, posY_;
	bool inScreen_;
	float width_, height_;

public:
	Laser(float posX, float posY) :
		width_(0.05f),
		height_(0.02f),
		posX_(posX),
		posY_(posY - (0.02f / 2.f)),	// pour placer le rectangle � la bonne hauteur : posY - largeur rectangle /2
		power_(25),
		rapidity_(0.002f),
		red_(0.0f),
		green_(0.0f),
		blue_(1.0f)
	{}

	~Laser();

	void draw();
	void tick();
	float getPosX() const;
	bool hit(const Enemy& enemy);
};

