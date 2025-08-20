#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size)
{
    int bilion_sec = 1000000000;
    time_t result_time = input + bilion_sec;

    struct tm result_tm = *gmtime(&result_time);

    strftime(output, size, "%Y-%m-%d %H:%M:%S", &result_tm);
}