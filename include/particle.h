/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 **/
#ifndef IFMOVE_PARTICLE_H
#define IFMOVE_PARTICLE_H

#include "vector3.h"

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 * \brief Particle, a class to represent a particle in physics simulations
 **/
class Particle
{
    public:
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Particle constructor
         * \param r - location of the particle
         * \param v - velocity
         * \param a - acceleration
         **/
        Particle(const Vector3<double> &r, const Vector3<double> &v,
            const Vector3<double> &a);
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief move a particle by a dt time, USE A SMALL dt value
         * \param dt - dt time used for move the particle
         **/
        virtual void move(double dt);
        // data members
        /**
         * r - coordinate location of the particle
         **/
        Vector3<double> r;
        /**
         * v - velocity of this particle - SET THE Z COORDINATE TO ZERO,
         * this system uses homogeneous coordinates for drawing functions,
         * a z velocity other than zero will change the position of the
         * particle in the screen
         **/
        Vector3<double> v;
        /**
         * a - acceleration of this particle - SET THE Z COORDINATE TO ZERO,
         * this system uses homogeneous coordinates for drawing functions,
         * a z acceleration other than zero will change the position of the
         * particle in the screen
         **/
        Vector3<double> a;
};

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 * \brief operator<< outputs particle information in the ostream 
 * \param o reference for ostream
 * \param a reference for a particle
 * \return a reference for an ostrem
 **/
ostream & operator<<(ostream &out, const Particle &c);

#endif
