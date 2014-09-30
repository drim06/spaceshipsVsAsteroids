#pragma once
#include "GraphicPrimitives.h"
#include <ctime>
#include <cstdlib>

class Square
{
private:
	float posX_, posY_, side_;
	float red_, green_, blue_;
	int nbClick_;

public:
	Square(float posX, float posY, float side, float red, float green, float blue):
		posX_(posX),
		posY_(posY),
		side_(side),
		red_(red),
		green_(green),
		blue_(blue),
		nbClick_(0)
	{}

	void draw();
	void tick();
	bool isClicked(float&, float&);
	void changeColor();
	void incrNbClick();
};

