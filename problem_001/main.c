/* 
 * problem description:
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we
 * get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of all the
 * multiples of 3 or 5 below 1000.
 */

#include <stdio.h>

int main(void)
{
    int mod, i, sum = 0;
    for (i = 0; i < 1000; i++)
    {
        if (i < 3) continue;

        if ((mod = (i % 15)) == 0)
        {
            sum += i;
        }
        else if ((mod % 3) == 0)
        {
            sum += i;
        }
        else if ((mod % 5) == 0)
        {
            sum += i;
        }
    }
    printf("Sum is %d\n", sum);
}
