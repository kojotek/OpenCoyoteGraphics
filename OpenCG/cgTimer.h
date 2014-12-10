#ifndef _CGTIMER_
#define _CGTIMER_

#include <sys/time.h>

#define CG_MICROSECONDS 0
#define CG_MILISECONDS  1
#define CG_SECONDS      2

class cgTimer
{
private:
    timeval last;
    timeval current;

public:
    cgTimer();
    unsigned long int reset( int unit );
    unsigned long int getTime( int unit );

};

#endif // _CGTIMER_
