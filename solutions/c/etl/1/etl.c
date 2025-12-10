#include "etl.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int compare_maps(const void *a, const void *b)
{
    return (*(const new_map *)a).key - (*(const new_map *)b).key;
}

int convert(const legacy_map *input, const size_t input_len, new_map **output)
{
    size_t new_map_length = 0;
    short output_i = 0;

    for (size_t i = 0; i < input_len; i++)
        new_map_length += strlen(input[i].keys);

    (*output) = calloc(new_map_length, sizeof(new_map));

    if (!(*output))
        return -1;

    for (size_t i = 0; i < input_len; i++)
    {
        legacy_map l_map = input[i];
        int l_map_value = l_map.value;

        for (size_t j = 0; j < strlen(l_map.keys); j++)
        {
            new_map n_map = {.key = tolower(l_map.keys[j]), .value = l_map_value};
            (*output)[output_i++] = n_map;
        }
    }

    qsort(*output, new_map_length, sizeof(new_map), compare_maps);

    return new_map_length;
}
