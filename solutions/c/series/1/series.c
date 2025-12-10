#include "series.h"

#include <stdlib.h>
#include <string.h>

slices_t slices(char *input_text, unsigned int substring_length)
{
    slices_t result = {.substring = NULL, .substring_count = 0};

    size_t input_len = strlen(input_text);

    if (substring_length > input_len || substring_length == 0)
        return result;

    // Calculate number of substrings
    size_t substring_count = input_len - substring_length + 1;

    result.substring_count = substring_count;
    result.substring = calloc(substring_count, sizeof(char *));

    if (!result.substring)
    {
        result.substring_count = 0;
        return result;
    }

    for (size_t i = 0; i < substring_count; i++)
    {
        result.substring[i] = calloc(substring_length + 1, sizeof(char));

        if (!result.substring[i])
        {
            result.substring_count = 0;
            return result;
        }
    }

    for (size_t i = 0; i < substring_count; i++)
        memmove(result.substring[i], input_text + i, substring_length);

    return result;
}
