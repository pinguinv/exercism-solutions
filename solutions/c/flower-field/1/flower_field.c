#include "flower_field.h"

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static uint8_t count_adjacent_flowers(char **garden,
                                      size_t rows,
                                      size_t columns,
                                      int16_t x_index,
                                      int16_t y_index)
{
    uint8_t result = 0;

    for (int16_t d_y = -1; d_y <= 1; d_y++)
    {
        int16_t curr_y = y_index + d_y;
        if (curr_y < 0 || (int32_t)curr_y >= (int32_t)rows)
            continue;

        for (int16_t d_x = -1; d_x <= 1; d_x++)
        {
            if (d_y == 0 && d_x == 0)
                continue;

            int16_t curr_x = x_index + d_x;

            if (curr_x < 0 || (int32_t)curr_x >= (int32_t)columns)
                continue;

            result += garden[curr_y][curr_x] == '*' ? 1 : 0;
        }
    }

    return result;
}

char **annotate(const char **garden, const size_t rows)
{
    if (!garden)
        return NULL;

    size_t columns = strlen(garden[0]);

    char **const annotation = calloc(rows + 1, sizeof(char *));

    if (!annotation)
        return NULL;

    for (size_t i = 0; i < rows; i++)
    {
        annotation[i] = calloc(columns + 1, sizeof(char));

        if (!annotation[i])
        {
            for (size_t j = 0; j < i; j++)
                free(annotation[j]);
            free(annotation);

            return NULL;
        }

        memmove(annotation[i], garden[i], columns);
    }

    // Actual annotations

    for (int16_t y = 0; (int32_t)y < (int32_t)rows; y++)
        for (int16_t x = 0; (int32_t)x < (int32_t)columns; x++)
        {
            if (annotation[y][x] == '*')
                continue;

            uint8_t count = count_adjacent_flowers(annotation, rows, columns, x, y);

            if (count != 0)
                annotation[y][x] = '0' + count;
        }

    return annotation;
}

void free_annotation(char **annotation)
{
    for (size_t i = 0; annotation[i]; i++)
        free(annotation[i]);
    free(annotation);
}