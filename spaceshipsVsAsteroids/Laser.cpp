#include "Laser.h"


Laser::~Laser()
{
}

void Laser::draw(){
	GraphicPrimitives::drawFillRect2D(
		posX_,
		posY_,
		width_,
		height_,
		red_,
		green_,
		blue_);
}

void Laser::tick(){
	posX_ += rapidity_;
}