/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 **/
#ifndef IFMOVE_POINT2_H
#define IFMOVE_POINT2_H

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023 
 * \brief Point2, a class to represent a point in the plane.
 **/
class Point2 {
    public:
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023 
         * \brief Default constructor
         **/
        Point2();  
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023 
         * \brief Constructor using x,y coordinates
         * \param x - x coordinate
         * \param y - y coordinate
         **/
        Point2(double x, double y);
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023 
         * \brief Copy constructor
         * \param p - a point
         **/
        Point2(const Point2 &p);
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023 
         * \brief Assignment operator
         * \param p - a point
         * \return a reference for this point
         **/
        Point2 & operator=(const Point2 &p);
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023 
         * \brief translate this point by an x,y amount
         **/
        void translate(double x, double y);
        // data members
        /**
         * the x coordinate
         */
        double x;
        /**
         * the y coordinate
         */
        double y;
};

#endif
