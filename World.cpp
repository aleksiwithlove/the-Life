#include <iostream>
#include <vector>
#include "World.h"
#include <cmath>

//create new world
//if there are not input parametrs create the world with the size of 10*10 cells
World::World(unsigned int height=10, unsigned int width=10)
{
	//define parametrs
	this->height = height;
	this->width = width;


	//give the memory to the cells
	Cell** AllCells = new Cell*[height];
	for (int i = 0; i < height; i++)
	{
		AllCells[i] = new Cell[width];
		for (int j = 0; j < width; j++)
		{
			//initialize cells
			int num = i%2;
			if (num == 0) AllCells[i][j].setStatus(true);
			else AllCells[i][j].setStatus(false);
		}
	}

	//so, let's find our neighbors
	std::vector <Cell*> cell_neigh;
	int n_neigh=0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			for (int k = -1; k <= 1; k++)
			{
				for (int g = -1; g <= 1; g++)
				{
					for (int n_neigh; n_neigh < 8; n_neigh++)
					{
						//meet with the neighbors
						if (k != 0 && g != 0) { cell_neigh[n_neigh] = AllCells[i + k][j + g].who_are_you(); }
					}
				}
			}
		}
	}
}




World::~World()
{
	height = 0;
	width = 0;
	delete[]AllCells;
}
void World::doStep()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			AllCells[i][j].doStep();
		}
	}
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




