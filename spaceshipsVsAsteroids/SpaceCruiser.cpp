#include "SpaceCruiser.h"
#include <iostream>

SpaceCruiser::~SpaceCruiser()
{
}

void SpaceCruiser::draw(){
	float squarePosX = square_.getPosX();
	float squarePosY = square_.getPosY();
	float squareSide = square_.getSide();
	GraphicPrimitives::drawFillTriangle2D(
		squarePosX + squareSide,
		squarePosY + squareSide / 2,
		squarePosX + squareSide - (squareSide * 0.7f),
		squarePosY + squareSide / 2 + (squareSide / 3),
		squarePosX + squareSide - (squareSide * 0.7f),
		squarePosY + squareSide / 2 - (squareSide / 3),
		red_,
		green_,
		blue_);
}

float SpaceCruiser::getWeaponPosX() const{
	return weaponPosX_;
}

float SpaceCruiser::getWeaponPosY() const{
	return weaponPosY_;
}

bool SpaceCruiser::canShoot(const int& x) const{
	return x % frequency_ == 0;
}