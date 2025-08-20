#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

#include <stdint.h>

#define COLORS BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE
#define UNITS OHMS, KILOOHMS, MEGAOHMS, GIGAOHMS

typedef enum
{
    COLORS
} resistor_band_t;

typedef enum
{
    UNITS
} resistance_unit_t;

typedef struct
{
    uint16_t value;
    resistance_unit_t unit;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t *colors);

#endif
