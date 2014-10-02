#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"
#include "Fenetre.h"
#include "SpaceShip.h"
#include "Missile.h"
#include "Enemy.h"
#include "Asteroid.h"


int main(int argc, char * argv[])
{
	srand(time(NULL));

	Fenetre f(800, 600);
    Engine e(argc,argv, f.getWindowsWidth(), f.getWindowsHeight(), "Spaceships VS Asteroids");
    
	std::vector<std::vector <Square> > square_;
	std::vector<SpaceShip * > spaceShips_;
	std::vector<Missile * > missiles_;
	std::vector<Enemy * > enemy_;

	
	// GameBoard construction
	for (int rows = 0; rows < 10; rows++) {
		square_.emplace_back();
		for (int columns = 0; columns < 10; columns++){
			float squareSide = (f.getWindowsHeight()-(f.getWindowsHeight()/7)) / (f.getWindowsHeight() / 2.f) / 10.f;
			square_[rows].emplace_back(-1 + columns*squareSide, 1.f - squareSide - rows*squareSide, squareSide, 1.f - 0.5f*((columns + rows) % 2), 1.f - 0.5f*((columns + rows) % 2), 1.f - 0.5f*((columns + rows) % 2));
		}
	}

	for (int i = 0; i < 5; i++){
		enemy_.push_back(new Asteroid(rand() % 10));
	}
    
    GraphicEngine * ge = new MyGraphicEngine(f, &square_, &spaceShips_, &missiles_, &enemy_);
	GameEngine * gme = new MyGameEngine(f, &spaceShips_, &missiles_, &enemy_);
	ControlEngine * ce = new MyControlEngine(f, &square_, &spaceShips_, &missiles_, &enemy_);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
