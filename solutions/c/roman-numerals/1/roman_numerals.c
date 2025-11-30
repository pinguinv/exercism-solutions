#include "roman_numerals.h"

#include <stdlib.h>
#include <stdbool.h>

// The longest possible roman number is 'MMMDCCCLXXXVIII'
// - it has 15 chars + 1 char '\0' = 16 chars
#define MAX_ROMAN_LENGTH 16

static char roman_digits[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
static unsigned short arabic_values[] = {1000, 500, 100, 50, 10, 5, 1};

static unsigned short exceptions_values[] = {900, 400, 90, 40, 9, 4};
static char exceptions_roman[][2] = {"CM", "CD", "XC", "XL", "IX", "IV"};

char *to_roman_numeral(unsigned int number)
{
    char *roman_numeral = calloc(MAX_ROMAN_LENGTH, sizeof(char));

    size_t i = 0, i_res = 0;

    while (number)
    {
        if (number / arabic_values[i] >= 1)
        {
            roman_numeral[i_res++] = roman_digits[i];
            number -= arabic_values[i];
            i = 0;
            continue;
        }

        bool reset_i = false;

        // Check for exceptions
        for (size_t j = 0; j < 6; j++)
        {
            unsigned short possible_e = exceptions_values[j];

            // 100, 10 or 1
            size_t order_of_magnitude_index = 2 + (j / 2) * 2;
            // Reminder of division must be smaller than 100 for 900 & 400, 10 for 90 & 40, 1 for 9 & 4
            if (number % possible_e < arabic_values[order_of_magnitude_index] && number / possible_e == 1)
            {
                roman_numeral[i_res++] = exceptions_roman[j][0];
                roman_numeral[i_res++] = exceptions_roman[j][1];
                number -= possible_e;

                reset_i = true;
                break;
            }
        }

        if (reset_i)
        {
            i = 0;
            continue;
        }

        i++;
    }

    return roman_numeral;
}