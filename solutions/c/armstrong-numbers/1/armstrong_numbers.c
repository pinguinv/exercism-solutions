#include "armstrong_numbers.h"

static int ipow(int x, int y)
{
    int result = 1;
    while (y > 0)
    {
        result *= x;
        y--;
    }
    return result;
}

bool is_armstrong_number(int candidate)
{
    int digits_sum = 0;
    int candidate_init_val = candidate;

    int no_digits = 0;

    while (candidate > 0)
    {
        no_digits++;
        candidate /= 10;
    }

    candidate = candidate_init_val;

    while (candidate > 0)
    {
        digits_sum += ipow((candidate % 10), no_digits);
        candidate /= 10;
    }

    return digits_sum == candidate_init_val;
}
