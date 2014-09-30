
#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw(){
    
    char* nbPaps = new char[100];
    itoa(paps_->size(), nbPaps);
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

char* MyGraphicEngine::itoa(int val, char* c){
    int i = 0;
    do{
        c[i] = val % 10 + '0';
        val /= 10;
        i++;
    } while (val);
    c[i] = '\0';
    return reverse(c);
}

char* MyGraphicEngine::reverse(char* c){
    char tmp;
    int size = strlen(c);
    for(int i = 0; i < size/2; i++){
        tmp = c[i];
        c[i] = c[size-1-i];
        c[size-1-i] = tmp;
    }
    return c;
}