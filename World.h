#include <iostream>
#include "Cell.h"
#pragma once

class World
{
private:
	unsigned int hight; //only positive
	unsigned int width;
	Cell** AllCells;

public:
	World(unsigned int hight, unsigned int width);
	~World();
	bool replay();
	void doStep();
	Cell setStatusofCell(int x, int y, bool alive);
	bool getStatusofCell(int x, int y);
};
