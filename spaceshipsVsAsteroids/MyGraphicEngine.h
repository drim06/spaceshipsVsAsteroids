#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Papillon.h"
#include "Fourmis.h"
#include "Square.h"
#include "utility.h"

class MyGraphicEngine:public GraphicEngine {
    
    std::vector<Papillon * > *paps_;
    std::vector<Fourmis * > *fourmis_;
	std::vector<Square * > * square_;
    
    char * str;
public:
    
	MyGraphicEngine(std::vector<Papillon * > * paps, std::vector<Fourmis * > * fourmis, std::vector<Square * > * square) :
        paps_(paps),
        fourmis_(fourmis),
		square_(square),
    	str(new char[13]{'C','l','i','c',' ','&',' ','E','n','j','o','y','\0'}){}
    
    virtual void Draw();
};
