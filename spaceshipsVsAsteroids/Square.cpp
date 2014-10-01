#include "Square.h"
#include <cstdlib>
#include "MyGraphicEngine.h"
#include "utility.h"

void Square::draw(){
	char* nbClicks = new char[100];
	utility::itoa(nbClick_, nbClicks);
	
	GraphicPrimitives::drawFillRect2D(
		posX_,
		posY_,
		side_,
		side_,
		red_,
		green_,
		blue_);
	GraphicPrimitives::drawText2D(nbClicks, posX_, posY_, 0.7f, 0.0f, 0.0f);
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
	std::cout << "nb click : " << nbClick_ << std::endl;
}

float Square::getSide(){
	return side_;
}