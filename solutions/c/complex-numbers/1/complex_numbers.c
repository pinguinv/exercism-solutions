#include "complex_numbers.h"

complex_t c_add(complex_t a, complex_t b)
{
   complex_t result = {.real = a.real + b.real,
                       .imag = a.imag + b.imag};
   return result;
}

complex_t c_sub(complex_t a, complex_t b)
{
   complex_t result = {.real = a.real - b.real,
                       .imag = a.imag - b.imag};
   return result;
}

complex_t c_mul(complex_t a, complex_t b)
{
   complex_t result = {.real = a.real * b.real - a.imag * b.imag,
                       .imag = a.imag * b.real + a.real * b.imag};
   return result;
}

complex_t c_div(complex_t a, complex_t b)
{
   double denominator = (b.real * b.real + b.imag * b.imag);
   if (denominator == 0)
      return (complex_t){.real = 0, .imag = 0};

   complex_t result = {.real = (a.real * b.real + a.imag * b.imag) / denominator,
                       .imag = (a.imag * b.real - a.real * b.imag) / denominator};
   return result;
}

double c_abs(complex_t x)
{
   double sum_of_squares = x.real * x.real + x.imag * x.imag;
   if (sum_of_squares < 0)
      return 0;

   return sqrt(sum_of_squares);
}

complex_t c_conjugate(complex_t x)
{
   complex_t result = {.real = x.real,
                       .imag = -x.imag};
   return result;
}

double c_real(complex_t x)
{
   return x.real;
}

double c_imag(complex_t x)
{
   return x.imag;
}

complex_t c_exp(complex_t x)
{
   double e_to_real = exp(x.real);
   complex_t result = {.real = cos(x.imag) * e_to_real, .imag = sin(x.imag) * e_to_real};
   return result;
}
