#pragma once
class Missile
{
public:
	virtual void draw() = 0;
	virtual void tick() = 0;
	virtual float getPosX() const = 0;
};

