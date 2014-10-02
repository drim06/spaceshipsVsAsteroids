#include <iostream>
#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"
#include "Fenetre.h"
#include "SpaceShip.h"
#include "Missile.h"


int main(int argc, char * argv[])
{
	Fenetre f(800, 600);
    Engine e(argc,argv, f.getWindowsWidth(), f.getWindowsHeight(), "Spaceships VS Asteroids");
    
    std::vector<Papillon *> paps_;
    std::vector<Fourmis *> fourmis_;
	std::vector<std::vector <Square> > square_;
	std::vector<SpaceShip * > spaceShips_;
	std::vector<Missile * > missiles_;
	
	// GameBoard construction
	for (int rows = 0; rows < 10; rows++) {
		square_.emplace_back();
		for (int columns = 0; columns < 10; columns++){
			float squareSide = (f.getWindowsHeight()-(f.getWindowsHeight()/7)) / (f.getWindowsHeight() / 2.f) / 10.f;
			square_[rows].emplace_back(-1 + columns*squareSide, 1.f - squareSide - rows*squareSide, squareSide, 1.f - 0.5f*((columns + rows) % 2), 1.f - 0.5f*((columns + rows) % 2), 1.f - 0.5f*((columns + rows) % 2));
		}
	}
    
    GraphicEngine * ge = new MyGraphicEngine(f, &paps_, &fourmis_, &square_, &spaceShips_, &missiles_);
	GameEngine * gme = new MyGameEngine(f, &paps_, &fourmis_, &missiles_, &spaceShips_);
	ControlEngine * ce = new MyControlEngine(f, &paps_, &fourmis_, &square_, &spaceShips_, &missiles_);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
