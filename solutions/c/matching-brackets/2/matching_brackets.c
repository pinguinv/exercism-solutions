#include "matching_brackets.h"

#include <stdlib.h>
#include <stdint.h>

#define OPENING "([{"
#define CLOSING ")]}"
#define MAX_OPENING_ARR_LENGTH 64

static uint8_t is_opening_bracket(const char c)
{
    for (size_t i = 0; i < 3; i++)
        if (OPENING[i] == c)
            // Return bracket's number
            return i + 1;

    return 0;
}

static uint8_t is_closing_bracket(const char c)
{
    for (size_t i = 0; i < 3; i++)
        if (CLOSING[i] == c)
            // Return bracket's number
            return i + 1;

    return 0;
}

bool is_paired(const char *input)
{
    uint8_t *brackets_stack = calloc(MAX_OPENING_ARR_LENGTH, sizeof(uint8_t));
    int16_t stack_i = 0;

    if (!brackets_stack)
        return NULL;

    for (size_t i = 0; input[i]; i++)
    {
        uint8_t bracket_num;

        if ((bracket_num = is_opening_bracket(input[i])))
            brackets_stack[stack_i++] = bracket_num;
        else if ((bracket_num = is_closing_bracket(input[i])))
        {
            // Set index of the last opening bracket
            stack_i--;

            if (stack_i >= 0 && brackets_stack[stack_i] == bracket_num)
                brackets_stack[stack_i] = 0;
            else
            {
                // If closing bracket is different or index exceeded
                // possible range, set index to impossible value and
                // break the loop, so it won't miss freeing the memory
                // and still will return false - correct value
                stack_i = -1;
                break;
            }
        }
    }

    free(brackets_stack);

    // means that brackets_stack is/was empty
    return stack_i == 0;
}