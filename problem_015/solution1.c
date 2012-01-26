/* for this problem just a little bit of logic
 * 1-19        - one word
 * x % 10 == 0 - one word (twenty, fourty...)
 * 101-119     - 4 words (one hundred and one)
 * 121-999     - 5 words (one hundred and twenty-one)
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define FALSE 0
#define TRUE  1

/* Grid sizes */
#define GRID_X 2
#define GRID_Y 4

/* Directions */
#define RIGHT 0
#define DOWN  1

/**
 * 20x20 matrix.
 * We cannot backtrack. This makes it earier. We're only putting the vertices
 * in the grid, so it's a 21x21 vertics that makes a 20x20 matrix
 *
 * As we can't move up or left, only possible dierctions are down and right.
 *
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * | | | | | | | | | | | | | | | | | | | | |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * | | | | | | | | | | | | | | | | | | | | |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * | | | | | | | | | | | | | | | | | | | | |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * | | | | | | | | | | | | | | | | | | | | |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * | | | | | | | | | | | | | | | | | | | | |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * | | | | | | | | | | | | | | | | | | | | |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * | | | | | | | | | | | | | | | | | | | | |
 * ...
 *
 * A *node_s* is a byte with directions. It's just like a pixel map.
 * The grid is formated by a grid of 21x21 nodes.
 */
struct node_s { char r:2, d:2; };
struct node_s grid[GRID_X][GRID_Y];

uint64_t path_count = 0;

//int walk(uint64_t path, int x, int y)
int walk(int x, int y)
{
	int from_right, from_down;

	/* we're out of the grid */
	if ( x > GRID_X || y >GRID_Y ) return -1;

	/* go right */
	//from_right = walk( ((path << 1) | RIGHT), x+1, y );
	from_right = walk(x+1, y);

	/* go down */
	//from_down  = walk( ((path << 1) | DOWN ), x, y+1 );
	from_down  = walk(x, y+1);

	if (from_right == -1 && from_down == -1)
	{
		path_count++;
	}

	return 0;
}

int main(int argc, const char *argv[])
{
	/**
	 * As we will work the path as a number, we cant have it been with size
	 * less than the more expensive path. In this case they'll all be 40
	 * units long. 6 bytes only because I'm giving some extra space
	 */
	if ( sizeof(uint64_t) < 6 ) { printf("!uint64_t\n"); return 10; }

	/**
	 * This, right here, will be our path
	 */
	uint64_t path = 1;

	//walk(path, 0, 0);
	walk(0, 0);
	printf("%d", path_count);

	return 0;
}





