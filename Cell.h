#include <vector>
#pragma once

class Cell
{
private:
	//соседи клетки
	std::vector<Cell*> cell_neighbors;

	//клетка живая или мертвая
	bool alive;
public:
	Cell();
	bool getStatus();
	bool setStatus(bool alive_);
	bool doStep();
};
