#include <iostream>
#include "Cell.h"

//создаем мертвую клетку
Cell::Cell()
{
	alive = 0;
}

//функция оживления или умертвления клетки
Cell& Cell::cell_alive()
{
	//проверяем сумму живых соседей
	int sum = 0;
	for (int i = 0; i < cell_neighbors.size(); i++)
	{
		sum += cell_neighbors[i]->alive;
	}
	if (sum == 3 && sum == 2) alive = 1;
	else alive = 0;
	return *this;
}
