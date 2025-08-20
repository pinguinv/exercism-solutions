#include "kindergarten_garden.h"

plants_t plants(const char *diagram, const char *student)
{
    plants_t result_plants = {.plants = {0}};

    if (diagram == NULL || student == NULL)
        return result_plants;

    unsigned int plants_index = (student[0] - 'A') * 2;
    const char *second_line = &diagram[0]; // with a breakline

    while (*(second_line++) != '\n')
        ;

    result_plants.plants[0] = (char)diagram[plants_index];
    result_plants.plants[1] = (char)diagram[plants_index + 1];

    result_plants.plants[2] = (char)second_line[plants_index];
    result_plants.plants[3] = (char)second_line[plants_index + 1];

    return result_plants;
}