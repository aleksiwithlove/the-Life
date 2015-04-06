#include <iostream>
#include "World.h"
#include <cmath>

//если не дадут размер, то будет 10 на 10
World::World(unsigned int hight_=10, unsigned int width_=10)
{
	//negative value??

	hight = hight_;
	width = width_;

	//инициализируем поле = все мертвые
	Cell** AllCells = new Cell*[hight];
	for (int i = 0; i < hight; i++)
	{
		AllCells[i] = new Cell[width];
		for (int j = 0; j < width; j++)
		{
			Cell a_cell;
			AllCells[i][j] = a_cell;
		}
	}
}
void World::doStep()
{
	
}
bool World::replay()
{
	//хотим ли мы закончить игру? будет кнопка "the end"? 
}




