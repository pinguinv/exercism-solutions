#include "secret_handshake.h"

#include <stdlib.h>

#define REVERSE_MASK 16
#define ACTIONS_COUNT 4

static const char masks[] = {1, 2, 4, 8};
static const char actions[ACTIONS_COUNT][16] = {"wink", "double blink", "close your eyes", "jump"};

const char **commands(size_t number)
{
    const char **result = malloc(ACTIONS_COUNT * sizeof(char *));

    if (!result)
        return NULL;

    for (size_t i = 0; i < ACTIONS_COUNT; i++)
        result[i] = NULL;

    short i = 0, j = 0, step = 1;

    if (number & REVERSE_MASK)
    {
        i = 3;
        step = -1;
    }

    while (i >= 0 && i < ACTIONS_COUNT)
    {
        if (number & masks[i])
            result[j++] = actions[i];

        i += step;
    }

    return result;
}