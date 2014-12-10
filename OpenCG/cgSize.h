#ifndef _CGSIZE_
#define _CGSIZE_


class cgSize
{
public:
    int width;
    int height;


    cgSize( int w, int h ):
        width(w),
        height(h){}


    cgSize():
        width(0),
        height(0){}
};



#endif // _CGSIZE_
