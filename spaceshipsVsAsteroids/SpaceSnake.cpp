#include "SpaceSnake.h"
#include <iostream>

void SpaceSnake::draw(){
	float squarePosX = square_.getPosX();
	float squarePosY = square_.getPosY();
	float squareSide = square_.getSide();
	GraphicPrimitives::drawFillRect2D(
		squarePosX + 0.0858335f - 0.01f,
		squarePosY,
		0.02f,
		0.171667,
		red_,
		green_,
		blue_);
	GraphicPrimitives::drawFillRect2D(
		squarePosX,
		squarePosY + 0.0858335f - 0.01f,
		0.171667,
		0.02f,
		red_,
		green_,
		blue_);
	GraphicPrimitives::drawFillRect2D(
		squarePosX + 0.06f,
		squarePosY + 0.06f,
		0.05f,
		0.05f,
		red_,
		green_,
		blue_);
}

void SpaceSnake::cleanSquare(){
	square_.setIsOccuped(false);
}