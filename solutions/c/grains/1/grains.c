#include "grains.h"

uint64_t square(uint8_t index)
{
    if (index < 1 || index > 64)
    {
        return 0;
    }

    // 2 ^ (index-1)
    uint64_t result = 1;
    for (uint8_t i = 1; i < index; i++)
    {
        result *= 2;
    }

    return result;
}

uint64_t total(void)
{
    uint64_t result = 1;
    for (uint8_t i = 0; i < 64; i++)
    {
        result *= 2;
    }
    // (2 ^ 64) - 1
    return result - 1;
}
