/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 09, 2023
 * \version September 10, 2023
 **/

#ifndef IFMOVE_MATRIX_H
#define IFMOVE_MATRIX_H

#include "array2.h"

// forward declaration
template <typename T>
class Matrix;

/**
* \author Eder Augusto Penharbel (oederaugusto)
* \date September 09, 2023
* \version September 09, 2023
* \brief Output stream operator<< 
* \param o - a reference for a output stream
* \param m - a reference for a matrix
**/
template <typename T>
ostream & operator<<(ostream &o, const Matrix<T> &m);

/**
* \author Eder Augusto Penharbel (oederaugusto)
* \date September 09, 2023
* \version September 09, 2023
* \brief Assignment and multiplication operator to allow commutative s * m
* \param s - scalar s to be multiplied by matrix m
* \param m - matrix m to be multiplied by scalar s
**/
template <typename T>
Matrix<T> operator*(const T &s, Matrix<T> &m);

template <typename T>
Matrix<T> operator*(const T &s, Matrix<T> &&m);

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 09, 2023
 * \version September 10, 2023
 * \brief Matrix, a class to represent a (mathematical) matrix
 **/
template <typename T>
class Matrix: public Array2<T>
{
    public:
         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief Constructor
         * \param r - rows 
         * \param c - columns
         * \param s - set value s to every entries in Matrix
         **/
        Matrix(ssize_t r, ssize_t c, const T &s = T{0});

         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief Destructor
         **/
        ~Matrix();

         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief Assignment and multiplication operator
         * \param m - this (matrix) will be multiplied by m and assigned to
         * the result of multiplication
         **/
        inline Matrix<T> & operator*=(const Matrix<T> &m);

         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief Assignment and multiplication operator with a scalar
         * \param s - the scalar to be multiplied with this matrix
         * the result of multiplication
         **/
        inline Matrix<T> & operator*=(const T &s);

         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief Multiplication operator
         * \param m - this (matrix) will be multiplied by m
         **/
        inline Matrix<T> operator*(const Matrix<T> &m) const;

         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief Multiplication operator for scalar
         * \param s - this (matrix) will be multiplied by scalar s
         **/
        inline Matrix<T> operator*(const T &s) const;

         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 10, 2023
         * \version September 10, 2023
         * \brief Assignment and addition operator
         * \param m - this (matrix) will be added by m and assigned to
         * the result of multiplication
         **/
        inline Matrix<T> & operator+=(const Matrix<T> &m);

         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 10, 2023
         * \version September 10, 2023
         * \brief Assignment and addition operator with a scalar
         * \param s - a scalar to be added to this matrix
         * the result of multiplication
         **/
        inline Matrix<T> & operator+=(const T &s);

         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 10, 2023
         * \version September 10, 2023
         * \brief Addition operator
         * \param m - this (matrix) will be added by m
         **/
        inline Matrix<T> operator+(const Matrix<T> &m) const;

         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 10, 2023
         * \version September 10, 2023
         * \brief Addition operator for a scalar
         * \param s - a scalar to be added to this matrix
         **/
        inline Matrix<T> operator+(const T &s) const;

         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief return the transpose of this matrix
         **/
        Matrix<T> inline transpose() const;        

         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief return an n by n identity matrix
         **/
        static Matrix<T> inline identity(ssize_t n);        

        friend ostream & operator<< <T>(ostream &o, const Matrix<T> &m); 
};

template <typename T>
Matrix<T>::Matrix(ssize_t r, ssize_t c, const T &s):
    Array2<T>{r, c, s}
{
}

template <typename T>
Matrix<T>::~Matrix()
{
}

template <typename T>
Matrix<T> & Matrix<T>::operator*=(const Matrix<T> &m)
{
    assert(Array2<T>::c == m.r);
    Matrix<T> tmp(Array2<T>::r, m.c);
    for (ssize_t  i = 0; i < Array2<T>::r; i++)
        for (ssize_t j = 0; j < m.c; j++)
            for (size_t k = 0; k < Array2<T>::c; k++)
                tmp.a[i][j] += Array2<T>::a[i][k] * m.a[k][j];
    Array2<T>::swap(tmp);
    return *this;
}

template <typename T>
Matrix<T> & Matrix<T>::operator*=(const T &s)
{
    for (ssize_t  i = 0; i < Array2<T>::r; i++)
        for (ssize_t j = 0; j < Array2<T>::c; j++)
            Array2<T>::a[i][j] *= s;
    return *this;
}

template <typename T>
inline Matrix<T> Matrix<T>::operator*(const Matrix<T> &m) const
{
    Matrix<T> tmp(*this);
    tmp *= m;
    return tmp; 
}

template <typename T>
inline Matrix<T> Matrix<T>::operator*(const T &s) const
{
    Matrix<T> tmp(*this);
    tmp *= s;
    return tmp;
}

template <typename T>
Matrix<T> operator*(const T &s, Matrix<T> &m)
{
    return m * s;
}

template <typename T>
Matrix<T> operator*(const T &s, Matrix<T> &&m)
{
    return m * s;
}

template <typename T>
Matrix<T> & Matrix<T>::operator+=(const Matrix<T> &m)
{
    assert(Array2<T>::r == m.r && Array2<T>::c == m.c);
    for (ssize_t  i = 0; i < Array2<T>::r; i++)
        for (ssize_t j = 0; j < Array2<T>::c; j++)
                Array2<T>::a[i][j] += m.a[i][j];
    return *this;
}

template <typename T>
Matrix<T> & Matrix<T>::operator+=(const T &s)
{
    for (ssize_t  i = 0; i < Array2<T>::r; i++)
        for (ssize_t j = 0; j < Array2<T>::c; j++)
            Array2<T>::a[i][j] += s;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &m) const
{
    Matrix<T> tmp(*this);
    tmp += m;
    return tmp; 
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const T &s) const
{
    Matrix<T> tmp(*this);
    tmp += s;
    return tmp; 
}

template <typename T>
Matrix<T> inline Matrix<T>::transpose() const
{
    Matrix<T> tmp{Array2<T>::c, Array2<T>::r};
    for (ssize_t  i = 0; i < Array2<T>::r; i++)
        for (ssize_t j = 0; j < Array2<T>::c; j++)
            tmp.a[j][i] = Array2<T>::a[i][j];
    return tmp;
}

/**
* \author Eder Augusto Penharbel (oederaugusto)
* \date September 09, 2023
* \version September 09, 2023
* \brief operator<< 
**/
template <typename T>
ostream & operator<<(ostream &o, const Matrix<T> &m)
{
    for (int i = 0; i < m.r-1; i++)
    {
        for (int j = 0; j < m.c-1; j++)
            o << m.a[i][j] << " ";
        o << m.a[i][m.c-1] << endl;
    }
    for (int j = 0; j < m.c-1; j++)
        o << m.a[m.r-1][j] << " ";
    o << m.a[m.r-1][m.c-1];
    return o;
}

template <typename T>
Matrix<T> Matrix<T>::identity(ssize_t n)
{
    Matrix<T> id{n, n};
    for (int i = 0; i < n; i++)
        id.a[i][i] = T{1.0};
    return id;
}

#endif
