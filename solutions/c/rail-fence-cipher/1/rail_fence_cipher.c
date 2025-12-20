#include "rail_fence_cipher.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static char **create_rail_fence(char *text, size_t rails, fence_fill_t fill_type)
{
    size_t text_len = strlen(text);

    char **rail_fence = malloc(rails * sizeof(char *));

    if (!rail_fence)
        return NULL;

    for (size_t i = 0; i < rails; i++)
    {
        rail_fence[i] = malloc((text_len + 1) * sizeof(char));

        if (!rail_fence[i])
        {
            // Free previously allocated memory
            for (size_t j = 0; j < i; j++)
                free(rail_fence[j]);
            free(rail_fence);

            return NULL;
        }

        memset(rail_fence[i], '.', text_len);
        // Set null terminators at the ends of strings
        rail_fence[i][text_len] = 0;
    }

    size_t y_index = 0;
    int y_step = 0;
    for (size_t i = 0; i < text_len; i++)
    {
        y_index += y_step;

        rail_fence[y_index][i] = '?';

        if (y_index == 0)
            y_step = 1;
        else if (y_index == rails - 1)
            y_step = -1;
    }

    size_t text_i = 0;

    switch (fill_type)
    {
    case ROWS:
        for (size_t i = 0; i < rails; i++)
            for (size_t j = 0; j < text_len; j++)
                if (rail_fence[i][j] == '?')
                    rail_fence[i][j] = text[text_i++];
        break;

    case ZIGZAG:
    default:
        for (size_t i = 0; i < text_len; i++)
            for (size_t j = 0; j < rails; j++)
                if (rail_fence[j][i] == '?')
                    rail_fence[j][i] = text[text_i++];
        break;
    }

    return rail_fence;
}

char *encode(char *text, size_t rails)
{
    if (text == NULL || rails == 0)
        return NULL;

    size_t input_len = strlen(text);

    if (input_len == 0)
        return "";

    char *encoded = calloc(input_len + 1, sizeof(char));
    size_t encoded_index = 0;

    if (!encoded)
        return NULL;

    char **fence = create_rail_fence(text, rails, ZIGZAG);

    if (!fence)
        return NULL;

    for (size_t i = 0; i < rails; i++)
        for (size_t j = 0; j < input_len; j++)
            if (isalpha(fence[i][j]))
                encoded[encoded_index++] = fence[i][j];

    for (size_t i = 0; i < rails; i++)
        free(fence[i]);
    free(fence);

    return encoded;
}

char *decode(char *ciphertext, size_t rails)
{

    if (ciphertext == NULL || rails == 0)
        return NULL;

    size_t input_len = strlen(ciphertext);

    if (input_len == 0)
        return "";

    char *decoded = calloc(input_len + 1, sizeof(char));
    size_t decoded_index = 0;

    if (!decoded)
        return NULL;

    char **fence = create_rail_fence(ciphertext, rails, ROWS);

    if (!fence)
        return NULL;

    for (size_t i = 0; i < input_len; i++)
        for (size_t j = 0; j < rails; j++)
            if (isalnum(fence[j][i]))
                decoded[decoded_index++] = fence[j][i];

    for (size_t i = 0; i < rails; i++)
        free(fence[i]);
    free(fence);

    return decoded;
}
