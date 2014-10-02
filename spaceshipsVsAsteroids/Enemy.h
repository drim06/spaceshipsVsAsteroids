#pragma once

class Enemy // classe abstraite 
{
protected:
	float posX_, posY_;
	float rapidity_;
	int health_;
	float red_, green_, blue_;
	int rows_;
	float coeffReducteur_;

public: 
	virtual void draw() = 0;

	virtual void tick(){
		posX_ -= rapidity_;
	}

	virtual float getPosX(){
		return posX_;
	}

	virtual float getPosY(){
		return posY_;
	}

	virtual void receiveDamage(int x){
		health_ -= x;
	}

	virtual bool isAlive() const{
		return health_ > 0;
	}
};

