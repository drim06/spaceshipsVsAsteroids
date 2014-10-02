
#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw(){
    
	// GameBoard
	for (int rows = 0; rows < square_->size(); rows++) {
		for (int columns = 0; columns < square_->size(); columns++){
			(*square_)[rows][columns].draw();
		}
	}

	// SpaceShips
	for (int i = 0; i < spaceShips_->size(); i++){
		(*spaceShips_)[i]->draw();
	}

	// Missiles
	for (int i = 0; i < missiles_->size(); i++){
		(*missiles_)[i]->draw();
	}

	// Enemies
	for (int i = 0; i < enemy_->size(); i++){
		(*enemy_)[i]->draw();
	}

	float squareSide = (f_.getWindowsHeight() - (f_.getWindowsHeight() / 7)) / (f_.getWindowsHeight() / 2.f) / 10.f;
}