#include "resistor_color.h"

resistor_band_t bands_arr[] = {BLACK, BROWN, RED, ORANGE, YELLOW,
                               GREEN, BLUE, VIOLET, GREY, WHITE};

uint16_t color_code(resistor_band_t resistor)
{
    return resistor;
}

resistor_band_t *colors()
{
    return bands_arr;
}