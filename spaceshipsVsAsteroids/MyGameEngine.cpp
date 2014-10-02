
#include "MyGameEngine.h"


void MyGameEngine::idle(){
	if(tick % 2 == 0){
		for (int s = 0; s < spaceShips_->size(); s++){
			if (tick % (*missiles_)[s]->getFrenquency() == 0){
				missiles_->push_back(new Laser(0.0f, 0.0f));
				//missiles_->push_back(new Laser((*spaceShips_)[s]->getWeaponPosX(), (*spaceShips_)[s]->getWeaponPosY()));
			}
			/*for (int i = 0; i < missiles_->size(); i++){
				//if (tick % (*missiles_)[i]->getFrenquency() == 0){
					missiles_->push_back(new Laser(0.0f, 0.0f));
				//}
			}*/
		}
		for (int i = 0; i < missiles_->size(); i++){
			(*missiles_)[i]->tick();
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