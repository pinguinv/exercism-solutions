#include "clock.h"
#include <stdio.h>

static int get_hour(clock_t clock)
{
    return (clock.text[0] - '0') * 10 + (clock.text[1] - '0');
}

static int get_minute(clock_t clock)
{
    return (clock.text[3] - '0') * 10 + (clock.text[4] - '0');
}

clock_t clock_create(int hour, int minute)
{
    clock_t clock = {.text = "##:##"};

    while (minute < 0)
    {
        hour -= 1;
        minute += 60;
    }

    while (minute >= 60)
    {
        hour += 1;
        minute -= 60;
    }

    while (hour < 0)
        hour += 24;

    while (hour >= 24)
        hour -= 24;

    clock.text[0] = '0' + hour / 10;
    clock.text[1] = '0' + hour % 10;

    clock.text[3] = '0' + minute / 10;
    clock.text[4] = '0' + minute % 10;

    return clock;
}

clock_t clock_add(clock_t clock, int minute_add)
{
    int hour = get_hour(clock);
    int minute = get_minute(clock) + minute_add;

    return clock_create(hour, minute);
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    int hour = get_hour(clock);
    int minute = get_minute(clock) - minute_subtract;

    return clock_create(hour, minute);
}

bool clock_is_equal(clock_t a, clock_t b)
{
    return get_hour(a) == get_hour(b) && get_minute(a) == get_minute(b);
}