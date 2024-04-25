/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 25, 2023
 * \version September 25, 2023
 **/
#ifndef IFMOVE_GSQUARE_H
#define IFMOVE_GSQUARE_H

#include "rgba.h"
#include "gmesh2.h"

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 25, 2023
 * \version September 25, 2023
 * \brief GSquare, a class to represent a drawable Square
 **/
class GSquare: public GMesh2
{
    public:
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 25, 2023
         * \version September 25, 2023
         * \brief Constructor
         * \param r - top right corner
         * \param l - lenght
         * \param rgba - color
         **/
        GSquare(const Vector3<double> &r, double l = 1.0, 
            const RGBA<unsigned char> &rgba = 
                RGBA<unsigned char>{0x0, 0xff, 0x0, 0xff});
        /**
         * center
         **/
        Vector3<double> c;
        /**
         * lenght
         **/
        double l; 
};


#endif
