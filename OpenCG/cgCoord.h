#ifndef _CGCOORD_
#define _CGCOORD_


class cgCoordi;
class cgCoordf;


class cgCoordi
{
public:
    int x;
    int y;


    cgCoordi(int argX, int argY):
        x(argX),
        y(argY){}


    cgCoordf getFloat();
};



class cgCoordf
{
public:
    float x;
    float y;

    cgCoordf(float argX, float argY):
        x(argX),
        y(argY){}


    cgCoordi getInt();
};

#endif // _CGCOORD_

