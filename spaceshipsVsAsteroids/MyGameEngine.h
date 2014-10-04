#pragma once
#include "Engine.h"
#include "Fenetre.h"
#include "SpaceShip.h"
#include "Missile.h"
#include "Laser.h"
#include "Enemy.h"
#include "Asteroid.h"
#include "AsteroidFragment.h"
#include "Wave.h"

class MyGameEngine:public GameEngine {
	Fenetre f_;
	std::vector<SpaceShip * > *spaceShips_;
	std::vector<Missile * > *missiles_;
	std::vector<Enemy * > *enemy_;
	Wave &wave_;

public:
    int tick;
	MyGameEngine(Fenetre f, 
		std::vector<SpaceShip * > *spaceShips, 
		std::vector<Missile *> * missiles, 
		std::vector<Enemy * > *enemy,
		Wave &wave) 
		:
		f_(f),
		spaceShips_(spaceShips),
		missiles_(missiles),
		enemy_(enemy),
		wave_(wave)
	{}
    
    virtual void idle();

    
};