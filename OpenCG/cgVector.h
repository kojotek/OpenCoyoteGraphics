#ifndef _CGVECTOR_
#define _CGVECTOR_

template <typename T>
class cgVector
{
public:
    T x;
    T y;


    cgVector( T argX, T argY ):
        x(argX),
        y(argY){}


     cgVector():
        x(0),
        y(0){}


    bool operator == ( const cgVector<T> &another )
    {
        return ( another.x == x && another.y == y );
    }


    bool operator != ( const cgVector<T> &another )
    {
        return !( another.x == x && another.y == y );
    }


    cgVector<T> operator + ( const cgVector<T> &another )
    {
        return cgVector<T>( another.x + x, another.y + y );
    }


    cgVector<T> operator - ( const cgVector<T> &another)
    {
        return cgVector<T>( another.x - x, another.y - y );
    }


    cgVector<T> operator * ( const T &another )
    {
        return cgVector<T>( x*another, y*another );
    }



    cgVector<T> operator / ( const T &another )
    {
        return cgVector<T>( x/another, y/another );
    }


    cgVector<T>& operator += ( const cgVector<T> &another )
    {
        x += another.x;
        y += another.y;
        return * this;
    }


    cgVector<T>& operator -= ( const cgVector<T> &another )
    {
        x -= another.x;
        y -= another.y;
        return * this;
    }


    cgVector<T>& operator *= ( const T &another )
    {
        x *= another;
        y *= another;
        return * this;
    }


    cgVector<T>& operator /= ( const T &another )
    {
        x /= another;
        y /= another;
        return * this;
    }

};


template <typename T> cgVector<T> operator * ( const T &modif, const cgVector<T> &obj )
{
    return cgVector<T>( obj.x*modif, obj.y*modif );
}


typedef cgVector<int> cgVectorInt;
typedef cgVector<float> cgVectorFloat;

#endif // _CGVECTOR
