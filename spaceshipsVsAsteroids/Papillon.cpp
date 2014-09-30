
#include "Papillon.h"
#include <cstdlib>

void Papillon::draw(){
    GraphicPrimitives::drawFillRect2D(
        posX_,
        posY_,
        width_,
        height_,
        red_,
        green_,
        blue_);
}

void Papillon::tick(){
    posX_ += VposX_;
    if (posX_ > 1.0f - height_ || posX_ < -1.0f) {
        VposX_ = -VposX_;
        posX_ += VposX_;
    }
    
    posY_ += VposY_;
    if (posY_ > 1.0f - width_ || posY_ < -1.0f) {
        VposY_ = -VposY_;
        posY_ += VposY_;
    }
    
    width_ += Vwidth_;
    if (width_ > 0.4f || width_ < 0.05) {
        Vwidth_ = - Vwidth_;
        width_ += Vwidth_;
    }
    
    height_ += Vheight_;
    if (height_ > 0.2f || height_ < 0.02) {
        Vheight_ = - Vheight_;
        height_ += Vheight_;
    }
}

bool Papillon::hit(const Fourmis& fourmis){
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
	leftB = fourmis.getPosX() - 0.06f;
	rightB = fourmis.getPosX() + 0.06f;
	topB = fourmis.getPosY();
	bottomB = fourmis.getPosY() - 0.18f;

	// tests de non collision
	if (bottomA >= topB) return false;
	if (topA <= bottomB) return false;
	if (rightA <= leftB) return false;
	if (leftA >= rightB) return false;

	// alors il y a eu collision
	return true;
}