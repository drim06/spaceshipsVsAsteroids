#include "AsteroidShyro.h"
#include "GraphicPrimitives.h"

void AsteroidShyro::draw(){

	GraphicPrimitives::drawFillRect2D(
		posX_,
		posY_ - height_ / 2,
		width_,
		height_,
		red_,
		green_,
		blue_);
	GraphicPrimitives::drawFillRect2D(
		posX_,
		posY_ - 0.05f,
		height_ / 2,
		width_ - 0.03f,
		red_,
		green_,
		blue_);
}

bool AsteroidShyro::hit(SpaceShip& spaceShip){
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
	bottomB = spaceShip.getWeaponPosY() - 0.15f;

	// tests de non collision
	if (bottomA >= topB) return false;
	if (topA <= bottomB) return false;
	if (rightA <= leftB) return false;
	if (leftA >= rightB) return false;

	// alors il y a eu collision
	return true;
}

void AsteroidShyro::shrink(){
	coeffReducteur_ += 0.01f;
}
