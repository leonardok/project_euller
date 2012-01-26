/* problem description:
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see 
 * that the 6th prime is 13. What is the 10001st prime number?
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE   1
#define FALSE  0

typedef struct prime_factors_s prime_factors_t;
struct prime_factors_s
{
    unsigned long long int number;
    prime_factors_t   *next;
};

void dump_primes(prime_factors_t *prime_factors)
{
    prime_factors_t *prime_ptr = prime_factors;
    while (prime_ptr)
    {
        printf("%lld ", prime_ptr->number);
        prime_ptr = prime_ptr->next;
    }
    printf("\n\n");
}

int have_prime_divisor(prime_factors_t **prime_factors, long unsigned int i)
{
    prime_factors_t *old_prime_ptr, *prime_ptr = *prime_factors;
    int flag_compare = TRUE;

    while (prime_ptr)
    {
        if (flag_compare == TRUE)
        {
            if ((i % prime_ptr->number) == 0)
                return TRUE;

            if (sqrt(i) < prime_ptr->number)
                flag_compare = FALSE;
        }

        old_prime_ptr = prime_ptr;
        prime_ptr     = prime_ptr->next;
    }

    /* add a new node because this is a prime */
    prime_factors_t *new_node = malloc(sizeof(prime_factors_t));
    new_node->number = i;

    if (*prime_factors == NULL)
    {
        *prime_factors = new_node;
        new_node->next = NULL;
    }
    else
    {
        old_prime_ptr->next = new_node;
    }

    return FALSE;
}

int main(void)
{
    unsigned long long int i;
    int prime_counter = 0;
    prime_factors_t *prime_factors = NULL;

    for (i = 2;; i++)
    {
        if (have_prime_divisor(&prime_factors, i) == FALSE) 
		{
			prime_counter++;

            if (prime_counter == 10001)
            {
                break;
            }
		}
    }

    printf("%d prime is %lld\n", prime_counter, i);

    return 0;
}









