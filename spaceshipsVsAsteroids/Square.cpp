#include "Square.h"
#include <cstdlib>
#include "MyGraphicEngine.h"
#include "utility.h"

void Square::draw(){
	
	GraphicPrimitives::drawFillRect2D(
		posX_,
		posY_,
		side_,
		side_,
		red_,
		green_,
		blue_);
}

void Square::tick(){}

bool Square::isClicked(float& x, float& y){
	if (x < posX_) return false;
	if (y < posY_) return false;
	if (x > posX_ + side_) return false;
	if (y > posY_ + side_) return false;
	return true;
}

void Square::changeColor(){
	red_ = 1.0f;
	green_ = 0.0f;
	blue_ = 0.0f;
}

void Square::incrNbClick(){
	nbClick_++;
}

float Square::getSide() const{
	return side_;
}

float Square::getPosX() const{
	return posX_;
}

float Square::getPosY() const{
	return posY_;
}

bool Square::isOccuped() const{
	return occuped_;
}

void Square::setIsOccuped(bool b){
	occuped_ = b;
}