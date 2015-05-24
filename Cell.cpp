#include <iostream>
#include "Cell.h"

Cell::Cell()
{
    alive = false;
}

bool Cell::calculateNewStatus()
{
    int sum = 0;
    for (int i = 0; i < cell_neighbors.size(); i++)
    {
        sum += cell_neighbors[i]->getStatus() ? 1 : 0;
    }
    if (alive)
    {
        newAlive = (sum == 3 || sum == 2);
    }
    else {newAlive = (sum == 3);}
    return newAlive;
}

bool Cell::returnNew()
{
    return newAlive;
}


bool Cell::getStatus() 
{
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
