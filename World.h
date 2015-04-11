#include "Cell.h"
#include <vector>

#pragma once

class World
{
private:
	unsigned int height; //only positive
	unsigned int width;
	Cell** AllCells;

public:
	World(unsigned int haight, unsigned int width);
	~World();
	void doStep();
	//std::vector<Cell*> add_a_heighbors(Cell obj);
	Cell setStatusofCell(int x, int y, bool alive);
	bool getStatusofCell(int x, int y);
	void reset();
};
