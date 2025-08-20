#include "sum_of_multiples.h"

uint32_t sum(const uint32_t *factors,
             const size_t number_of_factors,
             const uint32_t limit)
{
    uint32_t result = 0;

    for (uint32_t i = 0; i < limit; i++)
        for (uint32_t j = 0; j < number_of_factors; j++)
        {
            uint32_t factor = factors[j];
            if (factor < 1)
                continue;

            if (i % factor == 0)
            {
                result += i;
                break;
            }
        }

    return result;
}
