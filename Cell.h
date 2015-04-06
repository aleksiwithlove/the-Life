#include <vector>
#pragma once

class Cell
{
	//соседи клетки
	std::vector<Cell*> cell_neighbors;

	//клетка живая или мертвая
	bool alive;
public:
	Cell();
	
	Cell& cell_alive();
};
