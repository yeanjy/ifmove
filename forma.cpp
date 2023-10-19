#include "forma.h"
#include <iostream>
#include <cmath>
using namespace std;
#include "matrix.h"

FormaComposta::FormaComposta()
{}

void FormaComposta::draw(Window &window)
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



    for (int i =0 ; i < formas.size(); i++)
    {
        Matrix<double> my_rotation = Matrix<double>::identity(3);
        my_rotation.a[0][0] = cos(rotations[i]);
        my_rotation.a[0][1] = -sin(rotations[i]);
        my_rotation.a[1][0] = sin(rotations[i]);
        my_rotation.a[1][1] = cos(rotations[i]);

        formas[i].draw(window, translate*rotation*my_rotation*shearing); 
      
    }
    cout << shear_x << "\n" << shear_y << "\n";
}

void FormaComposta::addForma(GMesh2 &forma, double rotation)
{
    formas.push_back(forma);
    rotations.push_back(rotation);
    cout << "adicionando forma\n";
}


