#include "darts.h"

uint8_t score(coordinate_t landing_position)
{
    float sum_of_squares = landing_position.x * landing_position.x + landing_position.y * landing_position.y;

    if (sum_of_squares <= 1)
        return 10;

    if (sum_of_squares <= 25)
        return 5;

    if (sum_of_squares <= 100)
        return 1;

    return 0;
}