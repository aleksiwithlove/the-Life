#include <vector>
#pragma once

class Cell
{

private:
    std::vector<Cell*> cell_neighbors;
    bool alive;
    bool newAlive;

public:
	Cell();
	bool getStatus();
	void setStatus(bool alive);
    bool calculateNewStatus();
    bool returnNew();
    void addNeighbour(Cell* n);
};
