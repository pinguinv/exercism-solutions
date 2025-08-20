#ifndef BEER_SONG_H
#define BEER_SONG_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH (1024)

void recite(uint8_t start_bottles, uint16_t take_down, char **song);

#endif
