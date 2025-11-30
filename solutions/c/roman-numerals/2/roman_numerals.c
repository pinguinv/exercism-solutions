#include "roman_numerals.h"

#include <stdlib.h>
#include <string.h>

// The longest possible roman number is 'MMMDCCCLXXXVIII'
// - it has 15 chars + 1 char '\0' = 16 chars
#define MAX_ROMAN_LENGTH 16

// clang-format off
static const Arab_roman_pair pairs[13] = {
    {1000, "M", 1}, {900, "CM", 2}, {500, "D", 1}, 
    {400, "CD", 2}, {100, "C", 1}, {90, "XC", 2},
    {50, "L", 1}, {40, "XL", 2}, {10, "X", 1},
    {9, "IX", 2}, {5, "V", 1}, {4, "IV", 2},
    {1, "I", 1}};
// clang-format on

char *to_roman_numeral(unsigned int number)
{
    if (number == 0 || number > 3999)
        return "";

    char *roman_numeral = calloc(MAX_ROMAN_LENGTH, sizeof(char)), *end_pointer = roman_numeral;

    if (!roman_numeral)
        return NULL;

    for (size_t i = 0; i < 13; i++)
    {
        Arab_roman_pair pair = pairs[i];

        while (number >= pair.arab)
        {
            memcpy(end_pointer, pair.roman, pair.roman_len);
            end_pointer += pair.roman_len;
            number -= pair.arab;
        }
    }

    return roman_numeral;
}