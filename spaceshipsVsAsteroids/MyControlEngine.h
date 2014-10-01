#pragma once
#include "Engine.h"
#include "Papillon.h"
#include "Fourmis.h"
#include "Square.h"
#include "Dimension.h"

class MyControlEngine:public ControlEngine {
	Dimension dim_;
    std::vector<Papillon * > *paps_;
    std::vector<Fourmis * > *fourmis_;
	std::vector<std::vector <Square> > *square_;
public:
	MyControlEngine(Dimension dim, std::vector<Papillon * > * paps, std::vector<Fourmis *> * fourmis, std::vector<std::vector <Square> > * square) :
		dim_(dim),
		paps_(paps),
    	fourmis_(fourmis),
		square_(square)
	{}
    
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
