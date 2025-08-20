#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int allergy_score)
{
    return (1 << allergen) & allergy_score;
}

allergen_list_t get_allergens(int allergy_score)
{
    allergen_list_t list = {.allergens = {false}, .count = 0};
    for (int i = 0; i < ALLERGEN_COUNT; i++)
        if ((1 << i) & allergy_score)
        {
            list.allergens[i] = true;
            list.count++;
        }

    return list;
}