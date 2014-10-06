
#include "MyControlEngine.h"
#include <cstdlib>


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
	int indiceColumns = x / ((*square_)[0][0].getSide() * (f_.getWindowsWidth() / 2));
	int indiceRows = y / ((*square_)[0][0].getSide() * (f_.getWindowsHeight() / 2));
	float graphX = (x - (f_.getWindowsWidth() / 2.f)) / (f_.getWindowsWidth() / 2.f);
	float graphY = (y - (f_.getWindowsHeight() / 2.f)) / (-f_.getWindowsHeight() / 2.f);
	float sideSquare = (*square_)[0][0].getSide();

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && player_.getHealth() > 0){
		if (graphX >= -0.87f && graphX <= -0.75f && graphY >= -0.96f && graphY <= -0.77f){
			player_.setSpaceShipSelected(1);
		}
		else if (graphX >= -0.72f && graphX <= -0.6f && graphY >= -0.96f && graphY <= -0.77f){
			player_.setSpaceShipSelected(2);
		}
		else if (graphX >= -0.57f && graphX <= -0.45f && graphY >= -0.96f && graphY <= -0.77f){
			player_.setSpaceShipSelected(3);
		}

		// click sur le bouton pour lancer la prochaine vague
		if (graphX > 0.78f && graphX < 0.9f
			&& graphY < -0.78f && graphY > -0.91f
			&& !wave_.getIsLaunched()){
			wave_.nextWave();
		}

		// si c'est une case vide du GameBoard 
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
				if (player_.getMoney() >= 150){
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

	}

	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && player_.getHealth() <= 0){
		// do nothing
	}

	// click droit sur un vaisseau => supprime le vaisseau
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		if (indiceColumns < 10 && indiceRows < 10 && (*square_)[indiceRows][indiceColumns].isOccuped()){
			for (int i = 0; i < spaceShips_->size(); i++){
				if ((*spaceShips_)[i]->getWeaponPosX() >= graphX && ((*spaceShips_)[i]->getWeaponPosX() - sideSquare) <= graphX
					&& ((*spaceShips_)[i]->getWeaponPosY() + sideSquare / 2) >= graphY && ((*spaceShips_)[i]->getWeaponPosY() - sideSquare / 2) <= graphY){
					(*spaceShips_)[i]->cleanSquare();
					delete (*spaceShips_)[i];
					(*spaceShips_)[i] = nullptr;
					(*spaceShips_).erase((*spaceShips_).begin() + i);
				}
			}
		}

	}
	else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
		(*square_)[indiceRows][indiceColumns].incrNbClick();
		enemy_->push_back(new Asteroid(indiceRows));
		player_.earnMoney(1000);
	}
}