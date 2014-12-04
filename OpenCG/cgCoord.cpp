#include "cgCoord.h"
#include "math.h"


cgCoordf cgCoordi::getFloat()
{
    return cgCoordf( float(x), float(y) );
}


cgCoordi cgCoordf::getInt()
{
    return cgCoordi( round(x), round(y) );
}
