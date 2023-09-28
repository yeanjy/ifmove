/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 **/
#ifndef IFMOVE_GMESH2_H
#define IFMOVE_GMESH2_H

#include "window.h"
#include "mesh2.h"
#include "graphics.h"
#include "rgba.h"
#include <map>
#include <utility>
using namespace std;

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 * \brief GMesh, a class to represent a drawable Mesh2
 **/
class GMesh2: public Graphics, public Mesh2
{
    public:
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Constructor
         * \param m - Mesh2 (see mesh_utils.h)
         * \param dColor - default color
         **/
        GMesh2(const Mesh2 &m, const RGBA<unsigned char> &dColor);

        void draw(Window &w) override;

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief draw this mesh in a window transforming each 
         * vertex with transformation t
         * \param w - the window
         * \param t - a matrix transformation
         **/
        virtual void draw(Window &w, const Matrix<double> &t);

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief return a copy of the default color
         * \return a copy of the default color
         **/
        RGBA<unsigned char> dColor();

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief set the default color color for the edges
         **/
        void dColor(const RGBA<unsigned char> &rgba);
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief get the color of the edge e
         * \return the edge color
         **/
        RGBA<unsigned char> eColor(size_t e);
        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief set the edge e color 
         * \param e - edge index
         * \param rgba - the color
         **/
        void eColor(size_t e, const RGBA<unsigned char> &rgba);

    protected:

        /** edges colors */
        map< size_t, RGBA<unsigned char> > esColors; 
        /** default color for edges, edges without a specific color
         * assign to it will use this color */
        RGBA<unsigned char> _dColor; 
};

#endif
