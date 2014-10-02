#pragma once
class Missile
{
public:
	virtual void draw() = 0;
	virtual void tick() = 0;
	virtual int getFrenquency() const = 0;
};

