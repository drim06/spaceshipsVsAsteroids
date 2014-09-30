
#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw(){
    
    char* nbPaps = new char[100];
    utility::itoa(paps_->size(), nbPaps);
    //GraphicPrimitives::drawText2D(str,-1.0f,0.9f,0.0f,0.0f, 1.0f);
    //GraphicPrimitives::drawText2D("Papillons : " ,-1.0f,-0.9f,0.0f,0.0f, 1.0f);
    //GraphicPrimitives::drawText2D(nbPaps ,-0.78f,-0.9f,0.0f,0.0f, 1.0f);
	//GraphicPrimitives::drawFillRect2D(0, 0, (Engine::getWindowsWidth() - 400) / 400.f / 5.f, (Engine::getWindowsHeight() - 300) / -300.f / 5.f, 0, 0, 1);
	//std::cout << "width :" << (Engine::getWindowsWidth() - 400) / 400.f / 5.f << "height :" << (Engine::getWindowsHeight() - 300) / -300.f / 5.f << std::endl;
    
	for (int i = 0; i < square_->size(); i++) {
		(*square_)[i]->draw();
	}
    for (int i = 0; i < paps_->size(); i++) {
        (*paps_)[i]->draw();
    }
    for (int i = 0; i < fourmis_->size(); i++) {
        (*fourmis_)[i]->draw();
    }
}