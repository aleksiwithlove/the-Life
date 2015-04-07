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
			Cell a_cell; //add a memory!!!
			AllCells[i][j] = a_cell;
		}
	}
}
World::~World()
{
	hight = 0;
	width = 0;
	AllCells = NULL;
}
void World::doStep()
{
	
}

Cell World::setStatusofCell(int x, int y, bool alive)
{
	AllCells[x][y].setStatus(alive); 
	return AllCells[x][y];
}

bool World::getStatusofCell(int x, int y)
{
	return AllCells[x][y].getStatus();
}

bool World::replay()
{
	return 0;
	//хотим ли мы закончить игру? будет кнопка "конец"? 
}




