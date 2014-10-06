#pragma once
#include "Square.h"
#include "GraphicPrimitives.h"

class Shop
{
private:
	Square square_;

public:
	Shop(Square square) :
		square_(square)
	{}

	void draw();
};

