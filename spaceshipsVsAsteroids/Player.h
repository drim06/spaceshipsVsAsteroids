#pragma once

class Player
{
private:
	unsigned int money_, health_;
	int spaceShipSelected_ ;

public:
	Player() :
		money_(150),
		health_(100),
		spaceShipSelected_(0)
	{}

	inline int getMoney() const{
		return money_;
	}

	inline int getHealth() const{
		return health_;
	}

	void loseMoney(unsigned int);
	void loseHealth(unsigned int);
	void earnMoney(int);
	int getSpaceShipSelected() const;
	void setSpaceShipSelected(int);
	void earnHealth(int);
};

