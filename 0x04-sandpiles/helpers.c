#include "sandpiles.h"

#define MAX_VALUE 3

/**
 * not_Stable - Check if a grid is Stable( No value is over 3)
 *@grid: grid to check
 *
 * Return: True / False
 */

bool not_Stable(int grid[3][3])
{
	int i1, i2;

	for (i1 = 0; i1 < 3; i1++)
		for (i2 = 0; i2 < 3; i2++)
			if (grid[i1][i2] > MAX_VALUE)
				return (true);
	return (false);
}

/**
 * add_Grids - add two 3x3 grids
 *
 *@grid1: first Grid
 *@grid2: second Grid
 */

void add_Grids(int grid1[3][3], int grid2[3][3])
{
	int i1, i2;

	for (i1 = 0; i1 < 3; i1++)
		for (i2 = 0; i2 < 3; i2++)
			grid1[i1][i2] = grid1[i1][i2] + grid2[i1][i2];
}

/**
 * stabilize - Reduce values over 3 in grid by sending
 *             1 to the surrounding indecies
 *@grid: grid to stabilize
 *@template: template of indicies in grid to reduce
 */

void stabilize(int grid[3][3], int template[3][3])
{
	int i1, i2;

	for (i1 = 0; i1 < 3; i1++)
	{
		for (i2 = 0; i2 < 3; i2++)
		{
			if (template[i1][i2] == 1)
			{
				grid[i1][i2] -= 4;

				if (i1 != 0)
					grid[i1 - 1][i2] += 1;
				if (i1 != 2)
					grid[i1 + 1][i2] += 1;
				if (i2 != 0)
					grid[i1][i2 - 1] += 1;
				if (i2 != 2)
					grid[i1][i2 + 1] += 1;
			}
		}
	}
}

/**
 * get_template - get the indecies to reduce
 *
 *@grid: source grid to reduce
 *@template: indices of grid with a value over 3
 *           are set to one
 */

void get_template(int grid[3][3], int template[3][3])
{
	int i1, i2;

	for (i1 = 0; i1 < 3; i1++)
	{
		for (i2 = 0; i2 < 3; i2++)
		{
			if (grid[i1][i2] > MAX_VALUE)
				template[i1][i2] = 1;
			else
				template[i1][i2] = 0;
		}
	}
}
