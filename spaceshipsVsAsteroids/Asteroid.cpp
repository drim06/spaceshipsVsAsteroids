#include "Asteroid.h"

void Asteroid::draw(){
	GraphicPrimitives::drawFillTriangle2D(
		posX_,
		posY_,
		-0.05f,
		-0.02f,
		-0.05f,
		0.02f,
		red_,
		green_,
		blue_);
}

void Asteroid::tick(){
	posX_ -= rapidity_;
}