#include "Fourmis.h"

void Fourmis::draw(){
	GraphicPrimitives::drawFillTriangle2D(
		posX_, 
		posY_,
		posX_ - 0.06f, 
		posY_ - 0.18f,
		posX_ + 0.06f, 
		posY_ - 0.18,
		1.0f,
		0.0f,
		0.0f);
}

void Fourmis::tick(){

	// nouvelle abscisse point 1 (abscisse de la pointe du triangle)
	posX_ += vitesse_ * cos(direction_);
	if(posX_ > 1.0f || posX_ < -1.0f){
		posX_ -= vitesse_ * cos(direction_);
		if (cos(direction_) > 0 && sin(direction_) > 0) direction_ += M_PI / 2.f;
		else if (cos(direction_) > 0 && sin(direction_) < 0) direction_ -= M_PI / 2.f;
		else if (cos(direction_) < 0 && sin(direction_) < 0) direction_ += M_PI / 2.f;
		else if (cos(direction_) < 0 && sin(direction_) > 0) direction_ -= M_PI / 2.f;
	}

	// nouvelle ordonnée point 1 (ordonnée de la pointe du triangle)
	posY_ += vitesse_ * sin(direction_);
	if(posY_ > 1.0f || posY_ < -1.0f){
		posY_ -= vitesse_ * sin(direction_);
		if (cos(direction_) > 0 && sin(direction_) > 0) direction_ -= M_PI / 2.f;
		else if (cos(direction_) > 0 && sin(direction_) < 0) direction_ += M_PI / 2.f;
		else if (cos(direction_) < 0 && sin(direction_) < 0) direction_ -= M_PI / 2.f;
		else if (cos(direction_) < 0 && sin(direction_) > 0) direction_ += M_PI / 2.f;
	}
}

float Fourmis::getPosX() const{
	return posX_;
}

float Fourmis::getPosY() const{
	return posY_;
}