#include "grains.h"

uint64_t square(uint8_t index)
{
    if (index < 1 || index > 64)
        return 0;

    uint64_t result = 1;

    result <<= (index - 1);

    return result;
}

uint64_t total(void)
{
    uint64_t result = 1;

    for (uint8_t i = 0; i < 64; i++)
        result += 1 << i;

    return result;
}
