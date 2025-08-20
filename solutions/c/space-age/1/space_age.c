#include "space_age.h"

float age(planet_t planet, int64_t seconds)
{
    float earth_yrs = seconds / 31557600.0F;
    float planet_yrs = earth_yrs;

    switch (planet)
    {
    case MERCURY:
        planet_yrs /= 0.2408467F;
        break;

    case VENUS:
        planet_yrs /= 0.61519726F;
        break;

    case EARTH:
        break;

    case MARS:
        planet_yrs /= 1.8808158F;
        break;

    case JUPITER:
        planet_yrs /= 11.862615F;
        break;

    case SATURN:
        planet_yrs /= 29.447498F;
        break;

    case URANUS:
        planet_yrs /= 84.016846F;
        break;

    case NEPTUNE:
        planet_yrs /= 164.79132F;
        break;

    default:
        planet_yrs = -1; // error
        break;
    }
    return planet_yrs;
}
