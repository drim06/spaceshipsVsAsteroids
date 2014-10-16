#include "AsteroidFragment.h"
#include "GraphicPrimitives.h"

void AsteroidFragment::draw(){

	GraphicPrimitives::drawFillRect2D(
		posX_,
		posY_,
		width_,
		height_,
		red_,
		green_,
		blue_);

	GraphicPrimitives::drawFillRect2D(
		posX_ + width_/2 - height_/2,
		posY_ - width_/2,
		height_,
		width_,
		red_,
		green_,
		blue_);
}

bool AsteroidFragment::hit(SpaceShip& spaceShip){
	// cotés des hitbox A et B
	float leftA, leftB;
	float rightA, rightB;
	float topA, topB;
	float bottomA, bottomB;

	// calcul des cotés de la hitbox A
	leftA = posX_ + width_ / 2 - height_ / 2;
	rightA = posX_ + width_ + 0.1;
	topA = posY_ - width_ / 2 + height_;
	bottomA = posY_ - width_ / 2;

	// calcul des cotés de la hitbox B
	leftB = spaceShip.getWeaponPosX();
	rightB = spaceShip.getWeaponPosX();
	topB = spaceShip.getWeaponPosY() + 0.1f;
	bottomB = spaceShip.getWeaponPosY() - 0.1f;

	// tests de non collision
	if (bottomA >= topB) return false;
	if (topA <= bottomB) return false;
	if (rightA <= leftB) return false;
	if (leftA >= rightB) return false;

	// alors il y a eu collision
	return true;
}