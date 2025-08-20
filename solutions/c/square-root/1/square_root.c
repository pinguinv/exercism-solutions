#include "square_root.h"

uint16_t square_root(uint16_t number)
{
    uint16_t possible_ans = 0;

    while (possible_ans * possible_ans <= number)
    {
        if (possible_ans * possible_ans == number)
            return possible_ans;
        possible_ans++;
    }

    // Error if not found
    return -1;
}