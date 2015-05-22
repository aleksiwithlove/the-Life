#include <iostream>
#include "Cell.h"


//create new alive cell
Cell::Cell()
{
	alive = true;
}

bool Cell::calculateNew()
{
    int sum = 0;
    for (int i = 0; i < cell_neighbors.size(); i++)
    {
        sum += cell_neighbors[i]->alive?1:0;
    }
    for (int i = 0; i < cell_neighbors.size(); i++)
    {
        if (cell_neighbors[i]->alive == 1)
        {
            if ( sum == 3 || sum == 2) newAlive = true;
            else newAlive = false;
        }
        if (cell_neighbors[i]->alive == 0)
        {
            if (sum == 3) newAlive = true;
            else newAlive = false;
        }
    }
    return newAlive;
}
 bool Cell::returnNew()
 {
     return newAlive;
 }


bool Cell::getStatus() {
    return alive;
    }
void Cell::addNeighbour(Cell* n)
{
    cell_neighbors.push_back(n);
}

void Cell::setStatus(bool alive)
{
	this->alive = alive;
}
