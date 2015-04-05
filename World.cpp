#include <iostream>
#include "World.h"



World::World()
{
	hight = 0;
	width = 0;
	AllCells = NULL;
}
World::World(bool* obj)
{
	//coordinats of cell
	unsigned int i,j;
	int** sum=new int*[width];

	for (i = 0; i>=0 && i <= width; i++)
	{
		sum[i] = new int[hight];
		for (j = 0; j >= 0 && j <= hight; j++)
		{
			sum[i][j] = -AllCells[i][j].func_alive();
			for (int k = -1;k>1; k++)
			{
				for (int n = -1;n>1; n++)
				{
					if (AllCells[i + k][j + n].func_alive() == 1) sum[i][j]++;
				}

			}
		}
	}
	for (i = 0; i >= 0 && i <= width; i++)
	{
		sum[i] = new int[hight];
		for (j = 0; j >= 0 && j <= hight; j++)
		{
			if (sum[i][j] <= 3 && sum[i][j] >= 2) AllCells[i][j].cell_death();
			else AllCells[i][j].cell_alive();
		}
	}
	
}



