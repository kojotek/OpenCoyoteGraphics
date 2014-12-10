#include "cgTimer.h"


cgTimer::cgTimer()
{
    gettimeofday( &current, NULL );
    gettimeofday( &last, NULL );
}



unsigned long int cgTimer::reset( int unit )
{
    last = current;
    gettimeofday( &current, NULL );

    if ( unit == CG_MICROSECONDS )
        return ( ( ( current.tv_sec - last.tv_sec ) * 1000000 ) + ( current.tv_usec - last.tv_usec ) );

    if ( unit == CG_MILISECONDS )
        return ( ( ( current.tv_sec - last.tv_sec ) * 1000 ) + ( ( current.tv_usec - last.tv_usec ) / 1000 ) );

    if ( unit == CG_SECONDS )
        return ( current.tv_sec - last.tv_sec );
}


unsigned long int cgTimer::getTime( int unit )
{
    gettimeofday( &current, NULL );

    if ( unit == CG_MICROSECONDS )
        return ( ( ( current.tv_sec - last.tv_sec ) * 1000000 ) + ( current.tv_usec - last.tv_usec ) );

    if ( unit == CG_MILISECONDS )
        return ( ( ( current.tv_sec - last.tv_sec ) * 1000 ) + ( ( current.tv_usec - last.tv_usec ) / 1000 ) );

    if ( unit == CG_SECONDS )
        return ( current.tv_sec - last.tv_sec );
}
