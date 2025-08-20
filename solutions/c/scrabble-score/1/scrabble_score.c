#include "scrabble_score.h"

unsigned int score(const char *word)
{
    size_t word_length = strlen(word);

    if (word_length == 0)
        return 0;

    char word_cpy[word_length + 1];
    strcpy(word_cpy, word);

    for (size_t i = 0; i < word_length; i++)
    {
        char ch = word_cpy[i];

        if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')))
            return 0;

        if (ch >= 'a' && ch <= 'z')
        {
            ch -= 'a' - 'A';
            word_cpy[i] = ch;
        }
    }

    int word_score = 0;

    for (size_t i = 0; i < word_length; i++)
    {
        char ch = word_cpy[i];

        switch (ch)
        {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'L':
        case 'N':
        case 'R':
        case 'S':
        case 'T':
            word_score += 1;
            break;

        case 'D':
        case 'G':
            word_score += 2;
            break;

        case 'B':
        case 'C':
        case 'M':
        case 'P':
            word_score += 3;
            break;

        case 'F':
        case 'H':
        case 'V':
        case 'W':
        case 'Y':
            word_score += 4;
            break;

        case 'K':
            word_score += 5;
            break;

        case 'J':
        case 'X':
            word_score += 8;
            break;

        case 'Q':
        case 'Z':
            word_score += 10;
            break;

        default:
            word_score += 0;
            break;
        }
    }
    return word_score;
}