#include "run_length_encoding.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stddef.h>

char *encode(const char *text)
{
    if (!text)
        return NULL;

    char encoded[0xff];
    char curr_letter;
    size_t encoded_len = 0;
    size_t curr_letter_count;
    size_t chunk_len;
    char *result;

    for (const char *c = text; *c;)
    {
        curr_letter = *c;
        // clang-format off
        for (curr_letter_count = 0; c[curr_letter_count] == curr_letter; curr_letter_count++);
        // clang-format on

        if (curr_letter_count == 1)
            sprintf(&encoded[encoded_len++], "%c", curr_letter);
        else
        {
            chunk_len = log10(curr_letter_count) + 2;
            sprintf(&encoded[encoded_len], "%ld%c", curr_letter_count, curr_letter);
            encoded_len += chunk_len;
        }

        c += curr_letter_count;
    }

    result = calloc(encoded_len + 1, sizeof(char));

    if (!result)
        return NULL;

    strcpy(result, encoded);

    return result;
}

char *decode(const char *data)
{
    if (!data)
        return NULL;

    char decoded[0xff];
    size_t decoded_len = 0;
    size_t curr_char_count;
    size_t curr_chunk_len;
    char *result;

    for (const char *c = data; *c;)
    {
        curr_char_count = atoi(c);

        // second check (' ' == *c) is here to prevent
        // ignoring singular whitespace in front of a number
        // atoi() func ignores spaces and leads to incorrect results
        if (curr_char_count == 0 || ' ' == *c)
        {
            decoded[decoded_len++] = *c;
            c++;
        }
        else
        {
            curr_chunk_len = log10(curr_char_count) + 1;

            memset(&decoded[decoded_len], *(c + curr_chunk_len), curr_char_count);
            decoded_len += curr_char_count;

            c += curr_chunk_len + 1;
        }
    }

    result = calloc(decoded_len + 1, sizeof(char));

    if (!result)
        return NULL;

    strncpy(result, decoded, decoded_len);

    return result;
}