#include <iostream>
#include "Cell.h"


Cell::Cell()
{
	alive = 1;
	cell_neighbors = NULL;
}


Cell::Cell(bool* obj)
{
	cell_neighbors = new bool[8];
	cell_neighbors = obj;
	alive = 1;	
}

bool Cell::func_alive(){ return alive; }
bool Cell::cell_death()
{ 
	alive = 0; 
	return alive;
}
bool Cell::cell_alive()
{
	alive = 1;
	return alive;
}
