#include <iostream>
#include <vector>
#include "World.h"
#include <cmath>

World::World(unsigned int height=20, unsigned int width=20)
{
    this->height = height;
	this->width = width;

    AllCells.resize(height);
    //Cell** AllCells = new Cell*[height];
	for (int i = 0; i < height; i++)
	{
        AllCells[i].resize(width);
		for (int j = 0; j < width; j++)
		{
            Cell Ameba;
            Ameba.setStatus(false);
            AllCells[i][j] = Ameba;

		}
	}

	//so, let's find our neighbors
    for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			for (int k = -1; k <= 1; k++)
			{
				for (int g = -1; g <= 1; g++)
				{
					if (i != 0 && j != 0 && i != height && j != width)
					{
                            {
                          if (k != 0 && g != 0) {
                              AllCells[i][j].addNeighbour(&(AllCells[(i+k)%height][(j+g)%width]));
                          }
						}
					}
				}
			}
		}
	}
}



//deconstructor of the world
World::~World()
{
    AllCells.clear();
}

void World::doStep()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
            AllCells[i][j].calculateNew();
		}
	}
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            AllCells[i][j].setStatus(AllCells[i][j].returnNew());
        }
    }

}


Cell World::setStatusOfCell(int x, int y, bool alive)
{
    AllCells[x][y].setStatus(alive);
	return AllCells[x][y];
}


bool World::getStatusOfCell(int x, int y)
{
    return AllCells[x][y].getStatus();
}

//reset the world
void World::reset()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			AllCells[i][j].setStatus(false);
		}
	}
}






