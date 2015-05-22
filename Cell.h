#include <vector>
#pragma once

class Cell
{
public:
	
	std::vector<Cell*> cell_neighbors;

	bool alive;
    bool newAlive;

	Cell();
	bool getStatus();
	void setStatus(bool alive);
    bool calculateNew();
    bool returnNew();
    void addNeighbour(Cell* n);
};
