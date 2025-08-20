#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
    int8_t factor_index = 0;
    uint64_t possible_factor = 2;

    while (n > 1 && factor_index < MAXFACTORS)
        if (n % possible_factor)
            possible_factor++;
        else
        {
            factors[factor_index++] = possible_factor;
            n /= possible_factor;
        }

    return factor_index;
}