#include "list_ops.h"

list_t *new_list(size_t length, list_element_t elements[])
{
    list_t *list_ptr = (list_t *)malloc(sizeof(size_t) + length * sizeof(list_element_t));

    list_ptr->length = length;

    if (elements != NULL)
        for (size_t i = 0; i < length; i++)
            list_ptr->elements[i] = elements[i];

    return list_ptr;
}

list_t *append_list(list_t *list1, list_t *list2)
{
    size_t length = list1->length + list2->length;
    list_t *result_list = new_list(length, NULL);

    for (size_t i = 0; i < list1->length; i++)
        result_list->elements[i] = list1->elements[i];

    for (size_t i = 0; i < list2->length; i++)
        result_list->elements[list1->length + i] = list2->elements[i];

    return result_list;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t))
{
    size_t length = 0;
    for (size_t i = 0; i < list->length; i++)
        if (filter(list->elements[i]))
            length++;

    list_t *result_list = new_list(length, NULL);

    for (size_t i = 0, j = 0; i < list->length; i++)
        if (filter(list->elements[i]))
            result_list->elements[j++] = list->elements[i];

    return result_list;
}

size_t length_list(list_t *list)
{
    return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t))
{
    list_t *result_list = new_list(list->length, NULL);

    for (size_t i = 0; i < list->length; i++)
        result_list->elements[i] = map(list->elements[i]);

    return result_list;
}

list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t))
{
    list_element_t result = initial;

    for (size_t i = 0; i < list->length; i++)
        result = foldl(list->elements[i], result);

    return result;
}

list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t))
{
    list_element_t result = initial;

    for (size_t i = list->length; i > 0; i--)
        result = foldr(list->elements[i - 1], result);

    return result;
}

list_t *reverse_list(list_t *list)
{
    list_t *result_list = new_list(list->length, NULL);

    for (size_t i = 0, j = list->length - 1; i < list->length; i++, j--)
        result_list->elements[i] = list->elements[j];

    return result_list;
}

void delete_list(list_t *list)
{
    free(list);
    list = NULL;
}
