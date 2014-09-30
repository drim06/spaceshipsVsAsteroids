

#include <iostream>
#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"


int main(int argc, char * argv[])
{
    Engine e(argc,argv);
	
    
    std::vector<Papillon *> paps_;
    std::vector<Fourmis *> fourmis_;
	std::vector<Square *> square_;

	for (int i = 0; i < 10; i++){
		square_.push_back(new Square(-1 + i*(0.2), 0 - 0.1, 0.2, 0 + i % 2, 0, 1 + i % 2));
	}
    
    GraphicEngine * ge = new MyGraphicEngine(&paps_, &fourmis_, &square_);
    GameEngine * gme = new MyGameEngine(&paps_, &fourmis_);
    ControlEngine * ce = new MyControlEngine(&paps_, &fourmis_, &square_);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
