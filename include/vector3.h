/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 **/
#ifndef IFMOVE_VECTOR3_H
#define IFMOVE_VECTOR3_H

#include "matrix.h"

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 * \brief Vector3, a class to represent vectors in space and 
 * its operations
 **/
template <class T>
class Vector3: public Matrix<T> 
{
    public:
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Constructor
         * \param x - x coordinate
         * \param y - y coordinate
         * \param z - z coordinate
         **/
        Vector3(const T & x= 0, const T &y = 0, const T &z = 0);
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief copy constructor from a (3x1) matrix
         * \param m a (3x1) matrix
         **/
        Vector3(const Matrix<T> &m);
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Assignment operator with a matrix in right
         * hand side
         * \param m a (3x1) matrix
         * \return a reference for this vector
         **/
        Vector3 & operator=(const Matrix<T> &m);

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Add and assignment operator with a matrix in right
         * hand side
         * \param m a (3x1) matrix
         * \return a reference for this vector
         **/
        Vector3 & operator+=(const Matrix<T> &m);

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Return x coordinate of this vector
         * \return the value of x coordinate
         **/
        inline double x() const;
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Return y coordinate of this vector
         * \return the value of y coordinate
         **/
        inline double y() const;
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Return z coordinate of this vector
         * \return the value of z coordinate
         **/
        inline double z() const;
};

template <class T>
Vector3<T>::Vector3(const T &x, const T &y, const T &z):
    Matrix<T>{3, 1}
{
    Array2<T>::a[0][0] = x; 
    Array2<T>::a[1][0] = y; 
    Array2<T>::a[2][0] = z; 
}


template <class T>
Vector3<T>::Vector3(const Matrix<T> &m):
    Matrix<T>{m}
{
    assert(m.r == 3 && m.c == 1);
}


template <class T>
Vector3<T> & Vector3<T>::operator=(const Matrix<T> &m)
{
    assert(m.r == 3 && m.c == 1);
    Matrix<T>::operator=(m);
    return *this;
}

template <class T>
Vector3<T> & Vector3<T>::operator+=(const Matrix<T> &m)
{
    assert(m.r == 3 && m.c == 1);
    Matrix<T>::operator+=(m);
    return *this;
}

template <class T>
ostream & operator<<(ostream &out, const Vector3<T> &v)
{
    out << "<" << v.a[0][0] << ", " << v.a[1][0] << ", " << v.a[2][0] << ">";
    return out;
}

template <class T>
inline double Vector3<T>::x() const
{
    return Matrix<T>::a[0][0];
}

template <class T>
inline double Vector3<T>::y() const
{
    return Matrix<T>::a[1][0];
}

template <class T>
inline double Vector3<T>::z() const
{
    return Matrix<T>::a[2][0];
}


#endif
