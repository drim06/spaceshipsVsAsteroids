
#include "MyGameEngine.h"


void MyGameEngine::idle(){
	if(tick % 2 == 0){
		for (int s = 0; s < spaceShips_->size(); s++){
			if ((*spaceShips_)[s]->canShoot(tick)){
				missiles_->push_back(new Laser((*spaceShips_)[s]->getWeaponPosX(), (*spaceShips_)[s]->getWeaponPosY()));
				// plus tard fair un switch case avec pour chaque type
				// de vaisseau, le missile correspondant
			}
		}
		for (int i = 0; i < missiles_->size(); i++){
			(*missiles_)[i]->tick();
		}
		for (int i = 0; i < enemy_->size(); i++){
			(*enemy_)[i]->tick();
		}
	}
	tick++;
}

/*void MyGameEngine::idle(){
	if (tick % 30 == 0){
		/*for (int i = 0; i < paps_->size(); i++) {
		(*paps_)[i]->tick();
		for (int j = 0; j < fourmis_->size(); j++){
		if ((*paps_)[i]->hit(*(*fourmis_)[j])){
		delete (*fourmis_)[j];							// on désalloue la mémoire
		(*fourmis_).erase((*fourmis_).begin() + j);		// on supprime la fourmis
		}
		}
		}*/
		/*for (int i = 0; i < fourmis_->size(); i++) {
		(*fourmis_)[i]->tick();
		}*/
		/*for (int i = 0; i < missiles_->size(); i++){
			(*missiles_)[i]->tick();
		}
	}
	tick++;
}*/