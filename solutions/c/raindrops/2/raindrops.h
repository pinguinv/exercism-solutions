#ifndef RAINDROPS_H
#define RAINDROPS_H

#include <string.h>
#include <stdio.h>

#define DROP_NAME_LENGTH 5

typedef struct RainDrop
{
    int divisor;
    char dropName[DROP_NAME_LENGTH];
} RainDrop;

void convert(char result[], int drops);

#endif
