
#include "MyControlEngine.h"
#include <cstdlib>


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
	int indiceColumns = x / ((*square_)[0][0].getSide() * (f_.getWindowsWidth() / 2));
	int indiceRows = y / ((*square_)[0][0].getSide() * (f_.getWindowsHeight() / 2));

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (indiceColumns < 10 && indiceRows < 10){ // si la case existe 
			(*square_)[indiceRows][indiceColumns].incrNbClick();
			enemy_->push_back(new Asteroid(0));
		}
	} else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		// si la case existe et qu'elle n'est pas occupée
		if (indiceColumns < 10 && indiceRows < 10 && !((*square_)[indiceRows][indiceColumns].isOccuped())){
			spaceShips_->push_back(new SpaceCruiser((*square_)[indiceRows][indiceColumns]));
			(*square_)[indiceRows][indiceColumns].setIsOccuped(true);
		}
    }
}