#ifndef SUM_OF_MULTIPLES_H
#define SUM_OF_MULTIPLES_H

#include <stddef.h>
#include <stdint.h>

uint32_t sum(const uint32_t *factors,
             const size_t number_of_factors,
             const uint32_t limit);

#endif
