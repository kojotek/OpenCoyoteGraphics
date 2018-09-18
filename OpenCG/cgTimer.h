#ifndef _CGTIMER_
#define _CGTIMER_

#include <time.h>

#define CG_MICROSECONDS 0
#define CG_MILISECONDS  1
#define CG_SECONDS      2

class cgTimer
{
private:
    struct timeval* last;
	struct timeval* current;

public:
    cgTimer();
    unsigned long int reset( int unit = CG_MILISECONDS );
    unsigned long int getTime( int unit = CG_MILISECONDS );
	int gettimeofday(struct timeval *tv, struct timezone *tz);
};

#endif // _CGTIMER_
