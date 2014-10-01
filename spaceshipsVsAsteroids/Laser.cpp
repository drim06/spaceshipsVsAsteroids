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
	GraphicPrimitives::drawLine2D(
		posX_,
		posY_,
		posX_ - 0.5f,
		posY_ + 0.0f,
		red_,
		green_,
		blue_);
}

void Laser::tick(){
	posX_ += rapidity_;
}