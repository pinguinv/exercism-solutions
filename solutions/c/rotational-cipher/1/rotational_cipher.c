#include "rotational_cipher.h"

char *rotate(const char *text, int shift_key)
{
    int length = 0;
    while (text[length] != '\0')
        length++;

    char *result = (char *)calloc((length + 1), sizeof(char));

    shift_key = (shift_key < 0) ? (shift_key % 26) + 26 : (shift_key % 26);

    for (int i = 0; i < length; i++)
    {
        char src_char = text[i];
        result[i] = text[i];
        if (src_char >= 'a' && src_char <= 'z')
            result[i] = (char)((src_char - 'a' + shift_key) % 26 + 'a');

        if (src_char >= 'A' && src_char <= 'Z')
            result[i] = (char)((src_char - 'A' + shift_key) % 26 + 'A');
    }

    return result;
}