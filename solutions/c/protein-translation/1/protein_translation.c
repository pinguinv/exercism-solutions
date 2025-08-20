#include "protein_translation.h"

static short pow_ten(unsigned short x)
{
    short result = 1;
    while (x-- > 0)
        result *= 10;

    return result;
}

static short get_codon_number_code(const char *const codon)
{
    short codon_number_code = 0;
    for (short j = 0; j < 3; j++)
        switch (*(codon + j))
        {
        case 'A':
            codon_number_code += Adenine * pow_ten(2 - j);
            break;
        case 'C':
            codon_number_code += Cytosine * pow_ten(2 - j);
            break;
        case 'G':
            codon_number_code += Guanine * pow_ten(2 - j);
            break;
        case 'U':
            codon_number_code += Uracil * pow_ten(2 - j);
            break;

        default:
            break;
        }

    return codon_number_code;
}

proteins_t proteins(const char *const rna)
{
    proteins_t result = {.valid = true, .count = 0, .proteins = {0}};

    size_t rna_len = strlen(rna);

    for (size_t i = 0; i + 2 < rna_len; i += 3)
    {
        short codon_number_code = get_codon_number_code((rna + i));

        switch (codon_number_code)
        {
        // AUG
        case 143:
            result.proteins[result.count++] = Methionine;
            break;

        // UUU, UUC
        case 444:
        case 442:
            result.proteins[result.count++] = Phenylalanine;
            break;

        // UUA, UUG
        case 441:
        case 443:
            result.proteins[result.count++] = Leucine;
            break;

        // UCU, UCC, UCA, UCG
        case 424:
        case 422:
        case 421:
        case 423:
            result.proteins[result.count++] = Serine;
            break;

        // UAU, UAC
        case 414:
        case 412:
            result.proteins[result.count++] = Tyrosine;
            break;

        // UGU, UGC
        case 434:
        case 432:
            result.proteins[result.count++] = Cysteine;
            break;

        // UGG
        case 433:
            result.proteins[result.count++] = Tryptophan;
            break;

        // UAA, UAG, UGA
        case 411:
        case 413:
        case 431:
            return result;
            break;

        default:
            result.valid = false;
            return result;
            break;
        }
    }

    if (rna_len % 3 != 0)
    {
        result.valid = false;
        return result;
    }

    return result;
}