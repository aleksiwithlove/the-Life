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
	void setStatus(bool alive);
	bool doStep();
	Cell* who_are_you();
};
