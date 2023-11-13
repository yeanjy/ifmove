/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 **/
#ifndef IFMOVE_GCIRCLE_H
#define IFMOVE_GCIRCLE_H

#include "gmesh2.h"
#include "rgba.h"
/**
 * \brief default number of points in the mesh of this circle
 **/
#define GCIRCLE_DEFAULT_N 30

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 * \brief GCircle, a class to represent a drawable circle
 **/
class GCircle: public GMesh2
{
    public:
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Constructor
         * \param c - center
         * \param r - radius
         * \param n - points of this circle
         * \param rgba - rgba color
         **/
        GCircle(const Vector3<double> &c, double r = 1.0, 
            ssize_t n = GCIRCLE_DEFAULT_N, 
            const RGBA<unsigned char> &rgba = 
                RGBA<unsigned char>{0x0, 0xff, 0x0, 0xff});

        void move(double x, double y);
        void imprimir();
        static bool collision(GCircle &a, GCircle &b);
        static bool floorCollision(const int &floor, GCircle &a);
        static void multipleCollision(vector<GCircle> circle);
        static void update(GCircle &a);

        double getcX();
        double getcY();
        Vector3<double> getC();
        
        double ax, ay; //aceleration
        double vx, vy; //velocity
    private:
        /** center */
        Vector3<double> c;
        /** radius */
        double r; 
};

#endif
