#include "SpaceCruiser.h"
#include <iostream>

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

void SpaceCruiser::cleanSquare(){
	square_.setIsOccuped(false);
	std::cout << "yeah" << std::endl;
}