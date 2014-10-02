
#include "MyControlEngine.h"
#include <cstdlib>


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
	float middleWidth = dim_.getWindowsWidth() / 2.0f;
	float middleHeight = dim_.getWindowsHeight() / 2.0f;
	float posClickX = (x-middleWidth) / middleWidth; // compris entre -1.0f et 1.0f
	float posClickY = (y-middleHeight) / -middleHeight; // compris entre -1.0f et 1.0f
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		int indiceColumns = x / ((*square_)[0][0].getSide() * (dim_.getWindowsWidth() / 2));
		int indiceRows = y / ((*square_)[0][0].getSide() * (dim_.getWindowsHeight() / 2));
		if (indiceColumns < 10 && indiceRows < 10){ // si la case existe 
			(*square_)[indiceRows][indiceColumns].incrNbClick();
		}
		std::cout << "indiceX : " << indiceRows << std::endl;
		std::cout << "indiceY : " << indiceColumns << std::endl;
    } else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		int indiceColumns = x / ((*square_)[0][0].getSide() * (dim_.getWindowsWidth() / 2));
		int indiceRows = y / ((*square_)[0][0].getSide() * (dim_.getWindowsHeight() / 2));
		// si la case existe et qu'elle n'est pas occupée
		if (indiceColumns < 10 && indiceRows < 10 && !((*square_)[indiceRows][indiceColumns].isOccuped())){
			std::cout << "occuped :" << ((*square_)[indiceRows][indiceColumns].isOccuped()) << std::endl;
			spaceShips_->push_back(new SpaceCruiser((*square_)[indiceRows][indiceColumns]));
			(*square_)[indiceRows][indiceColumns].setIsOccuped(true);
			missiles_->push_back(new Laser((*square_)[indiceRows][indiceColumns].getPosX() + (*square_)[indiceRows][indiceColumns].getSide(), (*square_)[indiceRows][indiceColumns].getPosY() + (*square_)[indiceRows][indiceColumns].getSide()/2));
		}
		std::cout << "indiceX : " << indiceRows << std::endl;
		std::cout << "indiceY : " << indiceColumns << std::endl;
    }
}