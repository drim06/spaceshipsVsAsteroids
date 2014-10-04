#pragma once
class Player
{
private:
	unsigned int money_, health_;
public:
	Player() :
		money_(150),
		health_(100)
	{}

	inline int getMoney() const{
		return money_;
	}

	inline int getHealth() const{
		return health_;
	}

	void loseMoney(int x){
		if (x > money_){
			money_ = 0;
		}
		else {
			money_ -= x;
		}
	}

	void loseHealth(int x){
		if (x > health_){
			health_ = 0;
		}
		else {
			health_ -= x;
		}
		std::cout << "health : " << health_ << std::endl;
	}

	void earnMoney(int x){
		money_ += x;
	}
};

