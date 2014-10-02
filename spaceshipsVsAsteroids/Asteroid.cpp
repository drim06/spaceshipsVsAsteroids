#include "Asteroid.h"

void Asteroid::draw(){
	GraphicPrimitives::drawFillTriangle2D(
		posX_,
		posY_,
		posX_ -0.05f,
		posY_ -0.02f,
		posX_ -0.05f,
		posY_ + 0.02f,
		red_,
		green_,
		blue_);
}

void Asteroid::tick(){
	posX_ -= rapidity_;
}

float Asteroid::getPosX() const{
	return posX_;
}