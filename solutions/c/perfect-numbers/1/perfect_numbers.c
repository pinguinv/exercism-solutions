#include "perfect_numbers.h"

kind classify_number(int number)
{
    if (number < 1)
        return ERROR;

    int aliquot_sum = 0;

    for (int i = 1; i < (number / 2) + 1; i++)
    {
        if (!(number % i))
            aliquot_sum += i;
    }
    if (aliquot_sum == number)
        return PERFECT_NUMBER;

    if (aliquot_sum < number)
        return DEFICIENT_NUMBER;

    if (aliquot_sum > number)
        return ABUNDANT_NUMBER;

    return ERROR;
}