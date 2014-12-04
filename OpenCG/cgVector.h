#ifndef _CGVECTOR_
#define _CGVECTOR_

#include "cgCoord.h"

class cgVector2i
{
public:
    cgCoordi a;
    cgCoordi b;


    cgVector2i( cgCoordi argA, cgCoordi argB ):
        a(argA),
        b(argB){}


    cgVector2i( int ax, int ay, int bx, int by ):
        a( cgCoordi( ax, ay ) ),
        b( cgCoordi( bx, by ) ){}

};


class cgVector2f
{
public:
    cgCoordf a;
    cgCoordf b;


    cgVector2f( cgCoordf argA, cgCoordf argB ):
        a( argA ),
        b( argB ){}


    cgVector2f( float ax, float ay, float bx, float by ):
        a( cgCoordf( ax, ay ) ),
        b( cgCoordf( bx, by ) ){}

};

#endif // _CGVECTOR_

