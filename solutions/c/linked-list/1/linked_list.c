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
   struct list *r_list = malloc(sizeof(struct list));
   r_list->first = NULL;
   r_list->last = NULL;

   return r_list;
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

   ll_data_t data = list->last->data;

   if (list->last->prev)
   {
      list->last = list->last->prev;
      free(list->last->next);
      list->last->next = NULL;
   }
   else
   {
      free(list->last);
      list->first = list->last = NULL;
   }

   return data;
}

void list_unshift(struct list *list, ll_data_t item_data)
{
   struct list_node *new_node = malloc(sizeof(struct list_node));
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

   ll_data_t data = list->first->data;

   if (list->first->next)
   {
      list->first = list->first->next;
      free(list->first->prev);
      list->first->prev = NULL;
   }
   else
   {
      free(list->first);
      list->first = list->last = NULL;
   }

   return data;
}

void list_delete(struct list *list, ll_data_t data)
{
   struct list_node *curr_node = list->first;

   while (curr_node)
   {
      if (curr_node->data == data)
      {
         // prev neighbour = 2, next neighbour = 1
         // 0 <= node_neighbours <= 3
         short node_neighbours = ((!!curr_node->prev) << 1) + (!!curr_node->next);

         switch (node_neighbours)
         {
         // Both neighbours
         case 3:
            curr_node->next->prev = curr_node->prev;
            curr_node->prev->next = curr_node->next;
            break;

         // Only prev neighbour
         case 2:
            curr_node->prev->next = NULL;
            list->last = curr_node->prev;
            break;

         // Only next neighbour
         case 1:
            curr_node->next->prev = NULL;
            list->first = curr_node->next;
            break;

         // No neighbours
         case 0:
         default:
            list->first = NULL;
            list->last = NULL;
            break;
         }

         free(curr_node);
         break;
      }

      curr_node = curr_node->next;
   }
}

void list_destroy(struct list *list)
{

   struct list_node *curr_node = list->first;

   while (curr_node)
   {
      struct list_node *temp_next = curr_node->next;
      free(curr_node);
      curr_node = temp_next;
   }

   free(list);
}