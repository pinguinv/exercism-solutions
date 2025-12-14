#include "diamond.h"

#include <stdlib.h>
#include <string.h>

char **make_diamond(const char letter)
{
    char letter_index = letter - 'A';

    if (letter_index < 0 || letter_index > 25)
        return NULL;

    size_t arr_size = letter_index * 2 + 1;

    char **result = calloc(arr_size + 1, sizeof(char *));

    for (size_t i = 0; i < arr_size; i++)
    {
        result[i] = calloc(arr_size + 1, sizeof(char));
        memset(result[i], ' ', arr_size);
    }

    size_t mid = arr_size / 2;

    for (size_t i = 0; i < arr_size; i++)
    {
        size_t offset = i <= mid ? i : arr_size - 1 - i;

        result[i][mid - offset] = 'A' + offset;
        result[i][mid + offset] = 'A' + offset;
    }

    return result;
}

void free_diamond(char **diamond)
{
    for (size_t i = 0; diamond[i] != NULL; i++)
        free(diamond[i]);
    free(diamond);
}