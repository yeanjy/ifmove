/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 **/
#ifndef IFMOVE_IFMOVE_H
#define IFMOVE_IFMOVE_H

#include "window.h"
#include "mesh2.h"

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 * \brief A graphics interface for drawable objetcs
 **/
class Graphics
{
    public:

        virtual ~Graphics() = 0;

        /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Interface for drawing in a window
         * \param w - window 
         **/
        virtual void draw(Window &w) = 0;
};

#endif
