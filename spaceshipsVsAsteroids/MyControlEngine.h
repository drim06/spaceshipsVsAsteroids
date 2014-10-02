#pragma once
#include "Engine.h"
#include "Papillon.h"
#include "Fourmis.h"
#include "Square.h"
#include "Dimension.h"
#include "SpaceShip.h"
#include "SpaceCruiser.h"
#include "Missile.h"
#include "Laser.h"

class MyControlEngine:public ControlEngine {
	Dimension dim_;
    std::vector<Papillon * > *paps_;
    std::vector<Fourmis * > *fourmis_;
	std::vector<std::vector <Square> > *square_;
	std::vector<SpaceShip * > *spaceShips_;
	std::vector<Missile * > *missiles_;

public:
	MyControlEngine(Dimension dim, std::vector<Papillon * > * paps, std::vector<Fourmis *> * fourmis, std::vector<std::vector <Square> > * square, std::vector<SpaceShip * > * spaceShips, std::vector<Missile * > *missiles) :
		dim_(dim),
		paps_(paps),
    	fourmis_(fourmis),
		square_(square),
		spaceShips_(spaceShips),
		missiles_(missiles)
	{}
    
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
