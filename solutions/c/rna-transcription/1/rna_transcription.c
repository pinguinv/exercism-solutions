#include "rna_transcription.h"

char *to_rna(const char *dna)
{
    int rna_len = 0;
    while (dna[rna_len] != '\0')
        rna_len++;

    char *rna = (char *)malloc((rna_len + 1) * sizeof(char));
    rna[rna_len] = '\0';

    for (int i = 0; i < rna_len; i++)
    {
        switch (dna[i])
        {
        case 'G':
            rna[i] = 'C';
            break;

        case 'C':
            rna[i] = 'G';
            break;

        case 'T':
            rna[i] = 'A';
            break;

        case 'A':
            rna[i] = 'U';
            break;

        default:
            break;
        }
    }

    return rna;
}