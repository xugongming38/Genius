#include"../base/base.h"

struct timezone
{
    int tz_minuteswest;
    int tz_dsttime;
};

/*
struct timeval {
        long    tv_sec;         //seconds 
        long    tv_usec;        // and microseconds 
};
*/

int gettimeofday(struct timeval * val, struct timezone *);
