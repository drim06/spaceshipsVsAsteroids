#pragma once

class Enemy // classe abstraite 
{
public: 
	virtual void draw() = 0;
	virtual void tick() = 0;
	virtual float getPosX() const = 0;
	virtual float getPosY() const = 0;
	virtual void receiveDamage(int) = 0;
	virtual bool isAlive() const = 0;
};

