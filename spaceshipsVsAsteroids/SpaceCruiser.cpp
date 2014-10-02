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

float SpaceCruiser::getWeaponPosX(){
	return weaponPosX_;
}

float SpaceCruiser::getWeaponPosY(){
	return weaponPosY_;
}