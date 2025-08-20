#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
    bool is_prime[limit + 1];
    memset(is_prime, true, limit + 1);

    uint32_t primes_index = 0;

    for (uint32_t i = 2; i <= limit && primes_index < max_primes; i++)
        if (is_prime[i])
        {
            for (uint32_t j = i + i; j <= limit; j += i)
                is_prime[j] = false;
            primes[primes_index++] = i;
        }

    return primes_index;
}