#ifndef RAIL_FENCE_CIPHER_H
#define RAIL_FENCE_CIPHER_H

#include <stddef.h>

#define FENCE_FILL_TYPE ZIGZAG, ROWS

typedef enum
{
    FENCE_FILL_TYPE
} fence_fill_t;

char *encode(char *text, size_t rails);

char *decode(char *ciphertext, size_t rails);

#endif
