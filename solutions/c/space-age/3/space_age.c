#include "space_age.h"

static const float RATIOS[] = {0.2408467F, 0.61519726F, 1.0F, 1.8808158F, 11.862615F, 29.447498F, 84.016846F, 164.79132F};
static const int EARTH_YEAR_SECONDS = 31557600;

float age(planet_t planet, int64_t seconds)
{
    if (planet < 0 || planet > 7)
        return -1; // error

    float earth_yrs = seconds / EARTH_YEAR_SECONDS;

    return earth_yrs / RATIOS[planet];
}
