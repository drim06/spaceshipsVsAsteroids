#pragma once

class Player
{
private:
	unsigned int money_, health_;
	int spaceShipSelected_ ;
	char * roundTxt_;
	char * healthTxt_;
	char * moneyTxt_;

public:
	Player() :
		money_(150),
		health_(100),
		spaceShipSelected_(0),
		roundTxt_(new char[3]),
		healthTxt_(new char[4]),
		moneyTxt_(new char[7])
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

	void loseMoney(unsigned int);
	void loseHealth(unsigned int);
	void earnMoney(int);
	int getSpaceShipSelected() const;
	void setSpaceShipSelected(int);
	void earnHealth(int);
};

