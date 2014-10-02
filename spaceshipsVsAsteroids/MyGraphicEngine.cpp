
#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw(){
    
    char* nbPaps = new char[100];
    utility::itoa(paps_->size(), nbPaps);
	
	// Plateau de jeu 
	for (int rows = 0; rows < square_->size(); rows++) {
		for (int columns = 0; columns < square_->size(); columns++){
			(*square_)[rows][columns].draw();
		}
	}

	// Vaisseaux
	for (int i = 0; i < spaceShips_->size(); i++){
		(*spaceShips_)[i]->draw();
	}

	// Missiles
	for (int i = 0; i < missiles_->size(); i++){
		(*missiles_)[i]->draw();
	}

	float squareSide = (dim_.getWindowsHeight() - (dim_.getWindowsHeight() / 7)) / (dim_.getWindowsHeight() / 2.f) / 10.f;
	GraphicPrimitives::drawFillRect2D(-1.0 + 10*squareSide, -1.0f, squareSide*2, 2.0f, 0.1, 0.1, 0.1);

    for (int i = 0; i < paps_->size(); i++) {
        (*paps_)[i]->draw();
    }
    for (int i = 0; i < fourmis_->size(); i++) {
        (*fourmis_)[i]->draw();
    }
}