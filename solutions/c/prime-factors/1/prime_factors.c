#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
    if (n <= 0)
        return 0;

    int8_t factor_index = 0;

    while (n > 1 && factor_index < MAXFACTORS)
        for (uint64_t i = 2; i <= n; i++)
            if (n % i == 0)
            {
                factors[factor_index++] = i;
                n /= i;
                break;
            }

    return factor_index;
}
