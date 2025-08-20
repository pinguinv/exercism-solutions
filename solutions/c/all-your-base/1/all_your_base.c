#include "all_your_base.h"

#include <stdio.h>

static int i_pow(int x, int y)
{
    int result = 1;
    while (y > 0)
    {
        result *= x;
        y--;
    }

    return result;
}

size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base, int16_t output_base, size_t input_length)
{
    if (input_length < 1 || input_base < 2 || output_base < 2)
        return 0;

    for (size_t i = 0; i < input_length; i++)
        if (digits[i] < 0 || digits[i] >= input_base)
            return 0;

    int decimal_value = 0;

    for (int i = (int)input_length - 1; i >= 0; i--)
    {
        decimal_value += i_pow(input_base, (input_length - 1) - i) * (int)(digits[i]);
        digits[i] = 0;
    }

    int16_t output_length = 0;

    for (int i = decimal_value; i > 0; i /= output_base)
        output_length++;

    if (input_length > 0 && output_length == 0)
        output_length = 1;

    for (int i = output_length - 1; i >= 0; i--)
    {
        digits[i] = decimal_value % output_base;
        decimal_value /= output_base;
    }

    return output_length;
}