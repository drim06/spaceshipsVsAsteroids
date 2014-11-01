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
#include "Player.h"
#include "Needle.h"
#include "RapidFire.h"
#include "Venom.h"
#include "ManageFps.h"

class MyGameEngine:public GameEngine {
	Fenetre f_;
	std::vector<SpaceShip * > *spaceShips_;
	std::vector<Missile * > *missiles_;
	std::vector<Enemy * > *enemy_;
	Wave &wave_;
	Player &player_;
	ManageFps mFps_;
	int tick_;

public:
	MyGameEngine(Fenetre f, 
		std::vector<SpaceShip * > *spaceShips, 
		std::vector<Missile *> * missiles, 
		std::vector<Enemy * > *enemy,
		Wave &wave,
		Player &player) 
		:
		f_(f),
		spaceShips_(spaceShips),
		missiles_(missiles),
		enemy_(enemy),
		wave_(wave),
		player_(player)
	{}
    
    virtual void idle();

    
};