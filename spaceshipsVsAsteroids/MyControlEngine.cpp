
#include "MyControlEngine.h"
#include <cstdlib>


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
	float middleWidth = f_.getWindowsWidth() / 2.0f;
	float middleHeight = f_.getWindowsHeight() / 2.0f;
	float posClickX = (x-middleWidth) / middleWidth; // compris entre -1.0f et 1.0f
	float posClickY = (y-middleHeight) / -middleHeight; // compris entre -1.0f et 1.0f
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        //paps_->push_back(new Papillon(posClickX, posClickY,rand()%100/100.0f,rand()%100/100.0f,rand()%100/100.0f));
		for (int i = 0; i < square_->size(); i++){
			std::cout << "elt numero :" << i << std::endl;
			std::cout << "is clicked? " << (*square_)[i]->isClicked(posClickX, posClickY) << posClickX << "/" << posClickY << "\n";
			if ((*square_)[i]->isClicked(posClickX, posClickY)){
				//(*square_)[i]->changeColor();
				(*square_)[i]->incrNbClick();
			}
		}
    } else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        fourmis_->push_back(new Fourmis(posClickX, posClickY));
    }
}