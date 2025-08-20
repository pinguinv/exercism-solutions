#include "saddle_points.h"

static bool is_shortest_in_column(uint8_t rows, uint8_t columns,
                                  uint8_t matrix[rows][columns],
                                  uint8_t column_index,
                                  uint8_t tree_height)
{
    for (uint8_t row_i = 0; row_i < rows; row_i++)
        if (tree_height > matrix[row_i][column_index])
            return false;

    return true;
}

saddle_points_t *saddle_points(uint8_t rows, uint8_t columns,
                               uint8_t matrix[rows][columns])
{
    saddle_points_t *saddle_points = (saddle_points_t *)malloc(sizeof(saddle_points_t));
    saddle_points->count = 0;

    // count acceptable trees
    for (uint8_t row_i = 0; row_i < rows; row_i++)
    {
        // find tallest tree in the row
        uint8_t tallest_tree_in_row = 0;
        for (uint8_t col_i = 0; col_i < columns; col_i++)
            if (matrix[row_i][col_i] > tallest_tree_in_row)
                tallest_tree_in_row = matrix[row_i][col_i];

        for (uint8_t col_i = 0; col_i < columns; col_i++)
        {
            if (matrix[row_i][col_i] != tallest_tree_in_row)
                continue;

            if (is_shortest_in_column(rows, columns, matrix, col_i, tallest_tree_in_row))
                saddle_points->count++;
        }
    }

    saddle_points->points = malloc(sizeof(saddle_point_t) * saddle_points->count);

    // get acceptable trees' rows and columns
    if (saddle_points->count == 0)
        return saddle_points;

    uint8_t point_index = 0;

    for (uint8_t row_i = 0; row_i < rows; row_i++)
    {
        // find tallest tree in the row
        uint8_t tallest_tree_in_row = 0;
        for (uint8_t col_i = 0; col_i < columns; col_i++)
            if (matrix[row_i][col_i] > tallest_tree_in_row)
                tallest_tree_in_row = matrix[row_i][col_i];

        for (uint8_t col_i = 0; col_i < columns; col_i++)
        {
            if (matrix[row_i][col_i] != tallest_tree_in_row)
                continue;

            if (is_shortest_in_column(rows, columns, matrix, col_i, tallest_tree_in_row))
            {
                saddle_point_t s_p = {
                    .row = row_i + 1,
                    .column = col_i + 1};

                saddle_points->points[point_index++] = s_p;
            }
        }
    }

    return saddle_points;
}

void free_saddle_points(saddle_points_t *saddle_points)
{
    free(saddle_points->points);
    free(saddle_points);
}
