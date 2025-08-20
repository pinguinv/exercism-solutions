#include "sum_of_multiples.h"

static uint32_t index = 0;

static void add_if_not_present(uint32_t *arr, size_t arr_size, uint32_t num)
{
    for (size_t i = 0; i < arr_size; i++)
        if (arr[i] == num)
            return;

    arr[index++] = num;
}

uint32_t sum(const uint32_t *factors,
             const size_t number_of_factors,
             const uint32_t limit)
{
    if (number_of_factors < 1)
        return 0;

    uint32_t multiples_of_factors[limit];

    for (uint32_t i = 0; i < limit; i++)
        multiples_of_factors[i] = 0;

    for (uint32_t i = 0; i < number_of_factors; i++)
    {
        uint32_t factor = factors[i];
        if (factor < 1)
            break;

        for (uint32_t mul_of_fctr = 0; mul_of_fctr < limit; mul_of_fctr += factor)
            add_if_not_present(multiples_of_factors, limit, mul_of_fctr);
    }

    index = 0;

    uint32_t result = 0;

    for (uint32_t i = 0; i < limit; i++)
        result += multiples_of_factors[i];

    return result;
}
