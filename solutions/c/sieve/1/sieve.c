#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
    bool numbers[limit + 1];
    memset(numbers, true, limit + 1);

    for (uint32_t i = 2; i <= limit; i++)
    {
        if (numbers[i])
            for (uint32_t j = i + i; j <= limit; j += i)
                numbers[j] = false;
    }

    uint32_t primes_index = 0;

    for (uint32_t i = 2; i <= limit && primes_index < max_primes; i++)
        if (numbers[i])
            primes[primes_index++] = i;

    return primes_index;
}