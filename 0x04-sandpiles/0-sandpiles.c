#include "sandpiles.h"

/**
 * print_grid - prints grid
 * @grid: grid of integers
 */

static void print_grid(int grid[3][3])
{
	int i, j;

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

/**
 * sandpiles_sum - sums sandpiles and topple_cells to make it stable
 * @grid1: first grid of integers
 * @grid2: second grid of integers
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;
	int flags[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	while (is_grid_unstable(grid1, flags))
	{
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (flags[i][j])
					topple_cell(grid1, i, j);
			}
		}
	}
}


/**
 * is_grid_unstable - checks stabiliby of grid
 * @grid1: 3x3 first grid of integers
 * @flags: 3x3 grid with unstable indexes
 * Return: Returns 1 if unstable, 0 otherwise.
 */

int is_grid_unstable(int grid1[3][3], int flags[3][3])
{
	int unstable = 0, i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				unstable = 1;
				flags[i][j] = 1;
			}
			else
				flags[i][j] = 0;
		}
	}
	return (unstable);
}


/**
 * topple_cell - topples individual cell.
 * @grid1: grid to be toppled
 * @i: row index
 * @j: column index
 *
 */

void topple_cell(int grid1[3][3], int i, int j)
{
	grid1[i][j] -= 4;
	if (i - 1 >= 0)
		grid1[i - 1][j] += 1;
	if (i + 1 < 3)
		grid1[i + 1][j] += 1;
	if (j - 1 >= 0)
		grid1[i][j - 1] += 1;
	if (j + 1 < 3)
		grid1[i][j + 1] += 1;
}

