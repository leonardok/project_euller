/* problem description:
 * The prime factors of 13195 are 5, 7, 13 and 29. What is the largest prime
 * factor of the number 600851475143?
 */

/* this is important. to test if NUMBER is prime we test all primes while
 * sqrt(NUMBER) > PRIME. if NUMBER is not prime, it will have prime factors
 * like {2*2}, {2*3, 3*3}, {2*5, 3*5, 5*5}, {2*7, 3*7, 5*7, 7*7}. So, if the
 * number is not divisible by the PRIME, and is higher than square PRIME, 
 * this number is prime. In case of 51, we test all low primes, if we get in
 * a situation of discovering that it is not divisible by 7, we test 11. In 
 * this case, 51 is not divisible by 11 and sqare(11) > 51. 51 is prime!
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE   0
#define FALSE  1
#define NUMBER 600851475143ULL

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

    if ((NUMBER % new_node->number) == 0)
        //printf("%lld is divisible for prime %lld with quoc. %lld\n",
        //        NUMBER, prime_ptr->number, NUMBER/prime_ptr->number);
        printf("NUMBER is divisible by %lld\n", new_node->number);

    return FALSE;
}

void find_prime_divisors(prime_factors_t *prime_factors)
{
    prime_factors_t *prime_ptr = prime_factors;
    while (prime_ptr)
    {
        if ((NUMBER % prime_ptr->number) == 0)
            printf("%lld is divisible for prime %lld with quoc. %lld\n",
                    NUMBER, prime_ptr->number, NUMBER/prime_ptr->number);

        prime_ptr = prime_ptr->next;
    }
}

int main(void)
{
    unsigned long long int i;
    prime_factors_t *prime_factors = NULL;

    /*
     * this is better explained at the beginning of this code, but again: the
     * values that matter for us are not all primes untill 600851475143ULL, but
     * all primes that CAN FACTOR it. as the thinking tells, no prime greater
     * than the sqare root of 600851475143ULL will factor it.
     */
    unsigned int maximun_prime = abs(ceil(sqrt(600851475143ULL)));
    printf("greater value will be %d\n\n", maximun_prime);

    /* get the list of prime factors for NUMBER.
     * we go from 0 to sqare_root(NUMBER), as 
     */
    for (i = 2; i < maximun_prime;)
    {
        if (have_prime_divisor(&prime_factors, i) == FALSE) {}

        (i%2) ? (i+=2) : (i++);
    }
    
    return 0;
}









