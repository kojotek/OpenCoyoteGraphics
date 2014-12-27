#include "cgVector.h"

template <typename T> bool cgVector<T>::operator == ( const cgVector<T> &another )
{
    return ( another.x == x && another.y == y );
}


template <typename T> bool cgVector<T>::operator != ( const cgVector<T> &another )
{
    return !( another.x == x && another.y == y );
}


template <typename T> cgVector<T> cgVector<T>::operator + ( const cgVector<T> &another )
{
    return cgVector<T>( another.x + x, another.y + y );
}


template <typename T> cgVector<T> cgVector<T>::operator - ( const cgVector<T> &another)
{
    return cgVector<T>( another.x - x, another.y - y );
}


template <typename T> cgVector<T> cgVector<T>::operator * ( const T &another )
{
    return cgVector<T>( x*another, y*another );
}


template <typename T> cgVector<T> operator * ( const T &modif, const cgVector<T> &obj )
{
    return cgVector<T>( obj.x*modif, obj.y*modif );
}



template <typename T> cgVector<T> cgVector<T>::operator / ( const T &another )
{
    return cgVector<T>( x/another, y/another );
}


template <typename T> cgVector<T>& cgVector<T>::operator += ( const cgVector<T> &another )
{
    x += another.x;
    y += another.y;
    return * this;
}


template <typename T> cgVector<T>& cgVector<T>::operator -= ( const cgVector<T> &another )
{
    x -= another.x;
    y -= another.y;
    return * this;
}


template <typename T> cgVector<T>& cgVector<T>::operator *= ( const T &another )
{
    x *= another;
    y *= another;
    return * this;
}


template <typename T> cgVector<T>& cgVector<T>::operator /= ( const T &another )
{
    x /= another;
    y /= another;
    return * this;
}
