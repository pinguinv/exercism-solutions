#include "spiral_matrix.h"
#include <string.h>

spiral_matrix_t *spiral_matrix_create(int size)
{
    spiral_matrix_t *result_matrix = (spiral_matrix_t *)calloc(1, sizeof(spiral_matrix_t));
    result_matrix->size = size;

    if (size < 1)
        return result_matrix;

    result_matrix->matrix = (int **)calloc(size, sizeof(int *));

    for (int i = 0; i < size; i++)
        result_matrix->matrix[i] = (int *)calloc(size, sizeof(int));

    int x = 0, y = 0;
    int x_step = 1, y_step = 0;

    for (int number = 1; number <= size * size; number++)
    {
        result_matrix->matrix[y][x] = number;

        int new_x = x + x_step;
        int new_y = y + y_step;

        if (new_x < 0 || new_x >= size || new_y < 0 || new_y >= size || result_matrix->matrix[new_y][new_x] != 0)
        {
            int temp = -y_step;
            y_step = x_step;
            x_step = temp;
        }

        x += x_step;
        y += y_step;
    }

    return result_matrix;
}

void spiral_matrix_destroy(spiral_matrix_t *matrix)
{
    for (int i = 0; i < matrix->size; i++)
        free(matrix->matrix[i]);

    free(matrix->matrix);
    free(matrix);
}