#include "RandomBox.h"

void RandomBox::draw(){
	GraphicPrimitives::drawFillRect2D(
		posX_,
		posY_,
		width_,
		height_,
		red_,
		green_,
		blue_);
}

void RandomBox::tick(){
	posX_ += rapidity_ * vectX_;
	posY_ += rapidity_ * vectY_;
}

bool RandomBox::hit(Enemy& enemy){
	// cotés des hitbox A et B
	float leftA, leftB;
	float rightA, rightB;
	float topA, topB;
	float bottomA, bottomB;

	// calcul des cotés de la hitbox A
	leftA = posX_;
	rightA = posX_ + width_;
	topA = posY_ + height_;
	bottomA = posY_;

	// calcul des cotés de la hitbox B
	leftB = enemy.getPosX();
	rightB = enemy.getPosX();
	topB = enemy.getPosY() + 0.1f;
	bottomB = enemy.getPosY() - 0.1f;

	// tests de non collision
	if (bottomA >= topB) return false;
	if (topA <= bottomB) return false;
	if (rightA <= leftB) return false;
	if (leftA >= rightB) return false;

	// alors il y a eu collision
	return true;
}