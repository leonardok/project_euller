/* problem description:
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million
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

/* 
 * RETURN: FALSE  in case of not prime
 *         NUMBER in case of NUMBER is prime
 */
int is_prime(prime_factors_t **prime_factors, long unsigned int i)
{
    prime_factors_t *old_prime_ptr, *prime_ptr = *prime_factors;
    int flag_compare = TRUE;

    while (prime_ptr)
    {
        if (flag_compare == TRUE)
        {
            if ((i % prime_ptr->number) == 0)
                return FALSE;

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

    /* we can return the proper number */
    return i;
}

int main(void)
{
    unsigned long long int i, prime_sum = 0;
    int prime_counter = 0;
    prime_factors_t *prime_factors = NULL;

    for (i = 2; i < 2000000; (i%2) ? (i+=2) : (i++))
    {
        prime_sum += is_prime(&prime_factors, i);
    }

    printf("prime sum is %lld\n", prime_sum);

    return 0;
}







