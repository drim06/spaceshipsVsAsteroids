#include "Asteroid.h"

void Asteroid::draw(){
	std::vector<float> x;
	std::vector<float> y;

	// x values
	x.push_back(posX_);
	x.push_back(posX_ + 0.035f);
	x.push_back(posX_ + 0.07f);
	x.push_back(posX_ + 0.035f);
	x.push_back(posX_ + 0.14f);
	x.push_back(posX_ + 0.07f);

	// y values
	y.push_back(posY_);
	y.push_back(posY_ + 0.035f);
	y.push_back(posY_ + 0.07f);
	y.push_back(posY_ + 0.035f);
	y.push_back(posY_);
	y.push_back(posY_-0.07f);

	GraphicPrimitives::drawFillPolygone2D(
		x,
		y,
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

float Asteroid::getPosY() const{
	return posY_;
}