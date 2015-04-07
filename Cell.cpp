#include <iostream>
#include "Cell.h"

//создаем мертвую клетку
Cell::Cell()
{
	alive = true;
}

//функция оживления или умертвления клетки
bool Cell::doStep()
{
	//проверяем сумму живых соседей
	int sum = 0;
	for (int i = 0; i < cell_neighbors.size(); i++)
	{
		sum += cell_neighbors[i]->alive;
	}
	if (sum == 3 || sum == 2) alive = true;
	else alive = false;
	return alive;
}

bool Cell::getStatus() { return alive; }
bool Cell::setStatus(bool alive_)
{
	alive = alive_;
	return alive;
}

