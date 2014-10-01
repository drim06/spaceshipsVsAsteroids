#pragma once
#include "Engine.h"
#include "Papillon.h"
#include "Fourmis.h"
#include "Square.h"
#include "Fenetre.h"

class MyControlEngine:public ControlEngine {
	Fenetre f_;
    std::vector<Papillon * > *paps_;
    std::vector<Fourmis * > *fourmis_;
	std::vector<std::vector <Square> > *square_;
public:
	MyControlEngine(Fenetre f, std::vector<Papillon * > * paps, std::vector<Fourmis *> * fourmis, std::vector<std::vector <Square> > * square) :
		f_(f),
		paps_(paps),
    	fourmis_(fourmis),
		square_(square)
	{}
    
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
