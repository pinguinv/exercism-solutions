#include "collatz_conjecture.h"

int steps(int start)
{
    int steps = (start > 0) ? 0 : ERROR_VALUE;
    while (start > 1)
    {
        start = (start % 2) ? (start * 3 + 1) : (start / 2);
        steps++;
    }
    return steps;
}
