#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Papillon.h"
#include "Fourmis.h"
#include "Square.h"
#include "utility.h"
#include "Dimension.h"
#include "SpaceShip.h"
#include "SpaceCruiser.h"
#include "Missile.h"

class MyGraphicEngine:public GraphicEngine {
    
	Dimension dim_;
    std::vector<Papillon * > *paps_;
    std::vector<Fourmis * > *fourmis_;
	std::vector<std::vector <Square> > *square_;
	std::vector<SpaceShip * > *spaceShips_;
	std::vector<Missile * > *missiles_;
    
    char * str;
public:
    
	MyGraphicEngine(Dimension dim, std::vector<Papillon * > * paps, std::vector<Fourmis * > * fourmis, std::vector<std::vector <Square> > *square, std::vector<SpaceShip * > * spaceShips, std::vector<Missile * > * missiles) :
		dim_(dim),
		paps_(paps),
        fourmis_(fourmis),
		square_(square),
		spaceShips_(spaceShips),
		missiles_(missiles),
    	str(new char[13]{'C','l','i','c',' ','&',' ','E','n','j','o','y','\0'}){}
    
    virtual void Draw();
};
