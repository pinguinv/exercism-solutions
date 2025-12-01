#include "anagram.h"

#include <string.h>
#include <ctype.h>
#include <stdbool.h>

static bool is_pair_of_anagrams(const char *word1, const char *word2, size_t len)
{
    bool same_words = true;
    char word1_chars[len + 1];

    for (size_t i = 0; i < len + 1; i++)
    {
        word1_chars[i] = tolower(word1[i]);

        if (word1_chars[i] != tolower(word2[i]))
            same_words = false;
    }

    if (same_words)
        return false;

    for (size_t i = 0; i < len; i++)
    {
        char c = word2[i];

        for (size_t j = 0; j < len; j++)
            if (tolower(word1_chars[j]) == tolower(c))
            {
                memmove(word1_chars + j, word1_chars + j + 1, len - j);
                break;
            }
    }

    return strlen(word1_chars) == 0;
}

void find_anagrams(const char *subject, struct candidates *candidates)
{
    size_t len = strlen(subject);

    for (size_t i = 0; i < candidates->count; i++)
    {
        candidates->candidate[i].is_anagram = NOT_ANAGRAM;

        if (strlen(candidates->candidate[i].word) != len)
            continue;

        if (is_pair_of_anagrams(subject, candidates->candidate[i].word, len))
            candidates->candidate[i].is_anagram = IS_ANAGRAM;
    }
}
