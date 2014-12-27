#ifndef _CGVECTOR_
#define _CGVECTOR_

template <typename T> class cgVector
{
public:
    T x;
    T y;

    cgVector( T argX, T argY ):
        x(argX),
        y(argY){}

    bool operator == ( const cgVector<T> &a );
    bool operator != ( const cgVector<T> &a );
    cgVector<T> operator + ( const cgVector<T> &a );
    cgVector<T> operator - ( const cgVector<T> &a );
    cgVector<T> operator * ( const T &a );
    cgVector<T> operator / ( const T &a );
    cgVector<T> & operator += ( const cgVector<T> &a );
    cgVector<T> & operator -= ( const cgVector<T> &a );
    cgVector<T> & operator *= ( const T &a );
    cgVector<T> & operator /= ( const T &a );
};

typedef cgVector<int> cgVectorInt;
typedef cgVector<float> cgVectorFloat;

#endif // _CGVECTOR
