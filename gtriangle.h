/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 25, 2023
 * \version September 25, 2023
 **/
#ifndef IFMOVE_GTRIANGLE_H
#define IFMOVE_GTRIANGLE_H

#include "gmesh2.h"
#include "rgba.h"

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 25, 2023
 * \version September 25, 2023
 * \brief GTriangle, a class to represent a drawable Triangle
 **/
class GTriangle: public GMesh2
{
    public:
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 25, 2023
         * \version September 25, 2023
         * \brief Constructor
         * \param p1 - first point
         * \param p2 - second point
         * \param p3 - third point
         * \param rgba - color
         **/
        GTriangle(const Vector3<double> &p1,
            const Vector3<double> &p2,
            const Vector3<double> &p3,
            const RGBA<unsigned char> &rgba = 
                RGBA<unsigned char>{0x0, 0xff, 0x0, 0xff});
};

#endif
