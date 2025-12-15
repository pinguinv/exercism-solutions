#include "run_length_encoding.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 64

char *encode(const char *text)
{
    char *result = calloc(MAX_LENGTH, sizeof(char));

    if (result == NULL || text == NULL)
        return NULL;

    if (strlen(text) == 0)
        return result;

    char *result_end_ptr = result;

    char num_buffer[8] = {'\0'};

    char curr_letter = text[0];
    unsigned short curr_letter_count = 0;

    // This last iteration (+ 1) is neccessary to write
    // the last character to the result (last char in every string
    //  is '\0', so it always leads to the 'else' code block)
    for (size_t i = 0; i < strlen(text) + 1; i++)
    {
        if (text[i] == curr_letter)
        {
            curr_letter_count += 1;
        }
        else
        {
            if (curr_letter_count > 1)
            {
                // Write the number to the buffer
                snprintf(num_buffer, 7, "%d", curr_letter_count);
                // Append text from the buffer to the end of the result
                strcpy(result_end_ptr, num_buffer);
                // Adjust end_ptr to the new end
                result_end_ptr += strlen(num_buffer);
                // Clear the buffer
                memset(num_buffer, '\0', 7);
            }

            *result_end_ptr = curr_letter;
            result_end_ptr += 1;

            curr_letter = text[i];
            curr_letter_count = 1;
        }
    }

    return result;
}

char *decode(const char *data)
{
    char *const result = calloc(MAX_LENGTH, sizeof(char));

    if (result == NULL || data == NULL)
        return NULL;

    if (strlen(data) == 0)
        return result;

    char *result_end_ptr = result;
    char num_buff[4] = {'\0'};
    unsigned short num_index = 0;

    for (size_t i = 0; i < strlen(data) + 1; i++)
    {
        if (isdigit(data[i]))
        {
            num_buff[num_index++] = data[i];
        }
        else
        {
            int converted = atoi(num_buff);
            // Clear the buffer
            memset(num_buff, '\0', 4);
            num_index = 0;

            int letter_count = converted > 1 ? converted : 1;

            memset(result_end_ptr, data[i], letter_count);
            result_end_ptr += letter_count;
        }
    }

    return result;
}