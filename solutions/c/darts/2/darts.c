#include "darts.h"

uint8_t score(coordinate_t landing_position)
{
    float sum_of_squares = landing_position.x * landing_position.x + landing_position.y * landing_position.y;

    // within the inner circle (radius 1)
    if (sum_of_squares <= 1)
        return 10;

    // within the middle circle (radius 5)
    if (sum_of_squares <= 25)
        return 5;

    // within the outer circle (radius 10)
    if (sum_of_squares <= 100)
        return 1;

    // 0 points if outside the outer circle
    return 0;
}