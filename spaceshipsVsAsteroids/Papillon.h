#pragma once
#include "GraphicPrimitives.h"
#include "Fourmis.h"
#include <ctime>
#include <cstdlib>


class Papillon {
	float posX_, posY_, width_, height_;
	float VposX_, VposY_, Vwidth_, Vheight_;
	float red_, green_, blue_;
    
public:
    Papillon(float posX,float posY, float red, float green, float blue):
    	posX_(posX),
    	posY_(posY),
    	red_(red),
        green_(green),
        blue_(blue),
    	width_(0.1f),
    	height_(0.1f),
    	VposX_((rand()%400-200)/10000.0f),
    	VposY_((rand()%400-200)/10000.0f),
    	Vwidth_(0.01f),
    	Vheight_(-0.02f)
    	{}

    void draw();
    void tick();
	bool hit(const Fourmis&);
};