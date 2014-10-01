#pragma once

#include "Engine.h"
#include "Papillon.h"
#include "Fourmis.h"
#include "Fenetre.h"

class MyGameEngine:public GameEngine {
	Fenetre f_;
    std::vector<Papillon * > *paps_;
    std::vector<Fourmis * > *fourmis_;
public:
    int tick;
	MyGameEngine(Fenetre f, std::vector<Papillon * > * paps, std::vector<Fourmis * > * fourmis) :
		f_(f),
    	paps_(paps),
    	fourmis_(fourmis){}
    
    virtual void idle();

    
};