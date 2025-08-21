#include "variable_length_quantity.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static const uint8_t MAX_BYTES_PER_INT = 5;
static const uint8_t BYTE_LEFT_BIT_MASK = 0x80;
static const uint8_t BYTE_LEFT_BIT_MASK_REVERSE = 0x7f;

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
   int out_counter = 0;
   uint8_t *temp_stack = (uint8_t *)malloc(MAX_BYTES_PER_INT * sizeof(uint8_t));

   for (size_t i = 0; i < integers_len; i++)
   {
      uint32_t num = integers[i];
      bool first_flag = true;
      memset(temp_stack, 0, MAX_BYTES_PER_INT);
      uint8_t temp_stack_i = 0;

      // at least one run
      while (num || first_flag)
      {
         uint8_t byte = (uint8_t)num;

         // clear first bit
         byte &= BYTE_LEFT_BIT_MASK_REVERSE;

         // set first bit to all bytes but first,
         // since we're pushing these bytes to stack,
         // first one here gonna be last in the output
         if (!first_flag)
            // set first bit
            byte |= BYTE_LEFT_BIT_MASK;

         temp_stack[temp_stack_i++] = byte;

         first_flag = false;
         num >>= 7;
      }

      while (temp_stack_i > 0)
         output[out_counter++] = temp_stack[--temp_stack_i];
   }

   free(temp_stack);

   return out_counter;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
{
   int out_counter = 0;

   // if last byte does not start with 0 that means bytes are incorrect
   if (bytes[buffer_len - 1] & BYTE_LEFT_BIT_MASK)
      return -1;

   uint32_t curr_num = 0;

   for (size_t i = 0; i < buffer_len; i++)
   {
      curr_num <<= 7;
      // add only 7 right bits
      curr_num |= (bytes[i] & BYTE_LEFT_BIT_MASK_REVERSE);

      // if it is last byte (first bit not set)
      if (!(bytes[i] & BYTE_LEFT_BIT_MASK))
      {
         output[out_counter++] = curr_num;
         curr_num = 0;
      }
   }

   return out_counter;
}
