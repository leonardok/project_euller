/* for this problem just a little bit of logic
 * 1-19        - one word
 * x % 10 == 0 - one word (twenty, fourty...)
 * 101-119     - 4 words (one hundred and one)
 * 121-999     - 5 words (one hundred and twenty-one)
 */

#include <stdio.h>
#include <stdint.h>

/* Grid sizes */
#define GRID_X 17
#define GRID_Y 17

uint64_t sum_of(uint64_t x, uint64_t y)
{
	if (x == 0 || y == 0) return 1;
	else return sum_of(x, y-1) + sum_of(x-1, y);
}

int main(int argc, const char *argv[])
{
	printf("%d", sum_of(GRID_X, GRID_Y));
	return 0;
}





