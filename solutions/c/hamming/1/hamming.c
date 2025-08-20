#include "hamming.h"

int compute(const char *lhs, const char *rhs)
{
    int len_l = 0;
    while (lhs[len_l] != '\0')
        len_l++;

    int len_r = 0;
    while (rhs[len_r] != '\0')
        len_r++;

    int error_val = -1;

    if (len_l != len_r)
        return error_val;

    int hamming_distance = 0;

    for (int i = 0; i < len_l; i++)
        hamming_distance += lhs[i] != rhs[i] ? 1 : 0;

    return hamming_distance;
}