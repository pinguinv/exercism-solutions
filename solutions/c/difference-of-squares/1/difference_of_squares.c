#include "difference_of_squares.h"
unsigned int sum_of_squares(unsigned int number)
{
    unsigned int result = 0;
    for (unsigned int i = 1; i <= number; i++)
    {
        result += i * i;
    }
    return result;
}

unsigned int square_of_sum(unsigned int number)
{
    unsigned int result = 0;
    for (unsigned int i = 1; i <= number; i++)
    {
        result += i;
    }
    return result * result;
}

unsigned int difference_of_squares(unsigned int number)
{
    unsigned int sum_of_squares_result = sum_of_squares(number);
    unsigned int square_of_sum_result = square_of_sum(number);

    return square_of_sum_result - sum_of_squares_result;
}

// 1 2
// 3^2 = 9
// 1^2 + 2^2 = 5
// 9 - 5 = 4

// 1 2 3
// 6^2 = 36
// 1^2 + 2^2 + 3^2 = 5 + 9 = 14
// 36 - 14 = 22

// 1 2 3 4
// 10^2 = 100
// 1^2 + 2^2 + 3^2 + 4^2 = 5 + 9 + 16 = 30
// 100 - 30 = 70

// I don't see any pattern