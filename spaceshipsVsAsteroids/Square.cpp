#include "Square.h"
#include <cstdlib>
#include "MyGraphicEngine.h"

void Square::draw(){
	char* nbClicks = new char[100];
	itoa(nbClick_, nbClicks);
	
	GraphicPrimitives::drawFillRect2D(
		posX_,
		posY_,
		side_,
		side_,
		red_,
		green_,
		blue_);
	GraphicPrimitives::drawText2D(nbClicks, posX_, posY_, 0.0f, 0.0f, 1.0f);
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

char* Square::itoa(int val, char* c){
	int i = 0;
	do{
		c[i] = val % 10 + '0';
		val /= 10;
		i++;
	} while (val);
	c[i] = '\0';
	return reverse(c);
}

char* Square::reverse(char* c){
	char tmp;
	int size = strlen(c);
	for (int i = 0; i < size / 2; i++){
		tmp = c[i];
		c[i] = c[size - 1 - i];
		c[size - 1 - i] = tmp;
	}
	return c;
}