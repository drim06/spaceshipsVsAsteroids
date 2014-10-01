#pragma once
#include "SpaceShip.h"
#include "GraphicPrimitives.h"
#include "Square.h"
#include "Laser.h"

class SpaceCruiser : public SpaceShip
{
private:
	int missileFrequency_;
	float red_, green_, blue_;
	const Square& square_;
	float missilePosX_, missilePosY_;
	Laser * laser_;

public:
	SpaceCruiser(const Square& square) :
		square_(square),
		red_(1.0f),
		green_(0.0f),
		blue_(0.0f),
		laser_(new Laser(10, 0.03))
	{}

	~SpaceCruiser();

	void draw();

};

