
#include "MyGameEngine.h"


void MyGameEngine::idle(){
	if (tick % 3 == 0){
		wave_.run(tick, enemy_);
		
		for (int i = 0; i < spaceShips_->size(); i++){
			if ((*spaceShips_)[i]->canShoot(tick)){
				switch ((*spaceShips_)[i]->getSpaceShipValue()){
				case 1:
					missiles_->push_back(new Laser((*spaceShips_)[i]->getWeaponPosX(), (*spaceShips_)[i]->getWeaponPosY()));
					break;
				case 2:
					missiles_->push_back(new Needle((*spaceShips_)[i]->getWeaponPosX(), (*spaceShips_)[i]->getWeaponPosY()));
					break;
				case 3:
					missiles_->push_back(new RapidFire((*spaceShips_)[i]->getWeaponPosX(), (*spaceShips_)[i]->getWeaponPosY(), 1, 0.f));
					missiles_->push_back(new RapidFire((*spaceShips_)[i]->getWeaponPosX(), (*spaceShips_)[i]->getWeaponPosY(), 1, 0.5f));
					missiles_->push_back(new RapidFire((*spaceShips_)[i]->getWeaponPosX(), (*spaceShips_)[i]->getWeaponPosY(), 1, -0.5f));
					break;
				}
			}
			for (int j = 0; j < enemy_->size(); j++){ // supprime spaceship lors de collision avec enemy
				if ((*spaceShips_)[i] != nullptr && (*enemy_)[j] != nullptr){
					if ((*enemy_)[j]->hit(*(*spaceShips_)[i])){
						(*spaceShips_)[i]->cleanSquare();
						delete (*spaceShips_)[i];
						(*spaceShips_)[i] = nullptr;
						(*spaceShips_).erase((*spaceShips_).begin() + i);
					}
				}
			}
		}
		for (int i = 0; i < missiles_->size(); i++){ // supprime les missiles qui sortent du GameBoard 
			(*missiles_)[i]->tick();
			if ((*missiles_)[i]->getPosX() >= 0.67f 
				|| (*missiles_)[i]->getPosX() <= -1.1f
				|| (*missiles_)[i]->getPosY() >= 1.f 
				|| (*missiles_)[i]->getPosY() <= -0.72f){
				delete (*missiles_)[i];
				(*missiles_)[i] = nullptr;
				(*missiles_).erase((*missiles_).begin() + i);
			}
			for (int j = 0; j < enemy_->size(); j++){ // supprime les missiles/ennemis lors d'une collision
				if ((*missiles_)[i] != nullptr){
					if ((*missiles_)[i]->hit(*(*enemy_)[j])){
						(*missiles_)[i]->dealDamage(*(*enemy_)[j]);
						if (!(*enemy_)[j]->isAlive()){ // s'il ne reste plus de vie à l'ennemi on le supprime du GameBoard
							player_.earnMoney((*enemy_)[j]->getDropMoney());
							delete (*enemy_)[j];
							(*enemy_)[j] = nullptr;
							(*enemy_).erase((*enemy_).begin() + j);
						}
						delete (*missiles_)[i];
						(*missiles_)[i] = nullptr;
						(*missiles_).erase((*missiles_).begin() + i);
					}
				}
			}
		}
		for (int i = 0; i < enemy_->size(); i++){	// supprime les ennemis qui sortent du GameBoard
			(*enemy_)[i]->tick();
			if ((*enemy_)[i]->getPosX() <= -1.15f){
				(*enemy_)[i]->dealDamageToPlayer(player_);
				delete (*enemy_)[i];
				(*enemy_)[i] = nullptr;
				(*enemy_).erase((*enemy_).begin() + i);
			}
		}

	}
	tick++;
}