#include "phone_number.h"
#include "stdlib.h"
#include "memory.h"
#include "stdint.h"
#include "stdbool.h"

static const char *NUMBERS = "0123456789";

static bool is_digit(char c)
{
    for (uint8_t i = 0; i < 10; i++)
        if (NUMBERS[i] == c)
            return true;

    return false;
}

static uint8_t count_digits(const char *input)
{
    uint8_t digits = 0, i = 0;

    while (input[i])
    {
        if (is_digit(input[i]))
            digits++;

        i++;
    }

    return digits;
}

char *phone_number_clean(const char *input)
{
    uint8_t digit_count = count_digits(input);

    char *only_digits = (char *)malloc(11 * sizeof(char));
    memset(only_digits, '0', 10);
    only_digits[10] = '\0';

    // invalid digit count
    if (digit_count < 10 || digit_count > 11)
        return only_digits;

    size_t first_digit_index;

    for (uint8_t i = 0; input[i]; i++)
        if (is_digit(input[i]))
        {
            first_digit_index = i;
            break;
        }

    // 11 digits do not start with 1
    if (digit_count == 11 && input[first_digit_index] != '1')
        return only_digits;

    uint8_t only_digits_i = 0;

    for (uint8_t i = digit_count == 11 ? first_digit_index + 1 : 0; input[i]; i++)
        if (is_digit(input[i]))
            only_digits[only_digits_i++] = input[i];

    if (
        // area code starts with 0 or 1
        only_digits[0] == '0' ||
        only_digits[0] == '1' ||
        // exchange code starts with 0 or 1
        only_digits[3] == '0' ||
        only_digits[3] == '1')
    {
        memset(only_digits, '0', 10);
    }

    return only_digits;
}
