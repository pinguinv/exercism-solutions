#include "allergies.h"

static int ipow(int x, int y)
{
    int result = 1;
    for (int i = 0; i < y; i++)
        result *= x;
    return result;
}

bool is_allergic_to(allergen_t allergen, int allergy_score)
{
    return ipow(2, allergen) & allergy_score;
}

allergen_list_t get_allergens(int allergy_score)
{
    allergen_list_t list = {.allergens = {false}, .count = 0};
    for (int i = 0; i < ALLERGEN_COUNT; i++)
        if (ipow(2, i) & allergy_score)
        {
            list.allergens[i] = true;
            list.count++;
        }

    return list;
}