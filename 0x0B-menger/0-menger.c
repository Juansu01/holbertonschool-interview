#include "menger.h"
#include <stdio.h>
#include <math.h>


/**
 * menger - Function that draws a 2d menger sponge
 * @level: Menger sponge level.
 */
void menger(int level)
{
	int i, j, limit;

	if (level == 0)
	{
		printf("#\n");
		return;
	}
	if (level < 0)
	{
		return;
	}

	for (i = 0, limit = pow(3, level); i < limit; i++)
	{
		for (j = 0; j < limit; j++)
		{
			print_char(is_equal_to_one(i, j));
		}
		printf("\n");
	}
}

/**
 * is_equal_to_one - Checks if int i and int j are equal to 1
 * @i: Row Index
 * @j: Column Index
 * Return: Returns 1 if both are equal to 1, 0 otherwise.
 */

int is_equal_to_one(int i, int j)
{
	while (i != 0 && j != 0)
	{
		if (i % 3 == 1 && j % 3 == 1)
			return (0);

		i /= 3, j /= 3;
	}
	return (1);
}

/**
 * print_char - prints # or an empty space.
 * @num: integer
 */

void print_char(int num)
{
	if (num == 1)
	{
		printf("#");
	} else
	{
		printf(" ");
	}
}
