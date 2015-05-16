#include <vector>
#pragma once

class Cell
{
public:
	
	std::vector<Cell*> cell_neighbors;

	bool alive;

	Cell();
	bool getStatus();
	void setStatus(bool alive);
	bool doStep();
    void addNeighbour(Cell* n);
};
