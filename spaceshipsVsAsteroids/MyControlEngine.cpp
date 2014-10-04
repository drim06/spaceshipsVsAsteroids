
#include "MyControlEngine.h"
#include <cstdlib>


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
	int indiceColumns = x / ((*square_)[0][0].getSide() * (f_.getWindowsWidth() / 2));
	int indiceRows = y / ((*square_)[0][0].getSide() * (f_.getWindowsHeight() / 2));
	float graphX = (x - (f_.getWindowsWidth() / 2.f)) / (f_.getWindowsWidth() / 2.f);
	float graphY = (y - (f_.getWindowsHeight() / 2.f)) / (-f_.getWindowsHeight() / 2.f);

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		if (graphX >= -0.87f && graphX <= -0.75f && graphY >= -0.96f && graphY <= -0.82f){
			player_.setSpaceShipSelected(1);
		}

		std::cout << "graphX : " << graphX << " graphY : " << graphY << std::endl;
		// click sur le bouton pour lancer la prochaine vague
		if (graphX > 0.8f && graphX < 0.8f + 0.1f
			&& graphY < -0.8f && graphY > -0.8 - 0.1f
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
			}
		}

	} else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		(*square_)[indiceRows][indiceColumns].incrNbClick();
		enemy_->push_back(new AsteroidFragment(indiceRows));

	} else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
		(*square_)[indiceRows][indiceColumns].incrNbClick();
		enemy_->push_back(new Asteroid(indiceRows));
	}
}