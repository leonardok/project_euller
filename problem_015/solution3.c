/* for this problem just a little bit of logic
 * 1-19        - one word
 * x % 10 == 0 - one word (twenty, fourty...)
 * 101-119     - 4 words (one hundred and one)
 * 121-999     - 5 words (one hundred and twenty-one)
 */

#include <stdio.h>
#include <stdint.h>

/* Grid sizes */
#define GRID_X 21
#define GRID_Y 21

uint64_t grid[GRID_X+1][GRID_Y+1];

void init_grid(void)
{
	int x,y;
	for (x = 0; x < GRID_X; x++)
		for (y = 0; y < GRID_Y; y++)
			if (x == 0 || y == 0)
				grid[x][y] = 1;
			else
				grid[x][y] = 0;
}

int sum_of(int x, int y)
{

}

void print_grid(void)
{
	int x,y;
	for (x = 0; x < GRID_X; x++)
	{
		for (y = 0; y < GRID_Y; y++)
			printf("%llu ", grid[x][y]);

		printf("\n");
	}
}

int main(int argc, const char *argv[])
{
	init_grid();
	print_grid();
	
	int x,y;
	for (x = 1; x < GRID_X+1; x++)
	{
		for (y = 1; y < GRID_Y+1; y++)
		{
			grid[x][y] = grid[x-1][y] + grid[x][y-1];
		}
	}
	print_grid();

	return 0;
}





