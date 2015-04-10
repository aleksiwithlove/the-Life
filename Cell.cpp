#include <iostream>
#include "Cell.h"


//create new alive cell
Cell::Cell()
{
	alive = true;
}


//function of the step to the future, 
//define what will be the status of cell in the future
bool Cell::doStep()
{
	//calculate the sum of the neighbors
	int sum = 0;
	for (int i = 0; i < cell_neighbors.size(); i++)
	{
		//if the cell is alive "plus one" to the sum
		sum += cell_neighbors[i]->alive;
	}


	//if the sum of the neighbors satisfy our criteria 
	//than the cell become alive
	if (sum == 3 || sum == 2) alive = true;
	else alive = false;


	//return the status of cell
	return alive;
}


//recognize the cell's status
bool Cell::getStatus() { return alive; }
Cell* Cell::who_are_you() { return this; }

//give to the cell a certain status
void Cell::setStatus(bool alive)
{
	this->alive = alive;
}

