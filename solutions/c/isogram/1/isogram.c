#include "isogram.h"

bool is_isogram(const char phrase[])
{
    if (phrase == NULL)
        return false;

    int phrase_len = 0;
    int letter_counts[26] = {0};

    for (int i = 0; phrase[i] != '\0'; i++)
    {
        if (phrase[i] >= 'a' && phrase[i] <= 'z')
        {
            phrase_len++;
            letter_counts[phrase[i] - 'a'] = 1;
        }

        if (phrase[i] >= 'A' && phrase[i] <= 'Z')
        {
            phrase_len++;
            letter_counts[phrase[i] - 'A'] = 1;
        }
    }

    int sum_letter_counts = 0;

    for (int i = 0; i < 26; i++)
        sum_letter_counts += letter_counts[i];

    return phrase_len == sum_letter_counts;
}