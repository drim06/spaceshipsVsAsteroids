#include "SpaceFalcon.h"


void SpaceFalcon::draw(){
	float squarePosX = square_.getPosX();
	float squarePosY = square_.getPosY();
	float squareSide = square_.getSide();
	GraphicPrimitives::drawFillTriangle2D(
		squarePosX + squareSide - 0.035f,
		squarePosY + squareSide / 2,
		squarePosX + squareSide - (squareSide * 0.7f) - 0.035f,
		squarePosY + squareSide / 2 + (squareSide / 3),
		squarePosX + squareSide - (squareSide * 0.7f) - 0.035f,
		squarePosY + squareSide / 2 - (squareSide / 3),
		red_,
		green_,
		blue_+ 0.7);
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