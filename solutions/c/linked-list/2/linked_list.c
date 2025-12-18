#include "linked_list.h"

#include <stdlib.h>

struct list_node
{
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list
{
   struct list_node *first, *last;
};

struct list *list_create(void)
{
   struct list *new_list = malloc(sizeof(struct list));

   if (!new_list)
      return NULL;

   new_list->first = NULL;
   new_list->last = NULL;

   return new_list;
}

size_t list_count(const struct list *list)
{
   size_t count = 0;
   struct list_node *curr_node = list->first;

   while (curr_node)
   {
      count++;
      curr_node = curr_node->next;
   }

   return count;
}

void list_push(struct list *list, ll_data_t item_data)
{
   struct list_node *new_node = malloc(sizeof(struct list_node));

   if (!new_node)
      return;

   new_node->data = item_data;
   new_node->prev = new_node->next = NULL;

   if (list->last)
   {
      new_node->prev = list->last;
      list->last->next = new_node;
      list->last = new_node;
   }
   else
   {
      list->first = new_node;
      list->last = new_node;
   }
}

ll_data_t list_pop(struct list *list)
{
   if (!list->last)
      return 0;

   struct list_node *last_node = list->last;
   ll_data_t data = last_node->data;

   list->last = last_node->prev;

   if (list->last == NULL)
      list->first = NULL;
   else
      list->last->next = NULL;

   free(last_node);
   return data;
}

void list_unshift(struct list *list, ll_data_t item_data)
{
   struct list_node *new_node = malloc(sizeof(struct list_node));

   if (!new_node)
      return;

   new_node->data = item_data;
   new_node->prev = NULL;
   new_node->next = NULL;

   if (list->first)
   {
      new_node->next = list->first;
      list->first->prev = new_node;
      list->first = new_node;
   }
   else
   {
      list->first = new_node;
      list->last = new_node;
   }
}

ll_data_t list_shift(struct list *list)
{
   if (!list->first)
      return 0;

   struct list_node *first_node = list->first;
   ll_data_t data = first_node->data;

   list->first = first_node->next;

   if (list->first == NULL)
      list->last = NULL;
   else
      list->first->prev = NULL;

   free(first_node);
   return data;
}

void list_delete(struct list *list, ll_data_t data)
{
   struct list_node *curr_node = list->first;

   while (curr_node)
   {
      if (curr_node->data == data)
      {
         if (curr_node->prev == NULL)
            list->first = curr_node->next;
         else
            curr_node->prev->next = curr_node->next;

         if (curr_node->next == NULL)
            list->last = curr_node->prev;
         else
            curr_node->next->prev = curr_node->prev;

         free(curr_node);
         break;
      }

      curr_node = curr_node->next;
   }
}

void list_destroy(struct list *list)
{
   struct list_node *curr_node = list->first;
   struct list_node *helper_node;

   while (curr_node)
   {
      helper_node = curr_node->next;
      free(curr_node);
      curr_node = helper_node;
   }

   free(list);
}