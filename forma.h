#ifndef J1_FORMA_H1
#define J1_FORMA_H1
#include <iostream>
using namespace std;
#include "gmesh2.h"
#include "window.h"
#include <vector>
#include "vector3.h"

class FormaComposta 
{
    public: 
        FormaComposta();
        void draw(Window &w);
        void addForma(GMesh2 &forma, double rotation = 0.0);

        vector<GMesh2> formas;
        Vector3<double> center;
        double rotate;
        double shear_x;
        double shear_y;

        vector<double> rotations;
};


#endif