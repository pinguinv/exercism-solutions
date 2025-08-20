#include "pangram.h"

bool is_pangram(const char *sentence)
{
    if (!sentence)
        return false;

    int letter_present[26] = {0};
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] >= 'A' && sentence[i] <= 'Z')
        {
            letter_present[sentence[i] - 'A'] = 1;
            continue;
        }

        if (sentence[i] >= 'a' && sentence[i] <= 'z')
        {
            letter_present[sentence[i] - 'a'] = 1;
            continue;
        }
    }

    int sum_of_letter_present = 0;
    for (int i = 0; i < 26; i++)
        sum_of_letter_present += letter_present[i];

    return sum_of_letter_present == 26;
}