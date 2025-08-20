#include "raindrops.h"

void convert(char result[], int drops)
{
    int divisible_by[] = {3, 5, 7};
    char *sounds[] = {"Pling", "Plang", "Plong"};
    bool is_divisible_by_any = false;

    for (int i = 0; i < (int)(sizeof(divisible_by) / sizeof(int)); i++)
    {
        if (drops % divisible_by[i] == 0)
        {
            is_divisible_by_any = true;
            break;
        }
    }

    if (!is_divisible_by_any)
    {
        sprintf(result, "%d", drops);
        return;
    }

    for (int i = 0; i < (int)(sizeof(divisible_by) / sizeof(int)); i++)
    {
        if (drops % divisible_by[i] == 0)
            strcat(result, sounds[i]);
    }
}
