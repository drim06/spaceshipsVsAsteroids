#pragma once
#include "GraphicPrimitives.h"
#include <cmath>
#include <cstdlib>
#define M_PI           3.14159265358979323846  /* pi */

class Fourmis{
	float posX_, posY_;
	float vitesse_;
	float direction_;

public:
	Fourmis(float posX, float posY):
		posX_(posX),
		posY_(posY),
		vitesse_(0.01f),
		direction_(M_PI/4.f){}

	void draw();
	void tick();

	float getPosX() const;
	float getPosY() const;
};