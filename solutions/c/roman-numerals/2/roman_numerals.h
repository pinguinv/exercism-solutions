#ifndef ROMAN_NUMERALS_H
#define ROMAN_NUMERALS_H

typedef struct Arab_roman_pair
{
    unsigned short arab;
    char *roman;
    unsigned short roman_len;
} Arab_roman_pair;

char *to_roman_numeral(unsigned int number);

#endif
