#include "resistor_color_duo.h"

// `const` means that value of `resistors` won't be changed
uint16_t color_code(const resistor_band_t *resistors)
{
    return resistors[0] * 10 + resistors[1];
}
