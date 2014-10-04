
#include "MyControlEngine.h"
#include <cstdlib>


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
	int indiceColumns = x / ((*square_)[0][0].getSide() * (f_.getWindowsWidth() / 2));
	int indiceRows = y / ((*square_)[0][0].getSide() * (f_.getWindowsHeight() / 2));
	float graphX = (x - (f_.getWindowsWidth() / 2.f)) / (f_.getWindowsWidth() / 2.f);
	float graphY = (y - (f_.getWindowsHeight() / 2.f)) / (-f_.getWindowsHeight() / 2.f);

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		float side = 0.1f;
		std::cout << "graphX : " << graphX << " graphY : " << graphY << std::endl;
		if (graphX > 0.8f && graphX < 0.8f + side
			&& graphY < -0.8f && graphY > -0.8 - side
			&& !wave_.getIsLaunched()){
			wave_.nextWave();
			// effacer le bouton
		}
	}

	if (indiceColumns < 10 && indiceRows < 10){		// si c'est une case du GameBoard

		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (!((*square_)[indiceRows][indiceColumns].isOccuped())){
				spaceShips_->push_back(new SpaceCruiser((*square_)[indiceRows][indiceColumns]));
				(*square_)[indiceRows][indiceColumns].setIsOccuped(true);
			}

		} else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
			(*square_)[indiceRows][indiceColumns].incrNbClick();
			enemy_->push_back(new Asteroid(indiceRows));

		} else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
			(*square_)[indiceRows][indiceColumns].incrNbClick();
			enemy_->push_back(new Asteroid(indiceRows));
		}
	}
}