#include "sublist.h"

static bool a_superlist_of_b(int *a, int *b, size_t a_size, size_t b_size)
{
    for (size_t i = 0; i < a_size - (b_size - 1); i++)
    {
        bool b_in_a = true;

        for (size_t j = 0; j < b_size; j++)
            if (a[i + j] != b[j])
            {
                b_in_a = false;
                break;
            }

        if (b_in_a)
            return true;
    }
    return false;
}

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count)
{
    int size_diff = list_to_compare_element_count - base_list_element_count;

    if (size_diff > 0)
    {
        return a_superlist_of_b(list_to_compare, base_list,
                                list_to_compare_element_count,
                                base_list_element_count)
                   ? SUPERLIST
                   : UNEQUAL;
    }
    else if (size_diff < 0)
    {
        return a_superlist_of_b(base_list, list_to_compare,
                                base_list_element_count,
                                list_to_compare_element_count)
                   ? SUBLIST
                   : UNEQUAL;
    }

    // sizes are same
    for (size_t i = 0; i < list_to_compare_element_count; i++)
        if (list_to_compare[i] != base_list[i])
            return UNEQUAL;

    return EQUAL;
}