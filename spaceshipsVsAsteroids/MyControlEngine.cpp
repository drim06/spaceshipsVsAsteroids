
#include "MyControlEngine.h"
#include <cstdlib>


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
	int indiceColumns = x / ((*square_)[0][0].getSide() * (f_.getWindowsWidth() / 2));
	int indiceRows = y / ((*square_)[0][0].getSide() * (f_.getWindowsHeight() / 2));
	float graphX = (x - (f_.getWindowsWidth() / 2.f)) / (f_.getWindowsWidth() / 2.f);
	float graphY = (y - (f_.getWindowsHeight() / 2.f)) / (-f_.getWindowsHeight() / 2.f);
	float sideSquare = (*square_)[0][0].getSide();

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && player_.getHealth() > 0){

		// si c'est une case vide du GameBoard, on créé le vaisseau sélectionné
		if (indiceColumns < 10 && indiceRows < 10 && !((*square_)[indiceRows][indiceColumns].isOccuped())){
			switch (player_.getSpaceShipSelected()){
			case 0:
				// do nothing
				break;
			case 1:
				if (player_.getMoney() >= 40){
					spaceShips_->push_back(new SpaceCruiser((*square_)[indiceRows][indiceColumns], player_));
					(*square_)[indiceRows][indiceColumns].setIsOccuped(true);
				}
				break;
			case 2:
				if (player_.getMoney() >= 75){
					spaceShips_->push_back(new SpaceFalcon((*square_)[indiceRows][indiceColumns], player_));
					(*square_)[indiceRows][indiceColumns].setIsOccuped(true);
				}
				break;
			case 3:
				if (player_.getMoney() >= 200){
					spaceShips_->push_back(new SpaceTroy((*square_)[indiceRows][indiceColumns], player_));
					(*square_)[indiceRows][indiceColumns].setIsOccuped(true);
				}
				break;
			case 4:
				if (player_.getMoney() >= 400){
					spaceShips_->push_back(new SpaceSnake((*square_)[indiceRows][indiceColumns], player_));
					(*square_)[indiceRows][indiceColumns].setIsOccuped(true);
				}
				break;
			}
		}
		// gestion click sur le bouton Go
		else if (graphX <= 0.9f && graphX >= 0.78f && graphY >= -0.91f && graphY <= -0.79f && !wave_.getIsLaunched()){
			wave_.nextWave();
		} 
		else {
			// permet de colorer en blanc la case selectionnée dans le shop
			player_.setSpaceShipSelected(0);
			for (int i = 0; i < (int) (shopShip_)->size(); i++){
				if (graphX >= (*shopShip_)[i].getPosX()
					&& graphX <= (*shopShip_)[i].getPosX() + sideSquare
					&& graphY >= (*shopShip_)[i].getPosY()
					&& graphY <= (*shopShip_)[i].getPosY() + sideSquare){
					player_.setSpaceShipSelected(i + 1);
					(*shopShip_)[i].setColor(1.0f);
				}
				else {
					(*shopShip_)[i].setColor(0.0f);
				}
			}
		}

	}

	else if (player_.getHealth() <= 0){
		// On réinitialise les données du jeu pour une nouvelle partie
		for (int i = 0; i < (int) missiles_->size(); i++){
			delete (*missiles_)[i];
			(*missiles_)[i] = nullptr;
		}
		(*missiles_).clear();
		for (int i = 0; i < (int) spaceShips_->size(); i++){
			(*spaceShips_)[i]->cleanSquare();
			delete (*spaceShips_)[i];
			(*spaceShips_)[i] = nullptr;
		}
		(*spaceShips_).clear();
		for (int i = 0; i < (int) enemy_->size(); i++){
			delete (*enemy_)[i];
			(*enemy_)[i] = nullptr;
		}
		for (int i = 0; i < (int) shopShip_->size(); i++){
			(*shopShip_)[i].setColor(0.0f);
		}
		(*enemy_).clear();
		player_.init();
		wave_.init();
	}

	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		// click droit sur un vaisseau => supprime le vaisseau
		if (indiceColumns < 10 && indiceRows < 10 && (*square_)[indiceRows][indiceColumns].isOccuped()){
			for (int i = 0; i < (int) spaceShips_->size(); i++){
				if ((*spaceShips_)[i]->getWeaponPosX() >= graphX && ((*spaceShips_)[i]->getWeaponPosX() - sideSquare) <= graphX
					&& ((*spaceShips_)[i]->getWeaponPosY() + sideSquare / 2) >= graphY && ((*spaceShips_)[i]->getWeaponPosY() - sideSquare / 2) <= graphY){
					player_.earnMoney((*spaceShips_)[i]->getCost()/2);
					(*spaceShips_)[i]->cleanSquare();
					delete (*spaceShips_)[i];
					(*spaceShips_)[i] = nullptr;
					(*spaceShips_).erase((*spaceShips_).begin() + i);
				}
			}
		}

	}
}