#include "Asteroid.h"

void Asteroid::draw(){
	std::vector<float> x;
	std::vector<float> y;

	// x values
	x.push_back(posX_);
	x.push_back((posX_ + 0.035f));
	x.push_back((posX_ + 0.07f));
	x.push_back((posX_ + 0.035f));
	x.push_back((posX_ + 0.14f));
	x.push_back((posX_ + 0.07f));

	// y values
	y.push_back(posY_);
	y.push_back(posY_ + 0.035f);
	y.push_back(posY_ + 0.07f);
	y.push_back(posY_ + 0.035f);
	y.push_back(posY_);
	y.push_back(posY_ - 0.07f);

	GraphicPrimitives::drawFillPolygone2D(
		x,
		y,
		red_,
		green_,
		blue_);
}

bool Asteroid::hit(SpaceShip& spaceShip){
	// cotés des hitbox A et B
	float leftA, leftB;
	float rightA, rightB;
	float topA, topB;
	float bottomA, bottomB;

	// calcul des cotés de la hitbox A
	leftA = posX_;
	rightA = posX_ + 0.24f;
	topA = posY_;
	bottomA = posY_ - 0.07f;

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