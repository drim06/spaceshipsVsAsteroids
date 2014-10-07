#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Square.h"
#include "utility.h"
#include "Fenetre.h"
#include "SpaceShip.h"
#include "SpaceCruiser.h"
#include "Missile.h"
#include "Enemy.h"
#include "Asteroid.h"
#include "Wave.h"
#include "Player.h"

class MyGraphicEngine:public GraphicEngine {
    
	Fenetre f_;
	std::vector<std::vector <Square> > *square_;
	std::vector<SpaceShip * > *spaceShips_;
	std::vector<Missile * > *missiles_;
	std::vector<Enemy * > *enemy_;
	Wave &wave_;
	Player &player_;
	std::vector<Square> *shopShip_;
	std::vector<SpaceShip * > *shopShipList_;

    char * str;
public:
    
	MyGraphicEngine(Fenetre f,
		std::vector<std::vector <Square> > *square,
		std::vector<SpaceShip * > * spaceShips,
		std::vector<Missile * > * missiles,
		std::vector<Enemy * > *enemy,
		Wave &wave,
		Player &player,
		std::vector<Square> *shopShip,
		std::vector<SpaceShip * > *shopShipList)
		:
		f_(f),
		square_(square),
		spaceShips_(spaceShips),
		missiles_(missiles),
		enemy_(enemy),
		wave_(wave),
		player_(player),
		shopShip_(shopShip),
		shopShipList_(shopShipList),
    	str(new char[13]{'C','l','i','c',' ','&',' ','E','n','j','o','y','\0'}){}
    
    virtual void Draw();
};
