#include "Cell.h"
#include <vector>

#pragma once

class World
{
public:
    unsigned int height; //only positive
    unsigned int width;
    std::vector<std::vector<Cell>> AllCells;
    World(unsigned int height, unsigned int width);
	~World();
	void doStep();
    Cell setStatusOfCell(int x, int y, bool alive);
    bool getStatusOfCell(int x, int y);
	void reset();
};

