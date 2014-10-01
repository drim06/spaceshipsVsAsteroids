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
	std::vector<Square *> square_;

	for (int i = 0; i < 10; i++){
		square_.push_back(new Square(-1 + i*(0.2), 0 - 0.1, 0.2, 0 + i % 2, 1 + i % 2, 0.2));
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
