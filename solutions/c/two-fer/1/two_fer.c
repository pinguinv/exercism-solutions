#include "two_fer.h"

void two_fer(char *buffer, const char *name)
{
    if (name != NULL)
    {
        char *strs[] = {"One for ", ", one for me."};
        strcpy(buffer, strs[0]);
        strcat(buffer, name);
        strcat(buffer, strs[1]);
        return;
    }
    strcpy(buffer, "One for you, one for me.");

    return;
}