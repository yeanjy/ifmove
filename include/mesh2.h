/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 **/
#ifndef IFMOVE_MESH2
#define IFMOVE_MESH2

#include "matrix.h"
#include "vector3.h"
#include <vector>
#include <sstream>
using namespace std;

// forward definition for Mesh 2
class Mesh2;

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 09, 2023
 * \version September 09, 2023
 * \brief operator<<
 * \param o reference for ostream
 * \param m reference for mesh
 **/
ostream & operator<<(ostream &o, const Mesh2 &m);

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 12, 2023
 * \version September 12, 2023
 * \brief Mesh2 - an abstract class to manage geometry meshes in 2d space
 **/
class Mesh2
{
    public:
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 12, 2023
         * \version September 12, 2023
         * \brief Mesh2 constructor
         * \param n - number of vertexes in this geometry
         **/
        Mesh2(ssize_t n);

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 12, 2023
         * \version September 12, 2023
         * \brief transform THIS mesh
         * \param t - a const reference to a transformation matrix
         **/
        virtual void transform(const Matrix<double> &t);

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 12, 2023
         * \version September 12, 2023
         * \brief get i-th vertex
         * \param n - the index of the vertex
         **/
        Vector3<double> getVertex(ssize_t n) const;
        

        friend ostream & operator<<(ostream &o, const Mesh2 &m);

        /**
         * Vertexes, they will be stored in a matrix to allow transformations
         **/
        Matrix<double> vs; 
        /**
         * Edges of this mesh
         **/
        vector<pair<size_t, size_t>> es; 
};

#endif 
