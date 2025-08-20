#include "nucleotide_count.h"

#include <stdio.h>
#include <stdlib.h>

char *count(const char *dna_strand)
{
    char *result = (char *)calloc(32, sizeof(char));
    int letter_counts[4] = {0};

    while (*dna_strand)
    {
        switch (*dna_strand)
        {
        case 'A':
            letter_counts[0]++;
            break;
        case 'C':
            letter_counts[1]++;
            break;
        case 'G':
            letter_counts[2]++;
            break;
        case 'T':
            letter_counts[3]++;
            break;

        default:
            return result;
            break;
        }
        dna_strand++;
    }

    sprintf(result, "A:%d C:%d G:%d T:%d", letter_counts[0], letter_counts[1], letter_counts[2], letter_counts[3]);

    return result;
}