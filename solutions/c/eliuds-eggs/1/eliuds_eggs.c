#include "eliuds_eggs.h"

unsigned int egg_count(unsigned int number)
{
    unsigned int count = 0;

    for (; number; number >>= 1)
    {
        if (number % 2)
            count++;
    }

    return count;
}