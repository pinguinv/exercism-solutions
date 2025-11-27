#include "acronym.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ABB_LENGTH 64

char *abbreviate(const char *phrase)
{
    size_t phrase_len;

    if (phrase == NULL || (phrase_len = strlen(phrase)) == 0)
        return NULL;

    char *abbreviation = calloc(MAX_ABB_LENGTH, sizeof(char));

    if (abbreviation == NULL)
        return NULL;

    size_t i = 0, j = 0;
    bool next_word = true;

    while (i < phrase_len)
    {
        char c = phrase[i];

        if (!isalpha(c) && c != '\'')
            next_word = true;

        if (next_word && isalpha(c))
        {
            abbreviation[j++] = toupper(c);
            next_word = false;
        }

        i++;
    }

    return abbreviation;
}
