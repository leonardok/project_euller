#include <stdio.h>
#include <math.h>

#define MAX_NUMBERS 1000000

int numbers[MAX_NUMBERS];

int    biggest_sequence;
int    biggest_sequence_number;


unsigned int collatz_definition(unsigned int n)
{
	unsigned int ret = 0, col, row;
    
    if (n < 1000000)
	{
		if (n < 2) return 1;
		if (numbers[n] != 0) return numbers[n];
		
		if (n % 2 == 0) ret = collatz_definition(n/2) + 1;
		else            ret = collatz_definition(3*n + 1) + 1;

		numbers[n] = ret;

		if (ret > biggest_sequence)
		{
			biggest_sequence = ret;
			biggest_sequence_number = n;
		}
	}
	else 
	{
		if (n % 2 == 0) ret = collatz_definition(n/2) + 1;
		else            ret = collatz_definition(3*n + 1) + 1;
	}

	return ret;
}

int main(int argc, const char *argv[])
{
    int row_counter, col_counter, i;

    for (i = 1000000; i > 99999; i--)
    {
        collatz_definition(i);
    }

    printf("biggest seq %d number %d\n", biggest_sequence, biggest_sequence_number);
	
	return 0;
}
