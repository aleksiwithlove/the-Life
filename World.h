#include <iostream>
#include "Cell.h"

class World
{
	unsigned int hight; //only positive
	unsigned int width;
	Cell** AllCells;

public:
	World();
	World(bool* obj);

	void doStep();
	
	
};
