#include "AsteroidFragment.h"
#include "GraphicPrimitives.h"

void AsteroidFragment::draw(){

	GraphicPrimitives::drawFillRect2D(
		posX_,
		posY_,
		width_,
		height_,
		red_,
		green_,
		blue_);

	GraphicPrimitives::drawFillRect2D(
		posX_ + width_/2 - height_/2,
		posY_ - width_/2,
		height_,
		width_,
		red_,
		green_,
		blue_);
}

void AsteroidFragment::shrink(){
	coeffReducteur_ += 0.01f;
}
