/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 25, 2023
 * \version September 25, 2023
 **/
#ifndef IFMOVE_GRID_H
#define IFMOVE_GRID_H

#include "point2.h"
#include "window.h"
#include "graphics.h"
#include "rgba.h"

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 25, 2023
 * \version September 25, 2023
 * \brief Grid, a class to represent a Graphical Grid
 **/
class Grid: public Graphics {
    public:
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 25, 2023
         * \version September 25, 2023
         * \brief Constructor
         * \param o - origin
         * \param w - width
         * \param h - height
         * \param dx - distance between x lines
         * \param dy - distance between y lines
         * \param gridColor - color
         **/
        Grid(const Vector3<double> &o, int w, int h, int dx, int dy,
            const RGBA<unsigned char> &gridColor = 
                RGBA<unsigned char>{0xff, 0xff, 0xff, 0xff});
        void draw(Window &w) override;

        /**
         * origin
         **/
        const Vector3<double> o; 
        /**
         * width
         **/
        int w; 
        /**
         * height
         **/
        int h;
        /**
         * distance between x lines
         **/
        int dx; 
        /**
         * distance between x lines
         **/
        int dy;
        /**
         * grid color
         **/
        RGBA<unsigned char> gridColor;
};

#endif
