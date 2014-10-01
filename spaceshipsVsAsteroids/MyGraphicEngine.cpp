
#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw(){
    
    char* nbPaps = new char[100];
    utility::itoa(paps_->size(), nbPaps);
    //GraphicPrimitives::drawText2D(str,-1.0f,0.9f,0.0f,0.0f, 1.0f);
    //GraphicPrimitives::drawText2D("Papillons : " ,-1.0f,-0.9f,0.0f,0.0f, 1.0f);
    //GraphicPrimitives::drawText2D(nbPaps ,-0.78f,-0.9f,0.0f,0.0f, 1.0f);
	//GraphicPrimitives::drawFillRect2D(0, 0, (Engine::getWindowsWidth() - 400) / 400.f / 5.f, (Engine::getWindowsHeight() - 300) / -300.f / 5.f, 0, 0, 1);
	//std::cout << "width :" << (Engine::getWindowsWidth() - 400) / 400.f / 5.f << "height :" << (Engine::getWindowsHeight() - 300) / -300.f / 5.f << std::endl;
	
	for (int rows = 0; rows < square_->size(); rows++) {
		for (int columns = 0; columns < square_->size(); columns++){
			(*square_)[rows][columns].draw();
		}
	}

	for (int i = 0; i < spaceShips_->size(); i++){
		(*spaceShips_)[i]->draw();
	}

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