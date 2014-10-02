#pragma once
#include "Engine.h"
#include "Papillon.h"
#include "Fourmis.h"
#include "Square.h"
#include "Fenetre.h"
#include "SpaceShip.h"
#include "SpaceCruiser.h"
#include "Missile.h"
#include "Laser.h"
#include "Enemy.h"
#include "Asteroid.h"

class MyControlEngine:public ControlEngine {
	Fenetre f_;
    std::vector<Papillon * > *paps_;
    std::vector<Fourmis * > *fourmis_;
	std::vector<std::vector <Square> > *square_;
	std::vector<SpaceShip * > *spaceShips_;
	std::vector<Missile * > *missiles_;
	std::vector<Enemy * > *enemy_;

public:
	MyControlEngine(Fenetre f, std::vector<Papillon * > * paps, std::vector<Fourmis *> * fourmis, std::vector<std::vector <Square> > * square, std::vector<SpaceShip * > * spaceShips, std::vector<Missile * > *missiles, std::vector<Enemy * > *enemy) :
		f_(f),
		paps_(paps),
		fourmis_(fourmis),
		square_(square),
		spaceShips_(spaceShips),
		missiles_(missiles),
		enemy_(enemy)
	{}
    
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
