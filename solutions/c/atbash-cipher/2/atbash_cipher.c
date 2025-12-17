#include "atbash_cipher.h"

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *atbash_encode(const char *input)
{
    size_t input_len;

    if (input == NULL || (input_len = strlen(input)) == 0)
        return NULL;

    // `+ input_len / 5` - for every 5 chars in the input allocate
    // 1 additional char for spece = make sure that resulting string
    // won't exceed allocated space
    char *result = calloc(input_len + 1 + input_len / 5, sizeof(char));

    if (result == NULL)
        return NULL;

    size_t r_index = 0;

    for (size_t i = 0, chunk_len = 0; i < input_len; i++)
    {
        char c = input[i];

        if (!isalnum(c))
            continue;

        if (chunk_len && chunk_len % 5 == 0)
        {
            result[r_index++] = ' ';
            chunk_len = 0;
        }

        if (isalpha(c))
            result[r_index++] = 'z' - (tolower(c) - 'a');
        else
            result[r_index++] = c;

        chunk_len++;
    }

    return result;
}

char *atbash_decode(const char *input)
{
    size_t input_len;

    if (input == NULL || (input_len = strlen(input)) == 0)
        return NULL;

    char *result = calloc(input_len + 1, sizeof(char));

    if (result == NULL)
        return NULL;

    for (size_t i = 0, r_index = 0; i < input_len; i++)
    {
        char c = input[i];

        if (isalpha(c))
            result[r_index++] = 'a' + ('z' - c);

        if ((c >= '0' && c <= '9'))
            result[r_index++] = c;
    }

    return result;
}