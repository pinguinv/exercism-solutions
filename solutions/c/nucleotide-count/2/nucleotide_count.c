#include "nucleotide_count.h"

char *count(const char *dna_strand)
{
    int a = 0, c = 0, g = 0, t = 0;

    while (*dna_strand)
    {
        switch (*dna_strand)
        {
        case 'A':
            a++;
            break;
        case 'C':
            c++;
            break;
        case 'G':
            g++;
            break;
        case 'T':
            t++;
            break;

        default:
            return calloc(1, sizeof(char));
            break;
        }
        dna_strand++;
    }

    char *result = (char *)calloc(32, sizeof(char));
    sprintf(result, "A:%d C:%d G:%d T:%d", a, c, g, t);

    return result;
}