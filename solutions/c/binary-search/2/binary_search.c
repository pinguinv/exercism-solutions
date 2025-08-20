#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length)
{
    int left_i = 0, right_i = length - 1, mid_i = length / 2;

    while (left_i <= right_i)
    {
        if (arr[mid_i] == value)
            return &arr[mid_i];

        if (value > arr[mid_i])
            left_i = mid_i + 1;
        else
            right_i = mid_i - 1;
        mid_i = (left_i + right_i) / 2;
    }

    return NULL;
}