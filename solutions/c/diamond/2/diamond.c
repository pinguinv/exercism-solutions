#include "diamond.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>

char **make_diamond(const char letter)
{
    assert(letter >= 'A' && letter <= 'Z');

    const char letter_index = letter - 'A';
    const size_t arr_size = letter_index * 2 + 1;

    // arr_size + 1 => keep last index empty ('\0') so it can be
    // iterated over just like string while freeing memory,
    // without assuming correct input to the 'free_diamond' func
    char **const result = calloc(arr_size + 1, sizeof(char *));

    if (!result)
        return NULL;

    const size_t mid_col = arr_size / 2;

    for (size_t i = 0; i < arr_size; i++)
    {
        result[i] = calloc(arr_size + 1, sizeof(char));

        if (!result[i])
        {
            for (size_t j = 0; j < i; j++)
                free(result[j]);
            free(result);

            return NULL;
        }

        memset(result[i], ' ', arr_size);

        size_t c_offset = i <= mid_col ? i : arr_size - 1 - i;

        result[i][mid_col - c_offset] = 'A' + c_offset;
        result[i][mid_col + c_offset] = 'A' + c_offset;
    }

    return result;
}

void free_diamond(char **diamond)
{
    for (size_t i = 0; diamond[i]; i++)
        free(diamond[i]);
    free(diamond);
}