#include "spiral_matrix.h"

static int *get_new_position(int x, int y, direction_t dir)
{

    int *position = (int *)malloc(sizeof(int) * 2);

    switch (dir)
    {
    case right:
        x += 1;
        break;

    case down:
        y += 1;
        break;

    case left:
        x -= 1;
        break;

    case up:
        y -= 1;
        break;

    default:
        break;
    }

    position[0] = x;
    position[1] = y;

    return position;
}

static bool can_go_forward(spiral_matrix_t *matrix, int x, int y, direction_t dir)
{
    int *position = get_new_position(x, y, dir);

    x = position[0];
    y = position[1];

    free(position);

    if (x < 0 || x >= matrix->size || y < 0 || y >= matrix->size)
        // not within the matrix
        return false;

    return matrix->matrix[y][x] == 0;
}

spiral_matrix_t *spiral_matrix_create(int size)
{
    spiral_matrix_t *result_matrix = (spiral_matrix_t *)calloc(1, sizeof(spiral_matrix_t));
    result_matrix->size = size;

    if (size < 1)
    {
        result_matrix->matrix = NULL;
        return result_matrix;
    }

    result_matrix->matrix = (int **)calloc(size, sizeof(int *));

    for (int i = 0; i < size; i++)
        result_matrix->matrix[i] = (int *)calloc(size, sizeof(int));

    int x = -1, y = 0, number = 1;
    direction_t dir = 0;

    while (true)
    {
        while (can_go_forward(result_matrix, x, y, dir))
        {
            int *position = get_new_position(x, y, dir);

            x = position[0];
            y = position[1];

            free(position);

            result_matrix->matrix[y][x] = number++;
        }

        dir = (dir + 1) % 4;

        if (!can_go_forward(result_matrix, x, y, dir))
            break;
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