/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 **/
#ifndef IFMOVE_WINDOW_H
#define IFMOVE_WINDOW_H

#include <SDL.h>
#include "vector3.h"
#include "matrix.h"
#include "rgba.h"

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 * \brief Window, a wrapper class to a SDL window object
 **/
class Window 
{
    public:
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Window Constructor
         * \param width - width of this window
         * \param height - height of this window
         **/
        Window(int width, int height);
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Destructor
         **/
        ~Window();      

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief draw a line between coordines (xi,yi), (xf, yf)
         * \param xi - x coordinate of initial point
         * \param yi - y coordinate of initial point
         * \param xf - x coordinate of final point
         * \param yf - y coordinate of final point
         **/
        void drawLine(int xi, int yi, int xf, int yf);

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief draw a line between coordinates (xi,yi), (xf, yf)
         * \param xi - x coordinate of initial point
         * \param yi - y coordinate of initial point
         * \param xf - x coordinate of final point
         * \param yf - y coordinate of final point
         * \param rgba - color of this line
         **/
        void drawLine(int xi, int yi, int xf, int yf, 
            const RGBA<unsigned char> &rgba);

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief draw a line between the initial vector and the final vector
         * \param i - the initial coordinate
         * \param f - the final coordinate
         **/
        void drawLine(const Vector3<double> &i, const Vector3<double> &f);


        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief draw a line between the initial vector and the final vector
         * \param i - the initial coordinate
         * \param f - the final coordinate
         * \param rgba - color of this line
         **/
        void drawLine(const Vector3<double> &i, 
            const Vector3<double> &f, const RGBA<unsigned char> &rgba);

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief clear the entire window, use it before draw
         **/
        void clear();

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief update screen, use it after draw
         **/
        void update();

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief get the default transform of this window
         * \return a matrix with the transformation for this window
         **/
        Matrix<double> transform();
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief set the default transform of this window
         * \param t - a matrix with the transformation for this window
         **/
        void transform(const Matrix<double> &t);

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief set the default color of drawing 
         * \param rgba - the color
         **/
        void setDrawColor(const RGBA<unsigned char> &rgba);

    protected:
        /** width of this window */
        int width;
        /** height of this window */
        int height;
        /** SDL_Window wrapped by this object */
        SDL_Window * window;
        /** The surface contained by the window (pointer) */
        SDL_Surface * screenSurface;
        /** The window renderer (pointer) of this windows */
        SDL_Renderer * renderer = NULL;
        /** Matrix transform defining the transformation used
         * for the graphical primitives of this window, set
         * an identity matrix to default SDL coordinate frame */
        Matrix<double> _transform;
        /** Background color */
        RGBA<unsigned char> bgColor;
        /** Default color */
        RGBA<unsigned char> drawColor;
    private:
        void _drawLine(const Vector3<double> &b, const Vector3<double> &e);

};

#endif
