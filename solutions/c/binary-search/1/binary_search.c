#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length)
{
    int mid_index = length / 2, start_index = 0, end_index = length - 1;

    if (length < 1)
        return NULL;

    while (arr[mid_index] != value)
    {
        if (start_index == end_index)
            return NULL;

        if (value > arr[mid_index])
            start_index = mid_index + 1;
        else
            end_index = mid_index - 1;
        mid_index = start_index + (end_index - start_index) / 2;
    }

    return &arr[mid_index];
}
