#ifndef _CGSIZE_
#define _CGSIZE_

template <typename T = int>
class cgSize
{
public:
    T width;
    T height;


    cgSize( T argX, T argY ):
        width(argX),
        height(argY){}


	cgSize():
        width(0),
        height(0){}


    bool operator == ( const cgSize<T> &another )
    {
        return ( another.width == width && another.height == height );
    }

    bool operator != ( const cgSize<T> &another )
    {
        return !( another.width == width && another.height == height );
    }

    cgSize<T> operator + ( const cgSize<T> &another )
    {
        return cgSize<T>( another.width + width, another.height + height );
    }

    cgSize<T> operator - ( const cgSize<T> &another)
    {
        return cgSize<T>( another.width - width, another.height - height );
    }

    cgSize<T> operator * ( const T &another )
    {
        return cgSize<T>( width*another, height*another );
    }

    cgSize<T> operator / ( const T &another )
    {
        return cgSize<T>( width/another, height/another );
    }

    cgSize<T>& operator += ( const cgSize<T> &another )
    {
        width += another.width;
        height += another.height;
        return * this;
    }

    cgSize<T>& operator -= ( const cgSize<T> &another )
    {
        width -= another.width;
        height -= another.height;
        return * this;
    }

    cgSize<T>& operator *= ( const T &another )
    {
        width *= another;
        height *= another;
        return * this;
    }

    cgSize<T>& operator /= ( const T &another )
    {
        width /= another;
        height /= another;
        return * this;
    }

};


template <typename T> cgSize<T> operator * ( const T &modif, const cgSize<T> &obj )
{
    return cgSize<T>( obj.width*modif, obj.height*modif );
}


typedef cgSize<int> cgSizeInt;
typedef cgSize<float> cgSizeFloat;

#endif // _CGVECTOR
