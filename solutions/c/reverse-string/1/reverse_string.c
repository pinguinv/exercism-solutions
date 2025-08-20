#include "reverse_string.h"

char *reverse(const char *value)
{
    size_t len = strlen(value);
    char *reversed = calloc(len + 1, sizeof(char));

    for (size_t i = 0; i < len; i++)
    {
        reversed[(len - 1) - i] = value[i];
    }

    return reversed;
}
