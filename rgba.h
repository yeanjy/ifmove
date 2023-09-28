/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 **/

#ifndef IFMOVE_RGBA
#define IFMOVE_RGBA

/**
 * \author Eder Augusto Penharbel (oederaugusto)
 * \date September 24, 2023
 * \version September 24, 2023
 * \brief Matrix, a class to represent a RGBA color
 **/
template <typename T>
struct RGBA
{
    public:
         /**
         * \author Eder Augusto Penharbel (oederaugusto)
         * \date September 24, 2023
         * \version September 24, 2023
         * \brief Constructor for RGBA class
         * \param r - red value
         * \param g - green value
         * \param b - blue value
         * \param a - alpha value
         **/
        RGBA(const T &r = T{0}, T const &g = T{0}, 
            const T &b = T{0}, const T &a = T{0});
        // data members
        /**
         * red value
         */
        T r; 
        /**
         * green value
         */
        T g; 
        /**
         * blue value
         */
        T b; 
        /**
         * alpha value
         */
        T a; 
};

template <typename T>
RGBA<T>::RGBA(const T &r, const T &g, const T &b, const T &a):
    r{r}, g{g},
    b{b}, a{a}
{
}

#endif
