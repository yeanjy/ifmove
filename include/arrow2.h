/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 **/
#ifndef IFMOVE_ARROW2_H
#define IFMOVE_ARROW2_H

#include "point2.h"
#include "window.h"
#include "vector3.h"
#include "graphics.h"
#include "rgba.h"

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 * \brief Arrow2, a class to represent a drawable arrow
 **/
class Arrow2: public Graphics {
    public:
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Arrow2 constructor
         * \param tx - x coordinate of tail
         * \param ty - y coordinate of tail
         * \param hx - x coordinate of head
         * \param hy - y coordinate of head
         * \param rgba - rgba color
         **/
        Arrow2(double tx, double ty, 
                double hx, double hy,
                const RGBA<unsigned char> &rgba = 
                    RGBA<unsigned char>{0xff, 0xff, 0xff, 0xff});
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Arrow2 constructor
         * \param t - location of tail
         * \param h - location of head
         * \param rgba - rgba color
         **/
        Arrow2(const Point2 &t, const Point2 &h,
                const RGBA<unsigned char> &rgba = 
                    RGBA<unsigned char>{0xff, 0xff, 0xff, 0xff});
         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Arrow2 constructor
         * \param t - location of tail
         * \param h - location of head
         * \param rgba - rgba color
         **/
        Arrow2(const Vector3<double> &t, const Vector3<double> &h,
                const RGBA<unsigned char> &rgba = 
                    RGBA<unsigned char>{0xff, 0xff, 0xff, 0xff});

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Draw this arrow in the Window w
         * \param w - window 
         **/
        void draw(Window &w);

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Distance between tail and head
         * \return the length of this arrow
         **/
        double length();

        /** arrow tail */
        Vector3<double> t; 
        /** arrow head */
        Vector3<double> h; 
        /** arrow color */
        RGBA<unsigned char> color; 
};

#endif
