#include "beer_song.h"

#define BOTTLE_VERSE "%s %s of beer on the wall, %s %s of beer."
#define TAKE_DOWN_VERSE "Take %s down and pass it around, %s %s of beer on the wall."
#define END_VERSE "Go to the store and buy some more, 99 bottles of beer on the wall."

void recite(uint8_t start_bottles, uint16_t take_down, char **song)
{
    char *sentence = calloc(MAX_LINE_LENGTH, sizeof(char));
    uint16_t bottles_num = start_bottles;
    for (uint16_t i = 0; i < take_down * 3 - 1; i++)
    {
        char bottles_str[10] = {0};
        char noun[10] = {0}; // bottles or bottle

        switch ((i + 1) % 3)
        {
        case 0:
            strcpy(sentence, "");
            break;
        case 1:
            if (bottles_num == 1)
                strcpy(noun, "bottle");
            else
                strcpy(noun, "bottles");

            if (bottles_num != 0)
                sprintf(bottles_str, "%d", bottles_num);
            else
                strcpy(bottles_str, "no more");

            sprintf(sentence, BOTTLE_VERSE,
                    bottles_str[0] == 'n' ? "No more" : bottles_str,
                    noun,
                    bottles_str,
                    noun);
            break;
        case 2:
            if (bottles_num == 0)
            {
                sprintf(sentence, "Go to the store and buy some more, 99 bottles of beer on the wall.");
                break;
            }
            bottles_num--;

            char one_or_it[5] = {0};

            if (bottles_num == 1)
                strcpy(noun, "bottle");
            else
                strcpy(noun, "bottles");

            if (bottles_num == 0)
            {
                strcpy(one_or_it, "it");
                strcpy(bottles_str, "no more");
            }
            else
            {
                strcpy(one_or_it, "one");
                sprintf(bottles_str, "%d", bottles_num);
            }

            sprintf(sentence, TAKE_DOWN_VERSE, one_or_it, bottles_str, noun);
            break;
        }

        strcpy(song[i], sentence);
    }

    free(sentence);
}