#include "luhn.h"

bool luhn(const char *num)
{
    int full_len = strlen(num);

    int trimmed_len = 0;
    char trimmed[255] = {' '};

    for (int i = 0; i < full_len; i++)
    {
        char digit = num[i];
        if (!(digit >= '0' && digit <= '9') && digit != ' ')
            return false;

        if (digit != ' ')
            trimmed[trimmed_len++] = digit;

        if (trimmed_len > 255)
            return false;
    }

    if (trimmed_len <= 1)
        return false;

    for (int i = trimmed_len - 2; i >= 0; i -= 2)
    {
        char dig = (trimmed[i] - '0') * 2;
        trimmed[i] = (dig > 9 ? dig - 9 : dig) + '0';
    }

    int checksum = 0;

    for (int i = 0; i < trimmed_len; i++)
        checksum += trimmed[i] - '0';

    return checksum % 10 == 0;
}