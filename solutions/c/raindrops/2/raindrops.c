#include "raindrops.h"

static const RainDrop dropMap[] = {
    {3, "Pling"},
    {5, "Plang"},
    {7, "Plong"},
};

const int DROP_COUNT = (int)(sizeof(dropMap) / sizeof(RainDrop));

void convert(char result[], int drops)
{

    for (int i = 0; i < DROP_COUNT; i++)
        if (drops % dropMap[i].divisor == 0)
            strcat(result, dropMap[i].dropName);

    if (!*result)
        sprintf(result, "%d", drops);
}
