#include <iostream>
#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"
#include "Dimension.h"


int main(int argc, char * argv[])
{
	Dimension dim(800, 600);
    Engine e(argc,argv, dim.getWindowsWidth(), dim.getWindowsHeight(), "Spaceships VS Asteroids");
    
    std::vector<Papillon *> paps_;
    std::vector<Fourmis *> fourmis_;
	std::vector<std::vector <Square> > square_;
	
	for (int rows = 0; rows < 10; rows++) {
		square_.emplace_back();
		for (int columns = 0; columns < 10; columns++){
			float squareSide = (dim.getWindowsHeight()-(dim.getWindowsHeight()/7)) / (dim.getWindowsHeight() / 2.f) / 10.f;
			square_[rows].emplace_back(-1 + columns*squareSide, 1.f - squareSide - rows*squareSide, squareSide, 1.f - 0.5f*((columns + rows) % 2), 1.f - 0.5f*((columns + rows) % 2), 1.f - 0.5f*((columns + rows) % 2));
		}
	}
    
    GraphicEngine * ge = new MyGraphicEngine(dim, &paps_, &fourmis_, &square_);
	GameEngine * gme = new MyGameEngine(dim, &paps_, &fourmis_);
	ControlEngine * ce = new MyControlEngine(dim, &paps_, &fourmis_, &square_);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
