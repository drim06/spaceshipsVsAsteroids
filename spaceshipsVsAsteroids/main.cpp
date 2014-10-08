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
	std::vector<Square> shopShip;
	std::vector<SpaceShip *> shopShipList;

	float squareSide = (f.getWindowsHeight() - (f.getWindowsHeight() / 7)) / (f.getWindowsHeight() / 2.f) / 10.f;
	// GameBoard construction
	for (int rows = 0; rows < 10; rows++) {
		square.emplace_back();
		for (int columns = 0; columns < 10; columns++){
			square[rows].emplace_back(-1 + columns*squareSide, 1.f - squareSide - rows*squareSide, squareSide, 0.1f - 0.5f*(((columns + rows) % 2)/5.f) + columns / 80.f, 0.1f - 0.5f*(((columns + rows) % 2)/5.f) + columns / 100.f, 0.1f - 0.5f*(((columns + rows) % 2)/5.f) + columns / 100.f);
		}
	}

	// ShopShip construction
	for (int i = 0; i < 4; i++){
		shopShip.emplace_back(-0.98f + i * squareSide + i * squareSide/7.f, -0.98f, squareSide, 0.0f, 0.0f, 0.0f);
	}
	for (int i = 0; i < 4; i++){
		switch (i){
		case 0:
			shopShipList.push_back(new SpaceCruiser(shopShip[i], player, true));
			break;
		case 1:
			shopShipList.push_back(new SpaceFalcon(shopShip[i], player, true));
			break;
		case 2:
			shopShipList.push_back(new SpaceTroy(shopShip[i], player, true));
			break;
		case 3:
			shopShipList.push_back(new SpaceSnake(shopShip[i], player, true));
			break;
		}
	}

	GraphicEngine * ge = new MyGraphicEngine(f, &square, &spaceShips, &missiles, &enemy, wave, player, &shopShip, &shopShipList);
	GameEngine * gme = new MyGameEngine(f, &spaceShips, &missiles, &enemy, wave, player);
	ControlEngine * ce = new MyControlEngine(f, &square, &spaceShips, &missiles, &enemy, wave, player, &shopShip, &shopShipList);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
