/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 09, 2023
 * \version September 09, 2023
 **/

#ifndef IFMOVE_ARRAY2_H
#define IFMOVE_ARRAY2_H

#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std;

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 09, 2023
 * \version September 09, 2023
 * \brief Array2 - a class to control an 2 dimentional array
 **/
template <typename T>
class Array2
{
    public:
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief default constructor, set r = 0, c = 0, a = nullptr
         **/
        Array2(); 
         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief Constructor
         * \param r - rows 
         * \param c - columns
         * \param s - set value s to every entries in Array2
         **/
        Array2(ssize_t r, ssize_t c, const T &s = T{0});
         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief Copy constructor - hard copy 
         * \param m - Matrix that will be copied
         **/
        Array2(const Array2<T> &m);
         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief destructor
         **/
        ~Array2();
         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief Assignment operator (copy)
         **/
        Array2<T> & operator=(const Array2<T> &a);
         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief Assignment operator (move)
         **/
        Array2<T> & operator=(const Array2<T> &&a)
        {
            cout << "moving operator= not implemented" << endl;
            exit(1);
        }

        // data members
        /**  number of rows */
        ssize_t r;
        /** number of columns */
        ssize_t c; 
        /** data */
        T **a;     
    protected:
         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief used to allocate memory 
         **/
        void alloc(ssize_t r, ssize_t c);
         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief used to free memory 
         **/
        void free(); 
         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief used to copy data from a pointer to pointer a 
         * with r rows and c columns;
         **/
        void copy(const Array2<T> &a);

         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief swap all data members with a
         **/
        void swap(Array2<T> &a);
         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 09, 2023
         * \version September 09, 2023
         * \brief set all entries to s
         **/
        void set(const T &s);

};

template <typename T>
Array2<T>::Array2():
    r{0}, c{0}, a{nullptr}
{ }

template <typename T>
Array2<T>::Array2(ssize_t r, ssize_t c, const T &s):
    Array2<T>()
{
    alloc(r, c);
    set(s);
}

template <typename T>
Array2<T>::Array2(const Array2<T> &a):
    Array2<T>()
{
    alloc(a.r,a.c);
    copy(a);
}

template <typename T>
Array2<T>::~Array2()
{
    if (a != nullptr)
        free();
    r = 0;
    c = 0;
    a = nullptr;
}

template <typename T>
Array2<T> & Array2<T>::operator=(const Array2<T> &a)
{
    alloc(a.r, a.c);
    copy(a);
    return *this;
}

template <typename T>
void Array2<T>::free() 
{
    if ( a != nullptr ) {
        for (ssize_t i = 0; i < r; i++) 
            delete [] a[i];
        delete [] a;
    }
    r = c = 0;
    a = nullptr;
}

template <typename T>
void Array2<T>::alloc(ssize_t r, ssize_t c)
{
    // different sizes implies to free storage
    if (Array2<T>::r != r || Array2<T>::c != c)
        free();
    Array2<T>::r = r;
    Array2<T>::c = c;
    // allocating storage
    a = new T *[r];
    for (ssize_t i = 0; i < r; i++)
        a[i] = new T[c];
}
                
template <typename T>
void Array2<T>::copy(const Array2<T> &a)
{
    assert(Array2<T>::r == a.r and Array2<T>::c == a.c);
    for (ssize_t i = 0; i < r; i++)
        for (ssize_t j = 0; j < c; j++)
            Array2<T>::a[i][j] = a.a[i][j];            
}

template <typename T>
void Array2<T>::swap(Array2<T> &a)
{
    ssize_t iaux;
    T ** taux;
    // swaping number of rows
    iaux = a.r;
    a.r = r;
    r = iaux;
    // swaping number of columns
    iaux = a.c;
    a.c = c;
    c = iaux;
    // swaping data
    taux = a.a;
    a.a = Array2<T>::a;
    Array2<T>::a = taux;
}


template <typename T>
void Array2<T>::set(const T &s)
{
    for (ssize_t i = 0; i < r; i++)
        for (ssize_t j = 0; j < c; j++)
            Array2<T>::a[i][j] = s;            
}

#endif
