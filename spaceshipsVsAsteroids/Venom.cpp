#include "Venom.h"

void Venom::draw(){
	GraphicPrimitives::drawFillRect2D(
		posX_,
		posY_,
		width_,
		height_,
		red_,
		green_,
		blue_);
}

void Venom::tick(){
	posX_ += rapidity_ * vectX_;
	posY_ += rapidity_ * vectY_;
}

bool Venom::hit(Enemy& enemy){
	// cotés des hitbox A et B
	float leftA, leftB;
	float rightA, rightB;
	float topA, topB;
	float bottomA, bottomB;

	// calcul des cotés de la hitbox A
	leftA = posX_ - 0.12f;
	rightA = posX_ + width_;
	topA = posY_ + height_ + 0.05f;
	bottomA = posY_ - 0.05f;

	// calcul des cotés de la hitbox B
	leftB = enemy.getPosX();
	rightB = enemy.getPosX();
	topB = enemy.getPosY();
	bottomB = enemy.getPosY();

	// tests de non collision
	if (bottomA >= topB) return false;
	if (topA <= bottomB) return false;
	if (rightA <= leftB) return false;
	if (leftA >= rightB) return false;

	// alors il y a eu collision
	return true;
}