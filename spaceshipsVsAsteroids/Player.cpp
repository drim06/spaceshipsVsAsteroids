#include "Player.h"

void Player::loseMoney(unsigned int x){
	if (x > money_){
		money_ = 0;
	}
	else {
		money_ -= x;
	}
}

void Player::loseHealth(unsigned int x){
	if (x > health_){
		health_ = 0;
	}
	else {
		health_ -= x;
	}
}

void Player::earnMoney(int x){
	money_ += x;
}

int Player::getSpaceShipSelected() const{
	return spaceShipSelected_;
}

void Player::setSpaceShipSelected(int x){
	spaceShipSelected_ = x;
}