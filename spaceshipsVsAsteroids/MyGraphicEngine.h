#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Papillon.h"
#include "Fourmis.h"

class MyGraphicEngine:public GraphicEngine {
    
    std::vector<Papillon * > *paps_;
    std::vector<Fourmis * > *fourmis_;
    
    char * str;
public:
    
    MyGraphicEngine(std::vector<Papillon * > * paps, std::vector<Fourmis * > * fourmis):
        paps_(paps),
        fourmis_(fourmis),
    	str(new char[13]{'C','l','i','c',' ','&',' ','E','n','j','o','y','\0'}){}
    
    virtual void Draw();

    static char* itoa(int , char*);

    static char* reverse(char*);

    
};
