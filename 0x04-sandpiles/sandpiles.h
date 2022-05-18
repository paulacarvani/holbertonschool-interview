#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>

/**
 * enum boolean - Create boolean constants
 *@false: is false
 *@true: is true
 */
typedef enum boolean
{
	false, true
} bool;

/* 0-sandpiles.c  */
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void grid_print(int grid[3][3]);

/* helpers.c  */
bool not_Stable(int grid[3][3]);
void add_Grids(int grid1[3][3], int grid2[3][3]);
void stabilize(int grid[3][3], int template[3][3]);
void get_template(int grid[3][3], int template[3][3]);

#endif /* SANDPIELS_H */
