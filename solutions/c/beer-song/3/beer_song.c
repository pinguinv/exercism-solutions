#include "beer_song.h"

void recite(uint8_t start_bottles, uint16_t take_down, char **song)
{
    char *sentence = calloc(MAX_LINE_LENGTH, sizeof(char));
    uint16_t bottles_num = start_bottles;

    for (uint16_t i = 0; i < take_down * 3 - 1; i++)
    {
        switch ((i + 1) % 3)
        {
        case 0:
            strcpy(sentence, "");
            break;

        case 1:
            if (bottles_num == 0)
                strcpy(sentence, "No more bottles of beer on the wall, no more bottles of beer.");
            else
                sprintf(sentence, "%d %s of beer on the wall, %d %s of beer.",
                        bottles_num,
                        bottles_num == 1 ? "bottle" : "bottles",
                        bottles_num,
                        bottles_num == 1 ? "bottle" : "bottles");
            break;

        case 2:
            if (bottles_num == 0)
            {
                strcpy(sentence, "Go to the store and buy some more, 99 bottles of beer on the wall.");
                break;
            }

            bottles_num--;

            if (bottles_num == 0)
                strcpy(sentence, "Take it down and pass it around, no more bottles of beer on the wall.");
            else
                sprintf(sentence, "Take one down and pass it around, %d %s of beer on the wall.",
                        bottles_num,
                        bottles_num == 1 ? "bottle" : "bottles");
            break;
        }

        strcpy(song[i], sentence);
    }
    free(sentence);
}