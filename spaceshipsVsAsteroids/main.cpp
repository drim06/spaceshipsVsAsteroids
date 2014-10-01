#include <iostream>
#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"
#include "Fenetre.h"


int main(int argc, char * argv[])
{
	Fenetre f(600, 600);
    Engine e(argc,argv, f.getWindowsWidth(), f.getWindowsHeight());
    
    std::vector<Papillon *> paps_;
    std::vector<Fourmis *> fourmis_;
	std::vector<std::vector <Square> > square_;
	
	for (int rows = 0; rows < 10; rows++) {
		square_.emplace_back();
		for (int columns = 0; columns < 10; columns++){
			std::cout << rows << " " << columns << std::endl;
			square_[rows].emplace_back(-1 + columns*0.2f, 1.f - 0.2f - rows*0.2f, 0.2f, 1.f - 0.5f*((columns + rows) % 2), 1.f - 0.5f*((columns + rows) % 2), 1.f - 0.5f*((columns + rows) % 2));
		}
	}
    
    GraphicEngine * ge = new MyGraphicEngine(f, &paps_, &fourmis_, &square_);
    GameEngine * gme = new MyGameEngine(f, &paps_, &fourmis_);
    ControlEngine * ce = new MyControlEngine(f, &paps_, &fourmis_, &square_);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
