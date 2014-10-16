#pragma once
#include "GraphicPrimitives.h"
#include <ctime>
#include <cstdlib>

class Square
{
private:
	float posX_, posY_, side_;
	float red_, green_, blue_;
	bool occuped_;

public:
	Square(float posX, float posY, float side, float red, float green, float blue) :
		posX_(posX),
		posY_(posY),
		side_(side),
		red_(red),
		green_(green),
		blue_(blue),
		occuped_(false)
	{}

	void draw();
	void tick();
	bool isClicked(float&, float&);
	void changeColor();
	float getSide() const;
	float getPosX() const;
	float getPosY() const;
	bool isOccuped() const;
	void setIsOccuped(bool);
	void setColor(float);
};

