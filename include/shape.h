#ifndef J1_FORMA_H1
#define J1_FORMA_H1

#include <iostream>
#include <vector>

#include "gmesh2.h"
#include "window.h"
#include "vector3.h"
using namespace std;

class CompoundShape 
{
    public: 
        CompoundShape();
        void draw(Window &w);
        void addShape(GMesh2 &shape, double rotation = 0.0);

        vector<GMesh2> shapes;
        Vector3<double> center;
        double rotate;
        double shear_x;
        double shear_y;

        vector<double> rotations;
};


#endif