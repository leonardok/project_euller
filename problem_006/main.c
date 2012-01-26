/* problem description:
 * The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 * Hence the difference between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025  385 = 2640.
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 */

/*
 * after reading the forum someone have written two formulas that describe
 * the behavior of this system:
 * sum of first n numbers            = n(n+1)/2
 * sum of squares of first n numbers = n(n+1)(2n+1)/6
 */

#include <stdio.h>

int main(void)
{
	int i;
	int sum_of_hundred_first = 0;
	int sum_of_sqare_hundred_first = 0;
	int square_of_sum = 0, sum_of_square = 0;
	int n = 100;

	/* sum of all with one digit */
	for (i = 1; i < 101; i++)
	{
		sum_of_hundred_first += i;
		sum_of_square += i*i;
	}

	square_of_sum = sum_of_hundred_first * sum_of_hundred_first;

	printf("square of sum is %d\n", square_of_sum);
	printf("sum of sqares is %d\n", sum_of_square);
	printf("difference is %d\n", square_of_sum - sum_of_square);

	/* ===========================================================*/

	printf("\n\nother way of doing it:\n");
	square_of_sum  = (n * (n + 1) / 2);
	square_of_sum *= square_of_sum;

	sum_of_square = (n * (n + 1)*((2 * n) + 1)/6);

	printf("square of sum is %d\n", square_of_sum);
	printf("sum of sqares is %d\n", sum_of_square);
	printf("difference 2nd way: %d\n", square_of_sum - sum_of_square);
}
