#include "kindergarten_garden.h"

static plant_t determine_plant(char letter)
{
    switch (letter)
    {
    case 'G':
        return GRASS;

    case 'C':
        return CLOVER;

    case 'R':
        return RADISHES;

    case 'V':
        return VIOLETS;
    }

    return 0;
}

plants_t plants(const char *diagram, const char *student)
{
    plants_t result_plants = {.plants = {0}};

    if (diagram == NULL || student == NULL)
        return result_plants;

    char student_first_letter = student[0];
    unsigned int plants_index = (student_first_letter - 'A') * 2;
    size_t line_length = (strlen(diagram) + 1) / 2; // with a breakline

    result_plants.plants[0] = determine_plant(diagram[plants_index]);
    result_plants.plants[1] = determine_plant(diagram[plants_index + 1]);

    result_plants.plants[2] = determine_plant(diagram[line_length + plants_index]);
    result_plants.plants[3] = determine_plant(diagram[line_length + plants_index + 1]);

    return result_plants;
}