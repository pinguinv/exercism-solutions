#include "variable_length_quantity.h"
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BYTES_PER_INT 5
#define BYTE_LEFT_BIT_MASK 0x80u
#define BYTE_LEFT_BIT_MASK_REVERSE 0x7fu

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
   int out_counter = 0;
   uint8_t num_parts[MAX_BYTES_PER_INT];

   for (size_t i = 0; i < integers_len; i++)
   {
      uint32_t num = integers[i];

      uint8_t n;
      for (n = 0; n < MAX_BYTES_PER_INT; n++)
      {
         num_parts[n] = num & BYTE_LEFT_BIT_MASK_REVERSE;

         // set first bit to all bytes but first,
         // since we're pushing these bytes to stack,
         // first one here gonna be last in the output
         if (n > 0)
            num_parts[n] |= BYTE_LEFT_BIT_MASK;

         num >>= 7;

         if (!num)
            break;
      }

      for (int8_t i = n; i >= 0; i--)
         output[out_counter++] = num_parts[i];
   }

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
