#include <iostream>
#include <cmath>

#include "shape.h"
#include "matrix.h"
using namespace std;

CompoundShape::CompoundShape()
{}

void CompoundShape::draw(Window &window)
{
    Matrix<double> translate = Matrix<double>::identity(3);
    translate.a[0][2] = center.x();
    translate.a[1][2] = center.y();
    
    Matrix<double> rotation = Matrix<double>::identity(3);
    rotation.a[0][0] = cos(rotate);
    rotation.a[0][1] = -sin(rotate);
    rotation.a[1][0] = sin(rotate);
    rotation.a[1][1] = cos(rotate);

    Matrix<double> shearing = Matrix<double>::identity(3);
    shearing.a[0][1] = shear_x;
    shearing.a[1][0] = shear_y;



    for (int i =0 ; i < shapes.size(); i++)
    {
        // Vector3<double> position = shapes[i].c;

        Matrix<double> my_rotation = Matrix<double>::identity(3);
        my_rotation.a[0][0] = cos(rotations[i]);
        my_rotation.a[0][1] = -sin(rotations[i]);
        my_rotation.a[1][0] = sin(rotations[i]);
        my_rotation.a[1][1] = cos(rotations[i]);

        shapes[i].draw(window, translate*my_rotation*rotation*shearing); 
      
    }
    cout << shear_x << "\n" << shear_y << "\n";
}

void CompoundShape::addShape(GMesh2 &shape, double rotation)
{
    shapes.push_back(shape);
    rotations.push_back(rotation);
    cout << "adicionando shape\n";
}


