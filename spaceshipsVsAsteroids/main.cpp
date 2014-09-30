

#include <iostream>
#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"


int main(int argc, char * argv[])
{
    
    Engine e(argc,argv);
    
    std::vector<Papillon *> paps_;
    std::vector<Fourmis *> fourmis_;
    
    GraphicEngine * ge = new MyGraphicEngine(&paps_, &fourmis_);
    GameEngine * gme = new MyGameEngine(&paps_, &fourmis_);
    ControlEngine * ce = new MyControlEngine(&paps_, &fourmis_);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
