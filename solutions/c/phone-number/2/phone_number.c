#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "phone_number.h"

static const int MAX_LENGTH = 11;
static const int AREA_CODE_OFFSET = 0;
static const int EXCHANGE_CODE_OFFSET = 3;

static bool clean(char *cleaned, const char *input)
{
    uint8_t input_lenght = strlen(input);
    uint8_t digit_count = 0;

    for (uint8_t i = 0; i < input_lenght; i++)
    {
        if (digit_count >= MAX_LENGTH)
            return false;

        if (isdigit(input[i]))
            cleaned[digit_count++] = input[i];
        else if (isalpha(input[i]))
            return false;
    }

    // invalid digit count
    if (digit_count < 10)
        return false;

    if (digit_count == 11)
    {
        // if country code is 1, move one char to the left
        if (cleaned[0] == '1')
            memmove(cleaned, &cleaned[AREA_CODE_OFFSET + 1], MAX_LENGTH);
        else
            return false;
    }

    char area_code = cleaned[AREA_CODE_OFFSET];
    char exchange_code = cleaned[EXCHANGE_CODE_OFFSET];

    if (
        // area code starts with 0 or 1
        area_code == '0' || area_code == '1'
        // exchange code starts with 0 or 1
        || exchange_code == '0' || exchange_code == '1')
    {
        return false;
    }

    return true;
}

char *phone_number_clean(const char *input)
{
    char *cleaned = (char *)calloc(MAX_LENGTH + 1, sizeof(char));

    if (!clean(cleaned, input))
        strcpy(cleaned, "0000000000");

    return cleaned;
}
