#include "Laser.h"


Laser::~Laser()
{
}

/*void Laser::draw(){
	float squarePosX = square_.getPosX();
	float squarePosY = square_.getPosY();
	float squareSide = square_.getSide();
	float weaponPosX = squarePosX + squareSide;
	float weaponPosY = squarePosY + squareSide / 2;
	GraphicPrimitives::drawLine2D(
		weaponPosX - squareSide / 4.f,
		weaponPosY + squareSide / 4.f,
		weaponPosX,
		weaponPosY,
		red_,
		green_,
		blue_);
}*/

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

bool Laser::isInScreen() const{
	//return posX_ < (-1.0 + 10 * squareSide_);
}

int Laser::getFrenquency() const{
	return frequency_;
}