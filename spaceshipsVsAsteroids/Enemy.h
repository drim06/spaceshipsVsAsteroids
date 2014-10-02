#pragma once

class Enemy // classe abstraite 
{
public: 
	virtual void draw() = 0;
	virtual void tick() = 0;
};

