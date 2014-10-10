#pragma once
#include "GraphicPrimitives.h"
#include "utility.h"

class Player
{
private:
	unsigned int money_, health_, score_;
	int spaceShipSelected_ ;
	char * roundTxt_;
	char * healthTxt_;
	char * moneyTxt_;
	char * scoreTxt_;
	float rValue, gValue, yValue;

public:
	Player() :
		money_(150),
		score_(0),
		health_(100),
		spaceShipSelected_(0),
		roundTxt_(new char[3]),
		healthTxt_(new char[4]),
		moneyTxt_(new char[7]),
		scoreTxt_(new char[10]),
		yValue(0.1f * health_ / 100.f),
	    rValue((100 - health_) / 100.f),
	    gValue(health_ / 100.f)
	{}

	inline int getMoney() const{
		return money_;
	}

	inline int getHealth() const{
		return health_;
	}

	inline char* getRoundTxt() const{
		return roundTxt_;
	}

	inline char* getHealthTxt() const{
		return healthTxt_;
	}

	inline char* getMoneyTxt() const{
		return moneyTxt_;
	}

	inline int getScore() const{
		return score_;
	}

	inline char* getScoreTxt() const{
		return scoreTxt_;
	}

	inline void drawCurrentHealth(){
		GraphicPrimitives::drawText2D("Health", 0.75f, 0.65, 0.9f, 0.9f, 0.9f);
		GraphicPrimitives::drawFillRect2D(0.75f, 0.5f, 0.1f, 0.1f, 1.f, 1.f, 1.f);
		yValue = 0.1f * health_ / 100.f;
		rValue = (100 - health_) / 100.f;
		gValue = health_ / 100.f;
		GraphicPrimitives::drawFillRect2D(0.75f, 0.5f, 0.1f, yValue, rValue, gValue, 0.f);
		utility::itoa(health_, getHealthTxt());
		GraphicPrimitives::drawText2D(getHealthTxt(), 0.9f, 0.53f, rValue, gValue, 0.f);
		if (getHealth() <= 0){
			GraphicPrimitives::drawText2D("   GAME OVER", 0.1f, -0.84f, 0.0f, 1.0f, 0.0f);
			GraphicPrimitives::drawText2D("   Click to try again", 0.07f, -0.94f, 0.0f, 1.0f, 0.0f);
		}
	}

	inline void drawCurrentMoney(){
		utility::itoa(getMoney(), getMoneyTxt());
		GraphicPrimitives::drawText2D("Money", 0.75f, 0.25f, 0.9f, 0.9f, 0.9f);
		GraphicPrimitives::drawText2D("$", 0.75f, 0.15f, 1.f, 0.8f, 0.f);
		GraphicPrimitives::drawText2D(getMoneyTxt(), 0.79f, 0.15f, 1.f, 0.8f, 0.f);
	}

	inline void drawCurrentScore(){
		utility::itoa(getScore(), getScoreTxt());
		GraphicPrimitives::drawText2D("Score", 0.75f, -0.15f, 0.9f, 0.9f, 0.9f);
		GraphicPrimitives::drawText2D(getScoreTxt(), 0.75f, -0.25f, 0.9f, 0.9f, 0.9f);
	}

	void loseMoney(unsigned int);
	void loseHealth(unsigned int);
	void earnMoney(int);
	void earnScore(int);
	int getSpaceShipSelected() const;
	void setSpaceShipSelected(int);
	void earnHealth(int);
	void init();
};

