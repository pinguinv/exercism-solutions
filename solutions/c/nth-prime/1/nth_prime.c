#include "nth_prime.h"

// 0 - false, 1 - true
static int8_t is_prime(uint32_t num)
{
    if (num < 2)
        return 0;

    for (uint32_t i = 2; i * i <= num; i++)
        if (num % i == 0)
            return 0;

    return 1;
}

uint32_t nth(uint32_t n)
{
    uint32_t prime = 0, prime_counter = 0;

    while (prime_counter < n)
        for (uint32_t i = prime + 1;; i++)
            if (is_prime(i))
            {
                prime = i;
                prime_counter++;
                break;
            }

    return prime;
}