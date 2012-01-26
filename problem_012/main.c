#include <stdio.h>

#define TRUE  1
#define FALSE 0

int check_for_divisors(int triangle_num)
{
	int i, number_of_divisors = 0;

	for (i = 1; i < (triangle_num/2 + 1); i++)
	{
		if (triangle_num % i == 0) number_of_divisors++;
	}

	//printf("%d has %d divisors\n", triangle_num, number_of_divisors);

	/* return +1 because is divisible by itself too */
	return number_of_divisors + 1;
}

int main(int argc, const char *argv[])
{
	/* triangle number.
	 * a triangle number is formed by the sum of the last triangle number and 
	 * the current position. So we need two variables: one for current position
	 * and other for current triangle.
	 * i.e. 1 tri => 1		; 1
	 *      2 tri => 1 + 2 	; 3
	 *      3 tri => 3 + 3	; 6
	 *      4 tri => 6 + 4	; 10
	 *      5 tri => 10 + 5 ; 15
	 *      ...
	 */
	int triangle_position = 1, triangle_value = 1, number_of_divisors;

	while (TRUE)
	{
		/* current triangle is the sum of last triangle value and postion + 1 */
		triangle_position++;
		triangle_value += triangle_position;
		
		/* just for testing */
		if ((number_of_divisors = check_for_divisors(triangle_value)) >= 500)
		{
			printf("%d has %d divisors\n", triangle_value, number_of_divisors);
			break;
		}

		/* check how many divisors it have */
		
	}
    
    return 0;
}










