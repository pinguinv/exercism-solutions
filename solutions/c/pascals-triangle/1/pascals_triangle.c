#include "pascals_triangle.h"

#include <stdlib.h>

void free_triangle(uint8_t **triangle, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
        free(triangle[i]);

    free(triangle);
}

uint8_t **create_triangle(size_t rows)
{
    // Edge case - 0 rows

    if (rows == 0)
    {
        uint8_t **empty_arr = malloc(sizeof(uint8_t *));
        empty_arr[0] = calloc(1, sizeof(uint8_t));
        return empty_arr;
    }

    // Create triangle

    uint8_t **triangle_ptr = malloc(rows * sizeof(uint8_t *));

    for (size_t i = 0; i < rows; i++)
        triangle_ptr[i] = (uint8_t *)calloc(rows, sizeof(uint8_t));

    // Fill walls of the triangle with 1s

    for (size_t i = 0; i < rows; i++)
    {
        triangle_ptr[i][0] = 1;
        triangle_ptr[i][i] = 1;
    }

    // Calculate subsequent numbers in rows

    // i = 2 because numbers different than 1 gonna appear from 3'rd row
    for (size_t i = 2; i < rows; i++)
        for (size_t j = 1; j < rows - 1; j++)
            triangle_ptr[i][j] = triangle_ptr[i - 1][j - 1] + triangle_ptr[i - 1][j];

    return triangle_ptr;
}
