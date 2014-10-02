#pragma once

#include "Engine.h"
#include "Papillon.h"
#include "Fourmis.h"
#include "Dimension.h"
#include "SpaceShip.h"
#include "Missile.h"
#include "Laser.h"

class MyGameEngine:public GameEngine {
	Dimension dim_;
    std::vector<Papillon * > *paps_;
    std::vector<Fourmis * > *fourmis_;
	std::vector<SpaceShip * > *spaceShips_;
	std::vector<Missile * > *missiles_;

public:
    int tick;
	MyGameEngine(Dimension dim, std::vector<Papillon * > * paps, std::vector<Fourmis * > * fourmis, std::vector<Missile *> * missiles, std::vector<SpaceShip * > *spaceShips) :
		dim_(dim),
    	paps_(paps),
    	fourmis_(fourmis),
		missiles_(missiles),
		spaceShips_(spaceShips)
	{}
    
    virtual void idle();

    
};