#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Papillon.h"
#include "Fourmis.h"
#include "Square.h"
#include "utility.h"
#include "Fenetre.h"

class MyGraphicEngine:public GraphicEngine {
    
	Fenetre f_;
    std::vector<Papillon * > *paps_;
    std::vector<Fourmis * > *fourmis_;
	std::vector<std::vector <Square> > *square_;
    
    char * str;
public:
    
	MyGraphicEngine(Fenetre f, std::vector<Papillon * > * paps, std::vector<Fourmis * > * fourmis, std::vector<std::vector <Square> > *square) :
		f_(f),
		paps_(paps),
        fourmis_(fourmis),
		square_(square),
    	str(new char[13]{'C','l','i','c',' ','&',' ','E','n','j','o','y','\0'}){}
    
    virtual void Draw();
};
