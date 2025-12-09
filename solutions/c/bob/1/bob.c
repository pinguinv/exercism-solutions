#include "bob.h"

#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char *hey_bob(char *greeting)
{
    size_t greeting_len = strlen(greeting);

    char last_non_blank = '\0';
    bool all_whitespace = true;
    bool all_capital = false;

    // Check if there's any non-blank char
    // & save the last one to check if it's question mark
    for (size_t i = 0; i < greeting_len; i++)
    {
        char c = greeting[i];

        if (!isspace(c))
        {
            all_whitespace = false;
            last_non_blank = c;
        }
    }

    // Check if there's any alpha char that's not uppercase
    for (size_t i = 0; i < greeting_len; i++)
    {
        char c = greeting[i];

        if (isalpha(c))
            all_capital = true;

        if (islower(c))
        {
            all_capital = false;
            break;
        }
    }

    if (all_whitespace)
        return "Fine. Be that way!";

    if (last_non_blank == '?' && all_capital)
        return "Calm down, I know what I'm doing!";

    if (last_non_blank == '?')
        return "Sure.";

    if (all_capital)
        return "Whoa, chill out!";

    return "Whatever.";
}