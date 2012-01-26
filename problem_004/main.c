/* problem description:
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91  99. Find the largest
 * palindrome made from the product of two 3-digit numbers.
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

#define TRUE  1
#define FALSE 0

int is_palindrome(int number)
{
    char word[7];
    int  str_sz, i;

    sprintf(word, "%d", number);
    
    str_sz = strlen(word);
    for (i = 0; i < floor(str_sz/2); i++)
    {
        if (word[i] != word[str_sz - i - 1])
            return FALSE;
    }

    return TRUE;
}

int main(void)
{
    int i, j, for_counter = 0;
    
    for (i = 999; i > 99; i--)
    {
        for (j = 999; j > 99; j--)
        {
            for_counter++;
            if (is_palindrome(i*j) == TRUE)
            {
                printf("%d result of %d and %d\n", i * j, i, j);
            }
        }
    }

    printf("done %d fors\n", for_counter);

    return 0;
}
