#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t *colors)
{
    resistor_value_t resistor = {0, 0};

    resistor.value = colors[0] * 10 + colors[1];

    int zero_count = colors[2];

    for (int i = 1; i <= zero_count % 3; i++)
        resistor.value *= 10;

    resistor.unit = zero_count / 3;
    while (resistor.value != 0 && resistor.value % 1000 == 0)
    {
        resistor.value /= 1000;
        resistor.unit += 1;
    }

    return resistor;
}