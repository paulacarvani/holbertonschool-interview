#include "sandpiles.h"
#include "helpers.c"

/**
 * sandpiles_sum - gets the sum of sandpiles grids and prints
 *                 the new grid per iteration
 *@grid1: first grid
 *@grid2: second grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int template[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	add_Grids(grid1, grid2);
	while (not_Stable(grid1))
	{
		grid_print(grid1);
		get_template(grid1, template);
		stabilize(grid1, template);
	}
}

/**
 * grid_print - prints the 3x3 grid
 *@grid: grid to print
 */

void grid_print(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
