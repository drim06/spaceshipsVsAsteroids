#pragma once

#include "Engine.h"
#include "Papillon.h"
#include "Fourmis.h"
#include "Dimension.h"

class MyGameEngine:public GameEngine {
	Dimension dim_;
    std::vector<Papillon * > *paps_;
    std::vector<Fourmis * > *fourmis_;

public:
    int tick;
	MyGameEngine(Dimension dim, std::vector<Papillon * > * paps, std::vector<Fourmis * > * fourmis) :
		dim_(dim),
    	paps_(paps),
    	fourmis_(fourmis){}
    
    virtual void idle();

    
};