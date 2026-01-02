#include "meetup.h"

#include <string.h>

static const char
    // Days in month
    DIM[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    *WEEKS[] = {"first", "second", "third", "fourth", "fifth", "last", "teenth"},
    *DAYS[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week,
                        const char *day_of_week)
{
    int weekday_num, week_num;

    // clang-format off
    for (weekday_num = 0; weekday_num < 7 && strcmp(day_of_week, DAYS[weekday_num]); weekday_num++);
    for (week_num = 0; week_num < 7 && strcmp(week, WEEKS[week_num]); week_num++);
    // clang-format on

    int start = 0;

    switch (week_num)
    {
    // "first" case
    case 0:
        start = 1;
        break;

    // "second", "third", "fourth" case
    case 1:
    case 2:
    case 3:
        start = 1 + 7 * week_num;
        break;

    // "fifth" case
    // "last" case
    case 4:
    case 5:

        start = DIM[month - 1] - 6;

        // Add one if it is
        if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
            start += 1;

        break;

    // "teenth" case
    case 6:
        start = 13;
        break;
    }

    // Formula from https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Keith
    int d = start + (month < 3 ? year-- : year - 2);
    int dow = (23 * month / 9 + d + 4 + year / 4 - year / 100 + year / 400) % 7;

    int result = 0;

    for (int i = 0; i < 7; i++)
        if ((dow + i) % 7 == weekday_num)
        {
            result = start + i;
            break;
        }

    return result;
}