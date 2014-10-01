#pragma once
#include "SpaceShip.h"
#include "GraphicPrimitives.h"
#include "Square.h"

class SpaceCruiser : public SpaceShip
{
private:
	int missileFrequency_, power_, rapidity_;
	float red_, green_, blue_;
	const Square& square_;

public:
	SpaceCruiser(const Square& square) :
		square_(square),
		red_(1.0f),
		green_(0.0f),
		blue_(0.0f)
	{}

	~SpaceCruiser();

	void draw();

};

