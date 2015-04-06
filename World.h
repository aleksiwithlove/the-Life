#include <iostream>
#include "Cell.h"
#pragma once

class World
{
	unsigned int hight; //only positive
	unsigned int width;
	Cell** AllCells;

public:
	World(unsigned int hight, unsigned int width);
	bool replay();
	void doStep();
};
