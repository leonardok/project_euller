/* problem description:
 * 2520 is the smallest number that can be divided by each of the numbers from 1
 * to 10 without any remainder. What is the smallest positive number that is 
 * evenly divisible by all of the numbers from 1 to 20?
 */

#include <stdio.h>

#define TRUE  1
#define FALSE 0
#define MAX_ARRAY_SIZE 512
#define TOTAL_NUMBERS  10

int important_numbers[TOTAL_NUMBERS] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

int main(void)
{
    int array[MAX_ARRAY_SIZE];
    int i, j, counter;

    /*
     * first we need to get all numbers that really matter to our test.
     * 20 - if a number is divided by 20, is also by 2, 4, 5 and 10.
     * 19 - prime
     * 18 - if divides by 18, also by 3, 9.
     * 17 - prime
     * 16 - if divisible by 16 it is also by 2, 4, 8
     * 15 - also by 3, 5
     * 14 - also by 7
     * 13 - prime
     * 12 - also by 2, 3, 6
     * 11 - prime
     * <= 10 - already handled by number above.
     *
     * by this thinking we only need to find the smallest number that can be
     * divided by 20, 19, 18, 17, 16, 15, 14, 15, 14, 13, 12 and 11.
     */

    counter = 0;
    while (TRUE)
    {
        /* fill the array with multiples of 11 */
        for (i = 0; i < MAX_ARRAY_SIZE; i++)
        {
            array[i] = important_numbers[0] * (i + (counter * MAX_ARRAY_SIZE));
        }

        /* now that we have all multiples of 11, we can see if they are 
         * divisible by the other numbers as well. start on 1, as position
         * 0 was used to fill the array in the first place */
        for (i = 1; i < TOTAL_NUMBERS; i++)
        {
            for (j = 0; j < MAX_ARRAY_SIZE; j++)
            {
                if ((array[j] != 0) && ((array[j] % important_numbers[i]) != 0))
                    array[j] = 0;
            }
        }

        for (i = 0; i < MAX_ARRAY_SIZE; i++)
        {
            if (array[i] != 0)
            {
                printf("lowest number is %d\n\n", array[i]);
                return 0;
            }
        }

        counter++;
    }
    
    return 0;
}











