#pragma once

#include "Engine.h"
#include "Papillon.h"
#include "Fourmis.h"

class MyGameEngine:public GameEngine {
    std::vector<Papillon * > *paps_;
    std::vector<Fourmis * > *fourmis_;
public:
    int tick;
    MyGameEngine(std::vector<Papillon * > * paps, std::vector<Fourmis * > * fourmis):
    	paps_(paps),
    	fourmis_(fourmis){}
    
    virtual void idle();

    
};