
#include "MyControlEngine.h"
#include <cstdlib>


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
	float middleWidth = Engine::getWindowsWidth() / 2.0f;
	float middleHeight = Engine::getWindowsHeight() / 2.0f; // hey
	float posClickX = (x-middleWidth) / middleWidth; // compris entre -1.0f et 1.0f
	float posClickY = (y-middleHeight) / -middleHeight; // compris entre -1.0f et 1.0f
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        paps_->push_back(new Papillon(posClickX, posClickY,rand()%100/100.0f,rand()%100/100.0f,rand()%100/100.0f));
    } else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        fourmis_->push_back(new Fourmis(posClickX, posClickY));
    }
}