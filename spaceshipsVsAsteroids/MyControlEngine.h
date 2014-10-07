#pragma once
#include "Engine.h"
#include "Square.h"
#include "Fenetre.h"
#include "SpaceShip.h"
#include "SpaceCruiser.h"
#include "Missile.h"
#include "Laser.h"
#include "Enemy.h"
#include "Asteroid.h"
#include "Wave.h"
#include "Player.h"
#include "SpaceFalcon.h"
#include "SpaceTroy.h"
#include "SpaceSnake.h"

class MyControlEngine:public ControlEngine {
	Fenetre f_;
	std::vector<std::vector <Square> > *square_;
	std::vector<SpaceShip * > *spaceShips_;
	std::vector<Missile * > *missiles_;
	std::vector<Enemy * > *enemy_;
	Wave &wave_;
	Player &player_;
	std::vector<Square> *shopShip_;
	std::vector<SpaceShip * > * shopShipList_;

public:
	MyControlEngine(
		Fenetre f,
		std::vector<std::vector <Square> > * square,
		std::vector<SpaceShip * > * spaceShips,
		std::vector<Missile * > *missiles,
		std::vector<Enemy * > *enemy,
		Wave &wave,
		Player &player,
		std::vector<Square> *shopShip,
		std::vector<SpaceShip * > * shopShipList)
		:
		f_(f),
		square_(square),
		spaceShips_(spaceShips),
		missiles_(missiles),
		enemy_(enemy),
		wave_(wave),
		player_(player),
		shopShip_(shopShip),
		shopShipList_(shopShipList)
	{}
    
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
