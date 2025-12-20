#include "rail_fence_cipher.h"

#include <stdlib.h>
#include <string.h>

// There could be only 2 sizes of the step for given row in the fence:
// x & max_step - x
// Where:
// max_step = 2 * rails_count - 2
// x = max_step - 2 * nth_rail
#define NEXT_STEP(current, max_step) \
    current == max_step ? max_step : max_step - current

typedef enum CYPHER
{
    ENCODE = 0,
    DECODE = 1
} CYPHER;

// Clever solution that calculate indexes in the original and encoded messages
// and switch letters between these positions
static char *cipher(char *input, size_t rails, CYPHER action)
{
    const size_t len = strlen(input);
    const size_t max_step = 2 * rails - 2;

    char *result = calloc(len + 1, sizeof(char));

    for (size_t rail = 0, endoced_index = 0; rail < rails; rail++)
    {
        size_t step = max_step - 2 * rail;

        step = NEXT_STEP(step, max_step);

        for (size_t original_index = rail; original_index < len;
             step = NEXT_STEP(step, max_step), original_index += step, endoced_index++)
        {
            action == ENCODE ? (result[endoced_index] = input[original_index])
                             : (result[original_index] = input[endoced_index]);
        }
    }
    return result;
}

char *encode(char *input, size_t rails) { return cipher(input, rails, ENCODE); }

char *decode(char *input, size_t rails) { return cipher(input, rails, DECODE); }
