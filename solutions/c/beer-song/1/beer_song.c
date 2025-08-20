#include "beer_song.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void recite(uint8_t start_bottles, uint16_t take_down, char **song)
{
    char *sentence = calloc(MAX_LINE_LENGTH, sizeof(char));
    for (uint16_t i = 0; i < take_down * 3 - 1; i++)
    {
        switch ((i + 1) % 3)
        {
        case 0:
            strcpy(sentence, "");
            break;
        case 1:
            if (start_bottles == 0)
                sprintf(sentence, "No more bottles of beer on the wall, no more bottles of beer.");
            else
                sprintf(sentence, "%d bottle%sof beer on the wall, %d bottle%sof beer.",
                        start_bottles,
                        start_bottles != 1 ? "s " : " ",
                        start_bottles,
                        start_bottles != 1 ? "s " : " ");
            break;
        case 2:
            if (start_bottles == 0)
                sprintf(sentence, "Go to the store and buy some more, 99 bottles of beer on the wall.");
            else if (start_bottles == 1)
                sprintf(sentence, "Take it down and pass it around, no more bottles of beer on the wall.");
            else
                sprintf(sentence, "Take one down and pass it around, %d bottle%sof beer on the wall.",
                        start_bottles - 1,
                        start_bottles - 1 != 1 ? "s " : " ");
            start_bottles--;
            break;
        }

        strcpy(song[i], sentence);
    }

    free(sentence);
}