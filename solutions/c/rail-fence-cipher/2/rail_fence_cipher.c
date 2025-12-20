#include "rail_fence_cipher.h"

#include <stdlib.h>
#include <string.h>

char *encode(char *text, size_t rails)
{
    if (text == NULL || rails == 0)
        return NULL;

    size_t text_len = strlen(text);

    if (text_len == 0)
        return "";

    char fence[rails][text_len + 1];
    memset(fence, 0, rails * (text_len + 1));

    // Set in zigzag pattern
    size_t y_index = 0;
    int y_step = 0;
    for (size_t i = 0; i < text_len; i++)
    {
        y_index += y_step;

        fence[y_index][i] = text[i];

        if (y_index == 0)
            y_step = 1;
        else if (y_index == rails - 1)
            y_step = -1;
    }

    size_t encoded_index = 0;
    char *encoded = calloc(text_len + 1, sizeof(char));

    if (!encoded)
        return NULL;

    // Read chars to 'encoded' row by row
    for (size_t i = 0; i < rails; i++)
        for (size_t j = 0; j < text_len; j++)
            if (fence[i][j] != 0)
                encoded[encoded_index++] = fence[i][j];

    return encoded;
}

char *decode(char *ciphertext, size_t rails)
{

    if (ciphertext == NULL || rails == 0)
        return NULL;

    size_t text_len = strlen(ciphertext);

    if (text_len == 0)
        return "";

    char fence[rails][text_len + 1];
    memset(fence, 0, rails * (text_len + 1));

    // Write zigzag pattern row by row
    size_t n_positions = 2 * rails - 2;
    size_t text_i = 0;
    for (size_t i = 0; i < rails; i++)
    {
        for (size_t j = 0; j < text_len; ++j)
        {
            size_t position = j % n_positions;
            if (position == i)
            {
                fence[i][j] = ciphertext[text_i++];
            }
            else if (position == n_positions - i)
            {
                fence[i][j] = ciphertext[text_i++];
            }
        }
    }

    size_t decoded_index = 0;
    char *decoded = calloc(text_len + 1, sizeof(char));

    if (!decoded)
        return NULL;

    // Read chars to 'decoded' column by column (zigzag pattern)
    for (size_t i = 0; i < text_len; i++)
        for (size_t j = 0; j < rails; j++)
            if (fence[j][i] != 0)
                decoded[decoded_index++] = fence[j][i];

    return decoded;
}
