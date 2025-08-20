#include "rational_numbers.h"

static int gcd(rational_t r)
{
    int a = r.numerator < 0 ? -r.numerator : r.numerator;
    int b = r.denominator < 0 ? -r.denominator : r.denominator;

    if (a == 0 || b == 0)
        return a + b;

    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    return a;
}

rational_t absolute(rational_t r)
{
    r.numerator = r.numerator < 0 ? -r.numerator : r.numerator;
    r.denominator = r.denominator < 0 ? -r.denominator : r.denominator;

    r = reduce(r);
    return r;
}

rational_t reduce(rational_t r)
{
    int d = gcd(r);

    r.numerator = r.numerator / d;
    r.denominator = r.denominator / d;

    if (r.denominator < 0)
    {
        r.numerator = -r.numerator;
        r.denominator = -r.denominator;
    }

    return r;
}

rational_t add(rational_t r1, rational_t r2)
{
    rational_t result = {0, 0};

    result.numerator = r1.numerator * r2.denominator + r1.denominator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;

    result = reduce(result);
    return result;
}

rational_t subtract(rational_t r1, rational_t r2)
{
    rational_t result = {0, 0};

    result.numerator = r1.numerator * r2.denominator - r1.denominator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;

    result = reduce(result);
    return result;
}

rational_t multiply(rational_t r1, rational_t r2)
{
    rational_t result = {0, 0};

    result.numerator = r1.numerator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;

    result = reduce(result);
    return result;
}

rational_t divide(rational_t r1, rational_t r2)
{
    rational_t result = {0, 0};

    if (r2.numerator == 0)
        return result;

    result.numerator = r1.numerator * r2.denominator;
    result.denominator = r2.numerator * r1.denominator;

    result = reduce(result);
    return result;
}

rational_t exp_rational(rational_t r, int16_t n)
{
    rational_t result = {0, 0};

    if (n >= 0)
    {
        result.numerator = pow(r.numerator, n);
        result.denominator = pow(r.denominator, n);
    }
    else
    {
        n = -n;
        result.numerator = pow(r.denominator, n);
        result.denominator = pow(r.numerator, n);
    }

    result = reduce(result);
    return result;
}

float exp_real(uint16_t x, rational_t r)
{
    return pow(pow(x, r.numerator), (float)1 / r.denominator);
}