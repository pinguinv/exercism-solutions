#include "space_age.h"

float age(planet_t planet, int64_t seconds)
{
    if (planet < 0 || planet > 7)
        return -1; // error

    float ratios[] = {0.2408467F, 0.61519726F, 1.0F, 1.8808158F, 11.862615F, 29.447498F, 84.016846F, 164.79132F};

    float earth_yrs = seconds / 31557600.0F;

    return earth_yrs / ratios[planet];
}
