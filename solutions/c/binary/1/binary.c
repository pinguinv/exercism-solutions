#include "binary.h"

static int i_pow(int x, int y)
{
    int result = 1;
    for (int i = 0; i < y; i++)
        result *= x;

    return result;
}

int convert(const char *input)
{
    int input_len = 0;
    while (input[input_len] != '\0')
        input_len++;

    int result = 0;

    for (int i = input_len - 1; i >= 0; i--)
    {
        if (input[i] != '1' && input[i] != '0')
            return INVALID;

        if (input[i] == '1')
            result += i_pow(2, (input_len - 1) - i);
    }

    return result;
}