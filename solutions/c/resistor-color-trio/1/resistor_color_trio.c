#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t *colors)
{
    resistor_value_t resistor = {0, 0};

    resistor.value = colors[0] * 10 + colors[1];

    int zero_count = colors[2];

    while (zero_count > 0)
    {
        if (zero_count > 2)
        {
            resistor.unit += 1;
            zero_count -= 3;
            continue;
        }
        resistor.value *= 10;
        zero_count--;
    }

    if (resistor.value % 1000 == 0 && resistor.value != 0)
    {
        resistor.value /= 1000;
        resistor.unit += 1;
    }

    return resistor;
}