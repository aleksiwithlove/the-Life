#include "Cell.h"
#include <vector>

#pragma once

class World
{
private:
    unsigned int height; //only positive
    unsigned int width;
    std::vector<std::vector<Cell*>> AllCells;

public:
    World(unsigned int height, unsigned int width);
	~World();
    void doStep();
    int getHeight();
    int getWidth();
    Cell* setStatusOfCell(int x, int y, bool alive);
    bool getStatusOfCell(int x, int y);
	void reset();
    void setRandomAlive();
    int getAliveNumber();
};
