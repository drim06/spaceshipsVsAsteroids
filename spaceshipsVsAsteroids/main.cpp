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
#include "AsteroidFragment.h"
#include "Wave.h"
#include "Player.h"


int main(int argc, char * argv[])
{
	srand(time(NULL));

	Fenetre f(800, 600);
    Engine e(argc,argv, f.getWindowsWidth(), f.getWindowsHeight(), "Spaceships VS Asteroids");
    
	std::vector<std::vector <Square> > square;
	std::vector<SpaceShip * > spaceShips;
	std::vector<Missile * > missiles;
	std::vector<Enemy * > enemy;
	Wave wave;
	Player player;

	// GameBoard construction
	for (int rows = 0; rows < 10; rows++) {
		square.emplace_back();
		for (int columns = 0; columns < 10; columns++){
			float squareSide = (f.getWindowsHeight()-(f.getWindowsHeight()/7)) / (f.getWindowsHeight() / 2.f) / 10.f;
			square[rows].emplace_back(-1 + columns*squareSide, 1.f - squareSide - rows*squareSide, squareSide, 1.f - 0.5f*((columns + rows) % 2) + columns / 100.f, 1.f - 0.5f*((columns + rows) % 2) + columns / 100.f, 0.8f - 0.5f*((columns + rows) % 2) + columns / 50.f);
		}
	}
    
    GraphicEngine * ge = new MyGraphicEngine(f, &square, &spaceShips, &missiles, &enemy, wave, player);
	GameEngine * gme = new MyGameEngine(f, &spaceShips, &missiles, &enemy, wave, player);
	ControlEngine * ce = new MyControlEngine(f, &square, &spaceShips, &missiles, &enemy, wave, player);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
