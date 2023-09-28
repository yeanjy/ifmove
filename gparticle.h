/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 **/
#ifndef IFMOVE_GPARTICLE_H
#define IFMOVE_GPARTICLE_H

#include "particle.h"
#include "graphics.h"
#include "gcircle.h"

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 * \brief GParticle, a class to represent a drawable particle
 **/
class GParticle: public Graphics, public Particle
{
    public:
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Constructor
         * \param r - location 
         * \param v - velocity
         * \param a - acceleration
         * \param radius - radius in pixels
         **/
        GParticle(const Vector3<double> &r,
            const Vector3<double> &v,
            const Vector3<double> &a,
            double radius = 50);
        void draw(Window &w) override;
        void move(double dt) override;
    protected:
        // function members
        /**
         * Graphic representation fo this particle
         **/
        GCircle circle;
};

#endif
