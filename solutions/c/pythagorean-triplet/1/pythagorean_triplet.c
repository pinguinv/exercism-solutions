#include "pythagorean_triplet.h"

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Temp
#include <stdio.h>

#define MAX_TRIPLETS_COUNT 16

static bool is_pythagorean_triplet(uint16_t a, uint16_t b, uint16_t c)
{
    bool is_ascending = (a < b) && (b < c);
    bool is_pythagorean = a * a + b * b == c * c;

    return is_ascending && is_pythagorean;
}

triplets_t *triplets_with_sum(uint16_t sum)
{
    triplets_t *triplets = calloc(1, sizeof(triplets_t));
    if (triplets == NULL)
        return NULL;

    triplets->count = 0;
    triplets->triplets = calloc(MAX_TRIPLETS_COUNT, sizeof(triplet_t));

    if (triplets->triplets == NULL)
        return NULL;

    for (uint16_t pos_a = 1; pos_a < sum / 3; pos_a++)
        for (uint16_t pos_b = pos_a + 1; pos_b < sum / 2; pos_b++)
        {
            uint16_t pos_c = sqrt(pos_a * pos_a + pos_b * pos_b);
            if (pos_c + pos_b + pos_a == sum && is_pythagorean_triplet(pos_a, pos_b, pos_c))
                triplets->triplets[triplets->count++] = (triplet_t){pos_a, pos_b, pos_c};
        }

    return triplets;
}

void free_triplets(triplets_t *triplets)
{
    free(triplets->triplets);
    free(triplets);
}